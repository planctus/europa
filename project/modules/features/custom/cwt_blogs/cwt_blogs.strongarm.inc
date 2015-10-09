<?php
/**
 * @file
 * cwt_blogs.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cwt_blogs_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_commisioner_blog_post';
  $strongarm->value = '0';
  $export['comment_anonymous_commisioner_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_commisioner_blog_post';
  $strongarm->value = '2';
  $export['comment_commisioner_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_commisioner_blog_post';
  $strongarm->value = 0;
  $export['comment_default_mode_commisioner_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_commisioner_blog_post';
  $strongarm->value = '50';
  $export['comment_default_per_page_commisioner_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_commisioner_blog_post';
  $strongarm->value = 1;
  $export['comment_form_location_commisioner_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_commisioner_blog_post';
  $strongarm->value = '1';
  $export['comment_preview_commisioner_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_commisioner_blog_post';
  $strongarm->value = 1;
  $export['comment_subject_field_commisioner_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'data_table';
  $strongarm->value = array(
    'facebook' => array(
      'weight' => '-10',
      'enabled' => 1,
    ),
    'googleplus' => array(
      'weight' => '-7',
      'enabled' => 0,
    ),
    'twitter' => array(
      'weight' => '-9',
      'enabled' => 1,
    ),
    'linkedin' => array(
      'weight' => '-6',
      'enabled' => 0,
    ),
    'pocket' => array(
      'weight' => '-5',
      'enabled' => 0,
    ),
    'yammer' => array(
      'weight' => '-4',
      'enabled' => 0,
    ),
    'pinterest' => array(
      'weight' => '-3',
      'enabled' => 0,
    ),
    'email_link' => array(
      'weight' => '-8',
      'enabled' => 0,
    ),
    'favorites' => array(
      'weight' => '-2',
      'enabled' => 0,
    ),
    'wordpress' => array(
      'weight' => '-1',
      'enabled' => 0,
    ),
    'more' => array(
      'weight' => '0',
      'enabled' => 0,
    ),
  );
  $export['data_table'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__commisioner_blog_post';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => TRUE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'meta' => array(
        'custom_settings' => TRUE,
      ),
      'title' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '2',
        ),
        'language' => array(
          'weight' => '6',
        ),
      ),
      'display' => array(
        'language' => array(
          'default' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '16',
            'visible' => FALSE,
          ),
          'rss' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '17',
            'visible' => FALSE,
          ),
          'meta' => array(
            'weight' => '16',
            'visible' => FALSE,
          ),
        ),
        'subscriptions_ui' => array(
          'default' => array(
            'weight' => '100',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '6',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '13',
            'visible' => FALSE,
          ),
          'meta' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__commisioner_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'icon_size_socialbar';
  $strongarm->value = '32';
  $export['icon_size_socialbar'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'icon_size_socialbookmark';
  $strongarm->value = '16';
  $export['icon_size_socialbookmark'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'label_socialbookmark';
  $strongarm->value = '';
  $export['label_socialbookmark'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_commisioner_blog_post';
  $strongarm->value = '2';
  $export['language_content_type_commisioner_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_selector_socialbar';
  $strongarm->value = 'en';
  $export['language_selector_socialbar'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_selector_socialbookmark';
  $strongarm->value = 'en';
  $export['language_selector_socialbookmark'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_socialbar';
  $strongarm->value = 'From META DATA';
  $export['language_socialbar'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_socialbookmark';
  $strongarm->value = 'From META DATA';
  $export['language_socialbookmark'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'least_socialbookmark';
  $strongarm->value = '';
  $export['least_socialbookmark'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_commisioner_blog_post';
  $strongarm->value = array();
  $export['menu_options_commisioner_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_commisioner_blog_post';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_commisioner_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_commisioner_blog_post';
  $strongarm->value = array(
    0 => 'revision',
  );
  $export['node_options_commisioner_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_commisioner_blog_post';
  $strongarm->value = '1';
  $export['node_preview_commisioner_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_commisioner_blog_post';
  $strongarm->value = 0;
  $export['node_submitted_commisioner_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_commisioner_blog_post_en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_commisioner_blog_post_en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_commisioner_blog_post_pattern';
  $strongarm->value = 'blog/[node:field_editorial_section]/[node:title]';
  $export['pathauto_node_commisioner_blog_post_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_commisioner_blog_post_und_pattern';
  $strongarm->value = '';
  $export['pathauto_node_commisioner_blog_post_und_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'statistics_socialbar';
  $strongarm->value = 1;
  $export['statistics_socialbar'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'statistics_socialbookmark';
  $strongarm->value = 1;
  $export['statistics_socialbookmark'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'text_socialbar';
  $strongarm->value = 'None';
  $export['text_socialbar'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'type_socialbar';
  $strongarm->value = 'Horizontal';
  $export['type_socialbar'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'type_socialbookmark';
  $strongarm->value = 'Icon';
  $export['type_socialbookmark'] = $strongarm;

  return $export;
}
