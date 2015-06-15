<?php
/**
 * @file
 * dt_topic.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dt_topic_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'topics';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Topics';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Topics';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'title';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|title';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'title';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_core_description']['id'] = 'field_core_description';
  $handler->display->display_options['fields']['field_core_description']['table'] = 'field_data_field_core_description';
  $handler->display->display_options['fields']['field_core_description']['field'] = 'field_core_description';
  /* Field: Content: Introduction */
  $handler->display->display_options['fields']['field_core_introduction']['id'] = 'field_core_introduction';
  $handler->display->display_options['fields']['field_core_introduction']['table'] = 'field_data_field_core_introduction';
  $handler->display->display_options['fields']['field_core_introduction']['field'] = 'field_core_introduction';
  /* Field: Content: Objectives */
  $handler->display->display_options['fields']['field_topic_objectives']['id'] = 'field_topic_objectives';
  $handler->display->display_options['fields']['field_topic_objectives']['table'] = 'field_data_field_topic_objectives';
  $handler->display->display_options['fields']['field_topic_objectives']['field'] = 'field_topic_objectives';
  /* Field: Content: Related top tasks */
  $handler->display->display_options['fields']['field_core_top_tasks']['id'] = 'field_core_top_tasks';
  $handler->display->display_options['fields']['field_core_top_tasks']['table'] = 'field_data_field_core_top_tasks';
  $handler->display->display_options['fields']['field_core_top_tasks']['field'] = 'field_core_top_tasks';
  $handler->display->display_options['fields']['field_core_top_tasks']['delta_offset'] = '0';
  /* Field: Content: Targets */
  $handler->display->display_options['fields']['field_topic_targets']['id'] = 'field_topic_targets';
  $handler->display->display_options['fields']['field_topic_targets']['table'] = 'field_data_field_topic_targets';
  $handler->display->display_options['fields']['field_topic_targets']['field'] = 'field_topic_targets';
  /* Field: Content: What the Commission is doing */
  $handler->display->display_options['fields']['field_topic_commission_actions']['id'] = 'field_topic_commission_actions';
  $handler->display->display_options['fields']['field_topic_commission_actions']['table'] = 'field_data_field_topic_commission_actions';
  $handler->display->display_options['fields']['field_topic_commission_actions']['field'] = 'field_topic_commission_actions';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'topic' => 'topic',
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'by keyword';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_core_description' => 'field_core_description',
    'field_core_introduction' => 'field_core_introduction',
    'field_topic_objectives' => 'field_topic_objectives',
    'field_core_top_tasks' => 'field_core_top_tasks',
    'field_topic_targets' => 'field_topic_targets',
    'field_topic_commission_actions' => 'field_topic_commission_actions',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'topics';
  $export['topics'] = $view;

  return $export;
}
