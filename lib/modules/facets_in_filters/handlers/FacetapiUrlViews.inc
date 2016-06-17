<?php

/**
 * @file
 * The standard url processor class.
 */

/**
 * Url processor plugin that retrieves facet data from the query string.
 *
 * This plugin retrieves facet data from $_GET, and stored all information in
 * the "f" query string variable by default.
 *
 * @codingStandardsIgnoreFile
 */
class FacetapiUrlViews extends FacetapiUrlProcessorStandard {

  /**
   * Implements FacetapiUrlProcessor::normalizeParams().
   *
   * Strips the "q" and "page" variables from the params array.
   */
  public function normalizeParams(array $params, $filter_key = 'f') {
    $parameters = drupal_get_query_parameters($params, array('q', 'page'));

    $facets = [];
    // Parse them all. We need to take special care of trigger elements, as they
    // are checkboxes.
    foreach ($parameters as $key => $param) {
      if (!empty($param) && substr($key, 0, 7) == 'facets_') {
        $parsed = drupal_parse_url($param);
        if (strpos($key, '_trigger')) {
          if (isset($parsed['query']['f'])) {
            $facets = [
              'force' => $parsed['query']['f'],
            ];
          }
          unset($parameters[$key]);
          break;
        }
        if (isset($parsed['query']['trigger'])) {
          if (isset($parsed['query']['f'])) {
            $facets = [
              'force' => $parsed['query']['f'],
            ];
          }
          unset($parameters[$key]);
          break;
        }
        unset($parameters[$key]);
      }
    }

    if (!empty($facets)) {
      $merged = [];
      foreach ($facets as $facet) {
        foreach ($facet as $value) {
          array_push($merged, $value);
        }
      }
      $parameters[$filter_key] = $merged;
    }

    // Cleanup.
    foreach ($parameters as $key => $param) {
      if (substr($key, 0, 7) == 'facets_') {
        unset($parameters[$key]);
      }
    }

    return $parameters;
  }

}
