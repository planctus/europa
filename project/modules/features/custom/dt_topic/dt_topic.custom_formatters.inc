<?php
/**
 * @file
 * dt_topic.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function dt_topic_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'top_task_link';
  $formatter->label = 'top_task_link';
  $formatter->description = 'Linking directly to the value of field_core_top_task_link attached to Top Tasks vocabulary.';
  $formatter->mode = 'php';
  $formatter->field_types = 'taxonomy_term_reference';
  $formatter->code = '$element = array();

foreach ($variables[\'#items\'] as $delta => $item) {
 $term = taxonomy_term_load($item[\'tid\']);
 $link_field = field_get_items(\'taxonomy_term\', $term, \'field_core_top_task_link\');
 $link = field_view_value(\'taxonomy_term\', $term, \'field_core_top_task_link\', $link_field[0]);
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
return $element;
';
  $formatter->fapi = '';
  $export['top_task_link'] = $formatter;

  return $export;
}
