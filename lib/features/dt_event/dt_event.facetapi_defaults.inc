<?php
/**
 * @file
 * dt_event.facetapi_defaults.inc
 */

/**
 * Implements hook_facetapi_default_facet_settings().
 */
function dt_event_facetapi_default_facet_settings() {
  $export = array();

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@event_index::field_core_departments';
  $facet->searcher = 'search_api@event_index';
  $facet->realm = '';
  $facet->facet = 'field_core_departments';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        6 => 0,
        4 => 0,
        5 => 0,
        7 => 0,
        9 => 0,
        10 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'announcement' => 0,
        'article' => 0,
        'banner_video' => 0,
        'banner_quote' => 0,
        'page' => 0,
        'consultation' => 0,
        'contact' => 0,
        'coordination' => 0,
        'department' => 0,
        'editorial_team' => 0,
        'event' => 0,
        'featured_item' => 0,
        'file' => 0,
        'funding' => 0,
        'guidance' => 0,
        'impact_assessment' => 0,
        'info_homepage' => 0,
        'law' => 0,
        'new_content_type' => 0,
        'basic_page' => 0,
        'person' => 0,
        'policy' => 0,
        'policy_area' => 0,
        'policy_implementation' => 0,
        'policy_input' => 0,
        'policy_keyfile' => 0,
        'priority' => 0,
        'priority_policy_area' => 0,
        'publication' => 0,
        'class' => 0,
        'class_link_group' => 0,
        'tender' => 0,
        'topic' => 0,
        'toplink' => 0,
        'image' => 0,
        'video' => 0,
        'audio' => 0,
        'document' => 0,
      ),
      'facets' => array(
        'field_core_location:country' => 0,
        'field_event_type' => 0,
        'field_event_is_online' => 0,
        'field_event_is_live_streaming' => 0,
        'field_core_topics' => 0,
      ),
      'reverse_dependency' => 0,
      'force_deactivation' => 0,
      'regex' => 0,
      'facet_items_field_core_location:country' => '',
      'facet_items_field_event_type' => '',
      'facet_items_field_event_is_online' => '',
      'facet_items_field_event_is_live_streaming' => '',
      'facet_items_field_core_topics' => '',
    ),
    'facet_mincount' => '0',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 1,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@event_index::field_core_departments'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@event_index::field_core_location:country';
  $facet->searcher = 'search_api@event_index';
  $facet->realm = '';
  $facet->facet = 'field_core_location:country';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        6 => 0,
        4 => 0,
        5 => 0,
        7 => 0,
        9 => 0,
        10 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'announcement' => 0,
        'article' => 0,
        'banner_video' => 0,
        'banner_quote' => 0,
        'page' => 0,
        'consultation' => 0,
        'contact' => 0,
        'coordination' => 0,
        'department' => 0,
        'editorial_team' => 0,
        'event' => 0,
        'featured_item' => 0,
        'file' => 0,
        'funding' => 0,
        'guidance' => 0,
        'impact_assessment' => 0,
        'info_homepage' => 0,
        'law' => 0,
        'new_content_type' => 0,
        'basic_page' => 0,
        'person' => 0,
        'policy' => 0,
        'policy_area' => 0,
        'policy_implementation' => 0,
        'policy_input' => 0,
        'policy_keyfile' => 0,
        'priority' => 0,
        'priority_policy_area' => 0,
        'publication' => 0,
        'class' => 0,
        'class_link_group' => 0,
        'tender' => 0,
        'topic' => 0,
        'toplink' => 0,
        'image' => 0,
        'video' => 0,
        'audio' => 0,
        'document' => 0,
      ),
      'facets' => array(
        'field_event_type' => 0,
        'field_event_is_online' => 0,
        'field_event_is_live_streaming' => 0,
        'field_core_departments' => 0,
        'field_core_topics' => 0,
      ),
      'reverse_dependency' => 0,
      'force_deactivation' => 0,
      'regex' => 0,
      'facet_items_field_event_type' => '',
      'facet_items_field_event_is_online' => '',
      'facet_items_field_event_is_live_streaming' => '',
      'facet_items_field_core_departments' => '',
      'facet_items_field_core_topics' => '',
    ),
    'facet_mincount' => '0',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 1,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@event_index::field_core_location:country'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@event_index::field_core_topics';
  $facet->searcher = 'search_api@event_index';
  $facet->realm = '';
  $facet->facet = 'field_core_topics';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        6 => 0,
        4 => 0,
        5 => 0,
        7 => 0,
        9 => 0,
        10 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'announcement' => 0,
        'article' => 0,
        'banner_video' => 0,
        'banner_quote' => 0,
        'page' => 0,
        'consultation' => 0,
        'contact' => 0,
        'coordination' => 0,
        'department' => 0,
        'editorial_team' => 0,
        'event' => 0,
        'featured_item' => 0,
        'file' => 0,
        'funding' => 0,
        'guidance' => 0,
        'impact_assessment' => 0,
        'info_homepage' => 0,
        'law' => 0,
        'new_content_type' => 0,
        'basic_page' => 0,
        'person' => 0,
        'policy' => 0,
        'policy_area' => 0,
        'policy_implementation' => 0,
        'policy_input' => 0,
        'policy_keyfile' => 0,
        'priority' => 0,
        'priority_policy_area' => 0,
        'publication' => 0,
        'class' => 0,
        'class_link_group' => 0,
        'tender' => 0,
        'topic' => 0,
        'toplink' => 0,
        'image' => 0,
        'video' => 0,
        'audio' => 0,
        'document' => 0,
      ),
      'facets' => array(
        'field_core_introduction:value' => 0,
        'search_api_language' => 0,
        'field_event_type' => 0,
        'field_core_location:country' => 0,
        'field_event_date:value' => 0,
        'field_event_what_happened:value' => 0,
        'field_event_status_description:value' => 0,
        'field_event_date:value2' => 0,
        'field_event_is_online' => 0,
        'field_event_is_live_streaming' => 0,
      ),
      'reverse_dependency' => 0,
      'force_deactivation' => 0,
      'regex' => 0,
      'facet_items_field_core_introduction:value' => '',
      'facet_items_search_api_language' => '',
      'facet_items_field_event_type' => '',
      'facet_items_field_core_location:country' => '',
      'facet_items_field_event_date:value' => '',
      'facet_items_field_event_what_happened:value' => '',
      'facet_items_field_event_status_description:value' => '',
      'facet_items_field_event_date:value2' => '',
      'facet_items_field_event_is_online' => '',
      'facet_items_field_event_is_live_streaming' => '',
    ),
    'facet_mincount' => '0',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 1,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@event_index::field_core_topics'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@event_index::field_event_is_live_streaming';
  $facet->searcher = 'search_api@event_index';
  $facet->realm = '';
  $facet->facet = 'field_event_is_live_streaming';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        6 => 0,
        4 => 0,
        5 => 0,
        7 => 0,
        9 => 0,
        10 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'announcement' => 0,
        'article' => 0,
        'banner_video' => 0,
        'banner_quote' => 0,
        'page' => 0,
        'consultation' => 0,
        'contact' => 0,
        'coordination' => 0,
        'department' => 0,
        'editorial_team' => 0,
        'event' => 0,
        'featured_item' => 0,
        'file' => 0,
        'funding' => 0,
        'guidance' => 0,
        'impact_assessment' => 0,
        'info_homepage' => 0,
        'law' => 0,
        'new_content_type' => 0,
        'basic_page' => 0,
        'person' => 0,
        'policy' => 0,
        'policy_area' => 0,
        'policy_implementation' => 0,
        'policy_input' => 0,
        'policy_keyfile' => 0,
        'priority' => 0,
        'priority_policy_area' => 0,
        'publication' => 0,
        'class' => 0,
        'class_link_group' => 0,
        'tender' => 0,
        'topic' => 0,
        'toplink' => 0,
        'image' => 0,
        'video' => 0,
        'audio' => 0,
        'document' => 0,
      ),
      'facets' => array(
        'field_core_location:country' => 0,
        'field_event_type' => 0,
        'field_event_is_online' => 0,
        'field_core_departments' => 0,
        'field_core_topics' => 0,
      ),
      'reverse_dependency' => 0,
      'force_deactivation' => 0,
      'regex' => 0,
      'facet_items_field_core_location:country' => '',
      'facet_items_field_event_type' => '',
      'facet_items_field_event_is_online' => '',
      'facet_items_field_core_departments' => '',
      'facet_items_field_core_topics' => '',
    ),
    'facet_mincount' => '0',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 1,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@event_index::field_event_is_live_streaming'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@event_index::field_event_is_online';
  $facet->searcher = 'search_api@event_index';
  $facet->realm = '';
  $facet->facet = 'field_event_is_online';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        6 => 0,
        4 => 0,
        5 => 0,
        7 => 0,
        9 => 0,
        10 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'announcement' => 0,
        'article' => 0,
        'banner_video' => 0,
        'banner_quote' => 0,
        'page' => 0,
        'consultation' => 0,
        'contact' => 0,
        'coordination' => 0,
        'department' => 0,
        'editorial_team' => 0,
        'event' => 0,
        'featured_item' => 0,
        'file' => 0,
        'funding' => 0,
        'guidance' => 0,
        'impact_assessment' => 0,
        'info_homepage' => 0,
        'law' => 0,
        'new_content_type' => 0,
        'basic_page' => 0,
        'person' => 0,
        'policy' => 0,
        'policy_area' => 0,
        'policy_implementation' => 0,
        'policy_input' => 0,
        'policy_keyfile' => 0,
        'priority' => 0,
        'priority_policy_area' => 0,
        'publication' => 0,
        'class' => 0,
        'class_link_group' => 0,
        'tender' => 0,
        'topic' => 0,
        'toplink' => 0,
        'image' => 0,
        'video' => 0,
        'audio' => 0,
        'document' => 0,
      ),
      'facets' => array(
        'field_core_location:country' => 0,
        'field_event_type' => 0,
        'field_event_is_live_streaming' => 0,
        'field_core_departments' => 0,
        'field_core_topics' => 0,
      ),
      'reverse_dependency' => 0,
      'force_deactivation' => 0,
      'regex' => 0,
      'facet_items_field_core_location:country' => '',
      'facet_items_field_event_type' => '',
      'facet_items_field_event_is_live_streaming' => '',
      'facet_items_field_core_departments' => '',
      'facet_items_field_core_topics' => '',
    ),
    'facet_mincount' => '0',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 1,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@event_index::field_event_is_online'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@event_index::field_event_type';
  $facet->searcher = 'search_api@event_index';
  $facet->realm = '';
  $facet->facet = 'field_event_type';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        6 => 0,
        4 => 0,
        5 => 0,
        7 => 0,
        9 => 0,
        10 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'announcement' => 0,
        'article' => 0,
        'banner_video' => 0,
        'banner_quote' => 0,
        'page' => 0,
        'consultation' => 0,
        'contact' => 0,
        'coordination' => 0,
        'department' => 0,
        'editorial_team' => 0,
        'event' => 0,
        'featured_item' => 0,
        'file' => 0,
        'funding' => 0,
        'guidance' => 0,
        'impact_assessment' => 0,
        'info_homepage' => 0,
        'law' => 0,
        'new_content_type' => 0,
        'basic_page' => 0,
        'person' => 0,
        'policy' => 0,
        'policy_area' => 0,
        'policy_implementation' => 0,
        'policy_input' => 0,
        'policy_keyfile' => 0,
        'priority' => 0,
        'priority_policy_area' => 0,
        'publication' => 0,
        'class' => 0,
        'class_link_group' => 0,
        'tender' => 0,
        'topic' => 0,
        'toplink' => 0,
        'image' => 0,
        'video' => 0,
        'audio' => 0,
        'document' => 0,
      ),
      'facets' => array(
        'field_core_location:country' => 0,
        'field_event_is_online' => 0,
        'field_event_is_live_streaming' => 0,
        'field_core_departments' => 0,
        'field_core_topics' => 0,
      ),
      'reverse_dependency' => 0,
      'force_deactivation' => 0,
      'regex' => 0,
      'facet_items_field_core_location:country' => '',
      'facet_items_field_event_is_online' => '',
      'facet_items_field_event_is_live_streaming' => '',
      'facet_items_field_core_departments' => '',
      'facet_items_field_core_topics' => '',
    ),
    'facet_mincount' => '0',
    'facet_missing' => '0',
    'flatten' => '1',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 1,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@event_index::field_event_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@event_index:block:field_core_departments';
  $facet->searcher = 'search_api@event_index';
  $facet->realm = 'block';
  $facet->facet = 'field_core_departments';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_select_dropdowns',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'default_option_label' => '',
    'reset_option_label' => '',
    'submit_page' => '',
    'hide_facet_count' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
  );
  $export['search_api@event_index:block:field_core_departments'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@event_index:block:field_core_location:country';
  $facet->searcher = 'search_api@event_index';
  $facet->realm = 'block';
  $facet->facet = 'field_core_location:country';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_select_dropdowns',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'exclude_items' => array(
        'status' => 0,
        'weight' => '-49',
      ),
      'rewrite_items' => array(
        'status' => 0,
        'weight' => '-48',
      ),
      'narrow_results' => array(
        'status' => 0,
        'weight' => '-47',
      ),
      'show_if_minimum_items' => array(
        'status' => 1,
        'weight' => '-46',
      ),
      'deepest_level_items' => array(
        'status' => 0,
        'weight' => '-45',
      ),
    ),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'default_option_label' => '',
    'reset_option_label' => '',
    'submit_page' => '',
    'hide_facet_count' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => '0',
  );
  $export['search_api@event_index:block:field_core_location:country'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@event_index:block:field_core_topics';
  $facet->searcher = 'search_api@event_index';
  $facet->realm = 'block';
  $facet->facet = 'field_core_topics';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_select_dropdowns',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'exclude_items' => array(
        'status' => 0,
        'weight' => '-49',
      ),
      'rewrite_items' => array(
        'status' => 0,
        'weight' => '-48',
      ),
      'narrow_results' => array(
        'status' => 0,
        'weight' => '-47',
      ),
      'show_if_minimum_items' => array(
        'status' => 1,
        'weight' => '-46',
      ),
      'deepest_level_items' => array(
        'status' => 0,
        'weight' => '-45',
      ),
    ),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'text',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'default_option_label' => '',
    'reset_option_label' => '',
    'submit_page' => '',
    'hide_facet_count' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => '0',
  );
  $export['search_api@event_index:block:field_core_topics'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@event_index:block:field_event_is_live_streaming';
  $facet->searcher = 'search_api@event_index';
  $facet->realm = 'block';
  $facet->facet = 'field_event_is_live_streaming';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'dt_facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'exclude_items' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'rewrite_items' => array(
        'status' => 1,
        'weight' => '-48',
      ),
      'narrow_results' => array(
        'status' => 0,
        'weight' => '-47',
      ),
      'show_if_minimum_items' => array(
        'status' => 0,
        'weight' => '-46',
      ),
      'deepest_level_items' => array(
        'status' => 0,
        'weight' => '-45',
      ),
    ),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'default_option_label' => '',
    'reset_option_label' => '',
    'submit_page' => '',
    'hide_facet_count' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'exclude' => 'no',
    'regex' => 0,
    'show_minimum_items' => 2,
    'rewrite_items' => 1,
  );
  $export['search_api@event_index:block:field_event_is_live_streaming'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@event_index:block:field_event_is_online';
  $facet->searcher = 'search_api@event_index';
  $facet->realm = 'block';
  $facet->facet = 'field_event_is_online';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'dt_facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'exclude_items' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'rewrite_items' => array(
        'status' => 1,
        'weight' => '-48',
      ),
      'narrow_results' => array(
        'status' => 0,
        'weight' => '-47',
      ),
      'show_if_minimum_items' => array(
        'status' => 1,
        'weight' => '-46',
      ),
      'deepest_level_items' => array(
        'status' => 0,
        'weight' => '-45',
      ),
    ),
    'active_sorts' => array(
      'active' => 'active',
      'display' => 'display',
      'count' => 0,
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'default_option_label' => '',
    'reset_option_label' => '',
    'submit_page' => '',
    'hide_facet_count' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'exclude' => 'no',
    'regex' => 0,
    'show_minimum_items' => '0',
    'rewrite_items' => 1,
  );
  $export['search_api@event_index:block:field_event_is_online'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@event_index:block:field_event_type';
  $facet->searcher = 'search_api@event_index';
  $facet->realm = 'block';
  $facet->facet = 'field_event_type';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_select_dropdowns',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-49',
      ),
      'exclude_items' => array(
        'status' => 0,
        'weight' => '-48',
      ),
      'rewrite_items' => array(
        'status' => 0,
        'weight' => '-47',
      ),
      'narrow_results' => array(
        'status' => 0,
        'weight' => '-46',
      ),
      'show_if_minimum_items' => array(
        'status' => 0,
        'weight' => '-45',
      ),
      'deepest_level_items' => array(
        'status' => 0,
        'weight' => '-44',
      ),
    ),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'default_option_label' => '',
    'reset_option_label' => '',
    'submit_page' => '',
    'hide_facet_count' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => 2,
    'rewrite_items' => 1,
  );
  $export['search_api@event_index:block:field_event_type'] = $facet;

  return $export;
}
