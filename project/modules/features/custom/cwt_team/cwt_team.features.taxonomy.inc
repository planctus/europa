<?php
/**
 * @file
 * cwt_team.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function cwt_team_taxonomy_default_vocabularies() {
  return array(
    'team_statuses' => array(
      'name' => 'Team statuses',
      'machine_name' => 'team_statuses',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-3',
      'language' => 'und',
      'i18n_mode' => '1',
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
    'team_subtypes' => array(
      'name' => 'Team sub-types',
      'machine_name' => 'team_subtypes',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-4',
      'language' => 'und',
      'i18n_mode' => '1',
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
    'team_terms' => array(
      'name' => 'Team terms',
      'machine_name' => 'team_terms',
      'description' => 'The Commission\'s term of office',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-2',
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
