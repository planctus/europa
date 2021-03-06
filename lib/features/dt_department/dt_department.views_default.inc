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
  $view->tag = 'digital_transformation';
  $view->base_table = 'node';
  $view->human_name = 'Department';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Departments and executive agencies';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Field: Title (title_field) */
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
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['expose']['hide_empty_filter'] = FALSE;
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
  /* Filter criterion: Content: Department type (field_core_ecorganisation) (translated) */
  $handler->display->display_options['filters']['field_core_ecorganisation_value_i18n']['id'] = 'field_core_ecorganisation_value_i18n';
  $handler->display->display_options['filters']['field_core_ecorganisation_value_i18n']['table'] = 'field_data_field_core_ecorganisation';
  $handler->display->display_options['filters']['field_core_ecorganisation_value_i18n']['field'] = 'field_core_ecorganisation_value_i18n';
  $handler->display->display_options['filters']['field_core_ecorganisation_value_i18n']['value'] = array(
    'Directorate-General' => 'Directorate-General',
    'Service department' => 'Service department',
    'Executive agency' => 'Executive agency',
  );
  $handler->display->display_options['filters']['field_core_ecorganisation_value_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_core_ecorganisation_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_ecorganisation_value_i18n']['expose']['operator_id'] = 'field_core_ecorganisation_value_i18n_op';
  $handler->display->display_options['filters']['field_core_ecorganisation_value_i18n']['expose']['label'] = 'Department type';
  $handler->display->display_options['filters']['field_core_ecorganisation_value_i18n']['expose']['operator'] = 'field_core_ecorganisation_value_i18n_op';
  $handler->display->display_options['filters']['field_core_ecorganisation_value_i18n']['expose']['identifier'] = 'field_core_ecorganisation_value_i18n';
  $handler->display->display_options['filters']['field_core_ecorganisation_value_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_core_ecorganisation_value_i18n']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Main task (field_department_tasks) (reference filter) */
  $handler->display->display_options['filters']['field_department_tasks_tid_entityreference_filter']['id'] = 'field_department_tasks_tid_entityreference_filter';
  $handler->display->display_options['filters']['field_department_tasks_tid_entityreference_filter']['table'] = 'field_data_field_department_tasks';
  $handler->display->display_options['filters']['field_department_tasks_tid_entityreference_filter']['field'] = 'field_department_tasks_tid_entityreference_filter';
  $handler->display->display_options['filters']['field_department_tasks_tid_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['field_department_tasks_tid_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_department_tasks_tid_entityreference_filter']['expose']['operator_id'] = 'field_department_tasks_tid_entityreference_filter_op';
  $handler->display->display_options['filters']['field_department_tasks_tid_entityreference_filter']['expose']['label'] = 'Main task';
  $handler->display->display_options['filters']['field_department_tasks_tid_entityreference_filter']['expose']['operator'] = 'field_department_tasks_tid_entityreference_filter_op';
  $handler->display->display_options['filters']['field_department_tasks_tid_entityreference_filter']['expose']['identifier'] = 'field_department_tasks_tid_entityreference_filter';
  $handler->display->display_options['filters']['field_department_tasks_tid_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_department_tasks_tid_entityreference_filter']['reference_display'] = 'tax_department_tasks_list:entityreference_1';
  /* Filter criterion: Content: Department type (field_core_ecorganisation) */
  $handler->display->display_options['filters']['field_core_ecorganisation_value']['id'] = 'field_core_ecorganisation_value';
  $handler->display->display_options['filters']['field_core_ecorganisation_value']['table'] = 'field_data_field_core_ecorganisation';
  $handler->display->display_options['filters']['field_core_ecorganisation_value']['field'] = 'field_core_ecorganisation_value';
  $handler->display->display_options['filters']['field_core_ecorganisation_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_core_ecorganisation_value']['value'] = array(
    'External department' => 'External department',
  );
  $handler->display->display_options['filters']['field_core_ecorganisation_value']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['dt_shared_functions_views_config_title'] = 'Departments / Executive agencies';
  $handler->display->display_options['path'] = 'departments';
  $export['department'] = $view;

  $view = new view();
  $view->name = 'filter_list_departments';
  $view->description = 'Collection of views objects that can be used to filter lists';
  $view->tag = 'digital_transformation';
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
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Sort criterion: Field: Title (title_field) */
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
    'title_field' => 'title_field',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['filter_list_departments'] = $view;

  $view = new view();
  $view->name = 'tax_department_tasks_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Filter list - Departments Tasks';
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
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Entity translation: Name: translated */
  $handler->display->display_options['fields']['name_field_et_1']['id'] = 'name_field_et_1';
  $handler->display->display_options['fields']['name_field_et_1']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field_et_1']['field'] = 'name_field_et';
  $handler->display->display_options['fields']['name_field_et_1']['label'] = '';
  $handler->display->display_options['fields']['name_field_et_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_field_et_1']['type'] = 'text_plain';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'department_tasks' => 'department_tasks',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name_field_et_1' => 'name_field_et_1',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['tax_department_tasks_list'] = $view;

  return $export;
}
