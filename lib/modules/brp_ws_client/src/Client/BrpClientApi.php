<?php

namespace Drupal\brp_ws_client\Client;

use Drupal\brp_ws_client\Exceptions\ClientException;
use Drupal\dt_core_brp\BrpProps;
use Drupal\dt_core_brp\BrpTools;

/**
 * Class BrpClient - helper class for BRP REST Web Service Client.
 *
 * Provides direct BRP REST API methods for the client class.
 * Made to separate API which can change from business functionality developed
 * and wrapped on.
 */
class BrpClientApi {
  private $brpClient;
  private $connectionName;

  /**
   * BrpWsApi constructor.
   *
   * @param \Drupal\brp_ws_client\Client\BrpClient $connection
   *   Passing connection object with all needed details to perform actions
   *   against BRP REST WS API.
   */
  public function __construct(BrpClient $connection) {
    $this->brpClient = $connection;
    $this->connectionName = $connection->name;
  }

  /**
   * Main method for sending requests.
   *
   * @param string $resource_path
   *   Service ndpoint.
   * @param string $http_method
   *   HTTP request method.
   * @param array $data
   *   Data array that suppose to be send.
   *
   * @return mixed
   *    Response array
   */
  public function sendRequest($resource_path = '', $http_method = BrpProps::REQUEST_GET, $data = array()) {
    // Setting variables required by drupal_http_request function.
    $request_url = $this->brpClient->endpoint . $resource_path;
    $options = $this->prepareOptions($http_method, $data);

    $options['verify_ssl'] = 2;

    // Performing request via REST from Drupal to JIRA.
    $response = drupal_http_request($request_url, $options);

    // Handling errors.
    try {
      $this->handleRestError($response);
      $this->malformedDataCheck($response);
    }
    catch (ClientException $exc) {
      // Only show the error to admin users as other users receive a redirect.
      if (user_access('access administration menu')) {
        drupal_set_message(t("Connection errors. Please try again later."), 'error', FALSE);
      }
    }

    // Transforming and returning result.
    $result = drupal_json_decode($response->data);
    $result['code'] = $response->code;
    return $result;
  }

  /**
   * Provides an array with all needed data for HTTP request.
   *
   * @param string $http_method
   *   HTTP request method.
   * @param array $data
   *   Data array that suppose to be send.
   *
   * @return array
   *    Request data array.
   */
  protected function prepareOptions($http_method, $data) {
    $options = array(
      'headers' => $this->prepareHeaders(),
      'method'  => $http_method,
    );
    switch ($http_method) {
      case BrpProps::REQUEST_GET:
        break;

      case BrpProps::REQUEST_POST;
        $request_data = count($data) > 0 ? drupal_json_encode($data) : $data;
        $options['data'] = $request_data;
        break;

      default:
        break;
    }
    return $options;
  }

  /**
   * Provides HTTP request headers definition.
   *
   * @return array
   *   Array with headers.
   */
  protected function prepareHeaders() {
    $headers = array(
      'Accept' => 'application/json',
      'Content-Type' => 'application/json',
    );

    return $headers;
  }

  /**
   * Common helper for reacting to an error from a REST call.
   *
   * Gets the error from the response, logs the error message,
   * and throws an exception, which should be caught by the module making use
   * of the Clients connection API.
   *
   * @param array $response
   *   The REST response data, decoded.
   *
   * @throws ClientException
   */
  protected function handleRestError(&$response) {
    if ($response->code != 200) {
      watchdog('brp_ws_client', 'Error with REST request. Error was code @code
      with error "@error" and message "@message".', array(
        '@code'     => $response->code,
        '@error'    => $response->error,
        '@message'  => isset($response->status_message) ? $response->status_message : '(no message)',
      ));

      BrpTools::logToFile($this->prepareResponseErrorDump($response, BrpProps::RESPONSE_ERROR_DESC));

      throw new ClientException(t("BRP WS Client request error, got message '@message'.", array(
        '@message' => isset($response->status_message) ? $response->status_message : $response->error,
      )), $response->code);
    }
  }

  /**
   * Checking if decoding of the JSON data from http response is done correctly.
   *
   * @param array $response
   *   Response array.
   *
   * @throws ClientException
   */
  protected function malformedDataCheck(&$response) {
    drupal_json_decode($response->data);
    switch (json_last_error()) {
      case JSON_ERROR_NONE:
        $error_message = '';
        break;

      case JSON_ERROR_DEPTH:
        $error_message = 'Maximum stack depth exceeded';
        break;

      case JSON_ERROR_STATE_MISMATCH:
        $error_message = 'Underflow or the modes mismatch';
        break;

      case JSON_ERROR_CTRL_CHAR:
        $error_message = 'Unexpected control character found';
        break;

      case JSON_ERROR_SYNTAX:
        $error_message = 'Syntax error, malformed JSON';
        break;

      case JSON_ERROR_UTF8:
        $error_message = 'Malformed UTF-8 characters, possibly incorrectly encoded';
        break;

      default:
        $error_message = 'Unknown error';
        break;
    }
    // It's possible to have a code 200, but the data could be malformed.
    if ($error_message) {
      BrpTools::logToFile($this->prepareResponseErrorDump($response, $error_message));

      watchdog('brp_ws_client', 'Decoding JSON response error. Error message:
       "@message".', array(
         '@message'  => $error_message,
       )
      );

      throw new ClientException(t("Malformed data error. Data received was: '@data'.",
      array('@data' => $response->data)), $response->code);
    }
  }

  /**
   * Provides error dump array for logging.
   *
   * @param array $response
   *   HTTP response array.
   * @param string $error_desc
   *   Short error description.
   *
   * @return array
   *    Array with error details.
   */
  private function prepareResponseErrorDump($response, $error_desc) {
    $error_date = date('Y_m_d_T_H_i_s');
    $file_name = 'brp_ws_client_error_' . $error_date;

    return array(
      'error_filename' => $file_name,
      'module' => basename(__FILE__),
      'date' => date('Y_m_d_T_H_i_s'),
      'http_response' => $response,
    );
  }

  /**
   * Checks if response is OK.
   *
   * @param array $response
   *    HTTP response array.
   *
   * @return bool
   *    TRUE / FALSE.
   */
  public function checkResponse($response) {
    return isset($response['code'])
      && $response['code'] == BrpProps::RESPONSE_CODE_OK;
  }

  /**
   * Checks service connection status.
   *
   * @return bool
   *    TRUE / FALSE.
   */
  public function checkConnection() {
    $response = $this->sendRequest('', BrpProps::REQUEST_GET);
    return $this->checkResponse($response);
  }

  /**
   * Returns available service endpoints.
   *
   * @return bool|array
   *    Array with endpoints or FALSE.
   */
  public function getServiceEndpoints() {
    $response = $this->sendRequest('', BrpProps::REQUEST_GET);
    if ($this->checkResponse($response)) {
      return $response[BrpProps::SERVICE_LIST];
    }

    return FALSE;
  }

  /**
   * Returns service metadata endpoint list.
   *
   * @return bool|array
   *    Array with metadata enpoints or FALSE.
   */
  public function getServiceMetadataList() {
    $response = $this->sendRequest(BrpProps::META_LIST, BrpProps::REQUEST_GET);
    if ($this->checkResponse($response)) {
      if (isset($response[BrpProps::SERVICE_LIST][BrpProps::SERVICE_SELF])) {
        unset($response[BrpProps::SERVICE_LIST][BrpProps::SERVICE_SELF]);
      }
      return $response[BrpProps::SERVICE_LIST];
    }

    return FALSE;
  }

}
