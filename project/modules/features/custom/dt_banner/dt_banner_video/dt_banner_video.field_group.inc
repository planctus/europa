<?php
/**
 * @file
 * dt_banner_video.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_banner_video_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_banner|node|banner_video|form';
  $field_group->group_name = 'group_banner';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_video';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Banner',
    'weight' => '5',
    'children' => array(
      0 => 'field_core_description',
      1 => 'title_field',
      2 => 'field_banner_caption',
      3 => 'field_banner_video_file',
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
  $export['group_banner|node|banner_video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_tabgroup|node|banner_video|form';
  $field_group->group_name = 'group_content_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_video';
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
  $export['group_content_tabgroup|node|banner_video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_caption|node|banner_video|default';
  $field_group->group_name = 'group_video_caption';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_video';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_video_left';
  $field_group->data = array(
    'label' => 'Video caption',
    'weight' => '8',
    'children' => array(
      0 => 'field_banner_caption',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Video caption',
      'instance_settings' => array(
        'classes' => 'banner_video__caption',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_video_caption|node|banner_video|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_caption|node|banner_video|teaser';
  $field_group->group_name = 'group_video_caption';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_video';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_video_left';
  $field_group->data = array(
    'label' => 'Video caption',
    'weight' => '8',
    'children' => array(
      0 => 'field_banner_caption',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Video caption',
      'instance_settings' => array(
        'classes' => 'banner_video__caption',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_video_caption|node|banner_video|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_left|node|banner_video|default';
  $field_group->group_name = 'group_video_left';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_video';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_video_wrapper';
  $field_group->data = array(
    'label' => 'Video left',
    'weight' => '5',
    'children' => array(
      0 => 'group_video_video',
      1 => 'group_video_caption',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Video left',
      'instance_settings' => array(
        'classes' => 'col-md-6',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_video_left|node|banner_video|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_left|node|banner_video|teaser';
  $field_group->group_name = 'group_video_left';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_video';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_video_wrapper';
  $field_group->data = array(
    'label' => 'Video left',
    'weight' => '5',
    'children' => array(
      0 => 'group_video_video',
      1 => 'group_video_caption',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Video left',
      'instance_settings' => array(
        'classes' => 'col-md-6',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_video_left|node|banner_video|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_paragraph|node|banner_video|default';
  $field_group->group_name = 'group_video_paragraph';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_video';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_video_right';
  $field_group->data = array(
    'label' => 'Video paragraph',
    'weight' => '9',
    'children' => array(
      0 => 'field_core_description',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Video paragraph',
      'instance_settings' => array(
        'classes' => 'banner_video__paragraph',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_video_paragraph|node|banner_video|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_paragraph|node|banner_video|teaser';
  $field_group->group_name = 'group_video_paragraph';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_video';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_video_right';
  $field_group->data = array(
    'label' => 'Video paragraph',
    'weight' => '5',
    'children' => array(
      0 => 'field_core_description',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Video paragraph',
      'instance_settings' => array(
        'classes' => 'banner_video__paragraph',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_video_paragraph|node|banner_video|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_right|node|banner_video|default';
  $field_group->group_name = 'group_video_right';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_video';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_video_wrapper';
  $field_group->data = array(
    'label' => 'Video Right',
    'weight' => '6',
    'children' => array(
      0 => 'group_video_paragraph',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Video Right',
      'instance_settings' => array(
        'classes' => 'col-md-6',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_video_right|node|banner_video|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_right|node|banner_video|teaser';
  $field_group->group_name = 'group_video_right';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_video';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_video_wrapper';
  $field_group->data = array(
    'label' => 'Video Right',
    'weight' => '6',
    'children' => array(
      0 => 'group_video_paragraph',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Video Right',
      'instance_settings' => array(
        'classes' => 'col-md-6',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_video_right|node|banner_video|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_video|node|banner_video|default';
  $field_group->group_name = 'group_video_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_video';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_video_left';
  $field_group->data = array(
    'label' => 'Video Video',
    'weight' => '7',
    'children' => array(
      0 => 'field_banner_video_file',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Video Video',
      'instance_settings' => array(
        'classes' => 'banner_video__video',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_video_video|node|banner_video|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_video|node|banner_video|teaser';
  $field_group->group_name = 'group_video_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_video';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_video_left';
  $field_group->data = array(
    'label' => 'Video Video',
    'weight' => '7',
    'children' => array(
      0 => 'field_banner_video_file',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Video Video',
      'instance_settings' => array(
        'classes' => 'banner_video__video',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_video_video|node|banner_video|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_wrapper|node|banner_video|teaser';
  $field_group->group_name = 'group_video_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'banner_video';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Video Wrapper',
    'weight' => '0',
    'children' => array(
      0 => 'group_video_left',
      1 => 'group_video_right',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Video Wrapper',
      'instance_settings' => array(
        'classes' => 'banner_video row',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_video_wrapper|node|banner_video|teaser'] = $field_group;

  return $export;
}
