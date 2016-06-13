<?php
/**
 * @file
 * Defines the entity refence behaviour implementation.
 */

$plugin = array(
  'title' => t('Title overwrite behavior.'),
  'description' => t('This allows editors to override the node title on a per reference base.'),
  'class' => 'EntityReferenceFieldBehaviorTitleoverwrite',
  'weight' => 10,
  'behavior type' => 'field',
);
