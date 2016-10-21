<?php

/**
 * @file
 * Dt call for proposal ds fields.
 *
 * This file contains all custom ds fields and related functions.
 */

/**
 * Implements hook_ds_fields_info().
 */
function dt_call_for_proposal_default_ds_fields_info($entity_type) {
  $fields = [];

  // The actual DS definition.
  if ($entity_type == 'node') {

    $fields[$entity_type]['dt_call_for_proposal_status_message'] = [
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'ui_limit' => ['call_for_proposal|*'],
      'title' => t('Dt call for proposal: Status message'),
      'function' => '_dt_call_for_proposal_ds_fields_status_message',
      'use_token' => TRUE,
      'properties' => [
        'formatters' => [
          // For the top message.
          'dt_call_for_proposal_status_message_formatter' => t('Message formatting'),
        ],
      ],
    ];

    $fields[$entity_type]['dt_call_for_proposal_published'] = [
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'ui_limit' => ['call_for_proposal|full'],
      'title' => t('Dt call for proposal: published (journal)'),
      'function' => '_dt_call_for_proposal_ds_fields_published',
      'use_token' => TRUE,
    ];

    $fields[$entity_type]['dt_call_for_proposal_meta'] = [
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'ui_limit' => ['call_for_proposal|full'],
      'title' => t('Dt call for proposal: Meta item'),
      'function' => '_dt_call_for_proposal_ds_fields_meta_item',
      'use_token' => FALSE,
    ];

    $fields[$entity_type]['dt_call_for_proposal_deadline'] = [
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'ui_limit' => ['call_for_proposal|teaser'],
      'title' => t('Dt call for proposal: Deadline (teaser)'),
      'function' => '_dt_call_for_proposal_ds_fields_deadline',
      'use_token' => FALSE,
    ];

    return [$entity_type => $fields[$entity_type]];
  }
}

/**
 * Helper function to show the status message.
 *
 * @param array $field
 *   Holds the current context of the field.
 *
 * @return string
 *   The status message markup.
 */
function _dt_call_for_proposal_ds_fields_status_message($field) {
  // Default config.
  $render_config = [
    '#theme' => 'europa_status_message',
    '#message_classes' => ['messages', 'messages--icon-center'],
  ];

  $emw = entity_metadata_wrapper('node', $field['entity']);

  if (!$emw->__isset('field_cfp_status')) {
    return NULL;
  }

  switch ($emw->field_cfp_status->value()) {

    case 'open':
      $render_config['#message_title'] = t('This call is open.');
      $render_config['#message_body'] = t('You can send in your proposal before the closing date.');
      break;

    case 'upcoming':
      if ($emw->__isset('field_core_date_opening')) {
        $date_opening = $emw->field_core_date_opening->value();

        if (!empty($date_opening)) {
          $open_date = format_date($date_opening, 'ec_date_j_f_y');
          $render_config['#message_body'] = t('The call will be opened on') . ' ' . $open_date;
        }

        $render_config['#message_title'] = t('This call is upcoming.');
      }
      else {
        $render_config['#message_title'] = t('This call is upcoming.');
        $render_config['#message_body'] = t('The call will be opened soon.');
      }
      break;

    case 'closed':
      if ($emw->__isset('field_core_deadlines') && $emw->__isset('field_grants_awarded_link')) {
        $date_closing = $emw->field_core_deadlines->value();
        $render_config['#message_body'] = '';

        if (!empty($date_closing)) {
          $close_date = format_date($date_closing, 'ec_date_j_f_y');
          $render_config['#message_body'] = t('This call was closed on !close_date', ['!close_date' => $close_date . '. ']);
        }

        $grants_awarded = $emw->field_grants_awarded_link->value();

        $render_config['#message_title'] = t('This call is closed.');
        $render_config['#message_body'] .= t('Consult the results of this call in the !grants_awarded.', [
          '!grants_awarded' => l($grants_awarded['title'], $grants_awarded['url']),
        ]);
      }
      else {
        $render_config['#message_title'] = t('This call is closed.');
      }

      break;

    default:
      return NULL;
  }

  $render_config['#message_classes'] = implode(" ", $render_config['#message_classes']);

  return !empty($render_config['#message_title']) ? drupal_render($render_config) : NULL;
}

/**
 * Helper function to show the first part of the cfp meta.
 *
 * @param array $field
 *   Holds the current context of the field.
 *
 * @return string
 *   The meta markup.
 */
function _dt_call_for_proposal_ds_fields_meta_item($field) {
  $meta = [
    '#markup' => t('funding'),
    '#prefix' => '<span class="meta__item meta__item--type">',
    '#suffix' => '</span>',
  ];

  return drupal_render($meta);
}

/**
 * Helper function to build the "publication date".
 *
 * It is a field build combining two fields, a date field and a link field.
 * We basically show them one after the other.
 *
 * @param array $field
 *   Holds the current context of the field.
 *
 * @return string
 *   The field markup.
 */
function _dt_call_for_proposal_ds_fields_published($field) {
  $emw = entity_metadata_wrapper('node', $field['entity']);
  $open_date = format_date($emw->field_core_date_published->value(), 'ec_date_j_f_y');
  $journal = $emw->__isset('field_cfp_publication') && $emw->field_cfp_publication->value()['url'] ? l($emw->field_cfp_publication->value()['title'], $emw->field_cfp_publication->value()['url']) : '';

  if (!empty($journal)) {
    $in = t('in');
    $output = $open_date . ' ' . $in . ' ' . $journal;
  }
  else {
    $output = $open_date;
  }

  return $output;
}

/**
 * Helper function to build the "deadline" field display in teaser view mode.
 *
 * The logic behind this is that there is a controller field defining three
 * different deadline "models", in the teaser view mode of cfp only when this
 * field is set to single_stage then we show the date (the last value in a multi
 * ple values field), otherwise we show the deadline model.
 *
 * @param array $field
 *   Holds the current context of the field.
 *
 * @return string
 *   The field markup.
 */
function _dt_call_for_proposal_ds_fields_deadline($field) {
  $emw = entity_metadata_wrapper('node', $field['entity']);
  // Value for the "controller" field.
  $model = $emw->field_cfp_deadline_model->value();
  // Values for the date field.
  $deadlines = $emw->field_core_deadlines->value();
  $output = '';

  switch ($model) {
    case 'single_stage':
      // In case the field contains multiple values we use the last one.
      $deadlines = is_array($deadlines) ? end($deadlines) : $deadlines;
      $deadline = format_date($deadlines, 'ec_date_j_f_y');
      // We show the date in this case.
      $output = $deadline;
      break;

    case 'two_stage':
    case 'multiple_stage':
      // We show the "value" of the deadline model field in those cases.
      $output = $emw->field_cfp_deadline_model->label();
      break;
  }

  return $output;
}
