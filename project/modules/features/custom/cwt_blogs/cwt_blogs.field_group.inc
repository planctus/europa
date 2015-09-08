<?php
/**
 * @file
 * cwt_blogs.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cwt_blogs_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_com_blog_content|node|commisioner_blog_post|form';
  $field_group->group_name = 'group_com_blog_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'commisioner_blog_post';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_com_blog_image',
      2 => 'field_com_blog_video',
      3 => 'field_shared_teaser',
      4 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-com-blog-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_com_blog_content|node|commisioner_blog_post|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_com_blog_metadata|node|commisioner_blog_post|form';
  $field_group->group_name = 'group_com_blog_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'commisioner_blog_post';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '1',
    'children' => array(
      0 => 'field_editorial_section',
      1 => 'field_shared_tags',
      2 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-com-blog-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_com_blog_metadata|node|commisioner_blog_post|form'] = $field_group;

  return $export;
}
