<?php
/**
 * @file
 * dt_commemorative_coins_default.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dt_commemorative_coins_default_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'commemorative_coins';
  $view->description = 'dt_information';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Commemorative coins';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Commemorative coins';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Clear';
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
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|created';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'teaser';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<h3>Showing results @start to @end</h43';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No coins found.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Collective issue */
  $handler->display->display_options['fields']['field_cc_issue_page']['id'] = 'field_cc_issue_page';
  $handler->display->display_options['fields']['field_cc_issue_page']['table'] = 'field_data_field_cc_issue_page';
  $handler->display->display_options['fields']['field_cc_issue_page']['field'] = 'field_cc_issue_page';
  $handler->display->display_options['fields']['field_cc_issue_page']['label'] = '';
  $handler->display->display_options['fields']['field_cc_issue_page']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cc_issue_page']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Subject of commemoration */
  $handler->display->display_options['fields']['field_cc_subject']['id'] = 'field_cc_subject';
  $handler->display->display_options['fields']['field_cc_subject']['table'] = 'field_data_field_cc_subject';
  $handler->display->display_options['fields']['field_cc_subject']['field'] = 'field_cc_subject';
  $handler->display->display_options['fields']['field_cc_subject']['exclude'] = TRUE;
  /* Field: Field: Description */
  $handler->display->display_options['fields']['field_core_description']['id'] = 'field_core_description';
  $handler->display->display_options['fields']['field_core_description']['table'] = 'field_data_field_core_description';
  $handler->display->display_options['fields']['field_core_description']['field'] = 'field_core_description';
  $handler->display->display_options['fields']['field_core_description']['exclude'] = TRUE;
  /* Field: Content: Date of issue */
  $handler->display->display_options['fields']['field_cc_date']['id'] = 'field_cc_date';
  $handler->display->display_options['fields']['field_cc_date']['table'] = 'field_data_field_cc_date';
  $handler->display->display_options['fields']['field_cc_date']['field'] = 'field_cc_date';
  $handler->display->display_options['fields']['field_cc_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cc_date']['settings'] = array(
    'format_type' => 'ec_date_j_f_y',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_nal_country']['id'] = 'field_nal_country';
  $handler->display->display_options['fields']['field_nal_country']['table'] = 'field_data_field_nal_country';
  $handler->display->display_options['fields']['field_nal_country']['field'] = 'field_nal_country';
  $handler->display->display_options['fields']['field_nal_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_nal_country']['type'] = 'taxonomy_term_reference_plain';
  /* Sort criterion: Content: Date of issue (field_cc_date) */
  $handler->display->display_options['sorts']['field_cc_date_value']['id'] = 'field_cc_date_value';
  $handler->display->display_options['sorts']['field_cc_date_value']['table'] = 'field_data_field_cc_date';
  $handler->display->display_options['sorts']['field_cc_date_value']['field'] = 'field_cc_date_value';
  $handler->display->display_options['sorts']['field_cc_date_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_cc_date_value']['expose']['label'] = 'Date of issue (field_cc_date)';
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
    'commemorative_coins' => 'commemorative_coins',
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
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Keyword';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_cc_subject' => 'field_cc_subject',
    'field_core_description' => 'field_core_description',
  );
  /* Filter criterion: Country (field_nal_country) (selective) */
  $handler->display->display_options['filters']['field_nal_country_tid_selective']['id'] = 'field_nal_country_tid_selective';
  $handler->display->display_options['filters']['field_nal_country_tid_selective']['table'] = 'field_data_field_nal_country';
  $handler->display->display_options['filters']['field_nal_country_tid_selective']['field'] = 'field_nal_country_tid_selective';
  $handler->display->display_options['filters']['field_nal_country_tid_selective']['ui_name'] = 'Country (field_nal_country) (selective)';
  $handler->display->display_options['filters']['field_nal_country_tid_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_nal_country_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_nal_country_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_nal_country_tid_selective']['expose']['label'] = 'Issuing country';
  $handler->display->display_options['filters']['field_nal_country_tid_selective']['expose']['identifier'] = 'field_nal_country_tid_selective';
  $handler->display->display_options['filters']['field_nal_country_tid_selective']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_nal_country_tid_selective']['selective_display_field'] = 'field_nal_country';
  $handler->display->display_options['filters']['field_nal_country_tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Content: Date of issue (field_cc_date) */
  $handler->display->display_options['filters']['field_cc_date_value']['id'] = 'field_cc_date_value';
  $handler->display->display_options['filters']['field_cc_date_value']['table'] = 'field_data_field_cc_date';
  $handler->display->display_options['filters']['field_cc_date_value']['field'] = 'field_cc_date_value';
  $handler->display->display_options['filters']['field_cc_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_cc_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cc_date_value']['expose']['operator_id'] = 'field_cc_date_value_op';
  $handler->display->display_options['filters']['field_cc_date_value']['expose']['label'] = 'Year of issue';
  $handler->display->display_options['filters']['field_cc_date_value']['expose']['operator'] = 'field_cc_date_value_op';
  $handler->display->display_options['filters']['field_cc_date_value']['expose']['identifier'] = 'field_cc_date_value';
  $handler->display->display_options['filters']['field_cc_date_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_cc_date_value']['granularity'] = 'year';
  $handler->display->display_options['filters']['field_cc_date_value']['year_range'] = '-14:+0';
  /* Filter criterion: Collective issue (field_cc_issue_page) (selective) */
  $handler->display->display_options['filters']['field_cc_issue_page_target_id_selective']['id'] = 'field_cc_issue_page_target_id_selective';
  $handler->display->display_options['filters']['field_cc_issue_page_target_id_selective']['table'] = 'field_data_field_cc_issue_page';
  $handler->display->display_options['filters']['field_cc_issue_page_target_id_selective']['field'] = 'field_cc_issue_page_target_id_selective';
  $handler->display->display_options['filters']['field_cc_issue_page_target_id_selective']['ui_name'] = 'Collective issue (field_cc_issue_page) (selective)';
  $handler->display->display_options['filters']['field_cc_issue_page_target_id_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_cc_issue_page_target_id_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cc_issue_page_target_id_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_cc_issue_page_target_id_selective']['expose']['label'] = 'Collective issue';
  $handler->display->display_options['filters']['field_cc_issue_page_target_id_selective']['expose']['identifier'] = 'field_cc_issue_page_target_id_selective';
  $handler->display->display_options['filters']['field_cc_issue_page_target_id_selective']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_cc_issue_page_target_id_selective']['selective_display_field'] = 'field_cc_issue_page';
  $handler->display->display_options['filters']['field_cc_issue_page_target_id_selective']['selective_items_limit'] = '100';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['dt_shared_functions_views_config_title'] = 'Coins';
  $handler->display->display_options['og_access_override'] = array(
    'non-member' => 0,
    'member' => 0,
    'administrator member' => 0,
    'author' => 0,
    'validator' => 0,
    'reviewer' => 0,
    'translator' => 0,
    'translator reviewer' => 0,
  );
  $handler->display->display_options['path'] = 'commemorative-coins';
  $export['commemorative_coins'] = $view;

  return $export;
}
