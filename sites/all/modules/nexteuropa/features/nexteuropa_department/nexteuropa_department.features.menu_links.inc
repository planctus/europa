<?php
/**
 * @file
 * nexteuropa_department.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function nexteuropa_department_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_department:node/add/department
  $menu_links['navigation_department:node/add/department'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/department',
    'router_path' => 'node/add/department',
    'link_title' => 'Department',
    'options' => array(
      'identifier' => 'navigation_department:node/add/department',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Department');


  return $menu_links;
}
