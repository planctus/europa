<?php
/**
 * @file
 * cwt_team.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cwt_team_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_activities|node|team|form';
  $field_group->group_name = 'group_team_activities';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Activities',
    'weight' => '2',
    'children' => array(
      0 => 'field_team_activities_info',
      1 => 'field_team_agenda',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-team-activities field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_team_activities|node|team|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_comissioners|node|team|default';
  $field_group->group_name = 'group_team_comissioners';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Commissioners',
    'weight' => '8',
    'children' => array(
      0 => 'group_team_tabs',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Commissioners',
      'instance_settings' => array(
        'modifier' => '',
        'layout' => 'col-md-8',
        'classes' => '',
      ),
    ),
  );
  $export['group_team_comissioners|node|team|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_content|node|team|form';
  $field_group->group_name = 'group_team_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_illustrative_image',
      2 => 'field_team_links',
      3 => 'field_team_tagline',
      4 => 'field_team_term',
      5 => 'title',
      6 => 'field_team_attachments',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-team-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_team_content|node|team|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_disable|node|team|default';
  $field_group->group_name = 'group_team_disable';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Disable group',
    'weight' => '21',
    'children' => array(
      0 => 'subscriptions_ui',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-team-disable field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_team_disable|node|team|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_files|node|team|default';
  $field_group->group_name = 'group_team_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Files',
    'weight' => '9',
    'children' => array(
      0 => 'field_team_attachments',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Files',
      'instance_settings' => array(
        'modifier' => 'col-md-8',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_team_files|node|team|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_links|node|team|default';
  $field_group->group_name = 'group_team_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '5',
    'children' => array(
      0 => 'field_team_links',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Links',
      'instance_settings' => array(
        'modifier' => '',
        'layout' => 'col-md-9',
        'classes' => '',
      ),
    ),
  );
  $export['group_team_links|node|team|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_members|node|team|default';
  $field_group->group_name = 'group_team_members';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Members',
    'weight' => '7',
    'children' => array(
      0 => 'group_team_president',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Members',
      'instance_settings' => array(
        'modifier' => '',
        'layout' => 'col-md-8',
        'classes' => '',
      ),
    ),
  );
  $export['group_team_members|node|team|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_members|node|team|form';
  $field_group->group_name = 'group_team_members';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Members',
    'weight' => '1',
    'children' => array(),
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
  $export['group_team_members|node|team|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_metadata|node|team|form';
  $field_group->group_name = 'group_team_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '6',
    'children' => array(
      0 => 'field_editorial_section',
      1 => 'field_team_status',
      2 => 'field_team_subtype',
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
  $export['group_team_metadata|node|team|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_meta|node|team|default';
  $field_group->group_name = 'group_team_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'team_meta',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(
        'modifier' => 'meta--header',
        'classes' => '',
      ),
    ),
  );
  $export['group_team_meta|node|team|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_president|node|team|default';
  $field_group->group_name = 'group_team_president';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_team_members';
  $field_group->data = array(
    'label' => 'President',
    'weight' => '13',
    'children' => array(
      0 => 'cwt_team_president',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'President',
      'instance_settings' => array(
        'classes' => '',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h3',
        'attributes' => '',
      ),
    ),
  );
  $export['group_team_president|node|team|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_priorities|node|team|form';
  $field_group->group_name = 'group_team_priorities';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Priorities',
    'weight' => '5',
    'children' => array(
      0 => 'field_team_priorities',
      1 => 'field_team_priorities_info',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-team-priorities field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_team_priorities|node|team|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_role|node|team|default';
  $field_group->group_name = 'group_team_role';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Role',
    'weight' => '4',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Role',
      'instance_settings' => array(
        'modifier' => '',
        'layout' => 'col-md-9',
        'classes' => '',
      ),
    ),
  );
  $export['group_team_role|node|team|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_tab_name|node|team|default';
  $field_group->group_name = 'group_team_tab_name';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_team_tabs';
  $field_group->data = array(
    'label' => 'Name',
    'weight' => '7',
    'children' => array(
      0 => 'cwt_team_name',
    ),
    'format_type' => 'bootstrap_fieldgroup_nav_item',
    'format_settings' => array(
      'label' => 'Name',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_team_tab_name|node|team|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_tab_project_team|node|team|default';
  $field_group->group_name = 'group_team_tab_project_team';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_team_tabs';
  $field_group->data = array(
    'label' => 'Project team',
    'weight' => '6',
    'children' => array(
      0 => 'cwt_team_project_team',
    ),
    'format_type' => 'bootstrap_fieldgroup_nav_item',
    'format_settings' => array(
      'label' => 'Project team',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_team_tab_project_team|node|team|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_tab_role|node|team|default';
  $field_group->group_name = 'group_team_tab_role';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_team_tabs';
  $field_group->data = array(
    'label' => 'Role',
    'weight' => '5',
    'children' => array(
      0 => 'cwt_team_role',
    ),
    'format_type' => 'bootstrap_fieldgroup_nav_item',
    'format_settings' => array(
      'label' => 'Role',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_team_tab_role|node|team|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_tabs|node|team|default';
  $field_group->group_name = 'group_team_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_team_comissioners';
  $field_group->data = array(
    'label' => 'Horizontal tabs',
    'weight' => '6',
    'children' => array(
      0 => 'group_team_tab_name',
      1 => 'group_team_tab_project_team',
      2 => 'group_team_tab_role',
    ),
    'format_type' => 'bootstrap_fieldgroup_nav',
    'format_settings' => array(
      'label' => 'Horizontal tabs',
      'instance_settings' => array(
        'bootstrap_nav_type' => 'tabs',
        'bootstrap_stacked' => '0',
        'bootstrap_orientation' => '0',
        'classes' => '',
      ),
    ),
  );
  $export['group_team_tabs|node|team|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_top_image|node|team|default';
  $field_group->group_name = 'group_team_top_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Top image',
    'weight' => '3',
    'children' => array(
      0 => 'field_illustrative_image',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Top image',
      'instance_settings' => array(
        'classes' => 'top-image',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_team_top_image|node|team|default'] = $field_group;

  return $export;
}
