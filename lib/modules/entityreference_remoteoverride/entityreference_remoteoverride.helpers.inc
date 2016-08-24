<?php

/**
 * @file
 * Contains helper functions used by entityreference_titleoverwrite.
 */

/**
 * Migration helper function to alter the database schema for a certain field.
 *
 * This can be used to upgrade existing fields, together with a feature revert.
 *
 * @param string $field_name
 *   The field name.
 * @param array $remote_fields
 *   The fields on the remote entity to be overwritable. Textfields only.
 * @param bool $mandatory
 *   If the fields should be mandatory.
 *
 * @throws Exception
 *   If the $remote_fields dont exists.
 */
function _entityreference_remoteoverride_add_table_field($field_name, array $remote_fields, $mandatory = FALSE) {
  foreach ($remote_fields as $field) {
    if (field_info_field($field)) {

      // The actual field to add to the schema.
      $field_schema_name = $field_name . '_' . _entityreference_remoteoverride_generate_system_name($field);

      // The new fields properties.
      $field_schema_information = [
        'type' => 'varchar',
        'description' => $field_name . ' override',
        'length' => 255,
        'not null' => FALSE,
      ];

      // The data table.
      $data_table_name = 'field_data_' . $field_name;
      if (!db_field_exists($data_table_name, $field_schema_name)) {
        db_add_field($data_table_name, $field_schema_name, $field_schema_information);
      }

      // The revision table.
      $revision_table_name = 'field_revision_' . $field_name;
      if (!db_field_exists($revision_table_name, $field_schema_name)) {
        db_add_field($revision_table_name, $field_schema_name, $field_schema_information);
      }

      // Last step is to update the database config.
      $query = db_select('field_config', 'fc');
      $query->addField('fc', 'data');
      $query->addField('fc', 'field_name');
      $query->condition('field_name', $field_name, '=');
      $result = $query->execute()->fetchAssoc();
      // Unserialize the data.
      if (isset($result['data'])) {
        $unserialized_data = unserialize($result['data']);
        // Add the titleoverwrite config if it is not there.
        if (!isset($unserialized_data['settings']['handler_settings']['behaviors']['remoteoverride_field_behavior']['status'])) {
          $unserialized_data['settings']['handler_settings']['behaviors']['remoteoverride_field_behavior']['status'] = 1;
          $unserialized_data['settings']['handler_settings']['behaviors']['remoteoverride_field_behavior']['overwrite_title_mandatory'] = $mandatory;
          $unserialized_data['settings']['handler_settings']['behaviors']['remoteoverride_field_behavior']['overrideable_fields'][$field] = $field;
          // Store back the data.
          db_update('field_config')
            ->fields(array(
              'data' => serialize($unserialized_data),
            ))
            ->condition('field_name', $field_name, '=')
            ->execute();
        }
      }
    }
    else {
      throw new \Exception('Trying to upgrade a non existing field');
    }
  }
}

/**
 * Gets the readable label of the entity field.
 *
 * @param array $handler_settings
 *   The handler settings.
 * @param string $field_name
 *   The field to get the data for.
 *
 * @return string
 *   The label.
 */
function _entityreference_remoteoverride_get_readable_label($handler_settings, $field_name) {
  $entity_type = $handler_settings['target_type'];
  $target_bundle = reset($handler_settings['handler_settings']['target_bundles']);
  if ($instance = field_info_instance($entity_type, $field_name, $target_bundle)) {
    return $instance['label'];
  }
  return FALSE;
}

/**
 * Helper function to generate the system name.
 */
function _entityreference_remoteoverride_generate_system_name($field_name) {
  return 'er_override_' . $field_name;
}
