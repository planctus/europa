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
    'location' => array(
      'weight' => '2',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:10:{s:5:"label";s:6:"hidden";s:9:"formatter";s:10:"text_plain";s:11:"delta_limit";i:0;s:12:"delta_offset";s:1:"0";s:14:"delta_reversed";b:0;s:18:"formatter_settings";a:0:{}s:7:"context";s:25:"argument_entity_id:node_1";s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";s:22:"override_title_heading";s:2:"h2";}s:4:"type";s:12:"entity_field";s:7:"subtype";s:32:"node:field_announcement_location";}',
        'load_terms' => 0,
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Location',
          'lb-el' => 'span',
          'lb-cl' => 'context-nav__label',
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
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'published' => array(
      'weight' => '0',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Published',
          'lb-el' => 'span',
          'lb-cl' => 'context-nav__label',
          'lbw-el' => 'span',
          'lbw-cl' => 'context-nav__label',
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
    'author' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'author',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_nexteuropa_formatters_meta_item',
          'meta_modifier' => '',
        ),
      ),
    ),
    'changed_date' => array(
      'weight' => '1',
      'label' => 'inline',
      'format' => 'ds_post_date_ec_date_j_f_y',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Last update',
          'lb-el' => 'span',
          'lb-cl' => 'context-nav__label',
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
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'hr_1' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'social_bookmark_webtools' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'social-media-links--webtool-horizontal',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_announcement_department' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Author:',
        ),
      ),
    ),
    'field_announcement_info' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Background',
          'lb-el' => 'h3',
          'lb-at' => 'name="background"',
          'lb-col' => TRUE,
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
    'field_announcement_location' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_nexteuropa_formatters_meta_item',
          'meta_modifier' => '',
        ),
      ),
    ),
    'field_announcement_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_nexteuropa_formatters_meta_item',
          'meta_modifier' => 'meta__item--type',
        ),
      ),
    ),
    'field_core_department' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Departments:',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_core_persons' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Commissioner:',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_core_topics' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Topics:',
          'lb-col' => TRUE,
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
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_core_date_published' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_nexteuropa_formatters_meta_item',
          'meta_modifier' => '',
        ),
      ),
    ),
    'field_publication_referenceno' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Reference:',
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
    'title_field' => array(
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
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_core_date_published' => array(
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
  );
  $export['node|announcement|meta'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|announcement|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'announcement';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'sticky_label' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'title_field' => array(
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
    'field_core_description' => array(
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
    'field_core_date_published' => array(
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
  $ds_field->field = 'location';
  $ds_field->label = 'Location';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['location'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'published';
  $ds_field->label = 'Published';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '[node:field-core-date-published:ec_date_j_f_y]',
      'format' => 'plain_text',
    ),
    'use_token' => 1,
  );
  $export['published'] = $ds_field;

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
        13 => 'field_core_policies',
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
      'field_core_policies' => 'central',
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
        0 => 'group_announcement_meta',
        3 => 'field_announcement_type',
        4 => 'title',
        5 => 'field_core_date_published',
        8 => 'field_announcement_location',
        11 => 'author',
      ),
      'central' => array(
        1 => 'field_core_press_contacts',
        2 => 'published',
        6 => 'changed_date',
        7 => 'field_core_introduction',
        10 => 'location',
        12 => 'group_announcement_main',
        13 => 'body',
        14 => 'field_announcement_department',
        15 => 'field_core_topics',
        16 => 'field_announcement_info',
        17 => 'field_publication_referenceno',
        18 => 'group_announcement_contextual2',
        19 => 'hr_1',
        20 => 'field_core_department',
        21 => 'field_core_links',
        22 => 'social_bookmark_webtools',
        23 => 'group_announcement_contextual',
        24 => 'group_announcement_content',
        25 => 'field_core_persons',
        26 => 'group_contact',
        27 => 'group_related',
        28 => 'field_core_announcement',
      ),
      'top' => array(
        9 => 'field_announcement_image',
      ),
    ),
    'fields' => array(
      'group_announcement_meta' => 'left_header',
      'field_core_press_contacts' => 'central',
      'published' => 'central',
      'field_announcement_type' => 'left_header',
      'title' => 'left_header',
      'field_core_date_published' => 'left_header',
      'changed_date' => 'central',
      'field_core_introduction' => 'central',
      'field_announcement_location' => 'left_header',
      'field_announcement_image' => 'top',
      'location' => 'central',
      'author' => 'left_header',
      'group_announcement_main' => 'central',
      'body' => 'central',
      'field_announcement_department' => 'central',
      'field_core_topics' => 'central',
      'field_announcement_info' => 'central',
      'field_publication_referenceno' => 'central',
      'group_announcement_contextual2' => 'central',
      'hr_1' => 'central',
      'field_core_department' => 'central',
      'field_core_links' => 'central',
      'social_bookmark_webtools' => 'central',
      'group_announcement_contextual' => 'central',
      'group_announcement_content' => 'central',
      'field_core_persons' => 'central',
      'group_contact' => 'central',
      'group_related' => 'central',
      'field_core_announcement' => 'central',
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
        3 => 'field_core_date_published',
      ),
    ),
    'fields' => array(
      'group_announcement_meta' => 'main',
      'title_field' => 'main',
      'field_announcement_type' => 'main',
      'field_core_date_published' => 'main',
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
        0 => 'sticky_label',
        1 => 'group_announcement_meta',
        2 => 'title_field',
        3 => 'field_announcement_type',
        4 => 'field_core_description',
        5 => 'field_core_date_published',
      ),
      'second' => array(
        6 => 'field_announcement_image',
      ),
    ),
    'fields' => array(
      'sticky_label' => 'main',
      'group_announcement_meta' => 'main',
      'title_field' => 'main',
      'field_announcement_type' => 'main',
      'field_core_description' => 'main',
      'field_core_date_published' => 'main',
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
