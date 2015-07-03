<?php
/**
 * @file
 * dt_core.variable.inc
 */

/**
 * Implements hook_variable_realm_default_variables().
 */
function dt_core_variable_realm_default_variables() {
$realm_variables = array();
  $realm_variables['language']['en'] = array(
  'site_name' => 'European Commission Beta',
  'site_slogan' => '',
);

return $realm_variables;
}
