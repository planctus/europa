<?php
/**
 * @file
 * cwt_team.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cwt_team_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cwt_team_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function cwt_team_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: biographies_by_project_teams.
  $nodequeues['biographies_by_project_teams'] = (object) array(
    'name' => 'biographies_by_project_teams',
    'title' => 'Biographies by Project Teams',
    'subqueue_title' => 'Team %subqueue',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'smartqueue_taxonomy',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 'field_biography_project_team',
    'reverse' => 0,
    'i18n' => 0,
    'types' => array(
      0 => 'biography',
    ),
    'roles' => array(),
    'count' => 0,
    'use_parents' => 0,
  );

  // Exported nodequeues: team_members_by_hierarchy.
  $nodequeues['team_members_by_hierarchy'] = (object) array(
    'name' => 'team_members_by_hierarchy',
    'title' => 'Team members by hierarchy',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'types' => array(
      0 => 'biography',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return (object) $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function cwt_team_image_default_styles() {
  $styles = array();

  // Exported image style: members_responsive_custom_user_min_width_480px_1x.
  $styles['members_responsive_custom_user_min_width_480px_1x'] = array(
    'name' => 'members_responsive_custom_user_min_width_480px_1x',
    'label' => 'members_responsive_custom_user_min_width_480px_1x',
    'effects' => array(
      7 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 80,
          'height' => 80,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: team_cabinet_450x290.
  $styles['team_cabinet_450x290'] = array(
    'name' => 'team_cabinet_450x290',
    'label' => 'Team Cabinet (450x290)',
    'effects' => array(
      24 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 450,
          'height' => 290,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: team_image_1280px.
  $styles['team_image_1280px'] = array(
    'name' => 'team_image_1280px',
    'label' => 'Team image (1280px)',
    'effects' => array(
      21 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 1280,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: team_image_480px.
  $styles['team_image_480px'] = array(
    'name' => 'team_image_480px',
    'label' => 'Team image (480px)',
    'effects' => array(
      9 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 480,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: team_image_960px.
  $styles['team_image_960px'] = array(
    'name' => 'team_image_960px',
    'label' => 'Team image (960px)',
    'effects' => array(
      8 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 960,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: team_members_130x130.
  $styles['team_members_130x130'] = array(
    'name' => 'team_members_130x130',
    'label' => 'Team members (130x130)',
    'effects' => array(
      22 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 130,
          'height' => 130,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: team_members_90x90.
  $styles['team_members_90x90'] = array(
    'name' => 'team_members_90x90',
    'label' => 'Team members (90x90)',
    'effects' => array(
      23 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 90,
          'height' => 90,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: team_members_image_style.
  $styles['team_members_image_style'] = array(
    'name' => 'team_members_image_style',
    'label' => 'Team Members',
    'effects' => array(
      6 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 64,
          'height' => 64,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function cwt_team_node_info() {
  $items = array(
    'team' => array(
      'name' => t('Team'),
      'base' => 'node_content',
      'description' => t('Information about a defined organisational entity that consists of a group of people working within the EC, which strives to fulfill a clearly defined goal.'),
      'has_title' => '1',
      'title_label' => t('Team name'),
      'help' => '',
    ),
    'team_priority' => array(
      'name' => t('Team Priority'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
