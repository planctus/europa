<?php

/**
 * @file
 * Contains BRP Initiative Feature custom rules actions.
 */

use Drupal\dt_core_brp\BrpProps;
use Drupal\brp_ws_client\Client\BrpClient;

/**
 * Implements hook_rules_action_info().
 */
function brp_initiative_rules_action_info() {
  $actions = [
    'brp_initiative_create_update' => [
      'label' => t('Create or update initiative node from given remote initiative'),
      'parameter' => [
        'user' => [
          'type' => 'user',
          'label' => t('Content owner of the initiatives'),
          'description' => t('Select the user that will own the initiatives.'),
        ],
        'remote_initiative' => [
          'type' => 'remote_initiative',
          'label' => t('Remote initiative object'),
          'description' => t('Select remote initiative object.'),
        ],
      ],
      'group' => t('BRP Initiative'),
    ],
  ];

  return $actions;
}

/**
 * Custom rule action for creation and update of initiative.
 *
 * @param object $user
 *    Current user.
 * @param object $remote_initiative
 *    BRP WS Client initiative array.
 */
function brp_initiative_create_update($user, $remote_initiative) {
  $integrated_fields = BrpClient::getIntegratedFieldsFromEntity(
    BrpProps::INITIATIVE_CT_ENTITY_TYPE,
    BrpProps::INITIATIVE_CT_BUNDLE
  );
  $data = _brp_initiative_get_field_values($remote_initiative, $integrated_fields);
  _brp_initiative_create_update_entity(
    BrpProps::INITIATIVE_CT_ENTITY_TYPE,
    BrpProps::INITIATIVE_CT_BUNDLE,
    $data,
    $user,
    $remote_initiative
  );
}

/**
 * Helper function for fetching mapped fields values from remote initiative.
 *
 * @param object $remote_initiative
 *    BRP WS Client initiative response array.
 * @param array $integrated_fields
 *    Array with list of BRP WS Client integrated fields.
 *
 * @return array
 *    Array with data (fields mappings and values).
 */
function _brp_initiative_get_field_values($remote_initiative, $integrated_fields) {
  foreach ($integrated_fields as $field_key => $field_data) {
    $integrated_fields[$field_key]['field_value'] = $remote_initiative[$field_data['field_map']];
  }

  return $integrated_fields;
}

/**
 * Helper function responsible for creation and update of initiative entity.
 *
 * @param string $entity_type
 *    Entity type name.
 * @param string $entity_bundle
 *    Entity bundle name.
 * @param array $data
 *    Array with data (fields mappings and values).
 * @param object $user
 *    The user as in owner of the content.
 * @param object $remote_initiative
 *    The complete remote initiative object.
 */
