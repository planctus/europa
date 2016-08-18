<?php

/**
 * @file
 * dt_call_for_proposal_default.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_call_for_proposal_default_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|call_for_proposal|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'call_for_proposal';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'content_type_label' => array(
      'weight' => '1',
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
        'ft' => array(),
      ),
    ),
    'in_page_navigation' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_cfp_status' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_nexteuropa_formatters_meta_item',
          'meta_modifier' => 'meta__item--type',
        ),
      ),
    ),
  );
  $export['node|call_for_proposal|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|call_for_proposal|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'call_for_proposal';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'content_type_label' => array(
      'weight' => '14',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_nexteuropa_formatters_meta_item',
          'meta_modifier' => 'meta__item--type',
        ),
      ),
    ),
    'field_cfp_status' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_nexteuropa_formatters_meta_item',
          'meta_modifier' => 'meta__item--type',
        ),
      ),
    ),
  );
  $export['node|call_for_proposal|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_call_for_proposal_default_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|call_for_proposal|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'call_for_proposal';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ne_bootstrap_3_9_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'group_cfp_meta',
        1 => 'content_type_label',
        2 => 'title',
        3 => 'field_core_introduction',
        4 => 'field_cfp_status',
      ),
      'central' => array(
        5 => 'field_core_description',
        7 => 'field_core_background',
        8 => 'group_cfp_main_section',
        9 => 'group_cfp_departments',
        10 => 'group_cfp_topics',
        11 => 'group_cfp_documents',
        12 => 'field_core_publications',
        13 => 'field_core_departments',
        14 => 'field_core_topics',
      ),
      'left' => array(
        6 => 'in_page_navigation',
      ),
    ),
    'fields' => array(
      'group_cfp_meta' => 'left_header',
      'content_type_label' => 'left_header',
      'title' => 'left_header',
      'field_core_introduction' => 'left_header',
      'field_cfp_status' => 'left_header',
      'field_core_description' => 'central',
      'in_page_navigation' => 'left',
      'field_core_background' => 'central',
      'group_cfp_main_section' => 'central',
      'group_cfp_departments' => 'central',
      'group_cfp_topics' => 'central',
      'group_cfp_documents' => 'central',
      'field_core_publications' => 'central',
      'field_core_departments' => 'central',
      'field_core_topics' => 'central',
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
  $export['node|call_for_proposal|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|call_for_proposal|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'call_for_proposal';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ne_2col_sidebar_no_link';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'group_cfp_meta',
        1 => 'title_field',
        2 => 'field_core_description',
        3 => 'content_type_label',
        4 => 'field_cfp_status',
      ),
    ),
    'fields' => array(
      'group_cfp_meta' => 'main',
      'title_field' => 'main',
      'field_core_description' => 'main',
      'content_type_label' => 'main',
      'field_cfp_status' => 'main',
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
  $export['node|call_for_proposal|teaser'] = $ds_layout;

  return $export;
}
