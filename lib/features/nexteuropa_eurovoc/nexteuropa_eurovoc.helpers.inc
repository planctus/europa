<?php

/**
 * @file
 * Drupal-related helper functions.
 */

use Drupal\nexteuropa_eurovoc\EuroVoc;
use Drupal\nexteuropa_eurovoc\EuroVocTranslations;

/**
 * Retrieve path to XML data folder.
 */
function _nexteuropa_eurovoc_get_data_full_path() {
  $module_path = drupal_get_path('module', 'nexteuropa_eurovoc');
  return DRUPAL_ROOT . '/' . $module_path . '/data/';
}

/**
 * Helper function to translate between eurovoc id and drupal term id.
 *
 * @param string $level
 *   EuroVoc hierarchy level: domain, thesaurus, descriptor.
 * @param string $evid
 *   EuroVoc ID to query for.
 *
 * @return array|bool
 *   The list of Drupal term ids corresponding to the input evid.
 */
function _nexteuropa_eurovoc_get_tid_by_evid($level, $evid) {
  $eurovoc_voc = taxonomy_vocabulary_machine_name_load('eurovoc');
  if ($level && $evid) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'taxonomy_term')
      ->propertyCondition('vid', $eurovoc_voc->vid)
      ->fieldCondition('field_eurovoc_level', 'value', $level, '=')
      ->fieldCondition('field_eurovoc_id', 'value', $evid, '=');
    $result = $query->execute();
    if ($result && isset($result['taxonomy_term'])) {
      return array_keys($result['taxonomy_term']);
    }
  }
  return FALSE;
}

/**
 * There are orphan descriptors which are not recommended and should be adopted.
 *
 * @param null|\Drupal\nexteuropa_eurovoc\EuroVoc $eurovoc
 *   Optional existing instance of the EuroVoc handler.
 */
function _nexteuropa_eurovoc_adopt_orphan_descriptors($eurovoc = NULL) {
  // Defaults will create new handler.
  if ($eurovoc === NULL) {
    $eurovoc = new EuroVoc();
  }
  // Get a list of special cases.
  $recommendations = $eurovoc->getRelationship('use-instead');
  foreach ($recommendations as $recommendation) {
    // EuroVoc IDs.
    $ophan = $recommendation['SOURCE_ID'];
    $recommended_parent = $recommendation['CIBLE_ID'];
    // Drupal term ids.
    $orphan_tid = _nexteuropa_eurovoc_get_tid_by_evid('descriptor', $ophan);
    $recommended_tid = _nexteuropa_eurovoc_get_tid_by_evid('descriptor', $recommended_parent);
    if ($recommended_tid && $orphan_tid) {
      // Get parents of the recommended parents to share them with the orphan.
      $recommended_parents = taxonomy_get_parents($recommended_tid[0]);
      // Target recommendations.
      $parents_target = [];
      foreach ($recommended_parents as $rec_par_term) {
        $parents_target[] = $rec_par_term->tid;
      }
      $ophan_term = taxonomy_term_load($orphan_tid[0]);
      $oemw = entity_metadata_wrapper('taxonomy_term', $ophan_term);
      // Set the recommended parents as Use Instead reference.
      $oemw->field_eurovoc_ui->set($recommended_tid);
      $oemw->save();
      // Adopt the orphan.
      $ophan_term->parent = $parents_target;
      // Save changes.
      taxonomy_term_save($ophan_term);
    }
  }
}

/**
 * Some descriptors have broader terms, which means multiple parents.
 *
 * @param null|\Drupal\nexteuropa_eurovoc\EuroVoc $eurovoc
 *   Optional existing instance of the EuroVoc handler.
 */
function _nexteuropa_eurovoc_organize_broader_descriptors($eurovoc = NULL) {
  // Defaults will create new handler.
  if ($eurovoc === NULL) {
    $eurovoc = new EuroVoc();
  }
  $tree = _nexteuropa_eurovoc_get_eurovoc_terms();
  // Iterate only the descriptors.
  foreach ($tree['descriptor'] as $eurovoc_id => $drupal_term) {
    $broader_terms_eurovoc = $eurovoc->getBroaderTerms($eurovoc_id);
    // Translate broad term euvoroc ids to Drupal terms ids.
    if (isset($broader_terms_eurovoc) && count($broader_terms_eurovoc)) {
      $broader_terms_drupal = [];
      foreach ($broader_terms_eurovoc as $btev) {
        // If there is a Drupal equivalent of this EuroVoc term.
        if ($tid = _nexteuropa_eurovoc_get_tid_by_evid('descriptor', $btev)) {
          $broader_terms_drupal[] = $tid[0];
        }
      }
      if (count($broader_terms_drupal) > 0) {
        $existing_parents = array_keys(taxonomy_get_parents($drupal_term->tid));
        $all_parents = array_unique(array_merge($existing_parents, $broader_terms_drupal));
        $drupal_term->parent = $all_parents;
        taxonomy_term_save($drupal_term);
      }
    }
  }
}

/**
 * Any concept could potentially have related concepts.
 *
 * @param null|\Drupal\nexteuropa_eurovoc\EuroVoc $eurovoc
 *   Optional existing instance of the EuroVoc handler.
 */
