<?php
/**
 * @file
 * dt_department.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_department_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_tabgroup|node|department|form';
  $field_group->group_name = 'group_content_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_department_contact',
      1 => 'group_editorial_settings',
      2 => 'group_person',
      3 => 'group_priorities',
      4 => 'group_profile_information',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-content-tabgroup field-group-tabs',
      ),
    ),
  );
  $export['group_content_tabgroup|node|department|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_department_contact|node|department|form';
  $field_group->group_name = 'group_department_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '5',
    'children' => array(
      0 => 'field_core_contact',
      1 => 'field_core_social_network_links',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-department-contact field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_department_contact|node|department|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_department_contact|node|department|full';
  $field_group->group_name = 'group_department_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '9',
    'children' => array(
      0 => 'field_core_contact',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'classes' => 'section__group',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="contact"',
      ),
    ),
  );
  $export['group_department_contact|node|department|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_department_latest|node|department|full';
  $field_group->group_name = 'group_department_latest';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Latest',
    'weight' => '6',
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
  $export['group_department_latest|node|department|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_department_leadership|node|department|full';
  $field_group->group_name = 'group_department_leadership';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Leadership & Organisation',
    'weight' => '8',
    'children' => array(
      0 => 'field_core_persons',
      1 => 'field_department_organigram',
      2 => 'field_department_staff_search',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Leadership & Organisation',
      'instance_settings' => array(
        'classes' => 'section__group',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="leadership"',
      ),
    ),
  );
  $export['group_department_leadership|node|department|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_department_meta|node|department|full';
  $field_group->group_name = 'group_department_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_core_abbreviation',
      1 => 'field_core_ecorganisation',
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
  $export['group_department_meta|node|department|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_department_meta|node|department|meta';
  $field_group->group_name = 'group_department_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department';
  $field_group->mode = 'meta';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_core_abbreviation',
      1 => 'field_core_ecorganisation',
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
  $export['group_department_meta|node|department|meta'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_department_responsibilit|node|department|full';
  $field_group->group_name = 'group_department_responsibilit';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Responsibilities',
    'weight' => '7',
    'children' => array(
      0 => 'field_core_priorities',
      1 => 'field_core_topics',
      2 => 'field_department_intro_sentence',
      3 => 'field_department_plans_reports',
      4 => 'field_department_tasks_desc',
      5 => 'field_department_work_areas_sent',
      6 => 'field_department_mission',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Responsibilities',
      'instance_settings' => array(
        'classes' => 'section__group',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="resposibilities"',
      ),
    ),
  );
  $export['group_department_responsibilit|node|department|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_settings|node|department|form';
  $field_group->group_name = 'group_editorial_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '6',
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
  $export['group_editorial_settings|node|department|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_latest_main|node|department|full';
  $field_group->group_name = 'group_latest_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_department_latest';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '15',
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
      ),
    ),
  );
  $export['group_latest_main|node|department|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_latest_sidebar|node|department|full';
  $field_group->group_name = 'group_latest_sidebar';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_department_latest';
  $field_group->data = array(
    'label' => 'Sidebar',
    'weight' => '16',
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
  $export['group_latest_sidebar|node|department|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person|node|department|form';
  $field_group->group_name = 'group_person';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Leadership & Organisation',
    'weight' => '4',
    'children' => array(
      0 => 'field_core_persons',
      1 => 'field_department_organigram',
      2 => 'field_department_staff_search',
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
  $export['group_person|node|department|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priorities|node|department|form';
  $field_group->group_name = 'group_priorities';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Responsibilities, tasks',
    'weight' => '2',
    'children' => array(
      0 => 'field_core_topics',
      1 => 'field_department_intro_sentence',
      2 => 'field_department_plans_reports',
      3 => 'field_department_tasks_desc',
      4 => 'field_department_work_areas_sent',
      5 => 'field_core_priorities',
      6 => 'field_department_mission',
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
  $export['group_priorities|node|department|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_information|node|department|form';
  $field_group->group_name = 'group_profile_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Profile information',
    'weight' => '1',
    'children' => array(
      0 => 'title_field',
      1 => 'field_core_abbreviation',
      2 => 'field_core_ecorganisation',
      3 => 'field_core_introduction',
      4 => 'field_core_legacy_links',
      5 => 'field_department_tasks',
      6 => 'field_core_legacy_link',
      7 => 'field_core_description',
      8 => 'field_core_links',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Profile information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_profile_information|node|department|form'] = $field_group;

  return $export;
}
