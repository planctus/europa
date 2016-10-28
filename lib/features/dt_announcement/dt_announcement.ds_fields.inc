<?php

/**
 * @file
 * Ds fields defined for dt announcement.
 *
 * This file contains all custom ds fields and related functions.
 */

/**
 * Implements hook_ds_fields_info().
 */
function dt_announcement_ds_fields_info($entity_type) {
  $fields = [];

  if ($entity_type == 'node') {
    $fields[$entity_type]['announcement_block'] = [
      'title' => t('Full announcement section'),
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'function' => '_dt_announcement_ds_fields_announcement_block',
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
          'label' => [
            'type' => 'textfield',
            'description' => t('The label to display above the component'),
          ],
        ],
        'default' => [
          'show_featured_item' => TRUE,
          'show_social_media' => TRUE,
          'label' => 'Latest',
        ],
      ],
    ];

    $fields[$entity_type]['announcement_author_in_meta'] = [
      'title' => t('Announcement: Author (Responsible Department)'),
      'ui_limit' => ['announcement|*'],
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'function' => '_nexteuropa_ds_fields_token_replace',
      'properties' => [
        'value' => '[node:field-announcement-department:title]',
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
function dt_announcement_ds_field_settings_form($field) {
  return ds_ds_field_settings_form($field);
}

/**
 * Implements hook_ds_field_format_summary().
 */
function dt_announcement_ds_field_format_summary($field) {
  return ds_ds_field_format_summary($field);
}

/**
 * Custom function to display the full announcements block.
 *
 * @param array $field
 *   Array containing field related information.
 *
 * @return mixed
 *   NULL - when not necessary to display the block.
 *   string - as a rendered html.
 */
function _dt_announcement_ds_fields_announcement_block($field) {
  // Lets call the entity by its name.
  $node = $field['entity'];

  // A department content type rebels to global settings: DTTSB-1003.
  $is_latest_visible = variable_get('dt_shared_functions_dt_latest_visibility', TRUE);
  // Some content types can opt in to show block even if global setting is off.
  // This is done through a checkbox: 'field_core_latest_visibility'.
  $opt_in_content_type = field_info_instance('node', 'field_core_latest_visibility', $node->type);
  $opt_in_content_type_default = !$opt_in_content_type ? FALSE : $opt_in_content_type['default_value'][0]['value'];
  // Per node checkbox to control visibility on $opt_in_content_type(s).
  // If field is not filled in yet, fall back to the field's default value.
  $opt_in_node = (isset($field['entity']->field_core_latest_visibility[LANGUAGE_NONE][0]['value']) && $field['entity']->field_core_latest_visibility[LANGUAGE_NONE][0]['value'] == 1) ? TRUE : $opt_in_content_type_default;
  if (
    (!$opt_in_content_type && !$is_latest_visible) ||
    ($opt_in_content_type && !empty($node->field_department_news_link)) ||
    !$opt_in_node
  ) {
    // Global setting to hide the latest block.
    return NULL;
  }

  // Default settings.
  $show_featured = isset($field['formatter_settings']['show_featured_item']) ? $field['formatter_settings']['show_featured_item'] : FALSE;
  $show_social_media = isset($field['formatter_settings']['show_social_media']) ? $field['formatter_settings']['show_social_media'] : FALSE;

  // Set our announcements view.
  $news_items = views_embed_view('announcements', 'latest_block');

  // Get the social media to render.
  if ($show_social_media) {
    // Load social media links.
    $social_media_options = [
      'label' => 'hidden',
      'type' => 'social_network_link_theme_css',
      'module' => 'dt_social_network_links',
    ];
    $social_media = field_view_field('node', $node, 'field_core_social_network_links', $social_media_options);
  }

  // Get the featured item to render.
  if ($show_featured && isset($node->field_core_featured_item) && isset($node->field_core_featured_item[LANGUAGE_NONE])) {
    foreach ($node->field_core_featured_item[LANGUAGE_NONE] as $item) {
      if ($featured_item = node_load($item['target_id'])) {
        $featured_item_view = entity_view('node', array($item['target_id'] => $featured_item), 'teaser', _dt_shared_functions_content_language($node));
      }
    }
  }

  // Get the actual content language.
  $label_language = _dt_shared_functions_content_language($node);

  // @codingStandardsIgnoreStart
  $heading = isset($field['formatter_settings']['label'])
    ? t($field['formatter_settings']['label'], [], ['langcode' => $label_language])
    : NULL;
  // @codingStandardsIgnoreEnd

  // Our own render array.
  $render_config = [
    '#theme' => 'dt_announcement_announcement_block',
    '#heading' => $heading,
    '#heading_id' => drupal_clean_css_identifier(drupal_strtolower($heading)),
    '#news_items' => isset($news_items) ? $news_items : NULL,
    '#social_links' => isset($social_media) && is_array($social_media) ? drupal_render($social_media) : NULL,
    '#featued_item' => isset($featured_item_view) ? drupal_render($featured_item_view) : NULL,
  ];

  return drupal_render($render_config);
}
