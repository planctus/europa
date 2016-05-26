<?php
/**
 * @file
 * Simple command to generate the settings.
 */

if (isset($argv) && isset($argv[1])) {
  define('DRUPAL_ROOT', $argv[2]);
  $_SERVER['HTTP_HOST'] = 'empty';
  include DRUPAL_ROOT . '/includes/bootstrap.inc';
  include DRUPAL_ROOT . '/includes/install.inc';
  include DRUPAL_ROOT . '/includes/update.inc';
  global $db_prefix;
  $db['databases']['value'] = update_parse_db_url($argv[1], $db_prefix);
  drupal_rewrite_settings($db, $db_prefix);
}
