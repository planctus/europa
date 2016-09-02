<?php

/**
 * @file
 * dt_gallery.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dt_gallery_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = '_dt_gallery_dynamic';
  $strongarm->value = TRUE;
  $export['_dt_gallery_dynamic'] = $strongarm;

  return $export;
}
