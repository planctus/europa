<?php
/**
 * @file
 * dt_contact.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_contact_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_contact|node|contact|form';
  $field_group->group_name = 'group_contact_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'contact';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '2',
    'children' => array(
      0 => 'field_contact_phone_number',
      1 => 'field_contact_postal_mail',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-contact-contact field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_contact_contact|node|contact|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_online_contact|node|contact|form';
  $field_group->group_name = 'group_contact_online_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'contact';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Online Contact',
    'weight' => '1',
    'children' => array(
      0 => 'field_contact_online_contact',
      1 => 'field_contact_link_form',
      2 => 'field_contact_email_address',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-contact-online-contact field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_contact_online_contact|node|contact|form'] = $field_group;

  return $export;
}