function _nexteuropa_eurovoc_connect_related($eurovoc = NULL) {
  // Defaults will create new handler.
  if ($eurovoc === NULL) {
    $eurovoc = new EuroVoc();
  }
  if ($voc = taxonomy_vocabulary_machine_name_load('eurovoc')) {
    $terms = entity_load('taxonomy_term', FALSE, ['vid' => $voc->vid]);
    if (count($terms) && isset($terms)) {
      // Add information about related terms to each term that has such info.
      foreach ($terms as $term) {
        $emw = entity_metadata_wrapper('taxonomy_term', $term);
        $eurovoc_id = $emw->field_eurovoc_id->value();
        // List of related concepts in eurovoc ids.
        $related_eurovoc = $eurovoc->getRelatedDescriptors($eurovoc_id);
        if (isset($related_eurovoc) && count($related_eurovoc) > 0) {
          // Find Drupal term ids for the list of eurovoc ids.
          $related_drupal = [];
          foreach ($related_eurovoc as $related_evid) {
            if ($related_tid = _nexteuropa_eurovoc_get_tid_by_evid('descriptor', $related_evid)) {
              $related_drupal[] = $related_tid[0];
            }
          }
          $emw->field_eurovoc_related->set($related_drupal);
          $emw->save();
        }
      }
    }
  }
}

/**
 * Organized list of terms from eurovoc taxonomy.
 *
 * @return array
 *
 *   Levels by types and their key:value pairs of eurovoc_id:term_object.
 */
function _nexteuropa_eurovoc_get_eurovoc_terms() {
  $results = [];
  if ($voc = taxonomy_vocabulary_machine_name_load('eurovoc')) {
    $terms = entity_load('taxonomy_term', FALSE, ['vid' => $voc->vid]);
    if (count($terms) && isset($terms)) {
      // Re-organize the to save from level-specific iterations later.
      foreach ($terms as $term) {
        // These field values are not translatable, EMW operation saving.
        $eurovoc_id = $term->field_eurovoc_id[LANGUAGE_NONE][0]['value'];
        $eurovoc_level = $term->field_eurovoc_level[LANGUAGE_NONE][0]['value'];
        // If the term is categorized in any EuroVoc level.
        if ($eurovoc_level != '') {
          $results[$eurovoc_level][$eurovoc_id] = $term;
        }
      }
    }
  }
  return $results;
}

/**
 * Translates all eurovoc terms in all enabled languages.
 */
function _nexteuropa_eurovoc_translate_terms() {
  if (!module_exists('locale')) {
    drupal_set_message(t('Locale module must be enabled'), 'error');
  }
  else {
    $languages = locale_language_list('name');
    if ($voc = taxonomy_vocabulary_machine_name_load('eurovoc')) {
      $terms = entity_load('taxonomy_term', FALSE, ['vid' => $voc->vid]);
      // EuroVoc translations handler.
      $tr_handler = new EuroVocTranslations();
      // Load a tree with all available translations in all languages.
      $eurovoc_translations = $tr_handler->getTranslations();
      if (count($terms) && isset($terms)) {
        foreach ($terms as $term) {
          // EMW is unnecessary, these fields are not translatable.
          $eurovoc_id = $term->field_eurovoc_id[LANGUAGE_NONE][0]['value'];
          $eurovoc_level = $term->field_eurovoc_level[LANGUAGE_NONE][0]['value'];
          // For each available language, make translations for the term.
          foreach ($languages as $lang_code => $language) {
            // If available, take the translation for a specific id and level.
            if (isset($eurovoc_translations[$eurovoc_level][$lang_code][$eurovoc_id])) {
              $translation = $eurovoc_translations[$eurovoc_level][$lang_code][$eurovoc_id];
              _nexteuropa_eurovoc_translate_term($term, $translation, $lang_code);
            }
          }
        }
      }
    }
  }
}

/**
 * Translates a term name in a given language.
 *
 * @param {Mixed} obj|string $term
 *   The term name to translate.
 * @param string $term_translation
 *   The translation to input in the localisation db set.
 * @param string $language
 *   For which language to input the translation.
 *
 * @return mixed
 *   The translation created if successful operation.
 */
function _nexteuropa_eurovoc_translate_term($term, $term_translation, $language) {
  if (is_object($term)) {
    $terms[$term->tid] = $term;
  }
  else {
    $terms = taxonomy_get_term_by_name($term);
  }
  // If taxonomy term is actually found.
  foreach ($terms as $tid => $term) {
    i18n_string_translation_update(
      ['taxonomy', 'term', $tid, 'name'],
      $term_translation,
      $language,
      $term->name
    );
  }
}

/**
 * Removes all terms from the 'eurovoc' vocabulary.
 *
 * @return bool
 *   Whether the clearing was successful.
 */
function _nexteuropa_eurovoc_clear_eurovoc_vocabulary() {
  if ($voc = taxonomy_vocabulary_machine_name_load('eurovoc')) {
    $tree = taxonomy_get_tree($voc->vid);
    // If there's nothing in the vocabulary.
    if (!count($tree)) {
      return FALSE;
    }
    // Delete everything.
    foreach ($tree as $term) {
      taxonomy_term_delete($term->tid);
    }
    return TRUE;
  }
  return FALSE;
}
