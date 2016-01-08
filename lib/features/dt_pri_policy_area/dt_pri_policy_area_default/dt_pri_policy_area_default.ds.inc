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
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'content_type_label' => array(
      'weight' => '0',
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
    'field_core_banner' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_core_featured_item' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_core_policy_areas' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Part of priority',
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
    'field_core_section_intro' => array(
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
    'field_core_parent' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Priority',
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
        0 => 'content_type_label',
        1 => 'group_pri_pol_area_meta',
        4 => 'title',
        7 => 'field_core_introduction',
      ),
      'central' => array(
        2 => 'field_core_featured_item',
        5 => 'latest_announcements_block',
        12 => 'group_pri_pol_policy_areas',
        14 => 'field_core_background',
        15 => 'group_pri_pol_area_latest',
        16 => 'field_core_objective',
        17 => 'group_pri_pol_area_background',
        18 => 'group_pri_pol_area_documents',
        19 => 'group_pri_pol_area_whatnext',
        20 => 'field_core_publications',
        21 => 'field_core_links',
        22 => 'group_pri_pol_area_related',
        23 => 'field_core_next_steps',
        24 => 'field_core_section_intro',
        25 => 'field_core_child_policies',
        26 => 'field_core_social_network_links',
        27 => 'group_pri_pol_area_latest_main',
        28 => 'group_pri_pol_area_latest_sbar',
      ),
      'top' => array(
        3 => 'field_core_policy_areas',
        6 => 'field_core_topics',
        8 => 'field_core_persons',
        9 => 'group_pri_pol_area_contextual',
        10 => 'field_core_departments',
        11 => 'field_core_banner',
        13 => 'field_core_parent',
      ),
    ),
    'fields' => array(
      'content_type_label' => 'left_header',
      'group_pri_pol_area_meta' => 'left_header',
      'field_core_featured_item' => 'central',
      'field_core_policy_areas' => 'top',
      'title' => 'left_header',
      'latest_announcements_block' => 'central',
      'field_core_topics' => 'top',
      'field_core_introduction' => 'left_header',
      'field_core_persons' => 'top',
      'group_pri_pol_area_contextual' => 'top',
      'field_core_departments' => 'top',
      'field_core_banner' => 'top',
      'group_pri_pol_policy_areas' => 'central',
      'field_core_parent' => 'top',
      'field_core_background' => 'central',
      'group_pri_pol_area_latest' => 'central',
      'field_core_objective' => 'central',
      'group_pri_pol_area_background' => 'central',
      'group_pri_pol_area_documents' => 'central',
      'group_pri_pol_area_whatnext' => 'central',
      'field_core_publications' => 'central',
      'field_core_links' => 'central',
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
