<?php
/**
 * @file
 * Cwt_core context_condition_node_taxonomy_uuid.inc.
 */

/**
 * Expose node taxonomy terms as a context condition.
 */
class context_condition_node_taxonomy_uuid extends context_condition_node {
  /**
   *
   */
  function condition_values() {
    $values = array();
    if (module_exists('taxonomy') && module_exists('uuid')) {
      foreach (taxonomy_get_vocabularies() as $vocab) {
        if (empty($vocab->tags)) {
          foreach (taxonomy_get_tree($vocab->vid) as $term) {
            $values[$term->uuid] = check_plain($term->name);
          }
        }
      }
    }
    return $values;
  }

  /**
   *
   */
  function condition_form($context) {
    $form = parent::condition_form($context);
    $form['#type'] = 'select';
    $form['#size'] = 12;
    $form['#multiple'] = TRUE;
    $vocabularies = taxonomy_get_vocabularies();
    $options = array();
    foreach ($vocabularies as $vid => $vocabulary) {
      $tree = taxonomy_get_tree($vid);
      if ($tree && (count($tree) > 0)) {
        $options[$vocabulary->name] = array();
        foreach ($tree as $term) {
          $options[$vocabulary->name][$term->uuid] = str_repeat('-', $term->depth) . $term->name;
        }
      }
    }
    $form['#options'] = $options;
    return $form;
  }

  /**
   *
   */
  function execute($node, $op) {
    // Build a list of each taxonomy reference field belonging to the bundle for the current node.
    $fields = field_info_fields();
    $instance_fields = field_info_instances('node', $node->type);
    $check_fields = array();
    foreach ($instance_fields as $key => $field_info) {
      if ($fields[$key]['type'] == 'taxonomy_term_reference') {
        $check_fields[] = $key;
      }
    }
    if ($this->condition_used() && !empty($check_fields)) {
      $terms_to_load = array();
      foreach ($check_fields as $field) {
        if ($terms = field_get_items('node', $node, $field)) {
          foreach ($terms as $term) {
            $terms_to_load[] = $term['tid'];
          }
        }
      }
      $terms = entity_load('taxonomy_term', $terms_to_load);
      foreach ($terms as $term) {
        foreach ($this->get_contexts($term->uuid) as $context) {
          // Check the node form option.
          if ($op === 'form') {
            $options = $this->fetch_from_context($context, 'options');
            if (!empty($options['node_form'])) {
              $this->condition_met($context, $term->uuid);
            }
          }
          else {
            $this->condition_met($context, $term->uuid);
          }
        }
      }
    }
  }

}
