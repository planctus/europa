<?php
/**
 * @file
 * cwt_blogs.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cwt_blogs_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'blog_commisioner';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Blog Commisioner';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '[title_1] - Blog - European Commission';
  $handler->display->display_options['css_class'] = 'listing-custom';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'More Blog Posts';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'nexteuropa_bem_listing';
  $handler->display->display_options['style_options']['listing_columns'] = 'default';
  $handler->display->display_options['style_options']['listing_modifier'] = '';
  $handler->display->display_options['style_options']['listing_wrapper_modifier'] = '';
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
  $handler->display->display_options['header']['result']['content'] = '<div class="result-count"><p>@total posts</p></div>';
  /* Relationship: Content: Editorial section (field_editorial_section) */
  $handler->display->display_options['relationships']['field_editorial_section_tid']['id'] = 'field_editorial_section_tid';
  $handler->display->display_options['relationships']['field_editorial_section_tid']['table'] = 'field_data_field_editorial_section';
  $handler->display->display_options['relationships']['field_editorial_section_tid']['field'] = 'field_editorial_section_tid';
  /* Relationship: Taxonomy term: Content using Editorial section */
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['id'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['field'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['relationship'] = 'field_editorial_section_tid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = 'Published by <span class="listing-item-author">[title_1]</span> <span class="separator">|</span> [created]';
  $handler->display->display_options['fields']['created']['element_class'] = 'listing-item-metadata';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'ec_date';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_com_blog_image']['id'] = 'field_com_blog_image';
  $handler->display->display_options['fields']['field_com_blog_image']['table'] = 'field_data_field_com_blog_image';
  $handler->display->display_options['fields']['field_com_blog_image']['field'] = 'field_com_blog_image';
  $handler->display->display_options['fields']['field_com_blog_image']['label'] = '';
  $handler->display->display_options['fields']['field_com_blog_image']['element_class'] = 'listing-item-image';
  $handler->display->display_options['fields']['field_com_blog_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_com_blog_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_com_blog_image']['type'] = 'picture';
  $handler->display->display_options['fields']['field_com_blog_image']['settings'] = array(
    'picture_mapping' => 'lists_pages',
    'fallback_image_style' => 'listings_307x205',
    'image_link' => 'content',
    'colorbox' => 'team_members_picture',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Teaser */
  $handler->display->display_options['fields']['field_shared_teaser']['id'] = 'field_shared_teaser';
  $handler->display->display_options['fields']['field_shared_teaser']['table'] = 'field_data_field_shared_teaser';
  $handler->display->display_options['fields']['field_shared_teaser']['field'] = 'field_shared_teaser';
  $handler->display->display_options['fields']['field_shared_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_shared_teaser']['alter']['max_length'] = '250';
  $handler->display->display_options['fields']['field_shared_teaser']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_shared_teaser']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_shared_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_shared_teaser']['element_wrapper_class'] = 'listing-item-teaser';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['text'] = '[path]#comments';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['comment_count']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['element_type'] = '0';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['comment_count']['element_wrapper_class'] = 'listing-item-comment-count';
  $handler->display->display_options['fields']['comment_count']['suffix'] = ' comments';
  /* Field: Content: Tagline */
  $handler->display->display_options['fields']['field_biography_tagline']['id'] = 'field_biography_tagline';
  $handler->display->display_options['fields']['field_biography_tagline']['table'] = 'field_data_field_biography_tagline';
  $handler->display->display_options['fields']['field_biography_tagline']['field'] = 'field_biography_tagline';
  $handler->display->display_options['fields']['field_biography_tagline']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['fields']['field_biography_tagline']['label'] = '';
  $handler->display->display_options['fields']['field_biography_tagline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_tagline']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_biography_role']['id'] = 'field_biography_role';
  $handler->display->display_options['fields']['field_biography_role']['table'] = 'field_data_field_biography_role';
  $handler->display->display_options['fields']['field_biography_role']['field'] = 'field_biography_role';
  $handler->display->display_options['fields']['field_biography_role']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['fields']['field_biography_role']['label'] = '';
  $handler->display->display_options['fields']['field_biography_role']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_role']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
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
    'commisioner_blog_post' => 'commisioner_blog_post',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Blog list page */
  $handler = $view->new_display('page', 'Blog list page', 'list');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Blog';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'listing-custom listing-custom--page';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'biography' => 'biography',
  );
  $handler->display->display_options['path'] = 'blog';

  /* Display: Blog list page per term */
  $handler = $view->new_display('page', 'Blog list page per term', 'commisioner_blog_listing_term');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'listing-custom listing-custom--page';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Editorial section (field_editorial_section) */
  $handler->display->display_options['relationships']['field_editorial_section_tid']['id'] = 'field_editorial_section_tid';
  $handler->display->display_options['relationships']['field_editorial_section_tid']['table'] = 'field_data_field_editorial_section';
  $handler->display->display_options['relationships']['field_editorial_section_tid']['field'] = 'field_editorial_section_tid';
  /* Relationship: Taxonomy term: Content using Editorial section */
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['id'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['field'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['relationship'] = 'field_editorial_section_tid';
  /* Relationship: Content: Title (field_biography_role) (translated) */
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['id'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['table'] = 'field_data_field_biography_role';
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['field'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['relationships']['field_biography_role_tid_i18n']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid']['title'] = 'Tag: %1';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'tags' => 'tags',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
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
    'commisioner_blog_post' => 'commisioner_blog_post',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'biography' => 'biography',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  /* Filter criterion: High Representative */
  $handler->display->display_options['filters']['uuid_3']['id'] = 'uuid_3';
  $handler->display->display_options['filters']['uuid_3']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_3']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_3']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid_3']['ui_name'] = 'High Representative';
  $handler->display->display_options['filters']['uuid_3']['value'] = 'd6304632-edda-4f20-871a-0e49513adfa5';
  $handler->display->display_options['filters']['uuid_3']['group'] = 2;
  /* Filter criterion: First Vice-President */
  $handler->display->display_options['filters']['uuid_4']['id'] = 'uuid_4';
  $handler->display->display_options['filters']['uuid_4']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_4']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_4']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid_4']['ui_name'] = 'First Vice-President';
  $handler->display->display_options['filters']['uuid_4']['value'] = 'e0028e61-1cfa-4f6e-a036-4665b12ce86a';
  $handler->display->display_options['filters']['uuid_4']['group'] = 2;
  /* Filter criterion: President */
  $handler->display->display_options['filters']['uuid_2']['id'] = 'uuid_2';
  $handler->display->display_options['filters']['uuid_2']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_2']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_2']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid_2']['ui_name'] = 'President';
  $handler->display->display_options['filters']['uuid_2']['value'] = 'fea4c060-eb2d-4686-9ccc-64997aad4930';
  $handler->display->display_options['filters']['uuid_2']['group'] = 2;
  /* Filter criterion: Vice President */
  $handler->display->display_options['filters']['uuid']['id'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid']['ui_name'] = 'Vice President';
  $handler->display->display_options['filters']['uuid']['value'] = 'f7f7834a-3d60-4525-804b-439fd2d9f97a';
  $handler->display->display_options['filters']['uuid']['group'] = 2;
  /* Filter criterion: Commissioner */
  $handler->display->display_options['filters']['uuid_1']['id'] = 'uuid_1';
  $handler->display->display_options['filters']['uuid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_1']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_1']['relationship'] = 'field_biography_role_tid_i18n';
  $handler->display->display_options['filters']['uuid_1']['ui_name'] = 'Commissioner';
  $handler->display->display_options['filters']['uuid_1']['value'] = 'ffbcfcf3-2f50-4c70-a11c-936cc4385cde';
  $handler->display->display_options['filters']['uuid_1']['group'] = 2;
  $handler->display->display_options['path'] = 'blog/tag/%';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['row_options']['item_length'] = 'rss';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<div class="result-count"><p>@total posts</p></div>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = 'Published by <span class="listing-item-author">[title_1]</span> <span class="separator">|</span> [created]';
  $handler->display->display_options['fields']['created']['element_class'] = 'listing-item-metadata';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'ec_date';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_com_blog_image']['id'] = 'field_com_blog_image';
  $handler->display->display_options['fields']['field_com_blog_image']['table'] = 'field_data_field_com_blog_image';
  $handler->display->display_options['fields']['field_com_blog_image']['field'] = 'field_com_blog_image';
  $handler->display->display_options['fields']['field_com_blog_image']['label'] = '';
  $handler->display->display_options['fields']['field_com_blog_image']['element_class'] = 'listing-item-image';
  $handler->display->display_options['fields']['field_com_blog_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_com_blog_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_com_blog_image']['type'] = 'picture';
  $handler->display->display_options['fields']['field_com_blog_image']['settings'] = array(
    'picture_mapping' => 'lists_pages',
    'fallback_image_style' => 'listings_307x205',
    'image_link' => 'content',
    'colorbox' => 'team_members_picture',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Teaser */
  $handler->display->display_options['fields']['field_shared_teaser']['id'] = 'field_shared_teaser';
  $handler->display->display_options['fields']['field_shared_teaser']['table'] = 'field_data_field_shared_teaser';
  $handler->display->display_options['fields']['field_shared_teaser']['field'] = 'field_shared_teaser';
  $handler->display->display_options['fields']['field_shared_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_shared_teaser']['alter']['max_length'] = '250';
  $handler->display->display_options['fields']['field_shared_teaser']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_shared_teaser']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_shared_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_shared_teaser']['element_wrapper_class'] = 'listing-item-teaser';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['text'] = '[path]#comments';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['comment_count']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['element_type'] = '0';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['comment_count']['element_wrapper_class'] = 'listing-item-comment-count';
  $handler->display->display_options['fields']['comment_count']['suffix'] = ' comments';
  /* Field: Content: Tagline */
  $handler->display->display_options['fields']['field_biography_tagline']['id'] = 'field_biography_tagline';
  $handler->display->display_options['fields']['field_biography_tagline']['table'] = 'field_data_field_biography_tagline';
  $handler->display->display_options['fields']['field_biography_tagline']['field'] = 'field_biography_tagline';
  $handler->display->display_options['fields']['field_biography_tagline']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['fields']['field_biography_tagline']['label'] = '';
  $handler->display->display_options['fields']['field_biography_tagline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_tagline']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_biography_role']['id'] = 'field_biography_role';
  $handler->display->display_options['fields']['field_biography_role']['table'] = 'field_data_field_biography_role';
  $handler->display->display_options['fields']['field_biography_role']['field'] = 'field_biography_role';
  $handler->display->display_options['fields']['field_biography_role']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['fields']['field_biography_role']['label'] = '';
  $handler->display->display_options['fields']['field_biography_role']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_role']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['path'] = 'blog/%/feed';
  $handler->display->display_options['sitename_title'] = 0;
  $export['blog_commisioner'] = $view;

  $view = new view();
  $view->name = 'blog_commisioner_bio';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Blog Commisioner Bio';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Blog';
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
  $handler->display->display_options['style_options']['listing_columns'] = 'default';
  $handler->display->display_options['style_options']['listing_modifier'] = '';
  $handler->display->display_options['style_options']['listing_wrapper_modifier'] = '';
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'meta';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|created';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'meta';
  /* Footer: More link */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['ui_name'] = 'More link';
  $handler->display->display_options['footer']['area']['content'] = 'all blog posts';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  /* Relationship: Content: Editorial section (field_editorial_section) */
  $handler->display->display_options['relationships']['field_editorial_section_tid']['id'] = 'field_editorial_section_tid';
  $handler->display->display_options['relationships']['field_editorial_section_tid']['table'] = 'field_data_field_editorial_section';
  $handler->display->display_options['relationships']['field_editorial_section_tid']['field'] = 'field_editorial_section_tid';
  /* Relationship: Taxonomy term: Content using Editorial section */
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['id'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['field'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['relationship'] = 'field_editorial_section_tid';
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['required'] = TRUE;
  /* Relationship: Content: Title (field_biography_role) */
  $handler->display->display_options['relationships']['field_biography_role_tid']['id'] = 'field_biography_role_tid';
  $handler->display->display_options['relationships']['field_biography_role_tid']['table'] = 'field_data_field_biography_role';
  $handler->display->display_options['relationships']['field_biography_role_tid']['field'] = 'field_biography_role_tid';
  $handler->display->display_options['relationships']['field_biography_role_tid']['relationship'] = 'reverse_field_editorial_section_node';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_com_blog_image']['id'] = 'field_com_blog_image';
  $handler->display->display_options['fields']['field_com_blog_image']['table'] = 'field_data_field_com_blog_image';
  $handler->display->display_options['fields']['field_com_blog_image']['field'] = 'field_com_blog_image';
  $handler->display->display_options['fields']['field_com_blog_image']['label'] = '';
  $handler->display->display_options['fields']['field_com_blog_image']['element_class'] = 'listing-item-image';
  $handler->display->display_options['fields']['field_com_blog_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_com_blog_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_com_blog_image']['type'] = 'picture';
  $handler->display->display_options['fields']['field_com_blog_image']['settings'] = array(
    'picture_mapping' => 'lists',
    'fallback_image_style' => 'listings',
    'image_link' => 'content',
    'colorbox' => 'team_members_picture',
  );
  /* Field: Content: Editorial section */
  $handler->display->display_options['fields']['field_editorial_section']['id'] = 'field_editorial_section';
  $handler->display->display_options['fields']['field_editorial_section']['table'] = 'field_data_field_editorial_section';
  $handler->display->display_options['fields']['field_editorial_section']['field'] = 'field_editorial_section';
  $handler->display->display_options['fields']['field_editorial_section']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['fields']['field_editorial_section']['label'] = '';
  $handler->display->display_options['fields']['field_editorial_section']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_editorial_section']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_editorial_section']['alter']['text'] = 'all blog posts';
  $handler->display->display_options['fields']['field_editorial_section']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_editorial_section']['alter']['path'] = 'blog/[field_editorial_section]';
  $handler->display->display_options['fields']['field_editorial_section']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_editorial_section']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['field_editorial_section']['alter']['alt'] = 'all blog posts from %1';
  $handler->display->display_options['fields']['field_editorial_section']['alter']['link_class'] = 'link';
  $handler->display->display_options['fields']['field_editorial_section']['alter']['prefix'] = '<div class="more-link">';
  $handler->display->display_options['fields']['field_editorial_section']['alter']['suffix'] = '</div>';
  $handler->display->display_options['fields']['field_editorial_section']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_editorial_section']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_class'] = 'listing-item-metadata';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'ec_date';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path_case'] = 'lower';
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
    'commisioner_blog_post' => 'commisioner_blog_post',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: High Representative */
  $handler->display->display_options['filters']['uuid_4']['id'] = 'uuid_4';
  $handler->display->display_options['filters']['uuid_4']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_4']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_4']['relationship'] = 'field_biography_role_tid';
  $handler->display->display_options['filters']['uuid_4']['ui_name'] = 'High Representative';
  $handler->display->display_options['filters']['uuid_4']['value'] = 'd6304632-edda-4f20-871a-0e49513adfa5';
  $handler->display->display_options['filters']['uuid_4']['group'] = 2;
  /* Filter criterion: First Vice-President */
  $handler->display->display_options['filters']['uuid_5']['id'] = 'uuid_5';
  $handler->display->display_options['filters']['uuid_5']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_5']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_5']['relationship'] = 'field_biography_role_tid';
  $handler->display->display_options['filters']['uuid_5']['ui_name'] = 'First Vice-President';
  $handler->display->display_options['filters']['uuid_5']['value'] = 'e0028e61-1cfa-4f6e-a036-4665b12ce86a';
  $handler->display->display_options['filters']['uuid_5']['group'] = 2;
  /* Filter criterion: President */
  $handler->display->display_options['filters']['uuid_3']['id'] = 'uuid_3';
  $handler->display->display_options['filters']['uuid_3']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_3']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_3']['relationship'] = 'field_biography_role_tid';
  $handler->display->display_options['filters']['uuid_3']['ui_name'] = 'President';
  $handler->display->display_options['filters']['uuid_3']['value'] = 'fea4c060-eb2d-4686-9ccc-64997aad4930';
  $handler->display->display_options['filters']['uuid_3']['group'] = 2;
  /* Filter criterion: Vice President */
  $handler->display->display_options['filters']['uuid_2']['id'] = 'uuid_2';
  $handler->display->display_options['filters']['uuid_2']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_2']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_2']['relationship'] = 'field_biography_role_tid';
  $handler->display->display_options['filters']['uuid_2']['ui_name'] = 'Vice President';
  $handler->display->display_options['filters']['uuid_2']['value'] = 'f7f7834a-3d60-4525-804b-439fd2d9f97a';
  $handler->display->display_options['filters']['uuid_2']['group'] = 2;
  /* Filter criterion: Commissioner */
  $handler->display->display_options['filters']['uuid_1']['id'] = 'uuid_1';
  $handler->display->display_options['filters']['uuid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_1']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_1']['relationship'] = 'field_biography_role_tid';
  $handler->display->display_options['filters']['uuid_1']['ui_name'] = 'Commissioner';
  $handler->display->display_options['filters']['uuid_1']['value'] = 'ffbcfcf3-2f50-4c70-a11c-936cc4385cde';
  $handler->display->display_options['filters']['uuid_1']['group'] = 2;
  /* Filter criterion: Taxonomy term: Taxonomy term UUID */
  $handler->display->display_options['filters']['uuid']['id'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['relationship'] = 'field_biography_role_tid';
  $handler->display->display_options['filters']['uuid']['value'] = 'cbfbd9f8-72ae-4635-aa77-888075de774b';
  $handler->display->display_options['filters']['uuid']['group'] = 2;
  $handler->display->display_options['filters']['uuid']['expose']['operator_id'] = 'uuid_op';
  $handler->display->display_options['filters']['uuid']['expose']['label'] = 'Taxonomy term UUID';
  $handler->display->display_options['filters']['uuid']['expose']['operator'] = 'uuid_op';
  $handler->display->display_options['filters']['uuid']['expose']['identifier'] = 'uuid';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $export['blog_commisioner_bio'] = $view;

  $view = new view();
  $view->name = 'blog_commisioner_tags';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Blog Commisioner Tags';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'tags-list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_shared_tags']['id'] = 'field_shared_tags';
  $handler->display->display_options['fields']['field_shared_tags']['table'] = 'field_data_field_shared_tags';
  $handler->display->display_options['fields']['field_shared_tags']['field'] = 'field_shared_tags';
  $handler->display->display_options['fields']['field_shared_tags']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_shared_tags']['alter']['path'] = 'blog/tag/[field_shared_tags]';
  $handler->display->display_options['fields']['field_shared_tags']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_shared_tags']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['field_shared_tags']['element_class'] = 'tags-list-items';
  $handler->display->display_options['fields']['field_shared_tags']['element_label_class'] = 'tags-list-label';
  $handler->display->display_options['fields']['field_shared_tags']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_shared_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_shared_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_shared_tags']['multi_type'] = 'ul';
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

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['blog_commisioner_tags'] = $view;

  $view = new view();
  $view->name = 'blog_header';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Blog header';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Blog header';
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
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<h1 class="page-header">[title]</h1>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = TRUE;
  /* Relationship: Content: Editorial section (field_editorial_section) */
  $handler->display->display_options['relationships']['field_editorial_section_tid']['id'] = 'field_editorial_section_tid';
  $handler->display->display_options['relationships']['field_editorial_section_tid']['table'] = 'field_data_field_editorial_section';
  $handler->display->display_options['relationships']['field_editorial_section_tid']['field'] = 'field_editorial_section_tid';
  /* Relationship: Taxonomy term: Content using Editorial section */
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['id'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['field'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['relationships']['reverse_field_editorial_section_node']['relationship'] = 'field_editorial_section_tid';
  /* Relationship: Content: Title (field_biography_role) */
  $handler->display->display_options['relationships']['field_biography_role_tid']['id'] = 'field_biography_role_tid';
  $handler->display->display_options['relationships']['field_biography_role_tid']['table'] = 'field_data_field_biography_role';
  $handler->display->display_options['relationships']['field_biography_role_tid']['field'] = 'field_biography_role_tid';
  $handler->display->display_options['relationships']['field_biography_role_tid']['relationship'] = 'reverse_field_editorial_section_node';
  /* Field: Content: First name */
  $handler->display->display_options['fields']['field_biography_first_name']['id'] = 'field_biography_first_name';
  $handler->display->display_options['fields']['field_biography_first_name']['table'] = 'field_data_field_biography_first_name';
  $handler->display->display_options['fields']['field_biography_first_name']['field'] = 'field_biography_first_name';
  $handler->display->display_options['fields']['field_biography_first_name']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['fields']['field_biography_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_biography_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: Last name */
  $handler->display->display_options['fields']['field_biography_last_name']['id'] = 'field_biography_last_name';
  $handler->display->display_options['fields']['field_biography_last_name']['table'] = 'field_data_field_biography_last_name';
  $handler->display->display_options['fields']['field_biography_last_name']['field'] = 'field_biography_last_name';
  $handler->display->display_options['fields']['field_biography_last_name']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['fields']['field_biography_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_biography_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_biography_last_name']['alter']['text'] = '<span class="capitalize">by <span class="first-name">[field_biography_first_name]</span> <span class="last-name">[field_biography_last_name]</span></span>';
  $handler->display->display_options['fields']['field_biography_last_name']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = '<span class="capitalize">[created]</span>';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'ec_date';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Blog post';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="page-header-wrapper">
<span class="header-line-1">[nothing_1] - [field_biography_last_name] - [created]</span>
<h1 class="page-header">
<span class="header-line-2">[title]</span>
</h1>
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
    'commisioner_blog_post' => 'commisioner_blog_post',
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
    'commisioner_blog_post' => 'commisioner_blog_post',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'reverse_field_editorial_section_node';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    '***DEFAULT_LANGUAGE***' => '***DEFAULT_LANGUAGE***',
    'und' => 'und',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  /* Filter criterion: High Representative */
  $handler->display->display_options['filters']['uuid_4']['id'] = 'uuid_4';
  $handler->display->display_options['filters']['uuid_4']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_4']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_4']['relationship'] = 'field_biography_role_tid';
  $handler->display->display_options['filters']['uuid_4']['ui_name'] = 'High Representative';
  $handler->display->display_options['filters']['uuid_4']['value'] = 'd6304632-edda-4f20-871a-0e49513adfa5';
  $handler->display->display_options['filters']['uuid_4']['group'] = 2;
  /* Filter criterion: First Vice-President */
  $handler->display->display_options['filters']['uuid_5']['id'] = 'uuid_5';
  $handler->display->display_options['filters']['uuid_5']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_5']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_5']['relationship'] = 'field_biography_role_tid';
  $handler->display->display_options['filters']['uuid_5']['ui_name'] = 'First Vice-President';
  $handler->display->display_options['filters']['uuid_5']['value'] = 'e0028e61-1cfa-4f6e-a036-4665b12ce86a';
  $handler->display->display_options['filters']['uuid_5']['group'] = 2;
  /* Filter criterion: President */
  $handler->display->display_options['filters']['uuid']['id'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['relationship'] = 'field_biography_role_tid';
  $handler->display->display_options['filters']['uuid']['ui_name'] = 'President';
  $handler->display->display_options['filters']['uuid']['value'] = 'fea4c060-eb2d-4686-9ccc-64997aad4930';
  $handler->display->display_options['filters']['uuid']['group'] = 2;
  $handler->display->display_options['filters']['uuid']['expose']['operator_id'] = 'uuid_op';
  $handler->display->display_options['filters']['uuid']['expose']['label'] = 'Taxonomy term UUID';
  $handler->display->display_options['filters']['uuid']['expose']['operator'] = 'uuid_op';
  $handler->display->display_options['filters']['uuid']['expose']['identifier'] = 'uuid';
  /* Filter criterion: Vice President */
  $handler->display->display_options['filters']['uuid_1']['id'] = 'uuid_1';
  $handler->display->display_options['filters']['uuid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_1']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_1']['relationship'] = 'field_biography_role_tid';
  $handler->display->display_options['filters']['uuid_1']['ui_name'] = 'Vice President';
  $handler->display->display_options['filters']['uuid_1']['value'] = 'f7f7834a-3d60-4525-804b-439fd2d9f97a';
  $handler->display->display_options['filters']['uuid_1']['group'] = 2;
  /* Filter criterion: Commissioner */
  $handler->display->display_options['filters']['uuid_2']['id'] = 'uuid_2';
  $handler->display->display_options['filters']['uuid_2']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_2']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_2']['relationship'] = 'field_biography_role_tid';
  $handler->display->display_options['filters']['uuid_2']['ui_name'] = 'Commissioner';
  $handler->display->display_options['filters']['uuid_2']['value'] = 'ffbcfcf3-2f50-4c70-a11c-936cc4385cde';
  $handler->display->display_options['filters']['uuid_2']['group'] = 2;
  /* Filter criterion: Taxonomy term: Taxonomy term UUID */
  $handler->display->display_options['filters']['uuid_3']['id'] = 'uuid_3';
  $handler->display->display_options['filters']['uuid_3']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['uuid_3']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid_3']['relationship'] = 'field_biography_role_tid';
  $handler->display->display_options['filters']['uuid_3']['value'] = 'cbfbd9f8-72ae-4635-aa77-888075de774b';
  $handler->display->display_options['filters']['uuid_3']['group'] = 2;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'header');
  $export['blog_header'] = $view;

  return $export;
}
