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
  $ds_fieldsetting->id = 'node|policy|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'policy';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'latest_announcements_block' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'content_type_label' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'policy_actions' => array(
      'weight' => '43',
      'label' => 'hidden',
      'format' => 'default',
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
    'field_policy_detail_objectives' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb-col' => TRUE,
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
  );
  $export['node|policy|full'] = $ds_fieldsetting;

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

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|policy|title';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'policy';
  $ds_fieldsetting->view_mode = 'title';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => '',
        'class' => '',
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|policy|title'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function dt_policy_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'policy_actions';
  $ds_field->label = 'Policy actions';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'policy|full';
  $ds_field->properties = array(
    'block' => 'dt_policy|dt_policy_actions',
    'block_render' => '1',
  );
  $export['policy_actions'] = $ds_field;

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
      'left_header' => array(
        0 => 'content_type_label',
        1 => 'group_policy_meta',
        3 => 'title',
        4 => 'field_core_introduction',
      ),
      'central' => array(
        2 => 'latest_announcements_block',
        6 => 'group_policy_tabs',
        7 => 'group_policy_tab_actions',
        8 => 'group_policy_tab_latest',
        11 => 'group_policy_tab_details',
        14 => 'field_policy_detail_objectives',
        15 => 'field_policy_detail_body',
        16 => 'group_policy_documents',
        17 => 'field_policy_keyfiles',
        18 => 'group_latest',
        19 => 'group_latest_main',
        20 => 'group_latest_sidebar',
        21 => 'group_policies_wrapper',
        22 => 'policy_actions',
        23 => 'field_policy_next_steps',
      ),
      'top' => array(
        7 => 'group_policy_contextual',
        10 => 'field_core_priorities',
        12 => 'field_core_topics',
        14 => 'field_core_persons',
        15 => 'field_core_department',
      ),
    ),
    'fields' => array(
      'content_type_label' => 'left_header',
      'group_policy_meta' => 'left_header',
      'latest_announcements_block' => 'central',
      'title' => 'left_header',
      'field_core_introduction' => 'left_header',
      'group_policy_contextual' => 'top',
      'group_policy_tabs' => 'central',
      'group_policy_tab_actions' => 'central',
      'field_core_priorities' => 'top',
      'group_policy_tab_latest' => 'central',
      'field_core_topics' => 'top',
      'group_policy_tab_details' => 'central',
      'field_core_persons' => 'top',
      'field_core_department' => 'top',
      'field_policy_detail_objectives' => 'central',
      'field_policy_detail_body' => 'central',
      'group_policy_documents' => 'central',
      'field_policy_keyfiles' => 'central',
      'group_latest' => 'central',
      'group_latest_main' => 'central',
      'group_latest_sidebar' => 'central',
      'group_policies_wrapper' => 'central',
      'policy_actions' => 'central',
      'field_policy_next_steps' => 'central',
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

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|policy|title';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'policy';
  $ds_layout->view_mode = 'title';
  $ds_layout->layout = 'ne_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'title',
      ),
    ),
    'fields' => array(
      'title' => 'main',
    ),
    'classes' => array(),
    'wrappers' => array(
      'main' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|policy|title'] = $ds_layout;

  return $export;
}
