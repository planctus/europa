<?php

/**
 * @file
 * DT Access control plugin.
 *
 * @ingroup views_access_plugins
 * @codingStandardsIgnoreFile
 */

/**
 * Custom access mechanism for DT Editorial.
 */
class dt_editorial_access_plugin extends views_plugin_access {
  /**
   * Shows a message in the Views admin panel.
   */
  function summary_title() {
    return t('Configure');
  }

  /**
   * Determine if the current user has access or not.
   */
  function access($account) {
    return _dt_editorial_access_control($this->options['editorial-access-control'], $account);
  }

  /**
   * Access control.
   */
  function get_access_callback() {
    return array('_dt_editorial_access_control', [$this->options['editorial-access-control']]);
  }

  /**
   * Options definition.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['editorial-access-control'] = ['default' => []];
    return $options;
  }

  /**
   * The options form.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // List of og groups which contain role settings.
    $group_bundles = og_get_all_group_bundle();

    $form['description'] = [
      '#type' => 'item',
      '#title' => t('Organic Groups Roles Access Control'),
    ];
    $form['editorial-access-control'] = [
      '#tree' => TRUE,
      '#type' => 'fieldset',
      '#title' => t('OG Roles Access Control'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    ];
    // For every group bundle that contain roles.
    foreach ($group_bundles as $bundle_type_info => $bundle_type) {
      foreach ($bundle_type as $bundle_key => $bundle_name) {
        // Get list of roles in this group bundle.
        $group_roles = og_roles($bundle_type_info, $bundle_key);
        $form['editorial-access-control'][$bundle_key] = [
          '#group' => 'editorial-access-control',
          '#type' => 'checkboxes',
          '#title' => $bundle_name,
          '#default_value' => $this->options['editorial-access-control'][$bundle_key],
          '#options' => array_combine($group_roles, $group_roles),
        ];
      }
    }
  }

  /**
   * Submit handler to take selected values from the checkboxes.
   */
  function options_submit(&$form, &$form_state) {
    $access_groups = $form_state['values']['access_options']['editorial-access-control'];
    foreach ($access_groups as $group_name => $group_values) {
      // Save only the selected values.
      $form_state['values']['access_options']['editorial-access-control'][$group_name] = array_filter($group_values);
    }
  }

}
