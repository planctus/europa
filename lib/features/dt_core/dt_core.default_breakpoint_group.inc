<?php
/**
 * @file
 * dt_core.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function dt_core_default_breakpoint_group() {
  $export = array();

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'europa';
  $breakpoint_group->name = 'Europa';
  $breakpoint_group->breakpoints = array(
    0 => 'breakpoints.theme.europa.wide',
    1 => 'breakpoints.theme.europa.normal',
    2 => 'breakpoints.theme.europa.medium',
    3 => 'breakpoints.theme.europa.narrow',
    4 => 'breakpoints.theme.europa.mobile',
  );
  $breakpoint_group->type = 'theme';
  $breakpoint_group->overridden = 0;
  $export['europa'] = $breakpoint_group;

  return $export;
}