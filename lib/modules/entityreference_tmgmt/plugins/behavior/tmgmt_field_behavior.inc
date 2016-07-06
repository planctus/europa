<?php

/**
 * @file
 * Defines the entity refence behaviour implementation.
 */

$plugin = array(
  'title' => t('TMGMT behavior'),
  'description' => t('Setting this will make sure that the values are copied to translations through TMGMT.'),
  'class' => 'EntityReferenceFieldBehaviorTmgmt',
  'weight' => 8,
  'behavior type' => 'field',
);
