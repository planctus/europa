<?php
/**
 * @file
 * social_network_links.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function social_network_links_taxonomy_default_vocabularies() {
  return array(
    'social_networks' => array(
      'name' => 'Social Networks',
      'machine_name' => 'social_networks',
      'description' => 'List of social networks',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '1',
      'language' => 'und',
      'i18n_mode' => '0',
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