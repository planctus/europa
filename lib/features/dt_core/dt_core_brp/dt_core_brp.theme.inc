<?php

/**
 * @file
 * Site user menu - brp site option.
 */

/**
 * Returns HTML for the element.
 *
 * @param mixed $variables
 *   An associative array containing:
 *   - modifier: The modifier applied to the element.
 *
 * @return string
 *   The markup itself.
 */
function theme_site_user_menu($variables) {
  global $user;
  global $base_url;

  $logout_url = $base_url . '/ecaslogout';
  $user_profile = user_load($user->uid);
  $user_wrapper = entity_metadata_wrapper('user', $user_profile);

  $user_fullname = '';
  if (isset($user_wrapper->field_firstname) && !empty($user_wrapper->field_firstname->value())) {
    $user_fullname .= $user_wrapper->field_firstname->value();
  }
  if (isset($user_wrapper->field_lastname) && !empty($user_wrapper->field_lastname->value())) {
    $user_fullname .= (empty($user_fullname) ? '' : ' ') . $user_wrapper->field_lastname->value();
  }
  if (empty($user_fullname)) {
    $user_fullname .= $user_wrapper->name->value();
  }

  $items = [];
  $items[] = [
    'data' => t('Logged in as') . ' ' . $user_fullname,
    'class' => ['site-user-menu__option'],
  ];
  $items[] = [
    'data' => l(t('Logout'), $logout_url),
    'class' => ['site-user-menu__option'],
  ];

  $variables = [
    'items' => $items,
    'attributes' => [
      'class' => [
        'site-user-menu__list',
      ],
    ],
  ];

  return theme('item_list', $variables);
}
