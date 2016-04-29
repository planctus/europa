<?php
/**
 * @file
 * Event ds fields.
 *
 * This file contains all custom ds fields and related functions.
 */

/**
 * Implements hook_ds_fields_info().
 */
function dt_event_ds_fields_info($entity_type) {
  $fields = [];

  // As we need to render them twice, we can recreate them here. We set our
  // defaults, and add just the title to define them. If we need to make changes
  // we only have to do it once.
  $book_your_seat_defaults = [
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'ui_limit' => ['event|*'],
    'function' => '_dt_event_ds_fields_book_your_seat',
  ];
  $livestreaming_defaults = [
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'ui_limit' => ['event|*'],
    'function' => '_dt_event_ds_fields_livestreaming',
  ];

  // The actual DS definition.
  if ($entity_type == 'node') {
    // Book your seat.
    $fields[$entity_type]['book_your_seat'] = $book_your_seat_defaults + [
      'title' => t('Event: Book your seat button'),
    ];
    $fields[$entity_type]['book_your_seat_bottom'] = $book_your_seat_defaults + [
      'title' => t('Event: Book your seat button bottom'),
    ];
    // Livestreaming.
    $fields[$entity_type]['livestreaming'] = $livestreaming_defaults + [
      'title' => t('Event: Livestreaming'),
    ];
    $fields[$entity_type]['livestreaming_bottom'] = $livestreaming_defaults + [
      'title' => t('Event: Livestreaming bottom'),
    ];
    $fields[$entity_type]['dt_event_header'] = [
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'ui_limit' => ['event|*'],
      'title' => t('Event: header'),
      'function' => '_dt_event_ds_fields_header_event',
    ];
  }

  if (isset($fields[$entity_type])) {
    return [$entity_type => $fields[$entity_type]];
  }
}

/**
 * Helper function to show the book your seat button.
 *
 * We do not have to check if value's are set as we act on one content type
 * only.
 *
 * @param array $field
 *   Hold the current context of the field.
 */
function _dt_event_ds_fields_book_your_seat($field) {
  // Entity metadata wrapper.
  $emw = entity_metadata_wrapper('node', $field['entity']);

  // List of states, in which one could register for an event.
  $allowed_states = [
    DT_EVENT_STATE_FUTURE,
    DT_EVENT_STATE_ONGOING,
    DT_EVENT_STATE_RESCHEDULED,
  ];

  // Few conditions should be met.
  if (
    in_array($field['entity']->event_status, $allowed_states) &&
    !$emw->field_event_is_fully_booked->value() &&
    $registration = $emw->field_event_registration->value()
  ) {
    // If registration is still open we can show the button.
    if ($emw->field_event_registration_end->value() > time()) {
      // Our button text will default if not filled in.
      $button_link = $registration['display_url'];
      $button_text = !empty($registration['title']) && $registration['title'] !== $button_link ? $registration['title'] : t('Book your seat');
    }
    // Special case if ongoing and live stream is available.
    if (
      $field['entity']->event_livestream_status == DT_EVENT_LIVE_STREAM_ONGOING &&
      $stream_link = $emw->field_event_live_streaming_link->value()
    ) {
      $button_text = t('Watch live now');
      $button_link = $stream_link['display_url'];
    }

    if (isset($button_text)) {
      // Default attributes for the link.
      $attributes = [
        'attributes' => [
          'class' => [
            'btn',
            'btn-ctn',
            'pull-left',
          ],
        ],
        'html' => TRUE,
      ];

      // Return the link.
      return l($button_text, $button_link, $attributes);
    }
  }
}

/**
 * Helper function to show the livestreaming string.
 *
 * @param array $field
 *   Hold the current context of the field.
 */
