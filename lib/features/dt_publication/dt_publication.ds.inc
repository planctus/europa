<?php
/**
 * @file
 * dt_publication.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_publication_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|publication|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'publication';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
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
    'field_publication_type' => array(
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
    'field_core_files' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'paragraph',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_core_topics' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Topic:',
        ),
      ),
    ),
    'field_publication_authors' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Author:',
        ),
      ),
    ),
    'field_publication_referenceno' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Identification:',
        ),
      ),
    ),
    'field_core_date_published' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'First published on:',
        ),
      ),
    ),
    'field_core_publications' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Part of collection:',
        ),
      ),
    ),
  );
  $export['node|publication|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|publication|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'publication';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => '',
        'class' => '',
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
    'field_publication_type' => array(
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
  );
  $export['node|publication|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_publication_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|person|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'person';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ne_bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'title',
      ),
    ),
    'fields' => array(
      'title' => 'central',
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
  $export['node|person|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|publication|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'publication';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ne_bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'group_publication_meta',
        4 => 'title',
        5 => 'field_publication_type',
        6 => 'field_core_legacy_link',
      ),
      'top' => array(
        1 => 'field_core_publications',
        2 => 'field_core_date_published',
        7 => 'group_publication_contextual',
        15 => 'field_publication_authors',
        16 => 'field_core_topics',
        17 => 'field_publication_referenceno',
      ),
      'central' => array(
        3 => 'field_core_contact',
        8 => 'group_publication_body',
        9 => 'group_publication_file',
        10 => 'body',
        11 => 'group_publication_related',
        12 => 'field_core_files',
        13 => 'field_core_departments',
        14 => 'group_publication_contact',
      ),
    ),
    'fields' => array(
      'group_publication_meta' => 'left_header',
      'field_core_publications' => 'top',
      'field_core_date_published' => 'top',
      'field_core_contact' => 'central',
      'title' => 'left_header',
      'field_publication_type' => 'left_header',
      'field_core_legacy_link' => 'left_header',
      'group_publication_contextual' => 'top',
      'group_publication_body' => 'central',
      'group_publication_file' => 'central',
      'body' => 'central',
      'group_publication_related' => 'central',
      'field_core_files' => 'central',
      'field_core_departments' => 'central',
      'group_publication_contact' => 'central',
      'field_publication_authors' => 'top',
      'field_core_topics' => 'top',
      'field_publication_referenceno' => 'top',
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
  $export['node|publication|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|publication|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'publication';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ne_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'group_publication_meta',
        1 => 'title',
        2 => 'field_core_introduction',
        3 => 'field_publication_type',
      ),
    ),
    'fields' => array(
      'group_publication_meta' => 'main',
      'title' => 'main',
      'field_core_introduction' => 'main',
      'field_publication_type' => 'main',
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
  $export['node|publication|teaser'] = $ds_layout;

  return $export;
}
