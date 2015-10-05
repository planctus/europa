<?php
/**
 * @file
 * dt_policy_area.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_policy_area_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_tabgroup|node|policy_area|form';
  $field_group->group_name = 'group_content_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_editorial_settings',
      1 => 'group_policy_area_content',
      2 => 'group_policy_area_context',
      3 => 'group_policy_area_contact',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-content-tabgroup field-group-tabs',
      ),
    ),
  );
  $export['group_content_tabgroup|node|policy_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_settings|node|policy_area|form';
  $field_group->group_name = 'group_editorial_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_area';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '8',
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
        'classes' => 'group-editorial-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_editorial_settings|node|policy_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_latest_main|node|policy_area|full';
  $field_group->group_name = 'group_latest_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_area';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_policy_area_latest';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '39',
    'children' => array(
      0 => 'latest_announcements_block',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Main',
      'instance_settings' => array(
        'classes' => 'sidebar-field-group__main',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $export['group_latest_main|node|policy_area|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_latest_sidebar|node|policy_area|full';
  $field_group->group_name = 'group_latest_sidebar';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_area';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_policy_area_latest';
  $field_group->data = array(
    'label' => 'Sidebar',
    'weight' => '41',
    'children' => array(
      0 => 'field_core_social_network_links',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Sidebar',
      'instance_settings' => array(
        'classes' => 'sidebar-field-group__sidebar',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_latest_sidebar|node|policy_area|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_area_contact|node|policy_area|form';
  $field_group->group_name = 'group_policy_area_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_area';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '7',
    'children' => array(
      0 => 'field_core_social_network_links',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-area-contact field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_area_contact|node|policy_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_area_content|node|policy_area|form';
  $field_group->group_name = 'group_policy_area_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_area';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '5',
    'children' => array(
      0 => 'title_field',
      1 => 'field_core_introduction',
      2 => 'field_core_policy_area',
      3 => 'field_core_description',
      4 => 'field_core_legacy_link',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-area-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_area_content|node|policy_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_area_contextual|node|policy_area|full';
  $field_group->group_name = 'group_policy_area_contextual';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_area';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contextual navigation',
    'weight' => '4',
    'children' => array(
      0 => 'field_core_persons',
    ),
    'format_type' => 'context_nav',
    'format_settings' => array(
      'label' => 'Contextual navigation',
      'instance_settings' => array(
        'modifier' => '',
      ),
    ),
  );
  $export['group_policy_area_contextual|node|policy_area|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_area_context|node|policy_area|form';
  $field_group->group_name = 'group_policy_area_context';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_area';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Context references',
    'weight' => '6',
    'children' => array(
      0 => 'field_core_persons',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-area-context field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_area_context|node|policy_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_area_latest|node|policy_area|full';
  $field_group->group_name = 'group_policy_area_latest';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_area';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Latest',
    'weight' => '8',
    'children' => array(
      0 => 'group_latest_main',
      1 => 'group_latest_sidebar',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Latest',
      'instance_settings' => array(
        'classes' => 'sidebar-field-group section__group',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="latest"',
      ),
    ),
  );
  $export['group_policy_area_latest|node|policy_area|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_area_meta|node|policy_area|full';
  $field_group->group_name = 'group_policy_area_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_area';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'content_type_label',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(
        'classes' => 'meta meta--header',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_policy_area_meta|node|policy_area|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy|node|policy_area|full';
  $field_group->group_name = 'group_policy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_area';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Policy',
    'weight' => '5',
    'children' => array(
      0 => 'children_policies',
      1 => 'children_policy_areas',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Policy',
      'instance_settings' => array(
        'classes' => 'sidebar-field-group__main section__group',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="policy"',
      ),
    ),
  );
  $export['group_policy|node|policy_area|full'] = $field_group;

  return $export;
}
