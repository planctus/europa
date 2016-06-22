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
    'draft:expired' => (object) array(
      'from_name' => 'draft',
      'to_name' => 'expired',
      'name' => '',
    ),
    'draft:published' => (object) array(
      'from_name' => 'draft',
      'to_name' => 'published',
      'name' => '',
    ),
    'draft:request_validation' => (object) array(
      'from_name' => 'draft',
      'to_name' => 'request_validation',
      'name' => 'draft-request_validation',
    ),
    'draft:validated' => (object) array(
      'from_name' => 'draft',
      'to_name' => 'validated',
      'name' => '',
    ),
    'expired:draft' => (object) array(
      'from_name' => 'expired',
      'to_name' => 'draft',
      'name' => '',
    ),
    'expired:needs_review' => (object) array(
      'from_name' => 'expired',
      'to_name' => 'needs_review',
      'name' => '',
    ),
    'expired:published' => (object) array(
      'from_name' => 'expired',
      'to_name' => 'published',
      'name' => '',
    ),
    'expired:validated' => (object) array(
      'from_name' => 'expired',
      'to_name' => 'validated',
      'name' => '',
    ),
    'needs_review:expired' => (object) array(
      'from_name' => 'needs_review',
      'to_name' => 'expired',
      'name' => '',
    ),
    'needs_review:request_validation' => (object) array(
      'from_name' => 'needs_review',
      'to_name' => 'request_validation',
      'name' => 'needs_review-request_validation',
    ),
    'published:draft' => (object) array(
      'from_name' => 'published',
      'to_name' => 'draft',
      'name' => '',
    ),
    'published:expired' => (object) array(
      'from_name' => 'published',
      'to_name' => 'expired',
      'name' => '',
    ),
    'published:needs_review' => (object) array(
      'from_name' => 'published',
      'to_name' => 'needs_review',
      'name' => '',
    ),
    'published:validated' => (object) array(
      'from_name' => 'published',
      'to_name' => 'validated',
      'name' => '',
    ),
    'request_validation:needs_review' => (object) array(
      'from_name' => 'request_validation',
      'to_name' => 'needs_review',
      'name' => 'request_validation-needs_review',
    ),
    'request_validation:published' => (object) array(
      'from_name' => 'request_validation',
      'to_name' => 'published',
      'name' => 'request_validation-published',
    ),
    'request_validation:validated' => (object) array(
      'from_name' => 'request_validation',
      'to_name' => 'validated',
      'name' => 'request_validation-validated',
    ),
    'validated:draft' => (object) array(
      'from_name' => 'validated',
      'to_name' => 'draft',
      'name' => '',
    ),
    'validated:expired' => (object) array(
      'from_name' => 'validated',
      'to_name' => 'expired',
      'name' => '',
    ),
    'validated:needs_review' => (object) array(
      'from_name' => 'validated',
      'to_name' => 'needs_review',
      'name' => '',
    ),
  );
  return $items;
}
