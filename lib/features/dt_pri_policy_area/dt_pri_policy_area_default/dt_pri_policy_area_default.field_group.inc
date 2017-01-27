<?php
/**
 * @file
 * dt_pri_policy_area_default.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_pri_policy_area_default_field_group_info() {
  $field_groups = array();

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
    'weight' => '28',
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
  $field_groups['group_pri_pol_area_background|node|priority_policy_area|form'] = $field_group;

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
    'weight' => '7',
    'children' => array(
      0 => 'field_core_background',
      1 => 'field_core_objective',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Background',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'sidebar-field-group__main',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="background"',
        'modifier' => '',
        'layout' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_pri_pol_area_background|node|priority_policy_area|full'] = $field_group;

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
  $field_groups['group_pri_pol_area_banner|node|priority_policy_area|form'] = $field_group;

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
      5 => 'field_core_legacy_link',
      6 => 'field_core_social_network_links',
      7 => 'field_core_parent',
      8 => 'field_core_link',
      9 => 'field_core_keywords',
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
  $field_groups['group_pri_pol_area_content|node|priority_policy_area|form'] = $field_group;

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
      0 => 'field_core_departments',
      1 => 'field_core_parent',
      2 => 'field_core_persons',
      3 => 'field_core_policy_areas',
      4 => 'field_core_topics',
    ),
    'format_type' => 'context_nav',
    'format_settings' => array(
      'label' => 'Contextual navigation',
      'instance_settings' => array(
        'modifier' => '',
      ),
    ),
  );
  $field_groups['group_pri_pol_area_contextual|node|priority_policy_area|full'] = $field_group;

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
    'weight' => '8',
    'children' => array(
      0 => 'field_core_publications',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Documents',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'sidebar-field-group__main',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="documents"',
        'modifier' => '',
        'layout' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_pri_pol_area_documents|node|priority_policy_area|full'] = $field_group;

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
  $field_groups['group_pri_pol_area_editorial|node|priority_policy_area|form'] = $field_group;

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
  $field_groups['group_pri_pol_area_featured_item|node|priority_policy_area|form'] = $field_group;

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
  $field_groups['group_pri_pol_area_meta|node|priority_policy_area|full'] = $field_group;

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
    'weight' => '19',
    'children' => array(
      0 => 'content_type_label',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_pri_pol_area_meta|node|priority_policy_area|teaser'] = $field_group;

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
  $field_groups['group_pri_pol_area_policy|node|priority_policy_area|form'] = $field_group;

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
      0 => 'field_core_departments',
      1 => 'field_core_persons',
      2 => 'field_core_policy_areas',
      3 => 'field_core_topics',
      4 => 'field_core_links',
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
  $field_groups['group_pri_pol_area_related|node|priority_policy_area|form'] = $field_group;

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
    'weight' => '10',
    'children' => array(
      0 => 'field_core_links',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Related links',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'sidebar-field-group__main',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="related-links"',
        'modifier' => '',
        'layout' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_pri_pol_area_related|node|priority_policy_area|full'] = $field_group;

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
    'weight' => '1',
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
  $field_groups['group_pri_pol_area_tabgroup|node|priority_policy_area|form'] = $field_group;

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
    'weight' => '9',
    'children' => array(
      0 => 'field_core_next_steps',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'What\'s next?',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'sidebar-field-group__main',
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
  $field_groups['group_pri_pol_area_whatnext|node|priority_policy_area|full'] = $field_group;

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
    'label' => 'Actions',
    'weight' => '5',
    'children' => array(
      0 => 'field_core_child_policies',
      1 => 'field_core_section_intro',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Actions',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="policy-areas"',
        'modifier' => '',
        'layout' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_pri_pol_policy_areas|node|priority_policy_area|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Actions');
  t('Background');
  t('Banner');
  t('Content');
  t('Contextual navigation');
  t('Documents');
  t('Editorial settings');
  t('Featured content');
  t('Meta');
  t('Policy');
  t('Related');
  t('Related links');
  t('What\'s next?');

  return $field_groups;
}