function _dt_event_ds_fields_livestreaming($field) {
  // Entity metadata wrapper.
  $emw = entity_metadata_wrapper('node', $field['entity']);

  // List of states, in which one could register for an event.
  $allowed_states = [
    DT_EVENT_STATE_FUTURE,
    DT_EVENT_STATE_ONGOING,
    DT_EVENT_STATE_RESCHEDULED,
  ];

  // Few conditions should be met.
  if (in_array($field['entity']->event_status, $allowed_states)) {
    // Based on the state we set our message.
    switch ($field['entity']->event_livestream_status) {
      case DT_EVENT_LIVE_STREAM_FUTURE:
        $timezone = $field['entity']->field_event_live_streaming_date[LANGUAGE_NONE][0]['timezone'];
        $replacement = [
          '@time' => format_date($emw->field_event_live_streaming_date->value->value(), 'custom', 'h:m (T)', $timezone),
        ];
        $streaming_text = t('<strong>Or watch live streaming</strong> at @time', $replacement);
        break;

      case DT_EVENT_LIVE_STREAM_ONGOING:
        $stream_count = 0;
        $streaming_text = t('@count are watching', ['@count' => $stream_count]);
        break;
    }

    // Return the text if it is found.
    if (isset($streaming_text)) {
      return '<span class="label label--high pull-left">' . $streaming_text . '</span>';
    }
  }
}

/**
 * Helper function to show the event header.
 *
 * @param array $field
 *   Hold the current context of the field.
 */
function _dt_event_ds_fields_header_event($field) {
  $entity = entity_metadata_wrapper('node', $field['entity']);
  $node = $field['entity'];
  $lang = entity_translation_get_existing_language('node', $node);
  $date = $entity->field_event_date->value();
  $is_streaming = $entity->field_event_is_live_streaming->value();

  // Cancelled, it shows the date with a modifier.
  $modifier = $node->event_status == DT_EVENT_STATE_CANCELLED ? 'page-header__date--cancelled ' : '';

  // Build the markup.
  $wrapper = '<div class="page-header__eventinfo">';
  $markup = '<div class="' . $modifier . 'page-header__date icon icon--calendar">';

  switch ($node->event_status) {
    // Ongoing, it shows the current date.
    case DT_EVENT_STATE_ONGOING:
      $markup .= format_date(time(), 'dt_event', '', NULL, $lang);
      break;

    // Past event, it shows also the year.
    case DT_EVENT_STATE_PAST:
      $markup .= format_date($date['value'], 'dt_past_event', '', NULL, $lang);
      break;

    // Cancelled, apply the right date format.
    case DT_EVENT_STATE_CANCELLED:
      $end_date = !empty($date['value2']) ? $date['value2'] : $date['value'];
      $markup .= time() > $end_date ? format_date($date['value'], 'dt_past_event', '', NULL, $lang) : format_date($date['value'], 'dt_event', '', NULL, $lang);
      break;

    // Default is showing the start date of the event.
    default:
      $markup .= format_date($date['value'], 'dt_event', '', NULL, $lang);
  }

  $markup .= '</div>';

  // Event location, online event only.
  if ($entity->field_event_is_online->value()) {
    $markup .= '<span class="icon icon--location page-header__location">' . t('Online only') . '</span>';
  }
  // All of the others.
  else {
    $location = $entity->field_core_location->value();
    if (!empty($location)) {
      $markup .= '<span class="icon icon--location page-header__location">' . $location['locality'];
    }

    // We only get the country ISO code from addressfield.
    if (!empty($location['country'])) {
      $countries = country_get_list();
      $markup .= ', ' . $countries[$location['country']];
    }

    $markup .= '</span>';
  }

  if ($is_streaming && (!in_array($node->event_status, array(DT_EVENT_STATE_CANCELLED, DT_EVENT_STATE_PAST)))) {
    $markup .= '<span class="icon icon--livestreaming page-header__livestreaming">' . t('live streaming available') . '</span>';
  }

  $closure = '</div>';

  $output = array(
    '#markup' => $markup,
    '#prefix' => $wrapper,
    '#suffix' => $closure,
  );

  return drupal_render($output);
}
