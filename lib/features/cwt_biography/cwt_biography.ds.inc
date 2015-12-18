<?php
/**
 * @file
 * cwt_biography.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function cwt_biography_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|biography|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'biography';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'collapse_button' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'agenda_block' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'announcements_block' => array(
      'weight' => '38',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'biography_header' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'blog_block' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'contact' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'section',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'col-md-offset-2',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'listing__wrapper listing__wrapper--two-columns',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'departments' => array(
      'weight' => '0',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Related departments',
          'lb-el' => 'span',
          'lb-cl' => 'context-nav__label',
        ),
      ),
    ),
    'timeline_block' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'topics' => array(
      'weight' => '1',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Related topics',
          'lb-el' => 'span',
          'lb-cl' => 'context-nav__label',
        ),
      ),
    ),
    'in_page_navigation' => array(
      'weight' => '3',
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
    'field_biography_portrait' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'col-md-2',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_biography_team' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|biography|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function cwt_biography_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'agenda_block';
  $ds_field->label = 'Agenda block';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'biography|full';
  $ds_field->properties = array(
    'block' => 'views|activities-block',
    'block_render' => '3',
  );
  $export['agenda_block'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'announcements_block';
  $ds_field->label = 'Announcements Block';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'biography|full';
  $ds_field->properties = array(
    'block' => 'views|biography_news-block',
    'block_render' => '3',
  );
  $export['announcements_block'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'biography_header';
  $ds_field->label = 'Biography header';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'biography|full';
  $ds_field->properties = array(
    'block' => 'views|biography_header-header',
    'block_render' => '3',
  );
  $export['biography_header'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'blog_block';
  $ds_field->label = 'Blog block';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'biography|full';
  $ds_field->properties = array(
    'block' => 'views|blog_commisioner_bio-block',
    'block_render' => '3',
  );
  $export['blog_block'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'contact';
  $ds_field->label = 'Contact';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'biography|full';
  $ds_field->properties = array(
    'block' => 'views|contact-block',
    'block_render' => '3',
  );
  $export['contact'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'departments';
  $ds_field->label = 'Departments';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'biography|full';
  $ds_field->properties = array(
    'block' => 'views|biography_related_terms-block',
    'block_render' => '3',
  );
  $export['departments'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'timeline_block';
  $ds_field->label = 'Timeline block';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'biography|full';
  $ds_field->properties = array(
    'block' => 'views|biography_timeline-block',
    'block_render' => '3',
  );
  $export['timeline_block'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'topics';
  $ds_field->label = 'Topics';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'biography|full';
  $ds_field->properties = array(
    'block' => 'views|biography_related_terms-block_1',
    'block_render' => '3',
  );
  $export['topics'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function cwt_biography_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|biography|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'biography';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ne_bootstrap_3_9_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'biography_header',
      ),
      'top' => array(
        1 => 'contact',
        2 => 'departments',
        4 => 'topics',
        7 => 'group_bio_row',
        8 => 'group_bio_contact',
        11 => 'collapse_button',
        12 => 'group_bio_contextual',
        13 => 'group_bio_top_footer',
        23 => 'field_social_networks',
        25 => 'group_bio_top_wrapper',
        26 => 'field_biography_portrait',
        27 => 'group_bio_col',
      ),
      'central' => array(
        3 => 'field_biography_team_intro',
        5 => 'body',
        6 => 'field_biography_team',
        10 => 'group_bio_role',
        14 => 'group_bio_team',
        15 => 'agenda_block',
        16 => 'group_bio_news',
        17 => 'timeline_block',
        18 => 'group_bio_agenda',
        19 => 'blog_block',
        20 => 'group_bio_blog',
        21 => 'group_bio_timeline',
        22 => 'social_bookmark_webtools',
        24 => 'announcements_block',
      ),
      'left' => array(
        9 => 'in_page_navigation',
      ),
    ),
    'fields' => array(
      'biography_header' => 'left_header',
      'contact' => 'top',
      'departments' => 'top',
      'field_biography_team_intro' => 'central',
      'topics' => 'top',
      'body' => 'central',
      'field_biography_team' => 'central',
      'group_bio_row' => 'top',
      'group_bio_contact' => 'top',
      'in_page_navigation' => 'left',
      'group_bio_role' => 'central',
      'collapse_button' => 'top',
      'group_bio_contextual' => 'top',
      'group_bio_top_footer' => 'top',
      'group_bio_team' => 'central',
      'agenda_block' => 'central',
      'group_bio_news' => 'central',
      'timeline_block' => 'central',
      'group_bio_agenda' => 'central',
      'blog_block' => 'central',
      'group_bio_blog' => 'central',
      'group_bio_timeline' => 'central',
      'social_bookmark_webtools' => 'central',
      'field_social_networks' => 'top',
      'announcements_block' => 'central',
      'group_bio_top_wrapper' => 'top',
      'field_biography_portrait' => 'top',
      'group_bio_col' => 'top',
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
  $export['node|biography|full'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function cwt_biography_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'team_cabinet_member';
  $ds_view_mode->label = 'Team cabinet member';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['team_cabinet_member'] = $ds_view_mode;

  return $export;
}
