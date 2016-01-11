<?php
/**
 * @file
 * cwt_team.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cwt_team_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'team_agenda';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Team agenda';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Activities';
  $handler->display->display_options['css_class'] = 'nav-body';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<p>[field_team_activities_info]</p>';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  /* Relationship: Content: Type (field_team_subtype) (translated) */
  $handler->display->display_options['relationships']['field_team_subtype_tid_i18n']['id'] = 'field_team_subtype_tid_i18n';
  $handler->display->display_options['relationships']['field_team_subtype_tid_i18n']['table'] = 'field_data_field_team_subtype';
  $handler->display->display_options['relationships']['field_team_subtype_tid_i18n']['field'] = 'field_team_subtype_tid_i18n';
  /* Field: Content: Activities */
  $handler->display->display_options['fields']['field_team_agenda']['id'] = 'field_team_agenda';
  $handler->display->display_options['fields']['field_team_agenda']['table'] = 'field_data_field_team_agenda';
  $handler->display->display_options['fields']['field_team_agenda']['field'] = 'field_team_agenda';
  $handler->display->display_options['fields']['field_team_agenda']['label'] = '';
  $handler->display->display_options['fields']['field_team_agenda']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_agenda']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_team_agenda']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_team_agenda']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_team_agenda']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_team_agenda']['multi_type'] = 'ul';
  /* Field: Content: Activities info */
  $handler->display->display_options['fields']['field_team_activities_info']['id'] = 'field_team_activities_info';
  $handler->display->display_options['fields']['field_team_activities_info']['table'] = 'field_data_field_team_activities_info';
  $handler->display->display_options['fields']['field_team_activities_info']['field'] = 'field_team_activities_info';
  $handler->display->display_options['fields']['field_team_activities_info']['label'] = '';
  $handler->display->display_options['fields']['field_team_activities_info']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_activities_info']['element_label_colon'] = FALSE;
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
    'team' => 'team',
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
    'team' => 'team',
  );
  /* Filter criterion: Content: Activities (field_team_agenda:title) */
  $handler->display->display_options['filters']['field_team_agenda_title']['id'] = 'field_team_agenda_title';
  $handler->display->display_options['filters']['field_team_agenda_title']['table'] = 'field_data_field_team_agenda';
  $handler->display->display_options['filters']['field_team_agenda_title']['field'] = 'field_team_agenda_title';
  $handler->display->display_options['filters']['field_team_agenda_title']['operator'] = 'not empty';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['team_agenda'] = $view;

  $view = new view();
  $view->name = 'team_attachments';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Team attachments';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Team attachments';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Attachments */
  $handler->display->display_options['fields']['field_team_attachments']['id'] = 'field_team_attachments';
  $handler->display->display_options['fields']['field_team_attachments']['table'] = 'field_data_field_team_attachments';
  $handler->display->display_options['fields']['field_team_attachments']['field'] = 'field_team_attachments';
  $handler->display->display_options['fields']['field_team_attachments']['label'] = '';
  $handler->display->display_options['fields']['field_team_attachments']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_attachments']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_team_attachments']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_team_attachments']['separator'] = '';
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
    'team' => 'team',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['team_attachments'] = $view;

  $view = new view();
  $view->name = 'team_cabinet_contact';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Team Cabinet Contact';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Contact the team';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'nexteuropa_bem_listing';
  $handler->display->display_options['style_options']['listing_columns'] = 'default';
  $handler->display->display_options['style_options']['listing_modifier'] = '';
  $handler->display->display_options['style_options']['listing_wrapper_modifier'] = '';
  $handler->display->display_options['style_options']['listing_item_modifier'] = 'listing__item--contact';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '[fallback_image]';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_biography_team_node']['id'] = 'reverse_field_biography_team_node';
  $handler->display->display_options['relationships']['reverse_field_biography_team_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_biography_team_node']['field'] = 'reverse_field_biography_team_node';
  $handler->display->display_options['relationships']['reverse_field_biography_team_node']['required'] = TRUE;
  /* Relationship: Content: Editorial section (field_editorial_section) (translated) */
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['id'] = 'field_editorial_section_tid_i18n';
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['table'] = 'field_data_field_editorial_section';
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['field'] = 'field_editorial_section_tid_i18n';
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['relationship'] = 'reverse_field_biography_team_node';
  /* Field: Content: Illustrative image */
  $handler->display->display_options['fields']['field_illustrative_image']['id'] = 'field_illustrative_image';
  $handler->display->display_options['fields']['field_illustrative_image']['table'] = 'field_data_field_illustrative_image';
  $handler->display->display_options['fields']['field_illustrative_image']['field'] = 'field_illustrative_image';
  $handler->display->display_options['fields']['field_illustrative_image']['label'] = '';
  $handler->display->display_options['fields']['field_illustrative_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_illustrative_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_illustrative_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_illustrative_image']['empty'] = '[fallback_image]';
  $handler->display->display_options['fields']['field_illustrative_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_illustrative_image']['type'] = 'picture';
  $handler->display->display_options['fields']['field_illustrative_image']['settings'] = array(
    'picture_mapping' => 'team_cabinet_image',
    'fallback_image_style' => 'large',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_illustrative_image']['field_api_classes'] = TRUE;
  /* Field: Content: E-mail */
  $handler->display->display_options['fields']['field_biography_email']['id'] = 'field_biography_email';
  $handler->display->display_options['fields']['field_biography_email']['table'] = 'field_data_field_biography_email';
  $handler->display->display_options['fields']['field_biography_email']['field'] = 'field_biography_email';
  $handler->display->display_options['fields']['field_biography_email']['relationship'] = 'reverse_field_biography_team_node';
  $handler->display->display_options['fields']['field_biography_email']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_biography_email']['element_class'] = 'field__items';
  $handler->display->display_options['fields']['field_biography_email']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_biography_email']['element_label_class'] = 'field__label';
  $handler->display->display_options['fields']['field_biography_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_email']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_biography_email']['element_wrapper_class'] = 'field field--labeled';
  $handler->display->display_options['fields']['field_biography_email']['element_default_classes'] = FALSE;
  /* Field: Content: Address - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['field_biography_address_thoroughfare']['id'] = 'field_biography_address_thoroughfare';
  $handler->display->display_options['fields']['field_biography_address_thoroughfare']['table'] = 'field_data_field_biography_address';
  $handler->display->display_options['fields']['field_biography_address_thoroughfare']['field'] = 'field_biography_address_thoroughfare';
  $handler->display->display_options['fields']['field_biography_address_thoroughfare']['relationship'] = 'reverse_field_biography_team_node';
  $handler->display->display_options['fields']['field_biography_address_thoroughfare']['label'] = '';
  $handler->display->display_options['fields']['field_biography_address_thoroughfare']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_address_thoroughfare']['element_label_colon'] = FALSE;
  /* Field: Content: Address - Postal code */
  $handler->display->display_options['fields']['field_biography_address_postal_code']['id'] = 'field_biography_address_postal_code';
  $handler->display->display_options['fields']['field_biography_address_postal_code']['table'] = 'field_data_field_biography_address';
  $handler->display->display_options['fields']['field_biography_address_postal_code']['field'] = 'field_biography_address_postal_code';
  $handler->display->display_options['fields']['field_biography_address_postal_code']['relationship'] = 'reverse_field_biography_team_node';
  $handler->display->display_options['fields']['field_biography_address_postal_code']['label'] = '';
  $handler->display->display_options['fields']['field_biography_address_postal_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_address_postal_code']['element_label_colon'] = FALSE;
  /* Field: Content: Address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_biography_address_locality']['id'] = 'field_biography_address_locality';
  $handler->display->display_options['fields']['field_biography_address_locality']['table'] = 'field_data_field_biography_address';
  $handler->display->display_options['fields']['field_biography_address_locality']['field'] = 'field_biography_address_locality';
  $handler->display->display_options['fields']['field_biography_address_locality']['relationship'] = 'reverse_field_biography_team_node';
  $handler->display->display_options['fields']['field_biography_address_locality']['label'] = '';
  $handler->display->display_options['fields']['field_biography_address_locality']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_address_locality']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_biography_address_locality']['alter']['text'] = '<span>[field_biography_address_postal_code]</span>
<span>[field_biography_address_locality]</span>';
  $handler->display->display_options['fields']['field_biography_address_locality']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_address_locality']['hide_empty'] = TRUE;
  /* Field: Content: Address - Country */
  $handler->display->display_options['fields']['field_biography_address_country']['id'] = 'field_biography_address_country';
  $handler->display->display_options['fields']['field_biography_address_country']['table'] = 'field_data_field_biography_address';
  $handler->display->display_options['fields']['field_biography_address_country']['field'] = 'field_biography_address_country';
  $handler->display->display_options['fields']['field_biography_address_country']['relationship'] = 'reverse_field_biography_team_node';
  $handler->display->display_options['fields']['field_biography_address_country']['label'] = '';
  $handler->display->display_options['fields']['field_biography_address_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_address_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_address_country']['display_name'] = 1;
  /* Field: Content: Address - Company */
  $handler->display->display_options['fields']['field_biography_address_organisation_name']['id'] = 'field_biography_address_organisation_name';
  $handler->display->display_options['fields']['field_biography_address_organisation_name']['table'] = 'field_data_field_biography_address';
  $handler->display->display_options['fields']['field_biography_address_organisation_name']['field'] = 'field_biography_address_organisation_name';
  $handler->display->display_options['fields']['field_biography_address_organisation_name']['relationship'] = 'reverse_field_biography_team_node';
  $handler->display->display_options['fields']['field_biography_address_organisation_name']['label'] = 'Address';
  $handler->display->display_options['fields']['field_biography_address_organisation_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_biography_address_organisation_name']['alter']['text'] = '[field_biography_address_organisation_name]<br>
[field_biography_address_thoroughfare]<br>
[field_biography_address_locality]
';
  $handler->display->display_options['fields']['field_biography_address_organisation_name']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_biography_address_organisation_name']['element_class'] = 'field__items';
  $handler->display->display_options['fields']['field_biography_address_organisation_name']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_biography_address_organisation_name']['element_label_class'] = 'field__label';
  $handler->display->display_options['fields']['field_biography_address_organisation_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_address_organisation_name']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_biography_address_organisation_name']['element_wrapper_class'] = 'field field--labeled';
  $handler->display->display_options['fields']['field_biography_address_organisation_name']['element_default_classes'] = FALSE;
  /* Field: Content: Media enquiries */
  $handler->display->display_options['fields']['field_team_media_enquiries']['id'] = 'field_team_media_enquiries';
  $handler->display->display_options['fields']['field_team_media_enquiries']['table'] = 'field_data_field_team_media_enquiries';
  $handler->display->display_options['fields']['field_team_media_enquiries']['field'] = 'field_team_media_enquiries';
  $handler->display->display_options['fields']['field_team_media_enquiries']['label'] = '';
  $handler->display->display_options['fields']['field_team_media_enquiries']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_team_media_enquiries']['element_class'] = 'field__items';
  $handler->display->display_options['fields']['field_team_media_enquiries']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_media_enquiries']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_team_media_enquiries']['element_wrapper_class'] = 'field field--labeled-align';
  $handler->display->display_options['fields']['field_team_media_enquiries']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_team_media_enquiries']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_team_media_enquiries']['type'] = 'link_button_default';
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
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['nid']['validate_options']['code'] = 'if (is_numeric($argument)) {
    $translations = translation_path_get_translations(\'node/\' . $argument);
    $nids = \'\';
    if (!empty($translations)) {
      foreach ($translations as $lang => $path) {
        $nids .= str_replace(\'node/\', \'\', $path) . \'+\';
      }
      $handler->argument = substr($nids, 0, -1);
   }
    return TRUE;
  }
  else {
    return FALSE;
  }';
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'access denied';
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
    'team' => 'team',
  );

  /* Display: Contact the team */
  $handler = $view->new_display('block', 'Contact the team', 'block');
  $handler->display->display_options['field_language_add_to_query'] = 0;
  $export['team_cabinet_contact'] = $view;

  $view = new view();
  $view->name = 'team_cabinet_members';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Team Cabinet members';
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
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Relationship: Content: Title (field_biography_role) (translated) */
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['id'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['table'] = 'field_data_field_biography_role';
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['field'] = 'field_biography_role_tid_i18n';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_team_membership_target_id']['id'] = 'field_team_membership_target_id';
  $handler->display->display_options['relationships']['field_team_membership_target_id']['table'] = 'field_data_field_team_membership';
  $handler->display->display_options['relationships']['field_team_membership_target_id']['field'] = 'field_team_membership_target_id';
  /* Relationship: Content: Editorial section (field_editorial_section) (translated) */
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['id'] = 'field_editorial_section_tid_i18n';
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['table'] = 'field_data_field_editorial_section';
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['field'] = 'field_editorial_section_tid_i18n';
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['relationship'] = 'field_team_membership_target_id';
  /* Field: Taxonomy term: Plural */
  $handler->display->display_options['fields']['field_type_plural']['id'] = 'field_type_plural';
  $handler->display->display_options['fields']['field_type_plural']['table'] = 'field_data_field_type_plural';
  $handler->display->display_options['fields']['field_type_plural']['field'] = 'field_type_plural';
  $handler->display->display_options['fields']['field_type_plural']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['fields']['field_type_plural']['label'] = '';
  $handler->display->display_options['fields']['field_type_plural']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_type_plural']['element_label_colon'] = FALSE;
  /* Field: Content: Portrait */
  $handler->display->display_options['fields']['field_biography_portrait']['id'] = 'field_biography_portrait';
  $handler->display->display_options['fields']['field_biography_portrait']['table'] = 'field_data_field_biography_portrait';
  $handler->display->display_options['fields']['field_biography_portrait']['field'] = 'field_biography_portrait';
  $handler->display->display_options['fields']['field_biography_portrait']['label'] = '';
  $handler->display->display_options['fields']['field_biography_portrait']['alter']['text'] = '[field_biography_portrait]';
  $handler->display->display_options['fields']['field_biography_portrait']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_portrait']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_biography_portrait']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_biography_portrait']['type'] = 'picture';
  $handler->display->display_options['fields']['field_biography_portrait']['settings'] = array(
    'picture_mapping' => 'team_cabinet_members_picture',
    'fallback_image_style' => 'team_members_130x130',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: First name */
  $handler->display->display_options['fields']['field_biography_first_name']['id'] = 'field_biography_first_name';
  $handler->display->display_options['fields']['field_biography_first_name']['table'] = 'field_data_field_biography_first_name';
  $handler->display->display_options['fields']['field_biography_first_name']['field'] = 'field_biography_first_name';
  $handler->display->display_options['fields']['field_biography_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_biography_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_first_name']['element_default_classes'] = FALSE;
  /* Field: Content: Last name */
  $handler->display->display_options['fields']['field_biography_last_name']['id'] = 'field_biography_last_name';
  $handler->display->display_options['fields']['field_biography_last_name']['table'] = 'field_data_field_biography_last_name';
  $handler->display->display_options['fields']['field_biography_last_name']['field'] = 'field_biography_last_name';
  $handler->display->display_options['fields']['field_biography_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_biography_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_biography_last_name']['alter']['text'] = '<span class="first-name">[field_biography_first_name]</span> <span class="last-name">[field_biography_last_name]</span>';
  $handler->display->display_options['fields']['field_biography_last_name']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_biography_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_last_name']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Responsabilities';
  $handler->display->display_options['fields']['body']['alter']['text'] = '<div class="member-details__main">[body]</div>';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Social Networks */
  $handler->display->display_options['fields']['field_social_networks']['id'] = 'field_social_networks';
  $handler->display->display_options['fields']['field_social_networks']['table'] = 'field_data_field_social_networks';
  $handler->display->display_options['fields']['field_social_networks']['field'] = 'field_social_networks';
  $handler->display->display_options['fields']['field_social_networks']['label'] = '';
  $handler->display->display_options['fields']['field_social_networks']['alter']['text'] = '<span class="social-networks">[field_social_networks]</span>';
  $handler->display->display_options['fields']['field_social_networks']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_social_networks']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_social_networks']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_social_networks']['type'] = 'social_network_link_css';
  $handler->display->display_options['fields']['field_social_networks']['settings'] = array(
    'icon_image_style' => '',
  );
  $handler->display->display_options['fields']['field_social_networks']['delta_offset'] = '0';
  /* Field: Content: E-mail */
  $handler->display->display_options['fields']['field_biography_email']['id'] = 'field_biography_email';
  $handler->display->display_options['fields']['field_biography_email']['table'] = 'field_data_field_biography_email';
  $handler->display->display_options['fields']['field_biography_email']['field'] = 'field_biography_email';
  $handler->display->display_options['fields']['field_biography_email']['alter']['text'] = '<span class="team-member__email">[field_biography_email]</span>';
  $handler->display->display_options['fields']['field_biography_email']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_biography_email']['element_label_class'] = 'label--aligned';
  $handler->display->display_options['fields']['field_biography_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_email']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_biography_email']['hide_empty'] = TRUE;
  /* Field: Content: Phone number */
  $handler->display->display_options['fields']['field_biography_phone']['id'] = 'field_biography_phone';
  $handler->display->display_options['fields']['field_biography_phone']['table'] = 'field_data_field_biography_phone';
  $handler->display->display_options['fields']['field_biography_phone']['field'] = 'field_biography_phone';
  $handler->display->display_options['fields']['field_biography_phone']['label'] = '';
  $handler->display->display_options['fields']['field_biography_phone']['alter']['text'] = '<a class="team-member__phone" href="tel:[field_biography_phone]">[field_biography_phone]</a>
