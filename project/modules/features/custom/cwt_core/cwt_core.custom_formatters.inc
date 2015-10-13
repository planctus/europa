<?php
/**
 * @file
 * cwt_core.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function cwt_core_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'taxonomy_term_reference_external_links';
  $formatter->label = 'Taxonomy Departments External Links';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'taxonomy_term_reference';
  $formatter->code = '$element = array();

foreach ($variables[\'#items\'] as $delta => $item) {
  $term = taxonomy_term_load($item[\'tid\']);
  $link_field = field_get_items(\'taxonomy_term\', $term, \'field_department_link\');
  $link = field_view_value(\'taxonomy_term\', $term, \'field_department_link\', $link_field[0]);
  if(!empty($link[\'#element\'][\'url\'])) {
    $element[$delta] = array(
      \'#type\' => \'link\',
      \'#title\' => $term->name,
      \'#href\' => $link[\'#element\'][\'url\'],
    );
  } else {
    $element[$delta] = array(
      \'#markup\' => $term->name,
    );
  }
}
return $element;';
  $formatter->fapi = '';
  $export['taxonomy_term_reference_external_links'] = $formatter;

  return $export;
}
