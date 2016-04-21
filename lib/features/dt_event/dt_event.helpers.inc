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
        if ($emw->__isset('field_event_start')) {
          $start_date = $emw->field_event_start->value();

          // We always need a start date.
          if (is_null($start_date)) {
            return;
          }
        }
        if ($emw->__isset('field_event_end')) {
          // Set the end date.
          $end_date = $emw->field_event_end->value();

          // If no end date, end date is start date + 1 day.
          if (is_null($end_date)) {
            // Create a new time object.
            $date = new DateTime();
            // Set the timezone to the one of the start date.
            $date->setTimezone(new DateTimeZone($entity->field_event_start[LANGUAGE_NONE][0]['timezone']));
            $date->setTimestamp($start_date);
            $date->modify('tomorrow');
            $date->modify('1 second ago');
            // Set the end date to the timestamp.
            $end_date = $date->getTimestamp();
          }
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

      default:
        // In case it's undefined, we log a message.
        watchdog('Events', 'Undefined event status %status.', ['%status' => $event_status], WATCHDOG_ALERT);
        break;
    }
  }
}
