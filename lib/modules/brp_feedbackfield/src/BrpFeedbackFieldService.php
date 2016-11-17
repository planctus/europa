<?php

namespace Drupal\brp_feedbackfield;

use Drupal\dt_core_brp\BrpProps;

/**
 * Class BrpFeedbackFieldService.
 *
 * Helper class to get and generate feed backs from the web service.
 */
class BrpFeedbackFieldService {

  /**
   * Client connection.
   *
   * @var mixed
   */
  private $client;

  /**
   * Current result from WS.
   *
   * @var mixed
   */
  private $result;

  /**
   * Current initiative id.
   *
   * @var string
   */
  private $initiative;

  /**
   * Current feedback id.
   *
   * @var int
   */
  public $feedbackid;

  /**
   * Current feedback.
   *
   * @var array
   */
  public $feedback;

  /**
   * Current group of feedback for an initiative.
   *
   * @var array
   */
  private $feedbacks;

  /**
   * Total elements used for pager and UI.
   *
   * @var int
   */
  public $totalelements;

  /**
   * Total pages used for pager.
   *
   * @var int
   */
  public $totalpages;

  /**
   * BrpFeedbackFieldService constructor.
   *
   * @param int $initiative_id
   *   String value with the initiative reference.
   * @param int $feedback_id
   *   String value with the initiative reference.
   */
  public function __construct($initiative_id, $feedback_id = FALSE) {
    $this->initiative = $initiative_id;
    if ($feedback_id) {
      $this->feedbackid = $feedback_id;
    }
    $this->client = clients_connection_load(BrpProps::CONNECTION_NAME);
  }

  /**
   * Loads all the feedback for the current Initiative.
   *
   * @param string $args
   *    String with the pager query string.
   *
   * @return mixed
   *    Array with feed backs.
   */
  public function loadFeedbacksInitiative($args) {
    if (!$this->feedbacks) {
      if (self::getConnectionStatus()) {
        $this->result = $this->client->sendGetRequest(BrpProps::FEEDBACKS_BY_INITIATIVEID .
        $this->initiative . $args);
        if ($this->result) {
          $this->feedbacks = $this->result[BrpProps::FEEDBACK_EMBEDDED][BrpProps::FEEDBACKS_VERSION];
          $this->pagerElements();
          return $this->feedbacks;
        }
      }
      return FALSE;
    }
    return $this->feedbacks;
  }

  /**
   * For feed back pager.
   */
  private function pagerElements() {
    $this->totalelements = $this->result[BrpProps::FEEDBACK_PAGE][BrpProps::FEEDBACK_PAGE_TOTALELEMENTS];
    $this->totalpages = $this->result[BrpProps::FEEDBACK_PAGE][BrpProps::FEEDBACK_PAGE_TOTALPAGES];
  }

  /**
   * Loads feedback detail.
   *
   * @return mixed
   *    Array with feed backs.
   */
  public function loadSingleFeedbackInitiative() {
    if (!$this->feedback) {
      if (self::getConnectionStatus()) {
        if ($this->feedback = $this->client->sendGetRequest(BrpProps::FEEDBACKS_VERSION . '/' . $this->feedbackid)) {
          return FALSE;
        }
        return $this->feedback;
      }
      return FALSE;
    }
    return $this->feedback;
  }

  /**
   * Loads field values.
   *
   * @param string $field
   *    Field name as string.
   *
   * @return mixed
   *    Array with feed backs.
   */
  public function getSingleFeedbackFieldValue($field) {
    if (!$this->feedback) {
      self::loadSingleFeedbackInitiative();
      if ($this->feedback && isset($this->feedback[$field])) {
        return $this->feedback[$field];
      }
    }
    else {
      if (isset($this->feedback[$field])) {
        return $this->feedback[$field];
      }
    }
    return FALSE;
  }

  /**
   * Helper to check the status of web service.
   *
   * @return bool
   *    Returns current connection status.
   */
  private function getConnectionStatus() {
    if ($this->client->checkConnectionStatus()) {
      return TRUE;
    }
    return FALSE;
  }

}
