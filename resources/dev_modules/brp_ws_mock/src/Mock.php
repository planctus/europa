<?php

/**
 * @file
 * Contains the Mock handler.
 */

/**
 * Class provides mock of BRP REST Web Service.
 */
class Mock {
  const BRP_MOCK_API_DATA_DIR = '/mock_data/brp_api/';
  const BRP_MOCK_API_ROOT_FILE = 'root';
  private $mockDataDir;
  private $servicePath;
  private $paramsPath;
  private $requestMethod;

  /**
   * BrpMock object constructor.
   *
   * @param string $service
   *    Name of endpoint/service.
   * @param string $request_method
   *    Type of request.
   * @param array $parameters
   *    Array with request parameters.
   * @param array $request_data
   *    Array with request data.
   */
  public function __construct($mock_root, $service, $request_method, $parameters = [], $request_data = []) {
    $this->setMockDataDir($mock_root);
    $this->setServicePath($service);
    $this->setParamsPath($parameters);
    $this->setRequestMethod($request_method);
  }

  /**
   * Provides HTTP response.
   */
  public function getResponse() {
    return $this->processRequest();
  }

  /**
   * Setting up mock data directory path.
   *
   * @param string $mock_root
   *   The path of the mock root.
   */
  private function setMockDataDir($mock_root) {
    $this->mockDataDir = $mock_root . self::BRP_MOCK_API_DATA_DIR;
  }

  /**
   * Provides path to mock data directory.
   *
   * @return string
   *    Path to directory with mock data.
   */
  private function getMockDataDir() {
    return $this->mockDataDir;
  }

  /**
   * Setting up service path.
   *
   * @param array $service
   *    Array with arguments which were passed to hook_menu.
   */
  private function setServicePath($service) {
    $this->servicePath = (substr($service, 0, 1) == '/') ? substr_replace($service, '', 0, 1) : $service;
  }

  /**
   * Provides path to the service directory.
   *
   * @return string
   *    Path to service directory.
   */
  private function getServicePath() {
    return $this->servicePath;
  }

  /**
   * Setting up HTTP request method.
   *
   * @param string $request_method
   *    HTTP request method.
   */
  private function setRequestMethod($request_method) {
    $this->requestMethod = $request_method;
  }

  /**
   * Provides HTTP request method.
   *
   * @return string
   *    HTTP request method.
   */
  private function getRequestMethod() {
    return $this->requestMethod;
  }

  /**
   * Setting up HTTP request parameters path.
   *
   * @param array $parameters
   *    Array of parameters sent in HTTP request.
   */
  private function setParamsPath($parameters) {
    $this->paramsPath = '';
    if (count($parameters) > 0) {
      foreach ($parameters as $parm_name => $parm_value) {
        $this->paramsPath .= '&' . $parm_name . '=' . $parm_value;
      }
      // Changing first occurrence of '&' in to '?'.
      $pos = strpos($this->paramsPath, '&');
      if ($pos !== FALSE) {
        $this->paramsPath = substr_replace($this->paramsPath, '?', $pos, strlen('&'));
      }
    }
  }

  /**
   * Provides string form merged HTTP request parameters.
   *
   * @return string
   *    HTTP request method.
   */
  private function getParamsPath() {
    return $this->paramsPath;
  }

  /**
   * Main function for routing and processing HTTP requests.
   *
   * @return string
   *    HTTP response content from JSON file.
   */
  private function processRequest() {
    switch ($this->getRequestMethod()) {
      case 'GET':
        return $this->getFileContent();

      case 'POST':
        return file_get_contents($this->getMockDataDir() . $this->getServicePath() . '/POST.json');
    }

    return FALSE;
  }

  /**
   * Helper function for fetching given JSON file content.
   *
   * @return string
   *    Response content from file.
   */
  private function getFileContent() {
    $file_name = $this->getMockDataDir() . $this->getServicePath() . $this->getParamsPath() . '.json';

    if (!file_exists($file_name)) {

      // Check if we get an ID match.
      if (preg_match('/(\w*)\/(\d{1,})(?:\/$|$)/', $this->getServicePath(), $id)) {
        $data = file_get_contents($this->getMockDataDir() . '/' . $id[1] . '/default.json');
        return str_replace('##REPLACEID##', $id[2], $data);
      }

      // Fallback file.
      $file_name = $this->getMockDataDir() . $this->getServicePath() . 'default.json';
    }

    return file_get_contents($file_name);
  }

}
