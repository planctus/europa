<?php
/**
 * @file
 * dt_event.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dt_event_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'filter_list_event';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Filter list - Event (Content)';
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Contextual filter: Content: What do you want to create? (field_event_collection) */
  $handler->display->display_options['arguments']['field_event_collection_value']['id'] = 'field_event_collection_value';
  $handler->display->display_options['arguments']['field_event_collection_value']['table'] = 'field_data_field_event_collection';
  $handler->display->display_options['arguments']['field_event_collection_value']['field'] = 'field_event_collection_value';
  $handler->display->display_options['arguments']['field_event_collection_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_event_collection_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_event_collection_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_event_collection_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_event_collection_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_event_collection_value']['limit'] = '0';
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
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
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
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['filter_list_event'] = $view;

  $view = new view();
  $view->name = 'related_events';
  $view->description = 'Block that shows events related to a event, or events in a collection';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Related events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Related events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'nexteuropa_bem_listing';
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['style_options']['listing_columns'] = 'two_columns';
  $handler->display->display_options['style_options']['listing_modifier'] = '';
  $handler->display->display_options['style_options']['listing_wrapper_modifier'] = '';
  $handler->display->display_options['style_options']['listing_item_modifier'] = 'listing--teaser';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['relationship'] = 'field_event_children_events_target_id';
  $handler->display->display_options['row_options']['view_mode'] = 'meta';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = 'More about [title] | %all_events_link';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  /* Relationship: Parent entity */
  $handler->display->display_options['relationships']['field_event_parent_events_target_id']['id'] = 'field_event_parent_events_target_id';
  $handler->display->display_options['relationships']['field_event_parent_events_target_id']['table'] = 'field_data_field_event_parent_events';
  $handler->display->display_options['relationships']['field_event_parent_events_target_id']['field'] = 'field_event_parent_events_target_id';
  $handler->display->display_options['relationships']['field_event_parent_events_target_id']['ui_name'] = 'Parent entity';
  $handler->display->display_options['relationships']['field_event_parent_events_target_id']['label'] = 'Parent entity';
  $handler->display->display_options['relationships']['field_event_parent_events_target_id']['required'] = TRUE;
  /* Relationship: Children of parent */
  $handler->display->display_options['relationships']['field_event_children_events_target_id']['id'] = 'field_event_children_events_target_id';
  $handler->display->display_options['relationships']['field_event_children_events_target_id']['table'] = 'field_data_field_event_children_events';
  $handler->display->display_options['relationships']['field_event_children_events_target_id']['field'] = 'field_event_children_events_target_id';
  $handler->display->display_options['relationships']['field_event_children_events_target_id']['relationship'] = 'field_event_parent_events_target_id';
  $handler->display->display_options['relationships']['field_event_children_events_target_id']['ui_name'] = 'Children of parent';
  $handler->display->display_options['relationships']['field_event_children_events_target_id']['label'] = 'Children of parent';
  $handler->display->display_options['relationships']['field_event_children_events_target_id']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_event_parent_events_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Event date and time -  start date (field_event_date) */
  $handler->display->display_options['sorts']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['sorts']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['sorts']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['sorts']['field_event_date_value']['relationship'] = 'field_event_children_events_target_id';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'event' => 'event',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_event_children_events_target_id';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_event_children_events_target_id';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: What do you want to create? (field_event_collection) */
  $handler->display->display_options['filters']['field_event_collection_value']['id'] = 'field_event_collection_value';
  $handler->display->display_options['filters']['field_event_collection_value']['table'] = 'field_data_field_event_collection';
  $handler->display->display_options['filters']['field_event_collection_value']['field'] = 'field_event_collection_value';
  $handler->display->display_options['filters']['field_event_collection_value']['relationship'] = 'field_event_parent_events_target_id';
  $handler->display->display_options['filters']['field_event_collection_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: What do you want to create? (field_event_collection) */
  $handler->display->display_options['filters']['field_event_collection_value_1']['id'] = 'field_event_collection_value_1';
  $handler->display->display_options['filters']['field_event_collection_value_1']['table'] = 'field_data_field_event_collection';
  $handler->display->display_options['filters']['field_event_collection_value_1']['field'] = 'field_event_collection_value';
  $handler->display->display_options['filters']['field_event_collection_value_1']['relationship'] = 'field_event_children_events_target_id';
  $handler->display->display_options['filters']['field_event_collection_value_1']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'field_event_children_events_target_id';
  $handler->display->display_options['filters']['nid']['operator'] = '!=';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['related_events'] = $view;

  return $export;
}
