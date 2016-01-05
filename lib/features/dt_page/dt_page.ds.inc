<?php
/**
 * @file
 * dt_page.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_page_ds_field_settings_info() {
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
    'related_announcements' => array(
      'weight' => '13',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'in_page_navigation' => array(
      'weight' => '3',
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
    'field_core_links' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'listing__wrapper listing__wrapper--default listing--title__wrapper',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => 'listing listing--title',
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
    'field_core_banner' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
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
  );
  $export['node|basic_page|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|basic_page|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'basic_page';
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
          'fi-first-last' => FALSE,
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
function dt_page_ds_layout_settings_info() {
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
        2 => 'group_page_contextual_navigation',
        21 => 'field_core_priorities',
        22 => 'field_core_policy_area',
        23 => 'field_core_departments',
        24 => 'field_core_persons',
        25 => 'field_core_topics',
      ),
      'left' => array(
        3 => 'in_page_navigation',
      ),
      'central' => array(
        4 => 'group_page_priorities',
        5 => 'field_core_banner',
        6 => 'priorities_preprocess',
        7 => 'group_page_free_field',
        8 => 'body',
        9 => 'group_page_next_steps',
        10 => 'field_core_next_steps',
        11 => 'group_page_latest_main',
        12 => 'field_core_featured_item',
        13 => 'group_page_latest',
        14 => 'related_announcements',
        15 => 'group_page_latest_sidebar',
        16 => 'field_core_social_network_links',
        17 => 'group_page_documents',
        18 => 'field_core_publications',
        19 => 'group_page_related_links',
        20 => 'field_core_links',
      ),
    ),
    'fields' => array(
      'title' => 'left_header',
      'field_core_introduction' => 'left_header',
      'group_page_contextual_navigation' => 'top',
      'in_page_navigation' => 'left',
      'group_page_priorities' => 'central',
      'field_core_banner' => 'central',
      'priorities_preprocess' => 'central',
      'group_page_free_field' => 'central',
      'body' => 'central',
      'group_page_next_steps' => 'central',
      'field_core_next_steps' => 'central',
      'group_page_latest_main' => 'central',
      'field_core_featured_item' => 'central',
      'group_page_latest' => 'central',
      'related_announcements' => 'central',
      'group_page_latest_sidebar' => 'central',
      'field_core_social_network_links' => 'central',
      'group_page_documents' => 'central',
      'field_core_publications' => 'central',
      'group_page_related_links' => 'central',
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
  $ds_layout->id = 'node|basic_page|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'basic_page';
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
        3 => 'field_core_link',
      ),
    ),
    'fields' => array(
      'title_field' => 'main',
      'field_core_description' => 'main',
      'field_core_image' => 'second',
      'field_core_link' => 'second',
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
