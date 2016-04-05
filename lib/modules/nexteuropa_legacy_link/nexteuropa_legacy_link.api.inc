<?php
/**
 * @file
 * This file contains examples of hooks legacy_link can implement.
 */

/**
 * Alter hook for the legacy link.
 *
 * @param string $legacy_link_url
 *   The current legacy link, FALSE if none is present.
 * @param object $entity
 *   The entity to work with.
 * @param string $langcode
 *   The language code.
 */
function hook_nexteuropa_legacy_link_alter($legacy_link_url, $entity, $langcode) {
  if ($langcode == 'en') {
    $legacy_link_url = $legacy_link_url . '_en';
  }
}
