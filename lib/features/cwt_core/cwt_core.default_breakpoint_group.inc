<?php
/**
 * @file
 * cwt_core.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function cwt_core_default_breakpoint_group() {
  $export = array();

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'default_responsive_imags';
  $breakpoint_group->name = 'Default Responsive Imags';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.user.max_width_479px',
    1 => 'custom.user.min_width_960px',
    2 => 'custom.user.min_width_480px',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['default_responsive_imags'] = $breakpoint_group;

  return $export;
}
