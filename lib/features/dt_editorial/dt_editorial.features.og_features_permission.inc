<?php
/**
 * @file
 * dt_editorial.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function dt_editorial_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:editorial_team:View all unpublished content'.
  $permissions['node:editorial_team:View all unpublished content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'author' => 'author',
      'reviewer' => 'reviewer',
      'translator' => 'translator',
      'translator reviewer' => 'translator reviewer',
      'validator' => 'validator',
    ),
  );

  // Exported og permission: 'node:editorial_team:access group broken links
  // report'.
  $permissions['node:editorial_team:access group broken links report'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'author' => 'author',
      'reviewer' => 'reviewer',
      'translator' => 'translator',
      'translator reviewer' => 'translator reviewer',
      'validator' => 'validator',
    ),
  );

  // Exported og permission: 'node:editorial_team:add user'.
  $permissions['node:editorial_team:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:editorial_team:administer group'.
  $permissions['node:editorial_team:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:editorial_team:approve and deny
  // subscription'.
  $permissions['node:editorial_team:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:editorial_team:manage members'.
  $permissions['node:editorial_team:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:editorial_team:manage organic group
  // translation jobs'.
  $permissions['node:editorial_team:manage organic group translation jobs'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'author' => 'author',
      'reviewer' => 'reviewer',
      'translator' => 'translator',
      'translator reviewer' => 'translator reviewer',
      'validator' => 'validator',
    ),
  );

  // Exported og permission: 'node:editorial_team:manage permissions'.
  $permissions['node:editorial_team:manage permissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:editorial_team:manage roles'.
  $permissions['node:editorial_team:manage roles'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // draft to expired'.
  $permissions['node:editorial_team:moderate content from draft to expired'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // draft to needs_review'.
  $permissions['node:editorial_team:moderate content from draft to needs_review'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'author' => 'author',
      'validator' => 'validator',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // draft to published'.
  $permissions['node:editorial_team:moderate content from draft to published'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'validator' => 'validator',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // draft to request_validation'.
  $permissions['node:editorial_team:moderate content from draft to request_validation'] = array(
    'roles' => array(
      'author' => 'author',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // draft to validated'.
  $permissions['node:editorial_team:moderate content from draft to validated'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'validator' => 'validator',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // expired to draft'.
  $permissions['node:editorial_team:moderate content from expired to draft'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // expired to needs_review'.
  $permissions['node:editorial_team:moderate content from expired to needs_review'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // expired to published'.
  $permissions['node:editorial_team:moderate content from expired to published'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // expired to validated'.
  $permissions['node:editorial_team:moderate content from expired to validated'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // needs_review to draft'.
  $permissions['node:editorial_team:moderate content from needs_review to draft'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // needs_review to expired'.
  $permissions['node:editorial_team:moderate content from needs_review to expired'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // needs_review to published'.
  $permissions['node:editorial_team:moderate content from needs_review to published'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'validator' => 'validator',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // needs_review to request_validation'.
  $permissions['node:editorial_team:moderate content from needs_review to request_validation'] = array(
    'roles' => array(
      'author' => 'author',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // needs_review to validated'.
  $permissions['node:editorial_team:moderate content from needs_review to validated'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'validator' => 'validator',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // published to archived'.
  $permissions['node:editorial_team:moderate content from published to archived'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // published to draft'.
  $permissions['node:editorial_team:moderate content from published to draft'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'author' => 'author',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // published to expired'.
  $permissions['node:editorial_team:moderate content from published to expired'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // published to needs_review'.
  $permissions['node:editorial_team:moderate content from published to needs_review'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'validator' => 'validator',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // published to validated'.
  $permissions['node:editorial_team:moderate content from published to validated'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // request_validation to needs_review'.
  $permissions['node:editorial_team:moderate content from request_validation to needs_review'] = array(
    'roles' => array(
      'validator' => 'validator',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // request_validation to published'.
  $permissions['node:editorial_team:moderate content from request_validation to published'] = array(
    'roles' => array(
      'validator' => 'validator',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // request_validation to validated'.
  $permissions['node:editorial_team:moderate content from request_validation to validated'] = array(
    'roles' => array(
      'validator' => 'validator',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // validated to draft'.
  $permissions['node:editorial_team:moderate content from validated to draft'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'author' => 'author',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // validated to expired'.
  $permissions['node:editorial_team:moderate content from validated to expired'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // validated to needs_review'.
  $permissions['node:editorial_team:moderate content from validated to needs_review'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'validator' => 'validator',
    ),
  );

  // Exported og permission: 'node:editorial_team:moderate content from
  // validated to published'.
  $permissions['node:editorial_team:moderate content from validated to published'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'author' => 'author',
      'reviewer' => 'reviewer',
      'validator' => 'validator',
    ),
  );

  // Exported og permission: 'node:editorial_team:subscribe'.
  $permissions['node:editorial_team:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:editorial_team:subscribe without approval'.
  $permissions['node:editorial_team:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:editorial_team:unsubscribe'.
  $permissions['node:editorial_team:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:editorial_team:update group'.
  $permissions['node:editorial_team:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  return $permissions;
}
