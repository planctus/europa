<?php

/**
 * @file
 * dt_person.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_person_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_agenda|node|person|full';
  $field_group->group_name = 'group_agenda';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Agenda',
    'weight' => '8',
    'children' => array(
      0 => 'field_core_links',
      1 => 'field_person_agenda_introduction',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Agenda',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="agenda"',
      ),
    ),
  );
  $field_groups['group_agenda|node|person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_articles_presentation|node|person|full';
  $field_group->group_name = 'group_articles_presentation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Articles and presentations',
    'weight' => '9',
    'children' => array(
      0 => 'field_core_files',
      1 => 'field_core_publications',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Articles and presentations',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-articles-presentation field-group-html-element',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="article-presentation"',
      ),
    ),
  );
  $field_groups['group_articles_presentation|node|person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_job_meta|node|person|job';
  $field_group->group_name = 'group_person_job_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'job';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'job_role',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'modifier' => '',
        'classes' => 'group-person-job-meta field-group-meta_wrapper',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_person_job_meta|node|person|job'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_biography|node|person|full';
  $field_group->group_name = 'group_biography';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Biography',
    'weight' => '7',
    'children' => array(
      0 => 'body',
      1 => 'field_core_file',
      2 => 'field_core_next_steps',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Biography',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="biography"',
      ),
    ),
  );
  $field_groups['group_biography|node|person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_context_nav|node|person|full';
  $field_group->group_name = 'group_context_nav';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Context navigation',
    'weight' => '4',
    'children' => array(
      0 => 'field_core_departments',
    ),
    'format_type' => 'context_nav',
    'format_settings' => array(
      'label' => 'Context navigation',
      'instance_settings' => array(
        'classes' => '',
        'modifier' => '',
      ),
    ),
  );
  $field_groups['group_context_nav|node|person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_settings|node|person|form';
  $field_group->group_name = 'group_editorial_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_person_content';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '72',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'group_content_access',
      2 => 'field_core_listing_disable_link',
      3 => 'scheduler_settings',
      4 => 'language',
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
  $field_groups['group_editorial_settings|node|person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta|node|person|full';
  $field_group->group_name = 'group_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_person_role',
      1 => 'field_person_role_title',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(
        'classes' => '',
        'modifier' => 'meta--header',
      ),
    ),
  );
  $field_groups['group_meta|node|person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_agenda|node|person|form';
  $field_group->group_name = 'group_person_agenda';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_person_content';
  $field_group->data = array(
    'label' => 'Agenda',
    'weight' => '70',
    'children' => array(
      0 => 'field_core_links',
      1 => 'field_person_agenda_introduction',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-person-agenda field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_person_agenda|node|person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_biography_cv|node|person|form';
  $field_group->group_name = 'group_person_biography_cv';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_person_content';
  $field_group->data = array(
    'label' => 'Biography and CV',
    'weight' => '68',
    'children' => array(
      0 => 'body',
      1 => 'field_core_next_steps',
      2 => 'field_core_file',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-person-biography-cv field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_person_biography_cv|node|person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_contact|node|person|form';
  $field_group->group_name = 'group_person_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_person_content';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '66',
    'children' => array(
      0 => 'field_core_contact',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-person-contact field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_person_contact|node|person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_content|node|person|form';
  $field_group->group_name = 'group_person_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '1',
    'children' => array(
      0 => 'group_editorial_settings',
      1 => 'group_person_agenda',
      2 => 'group_person_documents',
      3 => 'group_person_biography_cv',
      4 => 'group_person_contact',
      5 => 'group_person_profile',
      6 => 'group_person_technical',
      7 => 'group_taxonomy',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_person_content|node|person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_documents|node|person|form';
  $field_group->group_name = 'group_person_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_person_content';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '69',
    'children' => array(
      0 => 'field_core_publications',
      1 => 'field_core_files',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-person-documents field-group-tab',
        'required_fields' => 0,
      ),
    ),
  );
  $field_groups['group_person_documents|node|person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_meta|node|person|event_speaker';
  $field_group->group_name = 'group_person_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'event_speaker';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_person_role',
      1 => 'field_person_role_title',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'modifier' => '',
        'classes' => 'group-person-meta field-group-meta_wrapper',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_person_meta|node|person|event_speaker'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_meta|node|person|meta';
  $field_group->group_name = 'group_person_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'meta';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_person_role',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_person_meta|node|person|meta'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_name|node|person|event_speaker';
  $field_group->group_name = 'group_person_name';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'event_speaker';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Name',
    'weight' => '1',
    'children' => array(
      0 => 'field_person_tagline',
      1 => 'full_name_nolink',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-person-name field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_person_name|node|person|event_speaker'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_name|node|person|meta';
  $field_group->group_name = 'group_person_name';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'meta';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Name',
    'weight' => '1',
    'children' => array(
      0 => 'full_name_nolink',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Name',
      'instance_settings' => array(
        'classes' => 'listing__title',
        'element' => 'h3',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_person_name|node|person|meta'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_profile|node|person|form';
  $field_group->group_name = 'group_person_profile';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_person_content';
  $field_group->data = array(
    'label' => 'Profile',
    'weight' => '64',
    'children' => array(
      0 => 'field_person_first_name',
      1 => 'field_person_gender',
      2 => 'field_person_last_name',
      3 => 'field_person_photo',
      4 => 'field_person_role',
      5 => 'field_person_tagline',
      6 => 'field_core_legacy_link',
      7 => 'field_core_departments',
      8 => 'field_person_role_title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Profile',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-person-profile field-group-tab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_person_profile|node|person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_technical|node|person|form';
  $field_group->group_name = 'group_person_technical';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_person_content';
  $field_group->data = array(
    'label' => 'Technical fields',
    'weight' => '65',
    'children' => array(
      0 => 'title_field',
      1 => 'field_core_jobs',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-person-technical field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_person_technical|node|person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy|node|person|form';
  $field_group->group_name = 'group_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_person_content';
  $field_group->data = array(
    'label' => 'Taxonomy',
    'weight' => '71',
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
  $field_groups['group_taxonomy|node|person|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Agenda');
  t('Articles and presentations');
  t('Biography');
  t('Biography and CV');
  t('Contact');
  t('Content');
  t('Context navigation');
  t('Documents');
  t('Editorial settings');
  t('Meta');
  t('Name');
  t('Profile');
  t('Taxonomy');
  t('Technical fields');

  return $field_groups;
}
