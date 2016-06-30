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
          'fi-first-last' => FALSE,
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
    'announcement_block' => array(
      'weight' => '6',
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
          'fi-first-last' => FALSE,
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
          'fi-first-last' => FALSE,
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
    'field_core_parent' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Political priorities',
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
    'field_core_policy_areas' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Part of priority',
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
          'fi-first-last' => FALSE,
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
        5 => 'field_core_banner',
        7 => 'field_core_parent',
        9 => 'field_core_policy_areas',
        11 => 'field_core_topics',
        15 => 'field_core_persons',
        16 => 'field_core_departments',
      ),
      'central' => array(
        6 => 'group_pri_pol_policy_areas',
        8 => 'announcement_block',
        10 => 'group_pri_pol_area_background',
        12 => 'field_core_background',
        13 => 'group_pri_pol_area_documents',
        14 => 'field_core_objective',
        17 => 'group_pri_pol_area_whatnext',
        18 => 'group_pri_pol_area_related',
        19 => 'field_core_publications',
        20 => 'field_core_links',
        21 => 'field_core_next_steps',
        22 => 'field_core_section_intro',
        23 => 'field_core_child_policies',
      ),
    ),
    'fields' => array(
      'group_pri_pol_area_meta' => 'left_header',
      'content_type_label' => 'left_header',
      'title' => 'left_header',
      'field_core_introduction' => 'left_header',
      'group_pri_pol_area_contextual' => 'top',
      'field_core_banner' => 'top',
      'group_pri_pol_policy_areas' => 'central',
      'field_core_parent' => 'top',
      'announcement_block' => 'central',
      'field_core_policy_areas' => 'top',
      'group_pri_pol_area_background' => 'central',
      'field_core_topics' => 'top',
      'field_core_background' => 'central',
      'group_pri_pol_area_documents' => 'central',
      'field_core_objective' => 'central',
      'field_core_persons' => 'top',
      'field_core_departments' => 'top',
      'group_pri_pol_area_whatnext' => 'central',
      'group_pri_pol_area_related' => 'central',
      'field_core_publications' => 'central',
      'field_core_links' => 'central',
      'field_core_next_steps' => 'central',
      'field_core_section_intro' => 'central',
      'field_core_child_policies' => 'central',
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
  $export['node|priority_policy_area|teaser'] = $ds_layout;

  return $export;
}
