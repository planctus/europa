<?php
/**
 * @file
 * dt_social_bookmarks.features.uuid_bean.inc
 */

/**
 * Implements hook_uuid_features_default_beans().
 */
function dt_social_bookmarks_uuid_features_default_beans() {
  $beans = array();

  $beans[] = array(
    'label' => 'Social bookmarking - Web Tools',
    'description' => NULL,
    'title' => '',
    'type' => 'webtools',
    'data' => array(
      'view_mode' => 'default',
    ),
    'delta' => 'social-bookmarking---web-tools',
    'view_mode' => 'default',
    'created' => 1447842955,
    'log' => '',
    'uid' => 1,
    'default_revision' => 1,
    'revisions' => array(),
    'vuuid' => '6510e2b5-4ec8-45a4-bb34-a35d11ed6290',
    'uuid' => '3ed860fa-7229-42a7-aaec-4270dcf48b81',
    'field_json_object' => array(
      'und' => array(
        0 => array(
          'value' => '<script type="application/json">
{
	"service": "sbkm",
	"popup": false,
	"icon": true,
	"to": [
		"twitter"
	]
}
</script>',
        ),
      ),
    ),
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'bean',
          'entity_id' => 6,
          'revision_id' => 20,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1447860712,
          'changed' => 1447860712,
        ),
      ),
    ),
  );
  return $beans;
}
