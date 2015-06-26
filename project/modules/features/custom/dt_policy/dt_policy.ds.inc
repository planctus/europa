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
  $ds_fieldsetting->id = 'node|policy|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'policy';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'policy_input_consultation' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'policy_input_not_consultation' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'content_type_label' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'meta__item meta__item--type',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_core_department' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Related departments',
        ),
      ),
    ),
    'field_core_priorities' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Part of priority',
        ),
      ),
    ),
    'field_core_topics' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Part of topic',
        ),
      ),
    ),
    'field_core_persons' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Related commissioners',
        ),
      ),
    ),
  );
  $export['node|policy|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_policy_ds_layout_settings_info() {
  $export = array();

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
        6 => 'field_policy_implementations',
        7 => 'group_policy_tab_actions',
        8 => 'policy_input_consultation',
        9 => 'group_policy_tab_latest',
        11 => 'group_policy_tabs',
        12 => 'group_policy_tab_details',
      ),
      'left_header' => array(
        1 => 'group_policy_meta',
        2 => 'content_type_label',
        3 => 'title',
        4 => 'field_policy_introduction',
      ),
      'top' => array(
        5 => 'group_policy_contextual',
        10 => 'field_core_priorities',
        13 => 'field_core_topics',
        14 => 'field_core_persons',
        15 => 'field_core_department',
      ),
    ),
    'fields' => array(
      'policy_input_not_consultation' => 'central',
      'group_policy_meta' => 'left_header',
      'content_type_label' => 'left_header',
      'title' => 'left_header',
      'field_policy_introduction' => 'left_header',
      'group_policy_contextual' => 'top',
      'field_policy_implementations' => 'central',
      'group_policy_tab_actions' => 'central',
      'policy_input_consultation' => 'central',
      'group_policy_tab_latest' => 'central',
      'field_core_priorities' => 'top',
      'group_policy_tabs' => 'central',
      'group_policy_tab_details' => 'central',
      'field_core_topics' => 'top',
      'field_core_persons' => 'top',
      'field_core_department' => 'top',
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

  return $export;
}
