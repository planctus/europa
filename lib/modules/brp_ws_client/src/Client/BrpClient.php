<?php

namespace Drupal\brp_ws_client\Client;

use Drupal\dt_core_brp\BrpProps;
use Drupal\dt_core_brp\BrpTools;

/**
 * Class for BRP REST Web Service client connections.
 */
class BrpClient extends \clients_connection_base {

  public $fields;

  /**
   * Clients connection configuration form alter.
   *
   * @see clients_connection_form()
   * @see clients_connection_form_submit()
   */
  public function connectionSettingsFormAlter(&$form, &$form_state) {
    // There is no authentication for the moment.
    $form['credentials']['#access'] = FALSE;
  }

  /**
   * Method for checking if BRP REST Web Service is working.
   *
   * @return bool
   *    TRUE / FALSE
   */
  public function checkConnectionStatus() {
    $brp_api = new BrpClientApi($this);
    return $brp_api->checkConnection();
  }

  /**
   * Provides list of available services.
   *
   * @return array|bool
   *    Array with response or FALSE
   */
  public function getServiceList() {
    $brp_api = new BrpClientApi($this);
    return $brp_api->getServiceEndpoints();
  }

  /**
   * Provides list of available service metadata schemas.
   *
   * @return array|bool
   *    Array with response or FALSE
   */
  public function getServiceMetaList() {
    $brp_api = new BrpClientApi($this);
    return $brp_api->getServiceMetadataList();
  }

  /**
   * Provides response for the HTTP GET request sent to the given endpoint.
   *
   * @param string $endpoint
   *   Service endpoint.
   *
   * @return array
   *    Array with response or FALSE
   */
  public function sendGetRequest($endpoint) {
    $brp_api = new BrpClientApi($this);
    $response = $brp_api->sendRequest($endpoint, BrpProps::REQUEST_GET);

    return $brp_api->checkResponse($response) ? $response : FALSE;
  }

  /**
   * Provides response for the HTTP POST request sent to the given endpoint.
   *
   * @param string $endpoint
   *   Service endpoint.
   * @param array $data
   *   Array with data to be send via response.
   *
   * @return array Array with response or FALSE
   *   Array with response or FALSE.
   */
  public function sendPostRequest($endpoint, $data) {
    $brp_api = new BrpClientApi($this);
    $response = $brp_api->sendRequest($endpoint, BrpProps::REQUEST_POST, $data);

    return $brp_api->checkResponse($response) ? $response : FALSE;
  }

  /**
   * Provides array for given descriptor ID from the metadata endpoint.
   *
   * @param string $meta_endpoint
   *    Metadata enpoint to travers.
   * @param string $descriptor_id
   *    Descriptor ID to serach for.
   *
   * @return array|bool
   *    Given descriptor array or FALSE.
   */
  public function getMetaDescriptorsById($meta_endpoint, $descriptor_id) {
    $response = $this->sendGetRequest($meta_endpoint);
    if ($response && isset($response['alps']['descriptors'])) {
      $search_result = BrpTools::recursiveArraySearch($descriptor_id, $response['alps']['descriptors']);
      if (!is_null($search_result)) {
        $desc_index = array_values($search_result)[0];

        return $response['alps']['descriptors'][$desc_index];
      }

      return FALSE;
    }

    return FALSE;
  }

  /**
   * Provides list of fields as object property.
   */
  public function getFields() {
    $cache_tag = 'brp_ws_client_initiative_fields_' . $this->name;
    if ($cache = cache_get($cache_tag)) {
      $fields = $cache->data;
    }
    else {
      $fields['initiative'] = $this->getMetaFieldsInfo(
        BrpProps::META_INITIATIVES,
        BrpProps::META_DESC_INITIATIVE
      );
      $fields['feedback'] = $this->getMetaFieldsInfo(
        BrpProps::META_FEEDBACK,
        BrpProps::META_DESC_FEEDBACK
      );
      $fields['feedback_report'] = $this->getMetaFieldsInfo(
        BrpProps::META_FEEDBACK_REPORT,
        BrpProps::META_DESC_FEEDBACK_REPORT
      );

      cache_set($cache_tag, $fields, 'cache', time() + BrpProps::CONNECTION_SETTINGS_CACHE);
    }

    $this->fields = array(
      'initiative' => $fields['initiative'],
      'feedback' => $fields['feedback'],
      'feedback_report' => $fields['feedback_report'],
    );

  }

  /**
   * Provides list of all initiatives IDs which are available.
   *
   * @return array|bool
   *    Array with all of initiatives IDs.
   */
  public function getAllInitiativesIds() {
    $initiatives_ids = array();

    $response = $this->sendGetRequest(BrpProps::SERVICE_INITIATIVES);
    if ($response['code'] == 200 && $response['page']['totalElements'] > 0) {
      for ($i = 0; $i < $response['page']['totalPages']; $i++) {
        $response = $this->sendGetRequest(BrpProps::SERVICE_INITIATIVES
          . "?page=$i&size="
          . BrpProps::SERVICE_INITIATIVES_DEFAULT_SIZE);
        foreach ($response['_embedded']['initiativesV1'] as $initative) {
          $initiatives_ids[] = $initative['id'];
        }
      }

      return $initiatives_ids;
    }

    return FALSE;
  }

