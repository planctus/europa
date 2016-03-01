<?php
/**
 * @file
 * dt_site_menu.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function dt_site_menu_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-site_menu-field_site_menu_classes'.
  $field_instances['bean-site_menu-field_site_menu_classes'] = array(
    'bundle' => 'site_menu',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 0,
          'nexteuropa_listing_columns' => 'two_columns',
          'nexteuropa_listing_modifier' => 'listing--dense',
          'nexteuropa_listing_wrapper_modifier' => '',
          'show_translations' => '',
          'use_content_language' => 1,
          'view_mode' => 'title',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 15,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'field_name' => 'field_site_menu_classes',
    'label' => 'Classes',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'bean-site_menu-field_site_menu_links'.
  $field_instances['bean-site_menu-field_site_menu_links'] = array(
    'bundle' => 'site_menu',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'nexteuropa_formatters',
        'settings' => array(
          'nexteuropa_title_item_link_modifier' => '',
          'nexteuropa_title_item_modifier' => '',
          'nexteuropa_title_listing_modifier' => 'listing--no-border listing--dense',
        ),
        'type' => 'link_listing_title',
        'weight' => 14,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'field_name' => 'field_site_menu_links',
    'label' => 'Links',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 0,
      'attributes' => array(
        'class' => 'listing__title',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'bean-site_menu-field_site_menu_topic_link'.
  $field_instances['bean-site_menu-field_site_menu_topic_link'] = array(
    'bundle' => 'site_menu',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 15,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'field_name' => 'field_site_menu_topic_link',
    'label' => 'Topics link',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 0,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Classes');
  t('Links');
  t('Topics link');

  return $field_instances;
}
