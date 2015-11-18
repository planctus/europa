<?php
/**
 * @file
 * Administrative pages for Dt development tools module.
 */

function dt_devtools_admin() {
  $form = array();

  $form['dt_devtools_webtools'] = array(
    '#type' => 'fieldset',
    '#title' => t('Webtools settings'),
    '#weight' => 0,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $weight = 0;
  foreach (_dt_devtools_libs() as $lib) {
    $form['dt_devtools_webtools']['dt_devtools_webtools_' . $lib['lib_name']] = array(
      '#type' => 'checkbox',
      '#title' =>  $lib['title'],
      '#description' =>  $lib['description'],
      '#weight' => $weight,
      '#default_value' =>  variable_get('dt_devtools_webtools_'. $lib['lib_name'], FALSE),
    );
    $weight++;
  }

  return system_settings_form($form);
}