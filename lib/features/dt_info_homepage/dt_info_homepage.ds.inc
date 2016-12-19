<?php
/**
 * @file
 * dt_info_homepage.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_info_homepage_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|info_homepage|homepage_informational';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'info_homepage';
  $ds_fieldsetting->view_mode = 'homepage_informational';
  $ds_fieldsetting->settings = array(
    'field_info_highlights' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|info_homepage|homepage_informational'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|info_homepage|homepage_political';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'info_homepage';
  $ds_fieldsetting->view_mode = 'homepage_political';
  $ds_fieldsetting->settings = array(
    'priorities_listing' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'announcement_block' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_featured_item' => 0,
        'show_promoted' => 1,
        'show_social_media' => 1,
        'label' => 'Latest',
        'limit_results' => '3',
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_core_introduction' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Highlight',
        ),
      ),
    ),
    'field_info_homepage_hero_links' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'container-fluid hero-links__items',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'hero-links__item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_info_homepage_hero_linktxt' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'container-fluid hero-links__text',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
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
  $export['node|info_homepage|homepage_political'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function dt_info_homepage_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'priorities_listing';
  $ds_field->label = 'Priorities Listing';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'info_homepage|homepage_political';
  $ds_field->properties = array(
    'block' => 'views|da527f03e2deb790d3a09dc828fe998a',
    'block_render' => '3',
  );
  $export['priorities_listing'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_info_homepage_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|info_homepage|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'info_homepage';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ne_bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'field_core_introduction',
      ),
    ),
    'fields' => array(
      'field_core_introduction' => 'left_header',
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
  $export['node|info_homepage|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|info_homepage|homepage_informational';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'info_homepage';
  $ds_layout->view_mode = 'homepage_informational';
  $ds_layout->layout = 'ne_bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'field_info_homepage_topic_intro',
        2 => 'group_info_homepage_section_top',
        3 => 'field_info_homepage_topic_link',
        4 => 'group_info_homepage_section_bot',
        5 => 'group_info_highlights',
        6 => 'group_topics',
        7 => 'field_info_secondary_links',
        8 => 'field_info_classes',
        9 => 'field_info_highlights',
      ),
      'left_header' => array(
        1 => 'field_core_introduction',
      ),
    ),
    'fields' => array(
      'field_info_homepage_topic_intro' => 'central',
      'field_core_introduction' => 'left_header',
      'group_info_homepage_section_top' => 'central',
      'field_info_homepage_topic_link' => 'central',
      'group_info_homepage_section_bot' => 'central',
      'group_info_highlights' => 'central',
      'group_topics' => 'central',
      'field_info_secondary_links' => 'central',
      'field_info_classes' => 'central',
      'field_info_highlights' => 'central',
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
  $export['node|info_homepage|homepage_informational'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|info_homepage|homepage_political';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'info_homepage';
  $ds_layout->view_mode = 'homepage_political';
  $ds_layout->layout = 'ne_bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'field_core_introduction',
      ),
      'central' => array(
        1 => 'priorities_listing',
        2 => 'group_info_homepage_section_top',
        3 => 'field_info_highlights',
        4 => 'field_info_homepage_prior_link',
        5 => 'field_core_links',
        6 => 'group_info_homepage_commissionrs',
        7 => 'group_info_homepage_about',
        8 => 'field_info_homepage_about_button',
        9 => 'group_info_homepage_contacts',
        10 => 'announcement_block',
        11 => 'field_info_homepage_hero_linktxt',
        12 => 'field_info_homepage_contacts',
        13 => 'field_info_homepage_hero_links',
        14 => 'group_info_highlights',
      ),
    ),
    'fields' => array(
      'field_core_introduction' => 'left_header',
      'priorities_listing' => 'central',
      'group_info_homepage_section_top' => 'central',
      'field_info_highlights' => 'central',
      'field_info_homepage_prior_link' => 'central',
      'field_core_links' => 'central',
      'group_info_homepage_commissionrs' => 'central',
      'group_info_homepage_about' => 'central',
      'field_info_homepage_about_button' => 'central',
      'group_info_homepage_contacts' => 'central',
      'announcement_block' => 'central',
      'field_info_homepage_hero_linktxt' => 'central',
      'field_info_homepage_contacts' => 'central',
      'field_info_homepage_hero_links' => 'central',
      'group_info_highlights' => 'central',
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
  $export['node|info_homepage|homepage_political'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function dt_info_homepage_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'homepage_informational';
  $ds_view_mode->label = 'Homepage: Informational';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['homepage_informational'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'homepage_political';
  $ds_view_mode->label = 'Homepage: Political';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['homepage_political'] = $ds_view_mode;

  return $export;
}
