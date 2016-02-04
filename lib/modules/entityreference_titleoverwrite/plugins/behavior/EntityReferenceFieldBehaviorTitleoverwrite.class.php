<?php
/**
 * @file
 * Additional behavior for the entityrefence field.
 */

/**
 * Class EntityReferenceFieldBehaviorTitleoverwrite.
 */
class EntityReferenceFieldBehaviorTitleoverwrite extends EntityReference_BehaviorHandler_Abstract {

  /**
   * Alter the items before rendering.
   */
  public function alterItems(&$items, $entity, $field, $display, $langcode) {
    foreach ($items as $item) {
      if (isset($item['title_override']) && !empty($item['title_override'])) {
        $custom_title = $item['title_override'];
        // Change entity properties.
        $item['entity']->title = $custom_title;
        $item['entity']->title_field[$langcode][0]['value'] = $custom_title;
        $item['entity']->title_field[$langcode][0]['safe_value'] = $custom_title;
      }
    }
  }

  /**
   * Overwrite the schema.
   */
  public function schema_alter(&$schema, $field) {
    $schema['columns']['title_override'] = array(
      'type' => 'varchar',
      'description' => 'Title override',
      'length' => 255,
      'not null' => FALSE,
    );
  }

  /**
   * Generate a settings form for this handler.
   */
  public function settingsForm($field, $instance) {
    $form['overwrite_title_mandatory'] = array(
      '#type' => 'checkbox',
      '#title' => t('Make the title field mandatory?'),
      '#description' => t('You could make this mandatory if you want the editor to be forced to set a title.'),
    );
    return $form;
  }

}
