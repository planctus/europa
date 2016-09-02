<?php
/**
 * @file
 * Additional behavior for the entityrefence field.
 */

/**
 * Class EntityReferenceFieldBehaviorRemoteOverride.
 */
class EntityReferenceFieldBehaviorRemoteOverride extends EntityReference_BehaviorHandler_Abstract {

  /**
   * Alter the items before rendering.
   */
  public function alterItems(&$items, $entity, $field, $display, $langcode) {
    foreach ($items as &$item) {
      if ($elements = $this->hasOverriddenFields($item)) {
        foreach ($elements as $field_name => $field_value) {
          $field_info = field_info_field($field_name);
          // If it is translateable we set the langcode. Otherwise we use
          // LANGUAGE_NONE.
          $langcode = $field_info['translatable'] ? $langcode : LANGUAGE_NONE;
          // Title field is a special case. In this case we also set the entity
          // title itself.
          if ($field_name == 'title_field') {
            $item['entity']->title = $field_value;
          }
          // Set the other array values.
          $item['entity']->{$field_name}[$langcode][0]['value'] = $field_value;
          $item['entity']->{$field_name}[$langcode][0]['safe_value'] = $field_value;
          $item['entity']->entity_reference_has_override = TRUE;
        }
      }
    }
  }

  /**
   * Overwrite the schema.
   */
  public function schema_alter(&$schema, $field) {
    if (isset($field['settings']['handler_settings']['behaviors']['remoteoverride_field_behavior']['overrideable_fields'])) {
      foreach ($field['settings']['handler_settings']['behaviors']['remoteoverride_field_behavior']['overrideable_fields'] as $field_name => $field_label) {
        $field_name_dynamic = _entityreference_remoteoverride_generate_system_name($field_name);
        $schema['columns'][$field_name_dynamic] = array(
          'type' => 'varchar',
          'description' => $field_label,
          'length' => 255,
          'not null' => FALSE,
        );
      }
    }
  }

  /**
   * Generate a settings form for this handler.
   */
  public function settingsForm($field, $instance) {
    $form['override_mandatory'] = [
      '#type' => 'checkbox',
      '#title' => t('Make the override field mandatory?'),
      '#description' => t('You could make this mandatory if you want the editor to be forced to set a override value.'),
    ];

    $target_bundles = $field['settings']['handler_settings']['target_bundles'];
    $target_type = $field['settings']['target_type'];

    $form['overrideable_fields'] = [
      '#type' => 'checkboxes',
      '#title' => t('Overrideable fields'),
      '#description' => t('Here you can select all the fields that will be available for overriding. Only the fields that are shared between all entity bundles are shown.'),
      '#options' => $this->getRemoteFields($target_bundles, $target_type),
    ];

    return $form;
  }

  /**
   * Gets the available fields on the remote entity types.
   *
   * @param array $target_bundles
   *   The array of target bundles.
   * @param string $entity_type
   *   Entity type as a string.
   *
   * @return array
   *   The list of fields system_name => readable name.
   */
  private function getRemoteFields(array $target_bundles = [], $entity_type) {
    $available_fields = [];
    foreach ($target_bundles as $bundle) {
      $field_instances = field_info_instances($entity_type, $bundle);
      foreach ($field_instances as $instance) {
        // For now, this only takes the last label. We need to figure out a way`
        // to make it more dynamic. But this is already a good start.
        if ($instance['widget']['type'] == 'text_textfield' && !isset($available_fields[$instance['field_name']])) {
          $available_fields[$instance['field_name']] =  $instance['label'];
        }
      }
    }
    // Filter them. This is a dirty way to check that we only use the fields
    // that are shared between all of the bundle's.
    foreach ($available_fields as $field_name => $field) {
      foreach ($target_bundles as $bundle) {
        if (!field_info_instance($entity_type, $field_name, $bundle)) {
          unset($available_fields[$field_name]);
        }
      }
    }
    return $available_fields;
  }

  /**
   * Check for the overridden fields.
   *
   * @param array $item
   *   The item to check for.
   *
   * @return array
   *   List of fields and their overwritten value.
   */
  private function hasOverriddenFields($item) {
    // Get all the elements that are override fields.
    $elements = array_intersect_key($item, array_flip(preg_grep('/er_override_(.*)/', array_keys($item))));
    $available = [];
    // Change the array keys to the actual field names.
    foreach ($elements as $key => $value) {
      $available[str_replace('er_override_', '', $key)] = $value;
    }
    return $available;
  }

}
