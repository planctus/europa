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
        ),
      ),
    ),
    'social_media' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
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
    'field_team_tagline' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
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
        0 => 'team_meta',
        2 => 'group_team_meta',
        3 => 'title',
        4 => 'field_team_tagline',
      ),
      'central' => array(
        1 => 'cwt_team_role',
        7 => 'group_team_role',
        8 => 'group_team_tab_role',
        9 => 'body',
        10 => 'group_team_links',
        11 => 'group_team_tabs',
        12 => 'cwt_team_name',
        13 => 'group_team_tab_project_team',
        14 => 'field_team_links',
        15 => 'cwt_team_president',
        16 => 'group_team_tab_name',
        17 => 'group_team_members',
        18 => 'group_team_comissioners',
        19 => 'field_team_attachments',
        20 => 'cwt_team_project_team',
        21 => 'group_team_files',
        22 => 'social_media',
        23 => 'group_team_president',
      ),
      'bottom_header' => array(
        5 => 'field_illustrative_image',
        6 => 'group_team_top_image',
      ),
    ),
    'fields' => array(
      'team_meta' => 'left_header',
      'cwt_team_role' => 'central',
      'group_team_meta' => 'left_header',
      'title' => 'left_header',
      'field_team_tagline' => 'left_header',
      'field_illustrative_image' => 'bottom_header',
      'group_team_top_image' => 'bottom_header',
      'group_team_role' => 'central',
      'group_team_tab_role' => 'central',
      'body' => 'central',
      'group_team_links' => 'central',
      'group_team_tabs' => 'central',
      'cwt_team_name' => 'central',
      'group_team_tab_project_team' => 'central',
      'field_team_links' => 'central',
      'cwt_team_president' => 'central',
      'group_team_tab_name' => 'central',
      'group_team_members' => 'central',
      'group_team_comissioners' => 'central',
      'field_team_attachments' => 'central',
      'cwt_team_project_team' => 'central',
      'group_team_files' => 'central',
      'social_media' => 'central',
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
        2 => 'field_team_tagline',
      ),
      'top' => array(
        3 => 'group_team_contact',
        6 => 'group_team_row',
        7 => 'team_contacts',
        8 => 'team_contact_image',
      ),
      'central' => array(
        4 => 'group_team_members',
        5 => 'team_members',
      ),
    ),
    'fields' => array(
      'content_type_label' => 'left_header',
      'title' => 'left_header',
      'field_team_tagline' => 'left_header',
      'group_team_contact' => 'top',
      'group_team_members' => 'central',
      'team_members' => 'central',
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
