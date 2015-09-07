<?php
/**
 * @file
 * cwt_core.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function cwt_core_taxonomy_default_vocabularies() {
  return array(
    'departments' => array(
      'name' => 'Departments',
      'machine_name' => 'departments',
      'description' => 'Organizational departments of the European Commission',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-8',
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
    'editorial_sections' => array(
      'name' => 'Editorial sections',
      'machine_name' => 'editorial_sections',
      'description' => 'Hiearchy to define granular access control for editors and contributors',
      'hierarchy' => '1',
      'module' => 'taxonomy',
      'weight' => '-7',
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
    'project_teams' => array(
      'name' => 'Project teams',
      'machine_name' => 'project_teams',
      'description' => 'Used for the functional grouping of the commissioners on the college page.',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-1',
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
  );
}
