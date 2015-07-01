<?php
/**
 * @file
 * dt_site_menu.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_site_menu_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_site_menu_first_row|bean|site_menu|default';
  $field_group->group_name = 'group_site_menu_first_row';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'site_menu';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'First row',
    'weight' => '1',
    'children' => array(
      0 => 'field_site_menu_first',
      1 => 'field_site_menu_second',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'First row',
      'instance_settings' => array(
        'classes' => 'section__group section__group--highlight-yellow section__group--full-width',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_site_menu_first_row|bean|site_menu|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_site_menu_second_row|bean|site_menu|default';
  $field_group->group_name = 'group_site_menu_second_row';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'site_menu';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Second row',
    'weight' => '2',
    'children' => array(
      0 => 'field_site_menu_third',
      1 => 'field_site_menu_fourth',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Second row',
      'instance_settings' => array(
        'classes' => 'section__group section__group--highlight-yellow section__group--full-width',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_site_menu_second_row|bean|site_menu|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_site_menu_third_row|bean|site_menu|default';
  $field_group->group_name = 'group_site_menu_third_row';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'site_menu';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Third row',
    'weight' => '3',
    'children' => array(
      0 => 'field_site_menu_fifth',
      1 => 'field_site_menu_sixth',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Third row',
      'instance_settings' => array(
        'classes' => 'section__group section__group--highlight-yellow section__group--full-width',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_site_menu_third_row|bean|site_menu|default'] = $field_group;

  return $export;
}
