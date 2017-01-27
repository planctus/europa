<?php
/**
 * @file
 * dt_info_homepage.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_info_homepage_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_tabgroup|node|info_homepage|form';
  $field_group->group_name = 'group_content_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_content',
      1 => 'group_editorial_settings',
      2 => 'group_info_homepage_info',
      3 => 'group_info_homepage_political',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-content-tabgroup field-group-tabs',
      ),
    ),
  );
  $field_groups['group_content_tabgroup|node|info_homepage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|info_homepage|form';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '11',
    'children' => array(
      0 => 'title_field',
      1 => 'field_core_header_image',
      2 => 'field_core_introduction',
      3 => 'field_info_highlights',
      4 => 'field_core_keywords',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_content|node|info_homepage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_settings|node|info_homepage|form';
  $field_group->group_name = 'group_editorial_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '14',
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
        'classes' => 'group-editorial-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_editorial_settings|node|info_homepage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info_highlights|node|info_homepage|full';
  $field_group->group_name = 'group_info_highlights';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Featured',
    'weight' => '3',
    'children' => array(
      0 => 'field_info_highlights',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Featured',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="featured"',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_info_highlights|node|info_homepage|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info_highlights|node|info_homepage|homepage_informational';
  $field_group->group_name = 'group_info_highlights';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'homepage_informational';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Featured',
    'weight' => '3',
    'children' => array(
      0 => 'field_info_highlights',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Featured',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="featured"',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_info_highlights|node|info_homepage|homepage_informational'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info_highlights|node|info_homepage|homepage_political';
  $field_group->group_name = 'group_info_highlights';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'homepage_political';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Featured',
    'weight' => '7',
    'children' => array(
      0 => 'field_info_highlights',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Featured',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="featured"',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_info_highlights|node|info_homepage|homepage_political'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info_homepage_about|node|info_homepage|homepage_political';
  $field_group->group_name = 'group_info_homepage_about';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'homepage_political';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'About the European Commission',
    'weight' => '3',
    'children' => array(
      0 => 'field_core_links',
      1 => 'field_info_homepage_about_button',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'About the European Commission',
      'instance_settings' => array(
        'classes' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_info_homepage_about|node|info_homepage|homepage_political'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info_homepage_commissionrs|node|info_homepage|homepage_political';
  $field_group->group_name = 'group_info_homepage_commissionrs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'homepage_political';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Commissioners',
    'weight' => '2',
    'children' => array(
      0 => 'field_info_homepage_hero_links',
      1 => 'field_info_homepage_hero_linktxt',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Commissioners',
      'instance_settings' => array(
        'classes' => 'field-group-section_group hero-links',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_info_homepage_commissionrs|node|info_homepage|homepage_political'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info_homepage_contacts|node|info_homepage|homepage_political';
  $field_group->group_name = 'group_info_homepage_contacts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'homepage_political';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '4',
    'children' => array(
      0 => 'field_info_homepage_contacts',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'classes' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="contact"',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_info_homepage_contacts|node|info_homepage|homepage_political'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info_homepage_info|node|info_homepage|form';
  $field_group->group_name = 'group_info_homepage_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Informational site related',
    'weight' => '12',
    'children' => array(
      0 => 'field_info_classes',
      1 => 'field_info_homepage_topic_intro',
      2 => 'field_info_homepage_topic_link',
      3 => 'field_info_secondary_links',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-info-homepage-info field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_info_homepage_info|node|info_homepage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info_homepage_latest|node|info_homepage|homepage_political';
  $field_group->group_name = 'group_info_homepage_latest';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'homepage_political';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Latest',
    'weight' => '5',
    'children' => array(
      0 => 'field_info_homepage_latest_link',
      1 => 'announcement_block',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Latest',
      'instance_settings' => array(
        'classes' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'attributes' => 'id="latest"',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_info_homepage_latest|node|info_homepage|homepage_political'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info_homepage_political|node|info_homepage|form';
  $field_group->group_name = 'group_info_homepage_political';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Political site related',
    'weight' => '13',
    'children' => array(
      0 => 'field_core_links',
      1 => 'field_info_homepage_about_button',
      2 => 'field_info_homepage_contacts',
      3 => 'field_info_homepage_hero_links',
      4 => 'field_info_homepage_prior_link',
      5 => 'field_core_latest_visibility',
      6 => 'field_core_social_network_links',
      7 => 'field_info_homepage_latest_link',
      8 => 'field_info_homepage_hero_linktxt',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-info-homepage-political field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_info_homepage_political|node|info_homepage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info_homepage_section_bot|node|info_homepage|full';
  $field_group->group_name = 'group_info_homepage_section_bot';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Section bottom',
    'weight' => '2',
    'children' => array(
      0 => 'field_info_secondary_links',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Section bottom',
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
  $field_groups['group_info_homepage_section_bot|node|info_homepage|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info_homepage_section_bot|node|info_homepage|homepage_informational';
  $field_group->group_name = 'group_info_homepage_section_bot';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'homepage_informational';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Section bottom',
    'weight' => '2',
    'children' => array(
      0 => 'field_info_secondary_links',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Section bottom',
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
  $field_groups['group_info_homepage_section_bot|node|info_homepage|homepage_informational'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info_homepage_section_bot|node|info_homepage|homepage_political';
  $field_group->group_name = 'group_info_homepage_section_bot';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'homepage_political';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Section bottom',
    'weight' => '36',
    'children' => array(
      0 => 'field_info_secondary_links',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Section bottom',
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
  $field_groups['group_info_homepage_section_bot|node|info_homepage|homepage_political'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info_homepage_section_top|node|info_homepage|full';
  $field_group->group_name = 'group_info_homepage_section_top';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Section top',
    'weight' => '1',
    'children' => array(
      0 => 'field_info_classes',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Section top',
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
  $field_groups['group_info_homepage_section_top|node|info_homepage|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info_homepage_section_top|node|info_homepage|homepage_informational';
  $field_group->group_name = 'group_info_homepage_section_top';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'homepage_informational';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Section top',
    'weight' => '1',
    'children' => array(
      0 => 'field_info_classes',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Section top',
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
  $field_groups['group_info_homepage_section_top|node|info_homepage|homepage_informational'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info_homepage_section_top|node|info_homepage|homepage_political';
  $field_group->group_name = 'group_info_homepage_section_top';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'homepage_political';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Section top',
    'weight' => '1',
    'children' => array(
      0 => 'field_info_homepage_prior_link',
      1 => 'priorities_listing',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Section top',
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
  $field_groups['group_info_homepage_section_top|node|info_homepage|homepage_political'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_latest_main|node|info_homepage|homepage_informational';
  $field_group->group_name = 'group_latest_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'homepage_informational';
  $field_group->parent_name = 'group_latest';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '22',
    'children' => array(
      0 => 'latest_announcements_block',
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
  $field_groups['group_latest_main|node|info_homepage|homepage_informational'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_latest_sidebar|node|info_homepage|homepage_informational';
  $field_group->group_name = 'group_latest_sidebar';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'homepage_informational';
  $field_group->parent_name = 'group_latest';
  $field_group->data = array(
    'label' => 'Sidebar',
    'weight' => '23',
    'children' => array(),
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
  $field_groups['group_latest_sidebar|node|info_homepage|homepage_informational'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_latest|node|info_homepage|homepage_informational';
  $field_group->group_name = 'group_latest';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'homepage_informational';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Latest',
    'weight' => '22',
    'children' => array(
      0 => 'group_latest_main',
      1 => 'group_latest_sidebar',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Latest',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'sidebar-field-group',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="latest"',
        'modifier' => '',
        'layout' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_latest|node|info_homepage|homepage_informational'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topics|node|info_homepage|full';
  $field_group->group_name = 'group_topics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Topics',
    'weight' => '4',
    'children' => array(
      0 => 'field_info_homepage_topic_intro',
      1 => 'field_info_homepage_topic_link',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Topics',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_topics|node|info_homepage|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topics|node|info_homepage|homepage_informational';
  $field_group->group_name = 'group_topics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'homepage_informational';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Topics',
    'weight' => '4',
    'children' => array(
      0 => 'field_info_homepage_topic_intro',
      1 => 'field_info_homepage_topic_link',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Topics',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_topics|node|info_homepage|homepage_informational'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('About the European Commission');
  t('Commissioners');
  t('Contact');
  t('Content');
  t('Editorial settings');
  t('Featured');
  t('Informational site related');
  t('Latest');
  t('Main');
  t('Political site related');
  t('Section bottom');
  t('Section top');
  t('Sidebar');
  t('Topics');

  return $field_groups;
}
