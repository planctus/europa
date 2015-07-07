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
  $field_group->identifier = 'group_menu_section_first|bean|site_menu|default';
  $field_group->group_name = 'group_menu_section_first';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'site_menu';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_site_menu_container';
  $field_group->data = array(
    'label' => 'First section',
    'weight' => '20',
    'children' => array(
      0 => 'group_site_menu_first_row',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'First section',
      'instance_settings' => array(
        'classes' => 'site-menu__section',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_menu_section_first|bean|site_menu|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_menu_section_second|bean|site_menu|default';
  $field_group->group_name = 'group_menu_section_second';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'site_menu';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_site_menu_container';
  $field_group->data = array(
    'label' => 'Second section',
    'weight' => '21',
    'children' => array(
      0 => 'group_site_menu_second_row',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Second section',
      'instance_settings' => array(
        'classes' => 'site-menu__section',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_menu_section_second|bean|site_menu|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_menu_section_third|bean|site_menu|default';
  $field_group->group_name = 'group_menu_section_third';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'site_menu';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_site_menu_container';
  $field_group->data = array(
    'label' => 'Third section',
    'weight' => '22',
    'children' => array(
      0 => 'group_site_menu_third_row',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Third section',
      'instance_settings' => array(
        'classes' => 'site-menu__section',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_menu_section_third|bean|site_menu|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_site_menu_container|bean|site_menu|default';
  $field_group->group_name = 'group_site_menu_container';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'site_menu';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_site_menu';
  $field_group->data = array(
    'label' => 'Menu Container',
    'weight' => '19',
    'children' => array(
      0 => 'group_menu_section_first',
      1 => 'group_menu_section_second',
      2 => 'group_menu_section_third',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Menu Container',
      'instance_settings' => array(
        'classes' => '',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_site_menu_container|bean|site_menu|default'] = $field_group;

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
  $field_group->parent_name = 'group_menu_section_first';
  $field_group->data = array(
    'label' => 'First row',
    'weight' => '14',
    'children' => array(
      0 => 'group_site_menu_first_left',
      1 => 'group_site_menu_first_right',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'First row',
      'instance_settings' => array(
        'classes' => 'row',
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
      1 => 'topics_atoz',
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
  $field_group->parent_name = 'group_menu_section_second';
  $field_group->data = array(
    'label' => 'Second row',
    'weight' => '15',
    'children' => array(
      0 => 'group_site_menu_second_left',
      1 => 'group_site_menu_second_right',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Second row',
      'instance_settings' => array(
        'classes' => 'row',
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
  $field_group->parent_name = 'group_menu_section_third';
  $field_group->data = array(
    'label' => 'Third row',
    'weight' => '16',
    'children' => array(
      0 => 'group_site_menu_third_left',
      1 => 'group_site_menu_third_right',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Third row',
      'instance_settings' => array(
        'classes' => 'row',
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
      0 => 'group_site_menu_container',
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
