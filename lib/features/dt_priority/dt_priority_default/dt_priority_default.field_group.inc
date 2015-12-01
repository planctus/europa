<?php
/**
 * @file
 * dt_priority_default.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_priority_default_field_group_info() {
  $export = array();

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
    'label' => 'Policy Areas',
    'weight' => '5',
    'children' => array(
      0 => 'field_core_child_policies',
      1 => 'field_core_section_intro',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Policy Areas',
      'instance_settings' => array(
        'classes' => 'section__group sidebar-field-group__main',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="policy-areas"',
      ),
    ),
  );
  $export['group_pri_pol_policy_areas|node|priority|full'] = $field_group;

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
  $export['group_priority_background|node|priority|form'] = $field_group;

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
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Background',
      'instance_settings' => array(
        'classes' => 'section__group sidebar-field-group__main',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="background"',
      ),
    ),
  );
  $export['group_priority_background|node|priority|full'] = $field_group;

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
  $export['group_priority_banner|node|priority|form'] = $field_group;

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
      3 => 'field_core_social_network_links',
      4 => 'field_core_header_image',
      5 => 'field_core_image',
      6 => 'field_core_legacy_link',
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
  $export['group_priority_content|node|priority|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_contextual|node|priority|full';
  $field_group->group_name = 'group_priority_contextual';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contextual navigation',
    'weight' => '3',
    'children' => array(
      0 => 'field_core_persons',
      1 => 'field_core_departments',
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
  $export['group_priority_contextual|node|priority|full'] = $field_group;

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
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Documents',
      'instance_settings' => array(
        'classes' => 'section__group sidebar-field-group__main',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="documents"',
      ),
    ),
  );
  $export['group_priority_documents|node|priority|full'] = $field_group;

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
    'weight' => '28',
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
  $export['group_priority_editorial|node|priority|form'] = $field_group;

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
  $export['group_priority_featured_item|node|priority|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_latest_main|node|priority|full';
  $field_group->group_name = 'group_priority_latest_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_priority_latest';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '33',
    'children' => array(
      0 => 'field_core_featured_item',
      1 => 'related_announcements',
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
  $export['group_priority_latest_main|node|priority|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_latest_sbar|node|priority|full';
  $field_group->group_name = 'group_priority_latest_sbar';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_priority_latest';
  $field_group->data = array(
    'label' => 'Sidebar',
    'weight' => '34',
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
  $export['group_priority_latest_sbar|node|priority|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_latest|node|priority|full';
  $field_group->group_name = 'group_priority_latest';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Latest',
    'weight' => '6',
    'children' => array(
      0 => 'group_priority_latest_main',
      1 => 'group_priority_latest_sbar',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Latest',
      'instance_settings' => array(
        'classes' => 'sidebar-field-group section__group',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
      ),
    ),
  );
  $export['group_priority_latest|node|priority|full'] = $field_group;

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
  $export['group_priority_meta|node|priority|full'] = $field_group;

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
  $export['group_priority_meta|node|priority|teaser'] = $field_group;

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
  $export['group_priority_policy|node|priority|form'] = $field_group;

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
      1 => 'field_core_links',
      2 => 'field_core_policy_areas',
      3 => 'field_core_departments',
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
  $export['group_priority_related|node|priority|form'] = $field_group;

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
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Related links',
      'instance_settings' => array(
        'classes' => 'section__group sidebar-field-group__main',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="related-links"',
      ),
    ),
  );
  $export['group_priority_related|node|priority|full'] = $field_group;

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
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-policy-next-step-tabgroup field-group-tabs',
      ),
    ),
  );
  $export['group_priority_tabgroup|node|priority|form'] = $field_group;

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
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'What\'s next?',
      'instance_settings' => array(
        'classes' => 'section__group sidebar-field-group__main',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="whats-next"',
      ),
    ),
  );
  $export['group_priority_whatnext|node|priority|full'] = $field_group;

  return $export;
}