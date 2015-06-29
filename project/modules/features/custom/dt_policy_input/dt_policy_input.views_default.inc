<?php
/**
 * @file
 * dt_policy_input.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dt_policy_input_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'policy_blocks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Policy blocks';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_policy_input_node']['id'] = 'reverse_field_policy_input_node';
  $handler->display->display_options['relationships']['reverse_field_policy_input_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_policy_input_node']['field'] = 'reverse_field_policy_input_node';
  $handler->display->display_options['relationships']['reverse_field_policy_input_node']['required'] = TRUE;
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
  /* Field: Content: Input type */
  $handler->display->display_options['fields']['field_policy_input_type']['id'] = 'field_policy_input_type';
  $handler->display->display_options['fields']['field_policy_input_type']['table'] = 'field_data_field_policy_input_type';
  $handler->display->display_options['fields']['field_policy_input_type']['field'] = 'field_policy_input_type';
  $handler->display->display_options['fields']['field_policy_input_type']['label'] = '';
  $handler->display->display_options['fields']['field_policy_input_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_policy_input_type']['element_label_colon'] = FALSE;
  /* Field: Content: Introduction */
  $handler->display->display_options['fields']['field_policy_input_introduction']['id'] = 'field_policy_input_introduction';
  $handler->display->display_options['fields']['field_policy_input_introduction']['table'] = 'field_data_field_policy_input_introduction';
  $handler->display->display_options['fields']['field_policy_input_introduction']['field'] = 'field_policy_input_introduction';
  $handler->display->display_options['fields']['field_policy_input_introduction']['label'] = '';
  $handler->display->display_options['fields']['field_policy_input_introduction']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_policy_input_introduction']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_policy_input_introduction']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['field_policy_input_introduction']['settings'] = array(
    'trim_length' => '300',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'trim_options' => array(
      'text' => 0,
    ),
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="[path]" class="listing__item-link" title="[title]">
  <div class="listing__column-main column-main">
   <div class="meta"><span class="meta__item meta__item--type">[field_policy_input_type]</span></div>
    <h3 class="listing__title">[title]</h3>
    <p>[field_policy_input_introduction]</p>
  </div>
</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_policy_input_node';
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
    'policy_input' => 'policy_input',
  );
  /* Filter criterion: Content: Input type (field_policy_input_type) */
  $handler->display->display_options['filters']['field_policy_input_type_value']['id'] = 'field_policy_input_type_value';
  $handler->display->display_options['filters']['field_policy_input_type_value']['table'] = 'field_data_field_policy_input_type';
  $handler->display->display_options['filters']['field_policy_input_type_value']['field'] = 'field_policy_input_type_value';
  $handler->display->display_options['filters']['field_policy_input_type_value']['value'] = array(
    'consultation' => 'consultation',
  );

  /* Display: Policy input (consultation) */
  $handler = $view->new_display('block', 'Policy input (consultation)', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: Content: Input type */
  $handler->display->display_options['fields']['field_policy_input_type']['id'] = 'field_policy_input_type';
  $handler->display->display_options['fields']['field_policy_input_type']['table'] = 'field_data_field_policy_input_type';
  $handler->display->display_options['fields']['field_policy_input_type']['field'] = 'field_policy_input_type';
  $handler->display->display_options['fields']['field_policy_input_type']['label'] = '';
  $handler->display->display_options['fields']['field_policy_input_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_policy_input_type']['element_label_colon'] = FALSE;
  /* Field: Content: Introduction */
  $handler->display->display_options['fields']['field_core_introduction']['id'] = 'field_core_introduction';
  $handler->display->display_options['fields']['field_core_introduction']['table'] = 'field_data_field_core_introduction';
  $handler->display->display_options['fields']['field_core_introduction']['field'] = 'field_core_introduction';
  $handler->display->display_options['fields']['field_core_introduction']['label'] = '';
  $handler->display->display_options['fields']['field_core_introduction']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_core_introduction']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_core_introduction']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['field_core_introduction']['settings'] = array(
    'trim_length' => '300',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'trim_options' => array(
      'text' => 0,
    ),
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="[path]" class="listing__item-link" title="[title]">
  <div class="listing__column-main column-main">
   <div class="meta"><span class="meta__item meta__item--type">[field_policy_input_type]</span></div>
    <h3 class="listing__title">[title]</h3>
    <p>[field_core_introduction]</p>
  </div>
</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;

  /* Display: Policy input (except consultation) */
  $handler = $view->new_display('block', 'Policy input (except consultation)', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Policy input';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: Content: Input type */
  $handler->display->display_options['fields']['field_policy_input_type']['id'] = 'field_policy_input_type';
  $handler->display->display_options['fields']['field_policy_input_type']['table'] = 'field_data_field_policy_input_type';
  $handler->display->display_options['fields']['field_policy_input_type']['field'] = 'field_policy_input_type';
  $handler->display->display_options['fields']['field_policy_input_type']['label'] = '';
  $handler->display->display_options['fields']['field_policy_input_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_policy_input_type']['element_label_colon'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_policy_input_status']['id'] = 'field_policy_input_status';
  $handler->display->display_options['fields']['field_policy_input_status']['table'] = 'field_data_field_policy_input_status';
  $handler->display->display_options['fields']['field_policy_input_status']['field'] = 'field_policy_input_status';
  $handler->display->display_options['fields']['field_policy_input_status']['label'] = '';
  $handler->display->display_options['fields']['field_policy_input_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_policy_input_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_policy_input_status']['type'] = 'i18n_list_default';
  /* Field: Content: Introduction */
  $handler->display->display_options['fields']['field_core_introduction']['id'] = 'field_core_introduction';
  $handler->display->display_options['fields']['field_core_introduction']['table'] = 'field_data_field_core_introduction';
  $handler->display->display_options['fields']['field_core_introduction']['field'] = 'field_core_introduction';
  $handler->display->display_options['fields']['field_core_introduction']['label'] = '';
  $handler->display->display_options['fields']['field_core_introduction']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_core_introduction']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_core_introduction']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['field_core_introduction']['settings'] = array(
    'trim_length' => '300',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'trim_options' => array(
      'text' => 0,
    ),
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="[path]" class="listing__item-link" title="[title]">
  <div class="listing__column-main column-main">
   <div class="meta">
      <span class="meta__item meta__item--type">[field_policy_input_type]</span>
      <span class="meta__item listing__meta-item">[field_policy_input_status]</span>
    </div>
    <h3 class="listing__title">[title]</h3>
    <p>[field_core_introduction]</p>
  </div>
</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
    'policy_input' => 'policy_input',
  );
  /* Filter criterion: Content: Input type (field_policy_input_type) */
  $handler->display->display_options['filters']['field_policy_input_type_value']['id'] = 'field_policy_input_type_value';
  $handler->display->display_options['filters']['field_policy_input_type_value']['table'] = 'field_data_field_policy_input_type';
  $handler->display->display_options['filters']['field_policy_input_type_value']['field'] = 'field_policy_input_type_value';
  $handler->display->display_options['filters']['field_policy_input_type_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_policy_input_type_value']['value'] = array(
    'consultation' => 'consultation',
  );
  $export['policy_blocks'] = $view;

  return $export;
}