';
  $handler->display->display_options['fields']['field_biography_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_biography_phone']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_biography_phone']['settings'] = array(
    'title_style' => '_none',
    'title_link' => '',
    'title_class' => '',
  );
  /* Field: Assistant Label */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Assistant Label';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = 'Assistant';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  /* Field: Content: Assistants */
  $handler->display->display_options['fields']['field_biography_assistants']['id'] = 'field_biography_assistants';
  $handler->display->display_options['fields']['field_biography_assistants']['table'] = 'field_data_field_biography_assistants';
  $handler->display->display_options['fields']['field_biography_assistants']['field'] = 'field_biography_assistants';
  $handler->display->display_options['fields']['field_biography_assistants']['label'] = '';
  $handler->display->display_options['fields']['field_biography_assistants']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_assistants']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_biography_assistants']['alter']['text'] = '<span class="label">[nothing_2]</span>
<div class="member-details-assistant">[field_biography_assistants]</div>';
  $handler->display->display_options['fields']['field_biography_assistants']['alter']['preserve_tags'] = '<span> <div>';
  $handler->display->display_options['fields']['field_biography_assistants']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_assistants']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_biography_assistants']['settings'] = array(
    'view_mode' => 'default',
    'links' => 0,
  );
  $handler->display->display_options['fields']['field_biography_assistants']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_biography_assistants']['multi_type'] = 'ul';
  /* Field: Content: Tagline */
  $handler->display->display_options['fields']['field_biography_tagline']['id'] = 'field_biography_tagline';
  $handler->display->display_options['fields']['field_biography_tagline']['table'] = 'field_data_field_biography_tagline';
  $handler->display->display_options['fields']['field_biography_tagline']['field'] = 'field_biography_tagline';
  $handler->display->display_options['fields']['field_biography_tagline']['label'] = '';
  $handler->display->display_options['fields']['field_biography_tagline']['alter']['text'] = '<div class="label label--upper">[field_biography_tagline] </div>';
  $handler->display->display_options['fields']['field_biography_tagline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_tagline']['element_default_classes'] = FALSE;
  /* Sort criterion: Weight: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'weight_weights';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Sort criterion: Content: Last name (field_biography_last_name) */
  $handler->display->display_options['sorts']['field_biography_last_name_value']['id'] = 'field_biography_last_name_value';
  $handler->display->display_options['sorts']['field_biography_last_name_value']['table'] = 'field_data_field_biography_last_name';
  $handler->display->display_options['sorts']['field_biography_last_name_value']['field'] = 'field_biography_last_name_value';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_team_membership_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['nid']['validate_options']['code'] = 'if (is_numeric($argument)) {
    $translations = translation_path_get_translations(\'node/\' . $argument);
    $nids = \'\';
    if (!empty($translations)) {
      foreach ($translations as $lang => $path) {
        $nids .= str_replace(\'node/\', \'\', $path) . \'+\';
      }
      $handler->argument = substr($nids, 0, -1);
    }
    return TRUE;
  }
  else {
    return FALSE;
  }';
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'access denied';
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
    'biography' => 'biography',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Taxonomy term: Taxonomy term UUID */
  $handler->display->display_options['filters']['uuid']['id'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid']['operator'] = '!=';
  $handler->display->display_options['filters']['uuid']['value'] = 'fea4c060-eb2d-4686-9ccc-64997aad4930';
  $handler->display->display_options['filters']['uuid']['group'] = 1;
  /* Filter criterion: Taxonomy term: Taxonomy term UUID */
  $handler->display->display_options['filters']['uuid_1']['id'] = 'uuid_1';
  $handler->display->display_options['filters']['uuid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_1']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_1']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid_1']['operator'] = '!=';
  $handler->display->display_options['filters']['uuid_1']['value'] = 'cbfbd9f8-72ae-4635-aa77-888075de774b';
  $handler->display->display_options['filters']['uuid_1']['group'] = 1;
  /* Filter criterion: Vice President */
  $handler->display->display_options['filters']['uuid_3']['id'] = 'uuid_3';
  $handler->display->display_options['filters']['uuid_3']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_3']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_3']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid_3']['ui_name'] = 'Vice President';
  $handler->display->display_options['filters']['uuid_3']['operator'] = '!=';
  $handler->display->display_options['filters']['uuid_3']['value'] = 'f7f7834a-3d60-4525-804b-439fd2d9f97a';
  $handler->display->display_options['filters']['uuid_3']['group'] = 1;
  /* Filter criterion: Commissioner */
  $handler->display->display_options['filters']['uuid_4']['id'] = 'uuid_4';
  $handler->display->display_options['filters']['uuid_4']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_4']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_4']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid_4']['ui_name'] = 'Commissioner';
  $handler->display->display_options['filters']['uuid_4']['operator'] = '!=';
  $handler->display->display_options['filters']['uuid_4']['value'] = 'ffbcfcf3-2f50-4c70-a11c-936cc4385cde';
  $handler->display->display_options['filters']['uuid_4']['group'] = 1;

  /* Display: Cabinet */
  $handler = $view->new_display('block', 'Cabinet', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Team members';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'nexteuropa_bem_listing';
  $handler->display->display_options['style_options']['listing_columns'] = 'default';
  $handler->display->display_options['style_options']['listing_modifier'] = 'listing--2rows';
  $handler->display->display_options['style_options']['listing_wrapper_modifier'] = 'listing__wrapper--forthy';
  $handler->display->display_options['style_options']['listing_item_modifier'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'team_cabinet_member';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['team_cabinet_members'] = $view;

  $view = new view();
  $view->name = 'team_header';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Team header';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Team header';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Term */
  $handler->display->display_options['fields']['field_team_term']['id'] = 'field_team_term';
  $handler->display->display_options['fields']['field_team_term']['table'] = 'field_data_field_team_term';
  $handler->display->display_options['fields']['field_team_term']['field'] = 'field_team_term';
  $handler->display->display_options['fields']['field_team_term']['label'] = '';
  $handler->display->display_options['fields']['field_team_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_term']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_team_term']['alter']['text'] = '([field_team_term])';
  $handler->display->display_options['fields']['field_team_term']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_term']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_team_subtype']['id'] = 'field_team_subtype';
  $handler->display->display_options['fields']['field_team_subtype']['table'] = 'field_data_field_team_subtype';
  $handler->display->display_options['fields']['field_team_subtype']['field'] = 'field_team_subtype';
  $handler->display->display_options['fields']['field_team_subtype']['label'] = '';
  $handler->display->display_options['fields']['field_team_subtype']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_subtype']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_subtype']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: Tagline */
  $handler->display->display_options['fields']['field_team_tagline']['id'] = 'field_team_tagline';
  $handler->display->display_options['fields']['field_team_tagline']['table'] = 'field_data_field_team_tagline';
  $handler->display->display_options['fields']['field_team_tagline']['field'] = 'field_team_tagline';
  $handler->display->display_options['fields']['field_team_tagline']['label'] = '';
  $handler->display->display_options['fields']['field_team_tagline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_tagline']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="page-header__hero-title">
