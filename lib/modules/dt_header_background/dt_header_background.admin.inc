<?php

/**
 * @file
 * Code for the header background admin.
 */

/**
 * Prepare data for the dt_header_background.
 */
function _dt_header_background_prepare_options($filter = FALSE) {
  // Get a list of the existing content types.
  $content_types = node_type_get_types();
  $selected = variable_get('dt_header_background_which_content_type', []);
  $types = [];
  $check_options = [];
  $options = [];

  foreach ($content_types as $machine_name => $content_type) {
    // Exclude helper content types from the list.
    $helper = variable_get('dt_node_settings_helper_node_type_' . $machine_name, 'not_found');

    if (!$helper || $helper == 'not_found') {
      // Default values for the which_content_type form element.
      if (field_info_instance('node', 'field_core_header_image', $machine_name) !== NULL) {
        $check_options[] = $machine_name;
      }

      // Options for all the primary content types.
      $options[$machine_name] = $content_type->name;

      // Active content types that will have the override option.
      if (in_array($machine_name, $selected) || in_array($machine_name, $check_options)) {
        $types[$machine_name] = [
          'name' => $content_type->name,
          'value' => variable_get('dt_header_background_' . $machine_name, FALSE),
        ];
      }
    }
  }

  $data = [
    'types' => $types,
    'options' => $options,
    'check_options' => $check_options,
  ];

  if ($filter) {
    return $data[$filter];
  }

  return $data;
}

/**
 * Implements hook_form_alter().
 */
