<?php
/**
 * @file
 * cwt_activities.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cwt_activities_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'activities';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Agenda';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Agenda';
  $handler->display->display_options['css_class'] = 'listing-custom';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'nexteuropa_bem_listing';
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['style_options']['listing_columns'] = 'default';
  $handler->display->display_options['style_options']['listing_modifier'] = '';
  $handler->display->display_options['style_options']['listing_wrapper_modifier'] = 'listing--agenda listing--column-left';
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'field_data_field_start_end_date|field_start_end_date_value';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'teaser';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '[nothing]';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* Relationship: Content: Editorial sections (field_editorial_section_multiple) */
  $handler->display->display_options['relationships']['field_editorial_section_multiple_tid']['id'] = 'field_editorial_section_multiple_tid';
  $handler->display->display_options['relationships']['field_editorial_section_multiple_tid']['table'] = 'field_data_field_editorial_section_multiple';
  $handler->display->display_options['relationships']['field_editorial_section_multiple_tid']['field'] = 'field_editorial_section_multiple_tid';
  $handler->display->display_options['relationships']['field_editorial_section_multiple_tid']['required'] = TRUE;
  /* Relationship: Taxonomy term: Content using Editorial section */
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['id'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['field'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['relationship'] = 'field_editorial_section_multiple_tid';
  /* Field: Content: Editorial section */
  $handler->display->display_options['fields']['field_editorial_section']['id'] = 'field_editorial_section';
  $handler->display->display_options['fields']['field_editorial_section']['table'] = 'field_data_field_editorial_section';
  $handler->display->display_options['fields']['field_editorial_section']['field'] = 'field_editorial_section';
  $handler->display->display_options['fields']['field_editorial_section']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['fields']['field_editorial_section']['label'] = '';
  $handler->display->display_options['fields']['field_editorial_section']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_editorial_section']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_editorial_section']['alter']['text'] = 'More agenda items';
  $handler->display->display_options['fields']['field_editorial_section']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_editorial_section']['alter']['path'] = 'agenda/[field_editorial_section]';
  $handler->display->display_options['fields']['field_editorial_section']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_editorial_section']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['field_editorial_section']['alter']['alt'] = 'More agenda items for %1';
  $handler->display->display_options['fields']['field_editorial_section']['alter']['link_class'] = 'link';
  $handler->display->display_options['fields']['field_editorial_section']['alter']['prefix'] = '<div class="more-link">';
  $handler->display->display_options['fields']['field_editorial_section']['alter']['suffix'] = '</div>';
  $handler->display->display_options['fields']['field_editorial_section']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_editorial_section']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Start/End date */
  $handler->display->display_options['fields']['field_start_end_date']['id'] = 'field_start_end_date';
  $handler->display->display_options['fields']['field_start_end_date']['table'] = 'field_data_field_start_end_date';
  $handler->display->display_options['fields']['field_start_end_date']['field'] = 'field_start_end_date';
  $handler->display->display_options['fields']['field_start_end_date']['label'] = '';
  $handler->display->display_options['fields']['field_start_end_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_end_date']['element_wrapper_class'] = 'listing-item-event-date';
  $handler->display->display_options['fields']['field_start_end_date']['type'] = 'commissioner_date_event_date';
  $handler->display->display_options['fields']['field_start_end_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: External link */
  $handler->display->display_options['fields']['field_activity_link']['id'] = 'field_activity_link';
  $handler->display->display_options['fields']['field_activity_link']['table'] = 'field_data_field_activity_link';
  $handler->display->display_options['fields']['field_activity_link']['field'] = 'field_activity_link';
  $handler->display->display_options['fields']['field_activity_link']['label'] = '';
  $handler->display->display_options['fields']['field_activity_link']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_activity_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_activity_link']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_activity_link']['click_sort_column'] = 'url';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Block and page description */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Block and page description';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Appointments and meetings';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Start/End date -  start date (field_start_end_date) */
  $handler->display->display_options['sorts']['field_start_end_date_value']['id'] = 'field_start_end_date_value';
  $handler->display->display_options['sorts']['field_start_end_date_value']['table'] = 'field_data_field_start_end_date';
  $handler->display->display_options['sorts']['field_start_end_date_value']['field'] = 'field_start_end_date_value';
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
    'activities' => 'activities',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Start/End date -  start date (field_start_end_date) */
  $handler->display->display_options['filters']['field_start_end_date_value']['id'] = 'field_start_end_date_value';
  $handler->display->display_options['filters']['field_start_end_date_value']['table'] = 'field_data_field_start_end_date';
  $handler->display->display_options['filters']['field_start_end_date_value']['field'] = 'field_start_end_date_value';
  $handler->display->display_options['filters']['field_start_end_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_start_end_date_value']['group'] = 2;
  $handler->display->display_options['filters']['field_start_end_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Start/End date - end date (field_start_end_date:value2) */
  $handler->display->display_options['filters']['field_start_end_date_value2']['id'] = 'field_start_end_date_value2';
  $handler->display->display_options['filters']['field_start_end_date_value2']['table'] = 'field_data_field_start_end_date';
  $handler->display->display_options['filters']['field_start_end_date_value2']['field'] = 'field_start_end_date_value2';
  $handler->display->display_options['filters']['field_start_end_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_start_end_date_value2']['group'] = 2;
  $handler->display->display_options['filters']['field_start_end_date_value2']['default_date'] = 'now';

  /* Display: Agenda block */
  $handler = $view->new_display('block', 'Agenda block', 'block');
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: More link */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['ui_name'] = 'More link';
  $handler->display->display_options['footer']['area']['content'] = 'More agenda items';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area_1']['id'] = 'area_1';
  $handler->display->display_options['footer']['area_1']['table'] = 'views';
  $handler->display->display_options['footer']['area_1']['field'] = 'area';
  $handler->display->display_options['footer']['area_1']['content'] = '<div class="free-text">[field_biography_agenda_text]</div>';
  $handler->display->display_options['footer']['area_1']['format'] = 'full_html';
  $handler->display->display_options['footer']['area_1']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: View area */
  $handler->display->display_options['empty']['view']['id'] = 'view';
  $handler->display->display_options['empty']['view']['table'] = 'views';
  $handler->display->display_options['empty']['view']['field'] = 'view';
  $handler->display->display_options['empty']['view']['empty'] = TRUE;
  $handler->display->display_options['empty']['view']['view_to_insert'] = 'activities:attachment_2';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Editorial section */
  $handler->display->display_options['fields']['field_editorial_section']['id'] = 'field_editorial_section';
  $handler->display->display_options['fields']['field_editorial_section']['table'] = 'field_data_field_editorial_section';
  $handler->display->display_options['fields']['field_editorial_section']['field'] = 'field_editorial_section';
  $handler->display->display_options['fields']['field_editorial_section']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['fields']['field_editorial_section']['label'] = '';
  $handler->display->display_options['fields']['field_editorial_section']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_editorial_section']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_editorial_section']['alter']['text'] = 'More agenda items';
  $handler->display->display_options['fields']['field_editorial_section']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_editorial_section']['alter']['path'] = 'agenda/[field_editorial_section]';
  $handler->display->display_options['fields']['field_editorial_section']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_editorial_section']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['field_editorial_section']['alter']['alt'] = 'More agenda items for %1';
  $handler->display->display_options['fields']['field_editorial_section']['alter']['link_class'] = 'link';
  $handler->display->display_options['fields']['field_editorial_section']['alter']['prefix'] = '<div class="more-link">';
  $handler->display->display_options['fields']['field_editorial_section']['alter']['suffix'] = '</div>';
  $handler->display->display_options['fields']['field_editorial_section']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_editorial_section']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Start/End date */
  $handler->display->display_options['fields']['field_start_end_date']['id'] = 'field_start_end_date';
  $handler->display->display_options['fields']['field_start_end_date']['table'] = 'field_data_field_start_end_date';
  $handler->display->display_options['fields']['field_start_end_date']['field'] = 'field_start_end_date';
  $handler->display->display_options['fields']['field_start_end_date']['label'] = '';
  $handler->display->display_options['fields']['field_start_end_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_end_date']['element_wrapper_class'] = 'listing-item-event-date';
  $handler->display->display_options['fields']['field_start_end_date']['type'] = 'commissioner_date_event_date';
  $handler->display->display_options['fields']['field_start_end_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: External link */
  $handler->display->display_options['fields']['field_activity_link']['id'] = 'field_activity_link';
  $handler->display->display_options['fields']['field_activity_link']['table'] = 'field_data_field_activity_link';
  $handler->display->display_options['fields']['field_activity_link']['field'] = 'field_activity_link';
  $handler->display->display_options['fields']['field_activity_link']['label'] = '';
  $handler->display->display_options['fields']['field_activity_link']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_activity_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_activity_link']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_activity_link']['click_sort_column'] = 'url';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Block and page description */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Block and page description';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Appointments and meetings';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Agenda transparency text */
  $handler->display->display_options['fields']['field_biography_agenda_text']['id'] = 'field_biography_agenda_text';
  $handler->display->display_options['fields']['field_biography_agenda_text']['table'] = 'field_data_field_biography_agenda_text';
  $handler->display->display_options['fields']['field_biography_agenda_text']['field'] = 'field_biography_agenda_text';
  $handler->display->display_options['fields']['field_biography_agenda_text']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['fields']['field_biography_agenda_text']['label'] = '';
  $handler->display->display_options['fields']['field_biography_agenda_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_agenda_text']['element_label_colon'] = FALSE;

  /* Display: Attachment for empty block */
  $handler = $view->new_display('attachment', 'Attachment for empty block', 'attachment_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Block and page description */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Block and page description';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Appointments and meetings';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: No upcoming agenda items */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'No upcoming agenda items';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'No upcoming agenda items';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Content: Agenda transparency text */
  $handler->display->display_options['fields']['field_biography_agenda_text']['id'] = 'field_biography_agenda_text';
  $handler->display->display_options['fields']['field_biography_agenda_text']['table'] = 'field_data_field_biography_agenda_text';
  $handler->display->display_options['fields']['field_biography_agenda_text']['field'] = 'field_biography_agenda_text';
  $handler->display->display_options['fields']['field_biography_agenda_text']['label'] = '';
  $handler->display->display_options['fields']['field_biography_agenda_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_agenda_text']['element_wrapper_class'] = 'free-text';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['arguments']['nid_1']['table'] = 'node';
  $handler->display->display_options['arguments']['nid_1']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid_1']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid_1']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid_1']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid_1']['validate_options']['types'] = array(
    'biography' => 'biography',
  );
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
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'block' => 0,
    'page_1' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_arguments'] = FALSE;
  $export['activities'] = $view;

  $view = new view();
  $view->name = 'agenda';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Agenda global';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Agenda';
  $handler->display->display_options['css_class'] = 'listing-custom';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Refine results';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'nexteuropa_bem_listing';
  $handler->display->display_options['style_options']['listing_columns'] = 'default';
  $handler->display->display_options['style_options']['listing_modifier'] = '';
  $handler->display->display_options['style_options']['listing_wrapper_modifier'] = 'listing--agenda listing--column-left';
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'field_data_field_start_end_date|field_start_end_date_value';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'teaser';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['header']['result']['content'] = '<div class="result-count pull-left"><p>@total items[filter_info]</p></div>';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>There are no matching agenda items.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Start/End date */
  $handler->display->display_options['fields']['field_start_end_date']['id'] = 'field_start_end_date';
  $handler->display->display_options['fields']['field_start_end_date']['table'] = 'field_data_field_start_end_date';
  $handler->display->display_options['fields']['field_start_end_date']['field'] = 'field_start_end_date';
  $handler->display->display_options['fields']['field_start_end_date']['label'] = '';
  $handler->display->display_options['fields']['field_start_end_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_end_date']['element_wrapper_class'] = 'listing-item-event-date';
  $handler->display->display_options['fields']['field_start_end_date']['type'] = 'commissioner_date_event_date';
  $handler->display->display_options['fields']['field_start_end_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: External link */
  $handler->display->display_options['fields']['field_activity_link']['id'] = 'field_activity_link';
  $handler->display->display_options['fields']['field_activity_link']['table'] = 'field_data_field_activity_link';
  $handler->display->display_options['fields']['field_activity_link']['field'] = 'field_activity_link';
  $handler->display->display_options['fields']['field_activity_link']['label'] = '';
  $handler->display->display_options['fields']['field_activity_link']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_activity_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_activity_link']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_activity_link']['click_sort_column'] = 'url';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Editorial sections */
  $handler->display->display_options['fields']['field_editorial_section_multiple']['id'] = 'field_editorial_section_multiple';
  $handler->display->display_options['fields']['field_editorial_section_multiple']['table'] = 'field_data_field_editorial_section_multiple';
  $handler->display->display_options['fields']['field_editorial_section_multiple']['field'] = 'field_editorial_section_multiple';
  $handler->display->display_options['fields']['field_editorial_section_multiple']['label'] = 'With';
  $handler->display->display_options['fields']['field_editorial_section_multiple']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_editorial_section_multiple']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_editorial_section_multiple']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_editorial_section_multiple']['delta_offset'] = '0';
  /* Sort criterion: Content: Start/End date -  start date (field_start_end_date) */
  $handler->display->display_options['sorts']['field_start_end_date_value']['id'] = 'field_start_end_date_value';
  $handler->display->display_options['sorts']['field_start_end_date_value']['table'] = 'field_data_field_start_end_date';
  $handler->display->display_options['sorts']['field_start_end_date_value']['field'] = 'field_start_end_date_value';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
    'editorial_sections' => 'editorial_sections',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['type'] = 'tids';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '4';
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
    'activities' => 'activities',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['date_filter']['group_info']['label'] = 'Date (node)';
  $handler->display->display_options['filters']['date_filter']['group_info']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['date_filter']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_start_end_date.field_start_end_date_value' => 'field_data_field_start_end_date.field_start_end_date_value',
    'field_data_field_start_end_date.field_start_end_date_value2' => 'field_data_field_start_end_date.field_start_end_date_value2',
  );
  /* Filter criterion: Content: Editorial sections (field_editorial_section_multiple) */
  $handler->display->display_options['filters']['field_editorial_section_multiple_tid']['id'] = 'field_editorial_section_multiple_tid';
  $handler->display->display_options['filters']['field_editorial_section_multiple_tid']['table'] = 'field_data_field_editorial_section_multiple';
  $handler->display->display_options['filters']['field_editorial_section_multiple_tid']['field'] = 'field_editorial_section_multiple_tid';
  $handler->display->display_options['filters']['field_editorial_section_multiple_tid']['value'] = array(
    163 => '163',
  );
  $handler->display->display_options['filters']['field_editorial_section_multiple_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_editorial_section_multiple_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_editorial_section_multiple_tid']['expose']['operator_id'] = 'field_editorial_section_multiple_tid_op';
  $handler->display->display_options['filters']['field_editorial_section_multiple_tid']['expose']['label'] = 'Commissioner';
  $handler->display->display_options['filters']['field_editorial_section_multiple_tid']['expose']['operator'] = 'field_editorial_section_multiple_tid_op';
  $handler->display->display_options['filters']['field_editorial_section_multiple_tid']['expose']['identifier'] = 'field_editorial_section_multiple_tid';
  $handler->display->display_options['filters']['field_editorial_section_multiple_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    6 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
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
  $handler->display->display_options['filters']['field_editorial_section_multiple_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_editorial_section_multiple_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_editorial_section_multiple_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_editorial_section_multiple_tid']['vocabulary'] = 'editorial_sections';

  /* Display: Agenda items */
  $handler = $view->new_display('page', 'Agenda items', 'list');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Agenda';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'listing-custom listing-custom--page';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['path'] = 'agenda/%';
  $export['agenda'] = $view;

  return $export;
}
