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
  $view->name = 'events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_event_index';
  $view->human_name = 'Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['css_class'] = 'has_date_popups';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'nexteuropa_bem_listing';
  $handler->display->display_options['style_options']['listing_columns'] = 'default';
  $handler->display->display_options['style_options']['listing_modifier'] = 'listing--column-left';
  $handler->display->display_options['style_options']['listing_wrapper_modifier'] = '';
  $handler->display->display_options['style_options']['listing_item_modifier'] = '';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'meta';
  /* Contextual filter: Indexed Node: Part of collection */
  $handler->display->display_options['arguments']['field_event_parent_events']['id'] = 'field_event_parent_events';
  $handler->display->display_options['arguments']['field_event_parent_events']['table'] = 'search_api_index_event_index';
  $handler->display->display_options['arguments']['field_event_parent_events']['field'] = 'field_event_parent_events';
  $handler->display->display_options['arguments']['field_event_parent_events']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_event_parent_events']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_event_parent_events']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_event_parent_events']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_event_parent_events']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_event_parent_events']['validate']['type'] = 'numeric';
  $handler->display->display_options['arguments']['field_event_parent_events']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['field_event_parent_events']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_event_parent_events']['not'] = 0;
  /* Filter criterion: Indexed Node: fulltext search */
  $handler->display->display_options['filters']['search_api_aggregation_1']['id'] = 'search_api_aggregation_1';
  $handler->display->display_options['filters']['search_api_aggregation_1']['table'] = 'search_api_index_event_index';
  $handler->display->display_options['filters']['search_api_aggregation_1']['field'] = 'search_api_aggregation_1';
  $handler->display->display_options['filters']['search_api_aggregation_1']['group'] = 1;
  $handler->display->display_options['filters']['search_api_aggregation_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['operator_id'] = 'search_api_aggregation_1_op';
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['label'] = 'Contains';
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['operator'] = 'search_api_aggregation_1_op';
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['identifier'] = 'search_api_aggregation_1';
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Facets: Exposed facet */
  $handler->display->display_options['filters']['facet_filter']['id'] = 'facet_filter';
  $handler->display->display_options['filters']['facet_filter']['table'] = 'facets';
  $handler->display->display_options['filters']['facet_filter']['field'] = 'facet_filter';
  $handler->display->display_options['filters']['facet_filter']['group'] = 1;
  $handler->display->display_options['filters']['facet_filter']['expose']['operator_id'] = 'facet_filter_op';
  $handler->display->display_options['filters']['facet_filter']['expose']['label'] = 'Topic';
  $handler->display->display_options['filters']['facet_filter']['expose']['operator'] = 'facet_filter_op';
  $handler->display->display_options['filters']['facet_filter']['expose']['identifier'] = 'facet_filter';
  $handler->display->display_options['filters']['facet_filter']['facet']['facet'] = 'field_core_topics';
  /* Filter criterion: Facets: Exposed facet */
  $handler->display->display_options['filters']['facet_filter_3']['id'] = 'facet_filter_3';
  $handler->display->display_options['filters']['facet_filter_3']['table'] = 'facets';
  $handler->display->display_options['filters']['facet_filter_3']['field'] = 'facet_filter';
  $handler->display->display_options['filters']['facet_filter_3']['group'] = 1;
  $handler->display->display_options['filters']['facet_filter_3']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['facet_filter_3']['expose']['label'] = 'Event type';
  $handler->display->display_options['filters']['facet_filter_3']['expose']['identifier'] = 'facet_event_type';
  $handler->display->display_options['filters']['facet_filter_3']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['facet_filter_3']['facet']['facet'] = 'field_event_type';
  /* Filter criterion: Facets: Exposed facet */
  $handler->display->display_options['filters']['facet_filter_5']['id'] = 'facet_filter_5';
  $handler->display->display_options['filters']['facet_filter_5']['table'] = 'facets';
  $handler->display->display_options['filters']['facet_filter_5']['field'] = 'facet_filter';
  $handler->display->display_options['filters']['facet_filter_5']['group'] = 1;
  $handler->display->display_options['filters']['facet_filter_5']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['facet_filter_5']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['facet_filter_5']['expose']['operator'] = 'facet_filter_5_op';
  $handler->display->display_options['filters']['facet_filter_5']['expose']['identifier'] = 'facet_filter_5';
  $handler->display->display_options['filters']['facet_filter_5']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['facet_filter_5']['facet']['facet'] = 'field_core_location:country';
  /* Filter criterion: Facets: Exposed facet */
  $handler->display->display_options['filters']['facet_filter_4']['id'] = 'facet_filter_4';
  $handler->display->display_options['filters']['facet_filter_4']['table'] = 'facets';
  $handler->display->display_options['filters']['facet_filter_4']['field'] = 'facet_filter';
  $handler->display->display_options['filters']['facet_filter_4']['group'] = 1;
  $handler->display->display_options['filters']['facet_filter_4']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['facet_filter_4']['expose']['operator'] = 'facet_filter_4_op';
  $handler->display->display_options['filters']['facet_filter_4']['expose']['identifier'] = 'facet_filter_4';
  $handler->display->display_options['filters']['facet_filter_4']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['facet_filter_4']['facet']['facet'] = 'field_event_is_online';
  /* Filter criterion: Facets: Exposed facet */
  $handler->display->display_options['filters']['facet_filter_1']['id'] = 'facet_filter_1';
  $handler->display->display_options['filters']['facet_filter_1']['table'] = 'facets';
  $handler->display->display_options['filters']['facet_filter_1']['field'] = 'facet_filter';
  $handler->display->display_options['filters']['facet_filter_1']['group'] = 1;
  $handler->display->display_options['filters']['facet_filter_1']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['facet_filter_1']['expose']['operator'] = 'facet_filter_1_op';
  $handler->display->display_options['filters']['facet_filter_1']['expose']['identifier'] = 'facet_filter_1';
  $handler->display->display_options['filters']['facet_filter_1']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['facet_filter_1']['facet']['facet'] = 'field_event_is_live_streaming';
  /* Filter criterion: Facets: Exposed facet */
  $handler->display->display_options['filters']['facet_filter_2']['id'] = 'facet_filter_2';
  $handler->display->display_options['filters']['facet_filter_2']['table'] = 'facets';
  $handler->display->display_options['filters']['facet_filter_2']['field'] = 'facet_filter';
  $handler->display->display_options['filters']['facet_filter_2']['group'] = 1;
  $handler->display->display_options['filters']['facet_filter_2']['expose']['operator_id'] = 'facet_filter_2_op';
  $handler->display->display_options['filters']['facet_filter_2']['expose']['label'] = 'Departments';
  $handler->display->display_options['filters']['facet_filter_2']['expose']['operator'] = 'facet_filter_2_op';
  $handler->display->display_options['filters']['facet_filter_2']['expose']['identifier'] = 'facet_filter_2';
  $handler->display->display_options['filters']['facet_filter_2']['facet']['facet'] = 'field_core_departments';
  /* Filter criterion: Event date and time: Start date (indexed) */
  $handler->display->display_options['filters']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['table'] = 'search_api_index_event_index';
  $handler->display->display_options['filters']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_event_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_event_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_date_value']['expose']['operator_id'] = 'field_event_date_value_op';
  $handler->display->display_options['filters']['field_event_date_value']['expose']['label'] = 'After';
  $handler->display->display_options['filters']['field_event_date_value']['expose']['operator'] = 'field_event_date_value_op';
  $handler->display->display_options['filters']['field_event_date_value']['expose']['identifier'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_event_date_value']['widget_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_event_date_value']['date_popup_format'] = 'Y-m-d';
  /* Filter criterion: Event date and time: Start date (indexed) */
  $handler->display->display_options['filters']['field_event_date_value_1']['id'] = 'field_event_date_value_1';
  $handler->display->display_options['filters']['field_event_date_value_1']['table'] = 'search_api_index_event_index';
  $handler->display->display_options['filters']['field_event_date_value_1']['field'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value_1']['operator'] = '<=';
  $handler->display->display_options['filters']['field_event_date_value_1']['group'] = 1;
  $handler->display->display_options['filters']['field_event_date_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_date_value_1']['expose']['operator_id'] = 'field_event_date_value_1_op';
  $handler->display->display_options['filters']['field_event_date_value_1']['expose']['label'] = 'Before';
  $handler->display->display_options['filters']['field_event_date_value_1']['expose']['operator'] = 'field_event_date_value_1_op';
  $handler->display->display_options['filters']['field_event_date_value_1']['expose']['identifier'] = 'field_event_date_value_1';
  $handler->display->display_options['filters']['field_event_date_value_1']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_event_date_value_1']['widget_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_event_date_value_1']['date_popup_format'] = 'Y-m-d';
  /* Filter criterion: Indexed Node: What do you want to create? */
  $handler->display->display_options['filters']['field_event_collection']['id'] = 'field_event_collection';
  $handler->display->display_options['filters']['field_event_collection']['table'] = 'search_api_index_event_index';
  $handler->display->display_options['filters']['field_event_collection']['field'] = 'field_event_collection';
  $handler->display->display_options['filters']['field_event_collection']['value'] = array(
    0 => '0',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['dt_shared_functions_views_config_title'] = 'Events';
  $handler->display->display_options['path'] = 'events';
  $export['events'] = $view;

  $view = new view();
  $view->name = 'events_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Events list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events list';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'All events for [node_title]';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'nexteuropa_bem_listing';
  $handler->display->display_options['style_options']['listing_columns'] = 'default';
  $handler->display->display_options['style_options']['listing_modifier'] = 'listing--column-left';
  $handler->display->display_options['style_options']['listing_wrapper_modifier'] = '';
  $handler->display->display_options['style_options']['listing_item_modifier'] = 'listing__item--fullwidth';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['relationship'] = 'field_event_children_events_target_id';
  $handler->display->display_options['row_options']['view_mode'] = 'meta';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No future or ongoing events.';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_event_children_events_target_id']['id'] = 'field_event_children_events_target_id';
  $handler->display->display_options['relationships']['field_event_children_events_target_id']['table'] = 'field_data_field_event_children_events';
  $handler->display->display_options['relationships']['field_event_children_events_target_id']['field'] = 'field_event_children_events_target_id';
  $handler->display->display_options['relationships']['field_event_children_events_target_id']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Event date and time - end date (field_event_date:value2) */
  $handler->display->display_options['sorts']['field_event_date_value2']['id'] = 'field_event_date_value2';
  $handler->display->display_options['sorts']['field_event_date_value2']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['sorts']['field_event_date_value2']['field'] = 'field_event_date_value2';
  $handler->display->display_options['sorts']['field_event_date_value2']['relationship'] = 'field_event_children_events_target_id';
  $handler->display->display_options['sorts']['field_event_date_value2']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'empty';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_event_children_events_target_id';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Cancelled or rescheduled (field_event_status) */
  $handler->display->display_options['filters']['field_event_status_value']['id'] = 'field_event_status_value';
  $handler->display->display_options['filters']['field_event_status_value']['table'] = 'field_data_field_event_status';
  $handler->display->display_options['filters']['field_event_status_value']['field'] = 'field_event_status_value';
  $handler->display->display_options['filters']['field_event_status_value']['relationship'] = 'field_event_children_events_target_id';
  $handler->display->display_options['filters']['field_event_status_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_event_status_value']['value'] = array(
    'cancelled' => 'cancelled',
  );
  /* Filter criterion: Content: Event date and time - end date (field_event_date:value2) */
  $handler->display->display_options['filters']['field_event_date_value2']['id'] = 'field_event_date_value2';
  $handler->display->display_options['filters']['field_event_date_value2']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['filters']['field_event_date_value2']['field'] = 'field_event_date_value2';
  $handler->display->display_options['filters']['field_event_date_value2']['relationship'] = 'field_event_children_events_target_id';
  $handler->display->display_options['filters']['field_event_date_value2']['operator'] = '<';
  $handler->display->display_options['filters']['field_event_date_value2']['granularity'] = 'second';
  $handler->display->display_options['filters']['field_event_date_value2']['default_date'] = 'now';
  /* Filter criterion: Content: What do you want to create? (field_event_collection) */
  $handler->display->display_options['filters']['field_event_collection_value']['id'] = 'field_event_collection_value';
  $handler->display->display_options['filters']['field_event_collection_value']['table'] = 'field_data_field_event_collection';
  $handler->display->display_options['filters']['field_event_collection_value']['field'] = 'field_event_collection_value';
  $handler->display->display_options['filters']['field_event_collection_value']['relationship'] = 'field_event_children_events_target_id';
  $handler->display->display_options['filters']['field_event_collection_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_event_collection_value']['value'] = array(
    1 => '1',
  );

  /* Display: Upcoming and current events */
  $handler = $view->new_display('block', 'Upcoming and current events', 'block');
  $handler->display->display_options['link_url'] = '/events/!1';

  /* Display: Past events */
  $handler = $view->new_display('block', 'Past events', 'block_1');
  $handler->display->display_options['link_url'] = '/events/!1';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_event_children_events_target_id';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Cancelled or rescheduled (field_event_status) */
  $handler->display->display_options['filters']['field_event_status_value']['id'] = 'field_event_status_value';
  $handler->display->display_options['filters']['field_event_status_value']['table'] = 'field_data_field_event_status';
  $handler->display->display_options['filters']['field_event_status_value']['field'] = 'field_event_status_value';
  $handler->display->display_options['filters']['field_event_status_value']['relationship'] = 'field_event_children_events_target_id';
  $handler->display->display_options['filters']['field_event_status_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_event_status_value']['value'] = array(
    'cancelled' => 'cancelled',
  );
  /* Filter criterion: Content: Event date and time - end date (field_event_date:value2) */
  $handler->display->display_options['filters']['field_event_date_value2']['id'] = 'field_event_date_value2';
  $handler->display->display_options['filters']['field_event_date_value2']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['filters']['field_event_date_value2']['field'] = 'field_event_date_value2';
  $handler->display->display_options['filters']['field_event_date_value2']['relationship'] = 'field_event_children_events_target_id';
  $handler->display->display_options['filters']['field_event_date_value2']['operator'] = '>';
  $handler->display->display_options['filters']['field_event_date_value2']['granularity'] = 'second';
  $handler->display->display_options['filters']['field_event_date_value2']['default_date'] = 'now';
  /* Filter criterion: Content: What do you want to create? (field_event_collection) */
  $handler->display->display_options['filters']['field_event_collection_value']['id'] = 'field_event_collection_value';
  $handler->display->display_options['filters']['field_event_collection_value']['table'] = 'field_data_field_event_collection';
  $handler->display->display_options['filters']['field_event_collection_value']['field'] = 'field_event_collection_value';
  $handler->display->display_options['filters']['field_event_collection_value']['relationship'] = 'field_event_children_events_target_id';
  $handler->display->display_options['filters']['field_event_collection_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_event_collection_value']['value'] = array(
    1 => '1',
  );
  $export['events_list'] = $view;

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
  $handler->display->display_options['style_options']['listing_modifier'] = 'listing--column-left';
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
