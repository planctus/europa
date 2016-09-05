<?php

/**
 * @file
 * template.php
 */

/**
 * Implements hook_form_BASE_FORM_ID_alter().
 */
function information_form_views_exposed_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'views_exposed_form') {
    $form['type']['#options']['All'] = t("All types");
    $form['department']['#options']['All'] = t("All departments");
    $form['policy_area']['#options']['All'] = t("All policy areas");
  }
}

/**
 * Implements hook_preprocess_page().
 */
function information_preprocess_page(&$variables) {
  // Adding a modifier for a specific case that will change the logo.
  if (drupal_is_front_page()) {
    $variables['logo_classes'] .= ' logo--logotype';
    $variables['node']->ceiling = 'ceiling';
  }
}
