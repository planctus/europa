<?php

/**
 * @file
 * dt_nal_corporate_bodies.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function dt_nal_corporate_bodies_taxonomy_default_vocabularies() {
  return array(
    'nal_corporate_bodies' => (object) array(
      'name' => 'NAL corporate bodies',
      'machine_name' => 'nal_corporate_bodies',
      'description' => 'Vocabulary holding records of http://publications.europa.eu/mdr/authority/corporate-body/index.html',
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
