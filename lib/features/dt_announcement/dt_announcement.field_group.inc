<?php

/**
 * @file
 * dt_announcement.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_announcement_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_announcement_content|node|announcement|form';
  $field_group->group_name = 'group_announcement_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '1',
    'children' => array(
      0 => 'title_field',
      1 => 'body',
      2 => 'field_announcement_department',
      3 => 'field_announcement_location',
      4 => 'field_announcement_type',
      5 => 'field_core_introduction',
      6 => 'field_core_description',
      7 => 'field_core_legacy_link',
      8 => 'field_core_date_published',
      9 => 'field_publication_referenceno',
      10 => 'field_core_press_contacts',
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
  $field_groups['group_announcement_content|node|announcement|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_announcement_content|node|announcement|full';
  $field_group->group_name = 'group_announcement_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_announcement_main';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '6',
    'children' => array(
      0 => 'body',
      1 => 'field_announcement_info',
      2 => 'field_core_introduction',
      3 => 'field_core_links',
      4 => 'social_bookmark_webtools',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Content',
      'instance_settings' => array(
        'classes' => 'sidebar-field-group__main',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_announcement_content|node|announcement|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_announcement_context_info|node|announcement|form';
  $field_group->group_name = 'group_announcement_context_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Context information',
    'weight' => '3',
    'children' => array(
      0 => 'field_announcement_info',
      1 => 'field_core_links',
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
  $field_groups['group_announcement_context_info|node|announcement|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_announcement_contextual2|node|announcement|full';
  $field_group->group_name = 'group_announcement_contextual2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contextual meta',
    'weight' => '4',
    'children' => array(
      0 => 'field_announcement_department',
      1 => 'field_publication_referenceno',
      2 => 'location',
      3 => 'published',
      4 => 'changed_date',
    ),
    'format_type' => 'context_nav',
    'format_settings' => array(
      'label' => 'Contextual meta',
      'instance_settings' => array(
        'classes' => '',
        'modifier' => '',
      ),
    ),
  );
  $field_groups['group_announcement_contextual2|node|announcement|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_announcement_contextual|node|announcement|full';
  $field_group->group_name = 'group_announcement_contextual';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contextual navigation',
    'weight' => '6',
    'children' => array(
      0 => 'field_core_department',
      1 => 'field_core_persons',
      2 => 'field_core_topics',
    ),
    'format_type' => 'context_nav',
    'format_settings' => array(
      'label' => 'Contextual navigation',
      'instance_settings' => array(
        'modifier' => '',
      ),
    ),
  );
  $field_groups['group_announcement_contextual|node|announcement|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_announcement_main|node|announcement|full';
  $field_group->group_name = 'group_announcement_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Section',
    'weight' => '3',
    'children' => array(
      0 => 'group_announcement_content',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'modifier' => '',
        'layout' => '',
        'classes' => 'group-announcemen-main field-group-section_group',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_announcement_main|node|announcement|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_announcement_meta|node|announcement|full';
  $field_group->group_name = 'group_announcement_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_announcement_location',
      1 => 'field_announcement_type',
      2 => 'field_core_date_published',
      3 => 'author',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(
        'modifier' => 'meta--header',
      ),
    ),
  );
  $field_groups['group_announcement_meta|node|announcement|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_announcement_meta|node|announcement|meta';
  $field_group->group_name = 'group_announcement_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
  $field_group->mode = 'meta';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_announcement_type',
      1 => 'field_core_date_published',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_announcement_meta|node|announcement|meta'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_announcement_meta|node|announcement|teaser';
  $field_group->group_name = 'group_announcement_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_announcement_type',
      1 => 'field_core_date_published',
      2 => 'sticky_label',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_announcement_meta|node|announcement|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_announcement_related|node|announcement|form';
  $field_group->group_name = 'group_announcement_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '4',
    'children' => array(
      0 => 'field_core_announcement',
      1 => 'field_core_department',
      2 => 'field_core_persons',
      3 => 'field_core_topics',
      4 => 'field_core_policies',
      5 => 'field_core_priorities',
      6 => 'field_core_pages',
      7 => 'field_core_pri_policy_areas',
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
  $field_groups['group_announcement_related|node|announcement|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|announcement|full';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '7',
    'children' => array(
      0 => 'field_core_press_contacts',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'classes' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_contact|node|announcement|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_tabgroup|node|announcement|form';
  $field_group->group_name = 'group_content_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '2',
    'children' => array(
      0 => 'group_announcement_content',
      1 => 'group_announcement_context_info',
      2 => 'group_announcement_related',
      3 => 'group_editorial_settings',
      4 => 'group_media',
      5 => 'group_taxonomy',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_content_tabgroup|node|announcement|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_settings|node|announcement|form';
  $field_group->group_name = 'group_editorial_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
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
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_editorial_settings|node|announcement|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media|node|announcement|form';
  $field_group->group_name = 'group_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Featured Media',
    'weight' => '2',
    'children' => array(
      0 => 'field_announcement_image',
      1 => 'field_announcement_media',
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
  $field_groups['group_media|node|announcement|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related|node|announcement|full';
  $field_group->group_name = 'group_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related',
    'weight' => '8',
    'children' => array(
      0 => 'field_core_announcement',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Related',
      'instance_settings' => array(
        'classes' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_related|node|announcement|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy|node|announcement|form';
  $field_group->group_name = 'group_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
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
  $field_groups['group_taxonomy|node|announcement|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact');
  t('Content');
  t('Context information');
  t('Contextual meta');
  t('Contextual navigation');
  t('Editorial settings');
  t('Featured Media');
  t('Main Section');
  t('Meta');
  t('Related');
  t('Related content');
  t('Taxonomy');

  return $field_groups;
}
