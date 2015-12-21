<?php
/**
 * @file
 * cwt_biography.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cwt_biography_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'biography_declaration';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Biography Declaration';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Declaration of interests';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>[nothing]</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* Relationship: Content: Title (field_biography_role) */
  $handler->display->display_options['relationships']['field_biography_role_tid']['id'] = 'field_biography_role_tid';
  $handler->display->display_options['relationships']['field_biography_role_tid']['table'] = 'field_data_field_biography_role';
  $handler->display->display_options['relationships']['field_biography_role_tid']['field'] = 'field_biography_role_tid';
  $handler->display->display_options['relationships']['field_biography_role_tid']['required'] = TRUE;
  /* Field: Taxonomy term: Declaration of interests */
  $handler->display->display_options['fields']['field_declaration_of_interest']['id'] = 'field_declaration_of_interest';
  $handler->display->display_options['fields']['field_declaration_of_interest']['table'] = 'field_data_field_declaration_of_interest';
  $handler->display->display_options['fields']['field_declaration_of_interest']['field'] = 'field_declaration_of_interest';
  $handler->display->display_options['fields']['field_declaration_of_interest']['relationship'] = 'field_biography_role_tid';
  $handler->display->display_options['fields']['field_declaration_of_interest']['label'] = '';
  $handler->display->display_options['fields']['field_declaration_of_interest']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_declaration_of_interest']['element_label_colon'] = FALSE;
  /* Field: Content: Declaration of interests */
  $handler->display->display_options['fields']['field_biography_declaration']['id'] = 'field_biography_declaration';
  $handler->display->display_options['fields']['field_biography_declaration']['table'] = 'field_data_field_biography_declaration';
  $handler->display->display_options['fields']['field_biography_declaration']['field'] = 'field_biography_declaration';
  $handler->display->display_options['fields']['field_biography_declaration']['label'] = '';
  $handler->display->display_options['fields']['field_biography_declaration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_declaration']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_biography_declaration']['settings'] = array(
    'text' => '[file:name]',
  );
  /* Field: View title */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'View title';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Declaration of interests';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
    'biography' => 'biography',
  );
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
    3 => 'OR',
  );
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
    'biography' => 'biography',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Taxonomy term: Declaration of interests (field_declaration_of_interest) */
  $handler->display->display_options['filters']['field_declaration_of_interest_value']['id'] = 'field_declaration_of_interest_value';
  $handler->display->display_options['filters']['field_declaration_of_interest_value']['table'] = 'field_data_field_declaration_of_interest';
  $handler->display->display_options['filters']['field_declaration_of_interest_value']['field'] = 'field_declaration_of_interest_value';
  $handler->display->display_options['filters']['field_declaration_of_interest_value']['relationship'] = 'field_biography_role_tid';
  $handler->display->display_options['filters']['field_declaration_of_interest_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_declaration_of_interest_value']['group'] = 2;
  /* Filter criterion: Content: Declaration of interests (field_biography_declaration:description) */
  $handler->display->display_options['filters']['field_biography_declaration_description']['id'] = 'field_biography_declaration_description';
  $handler->display->display_options['filters']['field_biography_declaration_description']['table'] = 'field_data_field_biography_declaration';
  $handler->display->display_options['filters']['field_biography_declaration_description']['field'] = 'field_biography_declaration_description';
  $handler->display->display_options['filters']['field_biography_declaration_description']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_biography_declaration_description']['group'] = 2;
  /* Filter criterion: Taxonomy term: Taxonomy term UUID */
  $handler->display->display_options['filters']['uuid_4']['id'] = 'uuid_4';
  $handler->display->display_options['filters']['uuid_4']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_4']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_4']['relationship'] = 'field_biography_role_tid';
  $handler->display->display_options['filters']['uuid_4']['value'] = 'e0028e61-1cfa-4f6e-a036-4665b12ce86a';
  $handler->display->display_options['filters']['uuid_4']['group'] = 3;
  /* Filter criterion: Taxonomy term: Taxonomy term UUID */
  $handler->display->display_options['filters']['uuid_3']['id'] = 'uuid_3';
  $handler->display->display_options['filters']['uuid_3']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_3']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_3']['relationship'] = 'field_biography_role_tid';
  $handler->display->display_options['filters']['uuid_3']['value'] = 'fea4c060-eb2d-4686-9ccc-64997aad4930';
  $handler->display->display_options['filters']['uuid_3']['group'] = 3;
  /* Filter criterion: Taxonomy term: Taxonomy term UUID */
  $handler->display->display_options['filters']['uuid_2']['id'] = 'uuid_2';
  $handler->display->display_options['filters']['uuid_2']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_2']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_2']['relationship'] = 'field_biography_role_tid';
  $handler->display->display_options['filters']['uuid_2']['value'] = 'f7f7834a-3d60-4525-804b-439fd2d9f97a';
  $handler->display->display_options['filters']['uuid_2']['group'] = 3;
  /* Filter criterion: Taxonomy term: Taxonomy term UUID */
  $handler->display->display_options['filters']['uuid_1']['id'] = 'uuid_1';
  $handler->display->display_options['filters']['uuid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_1']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_1']['relationship'] = 'field_biography_role_tid';
  $handler->display->display_options['filters']['uuid_1']['value'] = 'ffbcfcf3-2f50-4c70-a11c-936cc4385cde';
  $handler->display->display_options['filters']['uuid_1']['group'] = 3;
  /* Filter criterion: Taxonomy term: Taxonomy term UUID */
  $handler->display->display_options['filters']['uuid']['id'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['relationship'] = 'field_biography_role_tid';
  $handler->display->display_options['filters']['uuid']['value'] = 'cbfbd9f8-72ae-4635-aa77-888075de774b';
  $handler->display->display_options['filters']['uuid']['group'] = 3;
  $handler->display->display_options['filters']['uuid']['expose']['operator_id'] = 'uuid_op';
  $handler->display->display_options['filters']['uuid']['expose']['label'] = 'Taxonomy term UUID';
  $handler->display->display_options['filters']['uuid']['expose']['operator'] = 'uuid_op';
  $handler->display->display_options['filters']['uuid']['expose']['identifier'] = 'uuid';
  /* Filter criterion: Taxonomy term: Taxonomy term UUID */
  $handler->display->display_options['filters']['uuid_5']['id'] = 'uuid_5';
  $handler->display->display_options['filters']['uuid_5']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_5']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_5']['relationship'] = 'field_biography_role_tid';
  $handler->display->display_options['filters']['uuid_5']['value'] = 'd6304632-edda-4f20-871a-0e49513adfa5';
  $handler->display->display_options['filters']['uuid_5']['group'] = 3;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['biography_declaration'] = $view;

  $view = new view();
  $view->name = 'biography_header';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Biography header';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Biography header';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Title (field_biography_role) (translated) */
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['id'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['table'] = 'field_data_field_biography_role';
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['field'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_team_membership_target_id']['id'] = 'field_team_membership_target_id';
  $handler->display->display_options['relationships']['field_team_membership_target_id']['table'] = 'field_data_field_team_membership';
  $handler->display->display_options['relationships']['field_team_membership_target_id']['field'] = 'field_team_membership_target_id';
  /* Field: Content: Term */
  $handler->display->display_options['fields']['field_team_term']['id'] = 'field_team_term';
  $handler->display->display_options['fields']['field_team_term']['table'] = 'field_data_field_team_term';
  $handler->display->display_options['fields']['field_team_term']['field'] = 'field_team_term';
  $handler->display->display_options['fields']['field_team_term']['relationship'] = 'field_team_membership_target_id';
  $handler->display->display_options['fields']['field_team_term']['label'] = '';
  $handler->display->display_options['fields']['field_team_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_term']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_team_term']['alter']['text'] = '<span class="term">([field_team_term])</span>';
  $handler->display->display_options['fields']['field_team_term']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_biography_role']['id'] = 'field_biography_role';
  $handler->display->display_options['fields']['field_biography_role']['table'] = 'field_data_field_biography_role';
  $handler->display->display_options['fields']['field_biography_role']['field'] = 'field_biography_role';
  $handler->display->display_options['fields']['field_biography_role']['label'] = '';
  $handler->display->display_options['fields']['field_biography_role']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_role']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_role']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Taxonomy term: Feminine form */
  $handler->display->display_options['fields']['field_biography_role_feminine']['id'] = 'field_biography_role_feminine';
  $handler->display->display_options['fields']['field_biography_role_feminine']['table'] = 'field_data_field_biography_role_feminine';
  $handler->display->display_options['fields']['field_biography_role_feminine']['field'] = 'field_biography_role_feminine';
  $handler->display->display_options['fields']['field_biography_role_feminine']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['fields']['field_biography_role_feminine']['label'] = '';
  $handler->display->display_options['fields']['field_biography_role_feminine']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_role_feminine']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_role_feminine']['empty'] = '[field_biography_role]';
  /* Field: Content: Gender */
  $handler->display->display_options['fields']['field_gender']['id'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['table'] = 'field_data_field_gender';
  $handler->display->display_options['fields']['field_gender']['field'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['label'] = '';
  $handler->display->display_options['fields']['field_gender']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gender']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_gender']['alter']['text'] = '<span class="role">[field_biography_role_feminine]</span>';
  $handler->display->display_options['fields']['field_gender']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gender']['empty'] = '<span class="role">[field_biography_role]</span>';
  $handler->display->display_options['fields']['field_gender']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_gender']['type'] = 'list_key';
  /* Field: Content: First name */
  $handler->display->display_options['fields']['field_biography_first_name']['id'] = 'field_biography_first_name';
  $handler->display->display_options['fields']['field_biography_first_name']['table'] = 'field_data_field_biography_first_name';
  $handler->display->display_options['fields']['field_biography_first_name']['field'] = 'field_biography_first_name';
  $handler->display->display_options['fields']['field_biography_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_biography_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: Last name */
  $handler->display->display_options['fields']['field_biography_last_name']['id'] = 'field_biography_last_name';
  $handler->display->display_options['fields']['field_biography_last_name']['table'] = 'field_data_field_biography_last_name';
  $handler->display->display_options['fields']['field_biography_last_name']['field'] = 'field_biography_last_name';
  $handler->display->display_options['fields']['field_biography_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_biography_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_biography_last_name']['alter']['text'] = '<span class="first-name">[field_biography_first_name]</span> <span class="last-name">[field_biography_last_name]</span>';
  $handler->display->display_options['fields']['field_biography_last_name']['element_label_colon'] = FALSE;
  /* Field: Content: Tagline */
  $handler->display->display_options['fields']['field_biography_tagline']['id'] = 'field_biography_tagline';
  $handler->display->display_options['fields']['field_biography_tagline']['table'] = 'field_data_field_biography_tagline';
  $handler->display->display_options['fields']['field_biography_tagline']['field'] = 'field_biography_tagline';
  $handler->display->display_options['fields']['field_biography_tagline']['label'] = '';
  $handler->display->display_options['fields']['field_biography_tagline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_tagline']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_biography_tagline']['alter']['text'] = '<span class="header-line-3">[field_biography_tagline]</span>';
  $handler->display->display_options['fields']['field_biography_tagline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_tagline']['hide_empty'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="meta meta--header">
<div class="meta__item meta__item--type">[field_gender] [field_team_term]</div>
</div>
<h1>[field_biography_last_name]</h1>
<p>[field_biography_tagline]</p>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
    'biography' => 'biography',
  );
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
    'biography' => 'biography',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'header');
  $export['biography_header'] = $view;

  $view = new view();
  $view->name = 'biography_news';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Biography news';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Announcements';
  $handler->display->display_options['css_class'] = 'listing-custom';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['link_url'] = '[name]';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'listing-item';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '[nothing]';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = TRUE;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'editorial_sections' => 'editorial_sections',
    'departments' => 0,
    'biography_roles' => 0,
    'commissioner_statuses' => 0,
    'team_subtypes' => 0,
    'team_statuses' => 0,
    'team_terms' => 0,
    'project_teams' => 0,
    'biography_timeline_types' => 0,
    'classification' => 0,
    'portfolio_subjects' => 0,
    'tags' => 0,
    'social_networks' => 0,
    'aggregated_item_types' => 0,
  );
  /* Relationship: Taxonomy term: Content using Editorial section */
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['id'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['field'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['relationship'] = 'term_node_tid';
  /* Field: Content: Item type */
  $handler->display->display_options['fields']['field_aggregated_news_type']['id'] = 'field_aggregated_news_type';
  $handler->display->display_options['fields']['field_aggregated_news_type']['table'] = 'field_data_field_aggregated_news_type';
  $handler->display->display_options['fields']['field_aggregated_news_type']['field'] = 'field_aggregated_news_type';
  $handler->display->display_options['fields']['field_aggregated_news_type']['label'] = '';
  $handler->display->display_options['fields']['field_aggregated_news_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_aggregated_news_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_aggregated_news_type']['alter']['text'] = '[field_aggregated_news_type] <span class="separator">|</span>  ';
  $handler->display->display_options['fields']['field_aggregated_news_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_aggregated_news_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = '[field_aggregated_news_type][created]';
  $handler->display->display_options['fields']['created']['element_class'] = 'listing-item-metadata';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'ec_date';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_aggregated_news_link']['id'] = 'field_aggregated_news_link';
  $handler->display->display_options['fields']['field_aggregated_news_link']['table'] = 'field_data_field_aggregated_news_link';
  $handler->display->display_options['fields']['field_aggregated_news_link']['field'] = 'field_aggregated_news_link';
  $handler->display->display_options['fields']['field_aggregated_news_link']['label'] = '';
  $handler->display->display_options['fields']['field_aggregated_news_link']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_aggregated_news_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_aggregated_news_link']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_aggregated_news_link']['click_sort_column'] = 'url';
  /* Field: Block and page description */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Block and page description';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Latest news and speeches';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['nid_type'] = 'nids';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
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
    'aggregated_news' => 'aggregated_news',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'all announcements';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'nexteuropa_bem_listing';
  $handler->display->display_options['style_options']['listing_columns'] = 'default';
  $handler->display->display_options['style_options']['listing_modifier'] = '';
  $handler->display->display_options['style_options']['listing_wrapper_modifier'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'meta';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|created';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'meta';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: More link */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['ui_name'] = 'More link';
  $handler->display->display_options['footer']['area']['content'] = 'all announcements';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'list');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Announcements';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'listing-custom listing-custom--page';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Refine results';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'nexteuropa_bem_listing';
  $handler->display->display_options['style_options']['listing_columns'] = 'default';
  $handler->display->display_options['style_options']['listing_modifier'] = '';
  $handler->display->display_options['style_options']['listing_wrapper_modifier'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'meta';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|created';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'meta';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'aggregated_news' => 'aggregated_news',
  );
  /* Filter criterion: Content: Item type (field_aggregated_news_type) */
  $handler->display->display_options['filters']['field_aggregated_news_type_tid']['id'] = 'field_aggregated_news_type_tid';
  $handler->display->display_options['filters']['field_aggregated_news_type_tid']['table'] = 'field_data_field_aggregated_news_type';
  $handler->display->display_options['filters']['field_aggregated_news_type_tid']['field'] = 'field_aggregated_news_type_tid';
  $handler->display->display_options['filters']['field_aggregated_news_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_aggregated_news_type_tid']['expose']['operator_id'] = 'field_aggregated_news_type_tid_op';
  $handler->display->display_options['filters']['field_aggregated_news_type_tid']['expose']['label'] = 'Announcement type';
  $handler->display->display_options['filters']['field_aggregated_news_type_tid']['expose']['operator'] = 'field_aggregated_news_type_tid_op';
  $handler->display->display_options['filters']['field_aggregated_news_type_tid']['expose']['identifier'] = 'field_aggregated_news_type_tid';
  $handler->display->display_options['filters']['field_aggregated_news_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    33 => 0,
    7 => 0,
    6 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    34 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
    23 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    28 => 0,
    29 => 0,
    30 => 0,
    31 => 0,
    32 => 0,
  );
  $handler->display->display_options['filters']['field_aggregated_news_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_aggregated_news_type_tid']['vocabulary'] = 'aggregated_item_types';
  $handler->display->display_options['path'] = 'announcements';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '[title_1] - Announcements - European Commission';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Item type */
  $handler->display->display_options['fields']['field_aggregated_news_type']['id'] = 'field_aggregated_news_type';
  $handler->display->display_options['fields']['field_aggregated_news_type']['table'] = 'field_data_field_aggregated_news_type';
  $handler->display->display_options['fields']['field_aggregated_news_type']['field'] = 'field_aggregated_news_type';
  $handler->display->display_options['fields']['field_aggregated_news_type']['label'] = '';
  $handler->display->display_options['fields']['field_aggregated_news_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_aggregated_news_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_aggregated_news_type']['alter']['text'] = '[field_aggregated_news_type] <span class="separator">|</span>  ';
  $handler->display->display_options['fields']['field_aggregated_news_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_aggregated_news_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = '[field_aggregated_news_type][created]';
  $handler->display->display_options['fields']['created']['element_class'] = 'listing-item-metadata';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'ec_date';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_aggregated_news_link']['id'] = 'field_aggregated_news_link';
  $handler->display->display_options['fields']['field_aggregated_news_link']['table'] = 'field_data_field_aggregated_news_link';
  $handler->display->display_options['fields']['field_aggregated_news_link']['field'] = 'field_aggregated_news_link';
  $handler->display->display_options['fields']['field_aggregated_news_link']['label'] = '';
  $handler->display->display_options['fields']['field_aggregated_news_link']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_aggregated_news_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_aggregated_news_link']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_aggregated_news_link']['click_sort_column'] = 'url';
  /* Field: Block and page description */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Block and page description';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Latest news and speeches';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_biography_role']['id'] = 'field_biography_role';
  $handler->display->display_options['fields']['field_biography_role']['table'] = 'field_data_field_biography_role';
  $handler->display->display_options['fields']['field_biography_role']['field'] = 'field_biography_role';
  $handler->display->display_options['fields']['field_biography_role']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['fields']['field_biography_role']['label'] = '';
  $handler->display->display_options['fields']['field_biography_role']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Portrait */
  $handler->display->display_options['fields']['field_biography_portrait']['id'] = 'field_biography_portrait';
  $handler->display->display_options['fields']['field_biography_portrait']['table'] = 'field_data_field_biography_portrait';
  $handler->display->display_options['fields']['field_biography_portrait']['field'] = 'field_biography_portrait';
  $handler->display->display_options['fields']['field_biography_portrait']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['fields']['field_biography_portrait']['label'] = '';
  $handler->display->display_options['fields']['field_biography_portrait']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_portrait']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_portrait']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_biography_portrait']['settings'] = array(
    'image_style' => 'team_members_130x130',
    'image_link' => '',
  );
  /* Field: Content: Tagline */
  $handler->display->display_options['fields']['field_biography_tagline']['id'] = 'field_biography_tagline';
  $handler->display->display_options['fields']['field_biography_tagline']['table'] = 'field_data_field_biography_tagline';
  $handler->display->display_options['fields']['field_biography_tagline']['field'] = 'field_biography_tagline';
  $handler->display->display_options['fields']['field_biography_tagline']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['fields']['field_biography_tagline']['label'] = '';
  $handler->display->display_options['fields']['field_biography_tagline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_tagline']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'announcements/%/feed';
  $handler->display->display_options['sitename_title'] = 0;
  $export['biography_news'] = $view;

  $view = new view();
  $view->name = 'biography_portrait';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Biography portrait';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Portrait (field_biography_portrait:fid) */
  $handler->display->display_options['relationships']['field_biography_portrait_fid']['id'] = 'field_biography_portrait_fid';
  $handler->display->display_options['relationships']['field_biography_portrait_fid']['table'] = 'field_data_field_biography_portrait';
  $handler->display->display_options['relationships']['field_biography_portrait_fid']['field'] = 'field_biography_portrait_fid';
  /* Field: Portrait (Small) */
  $handler->display->display_options['fields']['field_biography_portrait']['id'] = 'field_biography_portrait';
  $handler->display->display_options['fields']['field_biography_portrait']['table'] = 'field_data_field_biography_portrait';
  $handler->display->display_options['fields']['field_biography_portrait']['field'] = 'field_biography_portrait';
  $handler->display->display_options['fields']['field_biography_portrait']['ui_name'] = 'Portrait (Small)';
  $handler->display->display_options['fields']['field_biography_portrait']['label'] = '';
  $handler->display->display_options['fields']['field_biography_portrait']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_biography_portrait']['alter']['text'] = '<a href="#" data-toggle="modal" data-target="#hi-res-picture">[field_biography_portrait]</a>';
  $handler->display->display_options['fields']['field_biography_portrait']['alter']['link_class'] = 'fancybox';
  $handler->display->display_options['fields']['field_biography_portrait']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_portrait']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_biography_portrait']['settings'] = array(
    'image_style' => 'biography_portrait_160x160',
    'image_link' => '',
  );
  /* Field: Hi-res download link */
  $handler->display->display_options['fields']['field_biography_portrait_1']['id'] = 'field_biography_portrait_1';
  $handler->display->display_options['fields']['field_biography_portrait_1']['table'] = 'field_data_field_biography_portrait';
  $handler->display->display_options['fields']['field_biography_portrait_1']['field'] = 'field_biography_portrait';
  $handler->display->display_options['fields']['field_biography_portrait_1']['ui_name'] = 'Hi-res download link';
  $handler->display->display_options['fields']['field_biography_portrait_1']['label'] = '';
  $handler->display->display_options['fields']['field_biography_portrait_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_portrait_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_biography_portrait_1']['type'] = 'file_download_link';
  $handler->display->display_options['fields']['field_biography_portrait_1']['settings'] = array(
    'text' => 'Download high resolution',
  );
  /* Field: Content: Portrait */
  $handler->display->display_options['fields']['field_biography_portrait_2']['id'] = 'field_biography_portrait_2';
  $handler->display->display_options['fields']['field_biography_portrait_2']['table'] = 'field_data_field_biography_portrait';
  $handler->display->display_options['fields']['field_biography_portrait_2']['field'] = 'field_biography_portrait';
  $handler->display->display_options['fields']['field_biography_portrait_2']['label'] = '';
  $handler->display->display_options['fields']['field_biography_portrait_2']['alter']['text'] = '<div class="modal fade" id="hi-res-picture" tabindex="-1" role="dialog" aria-hidden="true">
      <div class="modal-dialog">
        <div class="modal-content">
          <div class="modal-header">
            <a href="#" type="button" class="close" data-dismiss="modal"><span class="close-text">Close</span><span aria-hidden="true">&times;</span></a>
          </div>
          <div class="modal-body">
          [field_biography_portrait_2]
          [field_biography_portrait_1]
          </div>
        </div>
      </div>
    </div>';
  $handler->display->display_options['fields']['field_biography_portrait_2']['element_type'] = '0';
  $handler->display->display_options['fields']['field_biography_portrait_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_portrait_2']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_biography_portrait_2']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_biography_portrait_2']['type'] = 'picture';
  $handler->display->display_options['fields']['field_biography_portrait_2']['settings'] = array(
    'picture_mapping' => 'biography_portrait_large',
    'fallback_image_style' => 'biography_portrait_large_500px',
    'image_link' => '',
    'colorbox' => 'team_members_picture',
  );
  /* Field: Content: AV portal link */
  $handler->display->display_options['fields']['field_biography_av_portal']['id'] = 'field_biography_av_portal';
  $handler->display->display_options['fields']['field_biography_av_portal']['table'] = 'field_data_field_biography_av_portal';
  $handler->display->display_options['fields']['field_biography_av_portal']['field'] = 'field_biography_av_portal';
  $handler->display->display_options['fields']['field_biography_av_portal']['label'] = '';
  $handler->display->display_options['fields']['field_biography_av_portal']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_biography_av_portal']['alter']['path'] = '[field_biography_av_portal-url]';
  $handler->display->display_options['fields']['field_biography_av_portal']['alter']['alt'] = 'Audiovisual Portal Link';
  $handler->display->display_options['fields']['field_biography_av_portal']['alter']['link_class'] = 'av-portal-link';
  $handler->display->display_options['fields']['field_biography_av_portal']['element_type'] = '0';
  $handler->display->display_options['fields']['field_biography_av_portal']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_av_portal']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_biography_av_portal']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_biography_av_portal']['type'] = 'link_title_plain';
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
    'biography' => 'biography',
  );
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
    'biography' => 'biography',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['biography_portrait'] = $view;

  $view = new view();
  $view->name = 'biography_related_terms';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Biography Related Terms';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Topics */
  $handler->display->display_options['fields']['field_biography_portfolio']['id'] = 'field_biography_portfolio';
  $handler->display->display_options['fields']['field_biography_portfolio']['table'] = 'field_data_field_biography_portfolio';
  $handler->display->display_options['fields']['field_biography_portfolio']['field'] = 'field_biography_portfolio';
  $handler->display->display_options['fields']['field_biography_portfolio']['label'] = '';
  $handler->display->display_options['fields']['field_biography_portfolio']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_portfolio']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_biography_portfolio']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_biography_portfolio']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_biography_portfolio']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_biography_portfolio']['multi_type'] = 'ul';
  /* Field: Content: Departments */
  $handler->display->display_options['fields']['field_biography_departments']['id'] = 'field_biography_departments';
  $handler->display->display_options['fields']['field_biography_departments']['table'] = 'field_data_field_biography_departments';
  $handler->display->display_options['fields']['field_biography_departments']['field'] = 'field_biography_departments';
  $handler->display->display_options['fields']['field_biography_departments']['label'] = '';
  $handler->display->display_options['fields']['field_biography_departments']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_departments']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_biography_departments']['type'] = 'custom_formatters_taxonomy_term_reference_external_links';
  $handler->display->display_options['fields']['field_biography_departments']['settings'] = array(
    'relationship' => 'none',
    'ui_name' => '',
    'custom_label' => 0,
    'label' => '',
    'element_label_colon' => 0,
    'exclude' => 0,
    'element_type_enable' => 0,
    'element_type' => '',
    'element_class_enable' => 0,
    'element_class' => '',
    'element_label_type_enable' => 0,
    'element_label_type' => '',
    'element_label_class_enable' => 0,
    'element_label_class' => '',
    'element_wrapper_type_enable' => 0,
    'element_wrapper_type' => '',
    'element_wrapper_class_enable' => 0,
    'element_wrapper_class' => '',
    'element_default_classes' => 0,
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'absolute' => 0,
      'replace_spaces' => 0,
      'external' => 0,
      'path_case' => 'none',
      'link_class' => '',
      'alt' => '',
      'rel' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 0,
      'ellipsis' => 0,
      'more_link' => 0,
      'more_link_text' => '',
      'more_link_path' => '',
      'html' => 0,
      'strip_tags' => 0,
      'preserve_tags' => '',
      'trim_whitespace' => 0,
      'nl2br' => 0,
    ),
    'empty' => '',
    'empty_zero' => 0,
    'hide_empty' => 0,
    'hide_alter_empty' => 0,
    'group_rows' => 0,
    'multi_type' => NULL,
    'separator' => '',
    'delta_limit' => '',
    'delta_offset' => '',
    'delta_reversed' => 0,
    'delta_first_last' => 0,
    'click_sort_column' => 'tid',
    'type' => '',
    'field_api_classes' => 0,
  );
  $handler->display->display_options['fields']['field_biography_departments']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_biography_departments']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_biography_departments']['multi_type'] = 'ul';
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
    'biography' => 'biography',
  );
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
    'biography' => 'biography',
  );

  /* Display: Departments */
  $handler = $view->new_display('block', 'Departments', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Departments */
  $handler->display->display_options['fields']['field_biography_departments']['id'] = 'field_biography_departments';
  $handler->display->display_options['fields']['field_biography_departments']['table'] = 'field_data_field_biography_departments';
  $handler->display->display_options['fields']['field_biography_departments']['field'] = 'field_biography_departments';
  $handler->display->display_options['fields']['field_biography_departments']['label'] = '';
  $handler->display->display_options['fields']['field_biography_departments']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_departments']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_biography_departments']['type'] = 'custom_formatters_taxonomy_term_reference_external_links';
  $handler->display->display_options['fields']['field_biography_departments']['settings'] = array(
    'relationship' => 'none',
    'ui_name' => '',
    'custom_label' => 0,
    'label' => '',
    'element_label_colon' => 0,
    'exclude' => 0,
    'element_type_enable' => 0,
    'element_type' => '',
    'element_class_enable' => 0,
    'element_class' => '',
    'element_label_type_enable' => 0,
    'element_label_type' => '',
    'element_label_class_enable' => 0,
    'element_label_class' => '',
    'element_wrapper_type_enable' => 0,
    'element_wrapper_type' => '',
    'element_wrapper_class_enable' => 0,
    'element_wrapper_class' => '',
    'element_default_classes' => 0,
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'absolute' => 0,
      'replace_spaces' => 0,
      'external' => 0,
      'path_case' => 'none',
      'link_class' => '',
      'alt' => '',
      'rel' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 0,
      'ellipsis' => 0,
      'more_link' => 0,
      'more_link_text' => '',
      'more_link_path' => '',
      'html' => 0,
      'strip_tags' => 0,
      'preserve_tags' => '',
      'trim_whitespace' => 0,
      'nl2br' => 0,
    ),
    'empty' => '',
    'empty_zero' => 0,
    'hide_empty' => 0,
    'hide_alter_empty' => 0,
    'group_rows' => 0,
    'multi_type' => NULL,
    'separator' => '',
    'delta_limit' => '',
    'delta_offset' => '',
    'delta_reversed' => 0,
    'delta_first_last' => 0,
    'click_sort_column' => 'tid',
    'type' => '',
    'field_api_classes' => 0,
  );
  $handler->display->display_options['fields']['field_biography_departments']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_biography_departments']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_biography_departments']['multi_type'] = 'ul';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'biography' => 'biography',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Departments (field_biography_departments:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_biography_departments';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['operator'] = 'not empty';

  /* Display: Topics */
  $handler = $view->new_display('block', 'Topics', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Topics */
  $handler->display->display_options['fields']['field_biography_portfolio']['id'] = 'field_biography_portfolio';
  $handler->display->display_options['fields']['field_biography_portfolio']['table'] = 'field_data_field_biography_portfolio';
  $handler->display->display_options['fields']['field_biography_portfolio']['field'] = 'field_biography_portfolio';
  $handler->display->display_options['fields']['field_biography_portfolio']['label'] = '';
  $handler->display->display_options['fields']['field_biography_portfolio']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_portfolio']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_biography_portfolio']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_biography_portfolio']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_biography_portfolio']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_biography_portfolio']['multi_type'] = 'ul';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'biography' => 'biography',
  );
  /* Filter criterion: Content: Topics (field_biography_portfolio:title) */
  $handler->display->display_options['filters']['field_biography_portfolio_title']['id'] = 'field_biography_portfolio_title';
  $handler->display->display_options['filters']['field_biography_portfolio_title']['table'] = 'field_data_field_biography_portfolio';
  $handler->display->display_options['filters']['field_biography_portfolio_title']['field'] = 'field_biography_portfolio_title';
  $handler->display->display_options['filters']['field_biography_portfolio_title']['operator'] = 'not empty';
  $export['biography_related_terms'] = $view;

  $view = new view();
  $view->name = 'biography_social_networks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Biography Social Networks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '[field_social_block_title]';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Editorial section (field_editorial_section) (translated) */
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['id'] = 'field_editorial_section_tid_i18n';
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['table'] = 'field_data_field_editorial_section';
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['field'] = 'field_editorial_section_tid_i18n';
  /* Field: Content: Social Networks */
  $handler->display->display_options['fields']['field_social_networks']['id'] = 'field_social_networks';
  $handler->display->display_options['fields']['field_social_networks']['table'] = 'field_data_field_social_networks';
  $handler->display->display_options['fields']['field_social_networks']['field'] = 'field_social_networks';
  $handler->display->display_options['fields']['field_social_networks']['label'] = '';
  $handler->display->display_options['fields']['field_social_networks']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_social_networks']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_social_networks']['type'] = 'social_network_link_css';
  $handler->display->display_options['fields']['field_social_networks']['settings'] = array(
    'icon_image_style' => '',
  );
  $handler->display->display_options['fields']['field_social_networks']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_social_networks']['multi_type'] = 'ul';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_social_block_title']['id'] = 'field_social_block_title';
  $handler->display->display_options['fields']['field_social_block_title']['table'] = 'field_data_field_social_block_title';
  $handler->display->display_options['fields']['field_social_block_title']['field'] = 'field_social_block_title';
  $handler->display->display_options['fields']['field_social_block_title']['relationship'] = 'field_editorial_section_tid_i18n';
  $handler->display->display_options['fields']['field_social_block_title']['label'] = '';
  $handler->display->display_options['fields']['field_social_block_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_social_block_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_social_block_title']['empty'] = 'Social Networks';
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
    'biography' => 'biography',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Social Networks (field_social_networks:url) */
  $handler->display->display_options['filters']['field_social_networks_url']['id'] = 'field_social_networks_url';
  $handler->display->display_options['filters']['field_social_networks_url']['table'] = 'field_data_field_social_networks';
  $handler->display->display_options['filters']['field_social_networks_url']['field'] = 'field_social_networks_url';
  $handler->display->display_options['filters']['field_social_networks_url']['operator'] = 'not empty';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['biography_social_networks'] = $view;

  $view = new view();
  $view->name = 'biography_team';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Biography Team';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Team';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Relationship: Content: Title (field_biography_role) (translated) */
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['id'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['table'] = 'field_data_field_biography_role';
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['field'] = 'field_biography_role_tid_i18n';
  /* Relationship: Content: Editorial section (field_editorial_section) (translated) */
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['id'] = 'field_editorial_section_tid_i18n';
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['table'] = 'field_data_field_editorial_section';
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['field'] = 'field_editorial_section_tid_i18n';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_biography_team_target_id']['id'] = 'field_biography_team_target_id';
  $handler->display->display_options['relationships']['field_biography_team_target_id']['table'] = 'field_data_field_biography_team';
  $handler->display->display_options['relationships']['field_biography_team_target_id']['field'] = 'field_biography_team_target_id';
  /* Field: Taxonomy term: Team block description */
  $handler->display->display_options['fields']['field_team_block_description']['id'] = 'field_team_block_description';
  $handler->display->display_options['fields']['field_team_block_description']['table'] = 'field_data_field_team_block_description';
  $handler->display->display_options['fields']['field_team_block_description']['field'] = 'field_team_block_description';
  $handler->display->display_options['fields']['field_team_block_description']['relationship'] = 'field_editorial_section_tid_i18n';
  $handler->display->display_options['fields']['field_team_block_description']['label'] = '';
  $handler->display->display_options['fields']['field_team_block_description']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_team_block_description']['element_label_colon'] = FALSE;
  /* Field: Content: Source language path */
  $handler->display->display_options['fields']['cwt_team_source_language_path']['id'] = 'cwt_team_source_language_path';
  $handler->display->display_options['fields']['cwt_team_source_language_path']['table'] = 'node';
  $handler->display->display_options['fields']['cwt_team_source_language_path']['field'] = 'cwt_team_source_language_path';
  $handler->display->display_options['fields']['cwt_team_source_language_path']['relationship'] = 'field_biography_team_target_id';
  $handler->display->display_options['fields']['cwt_team_source_language_path']['label'] = '';
  $handler->display->display_options['fields']['cwt_team_source_language_path']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['cwt_team_source_language_path']['alter']['text'] = 'team page';
  $handler->display->display_options['fields']['cwt_team_source_language_path']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['cwt_team_source_language_path']['alter']['path'] = '[cwt_team_source_language_path]';
  $handler->display->display_options['fields']['cwt_team_source_language_path']['alter']['alt'] = 'team of %1';
  $handler->display->display_options['fields']['cwt_team_source_language_path']['alter']['link_class'] = 'link';
  $handler->display->display_options['fields']['cwt_team_source_language_path']['alter']['prefix'] = '<div class="more-link">';
  $handler->display->display_options['fields']['cwt_team_source_language_path']['alter']['suffix'] = '</div>';
  $handler->display->display_options['fields']['cwt_team_source_language_path']['element_type'] = '0';
  $handler->display->display_options['fields']['cwt_team_source_language_path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['cwt_team_source_language_path']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['cwt_team_source_language_path']['absolute'] = TRUE;
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
    'biography' => 'biography',
  );
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
    'biography' => 'biography',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Team (field_biography_team) */
  $handler->display->display_options['filters']['field_biography_team_target_id']['id'] = 'field_biography_team_target_id';
  $handler->display->display_options['filters']['field_biography_team_target_id']['table'] = 'field_data_field_biography_team';
  $handler->display->display_options['filters']['field_biography_team_target_id']['field'] = 'field_biography_team_target_id';
  $handler->display->display_options['filters']['field_biography_team_target_id']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_biography_team_target_id']['group'] = 1;
  /* Filter criterion: Taxonomy term: Taxonomy term UUID */
  $handler->display->display_options['filters']['uuid_3']['id'] = 'uuid_3';
  $handler->display->display_options['filters']['uuid_3']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_3']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_3']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid_3']['value'] = 'fea4c060-eb2d-4686-9ccc-64997aad4930';
  $handler->display->display_options['filters']['uuid_3']['group'] = 2;
  /* Filter criterion: Taxonomy term: Taxonomy term UUID */
  $handler->display->display_options['filters']['uuid_4']['id'] = 'uuid_4';
  $handler->display->display_options['filters']['uuid_4']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_4']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_4']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid_4']['value'] = 'd6304632-edda-4f20-871a-0e49513adfa5';
  $handler->display->display_options['filters']['uuid_4']['group'] = 2;
  /* Filter criterion: Taxonomy term: Taxonomy term UUID */
  $handler->display->display_options['filters']['uuid_5']['id'] = 'uuid_5';
  $handler->display->display_options['filters']['uuid_5']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_5']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_5']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid_5']['value'] = 'e0028e61-1cfa-4f6e-a036-4665b12ce86a';
  $handler->display->display_options['filters']['uuid_5']['group'] = 2;
  /* Filter criterion: Taxonomy term: Taxonomy term UUID */
  $handler->display->display_options['filters']['uuid_2']['id'] = 'uuid_2';
  $handler->display->display_options['filters']['uuid_2']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_2']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_2']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid_2']['value'] = 'f7f7834a-3d60-4525-804b-439fd2d9f97a';
  $handler->display->display_options['filters']['uuid_2']['group'] = 2;
  /* Filter criterion: Taxonomy term: Taxonomy term UUID */
  $handler->display->display_options['filters']['uuid_1']['id'] = 'uuid_1';
  $handler->display->display_options['filters']['uuid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_1']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_1']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid_1']['value'] = 'ffbcfcf3-2f50-4c70-a11c-936cc4385cde';
  $handler->display->display_options['filters']['uuid_1']['group'] = 2;
  /* Filter criterion: Taxonomy term: Taxonomy term UUID */
  $handler->display->display_options['filters']['uuid']['id'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid']['value'] = 'cbfbd9f8-72ae-4635-aa77-888075de774b';
  $handler->display->display_options['filters']['uuid']['group'] = 2;
  $handler->display->display_options['filters']['uuid']['expose']['operator_id'] = 'uuid_op';
  $handler->display->display_options['filters']['uuid']['expose']['label'] = 'Taxonomy term UUID';
  $handler->display->display_options['filters']['uuid']['expose']['operator'] = 'uuid_op';
  $handler->display->display_options['filters']['uuid']['expose']['identifier'] = 'uuid';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'field_biography_team_target_id';
  $handler->display->display_options['filters']['status_1']['value'] = '1';

  /* Display: Biography team */
  $handler = $view->new_display('block', 'Biography team', 'block_1');
  $export['biography_team'] = $view;

  $view = new view();
  $view->name = 'biography_timeline';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Biography Timeline';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Biography';
  $handler->display->display_options['css_class'] = 'listing--no-border';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'Show timeline';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'nexteuropa_bem_listing';
  $handler->display->display_options['style_options']['listing_columns'] = 'default';
  $handler->display->display_options['style_options']['listing_modifier'] = 'timeline';
  $handler->display->display_options['style_options']['listing_wrapper_modifier'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '[field_biography_cv]';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = TRUE;
  $handler->display->display_options['footer']['area']['content'] = '[field_download_cv_in_pdf_format]';
  $handler->display->display_options['footer']['area']['format'] = 'custom_text_filter';
  $handler->display->display_options['footer']['area']['tokenize'] = TRUE;
  /* Footer: Global: View area */
  $handler->display->display_options['footer']['view']['id'] = 'view';
  $handler->display->display_options['footer']['view']['table'] = 'views';
  $handler->display->display_options['footer']['view']['field'] = 'view';
  $handler->display->display_options['footer']['view']['empty'] = TRUE;
  $handler->display->display_options['footer']['view']['view_to_insert'] = 'biography_declaration:block';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_biography_timeline_target_id']['id'] = 'field_biography_timeline_target_id';
  $handler->display->display_options['relationships']['field_biography_timeline_target_id']['table'] = 'field_data_field_biography_timeline';
  $handler->display->display_options['relationships']['field_biography_timeline_target_id']['field'] = 'field_biography_timeline_target_id';
  $handler->display->display_options['relationships']['field_biography_timeline_target_id']['required'] = TRUE;
  /* Relationship: Content: Type (field_timeline_type) */
  $handler->display->display_options['relationships']['field_timeline_type_tid']['id'] = 'field_timeline_type_tid';
  $handler->display->display_options['relationships']['field_timeline_type_tid']['table'] = 'field_data_field_timeline_type';
  $handler->display->display_options['relationships']['field_timeline_type_tid']['field'] = 'field_timeline_type_tid';
  $handler->display->display_options['relationships']['field_timeline_type_tid']['relationship'] = 'field_biography_timeline_target_id';
  /* Field: Taxonomy term: Classname */
  $handler->display->display_options['fields']['field_icon_classname']['id'] = 'field_icon_classname';
  $handler->display->display_options['fields']['field_icon_classname']['table'] = 'field_data_field_icon_classname';
  $handler->display->display_options['fields']['field_icon_classname']['field'] = 'field_icon_classname';
  $handler->display->display_options['fields']['field_icon_classname']['relationship'] = 'field_timeline_type_tid';
  $handler->display->display_options['fields']['field_icon_classname']['label'] = '';
  $handler->display->display_options['fields']['field_icon_classname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_icon_classname']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_icon_classname']['alter']['text'] = '[field_icon_classname] ';
  $handler->display->display_options['fields']['field_icon_classname']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'field_timeline_type_tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['tid']['alter']['text'] = '[field_icon_classname]term-[tid]';
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_biography_timeline_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'span';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_timeline_date']['id'] = 'field_timeline_date';
  $handler->display->display_options['fields']['field_timeline_date']['table'] = 'field_data_field_timeline_date';
  $handler->display->display_options['fields']['field_timeline_date']['field'] = 'field_timeline_date';
  $handler->display->display_options['fields']['field_timeline_date']['relationship'] = 'field_biography_timeline_target_id';
  $handler->display->display_options['fields']['field_timeline_date']['label'] = '';
  $handler->display->display_options['fields']['field_timeline_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_timeline_date']['element_label_colon'] = FALSE;
  /* Field: Content: Curriculum Vitae */
  $handler->display->display_options['fields']['field_biography_cv']['id'] = 'field_biography_cv';
  $handler->display->display_options['fields']['field_biography_cv']['table'] = 'field_data_field_biography_cv';
  $handler->display->display_options['fields']['field_biography_cv']['field'] = 'field_biography_cv';
  $handler->display->display_options['fields']['field_biography_cv']['label'] = '';
  $handler->display->display_options['fields']['field_biography_cv']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_cv']['element_label_colon'] = FALSE;
  /* Field: Content: Download CV in PDF format */
  $handler->display->display_options['fields']['field_download_cv_in_pdf_format']['id'] = 'field_download_cv_in_pdf_format';
  $handler->display->display_options['fields']['field_download_cv_in_pdf_format']['table'] = 'field_data_field_download_cv_in_pdf_format';
  $handler->display->display_options['fields']['field_download_cv_in_pdf_format']['field'] = 'field_download_cv_in_pdf_format';
  $handler->display->display_options['fields']['field_download_cv_in_pdf_format']['label'] = '';
  $handler->display->display_options['fields']['field_download_cv_in_pdf_format']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_download_cv_in_pdf_format']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_download_cv_in_pdf_format']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_download_cv_in_pdf_format']['settings'] = array(
    'text' => '[file:name]',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="timeline__item">
    <div class="timeline__item-title">[title]</div>
    <div class="timeline__text">
      <ul>
        <li>[field_timeline_date]</li>
      </ul>
    </div>
</div>
';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
    'biography' => 'biography',
  );
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
    'biography' => 'biography',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Biography Timeline */
  $handler = $view->new_display('block', 'Biography Timeline', 'block');
  $export['biography_timeline'] = $view;

  $view = new view();
  $view->name = 'contact';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Contact';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['separator'] = ' ';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = 'Contact [title_1]';
  $handler->display->display_options['fields']['title_1']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_biography_address']['id'] = 'field_biography_address';
  $handler->display->display_options['fields']['field_biography_address']['table'] = 'field_data_field_biography_address';
  $handler->display->display_options['fields']['field_biography_address']['field'] = 'field_biography_address';
  $handler->display->display_options['fields']['field_biography_address']['label'] = '';
  $handler->display->display_options['fields']['field_biography_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_biography_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Phone number */
  $handler->display->display_options['fields']['field_biography_phone']['id'] = 'field_biography_phone';
  $handler->display->display_options['fields']['field_biography_phone']['table'] = 'field_data_field_biography_phone';
  $handler->display->display_options['fields']['field_biography_phone']['field'] = 'field_biography_phone';
  $handler->display->display_options['fields']['field_biography_phone']['label'] = 'Phone';
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
    'biography' => 'biography',
  );
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
    'biography' => 'biography',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Contact block (biography) */
  $handler = $view->new_display('block', 'Contact block (biography)', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'listing__item listing__item--contact';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['separator'] = ' ';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Address - Full name */
  $handler->display->display_options['fields']['field_biography_address_name_line']['id'] = 'field_biography_address_name_line';
  $handler->display->display_options['fields']['field_biography_address_name_line']['table'] = 'field_data_field_biography_address';
  $handler->display->display_options['fields']['field_biography_address_name_line']['field'] = 'field_biography_address_name_line';
  $handler->display->display_options['fields']['field_biography_address_name_line']['label'] = '';
  $handler->display->display_options['fields']['field_biography_address_name_line']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_address_name_line']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = 'Contact [field_biography_address_name_line]';
  $handler->display->display_options['fields']['title_1']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: E-mail */
  $handler->display->display_options['fields']['field_biography_email']['id'] = 'field_biography_email';
  $handler->display->display_options['fields']['field_biography_email']['table'] = 'field_data_field_biography_email';
  $handler->display->display_options['fields']['field_biography_email']['field'] = 'field_biography_email';
  $handler->display->display_options['fields']['field_biography_email']['label'] = 'Email';
  $handler->display->display_options['fields']['field_biography_email']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_biography_email']['element_class'] = 'field__items';
  $handler->display->display_options['fields']['field_biography_email']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_biography_email']['element_label_class'] = 'field__label';
  $handler->display->display_options['fields']['field_biography_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_email']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_biography_email']['element_wrapper_class'] = 'field field--labeled';
  $handler->display->display_options['fields']['field_biography_email']['element_default_classes'] = FALSE;
  /* Field: Content: Phone number */
  $handler->display->display_options['fields']['field_biography_phone']['id'] = 'field_biography_phone';
  $handler->display->display_options['fields']['field_biography_phone']['table'] = 'field_data_field_biography_phone';
  $handler->display->display_options['fields']['field_biography_phone']['field'] = 'field_biography_phone';
  $handler->display->display_options['fields']['field_biography_phone']['label'] = '';
  $handler->display->display_options['fields']['field_biography_phone']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_biography_phone']['element_class'] = 'field__items';
  $handler->display->display_options['fields']['field_biography_phone']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_biography_phone']['element_label_class'] = 'field__label';
  $handler->display->display_options['fields']['field_biography_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_phone']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_biography_phone']['element_wrapper_class'] = 'field field--labeled';
  $handler->display->display_options['fields']['field_biography_phone']['element_default_classes'] = FALSE;
  /* Field: Content: Address - Company */
  $handler->display->display_options['fields']['field_biography_address_organisation_name']['id'] = 'field_biography_address_organisation_name';
  $handler->display->display_options['fields']['field_biography_address_organisation_name']['table'] = 'field_data_field_biography_address';
  $handler->display->display_options['fields']['field_biography_address_organisation_name']['field'] = 'field_biography_address_organisation_name';
  $handler->display->display_options['fields']['field_biography_address_organisation_name']['label'] = '';
  $handler->display->display_options['fields']['field_biography_address_organisation_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_address_organisation_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_address_organisation_name']['element_default_classes'] = FALSE;
  /* Field: Content: Address - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['field_biography_address_thoroughfare']['id'] = 'field_biography_address_thoroughfare';
  $handler->display->display_options['fields']['field_biography_address_thoroughfare']['table'] = 'field_data_field_biography_address';
  $handler->display->display_options['fields']['field_biography_address_thoroughfare']['field'] = 'field_biography_address_thoroughfare';
  $handler->display->display_options['fields']['field_biography_address_thoroughfare']['label'] = '';
  $handler->display->display_options['fields']['field_biography_address_thoroughfare']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_address_thoroughfare']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_address_thoroughfare']['element_default_classes'] = FALSE;
  /* Field: Content: Address - Postal code */
  $handler->display->display_options['fields']['field_biography_address_postal_code']['id'] = 'field_biography_address_postal_code';
  $handler->display->display_options['fields']['field_biography_address_postal_code']['table'] = 'field_data_field_biography_address';
  $handler->display->display_options['fields']['field_biography_address_postal_code']['field'] = 'field_biography_address_postal_code';
  $handler->display->display_options['fields']['field_biography_address_postal_code']['label'] = '';
  $handler->display->display_options['fields']['field_biography_address_postal_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_address_postal_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_address_postal_code']['element_default_classes'] = FALSE;
  /* Field: Content: Address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_biography_address_locality']['id'] = 'field_biography_address_locality';
  $handler->display->display_options['fields']['field_biography_address_locality']['table'] = 'field_data_field_biography_address';
  $handler->display->display_options['fields']['field_biography_address_locality']['field'] = 'field_biography_address_locality';
  $handler->display->display_options['fields']['field_biography_address_locality']['label'] = '';
  $handler->display->display_options['fields']['field_biography_address_locality']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_address_locality']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_biography_address_locality']['alter']['text'] = '<span>[field_biography_address_postal_code]</span>
  <span>[field_biography_address_locality]</span>';
  $handler->display->display_options['fields']['field_biography_address_locality']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_address_locality']['element_default_classes'] = FALSE;
  /* Field: Content: Address - Country */
  $handler->display->display_options['fields']['field_biography_address_country']['id'] = 'field_biography_address_country';
  $handler->display->display_options['fields']['field_biography_address_country']['table'] = 'field_data_field_biography_address';
  $handler->display->display_options['fields']['field_biography_address_country']['field'] = 'field_biography_address_country';
  $handler->display->display_options['fields']['field_biography_address_country']['label'] = '';
  $handler->display->display_options['fields']['field_biography_address_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_address_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_address_country']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_biography_address_country']['display_name'] = 1;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Address';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<p>[field_biography_address_organisation_name]</p>
  <p>[field_biography_address_thoroughfare]</p>
  <p>
  [field_biography_address_postal_code]
  [field_biography_address_locality]
  </p>
  [field_biography_address_country]';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'field__items';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['nothing']['element_label_class'] = 'field__label';
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'field field--labeled';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;

  /* Display: Contact block  Press (biography) */
  $handler = $view->new_display('attachment', 'Contact block  Press (biography)', 'attachment_biography_press_contact');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'listing__item listing__item--contact';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['separator'] = ' ';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_biography_press_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = 'Press contact';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Press contact */
  $handler->display->display_options['fields']['field_biography_press_contact']['id'] = 'field_biography_press_contact';
  $handler->display->display_options['fields']['field_biography_press_contact']['table'] = 'field_data_field_biography_press_contact';
  $handler->display->display_options['fields']['field_biography_press_contact']['field'] = 'field_biography_press_contact';
  $handler->display->display_options['fields']['field_biography_press_contact']['label'] = '';
  $handler->display->display_options['fields']['field_biography_press_contact']['element_label_colon'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'block' => 'block',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $export['contact'] = $view;

  return $export;
}
