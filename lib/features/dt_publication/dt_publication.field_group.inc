<?php
/**
 * @file
 * dt_publication.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_publication_field_group_info() {
  $field_groups = array();

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
      4 => 'group_taxonomy',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-content-tabgroup field-group-tabs',
      ),
    ),
  );
  $field_groups['group_content_tabgroup|node|publication|form'] = $field_group;

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
    'weight' => '24',
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
  $field_groups['group_editorial_settings|node|publication|form'] = $field_group;

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
    'weight' => '4',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Body',
      'instance_settings' => array(
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_publication_body|node|publication|full'] = $field_group;

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
    'weight' => '21',
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
  $field_groups['group_publication_contact|node|publication|form'] = $field_group;

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
    'weight' => '7',
    'children' => array(
      0 => 'field_core_contact',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'paragraph',
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
  $field_groups['group_publication_contact|node|publication|full'] = $field_group;

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
      1 => 'field_publication_type',
      2 => 'field_core_files',
      3 => 'field_core_description',
      4 => 'field_core_legacy_link',
      5 => 'field_publication_authors',
      6 => 'field_publication_origin',
      7 => 'field_publication_referenceno',
      8 => 'field_core_date_published',
      9 => 'field_core_date_updated',
      10 => 'field_core_publications',
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
  $field_groups['group_publication_content|node|publication|form'] = $field_group;

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
    'weight' => '3',
    'children' => array(
      0 => 'field_core_topics',
      1 => 'field_publication_authors',
      2 => 'field_publication_referenceno',
      3 => 'field_core_date_published',
      4 => 'field_core_tags',
      5 => 'field_core_nal_countries',
      6 => 'publication_collections',
    ),
    'format_type' => 'context_nav',
    'format_settings' => array(
      'label' => 'Contextual navigation',
      'instance_settings' => array(
        'modifier' => '',
      ),
    ),
  );
  $field_groups['group_publication_contextual|node|publication|full'] = $field_group;

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
    'weight' => '5',
    'children' => array(
      0 => 'field_core_files',
      1 => 'collection_documents',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Files',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_publication_file|node|publication|full'] = $field_group;

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
      1 => 'collection_label',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(
        'modifier' => 'meta--header',
      ),
    ),
  );
  $field_groups['group_publication_meta|node|publication|full'] = $field_group;

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
      1 => 'field_core_date_published',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_publication_meta|node|publication|teaser'] = $field_group;

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
    'weight' => '22',
    'children' => array(
      0 => 'field_core_topics',
      1 => 'field_core_departments',
      2 => 'field_core_policies',
      3 => 'field_publication_rel_content',
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
  $field_groups['group_publication_related|node|publication|form'] = $field_group;

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
    'weight' => '6',
    'children' => array(
      0 => 'field_core_departments',
      1 => 'field_core_policies',
      2 => 'field_publication_rel_content',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Related information',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
        'classes' => 'paragraph',
      ),
    ),
  );
  $field_groups['group_publication_related|node|publication|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy|node|publication|form';
  $field_group->group_name = 'group_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Taxonomy',
    'weight' => '23',
    'children' => array(
      0 => 'field_eurovoc_taxonomy',
      1 => 'field_core_tags',
      2 => 'field_core_nal_countries',
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
  $field_groups['group_taxonomy|node|publication|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Abstract & contact');
  t('Body');
  t('Contact');
  t('Content');
  t('Contextual navigation');
  t('Editorial settings');
  t('Files');
  t('Meta');
  t('Related content');
  t('Related information');
  t('Taxonomy');

  return $field_groups;
}
