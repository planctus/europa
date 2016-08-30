<?php

/**
 * @file
 * Contains BRP WS Client Custom Rules data types.
 */

/**
 * Implements hook_rules_data_info().
 */
function brp_ws_client_rules_data_info() {
  return array(
    'remote_initiative' => array(
      'label' => t('Remote initiative'),
      'wrap' => TRUE,
      'group' => t('BRP WS Client'),
      'property info' => _rules_remote_initiative_data_info(),
    ),
    'remote_feedback' => array(
      'label' => t('Remote feedback'),
      'wrap' => TRUE,
      'group' => t('BRP WS Client'),
      'property info' => _rules_remote_feedback_data_info(),
    ),
    'remote_report' => array(
      'label' => t('Remote report'),
      'wrap' => TRUE,
      'group' => t('BRP WS Client'),
      'property info' => _rules_remote_report_data_info(),
    ),
  );
}

/**
 * Provides property info for BRP WC Client initiative object.
 *
 * @return array
 *    Property structure array.
 */
function _rules_remote_initiative_data_info() {
  return array(
    'createdDate' => array(
      'type' => 'text',
      'label' => t('createdDate'),
    ),
    'modifiedDate' => array(
      'type' => 'text',
      'label' => t('modifiedDate'),
    ),
    'id' => array(
      'type' => 'text',
      'label' => t('id'),
    ),
    'reference' => array(
      'type' => 'text',
      'label' => t('reference'),
    ),
    'title' => array(
      'type' => 'text',
      'label' => t('title'),
    ),
    'publishedDate' => array(
      'type' => 'text',
      'label' => t('publishedDate'),
    ),
    'feedbackPeriod' => array(
      'type' => 'text',
      'label' => t('feedbackPeriod'),
    ),
    'endDate' => array(
      'type' => 'text',
      'label' => t('endDate'),
    ),
    'dg' => array(
      'type' => 'text',
      'label' => t('dg'),
    ),
    'unit' => array(
      'type' => 'text',
      'label' => t('unit'),
    ),
    'type' => array(
      'type' => 'text',
      'label' => t('type'),
    ),
    'comment' => array(
      'type' => 'text',
      'label' => t('comment'),
    ),
    'institution' => array(
      'type' => 'text',
      'label' => t('institution'),
    ),
    'authorName' => array(
      'type' => 'text',
      'label' => t('authorName'),
    ),
    'authorSurname' => array(
      'type' => 'text',
      'label' => t('authorSurname'),
    ),
    'authorMail' => array(
      'type' => 'text',
      'label' => t('authorMail'),
    ),
    'authorPhoneNumber' => array(
      'type' => 'text',
      'label' => t('authorPhoneNumber'),
    ),
    'committee' => array(
      'type' => 'text',
      'label' => t('committee'),
    ),
    'expertGroup' => array(
      'type' => 'text',
      'label' => t('expertGroup'),
    ),
    'totalFeedback' => array(
      'type' => 'text',
      'label' => t('totalFeedback'),
    ),
    'reportedFeedback' => array(
      'type' => 'text',
      'label' => t('reportedFeedback'),
    ),
    'reviewedFeedback' => array(
      'type' => 'text',
      'label' => t('reviewedFeedback'),
    ),
    'toBeReviewedFeedback' => array(
      'type' => 'text',
      'label' => t('toBeReviewedFeedback'),
    ),
    'firstReportDate' => array(
      'type' => 'text',
      'label' => t('firstReportDate'),
    ),
    'status' => array(
      'type' => 'text',
      'label' => t('status'),
    ),
    'daysElapsedSinceFirstReport' => array(
      'type' => 'text',
      'label' => t('daysElapsedSinceFirstReport'),
    ),
    'code' => array(
      'type' => 'text',
      'label' => t('code'),
    ),
  );
}

/**
 * Provides property info for BRP WC Client feedback object.
 *
 * @return array
 *    Property structure array.
 */
function _rules_remote_feedback_data_info() {
  return array(
    'id' => array(
      'type' => 'text',
      'label' => t('id'),
    ),
  );
}

/**
 * Provides property info for BRP WC Client report object.
 *
 * @return array
 *    Property structure array.
 */
function _rules_remote_report_data_info() {
  return array(
    'id' => array(
      'type' => 'text',
      'label' => t('id'),
    ),
  );
}
