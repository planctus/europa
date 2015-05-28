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
  $field_group->identifier = 'group_content_tabgroup|node|policy|form';
  $field_group->group_name = 'group_content_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '1',
    'children' => array(
      0 => 'group_policy_banner',
      1 => 'group_policy_common',
      2 => 'group_policy_details',
      3 => 'group_policy_editorial',
      4 => 'group_policy_follow',
      5 => 'group_policy_implementation',
      6 => 'group_policy_input',
      7 => 'group_policy_next_steps',
      8 => 'group_policy_other_relations',
      9 => 'group_policy_related',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-content-tabgroup field-group-tabs',
      ),
    ),
  );
  $export['group_content_tabgroup|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_author|node|policy|form';
  $field_group->group_name = 'group_policy_author';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_policy_banner';
  $field_group->data = array(
    'label' => 'Author',
    'weight' => '16',
    'children' => array(
      0 => 'field_policy_author',
      1 => 'field_policy_author_gender',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-author field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_author|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_banner|node|policy|form';
  $field_group->group_name = 'group_policy_banner';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Banner',
    'weight' => '4',
    'children' => array(
      0 => 'field_policy_caption',
      1 => 'field_policy_featured_file',
      2 => 'field_policy_paragraph',
      3 => 'field_policy_quote',
      4 => 'field_policy_sharable_banner',
      5 => 'group_policy_author',
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
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Common',
    'weight' => '1',
    'children' => array(
      0 => 'title_field',
      1 => 'field_policy_introduction',
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
  $field_group->identifier = 'group_policy_details|node|policy|form';
  $field_group->group_name = 'group_policy_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '9',
    'children' => array(
      0 => 'field_policy_detail_additional',
      1 => 'field_policy_detail_body',
      2 => 'field_policy_detail_file',
      3 => 'field_policy_detail_objectives',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-details field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_details|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_editorial|node|policy|form';
  $field_group->group_name = 'group_policy_editorial';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '12',
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
        'classes' => 'group-policy-editorial field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_editorial|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_implementation|node|policy|form';
  $field_group->group_name = 'group_policy_implementation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Implementation',
    'weight' => '5',
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
  $field_group->identifier = 'group_policy_input|node|policy|form';
  $field_group->group_name = 'group_policy_input';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Policy input',
    'weight' => '6',
    'children' => array(
      0 => 'field_policy_input',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-input field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_input|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_next_steps|node|policy|form';
  $field_group->group_name = 'group_policy_next_steps';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Next steps',
    'weight' => '7',
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
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Other relations',
    'weight' => '3',
    'children' => array(
      0 => 'field_core_department',
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
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Relations with other content types',
    'weight' => '2',
    'children' => array(
      0 => 'field_core_topics',
      1 => 'field_strategy_policy_area',
      2 => 'field_strategy_priority',
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
