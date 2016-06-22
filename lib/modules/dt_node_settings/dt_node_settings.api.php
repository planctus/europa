<?php
/**
 * @file
 * Contains hook implementation documentation for dt_node_settings.
 */

/**
 * This function return the extra fields to be saved with the node.
 *
 * Return an array of fields to be added. All the fields will be added to the
 * dt_node_settings specific field group. The default values will be populated
 * with the database information, and have the fallback as defined in the hook.
 *
 * @param array $form
 *   The form that is acted on. Can be used to get more information or to add
 *   certain conditions.
 *
 * @return array
 *   Array with the form markup.
 */
function hook_dt_node_settings_config_fields($form) {
  return [
    'dt_editorial_linguistic_review' => [
      '#type' => 'checkbox',
      '#title' => 'Linguistic review',
      '#default_value' => FALSE,
      '#access' => user_access('dt editorial mark linguistic review'),
    ],
    'dt_editorial_content_review' => [
      '#type' => 'checkbox',
      '#title' => 'Content review',
      '#default_value' => FALSE,
      '#access' => user_access('dt editorial mark content review'),
    ],
  ];
}
