<?php
/**
 * @file
 * dt_publication.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_publication_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_tabgroup|node|publication|form';
  $field_group->group_name = 'group_content_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '1',
    'children' => array(
      0 => 'group_editorial_settings',
      1 => 'group_publication_contact',
      2 => 'group_publication_content',
      3 => 'group_publication_related',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-content-tabgroup field-group-tabs',
      ),
    ),
  );
  $export['group_content_tabgroup|node|publication|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_settings|node|publication|form';
  $field_group->group_name = 'group_editorial_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '25',
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
  $export['group_editorial_settings|node|publication|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publication_body|node|publication|full';
  $field_group->group_name = 'group_publication_body';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Body',
    'weight' => '5',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Body',
      'instance_settings' => array(
        'classes' => 'section__group',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_publication_body|node|publication|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publication_contact|node|publication|form';
  $field_group->group_name = 'group_publication_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Abstract & contact',
    'weight' => '22',
    'children' => array(
      0 => 'body',
      1 => 'field_core_contact',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Abstract & contact',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-publication-contact field-group-tab',
        'description' => '',
      ),
    ),
  );
  $export['group_publication_contact|node|publication|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publication_contact|node|publication|full';
  $field_group->group_name = 'group_publication_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '8',
    'children' => array(),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'classes' => 'section__group',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
      ),
    ),
  );
  $export['group_publication_contact|node|publication|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publication_content|node|publication|form';
  $field_group->group_name = 'group_publication_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '20',
    'children' => array(
      0 => 'title_field',
      1 => 'field_publication_authors',
      2 => 'field_publication_origin',
      3 => 'field_publication_referenceno',
      4 => 'field_publication_type',
      5 => 'field_core_description',
      6 => 'field_core_legacy_link',
      7 => 'field_core_date_updated',
      8 => 'field_core_publications',
      9 => 'field_core_files',
      10 => 'field_core_date_published',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-publication-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_publication_content|node|publication|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publication_contextual|node|publication|full';
  $field_group->group_name = 'group_publication_contextual';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contextual navigation',
    'weight' => '4',
    'children' => array(
      0 => 'field_core_topics',
      1 => 'field_publication_authors',
      2 => 'field_publication_referenceno',
      3 => 'field_core_date_published',
      4 => 'field_core_publications',
    ),
    'format_type' => 'context_nav',
    'format_settings' => array(
      'label' => 'Contextual navigation',
      'instance_settings' => array(
        'modifier' => '',
      ),
    ),
  );
  $export['group_publication_contextual|node|publication|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publication_file|node|publication|full';
  $field_group->group_name = 'group_publication_file';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Files',
    'weight' => '6',
    'children' => array(
      0 => 'field_core_files',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Files',
      'instance_settings' => array(
        'classes' => 'section__group',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
      ),
    ),
  );
  $export['group_publication_file|node|publication|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publication_meta|node|publication|full';
  $field_group->group_name = 'group_publication_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_publication_type',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(
        'modifier' => 'meta--header',
      ),
    ),
  );
  $export['group_publication_meta|node|publication|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publication_meta|node|publication|teaser';
  $field_group->group_name = 'group_publication_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_publication_type',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(),
    ),
  );
  $export['group_publication_meta|node|publication|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publication_related|node|publication|form';
  $field_group->group_name = 'group_publication_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '23',
    'children' => array(
      0 => 'field_core_departments',
      1 => 'field_core_topics',
      2 => 'field_publication_rel_content',
      3 => 'field_core_policies',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Related content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_publication_related|node|publication|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publication_related|node|publication|full';
  $field_group->group_name = 'group_publication_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related information',
    'weight' => '7',
    'children' => array(
      0 => 'field_core_departments',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Related information',
      'instance_settings' => array(
        'classes' => 'section__group',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
      ),
    ),
  );
  $export['group_publication_related|node|publication|full'] = $field_group;

  return $export;
}
