<?php

/**
 * @file
 * nexteuropa_eurovoc.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function nexteuropa_eurovoc_taxonomy_default_vocabularies() {
  return array(
    'eurovoc' => (object) array(
      'name' => 'EuroVoc',
      'machine_name' => 'eurovoc',
      'description' => 'Drupal implementation of eurovoc.europa.eu',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
