<?php

/**
 * @file
 * Transforms the request and delivers the correct json response.
 *
 * This helps us to test BRP services. This can be used by setting the endpoint
 * to http://{DEVURL.DEV}/sites/all/modules/dev_modules/brp_ws_mock/mock.php/.
 */

// Include required class files.
require_once 'src/Mock.php';

// Set the header.
header('Content-Type: application/json');

// Mock the request.
$request_data = isset(${'_' . $_SERVER['REQUEST_METHOD']}) ? ${'_' . $_SERVER['REQUEST_METHOD']} : '';
$request_path = isset($_SERVER['PATH_INFO']) ? $_SERVER['PATH_INFO'] : '';
$mock = new Mock(getcwd(), $request_path, $_SERVER['REQUEST_METHOD'], $request_data);
print $mock->getResponse();
