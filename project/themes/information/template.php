<?php
/**
 * @file
 * template.php
 */

/**
 * Returns an array with singular and plural form of a bundle.
 *
 * @param string $bundle
 *   Machine name of a bundle.
 *
 * @return array
 *   Containing $forms['singular'] and $forms['plural'].
 */
function _information_bundle_forms($bundle) {
  // Forming plurals for existing content types.
  $plurals = array(
    'announcement' => t("announcements"),
    'page' => t("pages"),
    'contact' => t("contacts"),
    'department' => t("departments"),
    'editorial_team' => t("editorial teams"),
    'file' => t("files"),
    'basic_page' => t("pages"),
    'person' => t("people"),
    'policy' => t("policies"),
    'policy_area' => t("policy areas"),
    'policy_implementation' => t("policy implementations"),
    'policy_input' => t("policy inputs"),
    'policy_keyfile' => t("policy key files"),
    'priority' => t("priorities"),
    'publication' => t("publications"),
    'class' => t("classes"),
    'topic' => t("topics"),
    'toplink' => t("top links"),
  );

  $singular = node_type_get_name($bundle);
  // If user preference for plural form - use it, otherwise use the label.
  if (isset($plurals[$bundle])) {
    $plural = $plurals[$bundle];
  }
  else {
    $plural = strtolower(t("@bundles", array('@bundle' => $singular)));
  }

  $forms = array(
    'singular' => strtolower($singular),
    'plural' => $plural,
  );

  return $forms;
}

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
  // Temporary variable that should be removed once the beta notification
  // is gone.
  $variables['node_about_beta'] = url('node/1108');
}

/**
 * Implements hook_preprocess_views_view().
 */
function information_preprocess_views_view(&$variables) {
  $view = $variables['view'];

  $content_type = array();
  $content_type_filters = $view->filter['type']->value;
  foreach ($content_type_filters as $filter) {
    $content_type = $filter;
  }

  $variables['items_count'] = '';

  // Checking if .listing exists in classes_array so that result count can be
  // displayed.
  if ((in_array('listing', $variables['classes_array'])) && isset($view->exposed_data)) {
    // Calculate the number of items displayed in a view listing.
    $total_rows = !$view->total_rows ? count($view->result) : $view->total_rows;

    $content_type_forms = _information_bundle_forms($content_type);

    if ($total_rows == 0) {
      $items_count = t("No @items", array('@items' => $content_type_forms['plural']));
    }
    else {
      $items_count = $total_rows . ' ' .
        format_plural($total_rows, $content_type_forms['singular'], $content_type_forms['plural']);
    }

    $variables['items_count'] = $items_count;
  }
}

/**
 * Implements hook_preprocess_field().
 */
function information_preprocess_field(&$variables) {
  // Changing label for the field to display stripped out values.
  switch ($variables['element']['#field_name']) {
    case 'field_core_ecorganisation':
      $field_value = $variables['element']['#items'][0]['value'];
      $field_value_stripped = explode(" (", $field_value);

      $variables['items'][0]['#markup'] = $field_value_stripped[0];
      break;
  }
}
