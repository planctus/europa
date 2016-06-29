<?php
/**
 * @file
 * Contains the methods to render the checkboxes.
 */

/**
 * Class FacetsInFiltersCheckbox.
 */
class FacetsInFiltersSelect extends FacetsInFiltersFilterBase {

  /**
   * {@inheritdoc}
   */
  public function facetFieldType() {
    return 'select';
  }

  /**
   * {@inheritdoc}
   */
  public function execute() {
    $element = &$this->build[$this->facet['field alias']];

    // Get the active item.
    $active_item = $this->getActiveItem();

    // Initialize the options.
    $options = [];

    // Add the default options.
    if (is_array($element)) {
      if ($active_item) {
        $options[] = $this->getResetOptionLabel();
      }
      else {
        $options[] = $this->getDefaultOptionLabel();
      }
    }

    // Go over the elements and populate the option array.
    foreach ($element as $value => $option) {
      $options[$value] = !$this->getSetting('hide_facet_count') && !empty($option['#count']) ? $option['#markup'] . ' (' . $option['#count'] . ')' : $option['#markup'];
    }

    // Recreate the array.
    $element = [];
    $element['facets'] = [
      '#type' => 'select',
      '#options' => $options,
      '#value' => $active_item,
      '#name' => $this->getFacetIdentifier($this->facetFieldType()),
    ];
    $this->addElementWrapper($element['facets']);
  }

  /**
   * Retrieve the facet reset option label.
   *
   * @return string
   *   The reset option label.
   */
  protected function getResetOptionLabel() {
    $reset_option_label = t('--Reset--');

    if (!empty($this->settings->settings['reset_option_label'])) {
      $reset_option_label = self::translateLabel('reset_option_label', $this->settings->settings['reset_option_label'], $this->key);
    }

    return $reset_option_label;
  }

  /**
   * Gets the active item value.
   *
   * @return mixed
   *   The value of the active element or false.
   */
  public function getActiveItem() {
    foreach ($this->build[$this->facet['field alias']] as $option) {
      if (!empty($option['#active'])) {
        return $option['#indexed_value'];
      }
    }
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function settingsForm(&$form, &$form_state) {
    parent::settingsForm($form, $form_state);

    $states = [
      'visible' => [
        'select[name="widget"]' => ['value' => $this->id],
      ],
    ];

    $form['widget']['widget_settings']['links'][$this->id]['default_option_label'] = [
      '#title' => t('Default option label'),
      '#type' => 'textfield',
      '#default_value' => !empty($this->settings->settings['default_option_label']) ? $this->settings->settings['default_option_label'] : '',
      '#states' => $states,
    ];
    $form['widget']['widget_settings']['links'][$this->id]['reset_option_label'] = [
      '#title' => t('Reset option label'),
      '#type' => 'textfield',
      '#default_value' => !empty($this->settings->settings['reset_option_label']) ? $this->settings->settings['reset_option_label'] : '',
      '#states' => $states,
    ];
    $form['widget']['widget_settings']['links'][$this->id]['submit_page'] = [
      '#type' => 'textfield',
      '#title' => t('Force this facet to submit to a specific search page'),
      '#description' => t('This facet will always submit to the page it is on if left empty.'),
      '#default_value' => !empty($this->settings->settings['submit_page']) ? $this->settings->settings['submit_page'] : '',
      '#states' => $states,
    ];
    $form['widget']['widget_settings']['links'][$this->id]['hide_facet_count'] = [
      '#type' => 'checkbox',
      '#title' => t('Hide the facet count'),
      '#default_value' => !empty($this->settings->settings['hide_facet_count']) ? $this->settings->settings['hide_facet_count'] : FALSE,
      '#states' => $states,
    ];

    $form['#submit'] = empty($form['#submit']) ? [] : $form['#submit'];
    $form['#submit'][] = 'facetapi_select_facet_settings_form_submit';
  }

  /**
   * Retrieve the facet default option label.
   *
   * @return string
   *   The default option label.
   */
  protected function getDefaultOptionLabel() {
    $default_option_label = t('--Choose--');

    if (!empty($this->settings->settings['default_option_label'])) {
      $default_option_label = self::translateLabel('default_option_label', $this->settings->settings['default_option_label'], $this->key);
    }

    return $default_option_label;
  }

  /**
   * Helper function to integrate with the i18n_string_translate function.
   *
   * @param string $name
   *   Translation context.
   * @param string $string
   *   The raw db value for the given property.
   *
   * @return string
   *   If i18n_string is available the translated string is returned, otherwise,
   *   the supplied string is returned.
   */
  public static function translateLabel($name, $string, $key) {
    if (!function_exists('i18n_string_translate')) {
      return $string;
    }

    $i18n_name = [
      'facetapi_select',
      $name,
      str_replace(':', '_', $key),
      'label',
    ];
    return i18n_string_translate($i18n_name, $string);
  }

}