<div class="meta meta--header">
<div class="meta__item meta__item--type">[field_team_subtype] [field_team_term]</div>
</div>
<h1>[title]</h1>
<p>[field_team_tagline]</p>
</div>';
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
    'team' => 'team',
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
    'team' => 'team',
  );

  /* Display: College */
  $handler = $view->new_display('block', 'College', 'college_header');

  /* Display: Cabinet */
  $handler = $view->new_display('block', 'Cabinet', 'cabinet_header');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_biography_team_node']['id'] = 'reverse_field_biography_team_node';
  $handler->display->display_options['relationships']['reverse_field_biography_team_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_biography_team_node']['field'] = 'reverse_field_biography_team_node';
  /* Relationship: Content: Editorial section (field_editorial_section) (translated) */
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['id'] = 'field_editorial_section_tid_i18n';
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['table'] = 'field_data_field_editorial_section';
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['field'] = 'field_editorial_section_tid_i18n';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="meta meta--header">
<div class="meta__item meta__item--type">Team</div>
</div>
<h1>[title_1]</h1>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $export['team_header'] = $view;

  $view = new view();
  $view->name = 'team_image';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Team image';
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
  /* Field: Content: Illustrative image */
  $handler->display->display_options['fields']['field_illustrative_image']['id'] = 'field_illustrative_image';
  $handler->display->display_options['fields']['field_illustrative_image']['table'] = 'field_data_field_illustrative_image';
  $handler->display->display_options['fields']['field_illustrative_image']['field'] = 'field_illustrative_image';
  $handler->display->display_options['fields']['field_illustrative_image']['label'] = '';
  $handler->display->display_options['fields']['field_illustrative_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_illustrative_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_illustrative_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_illustrative_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_illustrative_image']['type'] = 'picture';
  $handler->display->display_options['fields']['field_illustrative_image']['settings'] = array(
    'picture_mapping' => 'team_image',
    'fallback_image_style' => 'team_image_1280px',
    'image_link' => '',
    'colorbox' => 'team_members_picture',
  );
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
    'team' => 'team',
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
    'team' => 'team',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['team_image'] = $view;

  $view = new view();
  $view->name = 'team_members';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Team members';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '[field_team_block_title]';
  $handler->display->display_options['css_class'] = 'listing--column-left';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '21600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '21600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'nexteuropa_bem_listing';
  $handler->display->display_options['style_options']['listing_columns'] = 'default';
  $handler->display->display_options['style_options']['listing_modifier'] = 'listing--person';
  $handler->display->display_options['style_options']['listing_wrapper_modifier'] = 'listing--column-left';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Relationship: Content: Title (field_biography_role) (translated) */
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['id'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['table'] = 'field_data_field_biography_role';
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['field'] = 'field_biography_role_tid_i18n';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_team_membership_target_id']['id'] = 'field_team_membership_target_id';
  $handler->display->display_options['relationships']['field_team_membership_target_id']['table'] = 'field_data_field_team_membership';
  $handler->display->display_options['relationships']['field_team_membership_target_id']['field'] = 'field_team_membership_target_id';
  /* Relationship: Content: Editorial section (field_editorial_section) (translated) */
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['id'] = 'field_editorial_section_tid_i18n';
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['table'] = 'field_data_field_editorial_section';
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['field'] = 'field_editorial_section_tid_i18n';
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['relationship'] = 'field_team_membership_target_id';
  /* Relationship: Content: Status (field_biography_status) (translated) */
  $handler->display->display_options['relationships']['field_biography_status_tid_i18n']['id'] = 'field_biography_status_tid_i18n';
  $handler->display->display_options['relationships']['field_biography_status_tid_i18n']['table'] = 'field_data_field_biography_status';
  $handler->display->display_options['relationships']['field_biography_status_tid_i18n']['field'] = 'field_biography_status_tid_i18n';
  /* Field: Taxonomy term: Plural */
  $handler->display->display_options['fields']['field_type_plural']['id'] = 'field_type_plural';
  $handler->display->display_options['fields']['field_type_plural']['table'] = 'field_data_field_type_plural';
  $handler->display->display_options['fields']['field_type_plural']['field'] = 'field_type_plural';
  $handler->display->display_options['fields']['field_type_plural']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['fields']['field_type_plural']['label'] = '';
  $handler->display->display_options['fields']['field_type_plural']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_type_plural']['element_label_colon'] = FALSE;
  /* Field: Content: Portrait */
  $handler->display->display_options['fields']['field_biography_portrait']['id'] = 'field_biography_portrait';
  $handler->display->display_options['fields']['field_biography_portrait']['table'] = 'field_data_field_biography_portrait';
  $handler->display->display_options['fields']['field_biography_portrait']['field'] = 'field_biography_portrait';
  $handler->display->display_options['fields']['field_biography_portrait']['label'] = '';
  $handler->display->display_options['fields']['field_biography_portrait']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_portrait']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_biography_portrait']['alter']['text'] = '<div class="member-details-image">[field_biography_portrait]</div>';
  $handler->display->display_options['fields']['field_biography_portrait']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_portrait']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_biography_portrait']['settings'] = array(
    'image_style' => 'members_responsive_custom_user_min_width_480px_1x',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_field']['id'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field']['field'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['fields']['name_field']['label'] = '';
  $handler->display->display_options['fields']['name_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_field']['alter']['text'] = '<span class="term-[tid] [name_field] label role">[name_field]</span>';
  $handler->display->display_options['fields']['name_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['name_field']['link_to_entity'] = 0;
  /* Field: Taxonomy term: Feminine form */
  $handler->display->display_options['fields']['field_biography_role_feminine']['id'] = 'field_biography_role_feminine';
  $handler->display->display_options['fields']['field_biography_role_feminine']['table'] = 'field_data_field_biography_role_feminine';
  $handler->display->display_options['fields']['field_biography_role_feminine']['field'] = 'field_biography_role_feminine';
  $handler->display->display_options['fields']['field_biography_role_feminine']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['fields']['field_biography_role_feminine']['label'] = '';
  $handler->display->display_options['fields']['field_biography_role_feminine']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_role_feminine']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_role_feminine']['empty'] = '[name_field]';
  /* Field: Content: Gender */
  $handler->display->display_options['fields']['field_gender']['id'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['table'] = 'field_data_field_gender';
  $handler->display->display_options['fields']['field_gender']['field'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['label'] = '';
  $handler->display->display_options['fields']['field_gender']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gender']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_gender']['alter']['text'] = '<span class="term-[tid] [name_field] meta__item meta__item--type role">[field_biography_role_feminine]</span>';
  $handler->display->display_options['fields']['field_gender']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gender']['empty'] = '<span class="term-[tid] [name_field] meta__item meta__item--type role">[name_field]</span>';
  $handler->display->display_options['fields']['field_gender']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_gender']['type'] = 'list_key';
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['fields']['tid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid_1']['field'] = 'tid';
  $handler->display->display_options['fields']['tid_1']['relationship'] = 'field_biography_status_tid_i18n';
  $handler->display->display_options['fields']['tid_1']['label'] = '';
  $handler->display->display_options['fields']['tid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid_1']['separator'] = '';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_field_1']['id'] = 'name_field_1';
  $handler->display->display_options['fields']['name_field_1']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field_1']['field'] = 'name_field';
  $handler->display->display_options['fields']['name_field_1']['relationship'] = 'field_biography_status_tid_i18n';
  $handler->display->display_options['fields']['name_field_1']['label'] = '';
  $handler->display->display_options['fields']['name_field_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_field_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name_field_1']['alter']['text'] = '<span class="term-[tid_1] [name_field_1] label status">[name_field_1]</span>';
  $handler->display->display_options['fields']['name_field_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_field_1']['type'] = 'text_plain';
  $handler->display->display_options['fields']['name_field_1']['link_to_entity'] = 0;
  /* Field: Content: Source language path */
  $handler->display->display_options['fields']['cwt_team_source_language_path']['id'] = 'cwt_team_source_language_path';
  $handler->display->display_options['fields']['cwt_team_source_language_path']['table'] = 'node';
  $handler->display->display_options['fields']['cwt_team_source_language_path']['field'] = 'cwt_team_source_language_path';
  $handler->display->display_options['fields']['cwt_team_source_language_path']['label'] = '';
  $handler->display->display_options['fields']['cwt_team_source_language_path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cwt_team_source_language_path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['cwt_team_source_language_path']['absolute'] = TRUE;
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
  $handler->display->display_options['fields']['field_biography_last_name']['alter']['text'] = '<div class="member-details-name"><span class="first-name">[field_biography_first_name]</span> <span class="last-name">[field_biography_last_name]</span></div>';
  $handler->display->display_options['fields']['field_biography_last_name']['alter']['path'] = '[cwt_team_source_language_path]';
  $handler->display->display_options['fields']['field_biography_last_name']['element_label_colon'] = FALSE;
  /* Field: Content: Tagline */
  $handler->display->display_options['fields']['field_biography_tagline']['id'] = 'field_biography_tagline';
  $handler->display->display_options['fields']['field_biography_tagline']['table'] = 'field_data_field_biography_tagline';
  $handler->display->display_options['fields']['field_biography_tagline']['field'] = 'field_biography_tagline';
  $handler->display->display_options['fields']['field_biography_tagline']['label'] = '';
  $handler->display->display_options['fields']['field_biography_tagline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_tagline']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="[cwt_team_source_language_path]" class="listing__item-link is-internal">
  <div class="listing__column-second">
[field_biography_portrait]
 </div>
 <div class="listing__column-main">
  <div class="meta">
 <span class="meta__item meta__item--type">[field_gender]</span>
 </div>
<h3 class="listing__title">[field_biography_last_name]</h3>
<div>[field_biography_tagline]</div>
</div>
</a>';
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '[cwt_team_source_language_path]';
  $handler->display->display_options['fields']['nothing']['alter']['alt'] = '[field_biography_last_name]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight_1']['id'] = 'weight_1';
  $handler->display->display_options['sorts']['weight_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight_1']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight_1']['relationship'] = 'field_biography_status_tid_i18n';
  /* Sort criterion: Content: Last name (field_biography_last_name) */
  $handler->display->display_options['sorts']['field_biography_last_name_value']['id'] = 'field_biography_last_name_value';
  $handler->display->display_options['sorts']['field_biography_last_name_value']['table'] = 'field_data_field_biography_last_name';
  $handler->display->display_options['sorts']['field_biography_last_name_value']['field'] = 'field_biography_last_name_value';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_team_membership_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'team' => 'team',
  );
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
    3 => 'OR',
    4 => 'OR',
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
  /* Filter criterion: In office */
  $handler->display->display_options['filters']['uuid']['id'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['relationship'] = 'field_biography_status_tid_i18n';
  $handler->display->display_options['filters']['uuid']['ui_name'] = 'In office';
  $handler->display->display_options['filters']['uuid']['value'] = '5bea40f7-359a-4bf6-a952-c8a6c2f0f352';
  $handler->display->display_options['filters']['uuid']['group'] = 2;
  /* Filter criterion: On Leave */
  $handler->display->display_options['filters']['uuid_1']['id'] = 'uuid_1';
  $handler->display->display_options['filters']['uuid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_1']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_1']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid_1']['ui_name'] = 'On Leave';
  $handler->display->display_options['filters']['uuid_1']['value'] = 'a1e4e9d2-7c62-4d2b-a890-705ffe64bcaa';
  $handler->display->display_options['filters']['uuid_1']['group'] = 2;
  /* Filter criterion: No longer in office */
  $handler->display->display_options['filters']['uuid_2']['id'] = 'uuid_2';
  $handler->display->display_options['filters']['uuid_2']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_2']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_2']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid_2']['ui_name'] = 'No longer in office';
  $handler->display->display_options['filters']['uuid_2']['value'] = 'ad48f1e7-ee20-4d76-ae88-7c5bb0567e48';
  $handler->display->display_options['filters']['uuid_2']['group'] = 2;
  $handler->display->display_options['filters']['uuid_2']['expose']['operator_id'] = 'uuid_2_op';
  $handler->display->display_options['filters']['uuid_2']['expose']['label'] = 'Taxonomy term UUID';
  $handler->display->display_options['filters']['uuid_2']['expose']['operator'] = 'uuid_2_op';
  $handler->display->display_options['filters']['uuid_2']['expose']['identifier'] = 'uuid_2';
  /* Filter criterion: Vice President */
  $handler->display->display_options['filters']['uuid_3']['id'] = 'uuid_3';
  $handler->display->display_options['filters']['uuid_3']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_3']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_3']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid_3']['ui_name'] = 'Vice President';
  $handler->display->display_options['filters']['uuid_3']['value'] = 'f7f7834a-3d60-4525-804b-439fd2d9f97a';
  $handler->display->display_options['filters']['uuid_3']['group'] = 3;
  /* Filter criterion: High Representative */
  $handler->display->display_options['filters']['uuid_5']['id'] = 'uuid_5';
  $handler->display->display_options['filters']['uuid_5']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_5']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_5']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid_5']['ui_name'] = 'High Representative';
  $handler->display->display_options['filters']['uuid_5']['value'] = 'd6304632-edda-4f20-871a-0e49513adfa5';
  $handler->display->display_options['filters']['uuid_5']['group'] = 3;
  /* Filter criterion: First Vice-President */
  $handler->display->display_options['filters']['uuid_6']['id'] = 'uuid_6';
  $handler->display->display_options['filters']['uuid_6']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_6']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_6']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid_6']['ui_name'] = 'First Vice-President';
  $handler->display->display_options['filters']['uuid_6']['value'] = 'e0028e61-1cfa-4f6e-a036-4665b12ce86a';
  $handler->display->display_options['filters']['uuid_6']['group'] = 3;
  /* Filter criterion: Commissioner */
  $handler->display->display_options['filters']['uuid_4']['id'] = 'uuid_4';
  $handler->display->display_options['filters']['uuid_4']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_4']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_4']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid_4']['ui_name'] = 'Commissioner';
  $handler->display->display_options['filters']['uuid_4']['value'] = 'ffbcfcf3-2f50-4c70-a11c-936cc4385cde';
  $handler->display->display_options['filters']['uuid_4']['group'] = 3;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    'und' => 'und',
  );
  $handler->display->display_options['filters']['language']['group'] = 4;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language_1']['id'] = 'language_1';
  $handler->display->display_options['filters']['language_1']['table'] = 'node';
  $handler->display->display_options['filters']['language_1']['field'] = 'language';
  $handler->display->display_options['filters']['language_1']['value'] = array(
    '***DEFAULT_LANGUAGE***' => '***DEFAULT_LANGUAGE***',
  );
  $handler->display->display_options['filters']['language_1']['group'] = 4;

  /* Display: Commissioners Hierarchy */
  $handler = $view->new_display('block', 'Commissioners Hierarchy', 'block_2');
  $handler->display->display_options['display_comment'] = 'This display is altered to filter the results on the contents of the "Team members by hierarchy" nodequeue, and order it by the position in the queue. If the biography is not available in the current language it will use the default language as a fallback. See cwt_team_views_query_alter().';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Title (field_biography_role) (translated) */
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['id'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['table'] = 'field_data_field_biography_role';
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['field'] = 'field_biography_role_tid_i18n';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_team_membership_target_id']['id'] = 'field_team_membership_target_id';
  $handler->display->display_options['relationships']['field_team_membership_target_id']['table'] = 'field_data_field_team_membership';
  $handler->display->display_options['relationships']['field_team_membership_target_id']['field'] = 'field_team_membership_target_id';
  /* Relationship: Content: Editorial section (field_editorial_section) (translated) */
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['id'] = 'field_editorial_section_tid_i18n';
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['table'] = 'field_data_field_editorial_section';
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['field'] = 'field_editorial_section_tid_i18n';
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['relationship'] = 'field_team_membership_target_id';
  /* Relationship: Content: Status (field_biography_status) (translated) */
  $handler->display->display_options['relationships']['field_biography_status_tid_i18n']['id'] = 'field_biography_status_tid_i18n';
  $handler->display->display_options['relationships']['field_biography_status_tid_i18n']['table'] = 'field_data_field_biography_status';
  $handler->display->display_options['relationships']['field_biography_status_tid_i18n']['field'] = 'field_biography_status_tid_i18n';
  /* Relationship: Content translation: Source translation */
  $handler->display->display_options['relationships']['tnid']['id'] = 'tnid';
  $handler->display->display_options['relationships']['tnid']['table'] = 'node';
  $handler->display->display_options['relationships']['tnid']['field'] = 'tnid';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['relationship'] = 'tnid';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'team_members_by_hierarchy' => 'team_members_by_hierarchy',
    'biographies_by_project_teams' => 0,
    'highlights' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
  /* Filter criterion: Nodequeue: In queue */
  $handler->display->display_options['filters']['in_queue']['id'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['filters']['in_queue']['field'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['filters']['in_queue']['value'] = '1';
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: President */
  $handler = $view->new_display('block', 'President', 'block_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'team-members-president';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
    3 => 'OR',
  );
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
  /* Filter criterion: In office */
  $handler->display->display_options['filters']['uuid']['id'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['relationship'] = 'field_biography_status_tid_i18n';
  $handler->display->display_options['filters']['uuid']['ui_name'] = 'In office';
  $handler->display->display_options['filters']['uuid']['value'] = '5bea40f7-359a-4bf6-a952-c8a6c2f0f352';
  $handler->display->display_options['filters']['uuid']['group'] = 2;
  /* Filter criterion: On Leave */
  $handler->display->display_options['filters']['uuid_1']['id'] = 'uuid_1';
  $handler->display->display_options['filters']['uuid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_1']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_1']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid_1']['ui_name'] = 'On Leave';
  $handler->display->display_options['filters']['uuid_1']['value'] = 'a1e4e9d2-7c62-4d2b-a890-705ffe64bcaa';
  $handler->display->display_options['filters']['uuid_1']['group'] = 2;
  /* Filter criterion: No longer in office */
  $handler->display->display_options['filters']['uuid_2']['id'] = 'uuid_2';
  $handler->display->display_options['filters']['uuid_2']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_2']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_2']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid_2']['ui_name'] = 'No longer in office';
  $handler->display->display_options['filters']['uuid_2']['value'] = 'ad48f1e7-ee20-4d76-ae88-7c5bb0567e48';
  $handler->display->display_options['filters']['uuid_2']['group'] = 2;
  $handler->display->display_options['filters']['uuid_2']['expose']['operator_id'] = 'uuid_2_op';
  $handler->display->display_options['filters']['uuid_2']['expose']['label'] = 'Taxonomy term UUID';
  $handler->display->display_options['filters']['uuid_2']['expose']['operator'] = 'uuid_2_op';
  $handler->display->display_options['filters']['uuid_2']['expose']['identifier'] = 'uuid_2';
  /* Filter criterion: President */
  $handler->display->display_options['filters']['uuid_3']['id'] = 'uuid_3';
  $handler->display->display_options['filters']['uuid_3']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_3']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_3']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid_3']['ui_name'] = 'President';
  $handler->display->display_options['filters']['uuid_3']['value'] = 'fea4c060-eb2d-4686-9ccc-64997aad4930';
  $handler->display->display_options['filters']['uuid_3']['group'] = 3;

  /* Display: Commissioners Hierarchy - Name */
  $handler = $view->new_display('block', 'Commissioners Hierarchy - Name', 'block_3');
  $handler->display->display_options['display_comment'] = 'This display is altered to filter the results on the contents of the "Team members by hierarchy" nodequeue, and order it by the position in the queue. If the biography is not available in the current language it will use the default language as a fallback. See cwt_team_views_query_alter().';
  $handler->display->display_options['display_description'] = 'Only difference with this display is the order by name.';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Title (field_biography_role) (translated) */
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['id'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['table'] = 'field_data_field_biography_role';
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['field'] = 'field_biography_role_tid_i18n';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_team_membership_target_id']['id'] = 'field_team_membership_target_id';
  $handler->display->display_options['relationships']['field_team_membership_target_id']['table'] = 'field_data_field_team_membership';
  $handler->display->display_options['relationships']['field_team_membership_target_id']['field'] = 'field_team_membership_target_id';
  /* Relationship: Content: Editorial section (field_editorial_section) (translated) */
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['id'] = 'field_editorial_section_tid_i18n';
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['table'] = 'field_data_field_editorial_section';
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['field'] = 'field_editorial_section_tid_i18n';
  $handler->display->display_options['relationships']['field_editorial_section_tid_i18n']['relationship'] = 'field_team_membership_target_id';
  /* Relationship: Content: Status (field_biography_status) (translated) */
  $handler->display->display_options['relationships']['field_biography_status_tid_i18n']['id'] = 'field_biography_status_tid_i18n';
  $handler->display->display_options['relationships']['field_biography_status_tid_i18n']['table'] = 'field_data_field_biography_status';
  $handler->display->display_options['relationships']['field_biography_status_tid_i18n']['field'] = 'field_biography_status_tid_i18n';
  /* Relationship: Content translation: Source translation */
  $handler->display->display_options['relationships']['tnid']['id'] = 'tnid';
  $handler->display->display_options['relationships']['tnid']['table'] = 'node';
  $handler->display->display_options['relationships']['tnid']['field'] = 'tnid';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['relationship'] = 'tnid';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'team_members_by_hierarchy' => 'team_members_by_hierarchy',
    'biographies_by_project_teams' => 0,
    'highlights' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Last name (field_biography_last_name) */
  $handler->display->display_options['sorts']['field_biography_last_name_value']['id'] = 'field_biography_last_name_value';
  $handler->display->display_options['sorts']['field_biography_last_name_value']['table'] = 'field_data_field_biography_last_name';
  $handler->display->display_options['sorts']['field_biography_last_name_value']['field'] = 'field_biography_last_name_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
  /* Filter criterion: Nodequeue: In queue */
  $handler->display->display_options['filters']['in_queue']['id'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['filters']['in_queue']['field'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['filters']['in_queue']['value'] = '1';
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $export['team_members'] = $view;

  $view = new view();
  $view->name = 'team_members_by_domain';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Team members by domain';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Team members by domain';
  $handler->display->display_options['display_comment'] = 'This view is shown on "Team" pages (e.g. the "The Commissioners" page which currently serves as the homepage) in the "Project Teams" quicktab under the "Commissioners" section.

This view is altered by cwt_team_views_pre_render() to filter and order the results according to the "Biographies by Project Teams" smartqueues:
- The view retrieves all biographies that are tagged by terms in the "Project Teams" vocabulary in the current language as well as English. In the pre_render hook every node is checked to see if it is available in the current language. If not it falls back to English.
- All results that are not explicitly placed in one of the smartqueues are discarded.
- The results are grouped by Project Team, and the groups are ordered according to the position of the terms in the vocabulary.
- The results within a group are ordered according to their position in the smartqueue.';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '21600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '21600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name_field',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = 'expandable';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Taxonomy term: Content using Project team */
  $handler->display->display_options['relationships']['reverse_field_biography_project_team_node']['id'] = 'reverse_field_biography_project_team_node';
  $handler->display->display_options['relationships']['reverse_field_biography_project_team_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_biography_project_team_node']['field'] = 'reverse_field_biography_project_team_node';
  $handler->display->display_options['relationships']['reverse_field_biography_project_team_node']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_team_membership_target_id']['id'] = 'field_team_membership_target_id';
  $handler->display->display_options['relationships']['field_team_membership_target_id']['table'] = 'field_data_field_team_membership';
  $handler->display->display_options['relationships']['field_team_membership_target_id']['field'] = 'field_team_membership_target_id';
  $handler->display->display_options['relationships']['field_team_membership_target_id']['relationship'] = 'reverse_field_biography_project_team_node';
  /* Field: Taxonomy term: Classname */
  $handler->display->display_options['fields']['field_project_teams_classname']['id'] = 'field_project_teams_classname';
  $handler->display->display_options['fields']['field_project_teams_classname']['table'] = 'field_data_field_project_teams_classname';
  $handler->display->display_options['fields']['field_project_teams_classname']['field'] = 'field_project_teams_classname';
  $handler->display->display_options['fields']['field_project_teams_classname']['label'] = '';
  $handler->display->display_options['fields']['field_project_teams_classname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_project_teams_classname']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_field']['id'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field']['field'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['label'] = '';
  $handler->display->display_options['fields']['name_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_field']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name_field']['alter']['text'] = '<span class="icon icon--yellowbg icon--[field_project_teams_classname]"></span>[name_field]';
  $handler->display->display_options['fields']['name_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_field']['link_to_entity'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_biography_project_team_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Source language path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'cwt_team_source_language_path';
  $handler->display->display_options['fields']['path']['relationship'] = 'reverse_field_biography_project_team_node';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Tagline */
  $handler->display->display_options['fields']['field_biography_tagline']['id'] = 'field_biography_tagline';
  $handler->display->display_options['fields']['field_biography_tagline']['table'] = 'field_data_field_biography_tagline';
  $handler->display->display_options['fields']['field_biography_tagline']['field'] = 'field_biography_tagline';
  $handler->display->display_options['fields']['field_biography_tagline']['relationship'] = 'reverse_field_biography_project_team_node';
  $handler->display->display_options['fields']['field_biography_tagline']['label'] = '';
  $handler->display->display_options['fields']['field_biography_tagline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_tagline']['element_label_colon'] = FALSE;
  /* Field: Content: Topics */
  $handler->display->display_options['fields']['field_biography_portfolio']['id'] = 'field_biography_portfolio';
  $handler->display->display_options['fields']['field_biography_portfolio']['table'] = 'field_data_field_biography_portfolio';
  $handler->display->display_options['fields']['field_biography_portfolio']['field'] = 'field_biography_portfolio';
  $handler->display->display_options['fields']['field_biography_portfolio']['relationship'] = 'reverse_field_biography_project_team_node';
  $handler->display->display_options['fields']['field_biography_portfolio']['label'] = '';
  $handler->display->display_options['fields']['field_biography_portfolio']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_portfolio']['alter']['text'] = '<span class="member-details-portfolio">[field_biography_portfolio]</span>';
  $handler->display->display_options['fields']['field_biography_portfolio']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_portfolio']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_biography_portfolio']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_biography_portfolio']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_biography_portfolio']['multi_type'] = 'ul';
  /* Field: Content: Portrait */
  $handler->display->display_options['fields']['field_biography_portrait']['id'] = 'field_biography_portrait';
  $handler->display->display_options['fields']['field_biography_portrait']['table'] = 'field_data_field_biography_portrait';
  $handler->display->display_options['fields']['field_biography_portrait']['field'] = 'field_biography_portrait';
  $handler->display->display_options['fields']['field_biography_portrait']['relationship'] = 'reverse_field_biography_project_team_node';
  $handler->display->display_options['fields']['field_biography_portrait']['label'] = '';
  $handler->display->display_options['fields']['field_biography_portrait']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_portrait']['alter']['text'] = '<div class="member-details-image">[field_biography_portrait]</div>';
  $handler->display->display_options['fields']['field_biography_portrait']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_portrait']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_biography_portrait']['settings'] = array(
    'image_style' => 'members_responsive_custom_user_min_width_480px_1x',
    'image_link' => '',
  );
  /* Field: Content: First name */
  $handler->display->display_options['fields']['field_biography_first_name']['id'] = 'field_biography_first_name';
  $handler->display->display_options['fields']['field_biography_first_name']['table'] = 'field_data_field_biography_first_name';
  $handler->display->display_options['fields']['field_biography_first_name']['field'] = 'field_biography_first_name';
  $handler->display->display_options['fields']['field_biography_first_name']['relationship'] = 'reverse_field_biography_project_team_node';
  $handler->display->display_options['fields']['field_biography_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_biography_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: Gender */
  $handler->display->display_options['fields']['field_gender']['id'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['table'] = 'field_data_field_gender';
  $handler->display->display_options['fields']['field_gender']['field'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['relationship'] = 'reverse_field_biography_project_team_node';
  $handler->display->display_options['fields']['field_gender']['label'] = '';
  $handler->display->display_options['fields']['field_gender']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gender']['element_label_colon'] = FALSE;
  /* Field: Content: Last name */
  $handler->display->display_options['fields']['field_biography_last_name']['id'] = 'field_biography_last_name';
  $handler->display->display_options['fields']['field_biography_last_name']['table'] = 'field_data_field_biography_last_name';
  $handler->display->display_options['fields']['field_biography_last_name']['field'] = 'field_biography_last_name';
  $handler->display->display_options['fields']['field_biography_last_name']['relationship'] = 'reverse_field_biography_project_team_node';
  $handler->display->display_options['fields']['field_biography_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_biography_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_biography_last_name']['alter']['text'] = '<a href="[path]" class="listing__item-link is-internal">
  <div class="listing__column-second">
    [field_biography_portrait]
  </div>
  <div class="listing__column-main">
    <h3 class="listing__title">[field_biography_first_name] [field_biography_last_name]</h3>
    <div>[field_biography_tagline]</div>
  </div>
</a>';
  $handler->display->display_options['fields']['field_biography_last_name']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_biography_last_name']['alter']['alt'] = '[field_biography_first_name] [field_biography_last_name]';
  $handler->display->display_options['fields']['field_biography_last_name']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_biography_last_name']['element_class'] = 'member-details';
  $handler->display->display_options['fields']['field_biography_last_name']['element_label_colon'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'reverse_field_biography_project_team_node';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    13 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'reverse_field_biography_project_team_node';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    'en' => 'en',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['team_members_by_domain'] = $view;

  $view = new view();
  $view->name = 'team_navigation';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Team Navigation';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'nav-body';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Links */
  $handler->display->display_options['fields']['field_team_links']['id'] = 'field_team_links';
  $handler->display->display_options['fields']['field_team_links']['table'] = 'field_data_field_team_links';
  $handler->display->display_options['fields']['field_team_links']['field'] = 'field_team_links';
  $handler->display->display_options['fields']['field_team_links']['label'] = '';
  $handler->display->display_options['fields']['field_team_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_links']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_team_links']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_team_links']['multi_type'] = 'ul';
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
    'team' => 'team',
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
    'team' => 'team',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['team_navigation'] = $view;

  $view = new view();
  $view->name = 'team_priorities';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Team priorities';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Priorities of the Commission';
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
  $handler->display->display_options['header']['area']['content'] = '<div class="block-description">[field_team_priorities_info]</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_team_priorities_node']['id'] = 'reverse_field_team_priorities_node';
  $handler->display->display_options['relationships']['reverse_field_team_priorities_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_team_priorities_node']['field'] = 'reverse_field_team_priorities_node';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_college_priority_link_1']['id'] = 'field_college_priority_link_1';
  $handler->display->display_options['fields']['field_college_priority_link_1']['table'] = 'field_data_field_college_priority_link';
  $handler->display->display_options['fields']['field_college_priority_link_1']['field'] = 'field_college_priority_link';
  $handler->display->display_options['fields']['field_college_priority_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_college_priority_link_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_college_priority_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_college_priority_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_college_priority_link_1']['type'] = 'link_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h3>[title]</h3>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_priority_image']['id'] = 'field_priority_image';
  $handler->display->display_options['fields']['field_priority_image']['table'] = 'field_data_field_priority_image';
  $handler->display->display_options['fields']['field_priority_image']['field'] = 'field_priority_image';
  $handler->display->display_options['fields']['field_priority_image']['label'] = '';
  $handler->display->display_options['fields']['field_priority_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_priority_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_priority_image']['alter']['text'] = '<div class="image">[field_priority_image]</div>';
  $handler->display->display_options['fields']['field_priority_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_priority_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_priority_image']['settings'] = array(
    'image_style' => 'priority_thumbnail',
    'image_link' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<span class="hover-bar"></span>
[field_priority_image]
<div class="text">
[title]
[body]
</div>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '[field_college_priority_link_1]';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Priorities info */
  $handler->display->display_options['fields']['field_team_priorities_info']['id'] = 'field_team_priorities_info';
  $handler->display->display_options['fields']['field_team_priorities_info']['table'] = 'field_data_field_team_priorities_info';
  $handler->display->display_options['fields']['field_team_priorities_info']['field'] = 'field_team_priorities_info';
  $handler->display->display_options['fields']['field_team_priorities_info']['relationship'] = 'reverse_field_team_priorities_node';
  $handler->display->display_options['fields']['field_team_priorities_info']['label'] = '';
  $handler->display->display_options['fields']['field_team_priorities_info']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_priorities_info']['element_label_colon'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_team_priorities_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'team' => 'team',
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
    'team_priority' => 'team_priority',
  );
  /* Filter criterion: Content: Type (field_team_subtype) */
  $handler->display->display_options['filters']['field_team_subtype_tid']['id'] = 'field_team_subtype_tid';
  $handler->display->display_options['filters']['field_team_subtype_tid']['table'] = 'field_data_field_team_subtype';
  $handler->display->display_options['filters']['field_team_subtype_tid']['field'] = 'field_team_subtype_tid';
  $handler->display->display_options['filters']['field_team_subtype_tid']['relationship'] = 'reverse_field_team_priorities_node';
  $handler->display->display_options['filters']['field_team_subtype_tid']['value'] = array(
    106 => '106',
  );
  $handler->display->display_options['filters']['field_team_subtype_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_team_subtype_tid']['vocabulary'] = 'team_subtypes';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['team_priorities'] = $view;

  $view = new view();
  $view->name = 'teams';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Teams';
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
  /* Relationship: Content: Type (field_team_subtype) */
  $handler->display->display_options['relationships']['field_team_subtype_tid']['id'] = 'field_team_subtype_tid';
  $handler->display->display_options['relationships']['field_team_subtype_tid']['table'] = 'field_data_field_team_subtype';
  $handler->display->display_options['relationships']['field_team_subtype_tid']['field'] = 'field_team_subtype_tid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
    'team' => 'team',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Taxonomy term: Taxonomy term UUID */
  $handler->display->display_options['filters']['uuid']['id'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['relationship'] = 'field_team_subtype_tid';
  $handler->display->display_options['filters']['uuid']['value'] = '6995fb8a-82db-4610-8b65-3cfc9f4cb580';
  $handler->display->display_options['filters']['uuid']['group'] = 1;

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['teams'] = $view;

  return $export;
}
