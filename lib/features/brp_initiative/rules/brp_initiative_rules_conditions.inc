<?php

/**
 * @file
 * Contains BRP Initiative Feature custom rules conditions.
 */

/**
 * Implements hook_rules_condition_info().
 */
function brp_initiative_rules_condition_info() {
  return array(
    'brp_initiative_check_initiative_state' => array(
      'label' => t('Check if initiative is up to date'),
      'group' => t('BRP Initiative'),
      'module' => 'brp_initiative',
      'parameter' => array(
        'initiative' => array(
          'type' => 'node',
          'label' => t('Initiative node'),
          'description' => t('Select initiative node.'),
        ),
        'remote_initiative' => array(
          'type' => 'remote_initiative',
          'label' => t('Remote initiative'),
          'description' => t('Select remote initiative.'),
        ),
      ),
    ),
  );
}

/**
 * Custom condition for checking if initiative is up to date.
 *
 * @param object $initiative
 *    Initiative node.
 * @param array $remote_initiative
 *    BRP remote initiative.
 *
 * @return bool
 *   TRUE / FALSE
 */
function brp_initiative_check_initiative_state($initiative, $remote_initiative) {
  $initiative_wrap = entity_metadata_wrapper('node', $initiative);
  $mod_date = $initiative_wrap->field_brp_inve_modified_date->value();
  if (isset($remote_initiative['modifiedDate'])) {
    $remote_mod_date = strtotime($remote_initiative['modifiedDate']);
    return $mod_date == $remote_mod_date ? TRUE : FALSE;
  }

}
