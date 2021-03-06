<?php
/**
 * @file
 * dt_policy.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_policy_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_tabgroup|node|policy|form';
  $field_group->group_name = 'group_content_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '1',
    'children' => array(
      0 => 'group_policy_banner',
      1 => 'group_policy_common',
      2 => 'group_policy_details',
      3 => 'group_policy_editorial',
      4 => 'group_policy_implementation',
      5 => 'group_policy_input',
      6 => 'group_policy_keyfiles',
      7 => 'group_policy_next_steps',
      8 => 'group_policy_other_relations',
      9 => 'group_policy_related',
      10 => 'group_taxonomy',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-content-tabgroup field-group-tabs',
      ),
    ),
  );
  $field_groups['group_content_tabgroup|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policies_wrapper|node|policy|full';
  $field_group->group_name = 'group_policies_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_policy_tab_actions';
  $field_group->data = array(
    'label' => 'Policies wrapper',
    'weight' => '42',
    'children' => array(
      0 => 'field_policy_next_steps',
      1 => 'policy_actions',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Policies wrapper',
      'instance_settings' => array(
        'classes' => 'sidebar-field-group__main',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_policies_wrapper|node|policy|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_banner|node|policy|form';
  $field_group->group_name = 'group_policy_banner';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Banner',
    'weight' => '4',
    'children' => array(
      0 => 'field_policy_author',
      1 => 'field_policy_caption',
      2 => 'field_policy_featured_file',
      3 => 'field_policy_paragraph',
      4 => 'field_policy_quote',
      5 => 'field_policy_sharable_banner',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-banner field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_policy_banner|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_common|node|policy|form';
  $field_group->group_name = 'group_policy_common';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Common',
    'weight' => '1',
    'children' => array(
      0 => 'title_field',
      1 => 'field_core_description',
      2 => 'field_core_introduction',
      3 => 'field_core_legacy_link',
      4 => 'field_core_parent',
      5 => 'field_core_keywords',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-common field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_policy_common|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_contextual|node|policy|full';
  $field_group->group_name = 'group_policy_contextual';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contextual navigation',
    'weight' => '3',
    'children' => array(
      0 => 'field_core_department',
      1 => 'field_core_topics',
      2 => 'field_core_persons',
      3 => 'field_core_priorities',
    ),
    'format_type' => 'context_nav',
    'format_settings' => array(
      'label' => 'Contextual navigation',
      'instance_settings' => array(
        'modifier' => '',
      ),
    ),
  );
  $field_groups['group_policy_contextual|node|policy|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_details|node|policy|form';
  $field_group->group_name = 'group_policy_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '8',
    'children' => array(
      0 => 'field_policy_detail_body',
      1 => 'field_policy_detail_file',
      2 => 'field_policy_detail_objectives',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-details field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_policy_details|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_documents|node|policy|full';
  $field_group->group_name = 'group_policy_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_policy_tab_details';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '34',
    'children' => array(
      0 => 'field_policy_keyfiles',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Documents',
      'instance_settings' => array(
        'classes' => '',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h3',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_policy_documents|node|policy|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_editorial|node|policy|form';
  $field_group->group_name = 'group_policy_editorial';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '11',
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
        'classes' => 'group-policy-editorial field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_policy_editorial|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_implementation|node|policy|form';
  $field_group->group_name = 'group_policy_implementation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Implementation',
    'weight' => '5',
    'children' => array(
      0 => 'field_policy_implementations',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-implementation field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_policy_implementation|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_input|node|policy|form';
  $field_group->group_name = 'group_policy_input';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Policy input',
    'weight' => '6',
    'children' => array(
      0 => 'field_policy_input',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-input field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_policy_input|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_keyfiles|node|policy|form';
  $field_group->group_name = 'group_policy_keyfiles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Key files',
    'weight' => '9',
    'children' => array(
      0 => 'field_policy_keyfiles',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-keyfiles field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_policy_keyfiles|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_meta|node|policy|full';
  $field_group->group_name = 'group_policy_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
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
  $field_groups['group_policy_meta|node|policy|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_next_steps|node|policy|form';
  $field_group->group_name = 'group_policy_next_steps';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Next steps',
    'weight' => '7',
    'children' => array(
      0 => 'field_policy_next_steps',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-next-steps field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_policy_next_steps|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_other_relations|node|policy|form';
  $field_group->group_name = 'group_policy_other_relations';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Other relations',
    'weight' => '3',
    'children' => array(
      0 => 'field_core_department',
      1 => 'field_core_persons',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-other-relations field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_policy_other_relations|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_related|node|policy|form';
  $field_group->group_name = 'group_policy_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Relations with other content types',
    'weight' => '2',
    'children' => array(
      0 => 'field_core_policy_areas',
      1 => 'field_core_priorities',
      2 => 'field_core_topics',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-related field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_policy_related|node|policy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_socialmedia|node|policy|full';
  $field_group->group_name = 'group_policy_socialmedia';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Social Media',
    'weight' => '5',
    'children' => array(
      0 => 'social_bookmark_webtools',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Social Media',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_policy_socialmedia|node|policy|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_tab_actions|node|policy|full';
  $field_group->group_name = 'group_policy_tab_actions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_policy_tabs';
  $field_group->data = array(
    'label' => 'Actions',
    'weight' => '5',
    'children' => array(
      0 => 'group_policies_wrapper',
    ),
    'format_type' => 'bootstrap_fieldgroup_nav_item',
    'format_settings' => array(
      'label' => 'Actions',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
        'required_fields' => 1,
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'attributes' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_policy_tab_actions|node|policy|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_tab_details|node|policy|full';
  $field_group->group_name = 'group_policy_tab_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_policy_tabs';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '7',
    'children' => array(
      0 => 'field_policy_detail_body',
      1 => 'field_policy_detail_objectives',
      2 => 'group_policy_documents',
    ),
    'format_type' => 'bootstrap_fieldgroup_nav_item',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
        'required_fields' => 1,
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'attributes' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_policy_tab_details|node|policy|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_tab_latest|node|policy|full';
  $field_group->group_name = 'group_policy_tab_latest';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_policy_tabs';
  $field_group->data = array(
    'label' => 'Latest',
    'weight' => '6',
    'children' => array(
      0 => 'announcement_block',
    ),
    'format_type' => 'bootstrap_fieldgroup_nav_item',
    'format_settings' => array(
      'label' => 'Latest',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_policy_tab_latest|node|policy|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_tabs|node|policy|full';
  $field_group->group_name = 'group_policy_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Horizontal tabs',
    'weight' => '4',
    'children' => array(
      0 => 'group_policy_tab_actions',
      1 => 'group_policy_tab_details',
      2 => 'group_policy_tab_latest',
    ),
    'format_type' => 'bootstrap_fieldgroup_nav',
    'format_settings' => array(
      'label' => 'Horizontal tabs',
      'instance_settings' => array(
        'classes' => 'section__group',
        'bootstrap_nav_type' => 'tabs',
        'bootstrap_stacked' => 0,
        'bootstrap_orientation' => 0,
        'required_fields' => 1,
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'attributes' => '',
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_policy_tabs|node|policy|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy|node|policy|form';
  $field_group->group_name = 'group_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Taxonomy',
    'weight' => '10',
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
  $field_groups['group_taxonomy|node|policy|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Actions');
  t('Banner');
  t('Common');
  t('Content');
  t('Contextual navigation');
  t('Details');
  t('Documents');
  t('Editorial settings');
  t('Horizontal tabs');
  t('Implementation');
  t('Key files');
  t('Latest');
  t('Meta');
  t('Next steps');
  t('Other relations');
  t('Policies wrapper');
  t('Policy input');
  t('Relations with other content types');
  t('Social Media');
  t('Taxonomy');

  return $field_groups;
}
