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
 *
 * @return bool
 *   True if the update went fine. In other cases FALSE.
 */
function _entityreference_titleoverwrite_add_table_field($field_name) {
  // The actual field to add to the schema.
  $field_schema_name = $field_name . '_title_override';

  // The new fields properties.
  $field_schema_information = array(
    'type' => 'varchar',
    'description' => 'Title override',
    'length' => 255,
    'not null' => FALSE,
  );

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
    if (!isset($unserialized_data['settings']['handler_settings']['behaviors']['titleoverwrite_field_behavior']['status'])) {
      $unserialized_data['settings']['handler_settings']['behaviors']['titleoverwrite_field_behavior']['status'] = 1;
      $unserialized_data['settings']['handler_settings']['behaviors']['titleoverwrite_field_behavior']['overwrite_title_mandatory'] = 0;
      // Store back the data.
      $update_query = db_update('field_config')
        ->fields(array(
          'data' => serialize($unserialized_data),
        ))
        ->condition('field_name', $field_name, '=')
        ->execute();
    }
  }

  if (isset($update_query) && $update_query == 1) {
    return TRUE;
  }
  return FALSE;
}
