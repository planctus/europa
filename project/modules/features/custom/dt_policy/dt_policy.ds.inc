<?php
/**
 * @file
 * dt_policy.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_policy_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|policy|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'policy';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|policy|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|policy|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'policy';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h3',
          'fi-cl' => 'listing__title',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_core_description' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|policy|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_policy_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|policy|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'policy';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ne_bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'title',
      ),
    ),
    'fields' => array(
      'title' => 'left_header',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left_header' => 'div',
      'right_header' => 'div',
      'top' => 'div',
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|policy|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|policy|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'policy';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ne_bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'policy_input_not_consultation',
        2 => 'policy_input_consultation',
        6 => 'group_policy_tabs',
        7 => 'group_policy_tab_actions',
        8 => 'group_policy_tab_latest',
        10 => 'field_policy_implementations',
        11 => 'group_policy_tab_details',
        16 => 'field_policy_detail_body',
        17 => 'field_policy_detail_objectives',
        18 => 'field_policy_keyfiles',
      ),
      'left_header' => array(
        1 => 'group_policy_meta',
        3 => 'title',
        4 => 'field_core_introduction',
        15 => 'content_type_label',
      ),
      'top' => array(
        5 => 'group_policy_contextual',
        9 => 'field_core_priorities',
        12 => 'field_core_topics',
        13 => 'field_core_persons',
        14 => 'field_core_department',
      ),
    ),
    'fields' => array(
      'policy_input_not_consultation' => 'central',
      'group_policy_meta' => 'left_header',
      'policy_input_consultation' => 'central',
      'title' => 'left_header',
      'field_core_introduction' => 'left_header',
      'group_policy_contextual' => 'top',
      'group_policy_tabs' => 'central',
      'group_policy_tab_actions' => 'central',
      'group_policy_tab_latest' => 'central',
      'field_core_priorities' => 'top',
      'field_policy_implementations' => 'central',
      'group_policy_tab_details' => 'central',
      'field_core_topics' => 'top',
      'field_core_persons' => 'top',
      'field_core_department' => 'top',
      'content_type_label' => 'left_header',
      'field_policy_detail_body' => 'central',
      'field_policy_detail_objectives' => 'central',
      'field_policy_keyfiles' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left_header' => 'div',
      'right_header' => 'div',
      'top' => 'div',
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|policy|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|policy|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'policy';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ne_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'title_field',
        1 => 'field_core_description',
      ),
    ),
    'fields' => array(
      'title_field' => 'main',
      'field_core_description' => 'main',
    ),
    'classes' => array(),
    'wrappers' => array(
      'main' => 'div',
      'second' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|policy|teaser'] = $ds_layout;

  return $export;
}
