<?php

/**
 * @file
 * dt_tender_default.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function dt_tender_default_field_default_field_instances() {
  $field_instances = [];

  // Exported field_instance: 'node-tender-body'.
  $field_instances['node-tender-body'] = [
    'bundle' => 'tender',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => [
      'default' => [
        'label' => 'above',
        'module' => 'text',
        'settings' => [],
        'type' => 'text_default',
        'weight' => 6,
      ],
      'full' => [
        'label' => 'hidden',
        'module' => 'text',
        'settings' => [],
        'type' => 'text_default',
        'weight' => 6,
      ],
      'teaser' => [
        'label' => 'above',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 0,
      ],
    ],
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Background',
    'required' => 0,
    'settings' => [
      'better_formats' => [
        'allowed_formats' => [
          'basic_html' => 'basic_html',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ],
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => [
          'formats' => [
            'basic_html' => [
              'weight' => -7,
            ],
            'filtered_html' => [
              'weight' => -9,
            ],
            'full_html' => [
              'weight' => -10,
            ],
            'plain_text' => [
              'weight' => -8,
            ],
          ],
        ],
      ],
      'display_summary' => 0,
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ],
    'widget' => [
      'active' => 1,
      'module' => 'text',
      'settings' => [
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_label_summary' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_summary' => '',
        'maxlength_js_truncate_html' => 0,
        'rows' => 20,
        'summary_rows' => 5,
      ],
      'type' => 'text_textarea_with_summary',
      'weight' => -1,
    ],
  ];

  // Exported field_instance: 'node-tender-field_core_departments'.
  $field_instances['node-tender-field_core_departments'] = [
    'bundle' => 'tender',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => [
      'default' => [
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => [
          'link' => FALSE,
        ],
        'type' => 'entityreference_label',
        'weight' => 7,
      ],
      'full' => [
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => [
          'links' => 1,
          'nexteuropa_listing_columns' => 'default',
          'nexteuropa_listing_item_modifier' => '',
          'nexteuropa_listing_modifier' => '',
          'nexteuropa_listing_wrapper_modifier' => '',
          'show_translations' => '',
          'use_content_language' => 1,
          'view_mode' => 'meta',
        ],
        'type' => 'entityreference_entity_view',
        'weight' => 7,
      ],
      'teaser' => [
        'label' => 'above',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 0,
      ],
    ],
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_core_departments',
    'label' => 'Related departments',
    'required' => 0,
    'settings' => [
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ],
    'widget' => [
      'active' => 1,
      'module' => 'entityreference',
      'settings' => [
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ],
      'type' => 'entityreference_autocomplete',
      'weight' => 0,
    ],
  ];

  // Exported field_instance: 'node-tender-field_core_description'.
  $field_instances['node-tender-field_core_description'] = [
    'bundle' => 'tender',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Used for when the item is appearing in a list on another page.',
    'display' => [
      'default' => [
        'label' => 'above',
        'module' => 'text',
        'settings' => [],
        'type' => 'text_default',
        'weight' => 4,
      ],
      'full' => [
        'label' => 'above',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 27,
      ],
      'teaser' => [
        'label' => 'hidden',
        'module' => 'text',
        'settings' => [],
        'type' => 'text_default',
        'weight' => 2,
      ],
    ],
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_core_description',
    'label' => 'Description',
    'required' => 0,
    'settings' => [
      'better_formats' => [
        'allowed_formats' => [
          'basic_html' => 'basic_html',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ],
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => [
          'formats' => [
            'basic_html' => [
              'weight' => 5,
            ],
            'filtered_html' => [
              'weight' => -9,
            ],
            'full_html' => [
              'weight' => -10,
            ],
            'plain_text' => [
              'weight' => -8,
            ],
          ],
        ],
      ],
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ],
    'widget' => [
      'active' => 1,
      'module' => 'text',
      'settings' => [
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ],
      'type' => 'text_textarea',
      'weight' => -4,
    ],
  ];

  // Exported field_instance: 'node-tender-field_core_files'.
  $field_instances['node-tender-field_core_files'] = array(
    'bundle' => 'tender',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 12,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_core_files',
    'label' => 'Files',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-tender-field_core_introduction'.
  $field_instances['node-tender-field_core_introduction'] = [
    'bundle' => 'tender',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The general introduction for the item, please only use one paragraph.',
    'display' => [
      'default' => [
        'label' => 'above',
        'module' => 'text',
        'settings' => [],
        'type' => 'text_default',
        'weight' => 1,
      ],
      'full' => [
        'label' => 'hidden',
        'module' => 'text',
        'settings' => [],
        'type' => 'text_default',
        'weight' => 4,
      ],
      'teaser' => [
        'label' => 'hidden',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 17,
      ],
    ],
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_core_introduction',
    'info_value' => NULL,
    'label' => 'Introduction',
    'required' => 0,
    'settings' => [
      'better_formats' => [
        'allowed_formats' => [
          'basic_html' => 'basic_html',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ],
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => [
          'formats' => [
            'basic_html' => [
              'weight' => 5,
            ],
            'filtered_html' => [
              'weight' => -9,
            ],
            'full_html' => [
              'weight' => -10,
            ],
            'plain_text' => [
              'weight' => -8,
            ],
          ],
        ],
      ],
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ],
    'widget' => [
      'active' => 1,
      'module' => 'text',
      'settings' => [
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ],
      'type' => 'text_textarea',
      'weight' => -3,
    ],
  ];

  // Exported field_instance: 'node-tender-field_core_legacy_link'.
  $field_instances['node-tender-field_core_legacy_link'] = [
    'bundle' => 'tender',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Fill in if you want the item to link to an external place, instead of internal to the Drupal detail page',
    'display' => [
      'default' => [
        'label' => 'above',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 5,
      ],
      'full' => [
        'label' => 'above',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 32,
      ],
      'teaser' => [
        'label' => 'above',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 18,
      ],
    ],
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_core_legacy_link',
    'label' => 'Legacy link',
    'required' => 0,
    'settings' => [
      'absolute_url' => 0,
      'attributes' => [
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ],
      'display' => [
        'url_cutoff' => 80,
      ],
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ],
    'widget' => [
      'active' => 0,
      'module' => 'link',
      'settings' => [],
      'type' => 'link_field',
      'weight' => -2,
    ],
  ];

  // Exported field_instance: 'node-tender-field_core_topics'.
  $field_instances['node-tender-field_core_topics'] = [
    'bundle' => 'tender',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => [
      'default' => [
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => [
          'link' => FALSE,
        ],
        'type' => 'entityreference_label',
        'weight' => 8,
      ],
      'full' => [
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => [
          'links' => 1,
          'nexteuropa_listing_columns' => 'default',
          'nexteuropa_listing_item_modifier' => '',
          'nexteuropa_listing_modifier' => '',
          'nexteuropa_listing_wrapper_modifier' => '',
          'show_translations' => '',
          'use_content_language' => 1,
          'view_mode' => 'title',
        ],
        'type' => 'entityreference_entity_view',
        'weight' => 8,
      ],
      'teaser' => [
        'label' => 'above',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 0,
      ],
    ],
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_core_topics',
    'label' => 'Related Topics',
    'required' => 0,
    'settings' => [
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ],
    'widget' => [
      'active' => 1,
      'module' => 'entityreference',
      'settings' => [
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ],
      'type' => 'entityreference_autocomplete',
      'weight' => 1,
    ],
  ];

  // Exported field_instance: 'node-tender-field_eurovoc_taxonomy'.
  $field_instances['node-tender-field_eurovoc_taxonomy'] = [
    'bundle' => 'tender',
    'deleted' => 0,
    'description' => '',
    'display' => [
      'default' => [
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => [
          'link' => FALSE,
        ],
        'type' => 'entityreference_label',
        'weight' => 6,
      ],
      'teaser' => [
        'label' => 'above',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 0,
      ],
    ],
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_eurovoc_taxonomy',
    'label' => 'Taxonomy',
    'required' => 0,
    'settings' => [
      'behaviors' => [
        'taxonomy-index' => [
          'status' => TRUE,
        ],
      ],
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ],
    'widget' => [
      'active' => 1,
      'module' => 'entityreference_view_widget',
      'settings' => [
        'allow_duplicates' => 0,
        'close_modal' => 1,
        'pass_argument' => 0,
        'pass_arguments' => '',
        'rendered_entity' => 0,
        'view' => 'eurovoc_taxonomy_browser|entityreference_view_widget_1',
        'view_mode' => 'full',
      ],
      'type' => 'entityreference_view_widget',
      'weight' => 42,
    ],
  ];

  // Exported field_instance: 'node-tender-field_tender_contract_notice'.
  $field_instances['node-tender-field_tender_contract_notice'] = [
    'bundle' => 'tender',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => [
      'default' => [
        'label' => 'above',
        'module' => 'text',
        'settings' => [],
        'type' => 'text_default',
        'weight' => 11,
      ],
      'full' => [
        'label' => 'above',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 29,
      ],
      'teaser' => [
        'label' => 'above',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 0,
      ],
    ],
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_tender_contract_notice',
    'label' => 'Contract notice',
    'required' => 0,
    'settings' => [
      'better_formats' => [
        'allowed_formats' => [
          'basic_html' => 'basic_html',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ],
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => [
          'formats' => [
            'basic_html' => [
              'weight' => -7,
            ],
            'filtered_html' => [
              'weight' => -9,
            ],
            'full_html' => [
              'weight' => -10,
            ],
            'plain_text' => [
              'weight' => -8,
            ],
          ],
        ],
      ],
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ],
    'widget' => [
      'active' => 1,
      'module' => 'text',
      'settings' => [
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ],
      'type' => 'text_textfield',
      'weight' => 4,
    ],
  ];

  // Exported field_instance: 'node-tender-field_tender_deadline'.
  $field_instances['node-tender-field_tender_deadline'] = [
    'bundle' => 'tender',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => [
      'default' => [
        'label' => 'above',
        'module' => 'text',
        'settings' => [],
        'type' => 'text_default',
        'weight' => 10,
      ],
      'full' => [
        'label' => 'above',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 28,
      ],
      'teaser' => [
        'label' => 'above',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 0,
      ],
    ],
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_tender_deadline',
    'label' => 'Deadline',
    'required' => 0,
    'settings' => [
      'better_formats' => [
        'allowed_formats' => [
          'basic_html' => 'basic_html',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ],
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => [
          'formats' => [
            'basic_html' => [
              'weight' => -7,
            ],
            'filtered_html' => [
              'weight' => -9,
            ],
            'full_html' => [
              'weight' => -10,
            ],
            'plain_text' => [
              'weight' => -8,
            ],
          ],
        ],
      ],
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ],
    'widget' => [
      'active' => 1,
      'module' => 'text',
      'settings' => [
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ],
      'type' => 'text_textfield',
      'weight' => 3,
    ],
  ];

  // Exported field_instance: 'node-tender-field_tender_status'.
  $field_instances['node-tender-field_tender_status'] = [
    'bundle' => 'tender',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => [
      'default' => [
        'label' => 'above',
        'module' => 'list',
        'settings' => [],
        'type' => 'list_default',
        'weight' => 9,
      ],
      'full' => [
        'label' => 'hidden',
        'module' => 'i18n_field',
        'settings' => [],
        'type' => 'i18n_list_default',
        'weight' => 2,
      ],
      'teaser' => [
        'label' => 'above',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 0,
      ],
    ],
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_tender_status',
    'label' => 'Status',
    'required' => 0,
    'settings' => [
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ],
    'widget' => [
      'active' => 1,
      'module' => 'options',
      'settings' => [
        'apply_chosen' => '',
      ],
      'type' => 'options_select',
      'weight' => 2,
    ],
  ];

  // Exported field_instance: 'node-tender-group_content_access'.
  $field_instances['node-tender-group_content_access'] = [
    'bundle' => 'tender',
    'default_value' => [
      0 => [
        'value' => 0,
      ],
    ],
    'deleted' => 0,
    'description' => '',
    'display' => [
      'default' => [
        'label' => 'hidden',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 3,
      ],
      'full' => [
        'label' => 'hidden',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 31,
      ],
      'teaser' => [
        'label' => 'above',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 19,
      ],
    ],
    'entity_type' => 'node',
    'field_name' => 'group_content_access',
    'label' => 'Group content visibility',
    'required' => TRUE,
    'settings' => [
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ],
    'view modes' => [
      'full' => [
        'label' => 'above',
        'type' => 'list_info',
      ],
      'teaser' => [
        'label' => 'above',
        'type' => 'list_info',
      ],
    ],
    'widget' => [
      'module' => 'options',
      'settings' => [
        'apply_chosen' => '',
      ],
      'type' => 'options_select',
      'weight' => 10,
    ],
    'widget_type' => 'options_select',
  ];

  // Exported field_instance: 'node-tender-og_group_ref'.
  $field_instances['node-tender-og_group_ref'] = [
    'bundle' => 'tender',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => [
      'default' => [
        'label' => 'hidden',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 5,
      ],
      'full' => [
        'label' => 'hidden',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 33,
      ],
      'teaser' => [
        'label' => 'above',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 20,
      ],
    ],
    'entity_type' => 'node',
    'field_name' => 'og_group_ref',
    'info_value' => NULL,
    'label' => 'Groups audience',
    'required' => FALSE,
    'settings' => [
      'behaviors' => [
        'og_widget' => [
          'admin' => [
            'widget_type' => 'entityreference_autocomplete',
          ],
          'default' => [
            'widget_type' => 'options_select',
          ],
          'status' => TRUE,
        ],
      ],
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ],
    'view modes' => [
      'full' => [
        'custom settings' => FALSE,
        'label' => 'Full',
        'type' => 'og_list_default',
      ],
      'teaser' => [
        'custom settings' => FALSE,
        'label' => 'Teaser',
        'type' => 'og_list_default',
      ],
    ],
    'widget' => [
      'module' => 'og',
      'settings' => [],
      'type' => 'og_complex',
      'weight' => 9,
    ],
  ];

  // Exported field_instance: 'node-tender-title_field'.
  $field_instances['node-tender-title_field'] = [
    'bundle' => 'tender',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => [
      'default' => [
        'label' => 'above',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 2,
      ],
      'full' => [
        'label' => 'above',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 30,
      ],
      'teaser' => [
        'label' => 'hidden',
        'module' => 'nexteuropa_formatters',
        'settings' => [],
        'type' => 'listing_title',
        'weight' => 1,
      ],
    ],
    'entity_type' => 'node',
    'field_name' => 'title_field',
    'label' => 'Title',
    'required' => TRUE,
    'settings' => [
      'entity_translation_sync' => FALSE,
      'hide_label' => [
        'entity' => FALSE,
        'page' => FALSE,
      ],
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ],
    'widget' => [
      'module' => 'text',
      'settings' => [
        'size' => 60,
      ],
      'type' => 'text_textfield',
      'weight' => -5,
    ],
  ];

  // Translatables
  // Included for use with string extractors like potx.
  t('Background');
  t('Contract notice');
  t('Deadline');
  t('Description');
  t('Fill in if you want the item to link to an external place, instead of internal to the Drupal detail page');
  t('Group content visibility');
  t('Groups audience');
  t('Introduction');
  t('Legacy link');
  t('Taxonomy');
  t('Related Topics');
  t('Related departments');
  t('Status');
  t('The general introduction for the item, please only use one paragraph.');
  t('Title');
  t('Used for when the item is appearing in a list on another page.');

  return $field_instances;
}
