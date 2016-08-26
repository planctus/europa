<?php

/**
 * @file
 * dt_person.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function dt_person_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-person-body'.
  $field_instances['node-person-body'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'event_speaker' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 40,
      ),
      'meta' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Biography introduction',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => -7,
            ),
            'filtered_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
          ),
        ),
      ),
      'display_summary' => 0,
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_label_summary' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_summary' => '',
        'maxlength_js_truncate_html' => 0,
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 86,
    ),
  );

  // Exported field_instance: 'node-person-field_core_contact'.
  $field_instances['node-person-field_core_contact'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add contact details of the person. If you want to add additional contact details (for example for the press contact), use an additional contact reference, with a title override \'press contact\'.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'event_speaker' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 0,
          'nexteuropa_listing_columns' => 'row_two',
          'nexteuropa_listing_item_modifier' => '',
          'nexteuropa_listing_modifier' => '',
          'nexteuropa_listing_wrapper_modifier' => '',
          'show_translations' => '',
          'use_content_language' => 1,
          'view_mode' => 'teaser',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 5,
      ),
      'meta' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_core_contact',
    'label' => 'Contact group',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-person-field_core_departments'.
  $field_instances['node-person-field_core_departments'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'To which department does the person belong?',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'event_speaker' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'nexteuropa_formatters',
        'settings' => array(
          'contextual_date' => '',
          'expander_has_expander' => 0,
          'expander_trim_at' => 0,
          'expander_trim_to' => 0,
        ),
        'type' => 'context_nav_item',
        'weight' => 5,
      ),
      'meta' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_core_departments',
    'label' => 'Department',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 74,
    ),
  );

  // Exported field_instance: 'node-person-field_core_file'.
  $field_instances['node-person-field_core_file'] = array(
    'bundle' => 'person',
    'deleted' => 0,
    'description' => 'The full CV in PDF format.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
      'event_speaker' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 42,
      ),
      'meta' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_core_file',
    'label' => 'CV upload',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'entity_translation_sync' => 0,
      'file_directory' => '',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'avportal' => 0,
          'dailymotion' => 0,
          'node' => 0,
          'private' => 0,
          'public' => 'public',
          'vimeo' => 0,
          'youtube' => 0,
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 'document',
          'image' => 0,
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'media_internet' => 0,
          'upload' => 'upload',
        ),
      ),
      'type' => 'media_generic',
      'weight' => 89,
    ),
  );

  // Exported field_instance: 'node-person-field_core_legacy_link'.
  $field_instances['node-person-field_core_legacy_link'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please use an absolute URL! For example: http://example.com or https://example.com<br/>In case this page is a placeholder and should lead to a legacy page, use this field to define the legacy page\'s URL.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'event_speaker' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'meta' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_core_legacy_link',
    'label' => 'Legacy link',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 0,
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 75,
    ),
  );

  // Exported field_instance: 'node-person-field_core_links'.
  $field_instances['node-person-field_core_links'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add links to details on the agenda or agenda items. For example "Meetings with organisations and self-employed individuals" (which links to transparency site).',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
      'event_speaker' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'nexteuropa_formatters',
        'settings' => array(
          'nexteuropa_title_item_link_modifier' => '',
          'nexteuropa_title_item_modifier' => '',
          'nexteuropa_title_listing_modifier' => '',
        ),
        'type' => 'link_listing_title',
        'weight' => 37,
      ),
      'meta' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_core_links',
    'label' => 'Links',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 84,
    ),
  );

  // Exported field_instance: 'node-person-field_core_next_steps'.
  $field_instances['node-person-field_core_next_steps'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'event_speaker' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'dt_policy_next_step',
        'settings' => array(
          'date_formatter' => '',
          'modifier' => '',
          'show_timezone' => 1,
          'timeline_expander_disable' => 0,
        ),
        'type' => 'dt_policy_next_step_formatter_default',
        'weight' => 41,
      ),
      'meta' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_core_next_steps',
    'label' => 'Biography',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'dt_policy_next_step',
      'settings' => array(
        'value' => array(
          'rows' => 5,
          'size' => 5,
          'timeline_type' => 'timeline',
          'timezone' => 0,
        ),
      ),
      'type' => 'dt_policy_next_step_widget',
      'weight' => 88,
    ),
  );

  // Exported field_instance: 'node-person-field_eurovoc_taxonomy'.
  $field_instances['node-person-field_eurovoc_taxonomy'] = array(
    'bundle' => 'person',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'event_speaker' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
      'meta' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_eurovoc_taxonomy',
    'label' => 'Taxonomy',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference_view_widget',
      'settings' => array(
        'allow_duplicates' => 0,
        'close_modal' => 1,
        'pass_argument' => 0,
        'pass_arguments' => '',
        'rendered_entity' => 0,
        'view' => 'eurovoc_taxonomy_browser|entityreference_view_widget_1',
        'view_mode' => 'full',
      ),
      'type' => 'entityreference_view_widget',
      'weight' => 76,
    ),
  );

  // Exported field_instance: 'node-person-field_person_agenda_introduction'.
  $field_instances['node-person-field_person_agenda_introduction'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If possible, use the standard text for Commissioners and Directors-General.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'event_speaker' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 36,
      ),
      'meta' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_person_agenda_introduction',
    'label' => 'Agenda introduction',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => -7,
            ),
            'filtered_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 82,
    ),
  );

  // Exported field_instance: 'node-person-field_person_first_name'.
  $field_instances['node-person-field_person_first_name'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'event_speaker' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'meta' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
      'name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_person_first_name',
    'label' => 'First Name',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => 5,
            ),
            'filtered_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 67,
    ),
  );

  // Exported field_instance: 'node-person-field_person_gender'.
  $field_instances['node-person-field_person_gender'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'event_speaker' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
      'meta' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_person_gender',
    'label' => 'Gender',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 69,
    ),
  );

  // Exported field_instance: 'node-person-field_person_last_name'.
  $field_instances['node-person-field_person_last_name'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'event_speaker' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'meta' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
      'name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_person_last_name',
    'label' => 'Last Name',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => 5,
            ),
            'filtered_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 68,
    ),
  );

  // Exported field_instance: 'node-person-field_person_photo'.
  $field_instances['node-person-field_person_photo'] = array(
    'bundle' => 'person',
    'deleted' => 0,
    'description' => 'Will be shown as a square. 160px by 160px or 60 by 60px',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'event_speaker' => array(
        'label' => 'hidden',
        'module' => 'picture',
        'settings' => array(
          'colorbox_settings' => array(
            'colorbox_caption' => 'auto',
            'colorbox_caption_custom' => '',
            'colorbox_gallery' => 'post',
            'colorbox_gallery_custom' => '',
            'colorbox_group' => '',
            'colorbox_multivalue_index' => NULL,
          ),
          'fallback_image_style' => '',
          'image_link' => '',
          'picture_mapping' => 'person_meta',
        ),
        'type' => 'picture',
        'weight' => 3,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'picture',
        'settings' => array(
          'colorbox_settings' => array(
            'colorbox_caption' => 'auto',
            'colorbox_caption_custom' => '',
            'colorbox_gallery' => 'post',
            'colorbox_gallery_custom' => '',
            'colorbox_group' => '',
            'colorbox_multivalue_index' => NULL,
          ),
          'fallback_image_style' => '',
          'image_link' => '',
          'picture_mapping' => 'person_full',
        ),
        'type' => 'picture',
        'weight' => 3,
      ),
      'meta' => array(
        'label' => 'hidden',
        'module' => 'picture',
        'settings' => array(
          'colorbox_settings' => array(
            'colorbox_caption' => 'auto',
            'colorbox_caption_custom' => '',
            'colorbox_gallery' => 'post',
            'colorbox_gallery_custom' => '',
            'colorbox_group' => '',
            'colorbox_multivalue_index' => NULL,
          ),
          'fallback_image_style' => '',
          'image_link' => '',
          'picture_mapping' => 'person_meta',
        ),
        'type' => 'picture',
        'weight' => 3,
      ),
      'name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_person_photo',
    'label' => 'Portrait photo',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => 'myfiles',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'avportal' => 0,
          'dailymotion' => 0,
          'node' => 0,
          'private' => 'private',
          'public' => 'public',
          'vimeo' => 0,
          'youtube' => 0,
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 'media_default--media_browser_1',
          'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
          'media_internet' => 0,
          'upload' => 'upload',
        ),
      ),
      'type' => 'media_generic',
      'weight' => 70,
    ),
  );

  // Exported field_instance: 'node-person-field_person_role'.
  $field_instances['node-person-field_person_role'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Depends on team membership. E.g \'president\'; \'vice-president\'; \'commissioner\'',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'event_speaker' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_plain',
        'weight' => 35,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_plain',
        'weight' => 27,
      ),
      'meta' => array(
        'label' => 'hidden',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_plain',
        'weight' => 16,
      ),
      'name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_person_role',
    'label' => 'Role',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 72,
    ),
  );

  // Exported field_instance: 'node-person-field_person_role_title'.
  $field_instances['node-person-field_person_role_title'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'event_speaker' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 3,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 28,
      ),
      'meta' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_person_role_title',
    'label' => 'Role/Title',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => -7,
            ),
            'filtered_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 150,
      ),
      'type' => 'text_textfield',
      'weight' => 71,
    ),
  );

  // Exported field_instance: 'node-person-field_person_tagline'.
  $field_instances['node-person-field_person_tagline'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Only shown on the person\'s profile page, below the page title.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'event_speaker' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 34,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'meta' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_person_tagline',
    'label' => 'Tagline',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => 5,
            ),
            'filtered_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 73,
    ),
  );

  // Exported field_instance: 'node-person-field_type_of_person'.
  $field_instances['node-person-field_type_of_person'] = array(
    'bundle' => 'person',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'event_speaker' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
      'meta' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_type_of_person',
    'label' => 'What type of person are you adding',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_buttons',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-person-group_content_access'.
  $field_instances['node-person-group_content_access'] = array(
    'bundle' => 'person',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'event_speaker' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
      'meta' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'group_content_access',
    'label' => 'Group content visibility',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'view modes' => array(
      'full' => array(
        'label' => 'above',
        'type' => 'list_default',
      ),
      'teaser' => array(
        'label' => 'above',
        'type' => 'list_default',
      ),
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 7,
    ),
    'widget_type' => 'options_select',
  );

  // Exported field_instance: 'node-person-og_group_ref'.
  $field_instances['node-person-og_group_ref'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'event_speaker' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'meta' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'og_group_ref',
    'label' => 'Groups audience',
    'required' => FALSE,
    'settings' => array(
      'behaviors' => array(
        'og_widget' => array(
          'admin' => array(
            'widget_type' => 'entityreference_autocomplete',
          ),
          'default' => array(
            'widget_type' => 'options_select',
          ),
          'status' => TRUE,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'view modes' => array(
      'full' => array(
        'custom settings' => FALSE,
        'label' => 'Full',
        'type' => 'og_list_default',
      ),
      'teaser' => array(
        'custom settings' => FALSE,
        'label' => 'Teaser',
        'type' => 'og_list_default',
      ),
    ),
    'widget' => array(
      'module' => 'og',
      'settings' => array(),
      'type' => 'og_complex',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-person-title_field'.
  $field_instances['node-person-title_field'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Leave blank for general cases. Automatically taking values from Role+First name+Last name on first save. Could be changed at any time later.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'event_speaker' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'meta' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'title_field',
    'label' => 'Title',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'dt_editor' => 0,
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => -6,
            ),
            'dt_editor' => array(
              'weight' => -10,
            ),
            'filtered_html' => array(
              'weight' => -8,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'plain_text' => array(
              'weight' => -7,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'hide_label' => array(
        'entity' => 0,
        'page' => 'page',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-person_roles-field_user_role_feminine'.
  $field_instances['taxonomy_term-person_roles-field_user_role_feminine'] = array(
    'bundle' => 'person_roles',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_user_role_feminine',
    'label' => 'Feminine version',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'dt_editor' => 'dt_editor',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => -6,
            ),
            'dt_editor' => array(
              'weight' => -10,
            ),
            'filtered_html' => array(
              'weight' => -8,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'plain_text' => array(
              'weight' => -7,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-person_roles-field_user_role_plural'.
  $field_instances['taxonomy_term-person_roles-field_user_role_plural'] = array(
    'bundle' => 'person_roles',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_user_role_plural',
    'label' => 'Plural form',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'dt_editor' => 'dt_editor',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => -6,
            ),
            'dt_editor' => array(
              'weight' => -10,
            ),
            'filtered_html' => array(
              'weight' => -8,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'plain_text' => array(
              'weight' => -7,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add contact details of the person. If you want to add additional contact details (for example for the press contact), use an additional contact reference, with a title override \'press contact\'.');
  t('Add links to details on the agenda or agenda items. For example "Meetings with organisations and self-employed individuals" (which links to transparency site).');
  t('Agenda introduction');
  t('Biography');
  t('Biography introduction');
  t('CV upload');
  t('Contact group');
  t('Department');
  t('Depends on team membership. E.g \'president\'; \'vice-president\'; \'commissioner\'');
  t('Feminine version');
  t('First Name');
  t('Gender');
  t('Group content visibility');
  t('Groups audience');
  t('If possible, use the standard text for Commissioners and Directors-General.');
  t('Last Name');
  t('Leave blank for general cases. Automatically taking values from Role+First name+Last name on first save. Could be changed at any time later.');
  t('Legacy link');
  t('Links');
  t('Only shown on the person\'s profile page, below the page title.');
  t('Please use an absolute URL! For example: http://example.com or https://example.com<br/>In case this page is a placeholder and should lead to a legacy page, use this field to define the legacy page\'s URL.');
  t('Plural form');
  t('Portrait photo');
  t('Role');
  t('Role/Title');
  t('Tagline');
  t('Taxonomy');
  t('The full CV in PDF format.');
  t('Title');
  t('To which department does the person belong?');
  t('What type of person are you adding');
  t('Will be shown as a square. 160px by 160px or 60 by 60px');

  return $field_instances;
}
