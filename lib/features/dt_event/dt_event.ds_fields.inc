<?php

/**
 * @file
 * Event ds fields.
 *
 * This file contains all custom ds fields and related functions.
 */

use Drupal\dt_date_format\DtDateRangeFormat;

/**
 * Implements hook_ds_fields_info().
 */
function dt_event_ds_fields_info($entity_type) {
  $fields = [];

  if ($entity_type == 'node') {
    $fields[$entity_type]['book_your_seat'] = [
      'title' => t('Event: Book your seat button'),
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'ui_limit' => ['event|*'],
      'function' => '_dt_event_ds_fields_book_your_seat',
    ];

    $fields[$entity_type]['livestreaming'] = [
      'title' => t('Event: Livestreaming'),
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

    $fields[$entity_type]['attend'] = [
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'ui_limit' => ['event|*'],
      'title' => t('Attend'),
      'function' => '_dt_event_ds_fields_attend_field',
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
      'properties' => [
        'settings' => [
          'show_link' => [
            'title' => t('Show link'),
            'type' => 'checkbox',
            'description' => t('Show a google maps link'),
          ],
        ],
        'default' => [
          'show_link' => TRUE,
        ],
      ],
    ];

    $fields[$entity_type]['dt_event_status_label'] = [
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'ui_limit' => ['event|*'],
      'title' => t('Event: Status label'),
      'function' => '_dt_event_ds_fields_status_label',
      'use_token' => TRUE,
    ];

    // We need two status field.
    $amount_of_lines = 2;
    for ($i = 1; $i <= $amount_of_lines; $i++) {
      $fields[$entity_type]['dt_event_status_message_' . $i] = [
        'field_type' => DS_FIELD_TYPE_FUNCTION,
        'ui_limit' => ['event|*'],
        'title' => t('Event: Status message (@line)', ['@line' => $i]),
        'function' => '_dt_event_ds_fields_status_message',
        'use_token' => TRUE,
        'properties' => [
          'formatters' => [
            // For the top message.
            'event_status_message_formatter' => t('Message formatting'),
            // For practical information section.
            'event_status_inline_formatter' => t('Inline formatting'),
          ],
        ],
      ];
    }

    $fields[$entity_type]['dt_event_date_and_time'] = [
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'ui_limit' => ['event|*'],
      'title' => t('Event: when, custom date and time'),
      'function' => '_dt_event_ds_fields_date_and_time',
    ];

    $fields[$entity_type]['dt_event_scribble_embed'] = [
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'ui_limit' => ['event|*'],
      'title' => t('Event: Scribble embed'),
      'function' => '_dt_event_ds_fields_scribble_embed',
      'properties' => [
        'settings' => [
          'show_intro' => [
            'title' => t('Show intro'),
            'type' => 'checkbox',
            'description' => t('Show the introduction text'),
          ],
        ],
        'default' => [
          'show_intro' => FALSE,
        ],
      ],
    ];

    $fields[$entity_type]['dt_event_stream_embed'] = [
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'ui_limit' => ['event|*'],
      'title' => t('Event: Stream embed'),
      'function' => '_dt_event_ds_fields_stream_embed',
    ];

    $fields[$entity_type]['dt_event_stream_embed_intro'] = [
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'ui_limit' => ['event|*'],
      'title' => t('Event: Stream embed intro'),
      'function' => '_dt_event_ds_fields_stream_embed_intro',
    ];

    $fields[$entity_type]['dt_event_livestream_header'] = [
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'ui_limit' => ['event|*'],
      'title' => t('Event: Livestream header'),
      'function' => '_dt_event_ds_fields_livestream_header',
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
 * Helper function to show the scribble iframe with CCK.
 *
 * @param array $field
 *   Holds the current context of the field.
 *
 * @return string
 *   The rendered iframe.
 */
function _dt_event_ds_fields_scribble_embed($field) {
  $entity = entity_metadata_wrapper('node', $field['entity']);
  if ($entity->__isset('field_event_scribble_id') && $scribble_id = $entity->field_event_scribble_id->value()) {
    $content_language = _dt_shared_functions_content_language($field['entity']);
    $markup = [
      '#markup' => '<iframe width="100%" height="600px" src="//ec.europa.eu/cookie-consent/iframe?lang=' . $content_language . '&oriurl=//embed.scribblelive.com/Embed/v5.aspx?Id=' . $scribble_id . '" allowfullscreen="allowfullscreen"></iframe>',
    ];

    if (isset($field['formatter_settings']['show_intro']) && $field['formatter_settings']['show_intro']) {
      $markup['#prefix'] = '<p>' . t("What's happening in different social media channels") . '</p>';
    }

    return drupal_render($markup);
  }

  return NULL;
}

/**
 * Helper function to show the embed url iframe with CCK.
 *
 * @param array $field
 *   Holds the current context of the field.
 *
 * @return string
 *   The rendered iframe.
 */
function _dt_event_ds_fields_stream_embed($field) {
  $entity = entity_metadata_wrapper('node', $field['entity']);
  if ($entity->__isset('field_event_live_streaming_link') && $stream_url = $entity->field_event_live_streaming_link->value()) {
    $content_language = _dt_shared_functions_content_language($field['entity']);
    if (isset($stream_url['url'])) {
      $markup = [
        '#markup' => '<iframe width="100%" height="315px" src="//ec.europa.eu/cookie-consent/iframe?lang=' . $content_language . '&oriurl=' . $stream_url['url'] . '" allowfullscreen="allowfullscreen"></iframe>',
      ];

      return drupal_render($markup);
    }
  }

  return NULL;
}

/**
 * Helper function to show the embed video intro.
 *
 * @param array $field
 *   Holds the current context of the field.
 *
 * @return string
 *   The rendered intro.
 */
function _dt_event_ds_fields_stream_embed_intro($field) {
  $entity = entity_metadata_wrapper('node', $field['entity']);
  if ($entity->__isset('field_event_live_streaming_link') && $stream_url = $entity->field_event_live_streaming_link->value()) {
    if (isset($stream_url['url'])) {
      // Content language to render the field.
      $content_language = _dt_shared_functions_content_language($field['entity']);

      // Format the date.
      $display = [
        'label' => 'hidden',
        'module' => 'dt_date_format',
        'settings' => [
          'fallback' => 'sd_l sd_j sd_F, sd_G.sd_i - ed_l ed_j ed_F, ed_G.ed_i (sd_T)',
          'render_box' => 0,
          'same_date_format' => 'sd_l sd_j sd_F',
          'same_day_format' => 'sd_l sd_j sd_F, sd_G.sd_i - ed_G.ed_i (sd_T)',
        ],
        'type' => 'date_event_date',
      ];

      // Get the field.
      $date = field_view_field($entity->type(), $entity->raw(), 'field_event_date', $display, $content_language);

      // Build the markup.
      $markup = [
        '#prefix' => '<div class="row">',
        '#markup' => '<div class="col-md-6">' . drupal_render($date) . '</div><div class="col-md-6 text-right"><p>' . l(t('Event details'), 'node/' . $entity->getIdentifier()) . '</p></div>',
        '#suffix' => '</div>',
      ];

      return drupal_render($markup);
    }
  }

  return NULL;
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
function _dt_event_ds_fields_status_message($field) {
  // When the stream was started, but the event has not been started,
  // should not see any status message.
  // If the field formatter 'event_status_inline_formatter',
  // then use 'dt_event_status_message' theme function.
  $theme_function = ($field['formatter'] == 'event_status_inline_formatter') ? 'dt_event_status' : 'europa_status_message';
  // Default config.
  $render_config = [
    '#theme' => $theme_function,
    '#message_classes' => ['messages--icon-center'],
  ];

  // Based on the event state we modify the render array.
  if (!isset($field['entity']->event_status)) {
    return NULL;
  }

  switch ($field['entity']->event_status) {
    case DT_EVENT_STATE_ONGOING:
      $render_config['#message_title'] = t('This event has started.');

      // If live stream is available we add it to the message.
      if (
        _dt_event_live_stream_state($field['entity']) == DT_EVENT_LIVE_STREAM_ONGOING
        && isset($field['entity']->field_event_live_streaming_link[_dt_shared_functions_content_language($field['entity'])])
      ) {
        $render_config['#message_body'] = l(t('Watch live streaming'), drupal_get_path_alias('node/' . $field['entity']->nid) . '/live');
        $render_config['#message_classes'][] = 'live';
        $render_config['#message_type'] = 'Live streaming message';
      }
      break;

    case DT_EVENT_STATE_FUTURE:
      if (isset($field['entity']->event_status_rescheduled) && $field['entity']->event_status_rescheduled) {
        $render_config['#message_title'] = t('This event has been rescheduled.');
        $render_config['#message_body'] = _dt_event_get_status_information($field['entity']);
        $render_config['#message_classes'][] = 'warning';
        $render_config['#message_type'] = 'Warning message';
      }
      break;

    case DT_EVENT_STATE_CANCELLED:
      $render_config['#message_title'] = t('This event has been cancelled.');
      $render_config['#message_body'] = _dt_event_get_status_information($field['entity']);
      $render_config['#message_classes'][] = 'warning';
      $render_config['#message_type'] = 'Warning message';
      break;

    case DT_EVENT_STATE_PAST:
      $render_config['#message_title'] = t('This event has ended.');
      break;

    default:
      return NULL;
  }
  $render_config['#message_classes'] = implode(" ", $render_config['#message_classes']);

  return !empty($render_config['#message_title']) ? drupal_render($render_config) : NULL;
}

/**
 * Helper function to show the status label.
 *
 * @param array $field
 *   Holds the current context of the field.
 *
 * @return mixed
 *   The markup or nothing.
 */
function _dt_event_ds_fields_status_label($field) {
  switch ($field['entity']->event_status) {
    case DT_EVENT_STATE_FUTURE:
      if (isset($field['entity']->event_status_rescheduled) && $field['entity']->event_status_rescheduled) {
        $label = t('Rescheduled');
      }
      break;

    case DT_EVENT_STATE_CANCELLED:
      $label = t('Cancelled');
      break;
  }

  if (isset($label)) {
    return '<span class="label label--upper label--meta-medium label--status">' . $label . '</span>';
  }

  return NULL;
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
    if (isset($field['formatter_settings']['show_link']) && $field['formatter_settings']['show_link']) {
      return $address . ' ' . l(t('View map'), 'https://www.google.com/maps?q=' . $address);
    }

    return $address;
  }
}

/**
 * Helper function to show the book your seat button and watch live together.
 *
 * @param array $field
 *   Hold the current context of the field.
 *
 * @return string
 *   The markup.
 */
function _dt_event_ds_fields_attend_field($field) {
  return _dt_event_ds_fields_book_your_seat($field) . _dt_event_ds_fields_livestreaming($field);
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
  // List of states, in which one could register for an event.
  $allowed_states = [
    DT_EVENT_STATE_FUTURE,
    DT_EVENT_STATE_ONGOING,
  ];

  // Few conditions should be met.
  if (
    isset($field['entity']->event_status, $emw->field_event_is_fully_booked)
    && in_array($field['entity']->event_status, $allowed_states)
    && !$emw->field_event_is_fully_booked->value()
  ) {
    // If registration is still open we can show the button.
    if (
      $field['view_mode'] !== 'teaser'
      && $emw->field_event_registration_end->value() > time()
      && $emw->field_event_registration->value()
    ) {
      // The desired language.
      $langcode = $GLOBALS['language_content']->language;
      // Get the field data.
      $registration = $emw->language($langcode)->field_event_registration->value();
      // Our button text will default if not filled in.
      $button_link = $registration['url'];
      $button_text = !empty($registration['title']) && $registration['title'] !== $button_link ? $registration['title'] : t('Book your seat');
    }
    // Special case if ongoing and live stream is available.
    elseif (
      $field['entity']->event_livestream_status == DT_EVENT_LIVE_STREAM_ONGOING &&
      $emw->field_event_live_streaming_link->value()
    ) {
      $button_link = drupal_get_path_alias('node/' . $field['entity']->nid) . '/live';
      $button_text = t('Watch live streaming');
    }

    if (isset($button_text) && isset($button_link)) {
      // Default attributes for the link.
      $attributes = [
        'attributes' => [
          'class' => [
            'btn',
            'btn-ctn',
            'btn--no-margin-bottom',
          ],
        ],
        'html' => TRUE,
      ];

      if ($field['view_mode'] === 'teaser') {
        $attributes['attributes']['class'][] = 'listing__btn';
      }

      // Return the link.
      return l($button_text, $button_link, $attributes);
    }
  }

  return NULL;
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
  ];

  // Few conditions should be met.
  if (
    isset($field['entity']->event_status)
    && in_array($field['entity']->event_status, $allowed_states)
  ) {
    // Based on the state we set our message.
    switch ($field['entity']->event_livestream_status) {
      case DT_EVENT_LIVE_STREAM_FUTURE:
        $timezone = $field['entity']->field_event_live_streaming_date[LANGUAGE_NONE][0]['timezone'];
        $replacement = [
          '@time' => format_date($emw->field_event_live_streaming_date->value->value(), 'custom', 'H:i (T)', $timezone),
        ];
        $streaming_text = t('<strong>Watch live</strong> at @time', $replacement);
        break;

      case DT_EVENT_LIVE_STREAM_ONGOING:
        // @todo: This will be implemented in a future ticket.
        $stream_count = 0;
        if ($stream_count >= 1) {
          $streaming_text = t('@count are watching', ['@count' => $stream_count]);
        }
        break;
    }

    // Return the text if it is found.
    if (isset($streaming_text)) {
      return '<span class="' . implode(' ', $classes) . '">' . $streaming_text . '</span>';
    }
  }
}

/**
 * Helper function for displaying date and time for event.
 *
 * @param array $field
 *   DS field.
 * @param object $entity
 *   Loaded entity.
 * @param bool $short
 *   Defines if the short format should be used.
 *
 * @return string
 *   Formatted date.
 */
function _dt_event_date_display(array $field, $entity, $short = FALSE) {
  // Initialize a dateRange object.
  $date = $entity->field_event_date->value();
  $date_object = new DtDateRangeFormat(
    $date['value'],
    $date['value2'],
    $date['date_type'],
    $date['timezone'],
    entity_translation_get_existing_language('node', $field['entity'])
  );

  // Date formats will be put into an array to keep them maintainable.
  $formats = [
    'future_ongoing' => [
      'short' => [
        'single_date' => 'sd_l sd_j sd_F',
        'single_date_different_hour' => 'sd_l sd_j sd_F',
        'different_day_same_month' => 'sd_l sd_j - ed_l ed_j ed_F',
        'different_month' => 'sd_l sd_j sd_F - ed_l ed_j ed_F',
        'different_year' => 'sd_l sd_j sd_F sd_Y - ed_l ed_j ed_F ed_Y',
      ],
      'extended' => [
        'single_date' => 'sd_l sd_j sd_F sd_Y, sd_G.sd_i (sd_T)',
        'single_date_different_hour' => 'sd_l sd_j sd_F sd_Y, sd_G.sd_i - ed_G.ed_i (sd_T)',
        'different_day_same_month' => 'sd_l sd_j sd_F sd_Y, sd_G.sd_i - ed_l ed_j ed_F ed_Y, ed_G.ed_i (sd_T)',
        'different_month' => 'sd_l sd_j sd_F sd_Y, sd_G.sd_i - ed_l ed_j ed_F ed_Y, ed_G.ed_i (sd_T)',
        'different_year' => 'sd_l sd_j sd_F sd_Y, sd_G.sd_i - ed_l ed_j ed_F ed_Y, ed_G.ed_i (sd_T)',
      ],
    ],
    'other' => [
      'short' => [
        'single_date' => 'sd_j sd_F sd_Y',
        'single_date_different_hour' => 'sd_j sd_F sd_Y',
        'different_day_same_month' => 'sd_j - ed_j ed_F ed_Y',
        'different_month' => 'sd_j sd_F - ed_j ed_F ed_Y',
        'different_year' => 'sd_j sd_F sd_Y - ed_j ed_F ed_Y',
      ],
      'extended' => [
        'single_date' => 'sd_j sd_F sd_Y, sd_G.sd_i (sd_T)',
        'single_date_different_hour' => 'sd_j sd_F sd_Y, sd_G.sd_i - ed_G.ed_i (sd_T)',
        'different_day_same_month' => 'sd_j sd_F sd_Y, sd_G.sd_i - ed_j ed_F ed_Y, ed_G.ed_i (sd_T)',
        'different_month' => 'sd_j sd_F sd_Y, sd_G.sd_i - ed_j ed_F ed_Y, ed_G.ed_i (sd_T)',
        'different_year' => 'sd_j sd_F sd_Y, sd_G.sd_i - ed_j ed_F ed_Y, ed_G.ed_i (sd_T)',
      ],
    ],
  ];

  // Set the length format to use.
  $format_to_use = ($short) ? 'short' : 'extended';

  // The list of states that use the 'other' format.
  $other_states = [DT_EVENT_STATE_PAST, DT_EVENT_STATE_CANCELLED];

  // Assign the format.
  $format = in_array($field['entity']->event_status, $other_states) ? $formats['other'][$format_to_use] : $formats['future_ongoing'][$format_to_use];

  // Single day event.
  if ($date_object->isSameDate(TRUE)) {
    $date_object->setFormat($format['single_date']);
  }
  // Single day event, but different hours.
  elseif ($date_object->isSameDate(FALSE, 'Ymd')) {
    $date_object->setFormat($format['single_date_different_hour']);
  }
  // Multiple day event (days following each other) in one month.
  elseif ($date_object->isSameDate(FALSE, 'Ym')) {
    $date_object->setFormat($format['different_day_same_month']);
  }
  // Multiple day event (days following each other) in multiple months.
  elseif ($date_object->isSameDate(FALSE, 'Y')) {
    $date_object->setFormat($format['different_month']);
  }
  // Multiple day event (days following each other) in multiple months and
  // multiple years.
  else {
    $date_object->setFormat($format['different_year']);
  }

  return $date_object->getformattedDateRange();
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
  if (!$teaser_mode && isset($field['entity']->event_status)) {
    // If it is not the teaser, it is the header variant.
    $element_classes = [
      'location' => 'page-header__location',
      'livestream' => 'page-header__livestreaming',
    ];

    // Cancelled, it shows the date with a modifier.
    $modifier = $field['entity']->event_status == DT_EVENT_STATE_CANCELLED ? 'page-header__date--cancelled ' : '';
    // Add the date markup.
    $formatted_date = _dt_event_date_display($field, $entity, TRUE);
    $markup .= '<div class="' . $modifier . 'page-header__date icon icon--calendar">' . $formatted_date . '</div>';
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

  $unavailable_states = [
    DT_EVENT_STATE_CANCELLED,
    DT_EVENT_STATE_PAST,
  ];

  if ($is_streaming && (!in_array($field['entity']->event_status, $unavailable_states))) {
    $is_streaming_modifier_class = ' listing__status-container--inline';
    $markup .= '<span class="icon icon--livestreaming ' . $element_classes['livestream'] . '">' . t('live streaming available') . '</span>';
  }

  // Start building the render array.
  $output = ['#markup' => $markup];

  // Depending on the date placement we add our prefix and suffix.
  if (!$teaser_mode) {
    $output['#prefix'] = '<div class="page-header__eventinfo">';
    $output['#suffix'] = '</div>';
  }
  else {
    $output['#prefix'] = '<div class="listing__status-container' . (isset($is_streaming_modifier_class) ? $is_streaming_modifier_class : '') . '">';
    $output['#suffix'] = '</div>';
  }

  return drupal_render($output);
}

/**
 * Helper function for DS, to show the event date and time.
 *
 * @param array $field
 *   Hold the current context of the field.
 *
 * @return string
 *   The event header component markup.
 */
function _dt_event_ds_fields_date_and_time($field) {
  $entity = entity_metadata_wrapper('node', $field['entity']);
  $output = [];

  if (isset($entity->field_event_date)) {
    $formatted_date = _dt_event_date_display($field, $entity);
    // Add the date markup.
    $markup = ($field['entity']->event_status == DT_EVENT_STATE_CANCELLED) ? '<del>' . $formatted_date . '</del>' : $formatted_date;
    // Start building the render array.
    $output = ['#markup' => $markup];
  };

  return drupal_render($output);
}

/**
 * Helper function for DS, to show the event location.
 *
 * @param $field
 *    Field with entity.
 * @return string
 *    Return the markup.
 */
function _dt_event_ds_fields_livestream_header($field) {
  $entity = entity_metadata_wrapper('node', $field['entity']);
  $location = $entity->field_core_location->value();
  $markup = '';

  if ($location) {
    $markup = t('<h2>Live from ' . $location['locality'] . '</h2>');
  }

  return $markup;
}

