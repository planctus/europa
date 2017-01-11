<?php
/**
 * @file
 * dt_publication.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dt_publication_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'publication_collections';
  $view->description = '';
  $view->tag = 'digital_transformation';
  $view->base_table = 'node';
  $view->human_name = 'Publication collections';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Part of collections:';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'nexteuropa_context_nav';
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_core_publications_target_id']['id'] = 'field_core_publications_target_id';
  $handler->display->display_options['relationships']['field_core_publications_target_id']['table'] = 'field_data_field_core_publications';
  $handler->display->display_options['relationships']['field_core_publications_target_id']['field'] = 'field_core_publications_target_id';
  $handler->display->display_options['relationships']['field_core_publications_target_id']['label'] = 'Collections referring publication documents';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'span';
  $handler->display->display_options['fields']['title']['element_class'] = 'context-nav__item';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_core_publications_target_id';
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'publication' => 'publication',
  );

  /* Display: Part of collections: */
  $handler = $view->new_display('block', 'Part of collections:', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Part of collections:';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'nexteuropa_context_nav';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['publication_collections'] = $view;

  $view = new view();
  $view->name = 'publication_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Publication List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Publications List';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Clear';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
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
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Taxonomy */
  $handler->display->display_options['fields']['field_eurovoc_taxonomy']['id'] = 'field_eurovoc_taxonomy';
  $handler->display->display_options['fields']['field_eurovoc_taxonomy']['table'] = 'field_data_field_eurovoc_taxonomy';
  $handler->display->display_options['fields']['field_eurovoc_taxonomy']['field'] = 'field_eurovoc_taxonomy';
  $handler->display->display_options['fields']['field_eurovoc_taxonomy']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_eurovoc_taxonomy']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_eurovoc_taxonomy']['delta_offset'] = '0';
  /* Field: Content: Countries */
  $handler->display->display_options['fields']['field_core_nal_countries']['id'] = 'field_core_nal_countries';
  $handler->display->display_options['fields']['field_core_nal_countries']['table'] = 'field_data_field_core_nal_countries';
  $handler->display->display_options['fields']['field_core_nal_countries']['field'] = 'field_core_nal_countries';
  $handler->display->display_options['fields']['field_core_nal_countries']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_core_nal_countries']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_nal_countries']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'publication' => 'publication',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Taxonomy (field_eurovoc_taxonomy) (selective) */
  $handler->display->display_options['filters']['field_eurovoc_taxonomy_target_id_selective']['id'] = 'field_eurovoc_taxonomy_target_id_selective';
  $handler->display->display_options['filters']['field_eurovoc_taxonomy_target_id_selective']['table'] = 'field_data_field_eurovoc_taxonomy';
  $handler->display->display_options['filters']['field_eurovoc_taxonomy_target_id_selective']['field'] = 'field_eurovoc_taxonomy_target_id_selective';
  $handler->display->display_options['filters']['field_eurovoc_taxonomy_target_id_selective']['ui_name'] = 'Taxonomy (field_eurovoc_taxonomy) (selective)';
  $handler->display->display_options['filters']['field_eurovoc_taxonomy_target_id_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_eurovoc_taxonomy_target_id_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_eurovoc_taxonomy_target_id_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_eurovoc_taxonomy_target_id_selective']['expose']['label'] = 'Topic';
  $handler->display->display_options['filters']['field_eurovoc_taxonomy_target_id_selective']['expose']['identifier'] = 'field_eurovoc_taxonomy_target_id_selective';
  $handler->display->display_options['filters']['field_eurovoc_taxonomy_target_id_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    16 => 0,
    7 => 0,
    12 => 0,
    9 => 0,
    21 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_eurovoc_taxonomy_target_id_selective']['selective_display_field'] = 'field_eurovoc_taxonomy';
  $handler->display->display_options['filters']['field_eurovoc_taxonomy_target_id_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Countries (field_core_nal_countries) (selective) */
  $handler->display->display_options['filters']['field_core_nal_countries_tid_selective']['id'] = 'field_core_nal_countries_tid_selective';
  $handler->display->display_options['filters']['field_core_nal_countries_tid_selective']['table'] = 'field_data_field_core_nal_countries';
  $handler->display->display_options['filters']['field_core_nal_countries_tid_selective']['field'] = 'field_core_nal_countries_tid_selective';
  $handler->display->display_options['filters']['field_core_nal_countries_tid_selective']['ui_name'] = 'Countries (field_core_nal_countries) (selective)';
  $handler->display->display_options['filters']['field_core_nal_countries_tid_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_core_nal_countries_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_nal_countries_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_core_nal_countries_tid_selective']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_core_nal_countries_tid_selective']['expose']['identifier'] = 'field_core_nal_countries_tid_selective';
  $handler->display->display_options['filters']['field_core_nal_countries_tid_selective']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_core_nal_countries_tid_selective']['selective_display_field'] = 'field_core_nal_countries';
  $handler->display->display_options['filters']['field_core_nal_countries_tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Year */
  $handler->display->display_options['filters']['field_core_date_updated_value']['id'] = 'field_core_date_updated_value';
  $handler->display->display_options['filters']['field_core_date_updated_value']['table'] = 'field_data_field_core_date_updated';
  $handler->display->display_options['filters']['field_core_date_updated_value']['field'] = 'field_core_date_updated_value';
  $handler->display->display_options['filters']['field_core_date_updated_value']['ui_name'] = 'Year';
  $handler->display->display_options['filters']['field_core_date_updated_value']['group'] = 1;
  $handler->display->display_options['filters']['field_core_date_updated_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_date_updated_value']['expose']['operator_id'] = 'field_core_date_updated_value_op';
  $handler->display->display_options['filters']['field_core_date_updated_value']['expose']['label'] = 'Year';
  $handler->display->display_options['filters']['field_core_date_updated_value']['expose']['operator'] = 'field_core_date_updated_value_op';
  $handler->display->display_options['filters']['field_core_date_updated_value']['expose']['identifier'] = 'field_core_date_updated_value';
  $handler->display->display_options['filters']['field_core_date_updated_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    16 => 0,
    7 => 0,
    12 => 0,
    9 => 0,
    21 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_core_date_updated_value']['granularity'] = 'year';
  $handler->display->display_options['filters']['field_core_date_updated_value']['default_to_date'] = '-15';
  $handler->display->display_options['filters']['field_core_date_updated_value']['year_range'] = '+1:-10';
  /* Filter criterion: Content: Publication type (field_publication_type) (translated) */
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['id'] = 'field_publication_type_tid_i18n';
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['table'] = 'field_data_field_publication_type';
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['field'] = 'field_publication_type_tid_i18n';
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['expose']['operator_id'] = 'field_publication_type_tid_i18n_op';
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['expose']['label'] = 'Publication type';
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['expose']['operator'] = 'field_publication_type_tid_i18n_op';
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['expose']['identifier'] = 'field_publication_type_tid_i18n';
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    16 => 0,
    7 => 0,
    12 => 0,
    9 => 0,
    21 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['vocabulary'] = 'publication_types';
  /* Filter criterion: Content: Tags (field_core_tags) (translated) */
  $handler->display->display_options['filters']['field_core_tags_tid_i18n']['id'] = 'field_core_tags_tid_i18n';
  $handler->display->display_options['filters']['field_core_tags_tid_i18n']['table'] = 'field_data_field_core_tags';
  $handler->display->display_options['filters']['field_core_tags_tid_i18n']['field'] = 'field_core_tags_tid_i18n';
  $handler->display->display_options['filters']['field_core_tags_tid_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_core_tags_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_tags_tid_i18n']['expose']['operator_id'] = 'field_core_tags_tid_i18n_op';
  $handler->display->display_options['filters']['field_core_tags_tid_i18n']['expose']['label'] = 'Tag';
  $handler->display->display_options['filters']['field_core_tags_tid_i18n']['expose']['operator'] = 'field_core_tags_tid_i18n_op';
  $handler->display->display_options['filters']['field_core_tags_tid_i18n']['expose']['identifier'] = 'field_core_tags_tid_i18n';
  $handler->display->display_options['filters']['field_core_tags_tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    16 => 0,
    7 => 0,
    12 => 0,
    9 => 0,
    21 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_core_tags_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_core_tags_tid_i18n']['vocabulary'] = 'tags';

  /* Display: Publications List */
  $handler = $view->new_display('block', 'Publications List', 'block');
  $handler->display->display_options['block_description'] = 'publications_list';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'publication-list';
  $export['publication_list'] = $view;

  $view = new view();
  $view->name = 'publications';
  $view->description = '';
  $view->tag = 'digital_transformation';
  $view->base_table = 'node';
  $view->human_name = 'Publications';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Documents';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'nexteuropa_bem_listing';
  $handler->display->display_options['style_options']['listing_columns'] = 'default';
  $handler->display->display_options['style_options']['listing_modifier'] = '';
  $handler->display->display_options['style_options']['listing_wrapper_modifier'] = 'paragraph';
  $handler->display->display_options['style_options']['listing_item_modifier'] = '';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_core_publications_node']['id'] = 'reverse_field_core_publications_node';
  $handler->display->display_options['relationships']['reverse_field_core_publications_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_core_publications_node']['field'] = 'reverse_field_core_publications_node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_core_publications_node';
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'publication' => 'publication',
  );

  /* Display: Documents */
  $handler = $view->new_display('block', 'Documents', 'block_1');
  $export['publications'] = $view;

  return $export;
}
