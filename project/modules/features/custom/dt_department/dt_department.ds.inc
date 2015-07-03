<?php
/**
 * @file
 * dt_department.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_department_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|department|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'department';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'latest_announcements_block' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'in_page_navigation' => array(
      'weight' => '5',
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
    'field_core_abbreviation' => array(
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
    'field_core_contact' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_core_ecorganisation' => array(
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
    'field_core_persons' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_core_legacy_links' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'btn-group',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'field_core_priorities' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_core_links' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Related links',
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => 'listing listing--title listing--no-padding',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => 'listing__item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|department|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|department|meta';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'department';
  $ds_fieldsetting->view_mode = 'meta';
  $ds_fieldsetting->settings = array(
    'field_core_abbreviation' => array(
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
    'field_core_ecorganisation' => array(
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
  );
  $export['node|department|meta'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function dt_department_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'find_a_staff_member';
  $ds_field->label = 'Find a staff member';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'department|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<a href="#"><span>Find a staff member</span></a>',
      'format' => 'basic_html',
    ),
    'use_token' => 0,
  );
  $export['find_a_staff_member'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_department_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|department|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'department';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ne_bootstrap_3_9_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'group_department_meta',
        2 => 'title',
        4 => 'field_core_ecorganisation',
        6 => 'field_core_introduction',
        7 => 'field_core_abbreviation',
        10 => 'field_core_legacy_links',
      ),
      'central' => array(
        1 => 'latest_announcements_block',
        3 => 'field_core_persons',
        5 => 'field_core_social_network_links',
        8 => 'field_department_organigram',
        9 => 'field_department_staff_search',
        13 => 'group_department_latest',
        14 => 'field_department_work_areas_sent',
        15 => 'group_department_responsibilit',
        16 => 'field_core_topics',
        17 => 'group_department_leadership',
        18 => 'field_department_intro_sentence',
        19 => 'field_core_contact',
        20 => 'group_department_contact',
        21 => 'field_core_priorities',
        22 => 'field_department_tasks',
        23 => 'field_department_tasks_desc',
        24 => 'field_department_mission',
        25 => 'field_department_plans_reports',
        26 => 'group_latest_main',
        27 => 'group_latest_sidebar',
      ),
      'right_header' => array(
        11 => 'field_core_links',
      ),
      'left' => array(
        12 => 'in_page_navigation',
      ),
    ),
    'fields' => array(
      'group_department_meta' => 'left_header',
      'latest_announcements_block' => 'central',
      'title' => 'left_header',
      'field_core_persons' => 'central',
      'field_core_ecorganisation' => 'left_header',
      'field_core_social_network_links' => 'central',
      'field_core_introduction' => 'left_header',
      'field_core_abbreviation' => 'left_header',
      'field_department_organigram' => 'central',
      'field_department_staff_search' => 'central',
      'field_core_legacy_links' => 'left_header',
      'field_core_links' => 'right_header',
      'in_page_navigation' => 'left',
      'group_department_latest' => 'central',
      'field_department_work_areas_sent' => 'central',
      'group_department_responsibilit' => 'central',
      'field_core_topics' => 'central',
      'group_department_leadership' => 'central',
      'field_department_intro_sentence' => 'central',
      'field_core_contact' => 'central',
      'group_department_contact' => 'central',
      'field_core_priorities' => 'central',
      'field_department_tasks' => 'central',
      'field_department_tasks_desc' => 'central',
      'field_department_mission' => 'central',
      'field_department_plans_reports' => 'central',
      'group_latest_main' => 'central',
      'group_latest_sidebar' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left_header' => 'div',
      'right_header' => 'div',
      'top' => 'div',
      'left' => 'div',
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|department|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|department|meta';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'department';
  $ds_layout->view_mode = 'meta';
  $ds_layout->layout = 'ne_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'group_department_meta',
        1 => 'field_core_ecorganisation',
        2 => 'field_core_abbreviation',
        3 => 'title_field',
      ),
    ),
    'fields' => array(
      'group_department_meta' => 'main',
      'field_core_ecorganisation' => 'main',
      'field_core_abbreviation' => 'main',
      'title_field' => 'main',
    ),
    'classes' => array(),
    'wrappers' => array(
      'main' => 'div',
      'second' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => 'content',
    'layout_link_custom' => '',
  );
  $export['node|department|meta'] = $ds_layout;

  return $export;
}
