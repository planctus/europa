<?php

/**
 * @file
 * dt_department.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_department_field_group_info() {
  $field_groups = array();

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
      5 => 'group_taxonomy',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-content-tabgroup field-group-tabs',
      ),
    ),
  );
  $field_groups['group_content_tabgroup|node|department|form'] = $field_group;

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
    'weight' => '4',
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
  $field_groups['group_department_contact|node|department|form'] = $field_group;

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
    'weight' => '10',
    'children' => array(
      0 => 'field_core_contact',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="contact"',
        'modifier' => '',
        'layout' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_department_contact|node|department|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_department_latest_news|node|department|full';
  $field_group->group_name = 'group_department_latest_news';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Latest',
    'weight' => '6',
    'children' => array(
      0 => 'field_department_news_link',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Latest',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="latest"',
        'modifier' => '',
        'layout' => '',
        'classes' => 'group-department-latest-news field-group-section_group',
      ),
    ),
  );
  $field_groups['group_department_latest_news|node|department|full'] = $field_group;

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
    'label' => 'Leadership and organisation',
    'weight' => '9',
    'children' => array(
      0 => 'field_core_persons',
      1 => 'field_department_organigram',
      2 => 'field_department_staff_search',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Leadership and organisation',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="leadership"',
        'modifier' => '',
        'layout' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_department_leadership|node|department|full'] = $field_group;

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
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(
        'modifier' => 'meta--header',
      ),
    ),
  );
  $field_groups['group_department_meta|node|department|full'] = $field_group;

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
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_department_meta|node|department|meta'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_department_relatedlinks|node|department|full';
  $field_group->group_name = 'group_department_relatedlinks';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related links',
    'weight' => '11',
    'children' => array(
      0 => 'field_core_links',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Related links',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="related"',
        'modifier' => '',
        'layout' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_department_relatedlinks|node|department|full'] = $field_group;

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
    'weight' => '8',
    'children' => array(
      0 => 'field_core_priorities',
      1 => 'field_core_topics',
      2 => 'field_department_intro_sentence',
      3 => 'field_department_plans_reports',
      4 => 'field_department_tasks_desc',
      5 => 'field_department_work_areas_sent',
      6 => 'field_department_mission',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Responsibilities',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="responsibilities"',
        'modifier' => '',
        'layout' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_department_responsibilit|node|department|full'] = $field_group;

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
      2 => 'field_core_latest_visibility',
      3 => 'scheduler_settings',
      4 => 'language',
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
  $field_groups['group_editorial_settings|node|department|form'] = $field_group;

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
    'label' => 'Leadership and organisation',
    'weight' => '3',
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
  $field_groups['group_person|node|department|form'] = $field_group;

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
      0 => 'field_core_priorities',
      1 => 'field_core_topics',
      2 => 'field_department_intro_sentence',
      3 => 'field_department_plans_reports',
      4 => 'field_department_tasks_desc',
      5 => 'field_department_work_areas_sent',
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
  $field_groups['group_priorities|node|department|form'] = $field_group;

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
      1 => 'field_department_tasks',
      2 => 'field_core_abbreviation',
      3 => 'field_core_ecorganisation',
      4 => 'field_core_introduction',
      5 => 'field_core_legacy_link',
      6 => 'field_core_legacy_links',
      7 => 'field_core_description',
      8 => 'field_core_links',
      9 => 'field_department_dg_type',
      10 => 'field_department_news_link',
      11 => 'field_core_keywords',
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
  $field_groups['group_profile_information|node|department|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy|node|department|form';
  $field_group->group_name = 'group_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Taxonomy',
    'weight' => '5',
    'children' => array(
      0 => 'field_eurovoc_taxonomy',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomy field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomy|node|department|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact');
  t('Content');
  t('Editorial settings');
  t('Latest');
  t('Leadership and organisation');
  t('Meta');
  t('Profile information');
  t('Related links');
  t('Responsibilities');
  t('Responsibilities, tasks');
  t('Taxonomy');

  return $field_groups;
}
