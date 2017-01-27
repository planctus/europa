<?php

/**
 * @file
 * dt_priority_default.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_priority_default_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pri_pol_policy_areas|node|priority|full';
  $field_group->group_name = 'group_pri_pol_policy_areas';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Policy areas',
    'weight' => '5',
    'children' => array(
      0 => 'field_core_child_policies',
      1 => 'field_core_section_intro',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Policy areas',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="policy-areas"',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_pri_pol_policy_areas|node|priority|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_background|node|priority|form';
  $field_group->group_name = 'group_priority_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_priority_tabgroup';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '27',
    'children' => array(
      0 => 'field_core_background',
      1 => 'field_core_next_steps',
      2 => 'field_core_objective',
      3 => 'field_core_publications',
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
  $field_groups['group_priority_background|node|priority|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_background|node|priority|full';
  $field_group->group_name = 'group_priority_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '7',
    'children' => array(
      0 => 'field_core_background',
      1 => 'field_core_objective',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Background',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="background"',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_priority_background|node|priority|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_banner_sec_grp|node|priority|full';
  $field_group->group_name = 'group_priority_banner_sec_grp';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Banner Section group',
    'weight' => '4',
    'children' => array(
      0 => 'field_core_banner',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'modifier' => '',
        'layout' => '',
        'classes' => 'group-priority-banner-sec-grp field-group-section_group',
        'show_label' => 0,
        'attributes' => '',
        'label_element' => 'h2',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_priority_banner_sec_grp|node|priority|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_banner|node|priority|form';
  $field_group->group_name = 'group_priority_banner';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_priority_tabgroup';
  $field_group->data = array(
    'label' => 'Banner',
    'weight' => '25',
    'children' => array(
      0 => 'field_core_banner',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-priority-banner field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_priority_banner|node|priority|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_content|node|priority|form';
  $field_group->group_name = 'group_priority_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_priority_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '22',
    'children' => array(
      0 => 'title_field',
      1 => 'field_core_introduction',
      2 => 'field_core_description',
      3 => 'field_core_header_image',
      4 => 'field_core_image',
      5 => 'field_core_social_network_links',
      6 => 'field_core_legacy_link',
      7 => 'field_core_parent',
      8 => 'field_core_keywords',
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
  $field_groups['group_priority_content|node|priority|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_context_sec_grp|node|priority|full';
  $field_group->group_name = 'group_priority_context_sec_grp';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Context Nav Section Group',
    'weight' => '3',
    'children' => array(
      0 => 'group_priority_contextual',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'modifier' => '',
        'layout' => '',
        'classes' => 'group-priority-context-sec-grp field-group-section_group',
        'show_label' => 0,
        'attributes' => '',
        'label_element' => 'h2',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_priority_context_sec_grp|node|priority|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_contextual|node|priority|full';
  $field_group->group_name = 'group_priority_contextual';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_priority_context_sec_grp';
  $field_group->data = array(
    'label' => 'Contextual navigation',
    'weight' => '4',
    'children' => array(
      0 => 'field_core_departments',
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
  $field_groups['group_priority_contextual|node|priority|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_documents|node|priority|full';
  $field_group->group_name = 'group_priority_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '8',
    'children' => array(
      0 => 'field_core_publications',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Documents',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="documents"',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_priority_documents|node|priority|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_editorial|node|priority|form';
  $field_group->group_name = 'group_priority_editorial';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_priority_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '29',
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
  $field_groups['group_priority_editorial|node|priority|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_featured_item|node|priority|form';
  $field_group->group_name = 'group_priority_featured_item';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_priority_tabgroup';
  $field_group->data = array(
    'label' => 'Featured content',
    'weight' => '26',
    'children' => array(
      0 => 'field_core_featured_item',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-priority-featured-item field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_priority_featured_item|node|priority|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_meta|node|priority|full';
  $field_group->group_name = 'group_priority_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
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
  $field_groups['group_priority_meta|node|priority|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_meta|node|priority|teaser';
  $field_group->group_name = 'group_priority_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'teaser';
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
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_priority_meta|node|priority|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_policy|node|priority|form';
  $field_group->group_name = 'group_priority_policy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_priority_tabgroup';
  $field_group->data = array(
    'label' => 'Policy',
    'weight' => '23',
    'children' => array(
      0 => 'field_core_child_policies',
      1 => 'field_core_section_intro',
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
  $field_groups['group_priority_policy|node|priority|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_related|node|priority|form';
  $field_group->group_name = 'group_priority_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_priority_tabgroup';
  $field_group->data = array(
    'label' => 'Related',
    'weight' => '24',
    'children' => array(
      0 => 'field_core_persons',
      1 => 'field_core_departments',
      2 => 'field_core_links',
      3 => 'field_core_policy_areas',
      4 => 'field_core_topics',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-priority-related field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_priority_related|node|priority|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_related|node|priority|full';
  $field_group->group_name = 'group_priority_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related links',
    'weight' => '10',
    'children' => array(
      0 => 'field_core_links',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Related links',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="related-links"',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_priority_related|node|priority|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_tabgroup|node|priority|form';
  $field_group->group_name = 'group_priority_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_priority_background',
      1 => 'group_priority_banner',
      2 => 'group_priority_content',
      3 => 'group_priority_editorial',
      4 => 'group_priority_featured_item',
      5 => 'group_priority_policy',
      6 => 'group_priority_related',
      7 => 'group_taxonomy',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-policy-next-step-tabgroup field-group-tabs',
      ),
    ),
  );
  $field_groups['group_priority_tabgroup|node|priority|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_whatnext|node|priority|full';
  $field_group->group_name = 'group_priority_whatnext';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'What\'s next?',
    'weight' => '9',
    'children' => array(
      0 => 'field_core_next_steps',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'What\'s next?',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="whats-next"',
        'modifier' => '',
        'layout' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_priority_whatnext|node|priority|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy|node|priority|form';
  $field_group->group_name = 'group_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_priority_tabgroup';
  $field_group->data = array(
    'label' => 'Taxonomy',
    'weight' => '28',
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
  $field_groups['group_taxonomy|node|priority|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Background');
  t('Banner');
  t('Banner Section group');
  t('Content');
  t('Context Nav Section Group');
  t('Contextual navigation');
  t('Documents');
  t('Editorial settings');
  t('Featured content');
  t('Meta');
  t('Policy');
  t('Policy areas');
  t('Related');
  t('Related links');
  t('Taxonomy');
  t('What\'s next?');

  return $field_groups;
}
