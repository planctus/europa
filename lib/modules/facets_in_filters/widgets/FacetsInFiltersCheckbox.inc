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
  public function facetFieldType() {
    return 'checkboxes';
  }

  /**
   * {@inheritdoc}
   */
  public function execute() {
    $element = &$this->build[$this->facet['field alias']];

    // Get the identifier.
    $identifier = $this->getFacetIdentifier($this->facetFieldType());

    foreach ($element as &$option) {
      $title = $option['#markup'];
      // Add the count if the setting implies to do it.
      $title .= !$this->getSetting('hide_facet_count') && !empty($option['#count']) ? ' (' . $option['#count'] . ')' : '';
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

    $element['facets']['checkboxes'] = $clone;
    $this->addElementWrapper($element['facets']);
  }

}
