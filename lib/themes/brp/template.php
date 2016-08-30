<?php

/**
 * @file
 * template.php
 */

use Drupal\dt_core_brp\BrpProps;

/**
 * Implements tempalate_preprocess_page().
 */
function brp_preprocess_page(&$variables) {
  // Prepare the url for the "external" homepage.
  global $language;
  $delimiter = variable_get('language_suffix_delimiter', '_');
  $suffix = $delimiter . $language->prefix;
  // Set a variable containing the external url to point to.
  $variables['front_page'] = 'http://ec.europa.eu/index' . $suffix . '.htm';
}

/**
 * Implements hook_context_load_alter().
 */
function brp_context_load_alter(&$context) {
  if ($context->name == 'dt_core_non_homepage_pages') {
    unset($context->conditions['path']);
  }
}

/**
 * Implements theme_pager_link().
 */
function brp_pager_link($variables) {

  $text = $variables['text'];
  $page_new = $variables['page_new'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];
  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  $query = array();
  if (count($parameters)) {
    $query = drupal_get_query_parameters($parameters, array());
  }
  if ($query_pager = pager_get_query_parameters()) {
    $query = array_merge($query, $query_pager);
  }

  // Set each pager link title.
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('« first') => t('Go to first page'),
        t('‹ previous') => t('Go to previous page'),
        t('next ›') => t('Go to next page'),
        t('last »') => t('Go to last page'),
      );
    }
    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text];
    }
    elseif (is_numeric($text)) {
      $attributes['title'] = t('Go to page @number', array('@number' => $text));
    }
  }

  /* @todo l() cannot be used here, since it adds an 'active' class based on the
   * path only (which is always the current path for pager links). Apparently,
   * none of the pager links is active at any time - but it should still be
   * possible to use l() here.
   * @see http://drupal.org/node/1410574
   */

  // Specific for BRP Pager feedback section.
  if (function_exists('_brp_initiative_is_feedback_path') && _brp_initiative_is_feedback_path() == 'feedback') {
    $alias = check_url(request_uri());
    $url_parts = explode('/', $alias);
    $base = [];
    foreach ($url_parts as $part) {
      if (strstr($part, BrpProps::BRP_INITIATIVE_FEEDBACK_PATH)) {
        array_push($base, BrpProps::BRP_INITIATIVE_FEEDBACK_PATH);
        break;
      }
      $base[] = $part;
    }
    $url = implode('/', $base);
    $attributes['href'] = url($url, array('query' => $query));
  }
  else {
    $attributes['href'] = url($_GET['q'], array('query' => $query));
  }

  return '<a' . drupal_attributes($attributes) . '>' . $text . '</a>';
}

/**
 * Returns HTML for status and/or error messages, grouped by type.
 *
 * An invisible heading identifies the messages for assistive technology.
 * Sighted users see a colored box. See http://www.w3.org/TR/WCAG-TECHS/H69.html
 * for info.
 *
 * @param array $variables
 *   An associative array containing:
 *   - display: (optional) Set to 'status' or 'error' to display only messages
 *     of that type.
 *
 * @return string
 *   The constructed HTML.
 *
 * @see theme_status_messages()
 *
 * @ingroup theme_functions
 */
function brp_status_messages($variables) {

  $display = $variables['display'];
  $output = '';

  $status_heading = array(
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
    'info' => t('Informative message'),
  );

  // Map Drupal message types to their corresponding Bootstrap classes.
  // @see http://twitter.github.com/bootstrap/components.html#alerts
  $status_class = array(
    'status' => 'success',
    'error' => 'danger',
    'warning' => 'warning',
    // Not supported, but in theory a module could send any type of message.
    // @see drupal_set_message()
    // @see theme_status_messages()
    'info' => 'info',
  );
  // Specific for  BRP for better user experience.
  $errors = drupal_get_messages('error');
  if ($errors) {
    // Search for default brp_form_error.
    if (array_search('brp_form_error', $errors['error'])) {
      // Clean the message.
      drupal_get_messages('error');
      // Set only one error message.
      drupal_set_message(t('@default_feedbackerror',
        ['@default_feedbackerror' => BrpProps::BRP_FEEDBACKFORM_ERROR_DEFAULT]), 'error');
      // Set the title of error messgae.
      $status_heading['error'] = t('@default_feedbackerror_title',
        ['@default_feedbackerror_title' => BrpProps::BRP_FEEDBACKFORM_ERROR_DEFAULT_TITLE]);
    }
  }
  foreach (drupal_get_messages($display) as $type => $messages) {
    $class = (isset($status_class[$type])) ? ' alert-' . $status_class[$type] : '';
    $output .= "<div class=\"alert alert-block$class messages messages--icon-center $type\">\n";
    $output .= "  <a class=\"close\" data-dismiss=\"alert\" href=\"#\">&times;</a>\n";

    if (!empty($status_heading[$type])) {
      $output .= '<h3><span class="sr-only">error message: </span>' . $status_heading[$type] . "</h3>\n";
    }

    if (count($messages) > 1) {
      $output .= " <ul>\n";
      foreach ($messages as $message) {
        $output .= '  <li>' . $message . "</li>\n";
      }
      $output .= " </ul>\n";
    }
    else {
      $output .= '<p>' . $messages[0] . '</p>';
    }

    $output .= "</div>\n";
  }
  return $output;
}
