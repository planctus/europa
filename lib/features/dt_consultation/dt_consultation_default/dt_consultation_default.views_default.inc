<?php
/**
 * @file
 * dt_consultation_default.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dt_consultation_default_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'consultations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'consultations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Public consultations';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'nexteuropa_bem_listing';
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['style_options']['listing_columns'] = 'default';
  $handler->display->display_options['style_options']['listing_modifier'] = '';
  $handler->display->display_options['style_options']['listing_wrapper_modifier'] = '';
  $handler->display->display_options['style_options']['listing_item_modifier'] = '';
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'teaser';
  /* Field: Content: Policy areas */
  $handler->display->display_options['fields']['field_core_policy_areas']['id'] = 'field_core_policy_areas';
  $handler->display->display_options['fields']['field_core_policy_areas']['table'] = 'field_data_field_core_policy_areas';
  $handler->display->display_options['fields']['field_core_policy_areas']['field'] = 'field_core_policy_areas';
  $handler->display->display_options['fields']['field_core_policy_areas']['label'] = '';
  $handler->display->display_options['fields']['field_core_policy_areas']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_core_policy_areas']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_core_policy_areas']['delta_offset'] = '0';
  /* Field: Entity translation: How to submit your contribution: translated */
  $handler->display->display_options['fields']['field_consultation_how_to_submit_et']['id'] = 'field_consultation_how_to_submit_et';
  $handler->display->display_options['fields']['field_consultation_how_to_submit_et']['table'] = 'field_data_field_consultation_how_to_submit';
  $handler->display->display_options['fields']['field_consultation_how_to_submit_et']['field'] = 'field_consultation_how_to_submit_et';
  /* Field: Entity translation: Objective of the consultation: translated */
  $handler->display->display_options['fields']['field_consultation_objective_et']['id'] = 'field_consultation_objective_et';
  $handler->display->display_options['fields']['field_consultation_objective_et']['table'] = 'field_data_field_consultation_objective';
  $handler->display->display_options['fields']['field_consultation_objective_et']['field'] = 'field_consultation_objective_et';
  /* Field: Entity translation: View the questionnaire: translated */
  $handler->display->display_options['fields']['field_consultation_questionnaire_et']['id'] = 'field_consultation_questionnaire_et';
  $handler->display->display_options['fields']['field_consultation_questionnaire_et']['table'] = 'field_data_field_consultation_questionnaire';
  $handler->display->display_options['fields']['field_consultation_questionnaire_et']['field'] = 'field_consultation_questionnaire_et';
  /* Field: Entity translation: Target group(s): translated */
  $handler->display->display_options['fields']['field_consultation_target_groups_et']['id'] = 'field_consultation_target_groups_et';
  $handler->display->display_options['fields']['field_consultation_target_groups_et']['table'] = 'field_data_field_consultation_target_groups';
  $handler->display->display_options['fields']['field_consultation_target_groups_et']['field'] = 'field_consultation_target_groups_et';
  /* Sort criterion: Content: Status (field_consultation_status) */
  $handler->display->display_options['sorts']['field_consultation_status_value']['id'] = 'field_consultation_status_value';
  $handler->display->display_options['sorts']['field_consultation_status_value']['table'] = 'field_data_field_consultation_status';
  $handler->display->display_options['sorts']['field_consultation_status_value']['field'] = 'field_consultation_status_value';
  $handler->display->display_options['sorts']['field_consultation_status_value']['order'] = 'DESC';
  /* Sort criterion: Content: Closing date (field_core_date_closing) */
  $handler->display->display_options['sorts']['field_core_date_closing_value']['id'] = 'field_core_date_closing_value';
  $handler->display->display_options['sorts']['field_core_date_closing_value']['table'] = 'field_data_field_core_date_closing';
  $handler->display->display_options['sorts']['field_core_date_closing_value']['field'] = 'field_core_date_closing_value';
  /* Sort criterion: Content: Opening date (field_core_date_opening) */
  $handler->display->display_options['sorts']['field_core_date_opening_value']['id'] = 'field_core_date_opening_value';
  $handler->display->display_options['sorts']['field_core_date_opening_value']['table'] = 'field_data_field_core_date_opening';
  $handler->display->display_options['sorts']['field_core_date_opening_value']['field'] = 'field_core_date_opening_value';
  $handler->display->display_options['sorts']['field_core_date_opening_value']['order'] = 'DESC';
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
    'consultation' => 'consultation',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Contains';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    7 => 0,
    5 => 0,
    3 => 0,
    6 => 0,
    4 => 0,
    11 => 0,
    9 => 0,
    8 => 0,
    12 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_consultation_how_to_submit_et' => 'field_consultation_how_to_submit_et',
    'field_consultation_objective_et' => 'field_consultation_objective_et',
    'field_consultation_questionnaire_et' => 'field_consultation_questionnaire_et',
    'field_consultation_target_groups_et' => 'field_consultation_target_groups_et',
  );
  /* Filter criterion: Content: Status (field_consultation_status) */
  $handler->display->display_options['filters']['field_consultation_status_value']['id'] = 'field_consultation_status_value';
  $handler->display->display_options['filters']['field_consultation_status_value']['table'] = 'field_data_field_consultation_status';
  $handler->display->display_options['filters']['field_consultation_status_value']['field'] = 'field_consultation_status_value';
  $handler->display->display_options['filters']['field_consultation_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_consultation_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_consultation_status_value']['expose']['operator_id'] = 'field_consultation_status_value_op';
  $handler->display->display_options['filters']['field_consultation_status_value']['expose']['label'] = 'Consultation status';
  $handler->display->display_options['filters']['field_consultation_status_value']['expose']['operator'] = 'field_consultation_status_value_op';
  $handler->display->display_options['filters']['field_consultation_status_value']['expose']['identifier'] = 'field_consultation_status_value';
  $handler->display->display_options['filters']['field_consultation_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    14 => 0,
    7 => 0,
    12 => 0,
    9 => 0,
    18 => 0,
    10 => 0,
    15 => 0,
  );
  /* Filter criterion: Content: Opening date (field_core_date_opening) */
  $handler->display->display_options['filters']['field_core_date_opening_value']['id'] = 'field_core_date_opening_value';
  $handler->display->display_options['filters']['field_core_date_opening_value']['table'] = 'field_data_field_core_date_opening';
  $handler->display->display_options['filters']['field_core_date_opening_value']['field'] = 'field_core_date_opening_value';
  $handler->display->display_options['filters']['field_core_date_opening_value']['group'] = 1;
  $handler->display->display_options['filters']['field_core_date_opening_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_date_opening_value']['expose']['operator_id'] = 'field_core_date_opening_value_op';
  $handler->display->display_options['filters']['field_core_date_opening_value']['expose']['label'] = 'Consultation start date';
  $handler->display->display_options['filters']['field_core_date_opening_value']['expose']['operator'] = 'field_core_date_opening_value_op';
  $handler->display->display_options['filters']['field_core_date_opening_value']['expose']['identifier'] = 'field_core_date_opening_value';
  $handler->display->display_options['filters']['field_core_date_opening_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    14 => 0,
    7 => 0,
    12 => 0,
    9 => 0,
    18 => 0,
    10 => 0,
    15 => 0,
  );
  $handler->display->display_options['filters']['field_core_date_opening_value']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Closing date (field_core_date_closing) */
  $handler->display->display_options['filters']['field_core_date_closing_value']['id'] = 'field_core_date_closing_value';
  $handler->display->display_options['filters']['field_core_date_closing_value']['table'] = 'field_data_field_core_date_closing';
  $handler->display->display_options['filters']['field_core_date_closing_value']['field'] = 'field_core_date_closing_value';
  $handler->display->display_options['filters']['field_core_date_closing_value']['group'] = 1;
  $handler->display->display_options['filters']['field_core_date_closing_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_date_closing_value']['expose']['operator_id'] = 'field_core_date_closing_value_op';
  $handler->display->display_options['filters']['field_core_date_closing_value']['expose']['label'] = 'Consultation end date';
  $handler->display->display_options['filters']['field_core_date_closing_value']['expose']['operator'] = 'field_core_date_closing_value_op';
  $handler->display->display_options['filters']['field_core_date_closing_value']['expose']['identifier'] = 'field_core_date_closing_value';
  $handler->display->display_options['filters']['field_core_date_closing_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    14 => 0,
    7 => 0,
    12 => 0,
    9 => 0,
    18 => 0,
    10 => 0,
    15 => 0,
  );
  $handler->display->display_options['filters']['field_core_date_closing_value']['form_type'] = 'date_popup';
  /* Filter criterion: Policy areas (field_core_policy_areas) (selective) */
  $handler->display->display_options['filters']['field_core_policy_areas_target_id_selective']['id'] = 'field_core_policy_areas_target_id_selective';
  $handler->display->display_options['filters']['field_core_policy_areas_target_id_selective']['table'] = 'field_data_field_core_policy_areas';
  $handler->display->display_options['filters']['field_core_policy_areas_target_id_selective']['field'] = 'field_core_policy_areas_target_id_selective';
  $handler->display->display_options['filters']['field_core_policy_areas_target_id_selective']['ui_name'] = 'Policy areas (field_core_policy_areas) (selective)';
  $handler->display->display_options['filters']['field_core_policy_areas_target_id_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_core_policy_areas_target_id_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_policy_areas_target_id_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_core_policy_areas_target_id_selective']['expose']['label'] = 'Policy area';
  $handler->display->display_options['filters']['field_core_policy_areas_target_id_selective']['expose']['identifier'] = 'field_core_policy_areas_target_id_selective';
  $handler->display->display_options['filters']['field_core_policy_areas_target_id_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    14 => 0,
    7 => 0,
    12 => 0,
    9 => 0,
    18 => 0,
    10 => 0,
    15 => 0,
  );
  $handler->display->display_options['filters']['field_core_policy_areas_target_id_selective']['selective_display_field'] = 'field_core_policy_areas';
  $handler->display->display_options['filters']['field_core_policy_areas_target_id_selective']['selective_items_limit'] = '100';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'consultations';
  $export['consultations'] = $view;

  return $export;
}
