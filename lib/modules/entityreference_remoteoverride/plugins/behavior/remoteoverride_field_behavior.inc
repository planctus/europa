<?php

/**
 * @file
 * Defines the entity refence behaviour implementation.
 */

$plugin = array(
  'title' => t('Remote overwrite behavior.'),
  'description' => t('This allows editors to override a remote (text)field on a per reference base.'),
  'class' => 'EntityReferenceFieldBehaviorRemoteOverride',
  'weight' => 10,
  'behavior type' => 'field',
);
