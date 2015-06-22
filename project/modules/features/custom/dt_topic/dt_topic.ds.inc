<?php
/**
 * @file
 * dt_topic.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_topic_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|topic|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'topic';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'node_type' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:5:{s:8:"sanitize";i:1;s:7:"context";s:25:"argument_entity_id:node_1";s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";s:22:"override_title_heading";s:2:"h2";}s:4:"type";s:5:"token";s:7:"subtype";s:17:"node:content-type";}',
        'load_terms' => 0,
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
    'field_core_introduction' => array(
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
    'field_core_link' => array(
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
    'field_topic_objectives' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_topic_targets' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_topic_tasks' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_core_top_tasks' => array(
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
  );
  $export['node|topic|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|topic|title';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'topic';
  $ds_fieldsetting->view_mode = 'title';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h3',
        'class' => 'listing__title',
        'ft' => array(),
      ),
    ),
  );
  $export['node|topic|title'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_topic_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|topic|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'topic';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ne_bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'related_topic_specific_tasks',
        6 => 'field_core_top_tasks',
        7 => 'group_topic_contextual',
        8 => 'field_core_priorities',
        9 => 'group_topic_tasks',
        10 => 'field_core_topics',
        11 => 'field_core_persons',
        12 => 'field_core_department',
      ),
      'central' => array(
        1 => 'related_topic_policy_areas',
        13 => 'field_topic_commission_actions',
        14 => 'field_topic_objectives',
        15 => 'field_core_link',
      ),
      'left_header' => array(
        2 => 'group_topic_meta',
        3 => 'title',
        4 => 'content_type',
        5 => 'field_core_introduction',
      ),
    ),
    'fields' => array(
      'related_topic_specific_tasks' => 'top',
      'related_topic_policy_areas' => 'central',
      'group_topic_meta' => 'left_header',
      'title' => 'left_header',
      'content_type' => 'left_header',
      'field_core_introduction' => 'left_header',
      'field_core_top_tasks' => 'top',
      'group_topic_contextual' => 'top',
      'field_core_priorities' => 'top',
      'group_topic_tasks' => 'top',
      'field_core_topics' => 'top',
      'field_core_persons' => 'top',
      'field_core_department' => 'top',
      'field_topic_commission_actions' => 'central',
      'field_topic_objectives' => 'central',
      'field_core_link' => 'central',
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
  $export['node|topic|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|topic|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'topic';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ne_bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'node_type',
        1 => 'group_topic_meta',
        2 => 'title',
        3 => 'field_core_introduction',
      ),
      'top' => array(
        4 => 'group_topic_contextual',
        5 => 'field_core_priorities',
        7 => 'field_core_topics',
        9 => 'field_core_persons',
        11 => 'field_core_department',
      ),
      'central' => array(
        6 => 'group_topic_related_tasks',
        8 => 'group_topic_policy_areas',
        10 => 'group_topic_latest',
        12 => 'group_topic_what_is_doing',
        13 => 'field_core_policy_areas',
        14 => 'field_topic_commission_actions',
        15 => 'field_topic_objectives',
        16 => 'field_topic_targets',
        17 => 'group_latest_main',
        18 => 'field_topic_tasks',
        19 => 'field_core_top_tasks',
        20 => 'field_core_link',
        21 => 'group_latest_sidebar',
        22 => 'field_core_social_network_links',
      ),
    ),
    'fields' => array(
      'node_type' => 'left_header',
      'group_topic_meta' => 'left_header',
      'title' => 'left_header',
      'field_core_introduction' => 'left_header',
      'group_topic_contextual' => 'top',
      'field_core_priorities' => 'top',
      'group_topic_related_tasks' => 'central',
      'field_core_topics' => 'top',
      'group_topic_policy_areas' => 'central',
      'field_core_persons' => 'top',
      'group_topic_latest' => 'central',
      'field_core_department' => 'top',
      'group_topic_what_is_doing' => 'central',
      'field_core_policy_areas' => 'central',
      'field_topic_commission_actions' => 'central',
      'field_topic_objectives' => 'central',
      'field_topic_targets' => 'central',
      'group_latest_main' => 'central',
      'field_topic_tasks' => 'central',
      'field_core_top_tasks' => 'central',
      'field_core_link' => 'central',
      'group_latest_sidebar' => 'central',
      'field_core_social_network_links' => 'central',
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
  $export['node|topic|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|topic|title';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'topic';
  $ds_layout->view_mode = 'title';
  $ds_layout->layout = 'ne_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'title',
      ),
    ),
    'fields' => array(
      'title' => 'main',
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
  $export['node|topic|title'] = $ds_layout;

  return $export;
}
