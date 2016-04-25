<?php
/**
 * @file
 * cwt_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cwt_core_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  if ($module == "breakpoints" && $api == "default_breakpoints") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "custom_formatters" && $api == "custom_formatters") {
    return array("version" => "2");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "2");
  }
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cwt_core_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function cwt_core_image_default_styles() {
  $styles = array();

  // Exported image style: content_image_690px.
  $styles['content_image_690px'] = array(
    'label' => 'Content Image (690px)',
    'effects' => array(
      18 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 690,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: listings.
  $styles['listings'] = array(
    'label' => 'Listings (236x157) ',
    'effects' => array(
      12 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 236,
          'height' => 157,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: listings_307x205.
  $styles['listings_307x205'] = array(
    'label' => 'Listings (307x205)',
    'effects' => array(
      10 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 307,
          'height' => 205,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: priority_thumbnail.
  $styles['priority_thumbnail'] = array(
    'label' => 'priority_thumbnail (100x330)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 330,
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function cwt_core_node_info() {
  $items = array(
    'custom_page' => array(
      'name' => t('Custom Page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_tmgmt_translator().
 */
function cwt_core_default_tmgmt_translator() {
  $items = array();
  $items['file'] = entity_import('tmgmt_translator', '{
    "name" : "file",
    "label" : "File translator (auto created)",
    "description" : "File translator that exports and imports files.",
    "weight" : "0",
    "plugin" : "file",
    "settings" : {
      "auto_accept" : 1,
      "export_format" : "xml",
      "xliff_processing" : 0,
      "allow_override" : 0,
      "scheme" : "public",
      "remote_languages_mappings" : { "en" : "en", "fi" : "fi", "fr" : "fr", "de" : "de", "hu" : "hu" }
    },
    "rdf_mapping" : []
  }');
  return $items;
}
