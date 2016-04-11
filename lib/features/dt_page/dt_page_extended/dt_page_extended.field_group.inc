<?php
/**
 * @file
 * dt_page_extended.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_page_extended_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background|node|basic_page|form';
  $field_group->group_name = 'group_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'basic_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '16',
    'children' => array(
      0 => 'body',
      1 => 'field_core_publications',
      2 => 'field_core_next_steps',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_background|node|basic_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_banner|node|basic_page|form';
  $field_group->group_name = 'group_banner';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'basic_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Banner',
    'weight' => '13',
    'children' => array(
      0 => 'field_core_banner',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-banner field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_banner|node|basic_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_tabgroup|node|basic_page|form';
  $field_group->group_name = 'group_content_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'basic_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '1',
    'children' => array(
      0 => 'group_background',
      1 => 'group_banner',
      2 => 'group_editorial_settings',
      3 => 'group_featured_item',
      5 => 'group_page_main',
      6 => 'group_related',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-content-tabgroup field-group-tabs',
      ),
    ),
  );
  $field_groups['group_content_tabgroup|node|basic_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_settings|node|basic_page|form';
  $field_group->group_name = 'group_editorial_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'basic_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '17',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'group_content_access',
      2 => 'field_core_in_page_navigation',
      3 => 'field_core_latest_visibility',
      4 => 'scheduler_settings',
      5 => 'language',
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
  $field_groups['group_editorial_settings|node|basic_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_featured_item|node|basic_page|form';
  $field_group->group_name = 'group_featured_item';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'basic_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Featured item',
    'weight' => '14',
    'children' => array(
      0 => 'field_core_featured_item',
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
  $field_groups['group_featured_item|node|basic_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_contextual_navigation|node|basic_page|full';
  $field_group->group_name = 'group_page_contextual_navigation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'basic_page';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contextual navigation',
    'weight' => '2',
    'children' => array(
      0 => 'field_core_departments',
      1 => 'field_core_persons',
      2 => 'field_core_policy_area',
      3 => 'field_core_priorities',
      4 => 'field_core_topics',
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
  $field_groups['group_page_contextual_navigation|node|basic_page|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_documents|node|basic_page|full';
  $field_group->group_name = 'group_page_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'basic_page';
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
        'classes' => 'section__group',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="documents"',
      ),
    ),
  );
  $field_groups['group_page_documents|node|basic_page|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_free_field|node|basic_page|full';
  $field_group->group_name = 'group_page_free_field';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'basic_page';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Free field',
    'weight' => '6',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Free field',
      'instance_settings' => array(
        'classes' => 'section__group',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_page_free_field|node|basic_page|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_main|node|basic_page|form';
  $field_group->group_name = 'group_page_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'basic_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '11',
    'children' => array(
      0 => 'title_field',
      1 => 'field_core_description',
      2 => 'field_core_header_image',
      3 => 'field_core_image',
      4 => 'field_core_introduction',
      5 => 'field_core_legacy_link',
      6 => 'field_core_parent',
      7 => 'field_core_social_network_links',
      8 => 'field_core_link',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-page-main field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_page_main|node|basic_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_meta|node|basic_page|teaser';
  $field_group->group_name = 'group_page_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'basic_page';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '16',
    'children' => array(
      0 => 'content_type_label',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(
        'modifier' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_page_meta|node|basic_page|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_next_steps|node|basic_page|full';
  $field_group->group_name = 'group_page_next_steps';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'basic_page';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'What\'s next?',
    'weight' => '8',
    'children' => array(
      0 => 'field_core_next_steps',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'What\'s next?',
      'instance_settings' => array(
        'classes' => 'section__group',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="nextsteps"',
      ),
    ),
  );
  $field_groups['group_page_next_steps|node|basic_page|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_priorities|node|basic_page|full';
  $field_group->group_name = 'group_page_priorities';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'basic_page';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '10 priorities',
    'weight' => '5',
    'children' => array(
      0 => 'priorities_preprocess',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => '10 priorities',
      'instance_settings' => array(
        'classes' => 'section__group',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_page_priorities|node|basic_page|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_related_links|node|basic_page|full';
  $field_group->group_name = 'group_page_related_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'basic_page';
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
        'classes' => 'section__group',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="relatedlinks"',
      ),
    ),
  );
  $field_groups['group_page_related_links|node|basic_page|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related|node|basic_page|form';
  $field_group->group_name = 'group_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'basic_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Related',
    'weight' => '12',
    'children' => array(
      0 => 'field_core_departments',
      1 => 'field_core_persons',
      2 => 'field_core_policy_area',
      3 => 'field_core_priorities',
      4 => 'field_core_topics',
      5 => 'field_core_links',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-related field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_related|node|basic_page|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('10 priorities');
  t('Background');
  t('Banner');
  t('Content');
  t('Contextual navigation');
  t('Documents');
  t('Editorial settings');
  t('Featured item');
  t('Free field');
  t('Latest');
  t('Meta');
  t('Related');
  t('Related links');
  t('What\'s next?');

  return $field_groups;
}