<?php

/**
 * @file
 * Views integration for the Commissioners Web Template project.
 */

/**
 * Implements hook_views_query_alter().
 *
 * Alters the 'Commissioner's Hierarchy' display on the 'Team members' view to
 * make it display the biographies in the 'Team members by hierarchy' display in
 * the correct order. This display is shown in two QuickTab tabs: once ordered
 * by last name alphabetically, and once ordered by a nodequeue which lists the
 * biographies ordered by role. The ordering that is used is determined by the
 * first contextual argument: this can be set to either 'name' or 'role'.
 *
 * This nodequeue contains a list of biographies in a particular order. To make
 * it more manageable this nodequeue only contains the English versions of each
 * biography, rather than all 200+ translations. The view should show all
 * biographies in the users' current language, with a fallback to English if the
 * current translation does not exist.
 *
 * It was not possible to solve this using vanilla Nodequeue and Views.
 * Nodequeue has an option to 'treat translation nodes as a single node' but
 * this only works using Nodequeue's internal listings, not with the Views
 * integration. There is an issue about setting this up in Views (see
 * https://www.drupal.org/node/982382) but unfortunately with the suggested
 * approach the ordering is not respected. Another drawback is that this would
 * cause the node table to be joined with itself twice, which could cause
 * performance and memory issues if the number of nodes grows in the future.
 *
 * The ordering is critical; the sole reason we are using a nodequeue is to
 * expose the ordering of the biographies to editors.
 */
function cwt_team_views_query_alter(&$view, &$query) {
  global $language;

  if ($view->name == 'team_members' && $view->current_display == 'block_2') {
    // Load the "Team members by hierarchy" nodequeue. It only has one subqueue.
    $nodequeue = nodequeue_load_queue_by_name('team_members_by_hierarchy');
    $subqueues = nodequeue_load_subqueues_by_queue($nodequeue->qid);
    $subqueue = reset($subqueues);

    // Compile our list of nodes. We need a list of nodes in the current
    // language, ordered by the position in the nodequeue. If the node is not
    // present in the current language the default (English) translation should
    // be used as a fallback.
    $nids = array();
    foreach (nodequeue_load_nodes($subqueue->sqid, FALSE, 0, 0) as $node) {
      // If a translation exists in the current language then use it, otherwise
      // fall back to the default (English) translation.
      $nids[] = ($translations = translation_node_get_translations($node->nid)) && array_key_exists($language->language, $translations) ? $translations[$language->language]->nid : $node->nid;
    }

    // Add our list of nodes to the query.
    $query->add_where(0, 'node.nid', $nids, 'IN');

  }
}

/**
 * Implements hook_views_pre_render().
 *
 * Alter the 'Team Members by Domain' view.
 *
 * This view was originally built to return biographies that are tagged with one
 * of the terms in the 'Project Teams' vocabulary. The requirements have been
 * changed to work with smartqueues one week before the launch of the website.
 * Significant work had been done in the front end to make the grouped results
 * collapsible and showing tiny thumbnails in the headers in uncollapsed state
 * in particular browser widths. Our front end developer is currently on holiday
 * so we opted to "fix" this in pre_render rather than rebuilding the view from
 * scratch. This way we can keep the delicate markup intact.
 *
 * - Provide a language fallback to English if the node is not available in the
 *   current language. The query used in the view is returning both results if
 *   they are available. In here we filter out the inappropriate one.
 * - Discard all results that are not part of one of the 'Biographies by Project
 *   Teams' smartqueues, so that the results match the smartqueues. It was not
 *   easy to figure out a way to alter the view to make it work with queues. The
 * - Order the groups according to the position of the terms in the vocabulary.
 * - Order the results within a group according to their position in the
 *   nodequeue.
 *
 * @todo When additional budget is made available, rebuild this view from
 *   scratch to be based on nodequeue tables rather than on taxonomy.
 */
function cwt_team_views_pre_render(&$view) {
  global $language;

  if ($view->name == 'team_members_by_domain') {
    // The results will be grouped by project team in the order they have been
    // placed in the interface. Retrieve a list of project team tids ordered by
    // weight.
    $vocabulary = taxonomy_vocabulary_machine_name_load('project_teams');
    $term_weights = array_flip(db_select('taxonomy_term_data', 't')
      ->addTag('translatable')
      ->addTag('term_access')
      ->fields('t', array('tid'))
      ->condition('t.vid', $vocabulary->vid)
      ->orderBy('t.weight')
      ->orderBy('t.name')
      ->execute()
      ->fetchCol());

    // Load the nids that are part of the subqueues and order them by the weight
    // of the teams. Keep track of both the term ID (stored in the subqueue
    // 'reference' property) and the node position.
    $node_positions = array();
    $nodequeue = nodequeue_load_queue_by_name('biographies_by_project_teams');
    $subqueues = nodequeue_load_subqueues_by_queue($nodequeue->qid);
    foreach ($subqueues as $subqueue) {
      $position = 0;
      foreach (nodequeue_load_nodes($subqueue->sqid, FALSE, 0, 0) as $node) {
        // If a translation exists in the current language then use it,
        // otherwise fall back to the default (English) translation.
        $nid = ($translations = translation_node_get_translations($node->nid)) && array_key_exists($language->language, $translations) ? $translations[$language->language]->nid : $node->nid;
        $node_positions[$subqueue->reference][$nid] = $position++;
      }
    }

    // Filter the results, discarding all that are not in the nodequeue. This
    // will get rid of duplicate results for nodes that have a translation in
    // the current language as well as English, and nodes that are part of a
    // project team but have not manually been placed in a queue.
    $view->result = array_filter($view->result, function ($element) use ($node_positions) {
      return !empty($node_positions[$element->tid]) && array_key_exists($element->field_biography_project_team_taxonomy_term_data_nid, $node_positions[$element->tid]);
    });

    // Order the results, first by the order of the terms in the Project Teams
    // vocabulary, then by nodequeue position.
    uasort($view->result, function ($a, $b) use ($node_positions, $term_weights) {
      // Sort first on term weights.
      $a_weight = $term_weights[$a->tid];
      $b_weight = $term_weights[$b->tid];

      // If both results belong to the same term, sort on nodequeue position.
      if ($a_weight == $b_weight) {
        $a_position = $node_positions[$a->tid][$a->field_biography_project_team_taxonomy_term_data_nid];
        $b_position = $node_positions[$b->tid][$b->field_biography_project_team_taxonomy_term_data_nid];
        if ($a_position == $b_position) {
          return 0;
        }
        return ($a_position < $b_position) ? -1 : 1;
      }
      return ($a_weight < $b_weight) ? -1 : 1;
    });

    // Reset the keys of the Views results. Views uses the keys to determine the
    // ordering of results inside a group.
    // @see views_plugin_style::render_grouping()
    $view->result = array_values($view->result);
  }
}

/**
 * Implements hook_views_data_alter().
 *
 * Provides a customized field handler that allows to link to nodes in their
 * source language. This is needed when content is shown that has not been
 * translated to the current language but has a link to the full node.
 */
function cwt_team_views_data_alter(&$data) {
  $data['node']['cwt_team_source_language_path'] = array(
    'field' => array(
      'title' => t('Source language path'),
      'help' => t('The aliased path to this content in its source language.'),
      'handler' => 'cwt_team_handler_field_node_source_language_path',
    ),
  );
}
