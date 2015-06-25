<?php
/**
 * @file
 * dt_announcement.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_announcement_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|announcement|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'announcement';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|announcement|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|announcement|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'announcement';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'related_announcements' => array(
      'weight' => '10',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Related news',
          'lb-el' => 'h2',
          'lb-at' => 'id="related"',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field--full-width',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
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
    'post_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_ec_date_j_f_y',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'meta__item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_announcement_info' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h2',
          'lb-at' => 'name="background"',
          'lb-col' => TRUE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_announcement_type' => array(
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
    'field_core_department' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'span',
          'lb-cl' => 'context-nav__label',
          'lb-col' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'context-nav__items',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'context-nav__item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_core_topics' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'span',
          'lb-cl' => 'context-nav__label',
          'lb-col' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'context-nav__items',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'context-nav__item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_announcement_location' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'meta__item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_core_persons' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Commissioner',
          'lb-el' => 'span',
          'lb-cl' => 'context-nav__label',
          'lb-col' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'context-nav__items',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'context-nav__item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_core_links' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h4',
          'lb-col' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|announcement|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|announcement|meta';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'announcement';
  $ds_fieldsetting->view_mode = 'meta';
  $ds_fieldsetting->settings = array(
    'post_date' => array(
      'weight' => '21',
      'label' => 'hidden',
      'format' => 'ds_post_date_ec_date_j_f_y',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'meta__item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_announcement_type' => array(
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
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h3',
          'fi-cl' => 'listing__title',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|announcement|meta'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|announcement|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'announcement';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'post_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_ec_date_j_f_y',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'meta__item',
          'fi-at' => '',
          'fi-def-at' => TRUE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_announcement_image' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_announcement_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'meta__item meta__item--type',
          'fi-at' => '',
          'fi-def-at' => TRUE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h3',
          'fi-cl' => 'listing__title',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|announcement|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function dt_announcement_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'latest_announcements_block';
  $ds_field->label = 'Latest Announcements block';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|announcements-latest_block',
    'block_render' => '3',
  );
  $export['latest_announcements_block'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'related_announcements';
  $ds_field->label = 'Related Announcements';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'announcement|*';
  $ds_field->properties = array(
    'block' => 'views|announcements-block',
    'block_render' => '1',
  );
  $export['related_announcements'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_announcement_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|announcement|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'announcement';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ne_bootstrap_3_6_3_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'title',
        3 => 'field_core_introduction',
      ),
      'left' => array(
        1 => 'og_group_ref',
        4 => 'group_content_access',
        5 => 'field_announcement_info',
        6 => 'field_announcement_media',
        7 => 'field_announcement_image',
        8 => 'field_announcemnt_img_prominence',
      ),
      'central' => array(
        2 => 'body',
        11 => 'field_core_location',
        12 => 'field_core_topics',
        13 => 'field_core_policy',
        14 => 'field_core_department',
        15 => 'field_core_announcement',
        16 => 'field_core_subject',
        17 => 'field_core_links',
      ),
      'right' => array(
        9 => 'field_announcement_contact',
      ),
      'right_header' => array(
        10 => 'field_announcement_type',
      ),
    ),
    'fields' => array(
      'title' => 'left_header',
      'og_group_ref' => 'left',
      'body' => 'central',
      'field_core_introduction' => 'left_header',
      'group_content_access' => 'left',
      'field_announcement_info' => 'left',
      'field_announcement_media' => 'left',
      'field_announcement_image' => 'left',
      'field_announcemnt_img_prominence' => 'left',
      'field_announcement_contact' => 'right',
      'field_announcement_type' => 'right_header',
      'field_core_location' => 'central',
      'field_core_topics' => 'central',
      'field_core_policy' => 'central',
      'field_core_department' => 'central',
      'field_core_announcement' => 'central',
      'field_core_subject' => 'central',
      'field_core_links' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left_header' => 'div',
      'right_header' => 'div',
      'left' => 'div',
      'central' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|announcement|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|announcement|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'announcement';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ne_bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'field_announcement_type',
        1 => 'group_announcement_meta',
        2 => 'post_date',
        3 => 'title',
        4 => 'field_core_introduction',
        5 => 'field_announcement_location',
      ),
      'top' => array(
        6 => 'group_announcement_contextual',
        7 => 'field_announcement_image',
        8 => 'field_core_topics',
        9 => 'field_core_department',
        11 => 'field_core_persons',
      ),
      'central' => array(
        10 => 'group_announcement_latest',
        12 => 'body',
        13 => 'field_announcement_info',
        14 => 'field_core_links',
        15 => 'related_announcements',
        16 => 'group_latest_main',
        17 => 'group_latest_sidebar',
      ),
    ),
    'fields' => array(
      'field_announcement_type' => 'left_header',
      'group_announcement_meta' => 'left_header',
      'post_date' => 'left_header',
      'title' => 'left_header',
      'field_core_introduction' => 'left_header',
      'field_announcement_location' => 'left_header',
      'group_announcement_contextual' => 'top',
      'field_announcement_image' => 'top',
      'field_core_topics' => 'top',
      'field_core_department' => 'top',
      'group_announcement_latest' => 'central',
      'field_core_persons' => 'top',
      'body' => 'central',
      'field_announcement_info' => 'central',
      'field_core_links' => 'central',
      'related_announcements' => 'central',
      'group_latest_main' => 'central',
      'group_latest_sidebar' => 'central',
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
  $export['node|announcement|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|announcement|meta';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'announcement';
  $ds_layout->view_mode = 'meta';
  $ds_layout->layout = 'ne_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'group_announcement_meta',
        1 => 'title_field',
        2 => 'field_announcement_type',
        3 => 'post_date',
      ),
    ),
    'fields' => array(
      'group_announcement_meta' => 'main',
      'title_field' => 'main',
      'field_announcement_type' => 'main',
      'post_date' => 'main',
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
  $export['node|announcement|meta'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|announcement|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'announcement';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ne_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'field_announcement_type',
        1 => 'group_announcement_meta',
        2 => 'title_field',
        3 => 'post_date',
        4 => 'field_core_introduction',
      ),
      'second' => array(
        5 => 'field_announcement_image',
      ),
    ),
    'fields' => array(
      'field_announcement_type' => 'main',
      'group_announcement_meta' => 'main',
      'title_field' => 'main',
      'post_date' => 'main',
      'field_core_introduction' => 'main',
      'field_announcement_image' => 'second',
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
  $export['node|announcement|teaser'] = $ds_layout;

  return $export;
}
