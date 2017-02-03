<?php
/**
 * @file
 * dt_test_flexible_date.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dt_test_flexible_date_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'test_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'test view';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'test view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: test flexible date */
  $handler->display->display_options['fields']['field_test_flexible_date']['id'] = 'field_test_flexible_date';
  $handler->display->display_options['fields']['field_test_flexible_date']['table'] = 'field_data_field_test_flexible_date';
  $handler->display->display_options['fields']['field_test_flexible_date']['field'] = 'field_test_flexible_date';
  $handler->display->display_options['fields']['field_test_flexible_date']['click_sort_column'] = 'date';
  $handler->display->display_options['fields']['field_test_flexible_date']['type'] = 'dt_flexible_date_text_only';
  /* Sort criterion: Content: test flexible date */
  $handler->display->display_options['sorts']['field_test_flexible_date']['id'] = 'field_test_flexible_date';
  $handler->display->display_options['sorts']['field_test_flexible_date']['table'] = 'field_data_field_test_flexible_date';
  $handler->display->display_options['sorts']['field_test_flexible_date']['field'] = 'field_test_flexible_date';
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
    'dt_test_content_type' => 'dt_test_content_type',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'test-view';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: test flexible date */
  $handler->display->display_options['sorts']['field_test_flexible_date']['id'] = 'field_test_flexible_date';
  $handler->display->display_options['sorts']['field_test_flexible_date']['table'] = 'field_data_field_test_flexible_date';
  $handler->display->display_options['sorts']['field_test_flexible_date']['field'] = 'field_test_flexible_date';
  $handler->display->display_options['sorts']['field_test_flexible_date']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'test-view-desc';
  $export['test_view'] = $view;

  return $export;
}
