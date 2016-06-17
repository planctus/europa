<?php
/**
 * @file
 * Contains the methods to render the checkboxes.
 */

/**
 * Class FacetsInFiltersCheckbox.
 */
class FacetsInFiltersCheckbox extends FacetapiWidget {

  /**
   * {@inheritdoc}
   */
  public function execute() {
    drupal_add_js(drupal_get_path('module', 'facets_in_filters') . '/js/FacetsInFilters.js');
    $element = &$this->build[$this->facet['field alias']];

    foreach ($element as $ind => &$option) {
      $value = url(current_path(), ['query' => $option['#query']]);
      $name = 'facets_' . $this->key . '_' . $ind;
      $title = $option['#markup'];
      $option['#type'] = 'markup';
      $option['#prefix'] = '<div class="checkbox">';
      $option['#suffix'] = '</div>';
      $option['#markup'] = '<input type="checkbox" ';
      $option['#markup'] .= 'name="' . $name . '" id="' . $name . '" ';
      if ($option['#active']) {
        $option['#markup'] .= 'checked="checked" ';
      }
      $option['#markup'] .= 'value="' . $value . '"/>';
      $option['#markup'] .= '<label for="' . $name . '">' . $title . '</label>';
      $option['#markup'] .= '<input type="hidden" value="' . $value . '" name="' . $name . '" id="' . $name . '" />';
    }

    // Take a copy.
    $clone = $element;

    // Recreate the array.
    $element = [];
    $element['facets'] = $clone;
    $element['facets']['#prefix'] = '<div class="facet-trigger" id="' . drupal_clean_css_identifier('filters_in_facets_' . $this->settings->facet) . '">';
    $element['facets']['#suffix'] = '</div>';
  }

}
