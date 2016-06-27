<?php
/**
 * @file
 * Contains the base method for FacetInFilters widgets.
 */

/**
 * Class FacetsInFiltersFilterBase.
 */
class FacetsInFiltersFilterBase extends FacetapiWidget {

  /**
   * {@inheritdoc}
   */
  public function execute() {
    parent::execute();
  }

  /**
   * Gets the full Facet identiefier to use.
   *
   * @param string $field_type
   *   The type of field.
   *
   * @return string
   *   The full identifier as a string.
   */
  public function getFacetIdentifier($field_type) {
    return 'facet__' . $field_type . '__' . $this->key;
  }

}
