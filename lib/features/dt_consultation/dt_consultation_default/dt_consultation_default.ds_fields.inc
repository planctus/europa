<?php

/**
 * @file
 * Ds fields defined for dt consultation.
 *
 * This file contains all custom ds fields and related functions.
 */

define('DT_CONSULTATION_DEFAULT_OPEN_STATE', 'open');
define('DT_CONSULTATION_DEFAULT_CLOSE_STATE', 'closed');

/**
 * Implements hook_ds_fields_info().
 */
function dt_consultation_default_ds_fields_info($entity_type) {
  $fields = [];

  if ($entity_type == 'node') {
    $fields[$entity_type]['consultation_period'] = [
      'title' => t('Consultation period'),
      'ui_limit' => ['consultation|*'],
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'function' => '_nexteuropa_ds_fields_token_replace',
      'properties' => [
        'value' => '[node:field-core-date-opening:ec_date_j_f_y] - [node:field-core-date-closing:ec_date_j_f_y]',
      ],
      $fields[$entity_type]['consultation_status_label'] = [
        'title' => t('Consultation status'),
        'field_type' => DS_FIELD_TYPE_FUNCTION,
        'ui_limit' => ['consultation|teaser'],
        'function' => '_dt_consultation_status_label',
      ],
    ];
  }

  if (isset($fields[$entity_type])) {
    return [$entity_type => $fields[$entity_type]];
  }
}

/**
 * Helper to build the label for status field.
 *
 * @param array $field
 *   Array of properties required to render the field.
 *
 * @return string
 *    Rendered content.
 */
function _dt_consultation_status_label($field) {
  if (!isset($field['entity']) || $field['entity']->type !== 'consultation') {
    return FALSE;
  }
  $consultation_wrapper = entity_metadata_wrapper('node', $field['entity']);

  // Start our render config.
  $render_config['#theme'] = 'dt_consultation_default_status_label';

  // Set the correct message and status class.
  $render_config['#status_class'] = '';

  switch ($consultation_wrapper->field_consultation_status->value()) {
    case DT_CONSULTATION_DEFAULT_OPEN_STATE:
      $render_config['#status_text'] = t('Consultation status: Open');
      $render_config['#status_class'] = ' label--highlight';
      break;

    case DT_CONSULTATION_DEFAULT_CLOSE_STATE:
      $render_config['#status_text'] = t('Consultation status: Closed');
      $render_config['#status_class'] = ' label--status';
      break;

  }
  return drupal_render($render_config);
}

/**
 * Implements hook_theme().
 */
function dt_consultation_default_theme() {
  return [
    'dt_consultation_default_status_label' => [
      'template' => 'dt_consultation_default_status_label',
      'path' => drupal_get_path('module', 'dt_consultation_default') . '/templates',
      'variables' => [
        'status_class' => '',
        'status_text' => '',
      ],
    ],
  ];
}
