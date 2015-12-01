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
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Clear all';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'nexteuropa_bem_listing';
  $handler->display->display_options['style_options']['listing_columns'] = 'default';
  $handler->display->display_options['style_options']['listing_modifier'] = '';
  $handler->display->display_options['style_options']['listing_wrapper_modifier'] = '';
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'meta';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'field_data_title_field|title_field_value';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'meta';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'The Commission is organised in 2 types of departments. Directorates-General (DGs) make policy. Services provide administrative and other support - including publications and statistics - to parties inside or outside the Commission. Executive agencies are set up for a fixed period to manage programmes. They are not legally part of the EU institutions, but their activities are governed by EU law.';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Title (title_field) */
  $handler->display->display_options['sorts']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['sorts']['title_field_value']['field'] = 'title_field_value';
  /* Filter criterion: Content: Related topics (field_core_topics) (reference filter) */
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['id'] = 'field_core_topics_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['table'] = 'field_data_field_core_topics';
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['field'] = 'field_core_topics_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['expose']['operator_id'] = 'field_core_topics_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['expose']['label'] = 'Topics';
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['expose']['operator'] = 'field_core_topics_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['expose']['identifier'] = 'field_core_topics_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['reference_display'] = 'filter_list_topics:entityreference_1';
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Department type (field_core_ecorganisation) */
  $handler->display->display_options['filters']['field_core_ecorganisation_value']['id'] = 'field_core_ecorganisation_value';
  $handler->display->display_options['filters']['field_core_ecorganisation_value']['table'] = 'field_data_field_core_ecorganisation';
  $handler->display->display_options['filters']['field_core_ecorganisation_value']['field'] = 'field_core_ecorganisation_value';
  $handler->display->display_options['filters']['field_core_ecorganisation_value']['group'] = 1;
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
  /* Filter criterion: Content: Main task (field_department_tasks) */
  $handler->display->display_options['filters']['field_department_tasks_tid']['id'] = 'field_department_tasks_tid';
  $handler->display->display_options['filters']['field_department_tasks_tid']['table'] = 'field_data_field_department_tasks';
  $handler->display->display_options['filters']['field_department_tasks_tid']['field'] = 'field_department_tasks_tid';
  $handler->display->display_options['filters']['field_department_tasks_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_department_tasks_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_department_tasks_tid']['expose']['operator_id'] = 'field_department_tasks_tid_op';
  $handler->display->display_options['filters']['field_department_tasks_tid']['expose']['label'] = 'Main task';
  $handler->display->display_options['filters']['field_department_tasks_tid']['expose']['operator'] = 'field_department_tasks_tid_op';
  $handler->display->display_options['filters']['field_department_tasks_tid']['expose']['identifier'] = 'main_task';
  $handler->display->display_options['filters']['field_department_tasks_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_department_tasks_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_department_tasks_tid']['vocabulary'] = 'department_tasks';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'departments';
  $export['department'] = $view;

  $view = new view();
  $view->name = 'filter_list_departments';
  $view->description = 'Collection of views objects that can be used to filter lists';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Filter list - Departments';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'nexteuropa_bem_listing';
  $handler->display->display_options['style_options']['listing_columns'] = 'default';
  $handler->display->display_options['style_options']['listing_modifier'] = '';
  $handler->display->display_options['style_options']['listing_wrapper_modifier'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Title (title_field) */
  $handler->display->display_options['sorts']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['sorts']['title_field_value']['field'] = 'title_field_value';
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

  /* Display: Departments */
  $handler = $view->new_display('entityreference', 'Departments', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'List of topics that can be used for exposed filters';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['filter_list_departments'] = $view;

  return $export;
}