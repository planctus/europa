<?php
/**
 * @file
 * dt_pri_policy_area_default.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_pri_policy_area_default_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pri_pol_area_background|node|priority_policy_area|form';
  $field_group->group_name = 'group_pri_pol_area_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_pri_pol_area_tabgroup';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '25',
    'children' => array(
      0 => 'field_pri_pol_area_objectives',
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
  $export['group_pri_pol_area_background|node|priority_policy_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pri_pol_area_content|node|priority_policy_area|form';
  $field_group->group_name = 'group_pri_pol_area_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_pri_pol_area_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '22',
    'children' => array(
      0 => 'title_field',
      1 => 'field_core_introduction',
      2 => 'field_core_description',
      3 => 'field_pri_pol_area_headerbg',
      4 => 'field_pri_pol_area_image',
      5 => 'field_core_social_network_links',
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
  $export['group_pri_pol_area_content|node|priority_policy_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pri_pol_area_editorial_set|node|priority_policy_area|form';
  $field_group->group_name = 'group_pri_pol_area_editorial_set';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_pri_pol_area_input_tabg';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '25',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'group_content_access',
      2 => 'language',
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
  $export['group_pri_pol_area_editorial_set|node|priority_policy_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pri_pol_area_editorial|node|priority_policy_area|form';
  $field_group->group_name = 'group_pri_pol_area_editorial';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_pri_pol_area_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '26',
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
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_pri_pol_area_editorial|node|priority_policy_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pri_pol_area_input_tabg|node|priority_policy_area|form';
  $field_group->group_name = 'group_pri_pol_area_input_tabg';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_pri_pol_area_content',
      1 => 'group_pri_pol_area_policy',
      2 => 'group_pri_pol_area_related',
      3 => 'group_pri_pol_area_banner',
      4 => 'group_pri_pol_area_featured_cont',
      5 => 'group_pri_pol_area_background',
      6 => 'group_pri_pol_area_editorial_set',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-pri-pol-area-input-tabg field-group-tabs',
      ),
    ),
  );
  $export['group_pri_pol_area_input_tabg|node|priority_policy_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pri_pol_area_meta|node|priority_policy_area|teaser';
  $field_group->group_name = 'group_pri_pol_area_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_priority_policy_area_type',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(
        'classes' => 'meta',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_pri_pol_area_meta|node|priority_policy_area|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pri_pol_area_policy|node|priority_policy_area|form';
  $field_group->group_name = 'group_pri_pol_area_policy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_pri_pol_area_tabgroup';
  $field_group->data = array(
    'label' => 'Policy',
    'weight' => '23',
    'children' => array(
      0 => 'field_pri_pol_area_policy_intro',
      1 => 'field_pri_pol_child_pri_pol_area',
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
  $export['group_pri_pol_area_policy|node|priority_policy_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pri_pol_area_tabgroup|node|priority_policy_area|form';
  $field_group->group_name = 'group_pri_pol_area_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_pri_pol_area_related',
      1 => 'group_pri_pol_area_background',
      2 => 'group_pri_pol_area_content',
      3 => 'group_pri_pol_area_editorial',
      4 => 'group_pri_pol_area_policy',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-policy-next-step-tabgroup field-group-tabs',
      ),
    ),
  );
  $export['group_pri_pol_area_tabgroup|node|priority_policy_area|form'] = $field_group;

  return $export;
}
