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
    'properties' => [
      'settings' => [
        'no_padding' => [
          'title' => t('Remove left padding'),
          'type' => 'checkbox',
          'description' => t('Removes the left padding for different view mode usage'),
        ],
      ],
      'default' => [
        'no_padding' => FALSE,
      ],
    ],
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
      'properties' => [
        'settings' => [
          'teaser_version' => [
            'title' => t('Teaser version'),
            'type' => 'checkbox',
            'description' => t('The teaser version will add additional markup and hide various elements'),
          ],
        ],
        'default' => [
          'teaser_version' => FALSE,
        ],
      ],
    ];
    $fields[$entity_type]['dt_event_address_oneline'] = [
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'ui_limit' => ['event|*'],
      'title' => t('Event: Address oneline'),
      'function' => '_dt_event_ds_fields_address_oneline',
      'use_token' => TRUE,
    ];
    $fields[$entity_type]['dt_event_status_label'] = [
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'ui_limit' => ['event|*'],
      'title' => t('Event: Status label'),
      'function' => '_dt_event_ds_fields_status_label',
      'use_token' => TRUE,
    ];
  }

  if (isset($fields[$entity_type])) {
    return [$entity_type => $fields[$entity_type]];
  }
}

/**
 * Implements hook_ds_field_settings_form().
 */
function dt_event_ds_field_settings_form($field) {
  return ds_ds_field_settings_form($field);
}

/**
 * Implements hook_ds_field_format_summary().
 */
function dt_event_ds_field_format_summary($field) {
  return ds_ds_field_format_summary($field);
}

/**
 * Helper function to show the status label.
 *
 * @param array $field
 *   Hold the current context of the field.
 *
 * @return mixed
 *   The markup or nothing.
 */
function _dt_event_ds_fields_status_label($field) {
  switch ($field['entity']->event_status) {
    case DT_EVENT_STATE_RESCHEDULED:
      $label = t('Rescheduled');
      break;

    case DT_EVENT_STATE_CANCELLED:
      $label = t('Cancelled');
      break;

    default:
      return NULL;
  }
  return '<span class="label label--upper label--meta-medium label--status">' . $label . '</span>';
}

/**
 * Helper function to show the address in one line.
 *
 * @param array $field
 *   Hold the current context of the field.
 *
 * @return string
 *   The address text in one line.
 */
function _dt_event_ds_fields_address_oneline($field) {
  // The token output in the order we want to use it.
  $parts = [
    '[node:field_core_location:premise] [node:field_core_location:thoroughfare] [node:field_core_location:sub_premise]',
    '[node:field_core_location:postal-code] [node:field_core_location:locality]',
    '[node:field_core_location:country]',
  ];

  // Token replacement and checking for values.
  foreach ($parts as $key => &$part) {
    $part = trim(token_replace($part, [$field['entity_type'] => $field['entity']], ['clear' => TRUE]));
    if (ctype_space($part) || empty($part)) {
      // If it is only whitespace, we remove it.
      unset($parts[$key]);
    }
  }

  // If it is still available, we implode the array and return the address line.
  if (!empty($parts)) {
    $address = implode(', ', $parts);
    return $address . ' ' . l(t('View map'), 'https://www.google.com/maps?q=' . $address);
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
 *
 * @return string
 *   The book your seat button markup.
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
            'btn--no-margin-bottom',
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
 *
 * @return string
 *   The livestreaming field markup.
 */
function _dt_event_ds_fields_livestreaming($field) {
  // Entity metadata wrapper.
  $emw = entity_metadata_wrapper('node', $field['entity']);

  // Initialize classes array.
  $classes = [
    'label',
    'label--high',
    'pull-left',
  ];
  // In some cases we might remove the padding on the left.
  if (isset($field['formatter_settings']['no_padding']) && $field['formatter_settings']['no_padding']) {
    $classes[] = 'label--no-padding-left';
  }

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
      return '<span class="' . implode(' ', $classes) . '">' . $streaming_text . '</span>';
    }
  }
}

/**
 * Helper function to show the event header.
 *
 * @param array $field
 *   Hold the current context of the field.
 *
 * @return string
 *   The event header component markup.
 */
function _dt_event_ds_fields_header_event($field) {
  $entity = entity_metadata_wrapper('node', $field['entity']);
  $lang = entity_translation_get_existing_language('node', $field['entity']);
  $date = $entity->field_event_date->value();
  $is_streaming = $entity->field_event_is_live_streaming->value();

  // Check if we should render the teaser version.
  $teaser_mode = isset($field['formatter_settings']['teaser_version']) ? $field['formatter_settings']['teaser_version'] : FALSE;

  // Set the default classes.
  $element_classes = [
    'location' => 'icon--text-small icon--margin-right',
    'livestream' => 'icon--text-small',
  ];

  // Initialize markup.
  $markup = '';
  $location_content = '';

  // Start building the markup.
  if (!$teaser_mode) {
    // If it is not the teaser, it is the header variant.
    $element_classes = [
      'location' => 'page-header__location',
      'livestream' => 'page-header__livestreaming',
    ];

    // Cancelled, it shows the date with a modifier.
    $modifier = $field['entity']->event_status == DT_EVENT_STATE_CANCELLED ? 'page-header__date--cancelled ' : '';

    switch ($field['entity']->event_status) {
      // Ongoing, it shows the current date.
      case DT_EVENT_STATE_ONGOING:
        $date_value = format_date(time(), 'dt_event', '', NULL, $lang);
        break;

      // Past event, it shows also the year.
      case DT_EVENT_STATE_PAST:
        $date_value = format_date($date['value'], 'dt_past_event', '', NULL, $lang);
        break;

      // Cancelled, apply the right date format.
      case DT_EVENT_STATE_CANCELLED:
        $end_date = !empty($date['value2']) ? $date['value2'] : $date['value'];
        $date_value = time() > $end_date ? format_date($date['value'], 'dt_past_event', '', NULL, $lang) : format_date($date['value'], 'dt_event', '', NULL, $lang);
        break;

      // Default is showing the start date of the event.
      default:
        $date_value = format_date($date['value'], 'dt_event', '', NULL, $lang);
    }

    // Add the date markup.
    $markup .= '<div class="' . $modifier . 'page-header__date icon icon--calendar">' . $date_value . '</div>';
  }

  // Event location, online event only.
  if ($entity->field_event_is_online->value()) {
    $location_content .= t('Online only');
  }
  // All of the others.
  else {
    $location = $entity->field_core_location->value();
    if (!empty($location)) {
      $location_content .= $location['locality'];
    }
    // We only get the country ISO code from addressfield.
    if (!empty($location['country'])) {
      $countries = country_get_list();
      $location_content .= ', ' . $countries[$location['country']];
    }
  }

  // Add the extra markup.
  if (!empty($location_content)) {
    $markup .= '<span class="icon icon--location ' . $element_classes['location'] . '">' . $location_content . '</span>';
  }

  if ($is_streaming && (!in_array($field['entity']->event_status, array(DT_EVENT_STATE_CANCELLED, DT_EVENT_STATE_PAST)))) {
    $markup .= '<span class="icon icon--livestreaming ' . $element_classes['livestream'] . '">' . t('live streaming available') . '</span>';
  }

  // Start building the render array.
  $output = array(
    '#markup' => $markup,
  );

  // Depending on the date placement we add our prefix and suffix.
  if (!$teaser_mode) {
    $output['#prefix'] = '<div class="page-header__eventinfo">';
    $output['#suffix'] = '</div>';
  }

  return drupal_render($output);
}
