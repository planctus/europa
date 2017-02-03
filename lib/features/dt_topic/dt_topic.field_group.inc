<?php
/**
 * @file
 * dt_topic.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_topic_field_group_info() {
  $field_groups = array();

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
      1 => 'group_taxonomy',
      2 => 'group_topic_contact',
      3 => 'group_topic_content',
      4 => 'group_topic_details',
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
  $field_groups['group_content_tabgroup|node|topic|form'] = $field_group;

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
      4 => 'field_core_latest_visibility',
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
  $field_groups['group_editorial_settings|node|topic|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social_bookmark_section|node|topic|full';
  $field_group->group_name = 'group_social_bookmark_section';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Social Bookmark Webtools section group wrapper',
    'weight' => '7',
    'children' => array(
      0 => 'social_bookmark_webtools',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'modifier' => '',
        'layout' => '',
        'classes' => 'group-social-bookmark-section field-group-section_group',
        'show_label' => 0,
        'attributes' => '',
        'label_element' => 'h2',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_social_bookmark_section|node|topic|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy|node|topic|form';
  $field_group->group_name = 'group_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Taxonomy',
    'weight' => '14',
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
  $field_groups['group_taxonomy|node|topic|form'] = $field_group;

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
    'weight' => '13',
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
  $field_groups['group_topic_contact|node|topic|form'] = $field_group;

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
      4 => 'field_core_keywords',
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
  $field_groups['group_topic_content|node|topic|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topic_contextual_section|node|topic|full';
  $field_group->group_name = 'group_topic_contextual_section';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contextual navigation section group wrapper',
    'weight' => '6',
    'children' => array(
      0 => 'group_topic_contextual',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Contextual navigation section group wrapper',
      'instance_settings' => array(
        'show_label' => '0',
        'label_element' => 'h2',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
        'classes' => 'group-topic-contextual-section field-group-section_group',
      ),
    ),
  );
  $field_groups['group_topic_contextual_section|node|topic|full'] = $field_group;

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
    'weight' => '6',
    'children' => array(
      0 => 'field_core_persons',
      1 => 'field_core_priorities',
      2 => 'field_core_topics',
      3 => 'field_core_department',
    ),
    'format_type' => 'context_nav',
    'format_settings' => array(
      'label' => 'Contextual navigation',
      'instance_settings' => array(
        'modifier' => '',
      ),
    ),
  );
  $field_groups['group_topic_contextual|node|topic|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topic_contextual|node|topic|full';
  $field_group->group_name = 'group_topic_contextual';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_topic_contextual_section';
  $field_group->data = array(
    'label' => 'Contextual navigation',
    'weight' => '7',
    'children' => array(
      0 => 'field_core_topics',
      1 => 'field_core_department',
      2 => 'field_core_persons',
      3 => 'field_core_priorities',
    ),
    'format_type' => 'context_nav',
    'format_settings' => array(
      'label' => 'Contextual navigation',
      'instance_settings' => array(
        'modifier' => '',
        'layout' => '',
        'classes' => '',
        'show_label' => 0,
        'attributes' => '',
        'label_element' => 'h2',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_topic_contextual|node|topic|full'] = $field_group;

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
    'weight' => '12',
    'children' => array(
      0 => 'field_topic_commission_actions',
      1 => 'field_topic_objectives',
      2 => 'field_topic_targets',
      3 => 'field_core_links',
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
  $field_groups['group_topic_details|node|topic|form'] = $field_group;

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
  $field_groups['group_topic_meta|node|topic|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topic_related_tasks|node|topic|full';
  $field_group->group_name = 'group_topic_related_tasks';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_topic_tasks';
  $field_group->data = array(
    'label' => 'Related Tasks',
    'weight' => '24',
    'children' => array(
      0 => 'field_core_top_tasks_links',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Related Tasks',
      'instance_settings' => array(
        'classes' => 'section__item',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_topic_related_tasks|node|topic|full'] = $field_group;

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
  $field_groups['group_topic_related|node|topic|form'] = $field_group;

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
    'weight' => '2',
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
  $field_groups['group_topic_tasks|node|topic|default'] = $field_group;

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
    'weight' => '3',
    'children' => array(
      0 => 'group_topic_related_tasks',
      1 => 'group_topics_specific_tasks',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Tasks',
      'instance_settings' => array(
        'modifier' => '',
        'layout' => '',
        'classes' => 'section--row-two',
      ),
    ),
  );
  $field_groups['group_topic_tasks|node|topic|full'] = $field_group;

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
      1 => 'field_core_top_tasks_links',
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
  $field_groups['group_topic_task|node|topic|form'] = $field_group;

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
    'weight' => '5',
    'children' => array(
      0 => 'field_topic_commission_actions',
      1 => 'field_topic_objectives',
      2 => 'field_topic_targets',
      3 => 'field_core_links',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'What the Commission is doing',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="what-is-doing"',
        'modifier' => '',
        'layout' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_topic_what_is_doing|node|topic|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topics_specific_tasks|node|topic|full';
  $field_group->group_name = 'group_topics_specific_tasks';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_topic_tasks';
  $field_group->data = array(
    'label' => 'Topic specific tasks',
    'weight' => '23',
    'children' => array(
      0 => 'field_topic_tasks',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Topic specific tasks',
      'instance_settings' => array(
        'classes' => 'section__item',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_topics_specific_tasks|node|topic|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact');
  t('Content');
  t('Contextual navigation');
  t('Contextual navigation section group wrapper');
  t('Editorial settings');
  t('Further information');
  t('Meta');
  t('Related');
  t('Related Tasks');
  t('Social Bookmark Webtools section group wrapper');
  t('Task');
  t('Tasks');
  t('Taxonomy');
  t('Topic specific tasks');
  t('What the Commission is doing');

  return $field_groups;
}