function _brp_initiative_create_update_entity($entity_type, $entity_bundle, $data, $user, $remote_initiative) {
  // By default we tell it is a new entity..
  $is_new = TRUE;

  // Defining variable.
  $message = [
    'message' => '',
  ];

  // If we dont have mapping, we cannot do anything. Also, we need to have the
  // field_brp_inve_id mapped.
  if (!empty($data) && isset($data['field_brp_inve_id'])) {
    // We have to make sure that the ID does not already is used.
    $efq = new EntityFieldQuery();
    $efq->entityCondition('entity_type', $entity_type);
    $efq->fieldCondition('field_brp_inve_id', 'value', $data['field_brp_inve_id']['field_value'], '=');
    $result = $efq->execute();

    if (!isset($result['node'])) {
      // Create instance of entity.
      $entity = entity_create($entity_type, array('type' => $entity_bundle));
    }
    elseif (isset($result['node'])) {
      // Entity load the result.
      $entity = entity_load($entity_type, array_keys($result['node']));
      // We only need the first result (as there is only one).
      $entity = reset($entity);
      // Check the update condition before we continue. If timestamps are the
      // same, we dont need to take action.
      if (brp_initiative_check_initiative_state($entity, $remote_initiative)) {
        return;
      }
      // It's an update.
      $is_new = FALSE;
    }

    // If we have an entity. We should update it.
    if (isset($entity)) {
      // Metadata wrapper.
      $entity_wrapp = entity_metadata_wrapper($entity_type, $entity);

      if ($is_new) {
        // Author. If it is anonymous, we just set it to user 1??
        // @todo: discuss.
        $entity_wrapp->author = 0 !== $user->uid ? $user->uid : 1;

        // Check if the initiative is deleted, don't imported.
        if ($remote_initiative['initiativeStatus'] == "DELETED") {
          return;
        }
        else {
          $entity_wrapp->status = 1;
        }
      }

      // Loop over the mappings.
      foreach ($data as $field_sys_name => $field) {
        // Get field info, as we have to define how we store them.
        $field_info = field_info_field($field_sys_name);

        // Some fields need specific attention when mapping.
        if ($field_info['type'] == 'datestamp') {
          // We use the timestamp.
          $field['field_value'] = strtotime($field['field_value']);
        }
        elseif ($field_info['type'] == 'text_long') {
          // Long text needs an array.
          $field['field_value'] = ['value' => $field['field_value']];
        }
        elseif ($field_info['type'] == 'taxonomy_term_reference' && isset($field_info['settings']['allowed_values'][0]['vocabulary'])) {
          // Load taxonomy by reference field.
          $ttq = new EntityFieldQuery();
          $ttq->entityCondition('entity_type', 'taxonomy_term');
          $ttq->entityCondition('bundle', $field_info['settings']['allowed_values'][0]['vocabulary']);
          // We need conditional field query conditions.
          // @todo: We need to change the subfields to be equal and have one.
          if (field_info_instance('taxonomy_term', 'field_taxonomy_ws_key', $field_info['settings']['allowed_values'][0]['vocabulary'])) {
            $ttq->fieldCondition('field_taxonomy_ws_key', 'value', $field['field_value'], '=');
          }
          elseif (field_info_instance('taxonomy_term', 'field_authority_code', $field_info['settings']['allowed_values'][0]['vocabulary'])) {
            $ttq->fieldCondition('field_authority_code', 'value', $field['field_value'], '=');
          }
          // Execute the query.
          $taxonomy = $ttq->execute();
          // Fetch term and pass the ids to the field.
          if (isset($taxonomy['taxonomy_term']) && is_array($taxonomy['taxonomy_term'])) {
            // Web service key are unique.
            $term = array_values($taxonomy['taxonomy_term']);
            $field['field_value'] = $term[0]->tid;
          }
          else {
            // If we dont have a matching value, we can unset it, so we can
            // still import, but not break the field.
            unset($field['field_value']);
          }
        }

        // We might unset it, so we must double check.
        if (isset($field['field_value'])) {
          // Set the data to the mapped field.
          $entity_wrapp->{$field_sys_name}->set($field['field_value']);
          // When the mapping targets our title field, we should also apply it
          // to the regular title field.
          if ($field_sys_name == 'title_field') {
            $entity_wrapp->title->set($field['field_value']);
          }
        }
      }

      // An existing initiative that was deleted.
      if (!$is_new && $remote_initiative['initiativeStatus'] == "DELETED") {
        $entity_wrapp->status = 0;
      }

      // Save the entity.
      if ($entity_wrapp->save()) {
        if ($is_new) {
          $message['message'] = t('Created initiative %initiative.', ['%initiative' => $data['title_field']['field_value']]);
        }
        else {
          $message['message'] = t('Updated initiative %initiative', ['%initiative' => $data['title_field']['field_value']]);
        }
      }
    }
  }
  else {
    // Notify the user.
    $message = [
      'message' => t('Tried to import initiatives, but no mapping was found, or the minimum configuration is not set.'),
      'type' => 'warning',
    ];
  }

  drupal_set_message($message['message'], isset($message['type']) ? $message['type'] : 'status');
}
