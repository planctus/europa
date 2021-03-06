<?php
/**
 * @file
 * cwt_activities.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cwt_activities_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_left|node|activities|teaser';
  $field_group->group_name = 'group_activity_left';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activities';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Left',
    'weight' => '0',
    'children' => array(
      0 => 'field_start_end_date',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Left',
      'instance_settings' => array(
        'classes' => 'listing__column-second column-second',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_activity_left|node|activities|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_right|node|activities|teaser';
  $field_group->group_name = 'group_activity_right';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activities';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '1',
    'children' => array(
      0 => 'title',
      1 => 'agenda_with_who',
      2 => 'group_agenda_meta',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Right',
      'instance_settings' => array(
        'classes' => 'listing__column-main column-main',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_activity_right|node|activities|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_agenda_meta|node|activities|teaser';
  $field_group->group_name = 'group_agenda_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activities';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_activity_right';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '2',
    'children' => array(
      0 => 'field_activity_address',
      1 => 'field_activity_type',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-agenda-meta field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
        'modifier' => '',
      ),
    ),
  );
  $field_groups['group_agenda_meta|node|activities|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_agenda|taxonomy_term|editorial_sections|form';
  $field_group->group_name = 'group_agenda';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'editorial_sections';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Calendar',
    'weight' => '5',
    'children' => array(
      0 => 'field_activity_block_description',
      1 => 'field_activity_block_title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-agenda field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_agenda|taxonomy_term|editorial_sections|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|activities|form';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activities';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_activity_link',
      2 => 'field_start_end_date',
      3 => 'field_activity_address',
      4 => 'title',
      5 => 'field_activity_type',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_content|node|activities|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|node|activities|form';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activities';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '1',
    'children' => array(
      0 => 'field_editorial_section_multiple',
      1 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_metadata|node|activities|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Calendar');
  t('Content');
  t('Left');
  t('Meta');
  t('Metadata');
  t('Right');

  return $field_groups;
}
