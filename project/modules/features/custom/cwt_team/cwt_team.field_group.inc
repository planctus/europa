<?php
/**
 * @file
 * cwt_team.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cwt_team_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_activities|node|team|form';
  $field_group->group_name = 'group_team_activities';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Activities',
    'weight' => '2',
    'children' => array(
      0 => 'field_team_activities_info',
      1 => 'field_team_agenda',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-team-activities field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_team_activities|node|team|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_content|node|team|form';
  $field_group->group_name = 'group_team_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_illustrative_image',
      2 => 'field_team_links',
      3 => 'field_team_tagline',
      4 => 'field_team_term',
      5 => 'title',
      6 => 'field_team_attachments',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-team-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_team_content|node|team|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_disable|node|team|default';
  $field_group->group_name = 'group_team_disable';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Disable group',
    'weight' => '21',
    'children' => array(
      0 => 'body',
      1 => 'subscriptions_ui',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-team-disable field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_team_disable|node|team|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_members|node|team|form';
  $field_group->group_name = 'group_team_members';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Members',
    'weight' => '1',
    'children' => array(),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_team_members|node|team|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_metadata|node|team|form';
  $field_group->group_name = 'group_team_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '6',
    'children' => array(
      0 => 'field_editorial_section',
      1 => 'field_team_status',
      2 => 'field_team_subtype',
      3 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_team_metadata|node|team|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_priorities|node|team|form';
  $field_group->group_name = 'group_team_priorities';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Priorities',
    'weight' => '5',
    'children' => array(
      0 => 'field_team_priorities',
      1 => 'field_team_priorities_info',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-team-priorities field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_team_priorities|node|team|form'] = $field_group;

  return $export;
}
