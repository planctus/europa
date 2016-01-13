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
    'collection_documents' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
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
    'field_core_publications' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Part of collection:',
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
    'field_publication_rel_content' => array(
      'formatter_settings' => array(
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
    'field_core_policies' => array(
      'formatter_settings' => array(
        'ft' => array(),
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
  $ds_field->field = 'collection_documents';
  $ds_field->label = 'Collection documents';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'publication|*';
  $ds_field->properties = array(
    'block' => 'views|publications-block',
    'block_render' => '1',
  );
  $export['collection_documents'] = $ds_field;

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
        0 => 'group_publication_meta',
        1 => 'collection_label',
        4 => 'field_publication_type',
        5 => 'title',
        8 => 'field_core_legacy_link',
      ),
      'central' => array(
        2 => 'field_core_contact',
        12 => 'group_publication_body',
        13 => 'group_publication_file',
        14 => 'group_publication_related',
        15 => 'body',
        16 => 'group_publication_contact',
        17 => 'social_bookmark_webtools',
        18 => 'field_core_departments',
        19 => 'field_core_files',
        20 => 'collection_documents',
        21 => 'field_publication_rel_content',
        22 => 'field_core_policies',
      ),
      'top' => array(
        3 => 'field_core_publications',
        6 => 'field_core_date_published',
        7 => 'field_publication_authors',
        9 => 'group_publication_contextual',
        10 => 'field_publication_referenceno',
        11 => 'field_core_topics',
      ),
    ),
    'fields' => array(
      'group_publication_meta' => 'left_header',
      'collection_label' => 'left_header',
      'field_core_contact' => 'central',
      'field_core_publications' => 'top',
      'field_publication_type' => 'left_header',
      'title' => 'left_header',
      'field_core_date_published' => 'top',
      'field_publication_authors' => 'top',
      'field_core_legacy_link' => 'left_header',
      'group_publication_contextual' => 'top',
      'field_publication_referenceno' => 'top',
      'field_core_topics' => 'top',
      'group_publication_body' => 'central',
      'group_publication_file' => 'central',
      'group_publication_related' => 'central',
      'body' => 'central',
      'group_publication_contact' => 'central',
      'social_bookmark_webtools' => 'central',
      'field_core_departments' => 'central',
      'field_core_files' => 'central',
      'collection_documents' => 'central',
      'field_publication_rel_content' => 'central',
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
