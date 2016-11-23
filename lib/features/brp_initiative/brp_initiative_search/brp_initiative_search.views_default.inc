<?php

/**
 * @file
 * brp_initiative_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function brp_initiative_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'brp_initiatives_homepage';
  $view->description = '';
  $view->tag = 'digital_transformation';
  $view->base_table = 'search_api_index_brp_initiatives_index';
  $view->human_name = 'BRP Initiatives homepage';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest initiatives';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'all initiatives';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'initiatives';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'nexteuropa_bem_listing';
  $handler->display->display_options['style_options']['listing_columns'] = 'default';
  $handler->display->display_options['style_options']['listing_modifier'] = '';
  $handler->display->display_options['style_options']['listing_wrapper_modifier'] = '';
  $handler->display->display_options['style_options']['listing_item_modifier'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Indexed Node: Name */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  /* Field: Content: Rendered Node */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'teaser';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Sort criterion: Indexed Node: Initiative ID */
  $handler->display->display_options['sorts']['field_brp_inve_id']['id'] = 'field_brp_inve_id';
  $handler->display->display_options['sorts']['field_brp_inve_id']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['sorts']['field_brp_inve_id']['field'] = 'field_brp_inve_id';
  $handler->display->display_options['sorts']['field_brp_inve_id']['order'] = 'DESC';
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'brp_initiative' => 'brp_initiative',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Latest initiatives block */
  $handler = $view->new_display('block', 'Latest initiatives block', 'block_latest_initiatives');
  $handler->display->display_options['link_url'] = 'initiatives';
  $handler->display->display_options['block_description'] = 'Latest initiatives';
  $export['brp_initiatives_homepage'] = $view;

  $view = new view();
  $view->name = 'brp_initiatives_search_api';
  $view->description = '';
  $view->tag = 'digital_transformation';
  $view->base_table = 'search_api_index_brp_initiatives_index';
  $view->human_name = 'BRP Initiatives (search api)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Published initiatives';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'nexteuropa_bem_listing';
  $handler->display->display_options['style_options']['listing_columns'] = 'default';
  $handler->display->display_options['style_options']['listing_modifier'] = '';
  $handler->display->display_options['style_options']['listing_wrapper_modifier'] = '';
  $handler->display->display_options['style_options']['listing_item_modifier'] = '';
  $handler->display->display_options['row_plugin'] = 'entity';
  /* Field: Indexed Node: Name */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  /* Field: Content: Rendered Node */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'teaser';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Sort criterion: Indexed Node: Feedback start date */
  $handler->display->display_options['sorts']['field_brp_inve_fb_start_date']['id'] = 'field_brp_inve_fb_start_date';
  $handler->display->display_options['sorts']['field_brp_inve_fb_start_date']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['sorts']['field_brp_inve_fb_start_date']['field'] = 'field_brp_inve_fb_start_date';
  $handler->display->display_options['sorts']['field_brp_inve_fb_start_date']['order'] = 'DESC';
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'brp_initiative' => 'brp_initiative',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Node: Resource type */
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['id'] = 'field_brp_inve_resource_type';
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['field'] = 'field_brp_inve_resource_type';
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['value'] = array();
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['group'] = 1;
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['expose']['operator_id'] = 'field_brp_inve_resource_type_op';
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['expose']['label'] = 'Type of initiative';
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['expose']['operator'] = 'field_brp_inve_resource_type_op';
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['expose']['identifier'] = 'field_brp_inve_resource_type';
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Feedback start date */
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['id'] = 'field_brp_inve_fb_start_date';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['field'] = 'field_brp_inve_fb_start_date';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['operator'] = '>=';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['group'] = 1;
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['expose']['operator_id'] = 'field_brp_inve_fb_start_date_op';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['expose']['label'] = 'Feedback open from';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['expose']['operator'] = 'field_brp_inve_fb_start_date_op';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['expose']['identifier'] = 'field_brp_inve_fb_start_date';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['widget_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['date_popup_format'] = 'Y-m-d';
  /* Filter criterion: Indexed Node: Feedback end date */
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['id'] = 'field_brp_inve_fb_end_date';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['field'] = 'field_brp_inve_fb_end_date';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['operator'] = '<=';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['group'] = 1;
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['expose']['operator_id'] = 'field_brp_inve_fb_end_date_op';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['expose']['label'] = 'Feedback closed by';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['expose']['operator'] = 'field_brp_inve_fb_end_date_op';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['expose']['identifier'] = 'field_brp_inve_fb_end_date';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['widget_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['date_popup_format'] = 'Y-m-d';
  /* Filter criterion: Indexed Node: Leading Service */
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['id'] = 'field_brp_inve_leading_service';
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['field'] = 'field_brp_inve_leading_service';
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['value'] = array();
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['group'] = 1;
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['expose']['operator_id'] = 'field_brp_inve_leading_service_op';
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['expose']['label'] = 'Department';
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['expose']['operator'] = 'field_brp_inve_leading_service_op';
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['expose']['identifier'] = 'field_brp_inve_leading_service';
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['expose']['reduce'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'nexteuropa_bem_listing';
  $handler->display->display_options['style_options']['listing_columns'] = 'default';
  $handler->display->display_options['style_options']['listing_modifier'] = '';
  $handler->display->display_options['style_options']['listing_wrapper_modifier'] = '';
  $handler->display->display_options['style_options']['listing_item_modifier'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Nexteuropa result summary */
  $handler->display->display_options['header']['result_nexteuropa']['id'] = 'result_nexteuropa';
  $handler->display->display_options['header']['result_nexteuropa']['table'] = 'views';
  $handler->display->display_options['header']['result_nexteuropa']['field'] = 'result_nexteuropa';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Contains */
  $handler->display->display_options['filters']['search_api_aggregation_1']['id'] = 'search_api_aggregation_1';
  $handler->display->display_options['filters']['search_api_aggregation_1']['table'] = 'search_api_index_brp_initiatives_index';
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
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'brp_initiative' => 'brp_initiative',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Node: Resource type */
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['id'] = 'field_brp_inve_resource_type';
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['field'] = 'field_brp_inve_resource_type';
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['value'] = array();
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['group'] = 1;
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['expose']['operator_id'] = 'field_brp_inve_resource_type_op';
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['expose']['label'] = 'Type of initiative';
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['expose']['operator'] = 'field_brp_inve_resource_type_op';
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['expose']['identifier'] = 'field_brp_inve_resource_type';
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Feedback start date */
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['id'] = 'field_brp_inve_fb_start_date';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['field'] = 'field_brp_inve_fb_start_date';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['operator'] = '>=';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['group'] = 1;
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['expose']['operator_id'] = 'field_brp_inve_fb_start_date_op';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['expose']['label'] = 'Feedback open from';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['expose']['operator'] = 'field_brp_inve_fb_start_date_op';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['expose']['identifier'] = 'field_brp_inve_fb_start_date';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['widget_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['date_popup_format'] = 'Y-m-d';
  /* Filter criterion: Indexed Node: Feedback end date */
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['id'] = 'field_brp_inve_fb_end_date';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['field'] = 'field_brp_inve_fb_end_date';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['operator'] = '<=';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['group'] = 1;
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['expose']['operator_id'] = 'field_brp_inve_fb_end_date_op';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['expose']['label'] = 'Feedback closed by';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['expose']['operator'] = 'field_brp_inve_fb_end_date_op';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['expose']['identifier'] = 'field_brp_inve_fb_end_date';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['widget_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['date_popup_format'] = 'Y-m-d';
  /* Filter criterion: Indexed Node: Leading Service */
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['id'] = 'field_brp_inve_leading_service';
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['field'] = 'field_brp_inve_leading_service';
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['value'] = array();
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['group'] = 1;
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['expose']['operator_id'] = 'field_brp_inve_leading_service_op';
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['expose']['label'] = 'Department';
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['expose']['operator'] = 'field_brp_inve_leading_service_op';
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['expose']['identifier'] = 'field_brp_inve_leading_service';
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Reference */
  $handler->display->display_options['filters']['field_brp_inve_reference']['id'] = 'field_brp_inve_reference';
  $handler->display->display_options['filters']['field_brp_inve_reference']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['filters']['field_brp_inve_reference']['field'] = 'field_brp_inve_reference';
  $handler->display->display_options['filters']['field_brp_inve_reference']['group'] = 1;
  $handler->display->display_options['filters']['field_brp_inve_reference']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_brp_inve_reference']['expose']['operator_id'] = 'field_brp_inve_reference_op';
  $handler->display->display_options['filters']['field_brp_inve_reference']['expose']['label'] = 'Reference';
  $handler->display->display_options['filters']['field_brp_inve_reference']['expose']['operator'] = 'field_brp_inve_reference_op';
  $handler->display->display_options['filters']['field_brp_inve_reference']['expose']['identifier'] = 'field_brp_inve_reference';
  $handler->display->display_options['filters']['field_brp_inve_reference']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['dt_shared_functions_views_config_title'] = 'Initiatives';
  $handler->display->display_options['path'] = 'initiatives';

  /* Display: Page for initiatives management */
  $handler = $view->new_display('page', 'Page for initiatives management', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Admin initiatives content';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
  );
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title_field' => 'title_field',
    'rendered_entity' => 'rendered_entity',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title_field' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rendered_entity' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Name */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  /* Field: Indexed Node: Initiative ID */
  $handler->display->display_options['fields']['field_brp_inve_id']['id'] = 'field_brp_inve_id';
  $handler->display->display_options['fields']['field_brp_inve_id']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['fields']['field_brp_inve_id']['field'] = 'field_brp_inve_id';
  $handler->display->display_options['fields']['field_brp_inve_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Indexed Node: Description */
  $handler->display->display_options['fields']['field_core_description']['id'] = 'field_core_description';
  $handler->display->display_options['fields']['field_core_description']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['fields']['field_core_description']['field'] = 'field_core_description';
  /* Field: Indexed Node: Leading Service */
  $handler->display->display_options['fields']['field_brp_inve_leading_service']['id'] = 'field_brp_inve_leading_service';
  $handler->display->display_options['fields']['field_brp_inve_leading_service']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['fields']['field_brp_inve_leading_service']['field'] = 'field_brp_inve_leading_service';
  $handler->display->display_options['fields']['field_brp_inve_leading_service']['label'] = 'Department';
  $handler->display->display_options['fields']['field_brp_inve_leading_service']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_brp_inve_leading_service']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_brp_inve_leading_service']['bypass_access'] = 0;
  /* Field: Indexed Node: Initiative Status */
  $handler->display->display_options['fields']['field_brp_inve_initiative_status']['id'] = 'field_brp_inve_initiative_status';
  $handler->display->display_options['fields']['field_brp_inve_initiative_status']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['fields']['field_brp_inve_initiative_status']['field'] = 'field_brp_inve_initiative_status';
  /* Field: Indexed Node: Feedback count */
  $handler->display->display_options['fields']['field_brp_inve_fb_count']['id'] = 'field_brp_inve_fb_count';
  $handler->display->display_options['fields']['field_brp_inve_fb_count']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['fields']['field_brp_inve_fb_count']['field'] = 'field_brp_inve_fb_count';
  $handler->display->display_options['fields']['field_brp_inve_fb_count']['label'] = 'Fb #';
  $handler->display->display_options['fields']['field_brp_inve_fb_count']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Indexed Node: Feedback start date */
  $handler->display->display_options['fields']['field_brp_inve_fb_start_date']['id'] = 'field_brp_inve_fb_start_date';
  $handler->display->display_options['fields']['field_brp_inve_fb_start_date']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['fields']['field_brp_inve_fb_start_date']['field'] = 'field_brp_inve_fb_start_date';
  $handler->display->display_options['fields']['field_brp_inve_fb_start_date']['settings'] = array(
    'format_type' => 'ec_date_j_f_y',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Indexed Node: Feedback end date */
  $handler->display->display_options['fields']['field_brp_inve_fb_end_date']['id'] = 'field_brp_inve_fb_end_date';
  $handler->display->display_options['fields']['field_brp_inve_fb_end_date']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['fields']['field_brp_inve_fb_end_date']['field'] = 'field_brp_inve_fb_end_date';
  $handler->display->display_options['fields']['field_brp_inve_fb_end_date']['settings'] = array(
    'format_type' => 'ec_date_j_f_y',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Indexed Node: Initiatitve modified date */
  $handler->display->display_options['fields']['field_brp_inve_modified_date']['id'] = 'field_brp_inve_modified_date';
  $handler->display->display_options['fields']['field_brp_inve_modified_date']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['fields']['field_brp_inve_modified_date']['field'] = 'field_brp_inve_modified_date';
  $handler->display->display_options['fields']['field_brp_inve_modified_date']['settings'] = array(
    'format_type' => 'ec_date_j_f_y',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Indexed Node: Initiative Publication date */
  $handler->display->display_options['fields']['field_brp_inve_publication_date']['id'] = 'field_brp_inve_publication_date';
  $handler->display->display_options['fields']['field_brp_inve_publication_date']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['fields']['field_brp_inve_publication_date']['field'] = 'field_brp_inve_publication_date';
  $handler->display->display_options['fields']['field_brp_inve_publication_date']['label'] = 'Init. Pub. date';
  $handler->display->display_options['fields']['field_brp_inve_publication_date']['settings'] = array(
    'format_type' => 'ec_date_j_f_y',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'brp_initiative' => 'brp_initiative',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Node: Initiative ID */
  $handler->display->display_options['filters']['field_brp_inve_id']['id'] = 'field_brp_inve_id';
  $handler->display->display_options['filters']['field_brp_inve_id']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['filters']['field_brp_inve_id']['field'] = 'field_brp_inve_id';
  $handler->display->display_options['filters']['field_brp_inve_id']['group'] = 1;
  $handler->display->display_options['filters']['field_brp_inve_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_brp_inve_id']['expose']['operator_id'] = 'field_brp_inve_id_op';
  $handler->display->display_options['filters']['field_brp_inve_id']['expose']['label'] = 'Initiative ID';
  $handler->display->display_options['filters']['field_brp_inve_id']['expose']['operator'] = 'field_brp_inve_id_op';
  $handler->display->display_options['filters']['field_brp_inve_id']['expose']['identifier'] = 'field_brp_inve_id';
  $handler->display->display_options['filters']['field_brp_inve_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  /* Filter criterion: Indexed Node: Contains */
  $handler->display->display_options['filters']['search_api_aggregation_1']['id'] = 'search_api_aggregation_1';
  $handler->display->display_options['filters']['search_api_aggregation_1']['table'] = 'search_api_index_brp_initiatives_index';
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
    6 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Indexed Node: Resource type */
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['id'] = 'field_brp_inve_resource_type';
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['field'] = 'field_brp_inve_resource_type';
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['value'] = array();
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['group'] = 1;
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['expose']['operator_id'] = 'field_brp_inve_resource_type_op';
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['expose']['label'] = 'Resource type';
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['expose']['operator'] = 'field_brp_inve_resource_type_op';
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['expose']['identifier'] = 'field_brp_inve_resource_type';
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_brp_inve_resource_type']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Leading Service */
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['id'] = 'field_brp_inve_leading_service';
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['field'] = 'field_brp_inve_leading_service';
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['value'] = array();
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['group'] = 1;
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['expose']['operator_id'] = 'field_brp_inve_leading_service_op';
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['expose']['label'] = 'Department';
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['expose']['operator'] = 'field_brp_inve_leading_service_op';
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['expose']['identifier'] = 'field_brp_inve_leading_service';
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_brp_inve_leading_service']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Feedback start date */
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['id'] = 'field_brp_inve_fb_start_date';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['field'] = 'field_brp_inve_fb_start_date';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['operator'] = '>=';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['group'] = 1;
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['expose']['operator_id'] = 'field_brp_inve_fb_start_date_op';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['expose']['label'] = 'Feedback open from';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['expose']['operator'] = 'field_brp_inve_fb_start_date_op';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['expose']['identifier'] = 'field_brp_inve_fb_start_date';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['widget_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_brp_inve_fb_start_date']['date_popup_format'] = 'Y-m-d';
  /* Filter criterion: Indexed Node: Feedback end date */
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['id'] = 'field_brp_inve_fb_end_date';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['field'] = 'field_brp_inve_fb_end_date';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['operator'] = '<=';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['group'] = 1;
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['expose']['operator_id'] = 'field_brp_inve_fb_end_date_op';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['expose']['label'] = 'Feedback closed by';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['expose']['operator'] = 'field_brp_inve_fb_end_date_op';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['expose']['identifier'] = 'field_brp_inve_fb_end_date';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['widget_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_brp_inve_fb_end_date']['date_popup_format'] = 'Y-m-d';
  /* Filter criterion: Indexed Node: Initiatitve modified date */
  $handler->display->display_options['filters']['field_brp_inve_modified_date']['id'] = 'field_brp_inve_modified_date';
  $handler->display->display_options['filters']['field_brp_inve_modified_date']['table'] = 'search_api_index_brp_initiatives_index';
  $handler->display->display_options['filters']['field_brp_inve_modified_date']['field'] = 'field_brp_inve_modified_date';
  $handler->display->display_options['filters']['field_brp_inve_modified_date']['operator'] = '<=';
  $handler->display->display_options['filters']['field_brp_inve_modified_date']['group'] = 1;
  $handler->display->display_options['filters']['field_brp_inve_modified_date']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_brp_inve_modified_date']['expose']['operator_id'] = 'field_brp_inve_modified_date_op';
  $handler->display->display_options['filters']['field_brp_inve_modified_date']['expose']['label'] = 'Initiatitve modified date';
  $handler->display->display_options['filters']['field_brp_inve_modified_date']['expose']['operator'] = 'field_brp_inve_modified_date_op';
  $handler->display->display_options['filters']['field_brp_inve_modified_date']['expose']['identifier'] = 'field_brp_inve_modified_date';
  $handler->display->display_options['filters']['field_brp_inve_modified_date']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_brp_inve_modified_date']['widget_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_brp_inve_modified_date']['date_popup_format'] = 'Y-m-d';
  $handler->display->display_options['path'] = 'admin/manage-initiatives';
  $export['brp_initiatives_search_api'] = $view;

  return $export;
}
