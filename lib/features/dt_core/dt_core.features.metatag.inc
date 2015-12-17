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

  // Exported Metatag config instance: node.
  $config['node'] = (array) array(
    'instance' => 'node',
    'config' => array(
      'title' => array(
        'value' => '[node:title] | [site:name]',
      ),
      'description' => array(
        'value' => '[node:field-core-description]',
      ),
      'og:title' => array(
        'value' => '[node:title]',
      ),
      'og:description' => array(
        'value' => '[node:field-core-description]',
      ),
      'og:updated_time' => array(
        'value' => '[node:changed:custom:c]',
      ),
      'article:published_time' => array(
        'value' => '[node:created:custom:c]',
      ),
      'article:modified_time' => array(
        'value' => '[node:changed:custom:c]',
      ),
    ),
  );

  return $config;
}
