<?php
/**
 * @file
 * dt_law_default.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_law_default_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|law|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'law';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'content_type_label' => array(
      'weight' => '29',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_nexteuropa_formatters_meta_item',
          'meta_modifier' => 'meta__item--type',
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
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'in_page_navigation' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_core_introduction' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_law_status' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_nexteuropa_formatters_meta_item',
          'meta_modifier' => 'meta__item--type',
        ),
      ),
    ),
    'field_core_background' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
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
  $export['node|law|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|law|structured_navigation';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'law';
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
  );
  $export['node|law|structured_navigation'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|law|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'law';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'content_type_label' => array(
      'weight' => '14',
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
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_law_status' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'meta__item meta__item--type',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|law|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_law_default_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|law|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'law';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ne_bootstrap_3_9_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'group_law_meta',
        1 => 'title',
        2 => 'field_core_introduction',
        15 => 'content_type_label',
        16 => 'field_law_status',
      ),
      'top' => array(
        3 => 'field_core_children',
      ),
      'left' => array(
        4 => 'in_page_navigation',
      ),
      'central' => array(
        5 => 'field_core_topics',
        6 => 'field_core_publications',
        7 => 'field_core_background',
        8 => 'group_law_departments',
        9 => 'group_law_topics',
        10 => 'group_law_policies',
        11 => 'group_law_priorities',
        12 => 'field_core_departments',
        13 => 'group_law_documents',
        14 => 'field_core_policies',
        17 => 'field_core_priorities',
      ),
    ),
    'fields' => array(
      'group_law_meta' => 'left_header',
      'title' => 'left_header',
      'field_core_introduction' => 'left_header',
      'field_core_children' => 'top',
      'in_page_navigation' => 'left',
      'field_core_topics' => 'central',
      'field_core_publications' => 'central',
      'field_core_background' => 'central',
      'group_law_departments' => 'central',
      'group_law_topics' => 'central',
      'group_law_policies' => 'central',
      'group_law_priorities' => 'central',
      'field_core_departments' => 'central',
      'group_law_documents' => 'central',
      'field_core_policies' => 'central',
      'content_type_label' => 'left_header',
      'field_law_status' => 'left_header',
      'field_core_priorities' => 'central',
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
  $export['node|law|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|law|structured_navigation';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'law';
  $ds_layout->view_mode = 'structured_navigation';
  $ds_layout->layout = 'ne_1col_section_item';
  $ds_layout->settings = array(
    'regions' => array(
      'children' => array(
        0 => 'field_core_children',
      ),
      'title' => array(
        1 => 'title_field',
      ),
      'description' => array(
        2 => 'field_core_description',
      ),
    ),
    'fields' => array(
      'field_core_children' => 'children',
      'title_field' => 'title',
      'field_core_description' => 'description',
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
  $export['node|law|structured_navigation'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|law|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'law';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ne_2col_sidebar_no_link';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'group_law_meta',
        1 => 'title_field',
        2 => 'field_core_description',
        3 => 'content_type_label',
        4 => 'field_law_status',
      ),
    ),
    'fields' => array(
      'group_law_meta' => 'main',
      'title_field' => 'main',
      'field_core_description' => 'main',
      'content_type_label' => 'main',
      'field_law_status' => 'main',
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
  $export['node|law|teaser'] = $ds_layout;

  return $export;
}