function dt_header_background_form_alter(&$form, &$form_state) {
  if ($form['#form_id'] == 'system_theme_settings') {
    // Get informations about content types.
    $data = _dt_header_background_prepare_options();
    // Build the form.
    $form['header'] = [
      '#type' => 'fieldset',
      '#title' => t('DT Header background'),
    ];

    $form['header']['dt_header_background_default'] = [
      '#type' => 'managed_file',
      '#title' => t('Default image for the header background'),
      '#upload_validators' => [
        'file_validate_is_image' => [],
        'file_validate_extensions' => ['png jpg jpeg gif'],
        'file_validate_image_resolution' => ['0', '2400x900'],
      ],
      '#progress_message' => t('Uploading the image'),
      '#progress_indicator' => 'throbber',
      '#default_value' => variable_get('dt_header_background_default', FALSE),
      '#required' => FALSE,
      '#upload_location' => 'public://',
      '#weight' => 0,
      '#theme' => 'theme_image_widget',
      '#description' => t('Upload a file, allowed extensions: jpg, jpeg, png, gif. Minimal image size is 2400x900px'),
    ];

    $form['header']['views'] = [
      '#type' => 'fieldset',
      '#title' => t('Activate the Header Background on views page'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    ];

    $form['header']['views']['activate_listing'] = [
      '#type' => 'checkbox',
      '#title' => t('Would you like to be able to see this default image also in listing pages?'),
      '#default_value' => variable_get('dt_header_background_activate_listing', FALSE),
    ];

    if (!empty($data['options'])) {
      $form['header']['content_types'] = [
        '#type' => 'fieldset',
        '#title' => t('Select in which content types you want to show the default header background image.'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      ];

      $form['header']['content_types']['checkall'] = [
        '#type' => 'checkbox',
        '#title' => t('Select / Unselect all'),
        '#attributes' => ['onclick' => 'checkAll(this);'],
        '#weight' => -1,
      ];

      $form['header']['content_types']['which_content_type'] = [
        '#type' => 'checkboxes',
        '#options' => $data['options'],
        '#description' => t('The content types using the header background field are selected and not editable by default.'),
        '#default_value' => variable_get('dt_header_background_which_content_type', $data['check_options']),
      ];

      // Disable the default content type options.
      foreach ($data['check_options'] as $disable) {
        $form['header']['content_types']['which_content_type'][$disable]['#disabled'] = TRUE;
      }
    }

    $form['header']['overridable'] = [
      '#type' => 'fieldset',
      '#title' => t('Override Header Background image basing on content types'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    ];

    $form['header']['overridable']['per_content_type'] = [
      '#type' => 'checkbox',
      '#title' => t('Would you like to be able to override the default image on a content type basis?'),
      '#default_value' => variable_get('dt_header_background_per_content_type', FALSE),
    ];

    $form['header']['overrides'] = [
      '#type' => 'fieldset',
      '#title' => t('Overrides per content type'),
      '#description' => t('This is the list of content types where you can set a different default background image for the header'),
      '#prefix' => '<div id="dt_header_background_overrides">',
      '#suffix' => '</div>',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#states' => [
        'visible' => [
          ':input[name="per_content_type"]' => ['checked' => TRUE],
        ],
      ],
    ];

    $i = 1;
    foreach ($data['types'] as $machine_name => $header_background) {
      if ($header_background['value']) {
        $form_state['storage']['dt_header_background_' . $machine_name] = $header_background['value'];
      }

      $form['header']['overrides']['dt_header_background_' . $machine_name] = [
        '#type' => 'managed_file',
        '#title' => t('Default image for the header background for the %ct content type', ['%ct' => $header_background['name']]),
        '#upload_validators' => [
          'file_validate_is_image' => [],
          'file_validate_extensions' => ['png jpg jpeg gif'],
          'file_validate_image_resolution' => ['0', '2400x900'],
        ],
        '#progress_message' => t('Uploading the image'),
        '#progress_indicator' => 'throbber',
        '#default_value' => $header_background['value'],
        '#required' => FALSE,
        '#upload_location' => 'public://',
        '#weight' => $i,
        '#theme' => 'theme_image_widget',
        '#description' => t('Upload a file, allowed extensions: jpg, jpeg, png, gif. Minimal image size is 2400x900px'),
      ];

      $i++;
    }

    $form['header']['reset'] = [
      '#type' => 'fieldset',
      '#title' => t('Delete existing Header Background css files'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    ];

    $form['header']['reset']['button'] = [
      '#type' => 'submit',
      '#value' => 'Remove existing css files',
      '#prefix' => '<div id="header-reset">',
      '#suffix' => '<div class="description">' . t("Remove all the css files if needed.") . '</div></div>',
      '#ajax' => [
        'callback' => '_dt_header_background_clear_css',
        'event' => 'click',
        'wrapper' => 'header-reset',
        'effect' => 'fade',
        'method' => 'replace',
      ],
    ];

    drupal_add_js("
      function checkAll(e){
        var elements = document.getElementById('edit-which-content-type').getElementsByTagName('input'), z = 0;

        for(z=0; z<elements.length; z++){
          if(elements[z].type == 'checkbox' && elements[z].name != 'checkall'){
            elements[z].checked = e.checked;
          }
        }
      }
    ", 'inline');

    // Add the default to the storage if needed.
    $default = variable_get('dt_header_background_default', FALSE);

    if ($default) {
      $form_state['storage']['dt_header_background_default'] = $default;
    }

    $form['#submit'][] = "_dt_header_background_theme_settings_submit";
  }
}

/**
 * Custom submit function for the theme setting form.
 */
function _dt_header_background_theme_settings_submit(&$form, &$form_state) {
  // Relevant inputs.
  $keys = preg_grep('#dt_header_background_(.*?)#', array_keys($form_state['values']));

  foreach ($keys as $key) {
    $ct = str_replace('dt_header_background_', '', $key);
    // User uploaded a new image or there is already a value.
    $fids[$ct] = $form_state['values'][$key] == 0 ? FALSE : $form_state['values'][$key];
    // We store the previous value to be able to delete the css file.
    $prevs[$ct] = isset($form_state['storage'][$key]) ? $form_state['storage'][$key] : FALSE;

    if ($fids[$ct]) {
      if ($fids[$ct] != $prevs[$ct]) {
        _dt_header_background_set_default_header_background($ct, $fids[$ct]);
      }
    }
    // There's no default header background.
    else {
      // Let's check if it has been removed in this submission.
      if ($prevs[$ct]) {
        $file = new stdClass();
        $file->fid = $prevs[$ct];
        dt_header_background_file_delete($file);
        file_usage_delete($file, 'dt_header_background');
        variable_del($key);
      }
    }
  }

  // Save the variable for the "overrides" checkbox.
  $override = $form_state['values']['per_content_type'] == 1 ? TRUE : FALSE;
  variable_set('dt_header_background_per_content_type', $override);

  // Save the variable for the selected content types.
  $activate_listing = $form_state['values']['activate_listing'] == 1 ? TRUE : FALSE;
  variable_set('dt_header_background_activate_listing', $activate_listing);

  // Save the variable for the selected content types.
  $selected_ct = array_keys(array_filter($form_state['values']['which_content_type']));
  // We disable the default ct options so we don't have them in the form values.
  $check_options = _dt_header_background_prepare_options('check_options');
  $which_content_type = array_merge($selected_ct, $check_options);
  variable_set('dt_header_background_which_content_type', $which_content_type);
}

/**
 * Implements hook_file_delete().
 */
function dt_header_background_file_delete($file) {
  $fid = $file->fid;
  $file = drupal_realpath(DT_HEADER_BACKGROUND_DIR) . '/header_background_' . $fid . '.css';
  if (file_exists($file)) {
    drupal_unlink($file);
  }
}

/**
 * Helper function to delete all the generated css files.
 */
function _dt_header_background_clear_css() {
  $uri = DT_HEADER_BACKGROUND_DIR . '/header_background*.css';
  $dir = drupal_realpath($uri);
  // Remove all the css files that this module has generated.
  $deleted_files = 0;
  $not_deleted = 0;
  foreach (glob($dir) as $file) {
    if (is_writable($file)) {
      drupal_unlink($file);
      $deleted_files++;
    }
    else {
      $not_deleted++;
    }
  }

  // Build the message to return.
  $markup = t('%deleted_files Css files have been deleted', ['%deleted_files' => $deleted_files]);
  // If some files has not been deleted because of permissions, warn the user.
  if ($not_deleted > 0) {
    $markup .= t('while %not_deleted files could not be deleted because of permission issues, check with your administrator, please.', ['%not_deleted' => $not_deleted]);
  }

  // Return an information about deletion.
  $form['reset'] = [
    '#type' => 'markup',
    '#markup' => $markup,
  ];

  return $form['reset'];
}
