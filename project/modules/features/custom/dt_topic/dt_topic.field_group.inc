<?php
/**
 * @file
 * dt_topic.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_topic_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_tabgroup|node|topic|form';
  $field_group->group_name = 'group_content_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_editorial_settings',
      1 => 'group_topic_contact',
      2 => 'group_topic_content',
      3 => 'group_topic_details',
      4 => 'group_topic_policy_areas',
      5 => 'group_topic_related',
      6 => 'group_topic_task',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-content-tabgroup field-group-tabs',
      ),
    ),
  );
  $export['group_content_tabgroup|node|topic|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_settings|node|topic|form';
  $field_group->group_name = 'group_editorial_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '15',
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
  $export['group_editorial_settings|node|topic|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_latest_main|node|topic|full';
  $field_group->group_name = 'group_latest_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_topic_latest';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '21',
    'children' => array(),
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
  $export['group_latest_main|node|topic|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_latest_sidebar|node|topic|full';
  $field_group->group_name = 'group_latest_sidebar';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_topic_latest';
  $field_group->data = array(
    'label' => 'Sidebar',
    'weight' => '22',
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
  $export['group_latest_sidebar|node|topic|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topic_contact|node|topic|form';
  $field_group->group_name = 'group_topic_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '14',
    'children' => array(
      0 => 'field_core_social_network_links',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-topic-contact field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_topic_contact|node|topic|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topic_content|node|topic|form';
  $field_group->group_name = 'group_topic_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '9',
    'children' => array(
      0 => 'title_field',
      1 => 'field_core_introduction',
      2 => 'field_core_description',
      3 => 'field_core_legacy_link',
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
  $export['group_topic_content|node|topic|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topic_contextual|node|topic|default';
  $field_group->group_name = 'group_topic_contextual';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contextual navigation',
    'weight' => '3',
    'children' => array(
      0 => 'field_core_department',
      1 => 'field_core_persons',
      2 => 'field_core_priorities',
      3 => 'field_core_topics',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Contextual navigation',
      'instance_settings' => array(
        'classes' => 'context-nav',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_topic_contextual|node|topic|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topic_contextual|node|topic|full';
  $field_group->group_name = 'group_topic_contextual';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contextual navigation',
    'weight' => '3',
    'children' => array(
      0 => 'field_core_department',
      1 => 'field_core_persons',
      2 => 'field_core_priorities',
      3 => 'field_core_topics',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Contextual navigation',
      'instance_settings' => array(
        'classes' => 'context-nav',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_topic_contextual|node|topic|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topic_details|node|topic|form';
  $field_group->group_name = 'group_topic_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Further information',
    'weight' => '13',
    'children' => array(
      0 => 'field_topic_commission_actions',
      1 => 'field_topic_objectives',
      2 => 'field_topic_targets',
      3 => 'field_core_link',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-topic-details field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_topic_details|node|topic|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topic_latest|node|topic|full';
  $field_group->group_name = 'group_topic_latest';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Latest',
    'weight' => '7',
    'children' => array(
      0 => 'group_latest_main',
      1 => 'group_latest_sidebar',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Latest',
      'instance_settings' => array(
        'classes' => 'sidebar-field-group section-group',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="latest"',
      ),
    ),
  );
  $export['group_topic_latest|node|topic|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topic_meta|node|topic|full';
  $field_group->group_name = 'group_topic_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'node_type',
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
  $export['group_topic_meta|node|topic|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topic_policy_areas|node|topic|form';
  $field_group->group_name = 'group_topic_policy_areas';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Policy areas',
    'weight' => '12',
    'children' => array(
      0 => 'field_core_policy_areas',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-topic-policy-areas field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_topic_policy_areas|node|topic|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topic_policy_areas|node|topic|full';
  $field_group->group_name = 'group_topic_policy_areas';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Policy areas',
    'weight' => '6',
    'children' => array(
      0 => 'field_core_policy_areas',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Policy areas',
      'instance_settings' => array(
        'classes' => 'section-group',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="policy-areas"',
      ),
    ),
  );
  $export['group_topic_policy_areas|node|topic|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topic_related_tasks|node|topic|full';
  $field_group->group_name = 'group_topic_related_tasks';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related Tasks',
    'weight' => '4',
    'children' => array(
      0 => 'field_core_top_tasks',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Related Tasks',
      'instance_settings' => array(
        'classes' => 'section-group',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_topic_related_tasks|node|topic|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topic_related|node|topic|form';
  $field_group->group_name = 'group_topic_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Related',
    'weight' => '11',
    'children' => array(
      0 => 'field_core_persons',
      1 => 'field_core_priorities',
      2 => 'field_core_topics',
      3 => 'field_core_department',
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
  $export['group_topic_related|node|topic|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topic_tasks|node|topic|default';
  $field_group->group_name = 'group_topic_tasks';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tasks',
    'weight' => '4',
    'children' => array(
      0 => 'field_core_top_tasks',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Tasks',
      'instance_settings' => array(
        'classes' => 'context-nav row',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_topic_tasks|node|topic|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topic_tasks|node|topic|full';
  $field_group->group_name = 'group_topic_tasks';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tasks',
    'weight' => '26',
    'children' => array(),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Tasks',
      'instance_settings' => array(
        'classes' => 'context-nav row',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_topic_tasks|node|topic|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topic_task|node|topic|form';
  $field_group->group_name = 'group_topic_task';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Task',
    'weight' => '10',
    'children' => array(
      0 => 'field_topic_tasks',
      1 => 'field_core_top_tasks',
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
  $export['group_topic_task|node|topic|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topic_what_is_doing|node|topic|full';
  $field_group->group_name = 'group_topic_what_is_doing';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'What the Commission is doing',
    'weight' => '8',
    'children' => array(
      0 => 'field_core_link',
      1 => 'field_topic_commission_actions',
      2 => 'field_topic_objectives',
      3 => 'field_topic_targets',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'What the Commission is doing',
      'instance_settings' => array(
        'classes' => 'section-group',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="what-is-doing"',
      ),
    ),
  );
  $export['group_topic_what_is_doing|node|topic|full'] = $field_group;

  return $export;
}
