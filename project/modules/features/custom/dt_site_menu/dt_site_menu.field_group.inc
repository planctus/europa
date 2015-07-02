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
  $field_group->identifier = 'group_site_menu_first_left|bean|site_menu|default';
  $field_group->group_name = 'group_site_menu_first_left';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'site_menu';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_site_menu_first_row';
  $field_group->data = array(
    'label' => 'Left',
    'weight' => '4',
    'children' => array(
      0 => 'field_site_menu_first',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'col-md-6',
        'attributes' => '',
        'required_fields' => 0,
      ),
    ),
  );
  $export['group_site_menu_first_left|bean|site_menu|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_site_menu_first_right|bean|site_menu|default';
  $field_group->group_name = 'group_site_menu_first_right';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'site_menu';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_site_menu_first_row';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '5',
    'children' => array(
      0 => 'field_site_menu_second',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'col-md-6',
        'attributes' => '',
        'required_fields' => 0,
      ),
    ),
  );
  $export['group_site_menu_first_right|bean|site_menu|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_site_menu_first_row|bean|site_menu|default';
  $field_group->group_name = 'group_site_menu_first_row';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'site_menu';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_site_menu';
  $field_group->data = array(
    'label' => 'First row',
    'weight' => '2',
    'children' => array(
      0 => 'group_site_menu_first_left',
      1 => 'group_site_menu_first_right',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'First row',
      'instance_settings' => array(
        'classes' => 'site-menu__row',
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
  $field_group->identifier = 'group_site_menu_second_left|bean|site_menu|default';
  $field_group->group_name = 'group_site_menu_second_left';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'site_menu';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_site_menu_second_row';
  $field_group->data = array(
    'label' => 'Left',
    'weight' => '8',
    'children' => array(
      0 => 'field_site_menu_third',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'col-md-6',
        'attributes' => '',
        'required_fields' => 0,
      ),
    ),
  );
  $export['group_site_menu_second_left|bean|site_menu|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_site_menu_second_right|bean|site_menu|default';
  $field_group->group_name = 'group_site_menu_second_right';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'site_menu';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_site_menu_second_row';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '10',
    'children' => array(
      0 => 'field_site_menu_fourth',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'col-md-6',
        'attributes' => '',
        'required_fields' => 0,
      ),
    ),
  );
  $export['group_site_menu_second_right|bean|site_menu|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_site_menu_second_row|bean|site_menu|default';
  $field_group->group_name = 'group_site_menu_second_row';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'site_menu';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_site_menu';
  $field_group->data = array(
    'label' => 'Second row',
    'weight' => '4',
    'children' => array(
      0 => 'group_site_menu_second_left',
      1 => 'group_site_menu_second_right',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Second row',
      'instance_settings' => array(
        'classes' => 'site-menu__row',
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
  $field_group->identifier = 'group_site_menu_third_left|bean|site_menu|default';
  $field_group->group_name = 'group_site_menu_third_left';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'site_menu';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_site_menu_third_row';
  $field_group->data = array(
    'label' => 'Left',
    'weight' => '8',
    'children' => array(
      0 => 'field_site_menu_fifth',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'col-md-6',
        'attributes' => '',
        'required_fields' => 0,
      ),
    ),
  );
  $export['group_site_menu_third_left|bean|site_menu|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_site_menu_third_right|bean|site_menu|default';
  $field_group->group_name = 'group_site_menu_third_right';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'site_menu';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_site_menu_third_row';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '9',
    'children' => array(
      0 => 'field_site_menu_sixth',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'col-md-6',
        'attributes' => '',
        'required_fields' => 0,
      ),
    ),
  );
  $export['group_site_menu_third_right|bean|site_menu|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_site_menu_third_row|bean|site_menu|default';
  $field_group->group_name = 'group_site_menu_third_row';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'site_menu';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_site_menu';
  $field_group->data = array(
    'label' => 'Third row',
    'weight' => '5',
    'children' => array(
      0 => 'group_site_menu_third_left',
      1 => 'group_site_menu_third_right',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Third row',
      'instance_settings' => array(
        'classes' => 'site-menu__row',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_site_menu_third_row|bean|site_menu|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_site_menu|bean|site_menu|default';
  $field_group->group_name = 'group_site_menu';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'site_menu';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Menu',
    'weight' => '1',
    'children' => array(
      0 => 'group_site_menu_first_row',
      1 => 'group_site_menu_second_row',
      2 => 'group_site_menu_third_row',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Menu',
      'instance_settings' => array(
        'classes' => 'section__group section__group--highlight-yellow section__group--full-width listing--site-menu site-menu',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_site_menu|bean|site_menu|default'] = $field_group;

  return $export;
}
