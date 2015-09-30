<?php
/**
 * @file
 * cwt_news.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cwt_news_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_news_content|node|aggregated_news|form';
  $field_group->group_name = 'group_news_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'aggregated_news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_aggregated_news_link',
      2 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-news-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_news_content|node|aggregated_news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_news_metadata|node|aggregated_news|form';
  $field_group->group_name = 'group_news_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'aggregated_news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '4',
    'children' => array(
      0 => 'field_aggregated_news_type',
      1 => 'field_editorial_section_multiple',
      2 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-news-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_news_metadata|node|aggregated_news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_news_meta|node|aggregated_news|full';
  $field_group->group_name = 'group_news_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'aggregated_news';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_aggregated_news_type',
      1 => 'post_date',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-news-meta field-group-meta_wrapper',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_news_meta|node|aggregated_news|full'] = $field_group;

  return $export;
}
