<?php

namespace Drupal\nexteuropa_eurovoc;

/**
 * Class EuroVoc.
 */
class EuroVoc extends EuroVocBase {

  /**
   * List of file names which contain concept relationships.
   *
   * @var array
   */
  private $relationships = [
    'descriptors-thesauri' => 'desc_thes',
    'broader-terms' => 'relation_bt',
    'use-instead' => 'relation_ui',
    'related' => 'relation_rt',
  ];

  /**
   * That will contain the $relationships with their full data.
   *
   * @var array
   */
  private $relationshipsTable = [];

  /**
   * {@inheritdoc}
   */
  public function __construct() {

    // Load file names that have relationships information.
    $relationships = $this->getRelationships();

    // Go through the XML files and convert the data into an array.
    $relationships_table = [];
    foreach ($relationships as $relationship => $relationship_file) {
      $file = $this->getDataPath() . '/' . $relationship_file . '.xml';
      if (file_exists($file)) {
        $file_xml = simplexml_load_file($file, 'SimpleXMLElement', LIBXML_COMPACT);
        $file_array = json_decode(json_encode($file_xml), 1);
        $relationships_table[$relationship] = $file_array['RECORD'];
      }
    }

    // Place the array of relationships into the instance state.
    $this->setRelationshipsTable($relationships_table);
  }

  /**
   * Get the list of file names that contain any type of relationships.
   *
   * @return array
   *   The list of file names.
   */
  public function getRelationships() {
    return $this->relationships;
  }

  /**
   * Sets an array as information source of concept relationships.
   *
   * @param array $table
   *   Array representing relationships table.
   */
  public function setRelationshipsTable($table) {
    $this->relationshipsTable = $table;
  }

  /**
   * Gets an array of information about concept relationships.
   */
  public function getRelationshipsTable() {
    return $this->relationshipsTable;
  }

  /**
   * Searches for a specific relationship in relationshipsTable.
   *
   * @param string $relationship
   *   A relationship key to search in the table.
   *
   * @return array
   *   The specific information about a given $relationship.
   */
  public function getRelationship($relationship) {
    $relationship_table = $this->getRelationshipsTable();
    if (isset($relationship_table[$relationship])) {
      return $relationship_table[$relationship];
    }
    return [];
  }

  /**
   * Get parent thesaurus by descriptor id input.
   *
   * @param string $desc_id
   *   Descriptor ID.
   *
   * @return array
   *    Parent thesauri of the descriptor.
   */
  public function getParents($desc_id) {
    $desc_thes = $this->getRelationship('descriptors-thesauri');
    $parents = [];
    // Compile parent thesauri.
    foreach ($desc_thes as $relation) {
      if ($relation['DESCRIPTEUR_ID'] == $desc_id) {
        $parents[] = $relation['THESAURUS_ID'];
      }
    }
    return $parents;
  }

  /**
   * Returns a list of parents.
   *
   * @param string $desc_id
   *   The ID for the query.
   *
   * @return array
   *   List of eurovoc ids of parents if available.
   *   Empty array means the term is non-preferred.
   */
  public function getBroaderTerms($desc_id) {
    $desc_desc = $this->getRelationship('broader-terms');
    $parents = [];
    // Compile parent broader terms.
    foreach ($desc_desc as $relation) {
      if ($relation['SOURCE_ID'] == $desc_id) {
        $parents[] = $relation['CIBLE_ID'];
      }
    }
    return $parents;
  }

  /**
   * Returns a list of terms that should be used instead of the input id.
   *
   * @param string $desc_id
   *   The ID for the query.
   *
   * @return array
   *   List of eurovoc ids to use instead of input id.
   */
  public function getUseIstead($desc_id) {
    $list = $this->getRelationship('use-instead');
    $recommendations = [];
    // Compile use instead terms.
    foreach ($list as $relation) {
      if ($relation['SOURCE_ID'] == $desc_id) {
        $recommendations[] = $relation['CIBLE_ID'];
      }
    }
    return $recommendations;
  }

  /**
   * Returns a list of descriptors related to a given descriptor.
   *
   * @param string $desc_id
   *   The ID for the query.
   *
   * @return array
   *   List of descriptor ids related to the input id.
   */
  public function getRelatedDescriptors($desc_id) {
    $list = $this->getRelationship('related');
    $related = [];
    // Compile use instead terms.
    foreach ($list as $relation) {
      if ($relation['DESCRIPTEUR1_ID'] == $desc_id) {
        $related[] = $relation['DESCRIPTEUR2_ID'];
      }
      elseif ($relation['DESCRIPTEUR2_ID'] == $desc_id) {
        $related[] = $relation['DESCRIPTEUR1_ID'];
      }
    }
    return $related;
  }

}
