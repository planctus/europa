<?php
/**
 * @file
 * cwt_news.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function cwt_news_filter_default_formats() {
  $formats = array();

  // Exported format: News Text Filter.
  $formats['news_text_filter'] = (object) array(
    'format' => 'news_text_filter',
    'name' => 'News Text Filter',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_html' => array(
        'weight' => -10,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd> <table> <thead> <tbody> <tr> <td> <h2> <h3> <h4> <h5> <h6> <pre> <p> <address>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'ckeditor_link_filter' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
