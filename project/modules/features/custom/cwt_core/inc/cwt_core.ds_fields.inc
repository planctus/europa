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

  $fields['editorial_section_name_teser'] = array(

    // title: title of the field.
    'title' => t('Editorial section name for tesers'),

    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_nexteuropa_ds_fields_token_replace',

    // properties: can have different keys.
    'properties' => array(
      'value' => t('Published by') . ' ' . '[node:field-editorial-section:name_field]',
    ),
  );

  return array('node' => $fields);

};
