<?php
/**
 * @file
 * dt_banner_quote.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_banner_quote_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_banner|node|banner_quote|form';
  $field_group->group_name = 'group_banner';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_quote';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Banner',
    'weight' => '5',
    'children' => array(
      0 => 'title_field',
      1 => 'field_core_description',
      2 => 'field_banner_author',
      3 => 'field_banner_author_gender',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-banner field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_banner|node|banner_quote|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_blockquote|node|banner_quote|teaser';
  $field_group->group_name = 'group_blockquote';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_quote';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_quote_quote';
  $field_group->data = array(
    'label' => 'Blockquote',
    'weight' => '3',
    'children' => array(
      0 => 'field_core_description',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Blockquote',
      'instance_settings' => array(
        'classes' => 'blockquote blockquote--small',
        'element' => 'blockquote',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_blockquote|node|banner_quote|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_tabgroup|node|banner_quote|form';
  $field_group->group_name = 'group_content_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_quote';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_banner',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-content-tabgroup field-group-tabs',
      ),
    ),
  );
  $export['group_content_tabgroup|node|banner_quote|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_quote_author|node|banner_quote|teaser';
  $field_group->group_name = 'group_quote_author';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_quote';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_quote_wrapper';
  $field_group->data = array(
    'label' => 'Author',
    'weight' => '6',
    'children' => array(
      0 => 'field_banner_author',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Author',
      'instance_settings' => array(
        'classes' => 'banner_quote__author',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_quote_author|node|banner_quote|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_quote_quote|node|banner_quote|teaser';
  $field_group->group_name = 'group_quote_quote';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_quote';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_quote_wrapper';
  $field_group->data = array(
    'label' => 'Quote Quote',
    'weight' => '5',
    'children' => array(
      0 => 'group_blockquote',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Quote Quote',
      'instance_settings' => array(
        'classes' => 'banner_quote__quote',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_quote_quote|node|banner_quote|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_quote_wrapper|node|banner_quote|teaser';
  $field_group->group_name = 'group_quote_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_quote';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Quote Wrapper',
    'weight' => '0',
    'children' => array(
      0 => 'group_quote_quote',
      1 => 'group_quote_author',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Quote Wrapper',
      'instance_settings' => array(
        'classes' => 'banner_quote',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_quote_wrapper|node|banner_quote|teaser'] = $field_group;

  return $export;
}
