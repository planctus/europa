<?php

/**
 * @file
 * Contains BRP WS Client Custom Rules data types.
 */

/**
 * Implements hook_rules_data_info().
 */
function brp_ws_client_rules_data_info() {
  return [
    'remote_initiative' => [
      'label' => t('Remote initiative'),
      'wrap' => TRUE,
      'group' => t('BRP WS Client'),
      'property info' => _rules_remote_initiative_data_info(),
    ],
    'remote_feedback' => [
      'label' => t('Remote feedback'),
      'wrap' => TRUE,
      'group' => t('BRP WS Client'),
      'property info' => _rules_remote_feedback_data_info(),
    ],
    'remote_report' => [
      'label' => t('Remote report'),
      'wrap' => TRUE,
      'group' => t('BRP WS Client'),
      'property info' => _rules_remote_report_data_info(),
    ],
  ];
}

/**
 * Provides property info for BRP WC Client initiative object.
 *
 * @return array
 *    Property structure array.
 */
function _rules_remote_initiative_data_info() {
  return [
    'createdDate' => [
      'type' => 'text',
      'label' => t('createdDate'),
    ],
    'modifiedDate' => [
      'type' => 'text',
      'label' => t('modifiedDate'),
    ],
    'id' => [
      'type' => 'text',
      'label' => t('id'),
    ],
    'reference' => [
      'type' => 'text',
      'label' => t('reference'),
    ],
    'title' => [
      'type' => 'text',
      'label' => t('title'),
    ],
    'publishedDate' => [
      'type' => 'text',
      'label' => t('publishedDate'),
    ],
    'feedbackPeriod' => [
      'type' => 'text',
      'label' => t('feedbackPeriod'),
    ],
    'endDate' => [
      'type' => 'text',
      'label' => t('endDate'),
    ],
    'dg' => [
      'type' => 'text',
      'label' => t('dg'),
    ],
    'unit' => [
      'type' => 'text',
      'label' => t('unit'),
    ],
    'type' => [
      'type' => 'text',
      'label' => t('type'),
    ],
    'comment' => [
      'type' => 'text',
      'label' => t('comment'),
    ],
    'institution' => [
      'type' => 'text',
      'label' => t('institution'),
    ],
    'authorName' => [
      'type' => 'text',
      'label' => t('authorName'),
    ],
    'authorSurname' => [
      'type' => 'text',
      'label' => t('authorSurname'),
    ],
    'authorMail' => [
      'type' => 'text',
      'label' => t('authorMail'),
    ],
    'authorPhoneNumber' => [
      'type' => 'text',
      'label' => t('authorPhoneNumber'),
    ],
    'committee' => [
      'type' => 'text',
      'label' => t('committee'),
    ],
    'expertGroup' => [
      'type' => 'text',
      'label' => t('expertGroup'),
    ],
    'totalFeedback' => [
      'type' => 'text',
      'label' => t('totalFeedback'),
    ],
    'reportedFeedback' => [
      'type' => 'text',
      'label' => t('reportedFeedback'),
    ],
    'reviewedFeedback' => [
      'type' => 'text',
      'label' => t('reviewedFeedback'),
    ],
    'toBeReviewedFeedback' => [
      'type' => 'text',
      'label' => t('toBeReviewedFeedback'),
    ],
    'firstReportDate' => [
      'type' => 'text',
      'label' => t('firstReportDate'),
    ],
    'status' => [
      'type' => 'text',
      'label' => t('status'),
    ],
    'daysElapsedSinceFirstReport' => [
      'type' => 'text',
      'label' => t('daysElapsedSinceFirstReport'),
    ],
    'code' => [
      'type' => 'text',
      'label' => t('code'),
    ],
  ];
}

/**
 * Provides property info for BRP WC Client feedback object.
 *
 * @return array
 *    Property structure array.
 */
function _rules_remote_feedback_data_info() {
  return [
    'id' => [
      'type' => 'text',
      'label' => t('id'),
    ],
  ];
}

/**
 * Provides property info for BRP WC Client report object.
 *
 * @return array
 *    Property structure array.
 */
function _rules_remote_report_data_info() {
  return [
    'id' => [
      'type' => 'text',
      'label' => t('id'),
    ],
  ];
}
