<?php
/**
 * @file
 * dt_policy.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dt_policy_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'policy_overview';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Policy overview';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Policies';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Clear all';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'nexteuropa_bem_listing';
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['style_options']['listing_columns'] = 'default';
  $handler->display->display_options['style_options']['listing_modifier'] = '';
  $handler->display->display_options['style_options']['listing_wrapper_modifier'] = '';
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'title';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'field_data_title_field|title_field_value';
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
  $handler->display->display_options['fields']['field_core_description']['label'] = '';
  $handler->display->display_options['fields']['field_core_description']['element_label_colon'] = FALSE;
  /* Field: Content: Introduction */
  $handler->display->display_options['fields']['field_core_introduction']['id'] = 'field_core_introduction';
  $handler->display->display_options['fields']['field_core_introduction']['table'] = 'field_data_field_core_introduction';
  $handler->display->display_options['fields']['field_core_introduction']['field'] = 'field_core_introduction';
  $handler->display->display_options['fields']['field_core_introduction']['label'] = '';
  $handler->display->display_options['fields']['field_core_introduction']['element_label_colon'] = FALSE;
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
    'policy' => 'policy',
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
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'keyword';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_core_description' => 'field_core_description',
    'field_core_introduction' => 'field_core_introduction',
  );
  /* Filter criterion: Content: Policy areas (field_core_policy_areas) */
  $handler->display->display_options['filters']['field_core_policy_areas_target_id']['id'] = 'field_core_policy_areas_target_id';
  $handler->display->display_options['filters']['field_core_policy_areas_target_id']['table'] = 'field_data_field_core_policy_areas';
  $handler->display->display_options['filters']['field_core_policy_areas_target_id']['field'] = 'field_core_policy_areas_target_id';
  $handler->display->display_options['filters']['field_core_policy_areas_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_policy_areas_target_id']['expose']['operator_id'] = 'field_core_policy_areas_target_id_op';
  $handler->display->display_options['filters']['field_core_policy_areas_target_id']['expose']['label'] = 'by policy area';
  $handler->display->display_options['filters']['field_core_policy_areas_target_id']['expose']['operator'] = 'field_core_policy_areas_target_id_op';
  $handler->display->display_options['filters']['field_core_policy_areas_target_id']['expose']['identifier'] = 'policy_area';
  $handler->display->display_options['filters']['field_core_policy_areas_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );

  /* Display: Policy overview page */
  $handler = $view->new_display('page', 'Policy overview page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'policies';
  $export['policy_overview'] = $view;

  return $export;
}