  /**
   * Provides initiative data array.
   *
   * @param int $initiative_id
   *    Initiative ID.
   *
   * @return array|bool
   *    Array with initiative data or FALSE;
   */
  public function getInitiativeById($initiative_id) {
    $response = $this->sendGetRequest(BrpProps::SERVICE_INITIATIVES . '/' . $initiative_id);
    if ($response['code'] == 200) {
      return $response;
    }

    return FALSE;
  }

  /**
   * Provides list of fields for initiative.
   *
   * @return array
   *    Fields array for initiative.
   */
  private function getMetaFieldsInfo($meta_endpoint, $meta_descriptor) {
    $fields = array();
    $meta_desc = $this->getMetaDescriptorsById(
      $meta_endpoint,
      $meta_descriptor
    );

    if ($meta_desc) {
      $meta_fields = $meta_desc['descriptors'];
      foreach ($meta_fields as $value) {
        if ($options = $this->extractOptionsFromDescriptor($value)) {
          $fields['select'][$value['name']] = $value['name'];
          $fields['select_options'][$value['name']] = $options;
        }
        else {
          $fields['text'][$value['name']] = $value['name'];
        }
      }
    }

    return $fields;
  }

  /**
   * Helper function to extract options form given descriptor array.
   *
   * @param array $desc_array
   *    Descriptor item array.
   *
   * @return array|bool
   *    Returns array with options or FALSE.
   */
  private function extractOptionsFromDescriptor($desc_array) {
    if (isset($desc_array['doc'])) {
      $flat_options = str_replace(' ', '', $desc_array['doc']['value']);
      $flat_options = explode(',', $flat_options);
      foreach ($flat_options as $option) {
        $options[$option] = $option;
      }

      return $options;
    }

    return FALSE;
  }

  /**
   * Provides list of fields which are integrated with BRP WS Client.
   *
   * @param string $entity_type
   *    Entity type name.
   * @param string $entity_bundle
   *    Entity bundle name.
   *
   * @return array
   *    BRP WS Client integrated fields array.
   */
  public static function getIntegratedFieldsFromEntity($entity_type, $entity_bundle) {
    $field_instances = field_info_instances($entity_type, $entity_bundle);
    $integrated_fields = array();
    foreach ($field_instances as $key => $field_instance) {
      if (isset($field_instance['settings']['brp_ws_fields'])
        && $field_instance['settings']['brp_ws_fields']['field_map']
      ) {
        $integrated_fields[$key] = $field_instance['settings']['brp_ws_fields'];
      }
    }

    return $integrated_fields;
  }

  /**
   * Creates request data array according to give specification.
   *
   * @param object $ef_submission
   *    Entityform submission object.
   *
   * @return array
   *    Array with prepared request data.
   */
  public static function prepareRequestData($ef_submission) {
    $request_data = array();

    // Get mapped fields collection.
    switch ($ef_submission->type) {
      case 'brp_initiatives_feedback':
        $mapped_fields = self::getIntegratedFieldsFromEntity(
          BrpProps::FEEDBACK_FORM_ENTITY_TYPE,
          BrpProps::FEEDBACK_FORM_BUNDLE
        );
        break;

      case 'brp_initiatives_feedback_report':
        $mapped_fields = self::getIntegratedFieldsFromEntity(
          BrpProps::FEEDBACK_REPORT_FORM_ENTITY_TYPE,
          BrpProps::FEEDBACK_REPORT_FORM_BUNDLE
        );
        break;
    }

    $ef_sub_wrap = $ef_submission->wrapper();
    foreach ($mapped_fields as $field_name => $field_data) {
      if ($ef_sub_wrap->{$field_name}->value()) {
        $request_data[$field_data['field_map']] = $ef_sub_wrap->{$field_name}->value();
      }

      switch ($field_data['field_map']) {
        case 'publication':
          if ($field_data['field_map'] == 'publication' && $ef_sub_wrap->{$field_name}->value()) {
            $request_data[$field_data['field_map']] = 'WITHINFO';
          }
          else {
            $request_data[$field_data['field_map']] = 'ANONYMOUS';
          }
          break;

        case 'initiative':
          $request_data[$field_data['field_map']] = BrpProps::FEEDBACK_INITIATIVE_PATH . $ef_sub_wrap->{$field_name}->value();
          break;

        case 'feedback':
          if ($ef_submission->bundle() == BrpProps::FEEDBACK_REPORT_FORM_BUNDLE) {
            $request_data[$field_data['field_map']] = BrpProps::REPORT_FEEDBACK_PATH . $ef_sub_wrap->{$field_name}->value();
          }
          else {
            $request_data[$field_data['field_map']] = $ef_sub_wrap->{$field_name}->value();
          }
          break;
      }
    }

    return $request_data;
  }

}
