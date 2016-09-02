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
    'under_validation' => (object) array(
      'name' => 'under_validation',
      'label' => 'Under Validation',
      'description' => 'Being validated',
      'weight' => -7,
    ),
  );
  return $items;
}
