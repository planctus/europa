<?php
/**
 * @file
 * Contains the methods to render the checkboxes.
 */

/**
 * Class FacetsInFiltersCheckbox.
 */
class FacetsInFiltersCheckbox extends FacetsInFiltersFilterBase {

  /**
   * {@inheritdoc}
   */
  public function execute() {
    $element = &$this->build[$this->facet['field alias']];

    // Get the identifier.
    $identifier = $this->getFacetIdentifier('checkbox');

    foreach ($element as &$option) {
      $title = $option['#markup'];
      $option['#type'] = 'markup';
      $option['#prefix'] = '<div class="checkbox">';
      $option['#suffix'] = '</div>';
      $option['#markup'] = '<input type="checkbox" ';
      $option['#markup'] .= 'name="' . $identifier . '" id="' . $identifier . '" ';
      if ($option['#active']) {
        $option['#markup'] .= 'checked="checked" ';
      }
      $option['#markup'] .= '/>';
      $option['#markup'] .= '<label for="' . $identifier . '">' . $title . '</label>';
    }

    // Take a copy.
    $clone = $element;

    // Recreate the array.
    $element = [];
    $element['facets'] = $clone;
  }

}
