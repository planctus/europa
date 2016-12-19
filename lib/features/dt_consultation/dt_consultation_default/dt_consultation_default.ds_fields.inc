<?php

/**
 * @file
 * Ds fields defined for dt consultation.
 *
 * This file contains all custom ds fields and related functions.
 */

/**
 * Implements hook_ds_fields_info().
 */
function dt_consultation_default_ds_fields_info($entity_type) {
  $fields = [];

  if ($entity_type == 'node') {
    $fields[$entity_type]['consultation_period'] = [
      'title' => t('Consultation period (opening and closing dates)'),
      'ui_limit' => ['consultation|*'],
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'function' => '_nexteuropa_ds_fields_token_replace',
      'properties' => [
        'value' => '[node:field-core-date-opening:ec_date_j_f_y] - [node:field-core-date-closing:ec_date_j_f_y]',
      ],
    ];
  }

  if (isset($fields[$entity_type])) {
    return [$entity_type => $fields[$entity_type]];
  }
}
