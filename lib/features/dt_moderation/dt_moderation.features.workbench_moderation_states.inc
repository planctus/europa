<?php
/**
 * @file
 * dt_moderation.features.workbench_moderation_states.inc
 */

/**
 * Implements hook_workbench_moderation_export_states().
 */
function dt_moderation_workbench_moderation_export_states() {
  $items = array(
    'request_validation' => (object) array(
      'name' => 'request_validation',
      'label' => 'Request Validation',
      'description' => 'Requesting validation',
      'weight' => 0,
    ),
  );
  return $items;
}
