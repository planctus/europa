<?php

/**
 * @file
 * Contains image styles related configuration and helpers.
 */

/**
 * Implements hook_image_default_styles().
 */
function dt_gallery_image_default_styles() {
  $styles = [];

  // Our default sizes.
  $column_width = 190;
  $column_height = 370;

  foreach (_dt_gallery_get_image_sizes() as $columns) {
    // For each of the grids we generate an image style. We create a default and
    // a retina style.
    // Default:
    $styles['gallery_grid_' . $columns] = [
      'label' => 'Gallery Grid - ' . $columns,
      'effects' => [
        1 => [
          'name' => 'image_scale',
          'data' => [
            'width' => '',
            'height' => $column_height,
            'upscale' => 0,
            'retinafy' => 0,
          ],
          'weight' => 1,
        ],
        2 => [
          'name' => 'image_scale_and_crop',
          'data' => [
            'width' => $column_width * $columns,
            'height' => $column_height,
            'retinafy' => 0,
          ],
          'weight' => 2,
        ],
      ],
    ];
    // Retina:
    $styles['gallery_grid_2x_' . $columns] = $styles['gallery_grid_' . $columns];
    $styles['gallery_grid_2x_' . $columns]['label'] = $styles['gallery_grid_' . $columns]['label'] . ' - Retina';
    foreach ($styles['gallery_grid_2x_' . $columns]['effects'] as &$effect) {
      $effect['data']['retinafy'] = TRUE;
    }
  }

  // Also add the mobile style.
  $styles['gallery_grid_phone'] = [
    'label' => 'Gallery Grid - phone',
    'effects' => [
      1 => [
        'name' => 'image_scale',
        'data' => [
          'width' => '',
          'height' => 250,
          'upscale' => 0,
          'retinafy' => 0,
        ],
        'weight' => 1,
      ],
      2 => [
        'name' => 'image_scale_and_crop',
        'data' => [
          'width' => 380,
          'height' => 250,
          'retinafy' => 0,
        ],
        'weight' => 2,
      ],
    ],
  ];
  // Retina:
  $styles['gallery_grid_2x_phone'] = $styles['gallery_grid_phone'];
  $styles['gallery_grid_2x_phone']['label'] = $styles['gallery_grid_phone']['label'] . ' - Retina';
  foreach ($styles['gallery_grid_2x_phone']['effects'] as &$effect) {
    $effect['data']['retinafy'] = TRUE;
  }

  // Create image styles for gallery detail view.
  $europa_breakpoints = breakpoints_breakpoint_load_all_active('europa');
  $dimensions = [
    'mobile' => [320, 240],
    'narrow' => [480, 360],
    'medium' => [768, 576],
    'normal' => [992, 744],
    'wide' => [2048, 1536],
  ];

  foreach ($europa_breakpoints as $breakpoint) {
    if ($breakpoint->source == 'europa' && isset($dimensions[$breakpoint->name])) {
      $styles['gallery_full_' . $breakpoint->name] = [
        'label' => 'Gallery Full - ' . $breakpoint->name,
        'effects' => [
          1 => [
            'name' => 'image_scale',
            'data' => [
              'width' => $dimensions[$breakpoint->name][0],
              'height' => $dimensions[$breakpoint->name][1],
              'upscale' => 0,
              'retinafy' => 0,
            ],
            'weight' => 1,
          ],
        ],
      ];
      $styles['gallery_full_2x_' . $breakpoint->name] = $styles['gallery_full_' . $breakpoint->name];
      $styles['gallery_full_2x_' . $breakpoint->name]['label'] = $styles['gallery_full_' . $breakpoint->name]['label'] . ' -  Retina';
      $styles['gallery_full_2x_' . $breakpoint->name]['effects'][1]['data']['retinafy'] = TRUE;
    }
  }

  return $styles;
}

