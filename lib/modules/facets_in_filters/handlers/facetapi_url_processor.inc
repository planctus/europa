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
 */
class FacetapiUrlViews extends FacetapiUrlProcessorStandard {

  /**
   * Implements FacetapiUrlProcessor::normalizeParams().
   *
   * Strips the "q" and "page" variables from the params array.
   */
  public function normalizeParams(array $params, $filter_key = 'f') {
    $parameters = drupal_get_query_parameters($params, array('q', 'page'));
    if (isset($parameters['facets'])) {
      $facets = drupal_parse_url($parameters['facets']);
      if (isset($facets['query'][$filter_key])) {
        $parameters[$filter_key] = $facets['query'][$filter_key];
        unset($parameters['facets']);
      }
    }
    return $parameters;
  }

}
