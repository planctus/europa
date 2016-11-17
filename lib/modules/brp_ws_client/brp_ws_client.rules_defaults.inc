<?php

/**
 * @file
 * Contains BRP WS Client default Rules configuration.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function brp_ws_client_default_rules_configuration() {
  $config = [];
  $rule = '';
  // Getting all BRP WS Client rules configuration files.
  $rules_path = drupal_get_path('module', 'brp_ws_client') . '/rules';
  $files = file_scan_directory($rules_path, '/\.rule$/');

  foreach ($files as $file_path => $file) {
    require $file_path;
    if (!empty($rule)) {
      $config['brp_ws_client_' . $file->name] = rules_import($rule);
    }
  }

  return $config;
}
