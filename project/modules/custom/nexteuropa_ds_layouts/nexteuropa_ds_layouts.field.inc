<?php
/**
 * @file
 * Adding BEM related custom field formatters.
 */

/**
 * Implements hook_field_formatter_info().
 */
function nexteuropa_ds_layouts_field_formatter_info() {
  return array(
    'context_nav_item' => array(
      'label' => t('Context nav item'),
      'field types' => array(
        'text',
        'entityreference',
        'link_field',
      ),
    ),
    'nexteuropa_ds_layouts_formatter_link_button_default' => array(
      'label' => 'Link button default',
      'field types' => array(
        'link_field',
        'taxonomy_term_reference',
      ),
    ),
    'nexteuropa_ds_layouts_formatter_link_button_primary' => array(
      'label' => 'Link button primary',
      'field types' => array(
        'link_field',
        'taxonomy_term_reference',
      ),
    ),
    'nexteuropa_ds_layouts_formatter_link_button_secondary' => array(
      'label' => 'Link button secondary',
      'field types' => array(
        'link_field',
        'taxonomy_term_reference',
      ),
    ),
    'nexteuropa_ds_layouts_formatter_link_button_call_for_action' => array(
      'label' => 'Link button call for action',
      'field types' => array(
        'link_field',
        'taxonomy_term_reference',
      ),
    ),
    'nexteuropa_ds_layouts_formatter_link_button_block' => array(
      'label' => 'Link button block',
      'field types' => array(
        'link_field',
        'taxonomy_term_reference',
      ),
    ),
  );
}

/**
 * Helper function to select the right class.
 *
 * @param string $formatter
 *   Formatter name.
 *
 * @return string
 *   Class connected to formatter.
 */
function _nexteuropa_ds_layouts_field_formatter_view_classes($formatter) {
  switch ($formatter) {
    case 'nexteuropa_ds_layouts_formatter_link_button_default':
      return 'btn btn-default';

    case 'nexteuropa_ds_layouts_formatter_link_button_primary':
      return 'btn btn-primary';

    case 'nexteuropa_ds_layouts_formatter_link_button_secondary':
      return 'btn btn-secondary';

    case 'nexteuropa_ds_layouts_formatter_link_button_call_for_action':
      return 'btn btn-ctn';

    case 'nexteuropa_ds_layouts_formatter_link_button_block':
      return 'btn btn-default btn-block';

  }
  return '';
}

/**
 * Implements hook_field_formatter_prepare_view().
 */
function nexteuropa_ds_layouts_field_formatter_prepare_view($entity_type, $entities, $field, $instances, $langcode, &$items, $displays) {
  if ($field['type'] == 'entityreference') {
    $target_ids = array();

    // Collect every possible entity attached to any of the entities.
    foreach ($entities as $id => $entity) {
      foreach ($items[$id] as $delta => $item) {
        if (isset($item['target_id'])) {
          $target_ids[] = $item['target_id'];
        }
      }
    }

    if ($target_ids) {
      $target_entities = entity_load($field['settings']['target_type'], $target_ids);
    }
    else {
      $target_entities = array();
    }

    // Iterate through the fieldable entities again to attach the loaded data.
    foreach ($entities as $id => $entity) {
      $rekey = FALSE;

      foreach ($items[$id] as $delta => $item) {
        // Check whether the referenced entity could be loaded.
        if (isset($target_entities[$item['target_id']])) {
          // Replace the instance value with the term data.
          $items[$id][$delta]['entity'] = $target_entities[$item['target_id']];
          // Check whether the user has access to the referenced entity.
          $has_view_access = (entity_access('view', $field['settings']['target_type'], $target_entities[$item['target_id']]) !== FALSE);
          $has_update_access = (entity_access('update', $field['settings']['target_type'], $target_entities[$item['target_id']]) !== FALSE);
          $items[$id][$delta]['access'] = ($has_view_access || $has_update_access);
        }
        // Otherwise, unset the instance value, since the entity does not exist.
        else {
          unset($items[$id][$delta]);
          $rekey = TRUE;
        }
      }

      if ($rekey) {
        // Rekey the items array.
        $items[$id] = array_values($items[$id]);
      }
    }
  }
}

/**
 * Implements hook_field_formatter_view().
 */
