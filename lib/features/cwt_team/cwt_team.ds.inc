<?php
/**
 * @file
 * cwt_team.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function cwt_team_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|team|college';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'team';
  $ds_fieldsetting->view_mode = 'college';
  $ds_fieldsetting->settings = array(
    'commissioners_no_longer_in_office' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'team_meta' => array(
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
    'cwt_team_president' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'cwt_team_role' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'cwt_team_project_team' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'cwt_team_name' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'social_bookmark_webtools' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_team_tagline' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|team|college'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|team|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'team';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'team_contact_image' => array(
      'weight' => '47',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'col-md-6',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'team_contacts' => array(
      'weight' => '46',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'col-md-6',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'team_members' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'content_type_label' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'meta meta--header',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'meta__item meta__item--type',
          'fis-at' => '',
          'fis-def-at' => FALSE,
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
    'field_editorial_section' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Tagline',
        ),
      ),
    ),
  );
  $export['node|team|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function cwt_team_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'commissioners_no_longer_in_office';
  $ds_field->label = 'Commissioners no longer in office';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|team_members-block_4',
    'block_render' => '1',
  );
  $export['commissioners_no_longer_in_office'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'team_contact_image';
  $ds_field->label = 'Team contact - image';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'team|full';
  $ds_field->properties = array(
    'block' => 'views|team_cabinet_contact-block_1',
    'block_render' => '1',
  );
  $export['team_contact_image'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'team_contacts';
  $ds_field->label = 'Team contacts';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'team|*';
  $ds_field->properties = array(
    'block' => 'views|team_cabinet_contact-block',
    'block_render' => '1',
  );
  $export['team_contacts'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'team_members';
  $ds_field->label = 'Team members';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'team|*';
  $ds_field->properties = array(
    'block' => 'views|team_cabinet_members-block_2',
    'block_render' => '1',
  );
  $export['team_members'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'team_meta';
  $ds_field->label = 'Team meta';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'team|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '[node:field-team-subtype] ([node:field-team-term])',
      'format' => 'plain_text',
    ),
    'use_token' => 1,
  );
  $export['team_meta'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function cwt_team_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|team|college';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'team';
  $ds_layout->view_mode = 'college';
  $ds_layout->layout = 'ne_bootstrap_1col_stacked_bottom_header';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'group_team_meta',
        2 => 'team_meta',
        3 => 'title',
        4 => 'field_team_tagline',
      ),
      'central' => array(
        1 => 'cwt_team_role',
        7 => 'group_team_role',
        8 => 'body',
        9 => 'group_team_tab_role',
        10 => 'group_team_links',
        11 => 'cwt_team_president',
        12 => 'cwt_team_name',
        13 => 'group_team_tab_project_team',
        14 => 'field_team_links',
        15 => 'group_team_tabs',
        16 => 'commissioners_no_longer_in_office',
        17 => 'group_team_tab_name',
        18 => 'group_team_members',
        19 => 'group_team_comissioners',
        20 => 'group_team_files',
        21 => 'cwt_team_project_team',
        22 => 'field_team_attachments',
        23 => 'social_bookmark_webtools',
        24 => 'group_team_president',
      ),
      'bottom_header' => array(
        5 => 'group_team_top_image',
        6 => 'field_illustrative_image',
      ),
    ),
    'fields' => array(
      'group_team_meta' => 'left_header',
      'cwt_team_role' => 'central',
      'team_meta' => 'left_header',
      'title' => 'left_header',
      'field_team_tagline' => 'left_header',
      'group_team_top_image' => 'bottom_header',
      'field_illustrative_image' => 'bottom_header',
      'group_team_role' => 'central',
      'body' => 'central',
      'group_team_tab_role' => 'central',
      'group_team_links' => 'central',
      'cwt_team_president' => 'central',
      'cwt_team_name' => 'central',
      'group_team_tab_project_team' => 'central',
      'field_team_links' => 'central',
      'group_team_tabs' => 'central',
      'commissioners_no_longer_in_office' => 'central',
      'group_team_tab_name' => 'central',
      'group_team_members' => 'central',
      'group_team_comissioners' => 'central',
      'group_team_files' => 'central',
      'cwt_team_project_team' => 'central',
      'field_team_attachments' => 'central',
      'social_bookmark_webtools' => 'central',
      'group_team_president' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left_header' => 'div',
      'right_header' => 'div',
      'bottom_header' => 'div',
      'top' => 'div',
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|team|college'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|team|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'team';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ne_bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'content_type_label',
        1 => 'title',
        5 => 'field_editorial_section',
      ),
      'top' => array(
        2 => 'group_team_contact',
        6 => 'group_team_row',
        7 => 'team_contacts',
        8 => 'team_contact_image',
      ),
      'central' => array(
        3 => 'team_members',
        4 => 'group_team_members',
      ),
    ),
    'fields' => array(
      'content_type_label' => 'left_header',
      'title' => 'left_header',
      'group_team_contact' => 'top',
      'team_members' => 'central',
      'group_team_members' => 'central',
      'field_editorial_section' => 'left_header',
      'group_team_row' => 'top',
      'team_contacts' => 'top',
      'team_contact_image' => 'top',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left_header' => 'div',
      'right_header' => 'div',
      'top' => 'div',
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|team|full'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function cwt_team_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'college';
  $ds_view_mode->label = 'College';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['college'] = $ds_view_mode;

  return $export;
}
