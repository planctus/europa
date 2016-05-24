<?php
/**
 * @file
 * Definition of views_handler_filter_facet.
 */

/**
 * Exposes facet filters with views exposed forms.
 *
 * @ingroup views_filter_handlers
 * @codingStandardsIgnoreFile
 */
class ViewsHandlerFilterFacet extends views_handler_filter {

  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['facet'] = [
      'contains' => [
        'facet' => [
          'default' => FALSE,
        ],
        'label' => [
          'default' => FALSE,
        ],
      ],
    ];
    $options['exposed'] = ['default' => TRUE, 'bool' => TRUE];
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function admin_summary() {
    return isset($this->options['facet']['facet']) ? check_plain($this->options['facet']['facet']) : t('Not configured');
  }

  /**
   * {@inheritdoc}
   */
  public function expose_form(&$form, &$form_state) {
    parent::expose_form($form, $form_state);
    $form['expose']['label'] = [
      '#type' => 'textfield',
      '#default_value' => $this->options['expose']['label'],
      '#title' => t('Label'),
      '#size' => 40,
    ];
    $form['expose_button']['checkbox']['checkbox']['#disabled'] = TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $facets = facetapi_get_enabled_facets($this->getSearcher(), $this->getRealm());
    if (is_array($facets)) {
      $options = [];
      foreach ($facets as $key => $facet) {
        $options[$key] = $facet['label'];
      }

      $form['facet']['facet'] = [
        '#type' => 'select',
        '#default_value' => $this->options['facet']['facet'],
        '#title' => t('Facet'),
        '#options' => $options,
      ];
    }
    else {
      $form['facet']['facet']['#markup'] = t('No facets found');
    }
  }

  /**
   * {@inheritdoc}
   */
  public function query() {
    // Do nothing.
    return;
  }

  /**
   * {@inheritdoc}
   */
  public function exposed_form(&$form, &$form_state) {
    if (empty($this->options['exposed'])) {
      return;
    }

    if (is_null($this->getSearcher()) || !is_object($this->query)) {
      return;
    }

    // Build and execute the query so that the index is initialized.
    $this->query->build($this->view);
    $this->query->execute($this->view);
    // Get the field we need to process.
    $field = $this->options['facet']['facet'];

    // Build the realm.
    $adapter = facetapi_build_realm($this->getSearcher(), $this->getRealm());

    if (isset($adapter[$field])) {
      if (isset($adapter[$field][$field]['facets'])) {
        $value = $adapter[$field][$field]['facets'];
        unset($value['#attributes']['class']);
      }
      elseif (isset($adapter[$field][$field]['#theme'])) {
        unset($adapter[$field][$field]['#attributes']);
        $value = ['#markup' => drupal_render($adapter[$field][$field])];
      }
    }
    if (isset($value)) {
      $form[$this->options['expose']['identifier']] = $value;
    }
    return;
  }

  /**
   * {@inheritdoc}
   */
  public function accept_exposed_input($input) {
    return TRUE;
  }

  /**
   * Gets the searcher name.
   *
   * @return string
   */
  private function getSearcher() {
    if (is_object($this->query) && $query = $this->query->getSearchApiQuery()) {
      if ($index = $query->getIndex()) {
        $entity_info = $index->entityInfo();
        return $entity_info['module'] . '@' . $index->machine_name;
      }
    }
    // @todo: think of another way.
    return str_replace('_index_', '@', $this->view->base_table);
  }

  /**
   * Gets the searcher realm.
   *
   * @return string
   */
  private function getRealm() {
    return 'views';
  }
}
