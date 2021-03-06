<?php

/**
 * @file
 * dt_banner_quote.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_banner_quote_field_group_info() {
  $field_groups = array();

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
      0 => 'field_core_description',
      1 => 'field_banner_author',
      2 => 'field_banner_author_gender',
      3 => 'title_field',
      4 => 'field_core_keywords',
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
  $field_groups['group_banner|node|banner_quote|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_blockquote|node|banner_quote|default';
  $field_group->group_name = 'group_blockquote';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_quote';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_quote_quote';
  $field_group->data = array(
    'label' => 'Blockquote',
    'weight' => '18',
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
  $field_groups['group_blockquote|node|banner_quote|default'] = $field_group;

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
    'weight' => '6',
    'children' => array(
      0 => 'field_core_description',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Blockquote',
      'instance_settings' => array(
        'classes' => '',
        'element' => 'blockquote',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_blockquote|node|banner_quote|teaser'] = $field_group;

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
      1 => 'group_editorial_settings',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-content-tabgroup field-group-tabs',
      ),
    ),
  );
  $field_groups['group_content_tabgroup|node|banner_quote|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_settings|node|banner_quote|form';
  $field_group->group_name = 'group_editorial_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_quote';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial Settings',
    'weight' => '6',
    'children' => array(
      0 => 'group_content_access',
      1 => 'og_group_ref',
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
  $field_groups['group_editorial_settings|node|banner_quote|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_quote_author|node|banner_quote|default';
  $field_group->group_name = 'group_quote_author';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_quote';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_quote_quote';
  $field_group->data = array(
    'label' => 'Author',
    'weight' => '19',
    'children' => array(
      0 => 'field_banner_author',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Author',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'banner__author',
        'element' => 'footer',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_quote_author|node|banner_quote|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_quote_author|node|banner_quote|teaser';
  $field_group->group_name = 'group_quote_author';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_quote';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_quote_quote';
  $field_group->data = array(
    'label' => 'Author',
    'weight' => '7',
    'children' => array(
      0 => 'field_banner_author',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Author',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'banner__author',
        'element' => 'footer',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_quote_author|node|banner_quote|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_quote_quote|node|banner_quote|default';
  $field_group->group_name = 'group_quote_quote';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_quote';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_quote_wrapper';
  $field_group->data = array(
    'label' => 'Quote Quote',
    'weight' => '17',
    'children' => array(
      0 => 'group_blockquote',
      1 => 'group_quote_author',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Quote Quote',
      'instance_settings' => array(
        'classes' => 'banner__quote',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_quote_quote|node|banner_quote|default'] = $field_group;

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
      1 => 'group_quote_author',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Quote Quote',
      'instance_settings' => array(
        'classes' => 'banner__quote',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_quote_quote|node|banner_quote|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_quote_wrapper|node|banner_quote|default';
  $field_group->group_name = 'group_quote_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_quote';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Quote Wrapper',
    'weight' => '0',
    'children' => array(
      0 => 'group_quote_quote',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Quote Wrapper',
      'instance_settings' => array(
        'classes' => 'banner banner--quote',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_quote_wrapper|node|banner_quote|default'] = $field_group;

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
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Quote Wrapper',
      'instance_settings' => array(
        'classes' => 'banner banner--quote',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_quote_wrapper|node|banner_quote|teaser'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Author');
  t('Banner');
  t('Blockquote');
  t('Content');
  t('Editorial Settings');
  t('Quote Quote');
  t('Quote Wrapper');

  return $field_groups;
}
