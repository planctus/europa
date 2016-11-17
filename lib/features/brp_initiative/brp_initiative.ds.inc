<?php

/**
 * @file
 * brp_initiative.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function brp_initiative_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|brp_initiative|add_feedback';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'brp_initiative';
  $ds_fieldsetting->view_mode = 'add_feedback';
  $ds_fieldsetting->settings = array(
    'brp_feedbackfieldfeedbackform' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'brp_feedbackfield_initiative_tile' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|brp_initiative|add_feedback'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|brp_initiative|add_report_feedback';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'brp_initiative';
  $ds_fieldsetting->view_mode = 'add_report_feedback';
  $ds_fieldsetting->settings = array(
    'brp_feedbackfieldreportfeedbackform' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'brp_feedbackfield_organisation' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'brp_feedbackfield_tr_number' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'brp_feedbackfield_author' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'brp_feedbackfield_org_size' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'brp_feedbackfield_header' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'page_type' => '2',
        'ft' => array(),
      ),
    ),
    'brp_feedbackfield_country' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'brp_feedbackfield_submittedon' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'brp_feedbackfield_initiativeid' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'brp_fb_id' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|brp_initiative|add_report_feedback'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|brp_initiative|detail_feedback';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'brp_initiative';
  $ds_fieldsetting->view_mode = 'detail_feedback';
  $ds_fieldsetting->settings = array(
    'brp_feedbackfield_organisation' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'brp_feedbackfield_tr_number' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'brp_feedbackfield_author' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'brp_feedbackfield_user_type' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'brp_feedbackfield_org_size' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'brp_feedbackfield_header' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'page_type' => '1',
        'ft' => array(),
      ),
    ),
    'brp_feedbackfield_country' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'brp_feedbackfield_submittedon' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'brp_feedbackfield_initiativeid' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'brp_feedbackfield_feedback' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'brp_fb_id' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|brp_initiative|detail_feedback'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|brp_initiative|feedback';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'brp_initiative';
  $ds_fieldsetting->view_mode = 'feedback';
  $ds_fieldsetting->settings = array(
    'brp_feedbackfieldfield_simple' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'rows' => '10',
        'trim' => '300',
        'ft' => array(),
      ),
    ),
    'brp_feedbackfield_header' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'page_type' => '0',
        'ft' => array(),
      ),
    ),
    'brp_feedbackfield_button' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|brp_initiative|feedback'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|brp_initiative|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'brp_initiative';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'type_of_initiative' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'meta__item meta__item--type',
          'fi-at' => '',
          'fi-def-at' => TRUE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'in_page_navigation' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'brp_initiative_feedback_block' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'brp_initiative_attachments' => array(
      'weight' => '14',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'brp_feedbackfieldfield_simple' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'rows' => '6',
        'trim' => '200',
        'ft' => array(),
      ),
    ),
    'field_brp_inve_leading_service' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Department',
        ),
      ),
    ),
    'field_brp_inve_resource_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Type of initiative',
        ),
      ),
    ),
    'field_core_description' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Full title',
        ),
      ),
    ),
  );
  $export['node|brp_initiative|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|brp_initiative|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'brp_initiative';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'feedback_period' => array(
      'weight' => '6',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_nexteuropa_formatters_h4label_item',
          'lb' => 'Feedback period',
        ),
      ),
    ),
    'brp_initiative_status_label' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_brp_inve_leading_service' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_nexteuropa_formatters_h4label_item',
          'lb' => 'Department',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_brp_inve_reference' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_nexteuropa_formatters_h4label_item',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_brp_inve_resource_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_nexteuropa_formatters_h4label_item',
          'lb' => 'Type of initiative',
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['node|brp_initiative|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function brp_initiative_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'feedback_period';
  $ds_field->label = 'Feedback period';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'brp_initiative|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '[node:field-brp-inve-fb-start-date:ec_date_j_f_y] - [node:field-brp-inve-fb-end-date:ec_date_j_f_y]',
      'format' => 'plain_text',
    ),
    'use_token' => 1,
  );
  $export['feedback_period'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'type_of_initiative';
  $ds_field->label = 'Type of initiative';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'brp_initiative|full';
  $ds_field->properties = array(
    'code' => array(
      'value' => '[node:field-brp-inve-resource-type:i18n-name]',
      'format' => 'plain_text',
    ),
    'use_token' => 1,
  );
  $export['type_of_initiative'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function brp_initiative_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|brp_initiative|add_feedback';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'brp_initiative';
  $ds_layout->view_mode = 'add_feedback';
  $ds_layout->layout = 'ne_bootstrap_3_9_stacked_conditional';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'brp_feedbackfield_initiative_tile',
      ),
      'central' => array(
        1 => 'brp_feedbackfieldfeedbackform',
      ),
    ),
    'fields' => array(
      'brp_feedbackfield_initiative_tile' => 'left_header',
      'brp_feedbackfieldfeedbackform' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left_header' => 'div',
      'right_header' => 'div',
      'top' => 'div',
      'left' => 'div',
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|brp_initiative|add_feedback'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|brp_initiative|add_report_feedback';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'brp_initiative';
  $ds_layout->view_mode = 'add_report_feedback';
  $ds_layout->layout = 'ne_bootstrap_3_9_stacked_conditional';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'brp_fb_id',
        2 => 'brp_feedbackfield_organisation',
        3 => 'brp_feedbackfield_org_size',
        4 => 'brp_feedbackfield_tr_number',
        5 => 'brp_feedbackfield_country',
        6 => 'brp_feedbackfield_submittedon',
        7 => 'brp_feedbackfield_author',
        8 => 'brp_feedbackfield_initiativeid',
      ),
      'left_header' => array(
        1 => 'brp_feedbackfield_header',
      ),
      'central' => array(
        9 => 'brp_feedbackfieldreportfeedbackform',
      ),
    ),
    'fields' => array(
      'brp_fb_id' => 'top',
      'brp_feedbackfield_header' => 'left_header',
      'brp_feedbackfield_organisation' => 'top',
      'brp_feedbackfield_org_size' => 'top',
      'brp_feedbackfield_tr_number' => 'top',
      'brp_feedbackfield_country' => 'top',
      'brp_feedbackfield_submittedon' => 'top',
      'brp_feedbackfield_author' => 'top',
      'brp_feedbackfield_initiativeid' => 'top',
      'brp_feedbackfieldreportfeedbackform' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left_header' => 'div',
      'right_header' => 'div',
      'top' => 'div',
      'left' => 'div',
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|brp_initiative|add_report_feedback'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|brp_initiative|detail_feedback';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'brp_initiative';
  $ds_layout->view_mode = 'detail_feedback';
  $ds_layout->layout = 'ne_bootstrap_3_9_stacked_conditional';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'brp_feedbackfield_header',
      ),
      'top' => array(
        1 => 'brp_fb_id',
        2 => 'brp_feedbackfield_submittedon',
        3 => 'brp_feedbackfield_author',
        4 => 'brp_feedbackfield_user_type',
        5 => 'brp_feedbackfield_organisation',
        6 => 'brp_feedbackfield_org_size',
        7 => 'brp_feedbackfield_tr_number',
        8 => 'brp_feedbackfield_country',
        9 => 'brp_feedbackfield_initiativeid',
      ),
      'central' => array(
        10 => 'brp_feedbackfield_feedback',
      ),
    ),
    'fields' => array(
      'brp_feedbackfield_header' => 'left_header',
      'brp_fb_id' => 'top',
      'brp_feedbackfield_submittedon' => 'top',
      'brp_feedbackfield_author' => 'top',
      'brp_feedbackfield_user_type' => 'top',
      'brp_feedbackfield_organisation' => 'top',
      'brp_feedbackfield_org_size' => 'top',
      'brp_feedbackfield_tr_number' => 'top',
      'brp_feedbackfield_country' => 'top',
      'brp_feedbackfield_initiativeid' => 'top',
      'brp_feedbackfield_feedback' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left_header' => 'div',
      'right_header' => 'div',
      'top' => 'div',
      'left' => 'div',
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|brp_initiative|detail_feedback'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|brp_initiative|feedback';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'brp_initiative';
  $ds_layout->view_mode = 'feedback';
  $ds_layout->layout = 'ne_bootstrap_3_9_stacked_conditional';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'brp_feedbackfield_header',
        1 => 'brp_feedbackfield_button',
      ),
      'central' => array(
        2 => 'brp_feedbackfieldfield_simple',
      ),
    ),
    'fields' => array(
      'brp_feedbackfield_header' => 'left_header',
      'brp_feedbackfield_button' => 'left_header',
      'brp_feedbackfieldfield_simple' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left_header' => 'div',
      'right_header' => 'div',
      'top' => 'div',
      'left' => 'div',
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|brp_initiative|feedback'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|brp_initiative|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'brp_initiative';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ne_bootstrap_3_9_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'group_initiative_meta',
        1 => 'type_of_initiative',
        2 => 'title',
      ),
      'left' => array(
        3 => 'in_page_navigation',
      ),
      'central' => array(
        4 => 'group_inve_details',
        5 => 'group_inve_attachments',
        6 => 'brp_initiative_feedback_block',
        7 => 'brp_feedbackfieldfield_simple',
        8 => 'group_inve_givefeedback',
        9 => 'group_inve_recentfeedback',
        10 => 'field_brp_inve_reference',
        11 => 'field_brp_inve_resource_type',
        12 => 'field_core_description',
        13 => 'field_brp_inve_leading_service',
        14 => 'field_brp_inve_committee',
        15 => 'field_brp_inve_expert_group',
        16 => 'brp_initiative_attachments',
      ),
    ),
    'fields' => array(
      'group_initiative_meta' => 'left_header',
      'type_of_initiative' => 'left_header',
      'title' => 'left_header',
      'in_page_navigation' => 'left',
      'group_inve_details' => 'central',
      'group_inve_attachments' => 'central',
      'brp_initiative_feedback_block' => 'central',
      'brp_feedbackfieldfield_simple' => 'central',
      'group_inve_givefeedback' => 'central',
      'group_inve_recentfeedback' => 'central',
      'field_brp_inve_reference' => 'central',
      'field_brp_inve_resource_type' => 'central',
      'field_core_description' => 'central',
      'field_brp_inve_leading_service' => 'central',
      'field_brp_inve_committee' => 'central',
      'field_brp_inve_expert_group' => 'central',
      'brp_initiative_attachments' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left_header' => 'div',
      'right_header' => 'div',
      'top' => 'div',
      'left' => 'div',
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|brp_initiative|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|brp_initiative|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'brp_initiative';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ne_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'group_initiative_meta',
        1 => 'brp_initiative_status_label',
        2 => 'title_field',
        3 => 'field_brp_inve_reference',
        4 => 'field_brp_inve_resource_type',
        5 => 'field_brp_inve_leading_service',
        6 => 'feedback_period',
        7 => 'field_brp_inve_fb_count',
      ),
    ),
    'fields' => array(
      'group_initiative_meta' => 'main',
      'brp_initiative_status_label' => 'main',
      'title_field' => 'main',
      'field_brp_inve_reference' => 'main',
      'field_brp_inve_resource_type' => 'main',
      'field_brp_inve_leading_service' => 'main',
      'feedback_period' => 'main',
      'field_brp_inve_fb_count' => 'main',
    ),
    'classes' => array(),
    'wrappers' => array(
      'main' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|brp_initiative|teaser'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function brp_initiative_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'add_feedback';
  $ds_view_mode->label = 'Add feedback';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['add_feedback'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'add_report_feedback';
  $ds_view_mode->label = 'Add report feedback';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['add_report_feedback'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'detail_feedback';
  $ds_view_mode->label = 'Detail feedback';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['detail_feedback'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'feedback';
  $ds_view_mode->label = 'feedback';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['feedback'] = $ds_view_mode;

  return $export;
}