/**
 * Defines the default picture mappings.
 *
 * Instead of exporting them, we use the same generation functions as we do for
 * the image styles. This way, they are always kept in sync.
 *
 * @param string $op
 *   The operation, save or delete.
 */
function _dt_gallery_get_picture_presets($op = 'save') {
  $europa_breakpoints = breakpoints_breakpoint_load_all_active('europa');
  // Gallery full item picture mapping.
  if ($op == 'save') {
    $picture_mapping = new PictureMapping();
    $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
    $picture_mapping->api_version = 2;
    $picture_mapping->label = 'Gallery full';
    $picture_mapping->machine_name = 'gallery_full';
    $picture_mapping->breakpoint_group = 'europa';
    $mapping = [];
    foreach ($europa_breakpoints as $name => $breakpoint) {
      if ($breakpoint->source == 'europa') {
        $mapping[$name] = [
          '1x' => [
            'mapping_type' => 'image_style',
            'image_style' => 'gallery_full_' . $breakpoint->name,
          ],
          '2x' => [
            'mapping_type' => 'image_style',
            'image_style' => 'gallery_full_2x_' . $breakpoint->name,
          ],
        ];
      }
    }
    $picture_mapping->mapping = $mapping;
    $picture_mapping->save();
  }
  elseif ($op == 'delete') {
    ctools_export_crud_delete('picture_mapping', 'gallery_full');
  }

  // Gallery grid picture mapping.
  foreach (_dt_gallery_get_image_sizes() as $columns) {
    if ($op == 'save') {
      $picture_mapping = new PictureMapping();
      $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
      $picture_mapping->api_version = 2;
      $picture_mapping->label = 'Gallery responsive - grid ' . $columns;
      $picture_mapping->machine_name = 'gallery_responsive_grid_' . $columns;
      $picture_mapping->breakpoint_group = 'europa';
      $picture_mapping->mapping = array(
        'breakpoints.theme.europa.mobile' => array(
          '1x' => array(
            'mapping_type' => 'image_style',
            'image_style' => 'gallery_grid_phone',
          ),
          '2x' => array(
            'mapping_type' => 'image_style',
            'image_style' => 'gallery_grid_2x_phone',
          ),
        ),
        'breakpoints.theme.europa.narrow' => array(
          '1x' => array(
            'mapping_type' => 'image_style',
            'image_style' => 'gallery_grid_phone',
          ),
          '2x' => array(
            'mapping_type' => 'image_style',
            'image_style' => 'gallery_grid_2x_phone',
          ),
        ),
        'breakpoints.theme.europa.medium' => array(
          '1x' => array(
            'mapping_type' => 'image_style',
            'image_style' => 'gallery_grid_4',
          ),
          '2x' => array(
            'mapping_type' => 'image_style',
            'image_style' => 'gallery_grid_2x_4',
          ),
        ),
        'breakpoints.theme.europa.normal' => array(
          '1x' => array(
            'mapping_type' => 'image_style',
            'image_style' => 'gallery_grid_' . $columns,
          ),
          '2x' => array(
            'mapping_type' => 'image_style',
            'image_style' => 'gallery_grid_2x_' . $columns,
          ),
        ),
        'breakpoints.theme.europa.wide' => array(
          '1x' => array(
            'mapping_type' => 'image_style',
            'image_style' => 'gallery_grid_' . $columns,
          ),
          '2x' => array(
            'mapping_type' => 'image_style',
            'image_style' => 'gallery_grid_2x_' . $columns,
          ),
        ),
      );
      $picture_mapping->save();
    }
    elseif ($op == 'delete') {
      ctools_export_crud_delete('picture_mapping', 'gallery_responsive_grid_' . $columns);
    }
  }
}

/**
 * Helper function to get available grids.
 *
 * @return array
 *   Array of possible sizes.
 */
function _dt_gallery_get_image_sizes() {
  return [2, 3, 4, 5, 6, 7, 8, 12];
}
