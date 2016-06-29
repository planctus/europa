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
   * {@inheritdoc}
   */
  public function normalizeParams(array $params, $filter_key = 'f') {
    $parameters = drupal_get_query_parameters($params, array('q', 'page'));

    // Go over all of the options.
    foreach ($this->pregGrepKeys('/facet__(.*)/', $parameters) as $facet_key => $facet_value) {
      if ($this->getFieldType($facet_key) == 'checkboxes') {
        $facet_value = $facet_value == 'on' ? 1 : 0;
      }
      // Only add facets with a value.
      if (!empty($facet_value)) {
        $parameters[$filter_key][] = preg_replace('/^facet__(.*)__\B/', '', $facet_key, 1) . ':' . $facet_value;
      }
      // In all cases, we remove the key from the parameters.
      unset($parameters[$facet_key]);
    }

    return $parameters;
  }

  /**
   * Matches all the keys against a given pattern.
   *
   * @param string $pattern
   *   The pattern to match against.
   * @param array $input
   *   The string to search in.
   *
   * @return array
   *   Array list of matches.
   */
  private function pregGrepKeys($pattern, $input) {
    return array_intersect_key($input, array_flip(preg_grep($pattern, array_keys($input))));
  }

  /**
   * Returns the field type.
   *
   * @param string $identifier
   *   The string containing the full identifier.
   *
   * @return string
   *   The type of the field as a string.
   */
  private function getFieldType($identifier) {
    // Array that we will populate.
    $matches = [];
    // Matching pattern.
    preg_match('/^facet__(.*)__\B/', $identifier, $matches);
    return isset($matches[1]) ? $matches[1] : FALSE;
  }

}
