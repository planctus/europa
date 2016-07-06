<?php

/**
 * @file
 * dt_editorial.features.workbench_moderation_states.inc
 */

/**
 * Implements hook_workbench_moderation_export_states().
 */
function dt_editorial_workbench_moderation_export_states() {
  $items = array(
    'request_validation' => (object) array(
      'name' => 'request_validation',
      'label' => 'Request Validation',
      'description' => 'Requesting validation',
      'weight' => -8,
    ),
  );
  return $items;
}
