<?php

/**
 * @file
 * This file contains helpers to prepare releases.
 */

switch ($argv[1]) {
  // Returns the updated features.
  case 'UpdatedFeatures':
    if (isset($argv[2])) {

      if (empty($argv[3]) || empty($argv[4])) {
        throw new Exception('Required data missing. Please execute the command like this {target, source, version, pr id}: ./getReleaseTickets.sh master release/1.5 1.5 25');
      }

      $matches = [];
      preg_match_all('/\/lib\/(?:modules|features|themes)\/([^\/]*)\/.*/', $argv[2], $matches);
      foreach (array_unique($matches[1]) as $updated) {
        echo '-------- checklist title:' . PHP_EOL;
        echo '[qa] ' . $updated . ' - release ' . $argv[3] . PHP_EOL;
        echo '-------- Ticket body' . PHP_EOL;
        echo 'Checklist: https://webgate.ec.europa.eu/fpfis/wikis/display/MULTISITE/[qa] ' . $updated . ' - release ' . $argv[3] . PHP_EOL;
        echo 'PR: https://github.com/ec-europa/dt_info_reference/pull/' . $argv[3] . PHP_EOL;
        echo 'Project: https://webgate.ec.europa.eu/fpfis/wikis/display/MULTISITE/[COMM] DT Information site' . PHP_EOL;
      }
    }
    break;
}
