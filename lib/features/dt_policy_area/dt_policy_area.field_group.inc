<?php
/**
 * @file
 * dt_policy_area.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_policy_area_field_group_info() {
  $field_groups = array();

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
      1 => 'group_policy_area_contact',
      2 => 'group_policy_area_content',
      3 => 'group_policy_area_context',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-content-tabgroup field-group-tabs',
      ),
    ),
  );
  $field_groups['group_content_tabgroup|node|policy_area|form'] = $field_group;

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
  $field_groups['group_editorial_settings|node|policy_area|form'] = $field_group;

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
  $field_groups['group_policy_area_contact|node|policy_area|form'] = $field_group;

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
      2 => 'field_core_description',
      3 => 'field_core_legacy_link',
      4 => 'field_core_policy_areas',
      5 => 'field_core_keywords',
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
  $field_groups['group_policy_area_content|node|policy_area|form'] = $field_group;

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
  $field_groups['group_policy_area_contextual|node|policy_area|full'] = $field_group;

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
  $field_groups['group_policy_area_context|node|policy_area|form'] = $field_group;

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
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(
        'modifier' => 'meta--header',
      ),
    ),
  );
  $field_groups['group_policy_area_meta|node|policy_area|full'] = $field_group;

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
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Policy',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="policy"',
        'modifier' => '',
        'layout' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_policy|node|policy_area|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact');
  t('Content');
  t('Context references');
  t('Contextual navigation');
  t('Editorial settings');
  t('Meta');
  t('Policy');

  return $field_groups;
}
