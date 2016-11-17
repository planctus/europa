<?php
/**
 * @file
 * dt_call_for_proposal_default.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_call_for_proposal_default_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|call_for_proposal|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'call_for_proposal';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'content_type_label' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'meta__item meta__item--type',
          'fi-at' => '',
          'fi-def-at' => FALSE,
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
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'hr_1' => array(
      'weight' => '29',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'social_bookmark_webtools' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'dt_call_for_proposal_status_message' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'dt_call_for_proposal_status_message_formatter',
    ),
    'dt_call_for_proposal_published' => array(
      'weight' => '24',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Publication date',
        ),
      ),
    ),
    'dt_call_for_proposal_meta' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_cfp_call_reference' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Reference',
        ),
      ),
    ),
    'field_core_topics' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Topic',
        ),
      ),
    ),
    'field_cfp_program' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Funding programme',
        ),
      ),
    ),
    'field_core_links' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Related',
          'lb-col' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => 'listing--title',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'field_grants_awarded_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Results',
        ),
      ),
    ),
    'field_core_deadlines' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|call_for_proposal|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|call_for_proposal|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'call_for_proposal';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'dt_call_for_proposal_deadline' => array(
      'weight' => '4',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Deadline',
        ),
      ),
    ),
    'field_cfp_call_reference' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Reference',
        ),
      ),
    ),
    'field_cfp_status' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_nexteuropa_formatters_meta_item',
          'lb' => 'Call status',
          'meta_modifier' => 'meta__item--type',
        ),
      ),
    ),
    'field_core_topics' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_cfp_program' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Programme',
        ),
      ),
    ),
  );
  $export['node|call_for_proposal|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_call_for_proposal_default_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|call_for_proposal|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'call_for_proposal';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ne_bootstrap_3_9_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'dt_call_for_proposal_meta',
        2 => 'group_cfp_meta',
        4 => 'content_type_label',
        5 => 'title',
        6 => 'field_core_introduction',
      ),
      'central' => array(
        1 => 'field_core_files',
        3 => 'field_core_contacts',
        9 => 'field_core_background',
        10 => 'group_cfp_details',
        11 => 'group_cfp_main_section',
        12 => 'group_cfp_documents',
        13 => 'group_cfp_contact',
        14 => 'group_cfp_related',
        15 => 'social_bookmark_webtools',
        16 => 'field_core_links',
        17 => 'field_cfp_call_reference',
        18 => 'dt_call_for_proposal_published',
        19 => 'field_core_date_opening',
        20 => 'field_cfp_deadline_model',
        21 => 'field_core_deadlines',
        22 => 'field_grants_awarded_link',
        23 => 'hr_1',
        24 => 'field_cfp_program',
        25 => 'field_core_topics',
        26 => 'field_core_departments',
      ),
      'top' => array(
        7 => 'dt_call_for_proposal_status_message',
      ),
      'left' => array(
        8 => 'in_page_navigation',
      ),
    ),
    'fields' => array(
      'dt_call_for_proposal_meta' => 'left_header',
      'field_core_files' => 'central',
      'group_cfp_meta' => 'left_header',
      'field_core_contacts' => 'central',
      'content_type_label' => 'left_header',
      'title' => 'left_header',
      'field_core_introduction' => 'left_header',
      'dt_call_for_proposal_status_message' => 'top',
      'in_page_navigation' => 'left',
      'field_core_background' => 'central',
      'group_cfp_details' => 'central',
      'group_cfp_main_section' => 'central',
      'group_cfp_documents' => 'central',
      'group_cfp_contact' => 'central',
      'group_cfp_related' => 'central',
      'social_bookmark_webtools' => 'central',
      'field_core_links' => 'central',
      'field_cfp_call_reference' => 'central',
      'dt_call_for_proposal_published' => 'central',
      'field_core_date_opening' => 'central',
      'field_cfp_deadline_model' => 'central',
      'field_core_deadlines' => 'central',
      'field_grants_awarded_link' => 'central',
      'hr_1' => 'central',
      'field_cfp_program' => 'central',
      'field_core_topics' => 'central',
      'field_core_departments' => 'central',
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
  $export['node|call_for_proposal|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|call_for_proposal|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'call_for_proposal';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ne_2col_sidebar_no_link';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'group_cfp_meta',
        1 => 'title_field',
        2 => 'field_cfp_call_reference',
        3 => 'field_core_date_opening',
        4 => 'dt_call_for_proposal_deadline',
        5 => 'field_cfp_program',
        6 => 'field_core_topics',
        7 => 'field_cfp_status',
      ),
    ),
    'fields' => array(
      'group_cfp_meta' => 'main',
      'title_field' => 'main',
      'field_cfp_call_reference' => 'main',
      'field_core_date_opening' => 'main',
      'dt_call_for_proposal_deadline' => 'main',
      'field_cfp_program' => 'main',
      'field_core_topics' => 'main',
      'field_cfp_status' => 'main',
    ),
    'classes' => array(),
    'wrappers' => array(
      'main' => 'div',
      'second' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|call_for_proposal|teaser'] = $ds_layout;

  return $export;
}
