<?php
/**
 * @file
 * Additional behavior for the entityrefence field.
 */

/**
 * Class EntityReferenceFieldBehaviorTitleoverwrite.
 */
class EntityReferenceFieldBehavior_Titleoverwrite extends EntityReference_BehaviorHandler_Abstract {

  /**
   * Overwrite the schema.
   */
  public function schema_alter(&$schema, $field) {
    $schema['columns']['title_override'] = array(
      'type' => 'varchar',
      'description' => 'Title override',
      'length' => 255,
      'not null' => FALSE,
    );
  }

  /**
   * Generate a settings form for this handler.
   */
  public function settingsForm($field, $instance) {
    $form['overwrite_title_mandatory'] = array(
      '#type' => 'checkbox',
      '#title' => t('Make the title field mandatory?'),
      '#description' => t('You could make this mandatory if you want the editor to be forced to set a title.'),
    );
    return $form;
  }

}
