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
        echo $updated . PHP_EOL;
      }
      foreach (array_unique($matches[1]) as $updated) {

        $pull_request = 'https://github.com/ec-europa/dt_info_reference/pull/' . urlencode($argv[4]);
        $checklisturl = 'https://webgate.ec.europa.eu/fpfis/wikis/display/MULTISITE/' . urlencode('[qa] ' . $updated . ' - release ' . $argv[3]);
        $projecturl = 'https://webgate.ec.europa.eu/fpfis/wikis/display/MULTISITE/' . urlencode('[COMM] DT Information site');

        echo '-------- checklist title:' . PHP_EOL;
        echo '[qa] ' . $updated . ' - release ' . $argv[3] . PHP_EOL;
        echo '-------- Ticket body' . PHP_EOL;
        echo 'Checklist:' . $checklisturl . PHP_EOL;
        echo 'PR:' . $pull_request . PHP_EOL;
        echo 'Project:' . $projecturl . PHP_EOL;
      }
    }
    break;
}
