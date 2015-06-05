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
  $view->name = 'topic_related_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Topic related content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'listing';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'listing__item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_topic_tasks_target_id']['id'] = 'field_topic_tasks_target_id';
  $handler->display->display_options['relationships']['field_topic_tasks_target_id']['table'] = 'field_data_field_topic_tasks';
  $handler->display->display_options['relationships']['field_topic_tasks_target_id']['field'] = 'field_topic_tasks_target_id';
  $handler->display->display_options['relationships']['field_topic_tasks_target_id']['label'] = 'field_topic_tasks';
  $handler->display->display_options['relationships']['field_topic_tasks_target_id']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_topic_tasks_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'listing__title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Introduction */
  $handler->display->display_options['fields']['field_core_introduction']['id'] = 'field_core_introduction';
  $handler->display->display_options['fields']['field_core_introduction']['table'] = 'field_data_field_core_introduction';
  $handler->display->display_options['fields']['field_core_introduction']['field'] = 'field_core_introduction';
  $handler->display->display_options['fields']['field_core_introduction']['relationship'] = 'field_topic_tasks_target_id';
  $handler->display->display_options['fields']['field_core_introduction']['label'] = '';
  $handler->display->display_options['fields']['field_core_introduction']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_core_introduction']['element_default_classes'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Related topic specific tasks */
  $handler = $view->new_display('block', 'Related topic specific tasks', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_topic_tasks_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'listing__title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_toplink_description']['id'] = 'field_toplink_description';
  $handler->display->display_options['fields']['field_toplink_description']['table'] = 'field_data_field_toplink_description';
  $handler->display->display_options['fields']['field_toplink_description']['field'] = 'field_toplink_description';
  $handler->display->display_options['fields']['field_toplink_description']['relationship'] = 'field_topic_tasks_target_id';
  $handler->display->display_options['fields']['field_toplink_description']['label'] = '';
  $handler->display->display_options['fields']['field_toplink_description']['element_label_colon'] = FALSE;

  /* Display: Related policy areas */
  $handler = $view->new_display('block', 'Related policy areas', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Policy areas';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_core_policy_areas_target_id']['id'] = 'field_core_policy_areas_target_id';
  $handler->display->display_options['relationships']['field_core_policy_areas_target_id']['table'] = 'field_data_field_core_policy_areas';
  $handler->display->display_options['relationships']['field_core_policy_areas_target_id']['field'] = 'field_core_policy_areas_target_id';
  $handler->display->display_options['relationships']['field_core_policy_areas_target_id']['label'] = 'field_core_policy_areas';
  $handler->display->display_options['relationships']['field_core_policy_areas_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_core_policy_areas_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'listing__title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Introduction */
  $handler->display->display_options['fields']['field_core_introduction']['id'] = 'field_core_introduction';
  $handler->display->display_options['fields']['field_core_introduction']['table'] = 'field_data_field_core_introduction';
  $handler->display->display_options['fields']['field_core_introduction']['field'] = 'field_core_introduction';
  $handler->display->display_options['fields']['field_core_introduction']['relationship'] = 'field_core_policy_areas_target_id';
  $handler->display->display_options['fields']['field_core_introduction']['label'] = '';
  $handler->display->display_options['fields']['field_core_introduction']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_core_introduction']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $export['topic_related_content'] = $view;

  return $export;
}
