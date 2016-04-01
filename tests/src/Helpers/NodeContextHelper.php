<?php

namespace Drupal\nexteuropa\Helpers;

/**
 * Helper class to get node information.
 */
class NodeContextHelper {

  /**
   * Variable holding the complete node object.
   *
   * @var stdClass $nodeObject
   */
  private $nodeObject;

  /**
   * Variable holding the complete language object.
   *
   * @var stdClass $language
   */
  private $language;

  /**
   * NodeContextHelper constructor.
   */
  public function __construct($session) {
    global $base_url;

    // Get the language list.
    $language_list = language_list('enabled');

    // Get the alias without suffix and the language object.
    $alias_no_suffix = nexteuropa_multilingual_language_negotiation_split_suffix($session->getCurrentUrl(), $language_list[1]);

    // Get the real node path.
    $node_path = drupal_lookup_path('source', str_replace($base_url . '/', '', $alias_no_suffix[1]));

    if ($node = menu_get_object('node', 1, $node_path)) {
      $this->language = $alias_no_suffix[0];
      $this->nodeObject = $node;
    }
    else {
      throw new \Exception("Could not initialize node as you are not on a node page.");
    }
  }

  /**
   * Get the node id.
   *
   * @return string
   *   The id of the node.
   */
  public function getNodeId() {
    return $this->nodeObject->nid;
  }

  /**
   * Get the node path.
   *
   * @return string
   *   The path to the node.
   */
  public function getNodePath() {
    return '/node/' . $this->nodeObject->nid;
  }

  /**
   * Get the node language.
   *
   * @return object
   *   The language object of the current page.
   */
  public function getLanguage() {
    return $this->language;
  }

  /**
   * Get the add translation path.
   *
   * @param string $target
   *   The target language.
   *
   * @return string
   *   The url as string.
   */
  public function getAddTranslationPath($target) {
    return $this->getNodePath() . '/edit/add/' . $this->nodeObject->language . '/' . $target . '_' . $target;
  }

}
