<?php
/**
 * @file
 * dt_site_menu.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_site_menu_field_group_info() {
  $field_groups = array();

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
    'label' => 'Menu section',
    'weight' => '14',
    'children' => array(
      0 => 'field_site_menu_topic_link',
      1 => 'group_site_menu_first_row',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Menu section',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'site-menu__section',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_menu_section_first|bean|site_menu|default'] = $field_group;

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
  $field_groups['group_site_menu_container|bean|site_menu|default'] = $field_group;

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
    'label' => 'Classes',
    'weight' => '16',
    'children' => array(
      0 => 'field_site_menu_classes',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Classes',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'col-md-8',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_site_menu_first_left|bean|site_menu|default'] = $field_group;

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
    'label' => 'Links',
    'weight' => '17',
    'children' => array(
      0 => 'field_site_menu_links',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Links',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'col-md-4',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_site_menu_first_right|bean|site_menu|default'] = $field_group;

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
    'label' => 'Menu row',
    'weight' => '2',
    'children' => array(
      0 => 'group_site_menu_first_left',
      1 => 'group_site_menu_first_right',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Menu row',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'row',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_site_menu_first_row|bean|site_menu|default'] = $field_group;

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
    'weight' => '2',
    'children' => array(
      0 => 'group_site_menu_container',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Menu',
      'instance_settings' => array(
        'classes' => 'section__group section__group--highlight-yellow section__group--full-width site-menu',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_site_menu|bean|site_menu|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Classes');
  t('Links');
  t('Menu');
  t('Menu Container');
  t('Menu row');
  t('Menu section');

  return $field_groups;
}
