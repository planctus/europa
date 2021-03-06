<?php
/**
 * @file
 * dt_class.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_class_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|class_link_group|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'class_link_group';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_class_link_legacy_link' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|class_link_group|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|class|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'class';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
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
    'social_bookmark_webtools' => array(
      'weight' => '6',
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
    'field_class_related_links' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Related links',
          'lb-el' => 'h2',
          'lb-at' => 'id="related-links"',
          'lb-col' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
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
  );
  $export['node|class|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|class|structured_navigation';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'class';
  $ds_fieldsetting->view_mode = 'structured_navigation';
  $ds_fieldsetting->settings = array(
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_core_description' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|class|structured_navigation'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|class|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'class';
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
        ),
      ),
    ),
  );
  $export['node|class|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|class|title';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'class';
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
  $export['node|class|title'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function dt_class_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'work_in_progress';
  $ds_field->label = 'Work in progress';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<div class="messages info"><h3>Info message</h3><p>This part of the website is still under construction, but here are some links that may help in the meantime.</p></div>',
      'format' => 'full_html',
    ),
    'use_token' => 0,
  );
  $export['work_in_progress'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_class_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|class_link_group|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'class_link_group';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_class_link_explanation',
        2 => 'field_class_link_legacy_link',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_class_link_explanation' => 'ds_content',
      'field_class_link_legacy_link' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|class_link_group|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|class|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'class';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ne_bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'title',
        1 => 'field_core_introduction',
      ),
      'central' => array(
        2 => 'field_link_groups',
        3 => 'group_class_topics',
        4 => 'group_class_departments',
        5 => 'field_class_related_links',
        6 => 'field_core_topics',
        7 => 'social_bookmark_webtools',
        8 => 'field_core_department',
      ),
    ),
    'fields' => array(
      'title' => 'left_header',
      'field_core_introduction' => 'left_header',
      'field_link_groups' => 'central',
      'group_class_topics' => 'central',
      'group_class_departments' => 'central',
      'field_class_related_links' => 'central',
      'field_core_topics' => 'central',
      'social_bookmark_webtools' => 'central',
      'field_core_department' => 'central',
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
  $export['node|class|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|class|structured_navigation';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'class';
  $ds_layout->view_mode = 'structured_navigation';
  $ds_layout->layout = 'ne_1col_section_item';
  $ds_layout->settings = array(
    'regions' => array(
      'description' => array(
        0 => 'field_core_description',
      ),
      'title' => array(
        1 => 'title_field',
      ),
    ),
    'fields' => array(
      'field_core_description' => 'description',
      'title_field' => 'title',
    ),
    'classes' => array(),
    'wrappers' => array(
      'title' => 'div',
      'description' => 'div',
      'children' => 'div',
      'links' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|class|structured_navigation'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|class|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'class';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ne_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'title_field',
        1 => 'field_core_description',
      ),
    ),
    'fields' => array(
      'title_field' => 'main',
      'field_core_description' => 'main',
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
  $export['node|class|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|class|title';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'class';
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
  $export['node|class|title'] = $ds_layout;

  return $export;
}
