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
  $field_group->identifier = 'group_blog_bottom_section|node|commisioner_blog_post|full';
  $field_group->group_name = 'group_blog_bottom_section';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'commisioner_blog_post';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bottom',
    'weight' => '4',
    'children' => array(
      0 => 'field_shared_tags',
      1 => 'social_media',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Bottom',
      'instance_settings' => array(
        'modifier' => '',
        'layout' => 'col-md-8',
        'classes' => 'group-blog-bottom-section field-group-section_group',
      ),
    ),
  );
  $export['group_blog_bottom_section|node|commisioner_blog_post|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_blog_meta|node|commisioner_blog_post|full';
  $field_group->group_name = 'group_blog_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'commisioner_blog_post';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'content_type_label',
      1 => 'post_date',
      2 => 'editorial_section_name',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(
        'modifier' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_blog_meta|node|commisioner_blog_post|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_blog_meta|node|commisioner_blog_post|meta';
  $field_group->group_name = 'group_blog_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'commisioner_blog_post';
  $field_group->mode = 'meta';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'title',
      1 => 'post_date',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(
        'modifier' => '',
        'classes' => 'group-blog-meta field-group-meta_wrapper',
      ),
    ),
  );
  $export['group_blog_meta|node|commisioner_blog_post|meta'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_blog_meta|node|commisioner_blog_post|teaser';
  $field_group->group_name = 'group_blog_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'commisioner_blog_post';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'post_date',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'modifier' => '',
        'required_fields' => 1,
        'classes' => 'group-blog-meta field-group-meta_wrapper',
      ),
    ),
  );
  $export['group_blog_meta|node|commisioner_blog_post|teaser'] = $field_group;

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
