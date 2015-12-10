<?php
/**
 * @file
 * dt_core.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function dt_core_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: global.
  $config['global'] = (array) array(
    'instance' => 'global',
    'config' => array(
      'content-language' => array(
        'value' => '[dt_tokens:dt_content_language]',
      ),
    ),
  );

  return $config;
}
