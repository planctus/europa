<?php

/**
 * @file
 * Contains all non hook, helper function for dt_event.
 */

/**
 * Helper function to add the event status as entity property.
 *
 * @param object $entity
 *   The event entity.
 */
function _dt_event_entity_add_status_property(&$entity) {
  // Entity metadata wrapper, so we dont have to think about languages.
  $emw = entity_metadata_wrapper('node', $entity);

  // We should always have this set. But we make sure by doing this that we
  // are not working with bad entity's.
  if ($emw->__isset('field_event_status')) {

    // Based on the state, we set the property.
    switch ($emw->field_event_status->value()) {
      case 'cancelled':
        // Cancelled events.
        $entity->event_status = DT_EVENT_STATE_CANCELLED;
        break;

      case 'rescheduled':
        // Rescheduled events.
        $entity->event_status = DT_EVENT_STATE_RESCHEDULED;
        break;

      case 'no':
        // If it has no special state, we base it on the dates.
        if ($emw->__isset('field_event_date')) {
          $start_date = $emw->field_event_date->value->value();

          // We always need a start date.
          if (is_null($start_date)) {
            return;
          }

          // Set the end date if it is filled in.
          if ($emw->field_event_date->__isset('value2')) {
            // Set the end date. If the checkbox is unchecked, the default end
            // date is equal to the start date.
            $end_date = $emw->field_event_date->value2->value();
          }

          // If no end date, end date is start date + 1 day.
          if (!isset($end_date) || is_null($end_date) || $start_date == $end_date) {
            // Set the end date to the timestamp.
            $end_date = _dt_event_get_end_of_day($start_date, $entity->field_event_date[LANGUAGE_NONE][0]['timezone']);
          }

          // Get the current date.
          $current_date = time();

          // Based on the time comparison, we add the event state.
          switch (TRUE) {
            case ($end_date >= $current_date && $start_date <= $current_date):
              $entity->event_status = DT_EVENT_STATE_ONGOING;
              break;

            case $end_date <= $current_date:
              $entity->event_status = DT_EVENT_STATE_PAST;
              break;

            case $start_date >= $current_date:
              $entity->event_status = DT_EVENT_STATE_FUTURE;
              break;
          }
          break;
        }
        break;

      default:
        // In case it's undefined, we log a message.
        watchdog('Events', 'Undefined event status.');
        break;
    }
  }

  // Also add the livestream information.
  $entity->event_livestream_status = _dt_event_live_stream_state($entity);
}

/**
 * Helper function to get timestamp for the end of the day.
 *
 * @param int $timestamp
 *   The timestamp to get the end of day for.
 * @param string $timezone
 *   The timezone to use.
 *
 * @return string
 *   The end of the day as a timestamp.
 */
function _dt_event_get_end_of_day($timestamp, $timezone = 'UTC') {
  // Create a new time object.
  $date = new DateTime();
  // Set the timezone to the one of the start date.
  $date->setTimezone(new DateTimeZone($timezone));
  $date->setTimestamp($timestamp);
  $date->modify('tomorrow');
  $date->modify('1 second ago');
  // Set the end date to the timestamp.
  return $date->getTimestamp();
}

/**
 * Helper function to check if livestream is active on an event.
 *
 * This function should, ideally, not be called directly. Instead use the entity
 * property $entity->event_livestream_status.
 *
 * @param object $event
 *   The event node object.
 *
 * @return int
 *   TRUE if ongoing, FALSE otherwise.
 */
function _dt_event_live_stream_state($event) {
  if (empty($event->field_event_live_streaming_date)) {
    return NULL;
  }

  // Entity metadata wrapper.
  $emw = entity_metadata_wrapper('node', $event);
  // Set our start and end date.
  $stream_start = $emw->field_event_live_streaming_date->value->value();
  $stream_end = $emw->field_event_live_streaming_date->value2->value();

  // If the dates are equal, it means the end date checkbox is unchecked. In
  // this case, we set the end date to the end of the day.
  if ($stream_start == $stream_end) {
    // Need to take care of the timezone.
    $timezone = $event->field_event_live_streaming_date[LANGUAGE_NONE][0]['timezone'];
    $stream_end = _dt_event_get_end_of_day($stream_start, $timezone);
  }

  // Make sure we have livestream.
  $has_livestream = $emw->field_event_is_live_streaming->value() == 1;

  switch (TRUE) {
    case $has_livestream && $stream_start > time():
      $state = DT_EVENT_LIVE_STREAM_FUTURE;
      break;

    case $has_livestream && $stream_end > time() && $stream_start < time():
      $state = DT_EVENT_LIVE_STREAM_ONGOING;
      break;

    case $has_livestream && $stream_end < time():
      $state = DT_EVENT_LIVE_STREAM_END;
      break;

    default:
      $state = DT_EVENT_LIVE_STREAM_NONE;
      break;
  }

  return $state;
}

/**
 * Helper function to get the status information for an event.
 *
 * @param object $entity
 *   The entity object.
 *
 * @return string
 *   The status information.
 */
function _dt_event_get_status_information($entity) {
  $emw = entity_metadata_wrapper('node', $entity);
  if ($emw->__isset('field_event_status_description')) {
    if (!empty($entity->field_event_status_description)) {
      return $emw->field_event_status_description->value->value();
    }
  }
  return NULL;
}

/**
 * Helper function to check if we are on the /live part of the event.
 *
 * @param string $path
 *   The path to check for.
 *
 * @return bool
 *   True if on /live, false otherwise.
 */
function _dt_event_is_live_path($path = 'current') {
  if ($path == 'current') {
    $path = request_path();
  }
  return preg_match(DT_EVENT_LIVE_PATH_REGEX, $path);
}
