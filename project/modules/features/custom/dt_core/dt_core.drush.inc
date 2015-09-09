<?php

/**
 * @file
 * DT Core module drush integration.
 */

/**
 * Implements hook_drush_command().
 *
 * @see drush_parse_command()
 */
function dt_core_drush_command() {
  $items = array();

  $items['features-revert-dt'] = array(
    'description' => "Revert all enabled feature module on your site.",
    'options' => array(
      'force' => "Force revert even if Features assumes components' state are default.",
    ),
    'drupal dependencies' => array('features'),
    'aliases' => array('fr-dt', 'frdt'),
  );

  return $items;
}

/**
 * Implements hook_drush_help().
 */
function dt_core_drush_help($section) {
  switch ($section) {
    case 'drush:features-revert-dt':
      return dt("Revert all enabled feature module on your site that has the 'dt_' or 'cwt_' prefix.");
  }
}

/**
 * Revert all enabled features to their definitions in code.
 *
 * @param ...
 *   (Optional) A list of features to exclude from being reverted.
 */
function drush_dt_core_features_revert_dt() {
  module_load_include('inc', 'features', 'features.export');
  $force = drush_get_option('force');

  $features_to_revert = array('nexteuropa_file', 'nexteuropa_page');
  foreach (features_get_features(NULL, TRUE) as $module) {
    if ($module->status && preg_match('/dt_*|cwt_*/', $module->name)) {
      // If forced, add module regardless of status.
      if ($force) {
        $features_to_revert[] = $module->name;
      }
      else {
        switch (features_get_storage($module->name)) {
          case FEATURES_OVERRIDDEN:
          case FEATURES_NEEDS_REVIEW:
          case FEATURES_REBUILDABLE:
            $features_to_revert[] = $module->name;
            break;
        }
      }
    }
  }

  if ($features_to_revert) {
    $dt_args = array('!modules' => implode(', ', $features_to_revert));
    drush_print(dt('The following modules will be reverted: !modules', $dt_args));
    // Confirm that the user would like to continue. If not, simply abort.
    if (!drush_confirm(dt('Do you really want to continue?'))) {
      return drush_user_abort('Aborting.');
    }
    drush_invoke('features-revert', $features_to_revert);
  }
  else {
    drush_log(dt('Current state already matches defaults, aborting.'), 'ok');
  }
}
