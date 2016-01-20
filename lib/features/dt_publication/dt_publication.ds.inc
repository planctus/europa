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
    'collection_label' => array(
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
    'social_bookmark_webtools' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'social-media-links--webtool-horizontal',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'collection_documents' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'publication_collections' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
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
          'fi-first-last' => FALSE,
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
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'post_date' => array(
      'weight' => '21',
      'label' => 'hidden',
      'format' => 'ds_post_date_ec_date_j_f_y',
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
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|publication|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function dt_publication_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'collection_label';
  $ds_field->label = 'Collection label';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'publication|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => 'Collection',
      'format' => 'plain_text',
    ),
    'use_token' => 0,
  );
  $export['collection_label'] = $ds_field;

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
        0 => 'collection_label',
        1 => 'group_publication_meta',
        3 => 'title',
        4 => 'field_publication_type',
        5 => 'field_core_legacy_link',
      ),
      'central' => array(
        2 => 'field_core_contact',
        8 => 'group_publication_body',
        11 => 'group_publication_file',
        12 => 'group_publication_related',
        13 => 'body',
        15 => 'group_publication_contact',
        17 => 'field_core_files',
        18 => 'social_bookmark_webtools',
        19 => 'field_core_departments',
        20 => 'field_publication_rel_content',
        21 => 'collection_documents',
        22 => 'field_core_policies',
      ),
      'top' => array(
        6 => 'publication_collections',
        7 => 'group_publication_contextual',
        9 => 'field_core_date_published',
        10 => 'field_publication_authors',
        14 => 'field_publication_referenceno',
        16 => 'field_core_topics',
      ),
    ),
    'fields' => array(
      'collection_label' => 'left_header',
      'group_publication_meta' => 'left_header',
      'field_core_contact' => 'central',
      'title' => 'left_header',
      'field_publication_type' => 'left_header',
      'field_core_legacy_link' => 'left_header',
      'publication_collections' => 'top',
      'group_publication_contextual' => 'top',
      'group_publication_body' => 'central',
      'field_core_date_published' => 'top',
      'field_publication_authors' => 'top',
      'group_publication_file' => 'central',
      'group_publication_related' => 'central',
      'body' => 'central',
      'field_publication_referenceno' => 'top',
      'group_publication_contact' => 'central',
      'field_core_topics' => 'top',
      'field_core_files' => 'central',
      'social_bookmark_webtools' => 'central',
      'field_core_departments' => 'central',
      'field_publication_rel_content' => 'central',
      'collection_documents' => 'central',
      'field_core_policies' => 'central',
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
        2 => 'field_publication_type',
        3 => 'post_date',
      ),
    ),
    'fields' => array(
      'group_publication_meta' => 'main',
      'title' => 'main',
      'field_publication_type' => 'main',
      'post_date' => 'main',
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
