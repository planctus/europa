<?php
/**
 * @file
 * dt_featured_item.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_featured_item_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|featured_item|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'featured_item';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
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
    'field_core_legacy_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|featured_item|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|featured_item|hero_links';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'featured_item';
  $ds_fieldsetting->view_mode = 'hero_links';
  $ds_fieldsetting->settings = array(
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'hero-links__caption',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_feat_item_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|featured_item|hero_links'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|featured_item|image_label';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'featured_item';
  $ds_fieldsetting->view_mode = 'image_label';
  $ds_fieldsetting->settings = array(
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h3',
          'fi-cl' => 'highlighted-item__content',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_feat_item_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'highlighted-item__image',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|featured_item|image_label'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|featured_item|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'featured_item';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'field_feat_item_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
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
        ),
      ),
    ),
    'field_core_legacy_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|featured_item|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_featured_item_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|featured_item|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'featured_item';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_featured_item_wrapper',
        1 => 'title_field',
        2 => 'field_feat_item_image',
        3 => 'field_core_description',
        4 => 'field_core_legacy_link',
        5 => 'group_featured_item_left',
        6 => 'group_featured_item_right',
      ),
    ),
    'fields' => array(
      'group_featured_item_wrapper' => 'ds_content',
      'title_field' => 'ds_content',
      'field_feat_item_image' => 'ds_content',
      'field_core_description' => 'ds_content',
      'field_core_legacy_link' => 'ds_content',
      'group_featured_item_left' => 'ds_content',
      'group_featured_item_right' => 'ds_content',
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
  $export['node|featured_item|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|featured_item|hero_links';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'featured_item';
  $ds_layout->view_mode = 'hero_links';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_featured_item_link_wrapper',
        1 => 'field_feat_item_image',
        2 => 'title_field',
      ),
    ),
    'fields' => array(
      'group_featured_item_link_wrapper' => 'ds_content',
      'field_feat_item_image' => 'ds_content',
      'title_field' => 'ds_content',
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
  $export['node|featured_item|hero_links'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|featured_item|image_label';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'featured_item';
  $ds_layout->view_mode = 'image_label';
  $ds_layout->layout = 'ne_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'group_featured_item',
        1 => 'field_feat_item_image',
        2 => 'title_field',
      ),
    ),
    'fields' => array(
      'group_featured_item' => 'main',
      'field_feat_item_image' => 'main',
      'title_field' => 'main',
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
  $export['node|featured_item|image_label'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|featured_item|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'featured_item';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title_field',
        1 => 'group_featured_item_wrapper',
        2 => 'field_feat_item_image',
        3 => 'field_core_description',
        4 => 'field_core_legacy_link',
        5 => 'group_featured_item_left',
        6 => 'group_featured_item_right',
      ),
    ),
    'fields' => array(
      'title_field' => 'ds_content',
      'group_featured_item_wrapper' => 'ds_content',
      'field_feat_item_image' => 'ds_content',
      'field_core_description' => 'ds_content',
      'field_core_legacy_link' => 'ds_content',
      'group_featured_item_left' => 'ds_content',
      'group_featured_item_right' => 'ds_content',
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
  $export['node|featured_item|teaser'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function dt_featured_item_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'hero_links';
  $ds_view_mode->label = 'Hero links';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['hero_links'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'image_label';
  $ds_view_mode->label = 'Image Label';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['image_label'] = $ds_view_mode;

  return $export;
}
