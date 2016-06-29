<?php
/**
 * @file
 * Contains the base method for FacetInFilters widgets.
 */

/**
 * Class FacetsInFiltersFilterBase.
 */
abstract class FacetsInFiltersFilterBase extends FacetapiWidget {

  /**
   * {@inheritdoc}
   */
  public function init() {
    parent::init();
    $this->build['#facet_type'] = $this->facetFieldType();
    $this->build['#facet_data'] = $this->rawKeyValueData();
    $this->build['#facet_identifier'] = $this->getFacetIdentifier($this->facetFieldType());
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function execute() {
    parent::execute();
  }

  /**
   * Defines the #facet_type property.
   */
  abstract public function facetFieldType();

  /**
   * Sets the $rawKeyValue data.
   */
  public function rawKeyValueData() {
    $list = [];
    foreach ($this->build[$this->facet['field alias']] as $element) {
      $list[$element['#indexed_value']] = $element['#markup'];
    }
    return $list;
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

  /**
   * Gets the value of a setting.
   *
   * @param string $setting
   *   The name of the setting.
   *
   * @return mixed
   *   The value of the setting.
   */
  public function getSetting($setting) {
    return $this->settings->settings['hide_facet_count'];
  }

  /**
   * Adds the prefix and suffix to a form element.
   *
   * @param array $renderer
   *   The render array to apply the element to. Passed by reference.
   */
  public function addElementWrapper(&$renderer) {
    $renderer['#prefix'] = '<div id="' . drupal_clean_css_identifier('filters_in_facets_' . $this->settings->facet) . '">';
    $renderer['#suffix'] = '</div>';
  }

}
