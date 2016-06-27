<?php
/**
 * @file
 * dt_editorial.features.workbench_moderation_transitions.inc
 */

/**
 * Implements hook_workbench_moderation_export_transitions().
 */
function dt_editorial_workbench_moderation_export_transitions() {
  $items = array(
    'draft:expired' => array(
      'from_name' => 'draft',
      'to_name' => 'expired',
      'name' => '',
    ),
    'draft:published' => array(
      'from_name' => 'draft',
      'to_name' => 'published',
      'name' => '',
    ),
    'draft:request_validation' => array(
      'from_name' => 'draft',
      'to_name' => 'request_validation',
      'name' => 'draft-request_validation',
    ),
    'draft:validated' => array(
      'from_name' => 'draft',
      'to_name' => 'validated',
      'name' => '',
    ),
    'expired:draft' => array(
      'from_name' => 'expired',
      'to_name' => 'draft',
      'name' => '',
    ),
    'expired:needs_review' => array(
      'from_name' => 'expired',
      'to_name' => 'needs_review',
      'name' => '',
    ),
    'expired:published' => array(
      'from_name' => 'expired',
      'to_name' => 'published',
      'name' => '',
    ),
    'expired:validated' => array(
      'from_name' => 'expired',
      'to_name' => 'validated',
      'name' => '',
    ),
    'needs_review:expired' => array(
      'from_name' => 'needs_review',
      'to_name' => 'expired',
      'name' => '',
    ),
    'needs_review:request_validation' => array(
      'from_name' => 'needs_review',
      'to_name' => 'request_validation',
      'name' => 'needs_review-request_validation',
    ),
    'published:draft' => array(
      'from_name' => 'published',
      'to_name' => 'draft',
      'name' => '',
    ),
    'published:expired' => array(
      'from_name' => 'published',
      'to_name' => 'expired',
      'name' => '',
    ),
    'published:needs_review' => array(
      'from_name' => 'published',
      'to_name' => 'needs_review',
      'name' => '',
    ),
    'published:validated' => array(
      'from_name' => 'published',
      'to_name' => 'validated',
      'name' => '',
    ),
    'request_validation:needs_review' => array(
      'from_name' => 'request_validation',
      'to_name' => 'needs_review',
      'name' => 'request_validation-needs_review',
    ),
    'request_validation:published' => array(
      'from_name' => 'request_validation',
      'to_name' => 'published',
      'name' => 'request_validation-published',
    ),
    'request_validation:validated' => array(
      'from_name' => 'request_validation',
      'to_name' => 'validated',
      'name' => 'request_validation-validated',
    ),
    'validated:draft' => array(
      'from_name' => 'validated',
      'to_name' => 'draft',
      'name' => '',
    ),
    'validated:expired' => array(
      'from_name' => 'validated',
      'to_name' => 'expired',
      'name' => '',
    ),
    'validated:needs_review' => array(
      'from_name' => 'validated',
      'to_name' => 'needs_review',
      'name' => '',
    ),
  );
  return $items;
}
