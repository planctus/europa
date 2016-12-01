<?php

/**
 * @file
 * This file contains helpers to prepare releases.
 */

switch ($argv[1]) {
  // Returns the updated features.
  case 'UpdatedFeatures':
    if (isset($argv[2])) {
      $matches = [];
      preg_match_all('/\/lib\/(?:modules|features|themes)\/([^\/]*)\/.*/', $argv[2], $matches);
      foreach (array_unique($matches[1]) as $updated) {
        echo $updated . PHP_EOL;
      }
    }
    break;
}

