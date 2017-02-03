<?php
/**
 * @file
 * Defines flexible-date-related Views data and plugins:.
 */

/**
 * Implements hook_views_data_alter().
 */
function dt_flexible_date_views_data_alter(&$data) {
  // Find flexible date fields.
  $flexible_date_fields = field_read_fields(['type' => 'dt_flexible_date']);

  foreach ($flexible_date_fields as $key => $value) {
    if (isset($data['field_data_' . $key])) {
      $data['field_data_' . $key][$key]['sort'] = [
        'handler' => 'DtFlexibleDateSortHandler',
      ];
    }
  }
}
