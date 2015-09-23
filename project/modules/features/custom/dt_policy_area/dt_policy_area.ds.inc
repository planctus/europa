<?php
/**
 * @file
 * dt_policy_area.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_policy_area_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|policy_area|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'policy_area';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'latest_announcements_block' => array(
      'weight' => '1',
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
    'children_policies' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'children_policy_areas' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h1',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_core_introduction' => array(
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
    'field_core_persons' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Related commissioners',
        ),
      ),
    ),
  );
  $export['node|policy_area|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|policy_area|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'policy_area';
  $ds_fieldsetting->view_mode = 'teaser';
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
  $export['node|policy_area|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|policy_area|title';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'policy_area';
  $ds_fieldsetting->view_mode = 'title';
  $ds_fieldsetting->settings = array(
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|policy_area|title'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function dt_policy_area_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'children_policies';
  $ds_field->label = 'Children policies';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'policy_area|*';
  $ds_field->properties = array(
    'block' => 'views|c47c600594924567e40e41a9b0e110f6',
    'block_render' => '1',
  );
  $export['children_policies'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'children_policy_areas';
  $ds_field->label = 'Children policy areas';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'policy_area|*';
  $ds_field->properties = array(
    'block' => 'views|ba106683ecf39aa60372ee99a00fd9aa',
    'block_render' => '1',
  );
  $export['children_policy_areas'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_policy_area_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|policy_area|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'policy_area';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ne_bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'group_policy_area_meta',
        2 => 'title_field',
        3 => 'content_type_label',
        4 => 'field_core_introduction',
        5 => 'field_core_description',
      ),
      'central' => array(
        1 => 'latest_announcements_block',
        8 => 'group_policy',
        9 => 'children_policy_areas',
        10 => 'children_policies',
        11 => 'group_policy_area_latest',
        12 => 'field_core_social_network_links',
        13 => 'group_latest_main',
        14 => 'group_latest_sidebar',
      ),
      'top' => array(
        6 => 'group_policy_area_contextual',
        7 => 'field_core_persons',
      ),
    ),
    'fields' => array(
      'group_policy_area_meta' => 'left_header',
      'latest_announcements_block' => 'central',
      'title_field' => 'left_header',
      'content_type_label' => 'left_header',
      'field_core_introduction' => 'left_header',
      'field_core_description' => 'left_header',
      'group_policy_area_contextual' => 'top',
      'field_core_persons' => 'top',
      'group_policy' => 'central',
      'children_policy_areas' => 'central',
      'children_policies' => 'central',
      'group_policy_area_latest' => 'central',
      'field_core_social_network_links' => 'central',
      'group_latest_main' => 'central',
      'group_latest_sidebar' => 'central',
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
  $export['node|policy_area|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|policy_area|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'policy_area';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ne_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'title',
        1 => 'field_core_description',
      ),
    ),
    'fields' => array(
      'title' => 'main',
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
  $export['node|policy_area|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|policy_area|title';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'policy_area';
  $ds_layout->view_mode = 'title';
  $ds_layout->layout = 'ne_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'title_field',
      ),
    ),
    'fields' => array(
      'title_field' => 'main',
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
  $export['node|policy_area|title'] = $ds_layout;

  return $export;
}