function nexteuropa_ds_layouts_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  if (!empty($items)) {
    switch ($display['type']) {
      case 'context_nav_item':
        $element['#prefix'] = '<span class="context-nav__label">' . $instance['label'] . '</span>';
        $element['#prefix'] .= '<div class="context-nav__items">';
        $element['#suffix'] = '</div>';
        switch ($field['type']) {
          case 'entityreference':
            $handler = entityreference_get_selection_handler($field, $instance, $entity_type, $entity);
            foreach ($items as $delta => $item) {

              $label = $handler->getLabel($item['entity']);
              // Note the assignment ($url = ) here is intended to be an
              // assignment.
              if ($uri = entity_uri($field['settings']['target_type'], $item['entity'])) {
                $link_url = isset($item['entity']->legacy) ? $item['entity']->legacy : $uri['path'];
                $link = l($label, $link_url, $uri['options']);
                $element[$delta] = array(
                  '#markup' => '<span class="context-nav__item">' . $link . '</span>',
                );
              }
              else {
                $element[$delta] = array('#markup' => check_plain($label));
              }
            }
            break;

          case 'link_field':
            foreach ($items as $delta => $item) {
              $link = l($item['title'], $item['url'], array('attributes' => $item['attributes']));
              $element[$delta] = array(
                '#markup' => '<span class="context-nav__item">' . $link . '</span>',
              );
            }
            break;

          case 'text':
            foreach ($items as $delta => $item) {
              $element[$delta] = array(
                '#markup' => '<span class="context-nav__item">' . $item['safe_value'] . '</span>',
              );
            }
            break;
        }
        break;

      case 'nexteuropa_ds_layouts_formatter_link_button_default':
      case 'nexteuropa_ds_layouts_formatter_link_button_primary':
      case 'nexteuropa_ds_layouts_formatter_link_button_secondary':
      case 'nexteuropa_ds_layouts_formatter_link_button_call_for_action':
      case 'nexteuropa_ds_layouts_formatter_link_button_block':
        $formatter = $display['type'];

        switch ($field['type']) {
          case 'link_field':
            foreach ($items as $delta => $item) {
              // Set attribute from formatter settings.
              $item['attributes']['class'] = _nexteuropa_ds_layouts_field_formatter_view_classes($formatter);

              // Call theme function of link module (theme_link_formatter_link_
              // default).
              $element[$delta] = array(
                '#theme' => 'link_formatter_link_default',
                '#element' => $item,
                '#field' => $instance,
                '#display' => $display,
              );
            }
            break;

          case 'taxonomy_term_reference':
            foreach ($items as $delta => $item) {
              $term = taxonomy_term_load($item['tid']);
              $link = isset($term->legacy) ? $term->legacy : url('taxonomy/term/' . $item['tid']);

              $element[$delta] = array(
                '#type' => 'link',
                '#title' => $term->name,
                '#href' => $link,
                '#options' => array(
                  'attributes' => array(
                    'class' => _nexteuropa_ds_layouts_field_formatter_view_classes($formatter),
                  ),
                ),
              );
            }
            break;

        }
        // Multiple field wrapper.
        if (($field['cardinality'] == -1) && ($formatter != 'nexteuropa_ds_layouts_formatter_link_button_block')) {
          $element['#prefix'] = '<div class="btn-group">';
          $element['#suffix'] = '</div>';
        }
        break;
    }
  }
  return $element;
}

/**
 * Implements hook_field_formatter_info_alter().
 */
function nexteuropa_ds_layouts_field_formatter_info_alter(&$info) {
  $info['entityreference_entity_view']['settings'] += array(
    'nexteuropa_ds_layouts_columns' => 'default',
    'nexteuropa_ds_layouts_modifier' => '',
  );
}

/**
 * Implements hook_field_formatter_settings_form_alter().
 */
function nexteuropa_ds_layouts_field_formatter_settings_form_alter(&$settings_form, $context) {
  if ($context['instance']['display'][$context['view_mode']]['type'] == 'entityreference_entity_view') {
    $display = $context['instance']['display'][$context['view_mode']];
    $settings = $display['settings'];
    $settings_form['nexteuropa_ds_layouts_columns'] = array(
      '#type' => 'select',
      '#title' => t('BEM: Listing layout'),
      '#options' => array(
        'default' => t('Default'),
        'two_columns' => t('Two Columns'),
        'three_columns' => t('Three Columns'),
        'row_two' => t('Row with two items'),
        'row_three' => t('Row with three items'),
      ),
      '#default_value' => $settings['nexteuropa_ds_layouts_columns'],
    );
    $settings_form['nexteuropa_ds_layouts_modifier'] = array(
      '#type' => 'textfield',
      '#title' => t('BEM: Modifier'),
      '#default_value' => $settings['nexteuropa_ds_layouts_modifier'],
      '#description' => t('Class names separated by spaces.'),
    );
  }
}

/**
 * Implements hook_field_formatter_settings_summary_alter().
 */
function nexteuropa_ds_layouts_field_formatter_settings_summary_alter(&$summary, $context) {
  if ($context['instance']['display'][$context['view_mode']]['type'] == 'entityreference_entity_view') {
    $display = $context['instance']['display'][$context['view_mode']];
    $settings = $display['settings'];
    if (isset($settings['nexteuropa_ds_layouts_columns'])) {
      if (!empty($summary)) {
        $summary .= '<br />';
      }
      $summary .= t('BEM: List layout') . ': ' . $settings['nexteuropa_ds_layouts_columns'];
    }

    if (isset($settings['nexteuropa_ds_layouts_modifier']) && !empty($settings['nexteuropa_ds_layouts_modifier'])) {
      if (!empty($summary)) {
        $summary .= '<br />';
      }
      $summary .= t('BEM: Modifier') . ': ' . $settings['nexteuropa_ds_layouts_modifier'];
    }
  }
}

/**
 * Implements hook_preprocess_field().
 */
function nexteuropa_ds_layouts_preprocess_field(&$variables) {
  if (isset($variables['element']['#formatter']) && $variables['element']['#formatter'] == 'entityreference_entity_view') {
    $entity_type = $variables['element']['#entity_type'];
    $field_name  = $variables['element']['#field_name'];
    $bundle      = $variables['element']['#bundle'];
    $view_mode   = $variables['element']['#view_mode'];

    // Fetch the instance settings and default display settings.
    $info = field_info_instance($entity_type, $field_name, $bundle);
    $formatter_settings = $info['display']['default']['settings'];
    if (isset($info['display'][$view_mode]['settings'])) {
      $formatter_settings = $info['display'][$view_mode]['settings'] + $formatter_settings;
    }
    // Make the setting available in the field template.
    $variables['nexteuropa_ds_layouts_columns'] = $formatter_settings['nexteuropa_ds_layouts_columns'];
    $variables['nexteuropa_ds_layouts_modifier'] = $formatter_settings['nexteuropa_ds_layouts_modifier'];
  }
}
