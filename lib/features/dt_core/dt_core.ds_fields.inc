<?php
/**
 * @file
 * Ds fields defined for dt.
 *
 * This file contains all custom ds fields and related functions.
 */

/**
 * Implements hook_ds_fields_info().
 */
function dt_core_ds_fields_info($entity_type) {
  $fields = [];

  if ($entity_type == 'node') {
    $fields['node']['sticky_label'] = [
      'title' => t('Sticky label'),
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'function' => '_dt_core_ds_fields_stick_label',
    ];

    $fields['node']['announcement_block'] = [
      'title' => t('Announcement block'),
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'function' => '_dt_core_ds_fields_announcement_block',
      'properties' => [
        'settings' => [
          'show_featured_item' => [
            'type' => 'checkbox',
            'description' => t('Display or do not display the featured item'),
          ],
          'show_social_media' => [
            'type' => 'checkbox',
            'description' => t('Display or do not display the social media'),
          ],
        ],
        'default' => [
          'show_featured_item' => TRUE,
          'show_social_media' => TRUE,
        ],
      ],
    ];
  }

  if (isset($fields[$entity_type])) {
    return [$entity_type => $fields[$entity_type]];
  }
}

/**
 * Implements hook_ds_field_settings_form().
 */
function dt_core_ds_field_settings_form($field) {
  return ds_ds_field_settings_form($field);
}

/**
 * Implements hook_ds_field_format_summary().
 */
function dt_core_ds_field_format_summary($field) {
  return ds_ds_field_format_summary($field);
}

/**
 * Custom function for single token replacement in a field.
 *
 * @param array $field
 *   Array containing field related information.
 */
function _dt_core_ds_fields_stick_label($field) {
  if (isset($field['entity']->sticky) && $field['entity']->sticky) {
    return '<span class="label label--highlight label--meta">' . t('Highlight') . '</span>';
  }
}

/**
 * Custom function to display the full announcements block.
 *
 * @param array $field
 *   Array containing field related information.
 */
function _dt_core_ds_fields_announcement_block($field) {
  // Lets call the entity by its name.
  $node = $field['entity'];

  // Set our announcements view..
  $news_items = views_embed_view('announcements', 'latest_block');
  // Load social media links.
  $social_media = field_view_field('node', $node, 'field_core_social_network_links', $field['view_mode']);

  // Our own render array.
  $render_config = [
    '#theme' => 'dt_core_announcement_block',
    '#heading' => isset($field['formatter_settings']['ft']['lb']) ? $field['formatter_settings']['ft']['lb'] : NULL,
    '#news_items' => isset($news_items) ? $news_items : NULL,
    '#social_links' => is_array($social_media) ? drupal_render($social_media) : NULL,
  ];

  return drupal_render($render_config);
}
