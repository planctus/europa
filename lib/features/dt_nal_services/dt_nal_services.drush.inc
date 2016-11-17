<?php

/**
 * @file
 * Drush code for the module.
 */

/**
 * Implements hook_drush_command().
 */
function dt_nal_services_drush_command() {

  $items['dt-nal-services'] = [
    'description' => t('Drupal commands for NAL services.'),
    'aliases' => ['nal'],
    'callback' => 'drush_nal_services',
    'arguments' => [
      'op' => 'Operation type.',
    ],
    'options' => [
      'service' => 'Select a service to apply a function to.',
    ],
  ];

  return $items;
}

/**
 * Callback for dt-nal-services command.
 *
 * @param string $op
 *   Type of operation to run.
 */
function drush_nal_services($op = 'i') {
  // Possible operations.
  $op_possible = [
    'import',
    'translate',
    'help',
    'h',
    'i',
    't',
  ];
  // Possible service importers.
  $services_possible = [
    'all' => dt('All'),
    'corporate_bodies' => dt('Corporate bodies'),
    'countries' => dt('Countries'),
    'resource_types' => dt('Resource types'),
  ];
  // Take user input.
  $service = drush_get_option('service', 'all');

  if (!in_array($service, $services_possible)) {
    $service = drush_choice($services_possible,
      dt('Please select a service:'));
  }

  switch ($op) {
    case 'import':
    case 'i':
      // Execute all importers.
      if ($service == 'all') {
        drush_invoke('dt-nal-corporate-bodies-import');
        drush_invoke('dt-nal-resource-types-import');
        drush_invoke('dt-nal-countries-import');
      }
      else {
        switch ($service) {
          case 'corporate_bodies':
            drush_invoke('dt-nal-corporate-bodies-import');
            break;

          case 'resource_types':
            drush_invoke('dt-nal-resource-types-import');
            break;

          case 'countries':
            drush_invoke('dt-nal-countries-import');
            break;
        }
      }
      break;

    case 'translate':
    case 't':
      // Execute all translators.
      if ($service == 'all') {
        drush_invoke('dt-nal-corporate-bodies-translate');
        drush_invoke('dt-nal-resource-types-translate');
        drush_invoke('dt-nal-countries-translate');
        exit();
      }
      else {
        // Execute specific translator.
        switch ($service) {
          case 'corporate_bodies':
            drush_invoke('dt-nal-corporate-bodies-translate');
            break;

          case 'resource_types':
            drush_invoke('dt-nal-resource-types-translate');
            break;

          case 'countries':
            drush_invoke('dt-nal-countries-translate');
            break;
        }
      }

      break;

    // Fallback if no operation is provided.
    default:
      drush_set_error(dt('Operation not available. Please choose between: @options',
        [
          '@options' => implode(', ', $op_possible),
        ]));
      break;
  }

}
