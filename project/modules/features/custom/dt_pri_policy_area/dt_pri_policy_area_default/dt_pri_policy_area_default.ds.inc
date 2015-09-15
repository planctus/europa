<?php
/**
 * @file
 * dt_pri_policy_area_default.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_pri_policy_area_default_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|priority_policy_area|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'priority_policy_area';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'latest_announcements_block' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'content_type_label' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
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
    'field_core_links' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => 'listing--title',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => 'listing__item listing__item-link',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_core_objective' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['node|priority_policy_area|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|priority_policy_area|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'priority_policy_area';
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
    'field_core_image' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|priority_policy_area|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_pri_policy_area_default_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|priority_policy_area|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'priority_policy_area';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ne_bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'group_pri_pol_area_meta',
        1 => 'content_type_label',
        2 => 'title',
        3 => 'field_core_introduction',
      ),
      'top' => array(
        4 => 'group_pri_pol_area_contextual',
        5 => 'field_core_persons',
        6 => 'field_core_banner',
      ),
      'central' => array(
        7 => 'group_pri_pol_policy_areas',
        8 => 'field_core_background',
        9 => 'group_pri_pol_area_latest',
        10 => 'field_core_objective',
        11 => 'group_pri_pol_area_background',
        12 => 'group_pri_pol_area_documents',
        13 => 'field_core_publications',
        14 => 'field_core_featured_item',
        15 => 'field_core_links',
        16 => 'group_pri_pol_area_whatnext',
        17 => 'latest_announcements_block',
        18 => 'group_pri_pol_area_related',
        19 => 'field_core_next_steps',
        20 => 'field_core_section_intro',
        21 => 'field_core_child_policies',
        22 => 'field_core_social_network_links',
        23 => 'group_pri_pol_area_latest_main',
        24 => 'group_pri_pol_area_latest_sbar',
      ),
    ),
    'fields' => array(
      'group_pri_pol_area_meta' => 'left_header',
      'content_type_label' => 'left_header',
      'title' => 'left_header',
      'field_core_introduction' => 'left_header',
      'group_pri_pol_area_contextual' => 'top',
      'field_core_persons' => 'top',
      'field_core_banner' => 'top',
      'group_pri_pol_policy_areas' => 'central',
      'field_core_background' => 'central',
      'group_pri_pol_area_latest' => 'central',
      'field_core_objective' => 'central',
      'group_pri_pol_area_background' => 'central',
      'group_pri_pol_area_documents' => 'central',
      'field_core_publications' => 'central',
      'field_core_featured_item' => 'central',
      'field_core_links' => 'central',
      'group_pri_pol_area_whatnext' => 'central',
      'latest_announcements_block' => 'central',
      'group_pri_pol_area_related' => 'central',
      'field_core_next_steps' => 'central',
      'field_core_section_intro' => 'central',
      'field_core_child_policies' => 'central',
      'field_core_social_network_links' => 'central',
      'group_pri_pol_area_latest_main' => 'central',
      'group_pri_pol_area_latest_sbar' => 'central',
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
  $export['node|priority_policy_area|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|priority_policy_area|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'priority_policy_area';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ne_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'title_field',
        1 => 'field_core_description',
      ),
      'second' => array(
        2 => 'field_core_image',
      ),
    ),
    'fields' => array(
      'title_field' => 'main',
      'field_core_description' => 'main',
      'field_core_image' => 'second',
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
  $export['node|priority_policy_area|teaser'] = $ds_layout;

  return $export;
}
