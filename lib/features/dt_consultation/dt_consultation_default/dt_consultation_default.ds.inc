<?php
/**
 * @file
 * dt_consultation_default.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_consultation_default_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|consultation|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'consultation';
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
    'in_page_navigation' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'social_bookmark_webtools' => array(
      'weight' => '15',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'consultation_period' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Consultation period',
        ),
      ),
    ),
  );
  $export['node|consultation|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|consultation|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'consultation';
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
    'field_consultation_status' => array(
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
    'field_core_date_opening' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_core_date_closing' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|consultation|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_consultation_default_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|consultation|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'consultation';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ne_bootstrap_3_9_stacked_conditional';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'content_type_label',
        2 => 'group_consultation_meta',
        3 => 'title',
      ),
      'central' => array(
        1 => 'consultation_period',
        5 => 'field_core_policy_areas',
        6 => 'group_consultation_details',
        7 => 'field_core_departments',
        8 => 'group_consultation_target_group',
        9 => 'group_consultation_objective',
        10 => 'field_consultation_objective',
        11 => 'group_consultation_how_to_submit',
        12 => 'group_consultation_questionnaire',
        13 => 'field_consultation_target_groups',
        14 => 'field_consultation_how_to_submit',
        15 => 'group_consultation_reference',
        16 => 'group_consultation_contact',
        17 => 'group_consultation_contributions',
        18 => 'group_consultation_results',
        19 => 'field_core_contact',
        20 => 'field_consultation_results',
        21 => 'field_core_publications',
        22 => 'field_consultation_contributions',
        23 => 'field_core_files',
        24 => 'field_core_pages',
        25 => 'field_consultation_questionnaire',
        26 => 'group_consultation_legal_notices',
      ),
      'left' => array(
        4 => 'in_page_navigation',
      ),
      'bottom_central' => array(
        27 => 'social_bookmark_webtools',
      ),
    ),
    'fields' => array(
      'content_type_label' => 'left_header',
      'consultation_period' => 'central',
      'group_consultation_meta' => 'left_header',
      'title' => 'left_header',
      'in_page_navigation' => 'left',
      'field_core_policy_areas' => 'central',
      'group_consultation_details' => 'central',
      'field_core_departments' => 'central',
      'group_consultation_target_group' => 'central',
      'group_consultation_objective' => 'central',
      'field_consultation_objective' => 'central',
      'group_consultation_how_to_submit' => 'central',
      'group_consultation_questionnaire' => 'central',
      'field_consultation_target_groups' => 'central',
      'field_consultation_how_to_submit' => 'central',
      'group_consultation_reference' => 'central',
      'group_consultation_contact' => 'central',
      'group_consultation_contributions' => 'central',
      'group_consultation_results' => 'central',
      'field_core_contact' => 'central',
      'field_consultation_results' => 'central',
      'field_core_publications' => 'central',
      'field_consultation_contributions' => 'central',
      'field_core_files' => 'central',
      'field_core_pages' => 'central',
      'field_consultation_questionnaire' => 'central',
      'group_consultation_legal_notices' => 'central',
      'social_bookmark_webtools' => 'bottom_central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left_header' => 'div',
      'right_header' => 'div',
      'top' => 'div',
      'left' => 'div',
      'central' => 'div',
      'bottom_left' => 'div',
      'bottom_central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|consultation|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|consultation|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'consultation';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ne_2col_sidebar_no_link';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'group_consultation_meta',
        1 => 'title_field',
        2 => 'field_core_date_opening',
        3 => 'field_core_date_closing',
        4 => 'content_type_label',
        5 => 'field_consultation_status',
      ),
    ),
    'fields' => array(
      'group_consultation_meta' => 'main',
      'title_field' => 'main',
      'field_core_date_opening' => 'main',
      'field_core_date_closing' => 'main',
      'content_type_label' => 'main',
      'field_consultation_status' => 'main',
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
  $export['node|consultation|teaser'] = $ds_layout;

  return $export;
}
