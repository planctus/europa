<?php
/**
 * @file
 * dt_priority_default.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_priority_default_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|priority|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'priority';
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
    'field_core_featured_item' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_core_banner' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
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
  );
  $export['node|priority|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|priority|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'priority';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'content_type_label' => array(
      'weight' => '2',
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
  $export['node|priority|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_priority_default_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|priority|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'priority';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ne_bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'content_type_label',
        3 => 'group_priority_meta',
        6 => 'title',
        7 => 'field_core_introduction',
      ),
      'top' => array(
        1 => 'field_core_departments',
        2 => 'field_core_topics',
        8 => 'group_priority_contextual',
        9 => 'field_core_banner',
        22 => 'field_core_persons',
      ),
      'central' => array(
        4 => 'field_core_featured_item',
        5 => 'latest_announcements_block',
        10 => 'group_pri_pol_policy_areas',
        11 => 'group_priority_latest',
        12 => 'group_priority_background',
        13 => 'group_priority_documents',
        14 => 'group_priority_whatnext',
        15 => 'group_priority_related',
        16 => 'field_core_next_steps',
        17 => 'field_core_links',
        18 => 'field_core_section_intro',
        19 => 'field_core_publications',
        20 => 'field_core_child_policies',
        21 => 'field_core_background',
        23 => 'field_core_social_network_links',
        24 => 'field_core_objective',
        25 => 'group_priority_latest_main',
        26 => 'group_priority_latest_sbar',
      ),
    ),
    'fields' => array(
      'content_type_label' => 'left_header',
      'field_core_departments' => 'top',
      'field_core_topics' => 'top',
      'group_priority_meta' => 'left_header',
      'field_core_featured_item' => 'central',
      'latest_announcements_block' => 'central',
      'title' => 'left_header',
      'field_core_introduction' => 'left_header',
      'group_priority_contextual' => 'top',
      'field_core_banner' => 'top',
      'group_pri_pol_policy_areas' => 'central',
      'group_priority_latest' => 'central',
      'group_priority_background' => 'central',
      'group_priority_documents' => 'central',
      'group_priority_whatnext' => 'central',
      'group_priority_related' => 'central',
      'field_core_next_steps' => 'central',
      'field_core_links' => 'central',
      'field_core_section_intro' => 'central',
      'field_core_publications' => 'central',
      'field_core_child_policies' => 'central',
      'field_core_background' => 'central',
      'field_core_persons' => 'top',
      'field_core_social_network_links' => 'central',
      'field_core_objective' => 'central',
      'group_priority_latest_main' => 'central',
      'group_priority_latest_sbar' => 'central',
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
  $export['node|priority|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|priority|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'priority';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ne_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'group_priority_meta',
        1 => 'title_field',
        2 => 'content_type_label',
        3 => 'field_core_description',
      ),
      'second' => array(
        4 => 'field_core_image',
      ),
    ),
    'fields' => array(
      'group_priority_meta' => 'main',
      'title_field' => 'main',
      'content_type_label' => 'main',
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
  $export['node|priority|teaser'] = $ds_layout;

  return $export;
}
