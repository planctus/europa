<?php
/**
 * @file
 * dt_person_press_contacts_list.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dt_person_press_contacts_list_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'press_contacts';
  $view->description = '';
  $view->tag = 'digital_transformation';
  $view->base_table = 'node';
  $view->human_name = 'Press contacts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Press contacts – Spokesperson\'s Service';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'nexteuropa_bem_listing';
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['style_options']['listing_columns'] = 'default';
  $handler->display->display_options['style_options']['listing_modifier'] = '';
  $handler->display->display_options['style_options']['listing_wrapper_modifier'] = '';
  $handler->display->display_options['style_options']['listing_item_modifier'] = '';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'job';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_core_jobs_target_id']['id'] = 'field_core_jobs_target_id';
  $handler->display->display_options['relationships']['field_core_jobs_target_id']['table'] = 'field_data_field_core_jobs';
  $handler->display->display_options['relationships']['field_core_jobs_target_id']['field'] = 'field_core_jobs_target_id';
  $handler->display->display_options['relationships']['field_core_jobs_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_job_role_target_id']['id'] = 'field_job_role_target_id';
  $handler->display->display_options['relationships']['field_job_role_target_id']['table'] = 'field_data_field_job_role';
  $handler->display->display_options['relationships']['field_job_role_target_id']['field'] = 'field_job_role_target_id';
  $handler->display->display_options['relationships']['field_job_role_target_id']['relationship'] = 'field_core_jobs_target_id';
  $handler->display->display_options['relationships']['field_job_role_target_id']['required'] = TRUE;
  /* Field: Content: Jobs */
  $handler->display->display_options['fields']['field_core_jobs']['id'] = 'field_core_jobs';
  $handler->display->display_options['fields']['field_core_jobs']['table'] = 'field_data_field_core_jobs';
  $handler->display->display_options['fields']['field_core_jobs']['field'] = 'field_core_jobs';
  $handler->display->display_options['fields']['field_core_jobs']['label'] = '';
  $handler->display->display_options['fields']['field_core_jobs']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_core_jobs']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_core_jobs']['delta_offset'] = '0';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_job_role_target_id';
  /* Sort criterion: Content: Last Name (field_person_last_name) */
  $handler->display->display_options['sorts']['field_person_last_name_value']['id'] = 'field_person_last_name_value';
  $handler->display->display_options['sorts']['field_person_last_name_value']['table'] = 'field_data_field_person_last_name';
  $handler->display->display_options['sorts']['field_person_last_name_value']['field'] = 'field_person_last_name_value';
  /* Sort criterion: Content: First Name (field_person_first_name) */
  $handler->display->display_options['sorts']['field_person_first_name_value']['id'] = 'field_person_first_name_value';
  $handler->display->display_options['sorts']['field_person_first_name_value']['table'] = 'field_data_field_person_first_name';
  $handler->display->display_options['sorts']['field_person_first_name_value']['field'] = 'field_person_first_name_value';
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
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Responsabilities attached to this job (field_job_responsabilities) */
  $handler->display->display_options['filters']['field_job_responsabilities_value']['id'] = 'field_job_responsabilities_value';
  $handler->display->display_options['filters']['field_job_responsabilities_value']['table'] = 'field_data_field_job_responsabilities';
  $handler->display->display_options['filters']['field_job_responsabilities_value']['field'] = 'field_job_responsabilities_value';
  $handler->display->display_options['filters']['field_job_responsabilities_value']['relationship'] = 'field_core_jobs_target_id';
  $handler->display->display_options['filters']['field_job_responsabilities_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_job_responsabilities_value']['group'] = 1;
  $handler->display->display_options['filters']['field_job_responsabilities_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_job_responsabilities_value']['expose']['operator_id'] = 'field_job_responsabilities_value_op';
  $handler->display->display_options['filters']['field_job_responsabilities_value']['expose']['label'] = 'Responsibilities or portfolio';
  $handler->display->display_options['filters']['field_job_responsabilities_value']['expose']['operator'] = 'field_job_responsabilities_value_op';
  $handler->display->display_options['filters']['field_job_responsabilities_value']['expose']['identifier'] = 'field_job_responsabilities_value';
  $handler->display->display_options['filters']['field_job_responsabilities_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Topics (field_core_topics) (reference filter) */
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['id'] = 'field_core_topics_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['table'] = 'field_data_field_core_topics';
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['field'] = 'field_core_topics_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['relationship'] = 'field_core_jobs_target_id';
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['expose']['operator_id'] = 'field_core_topics_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['expose']['label'] = 'Topics';
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['expose']['operator'] = 'field_core_topics_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['expose']['identifier'] = 'field_core_topics_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    10 => 0,
    8 => 0,
    7 => 0,
    11 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_core_topics_target_id_entityreference_filter']['reference_display'] = 'filter_list_topics:entityreference_1';
  /* Filter criterion: Content: Team/group (field_job_team_group) (translated) */
  $handler->display->display_options['filters']['field_job_team_group_value_i18n']['id'] = 'field_job_team_group_value_i18n';
  $handler->display->display_options['filters']['field_job_team_group_value_i18n']['table'] = 'field_data_field_job_team_group';
  $handler->display->display_options['filters']['field_job_team_group_value_i18n']['field'] = 'field_job_team_group_value_i18n';
  $handler->display->display_options['filters']['field_job_team_group_value_i18n']['relationship'] = 'field_core_jobs_target_id';
  $handler->display->display_options['filters']['field_job_team_group_value_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_job_team_group_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_job_team_group_value_i18n']['expose']['operator_id'] = 'field_job_team_group_value_i18n_op';
  $handler->display->display_options['filters']['field_job_team_group_value_i18n']['expose']['label'] = 'Team/role';
  $handler->display->display_options['filters']['field_job_team_group_value_i18n']['expose']['operator'] = 'field_job_team_group_value_i18n_op';
  $handler->display->display_options['filters']['field_job_team_group_value_i18n']['expose']['identifier'] = 'field_job_team_group_value_i18n';
  $handler->display->display_options['filters']['field_job_team_group_value_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    10 => 0,
    8 => 0,
    7 => 0,
    11 => 0,
    9 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['dt_shared_functions_views_config_hidecount'] = 1;
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
  $handler->display->display_options['path'] = 'contact/press-services/press-contacts/press-contacts-spokespersons-service';
  $export['press_contacts'] = $view;

  return $export;
}
