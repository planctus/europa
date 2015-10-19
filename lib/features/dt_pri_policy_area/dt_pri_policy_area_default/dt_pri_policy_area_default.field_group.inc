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
    'weight' => '27',
    'children' => array(
      0 => 'field_core_publications',
      1 => 'field_core_background',
      2 => 'field_core_next_steps',
      3 => 'field_core_objective',
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
  $field_group->identifier = 'group_pri_pol_area_background|node|priority_policy_area|full';
  $field_group->group_name = 'group_pri_pol_area_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '8',
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
  $export['group_pri_pol_area_background|node|priority_policy_area|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pri_pol_area_banner|node|priority_policy_area|form';
  $field_group->group_name = 'group_pri_pol_area_banner';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_pri_pol_area_tabgroup';
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
        'classes' => 'group-pri-pol-area-banner field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_pri_pol_area_banner|node|priority_policy_area|form'] = $field_group;

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
      1 => 'field_core_description',
      2 => 'field_core_header_image',
      3 => 'field_core_image',
      4 => 'field_core_introduction',
      5 => 'field_core_social_network_links',
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
  $export['group_pri_pol_area_content|node|priority_policy_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pri_pol_area_contextual|node|priority_policy_area|full';
  $field_group->group_name = 'group_pri_pol_area_contextual';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contextual navigation',
    'weight' => '3',
    'children' => array(
      0 => 'field_core_persons',
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
  $export['group_pri_pol_area_contextual|node|priority_policy_area|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pri_pol_area_documents|node|priority_policy_area|full';
  $field_group->group_name = 'group_pri_pol_area_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '9',
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
  $export['group_pri_pol_area_documents|node|priority_policy_area|full'] = $field_group;

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
  $export['group_pri_pol_area_editorial|node|priority_policy_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pri_pol_area_featured_item|node|priority_policy_area|form';
  $field_group->group_name = 'group_pri_pol_area_featured_item';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_pri_pol_area_tabgroup';
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
        'classes' => 'group-pri-pol-area-featured-item field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_pri_pol_area_featured_item|node|priority_policy_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pri_pol_area_latest_main|node|priority_policy_area|full';
  $field_group->group_name = 'group_pri_pol_area_latest_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_pri_pol_area_latest';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '33',
    'children' => array(
      0 => 'field_core_featured_item',
      1 => 'latest_announcements_block',
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
  $export['group_pri_pol_area_latest_main|node|priority_policy_area|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pri_pol_area_latest_sbar|node|priority_policy_area|full';
  $field_group->group_name = 'group_pri_pol_area_latest_sbar';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_pri_pol_area_latest';
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
  $export['group_pri_pol_area_latest_sbar|node|priority_policy_area|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pri_pol_area_latest|node|priority_policy_area|full';
  $field_group->group_name = 'group_pri_pol_area_latest';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Latest',
    'weight' => '7',
    'children' => array(
      0 => 'group_pri_pol_area_latest_main',
      1 => 'group_pri_pol_area_latest_sbar',
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
  $export['group_pri_pol_area_latest|node|priority_policy_area|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pri_pol_area_meta|node|priority_policy_area|full';
  $field_group->group_name = 'group_pri_pol_area_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
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
  $export['group_pri_pol_area_meta|node|priority_policy_area|full'] = $field_group;

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
      0 => 'content_type_label',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(),
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
  $export['group_pri_pol_area_policy|node|priority_policy_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pri_pol_area_related|node|priority_policy_area|form';
  $field_group->group_name = 'group_pri_pol_area_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_pri_pol_area_tabgroup';
  $field_group->data = array(
    'label' => 'Related',
    'weight' => '24',
    'children' => array(
      0 => 'field_core_persons',
      1 => 'field_core_policy_areas',
      2 => 'field_core_links',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-pri-pol-area-related field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_pri_pol_area_related|node|priority_policy_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pri_pol_area_related|node|priority_policy_area|full';
  $field_group->group_name = 'group_pri_pol_area_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related links',
    'weight' => '11',
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
  $export['group_pri_pol_area_related|node|priority_policy_area|full'] = $field_group;

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
      0 => 'group_pri_pol_area_background',
      1 => 'group_pri_pol_area_banner',
      2 => 'group_pri_pol_area_content',
      3 => 'group_pri_pol_area_editorial',
      4 => 'group_pri_pol_area_featured_item',
      5 => 'group_pri_pol_area_policy',
      6 => 'group_pri_pol_area_related',
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pri_pol_area_whatnext|node|priority_policy_area|full';
  $field_group->group_name = 'group_pri_pol_area_whatnext';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'What\'s next?',
    'weight' => '10',
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
  $export['group_pri_pol_area_whatnext|node|priority_policy_area|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pri_pol_policy_areas|node|priority_policy_area|full';
  $field_group->group_name = 'group_pri_pol_policy_areas';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
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
  $export['group_pri_pol_policy_areas|node|priority_policy_area|full'] = $field_group;

  return $export;
}
