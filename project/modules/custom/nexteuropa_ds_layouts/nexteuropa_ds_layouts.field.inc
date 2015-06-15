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
      'field types' => array('link_field'),
    ),
    'nexteuropa_ds_layouts_formatter_link_button_primary' => array(
      'label' => 'Link button primary',
      'field types' => array('link_field'),
    ),
    'nexteuropa_ds_layouts_formatter_link_button_secondary' => array(
      'label' => 'Link button secondary',
      'field types' => array('link_field'),
    ),
    'nexteuropa_ds_layouts_formatter_link_button_call_for_action' => array(
      'label' => 'Link button call for action',
      'field types' => array('link_field'),
    ),
    'nexteuropa_ds_layouts_formatter_link_button_block' => array(
      'label' => 'Link button block',
      'field types' => array('link_field'),
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
  switch ($display['type']) {
    case 'context_nav_item':
      if (!empty($items)) {
        $element['#prefix'] = '<span class="context-nav__label">' . $instance['label'] . '</span>';
        $element['#prefix'] .= '<div class="context-nav__items">';
        $element['#suffix'] = '</div>';
        switch ($field['type']) {
          case 'entityreference':
            $handler = entityreference_get_selection_handler($field, $instance, $entity_type, $entity);
            foreach ($items as $delta => $item) {

              $label = $handler->getLabel($item['entity']);
              // Note the assignment ($url = ) here is intended to be an assignment.
              if ($uri = entity_uri($field['settings']['target_type'], $item['entity'])) {
                $link = l($label, $uri['path'], $uri['options']);
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
      }
      break;

    case 'nexteuropa_ds_layouts_formatter_link_button_default':
    case 'nexteuropa_ds_layouts_formatter_link_button_primary':
    case 'nexteuropa_ds_layouts_formatter_link_button_secondary':
    case 'nexteuropa_ds_layouts_formatter_link_button_call_for_action':
    case 'nexteuropa_ds_layouts_formatter_link_button_block':
      $formatter = $display['type'];

      foreach ($items as $delta => $item) {
        // Set attribute from formatter settings.
        $item['attributes']['class'] = _nexteuropa_ds_layouts_field_formatter_view_classes($formatter);

        // Call theme function of link module (theme_link_formatter_link_default).
        $element[$delta] = array(
          '#theme' => 'link_formatter_link_default',
          '#element' => $item,
          '#field' => $instance,
          '#display' => $display,
        );
      }
      // Multiple field wrapper.
      if (($field['cardinality'] == -1) && ($formatter != 'nexteuropa_ds_layouts_formatter_link_button_block')) {
        $element['#prefix'] = '<div class="btn-group">';
        $element['#suffix'] = '</div>';
      }
      break;
  }
  return $element;
}
