<?php
/**
 * @file
 * Cwt_core.ds_fields.
 */

/**
 * Implements hook_ds_fields_info().
 */
function cwt_core_ds_fields_info($entity_type) {
  $fields = array();

  $fields['editorial_section_name'] = array(

    // title: title of the field.
    'title' => t('Editorial section name'),

    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_nexteuropa_ds_fields_token_replace',

    // properties: can have different keys.
    'properties' => array(
      'value' => t('By') . ' ' . '[node:field-editorial-section:name_field]',
    ),
  );

  $fields['editorial_section_name_teaser'] = array(

    // title: title of the field.
    'title' => t('Editorial section name for teasers'),

    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_nexteuropa_ds_fields_token_replace',

    // properties: can have different keys.
    'properties' => array(
      'value' => t('Published by') . ' ' . '[node:field-editorial-section:name_field]',
    ),
  );

  // This field will render the legacy title.
  $fields['dt_core_legacy_title'] = array(
    // title: title of the field.
    'title' => t('Legacy title layout'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_cwt_core_legacy_title',
  );

  return array('node' => $fields);

};

/**
 * Custom function for single token replacement in a field.
 */
function _cwt_core_legacy_title($field) {
  // Simulate page variables.
  if (isset($field['entity']) && isset($field['entity']->type)) {
    $variables = array();
    $variables['node'] = $field['entity'];
    return _cwt_core_custom_page_title($variables);
  }
}
