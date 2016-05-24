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
  $facet->name = 'search_api@event_index:views:field_core_departments';
  $facet->searcher = 'search_api@event_index';
  $facet->realm = 'views';
  $facet->facet = 'field_core_departments';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facets_in_filters_select',
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
        'status' => 1,
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
    'hide_facet_count' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => 2,
  );
  $export['search_api@event_index:views:field_core_departments'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@event_index:views:field_core_location:country';
  $facet->searcher = 'search_api@event_index';
  $facet->realm = 'views';
  $facet->facet = 'field_core_location:country';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facets_in_filters_select',
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
        'status' => 1,
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
    'hide_facet_count' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => 2,
  );
  $export['search_api@event_index:views:field_core_location:country'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@event_index:views:field_core_topics';
  $facet->searcher = 'search_api@event_index';
  $facet->realm = 'views';
  $facet->facet = 'field_core_topics';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facets_in_filters_select',
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
        'status' => 1,
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
    'hide_facet_count' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => 2,
  );
  $export['search_api@event_index:views:field_core_topics'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@event_index:views:field_event_is_live_streaming';
  $facet->searcher = 'search_api@event_index';
  $facet->realm = 'views';
  $facet->facet = 'field_event_is_live_streaming';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facets_in_filters_checkbox',
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
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => 2,
    'rewrite_items' => 1,
  );
  $export['search_api@event_index:views:field_event_is_live_streaming'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@event_index:views:field_event_is_online';
  $facet->searcher = 'search_api@event_index';
  $facet->realm = 'views';
  $facet->facet = 'field_event_is_online';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facets_in_filters_checkbox',
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
  $export['search_api@event_index:views:field_event_is_online'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@event_index:views:field_event_type';
  $facet->searcher = 'search_api@event_index';
  $facet->realm = 'views';
  $facet->facet = 'field_event_type';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facets_in_filters_select',
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
        'status' => 1,
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
  );
  $export['search_api@event_index:views:field_event_type'] = $facet;

  return $export;
}
