<?php

/**
 * @file
 * Handler for node source language path field.
 */

module_load_include('inc', 'views', 'modules/node/views_handler_field_node_path');

/**
 * Field handler to present the path to the node in its source language.
 *
 * @ingroup views_field_handlers
 */
class cwt_team_handler_field_node_source_language_path extends views_handler_field_node_path {

  /**
   * {@inheritdoc}
   */
  function construct() {
    parent::construct();
    $this->additional_fields['language'] = 'language';
  }

  /**
   * {@inheritdoc}
   */
  function render($values) {
    $nid = $this->get_value($values, 'nid');
    $language = i18n_language_load($this->get_value($values, 'language'));
    return url("node/$nid", array(
      'absolute' => $this->options['absolute'],
      'language' => $language,
    ));
  }

}
