<?php
/**
 * @file
 * Contains the methods to render the checkboxes.
 */

/**
 * Class FacetsInFiltersCheckbox.
 */
class FacetsInFiltersSelect extends FacetapiSelectDropdowns {

  /**
   * {@inheritdoc}
   */
  public function execute() {
    parent::execute();
    $element = &$this->build[$this->facet['field alias']];
    $name = drupal_clean_css_identifier('filters_in_facets_' . $this->settings->facet);
    $element['facets']['#name'] = 'facets_' . $this->key;
    $element['facets']['#prefix'] = '<div class="facet-trigger" id="' . $name . '">';
    $element['facets']['#suffix'] = '</div>';
    // We dont want to trigger the default js.
    unset($element['facets']['#attached']);
  }

}
