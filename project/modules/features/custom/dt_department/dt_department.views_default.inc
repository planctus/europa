<?php
/**
 * @file
 * dt_department.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dt_department_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'department';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Department';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Departments and agencies';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'title';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'The Commission is organised in 2 types of departments. Directorates-General (DGs) make policy. Services provide administrative and other support - including publications and statistics - to parties inside or outside the Commission. Executive agencies are set up for a fixed period to manage programmes. They are not legally part of the EU institutions, but their activities are governed by EU law.';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['header']['result']['content'] = '@total departments';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'department' => 'department',
  );
  /* Filter criterion: Content: Topics (field_core_topics) */
  $handler->display->display_options['filters']['field_core_topics_target_id']['id'] = 'field_core_topics_target_id';
  $handler->display->display_options['filters']['field_core_topics_target_id']['table'] = 'field_data_field_core_topics';
  $handler->display->display_options['filters']['field_core_topics_target_id']['field'] = 'field_core_topics_target_id';
  $handler->display->display_options['filters']['field_core_topics_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_topics_target_id']['expose']['operator_id'] = 'field_core_topics_target_id_op';
  $handler->display->display_options['filters']['field_core_topics_target_id']['expose']['label'] = 'Topics';
  $handler->display->display_options['filters']['field_core_topics_target_id']['expose']['operator'] = 'field_core_topics_target_id_op';
  $handler->display->display_options['filters']['field_core_topics_target_id']['expose']['identifier'] = 'topics';
  $handler->display->display_options['filters']['field_core_topics_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Main tasks (field_department_main_tasks) */
  $handler->display->display_options['filters']['field_department_main_tasks_value']['id'] = 'field_department_main_tasks_value';
  $handler->display->display_options['filters']['field_department_main_tasks_value']['table'] = 'field_data_field_department_main_tasks';
  $handler->display->display_options['filters']['field_department_main_tasks_value']['field'] = 'field_department_main_tasks_value';
  $handler->display->display_options['filters']['field_department_main_tasks_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_department_main_tasks_value']['expose']['operator_id'] = 'field_department_main_tasks_value_op';
  $handler->display->display_options['filters']['field_department_main_tasks_value']['expose']['label'] = 'Main tasks';
  $handler->display->display_options['filters']['field_department_main_tasks_value']['expose']['operator'] = 'field_department_main_tasks_value_op';
  $handler->display->display_options['filters']['field_department_main_tasks_value']['expose']['identifier'] = 'main_task';
  $handler->display->display_options['filters']['field_department_main_tasks_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_department_main_tasks_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: EC Organisation (field_core_ecorganisation) */
  $handler->display->display_options['filters']['field_core_ecorganisation_value']['id'] = 'field_core_ecorganisation_value';
  $handler->display->display_options['filters']['field_core_ecorganisation_value']['table'] = 'field_data_field_core_ecorganisation';
  $handler->display->display_options['filters']['field_core_ecorganisation_value']['field'] = 'field_core_ecorganisation_value';
  $handler->display->display_options['filters']['field_core_ecorganisation_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_ecorganisation_value']['expose']['operator_id'] = 'field_core_ecorganisation_value_op';
  $handler->display->display_options['filters']['field_core_ecorganisation_value']['expose']['label'] = 'Department type';
  $handler->display->display_options['filters']['field_core_ecorganisation_value']['expose']['operator'] = 'field_core_ecorganisation_value_op';
  $handler->display->display_options['filters']['field_core_ecorganisation_value']['expose']['identifier'] = 'department_type';
  $handler->display->display_options['filters']['field_core_ecorganisation_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'departments';
  $export['department'] = $view;

  return $export;
}