<?php
/**
 * @file
 * dt_contact.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_contact_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|contact|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'contact';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_contact_email_address' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Email',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_contact_link_form' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
    'field_contact_phone_number' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_contact_postal_mail' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['node|contact|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|contact|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'contact';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h3',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field field--labeled-align',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'field__items',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'field_contact_email_address' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Email',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_contact_link_form' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field field--labeled-align',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'field__items',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'field_contact_phone_number' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_contact_postal_mail' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['node|contact|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_contact_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|contact|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'contact';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'field_contact_phone_number',
        2 => 'field_contact_postal_mail',
        3 => 'field_contact_email_address',
        4 => 'field_contact_link_form',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'field_contact_phone_number' => 'ds_content',
      'field_contact_postal_mail' => 'ds_content',
      'field_contact_email_address' => 'ds_content',
      'field_contact_link_form' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
  );
  $export['node|contact|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|contact|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'contact';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'body',
        2 => 'field_contact_phone_number',
        3 => 'field_contact_postal_mail',
        4 => 'field_contact_email_address',
        5 => 'field_contact_link_form',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'body' => 'ds_content',
      'field_contact_phone_number' => 'ds_content',
      'field_contact_postal_mail' => 'ds_content',
      'field_contact_email_address' => 'ds_content',
      'field_contact_link_form' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
  );
  $export['node|contact|teaser'] = $ds_layout;

  return $export;
}
