<?php
/**
 * @file
 * dt_featured_item.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_featured_item_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_tabgroup|node|featured_item|form';
  $field_group->group_name = 'group_content_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'featured_item';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_editorial_settings',
      1 => 'group_featured',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-content-tabgroup field-group-tabs',
      ),
    ),
  );
  $export['group_content_tabgroup|node|featured_item|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_settings|node|featured_item|form';
  $field_group->group_name = 'group_editorial_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'featured_item';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '10',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'group_content_access',
      2 => 'scheduler_settings',
      3 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-editorial-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_editorial_settings|node|featured_item|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_featured_item_left|node|featured_item|default';
  $field_group->group_name = 'group_featured_item_left';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'featured_item';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_featured_item_wrapper';
  $field_group->data = array(
    'label' => 'Featured item left',
    'weight' => '13',
    'children' => array(
      0 => 'field_feat_item_image',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Featured item left',
      'instance_settings' => array(
        'classes' => 'featured-item__image',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_featured_item_left|node|featured_item|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_featured_item_left|node|featured_item|teaser';
  $field_group->group_name = 'group_featured_item_left';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'featured_item';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_featured_item_wrapper';
  $field_group->data = array(
    'label' => 'Featured item left',
    'weight' => '13',
    'children' => array(
      0 => 'field_feat_item_image',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Featured item left',
      'instance_settings' => array(
        'classes' => 'featured-item__image',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_featured_item_left|node|featured_item|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_featured_item_right|node|featured_item|default';
  $field_group->group_name = 'group_featured_item_right';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'featured_item';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_featured_item_wrapper';
  $field_group->data = array(
    'label' => 'Featured item right',
    'weight' => '14',
    'children' => array(
      0 => 'title_field',
      1 => 'field_core_legacy_link',
      2 => 'field_core_description',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Featured item right',
      'instance_settings' => array(
        'classes' => 'featured-item__content',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_featured_item_right|node|featured_item|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_featured_item_right|node|featured_item|teaser';
  $field_group->group_name = 'group_featured_item_right';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'featured_item';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_featured_item_wrapper';
  $field_group->data = array(
    'label' => 'Featured item right',
    'weight' => '14',
    'children' => array(
      0 => 'title_field',
      1 => 'field_core_legacy_link',
      2 => 'field_core_description',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Featured item right',
      'instance_settings' => array(
        'classes' => 'featured-item__content',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_featured_item_right|node|featured_item|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_featured_item_wrapper|node|featured_item|default';
  $field_group->group_name = 'group_featured_item_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'featured_item';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Featured item wrapper',
    'weight' => '0',
    'children' => array(
      0 => 'group_featured_item_left',
      1 => 'group_featured_item_right',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Featured item wrapper',
      'instance_settings' => array(
        'classes' => 'featured-item',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_featured_item_wrapper|node|featured_item|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_featured_item_wrapper|node|featured_item|teaser';
  $field_group->group_name = 'group_featured_item_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'featured_item';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Featured item wrapper',
    'weight' => '0',
    'children' => array(
      0 => 'group_featured_item_left',
      1 => 'group_featured_item_right',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Featured item wrapper',
      'instance_settings' => array(
        'classes' => 'featured-item',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_featured_item_wrapper|node|featured_item|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_featured|node|featured_item|form';
  $field_group->group_name = 'group_featured';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'featured_item';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Featured',
    'weight' => '9',
    'children' => array(
      0 => 'title_field',
      1 => 'field_feat_item_description',
      2 => 'field_feat_item_image',
      3 => 'field_core_legacy_link',
      4 => 'field_core_description',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-featured field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_featured|node|featured_item|form'] = $field_group;

  return $export;
}
