<?php
/**
 * @file
 * nexteuropa_publication.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nexteuropa_publication_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_nexteuropa_publication';
  $strongarm->value = '0';
  $export['comment_anonymous_nexteuropa_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_nexteuropa_publication';
  $strongarm->value = 1;
  $export['comment_default_mode_nexteuropa_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_nexteuropa_publication';
  $strongarm->value = '50';
  $export['comment_default_per_page_nexteuropa_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_nexteuropa_publication';
  $strongarm->value = 1;
  $export['comment_form_location_nexteuropa_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_nexteuropa_publication';
  $strongarm->value = '2';
  $export['comment_nexteuropa_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_nexteuropa_publication';
  $strongarm->value = '1';
  $export['comment_preview_nexteuropa_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_nexteuropa_publication';
  $strongarm->value = 1;
  $export['comment_subject_field_nexteuropa_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_nexteuropa_publication';
  $strongarm->value = '0';
  $export['language_content_type_nexteuropa_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_nexteuropa_publication';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_nexteuropa_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_nexteuropa_publication';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_nexteuropa_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_nexteuropa_publication';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_nexteuropa_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_nexteuropa_publication';
  $strongarm->value = '1';
  $export['node_preview_nexteuropa_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_nexteuropa_publication';
  $strongarm->value = 1;
  $export['node_submitted_nexteuropa_publication'] = $strongarm;

  return $export;
}
