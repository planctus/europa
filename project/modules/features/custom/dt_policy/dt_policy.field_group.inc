<?php
/**
 * @file
 * dt_policy.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_policy_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_banner|node|policy|form';
  $field_group->group_name = 'group_policy_banner';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Banner',
    'weight' => '3',
    'children' => array(
      0 => 'field_policy_banner',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-banner field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_banner|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_common|node|policy|form';
  $field_group->group_name = 'group_policy_common';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Common',
    'weight' => '0',
    'children' => array(
      0 => 'field_policy_introduction',
      1 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-common field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_common|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_follow|node|policy|form';
  $field_group->group_name = 'group_policy_follow';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Follow',
    'weight' => '8',
    'children' => array(
      0 => 'field_policy_follow',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-follow field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_follow|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_implementation|node|policy|form';
  $field_group->group_name = 'group_policy_implementation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Implementation',
    'weight' => '4',
    'children' => array(
      0 => 'field_policy_implementations',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-implementation field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_implementation|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_imput|node|policy|form';
  $field_group->group_name = 'group_policy_imput';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Policy input',
    'weight' => '5',
    'children' => array(
      0 => 'field_policy_input',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-imput field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_imput|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_latest|node|policy|form';
  $field_group->group_name = 'group_policy_latest';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Latest',
    'weight' => '7',
    'children' => array(
      0 => 'field_core_announcement',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-latest field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_latest|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_metadata|node|policy|form';
  $field_group->group_name = 'group_policy_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta data',
    'weight' => '9',
    'children' => array(
      0 => 'group_content_access',
      1 => 'path',
      2 => 'scheduler_settings',
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
  $export['group_policy_metadata|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_next_steps|node|policy|form';
  $field_group->group_name = 'group_policy_next_steps';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Next steps',
    'weight' => '6',
    'children' => array(
      0 => 'field_policy_next_steps',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-next-steps field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_next_steps|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_other_relations|node|policy|form';
  $field_group->group_name = 'group_policy_other_relations';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Other relations',
    'weight' => '2',
    'children' => array(
      0 => 'field_core_department',
      1 => 'field_policy_commissioner',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-other-relations field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_other_relations|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_related|node|policy|form';
  $field_group->group_name = 'group_policy_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Relations with other content types',
    'weight' => '1',
    'children' => array(
      0 => 'field_policy_priority',
      1 => 'field_policy_area',
      2 => 'field_core_topics',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-related field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_related|node|policy|form'] = $field_group;

  return $export;
}
