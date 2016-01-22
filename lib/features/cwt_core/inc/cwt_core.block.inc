<?php
/**
 * @file
 * Cwt_core.block.
 */

/**
 * Implements hook_block_info().
 */
function cwt_core_block_info() {
  $blocks['cwt_block_copyright'] = array(
    'info' => t('Copyright paragraph'),
  );

  $blocks['cwt_header_site_tab_switcher'] = array(
    'info' => t('Header site tab switcher'),
  );

  $blocks['cwt_footer_site_tab_switcher'] = array(
    'info' => t('Footer site tab switcher'),
  );

  $blocks['college_members'] = array(
    'info' => t('College members'),
  );

  $blocks['translation_selector'] = array(
    'info' => t('Translation selector'),
  );

  $blocks['page_contents'] = array(
    'info' => t('Page Contents'),
  );

  return $blocks;
}

/**
 * Implements hook_block_info_alter().
 */
function cwt_core_block_info_alter(&$blocks, $theme, $code_blocks) {
  // Hide Service tools title.
  if (isset($blocks['menu']['menu-service-tools'])) {
    $blocks['menu']['menu-service-tools']['title'] = '<none>';
  }
}

/**
 * Implements hook_block_view().
 */
function cwt_core_block_view($delta = '') {
  $block = array();

  $function = '_cwt_core_block_' . $delta . '_view';
  if (function_exists($function)) {
    $block = $function();
  }

  return $block;
}

/**
 * Page Contents block content.
 */
function _cwt_core_block_page_contents_view() {
  $block = array();
  $items = array();
  $node = menu_get_object('node');
  $reaction = context_get_plugin('reaction', 'block');
  if ($node && ($context_blocks = $reaction->block_list('content'))) {
    foreach ($context_blocks as $key => $current_block) {
      if ($key == 'system_main') {
        $content_node = $current_block->content['nodes'][$node->nid];
        $title = isset($content_node['body']['#title']) ? $content_node['body']['#title'] : FALSE;
      }
      else {
        $title = isset($current_block->subject) && $current_block->subject ? $current_block->subject : FALSE;
      }
      if ($title) {
        $fragment = str_replace('_', '-', ('block-' . $current_block->module . '-' . $current_block->delta));
        $items[$key] = '<a href="#' . $fragment . '">' . $title . '</a>';
      }
    }
  }

  if (!empty($items)) {
    $block['subject'] = t('Page Contents');
    $variables = array(
      'items' => $items,
      'attributes' => array(
        'class' => 'nav nav-stacked',
      ),
    );
    $block['content'] = theme('item_list', $variables);
  }

  return $block;
}

/**
 * Translation selector block content.
 */
function _cwt_core_block_translation_selector_view() {
  $block = array();
  $selector = _cwt_core_translation_selector();
  if ($selector) {
    $block['subject'] = '';
    $block['content'] = array(
      '#markup' => render($selector),
      '#attached' => array(
        'js' => array(
          drupal_get_path('module', 'cwt_core') .'/js/translation_selector.js', 'file'
        ),
      ),
    );
  }
  return $block;
}

/**
 * College members block content.
 */
function _cwt_core_block_college_members_view() {
  $block = array();
  // Get the customized title from the term.
  $team_node = menu_get_object();
  if (isset($team_node->field_team_subtype) && !empty($team_node->field_team_subtype)) {
    $type_field = field_get_items('node', $team_node, 'field_team_subtype');
    $type = field_view_value('node', $team_node, 'field_team_subtype', $type_field[0]);

    $block_title_field = field_get_items('taxonomy_term', $type['#options']['entity'], 'field_members_block_title');
    if ($block_title_field) {
      $block_title = field_view_value('taxonomy_term', $type['#options']['entity'], 'field_members_block_title', $block_title_field[0]);
      $block['subject'] = $block_title['#markup'];
    }
  }
  $block['content']['president_title']['#markup'] = "<h3>" . t('President') . "</h3>";
  $block['content']['president']['#markup'] = views_embed_view('team_members', 'block_1');
  if ($qt = quicktabs_build_quicktabs('team_members')) {
    $block['content']['tabs_title']['#markup'] = "<h3>" . check_plain($qt['#title']) . "</h3>";
    $block['content']['tabs'] = $qt['content'];
    $block['content']['tabs']['#contextual_links']['quicktabs'] = array('admin/structure/quicktabs/manage', array('college_members'));
    $block['content']['attachments']['#markup'] = views_embed_view('team_attachments', 'block');
  }
  return $block;
}

/**
 * Copyright block content.
 */
function _cwt_core_block_cwt_block_copyright_view() {
  $block = array();

  $block['content'] = array(
    '#markup' => "<div class='footer__disclaimer'><span>" . t('© European Commission 2015') . "</span></div>",
  );

  return $block;
}

/**
 * Header site tab switcher content.
 */
function _cwt_core_block_cwt_header_site_tab_switcher_view() {
  $block = array();

  $block['content'] = array(
    '#markup' => theme('site_switcher_tabs', array('modifier' => 'site-switcher--header')),
  );

  return $block;
}
/**
 * Footer site tab switcher content.
 */
function _cwt_core_block_cwt_footer_site_tab_switcher_view() {
  $block = array();

  $block['content'] = array(
    '#markup' => theme('site_switcher_tabs', array('modifier' => 'site-switcher--footer')),
  );

  return $block;
}
