<?php

/**
 * @file
 * dt_page_extended.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_page_extended_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|basic_page|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'basic_page';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'priorities_preprocess' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'in_page_navigation' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'announcement_block' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_featured_item' => 1,
        'show_social_media' => 1,
        'label' => 'Latest',
      ),
    ),
    'field_core_banner' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_core_departments' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Departments',
        ),
      ),
    ),
    'field_core_persons' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Commissioners',
        ),
      ),
    ),
    'field_core_policy_area' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Policy areas',
        ),
      ),
    ),
    'field_core_priorities' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Political priorities',
        ),
      ),
    ),
    'field_core_topics' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Topics',
        ),
      ),
    ),
    'field_core_children' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_nexteuropa_formatters_section_item',
        ),
      ),
    ),
  );
  $export['node|basic_page|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|basic_page|structured_navigation';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'basic_page';
  $ds_fieldsetting->view_mode = 'structured_navigation';
  $ds_fieldsetting->settings = array(
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_core_description' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_core_children' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_core_quick_nav_links' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|basic_page|structured_navigation'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|basic_page|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'basic_page';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(),
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
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|basic_page|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|basic_page|title';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'basic_page';
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
        'ft' => array(),
      ),
    ),
  );
  $export['node|basic_page|title'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_page_extended_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|basic_page|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'basic_page';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ne_bootstrap_3_9_stacked_conditional';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'title',
        1 => 'field_core_introduction',
      ),
      'top' => array(
        2 => 'field_core_children',
        3 => 'group_page_contextual_navigation',
        4 => 'field_core_banner',
        17 => 'field_core_priorities',
        18 => 'field_core_policy_area',
        19 => 'field_core_departments',
        20 => 'field_core_persons',
        21 => 'field_core_topics',
      ),
      'left' => array(
        5 => 'in_page_navigation',
      ),
      'central' => array(
        6 => 'priorities_preprocess',
        7 => 'group_page_priorities',
        8 => 'body',
        9 => 'group_page_free_field',
        10 => 'announcement_block',
        11 => 'field_core_next_steps',
        12 => 'group_page_next_steps',
        13 => 'group_page_documents',
        14 => 'group_page_related_links',
        15 => 'field_core_publications',
        16 => 'field_core_links',
      ),
    ),
    'fields' => array(
      'title' => 'left_header',
      'field_core_introduction' => 'left_header',
      'field_core_children' => 'top',
      'group_page_contextual_navigation' => 'top',
      'field_core_banner' => 'top',
      'in_page_navigation' => 'left',
      'priorities_preprocess' => 'central',
      'group_page_priorities' => 'central',
      'body' => 'central',
      'group_page_free_field' => 'central',
      'announcement_block' => 'central',
      'field_core_next_steps' => 'central',
      'group_page_next_steps' => 'central',
      'group_page_documents' => 'central',
      'group_page_related_links' => 'central',
      'field_core_publications' => 'central',
      'field_core_links' => 'central',
      'field_core_priorities' => 'top',
      'field_core_policy_area' => 'top',
      'field_core_departments' => 'top',
      'field_core_persons' => 'top',
      'field_core_topics' => 'top',
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
  $export['node|basic_page|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|basic_page|structured_navigation';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'basic_page';
  $ds_layout->view_mode = 'structured_navigation';
  $ds_layout->layout = 'ne_1col_section_item';
  $ds_layout->settings = array(
    'regions' => array(
      'title' => array(
        0 => 'title_field',
      ),
      'description' => array(
        1 => 'field_core_description',
      ),
      'children' => array(
        2 => 'field_core_children',
      ),
      'links' => array(
        3 => 'field_core_quick_nav_links',
      ),
    ),
    'fields' => array(
      'title_field' => 'title',
      'field_core_description' => 'description',
      'field_core_children' => 'children',
      'field_core_quick_nav_links' => 'links',
    ),
    'classes' => array(),
    'wrappers' => array(
      'title' => 'div',
      'description' => 'div',
      'children' => 'div',
      'links' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|basic_page|structured_navigation'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|basic_page|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'basic_page';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ne_2col_sidebar_no_link';
  $ds_layout->settings = array(
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
    'layout_disable_css' => FALSE,
    'regions' => array(
      'main' => array(
        0 => 'title_field',
        1 => 'field_core_description',
      ),
      'second' => array(
        0 => 'field_core_image',
        1 => 'field_core_link',
      ),
    ),
    'fields' => array(
      'title_field' => 'main',
      'field_core_description' => 'main',
      'field_core_image' => 'second',
      'field_core_link' => 'second',
    ),
  );
  $export['node|basic_page|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|basic_page|title';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'basic_page';
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
  $export['node|basic_page|title'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function dt_page_extended_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'structured_navigation';
  $ds_view_mode->label = 'Structured Navigation';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['structured_navigation'] = $ds_view_mode;

  return $export;
}
