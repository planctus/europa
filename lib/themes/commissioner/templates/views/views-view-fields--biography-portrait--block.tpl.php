<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * Variables:
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field.
 *     Do not use var_export to dump this object, as it can't handle recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 *
 * Fields can be rendered as $fields['field_biography_portrait_2']
 */
?>

<?php print $fields['field_biography_portrait']->wrapper_prefix; ?>
	<?php print $fields['field_biography_portrait']->content; ?>
<?php print $fields['field_biography_portrait']->wrapper_suffix; ?>
<?php print $fields['field_biography_av_portal']->content; ?>

<div class="modal fade" id="hi-res-picture" tabindex="-1" role="dialog" aria-hidden="true">
	<div class="modal-dialog">
		<div class="modal-content">
			<div class="modal-header">
				<a href="#" class="close" data-dismiss="modal"><span class="close-text" aria-hidden="true"><?php print t('Close'); ?></span><span aria-hidden="true">&times;</span></a>
			</div>
			<div class="modal-body">
				<?php print $fields['field_biography_portrait_2']->content; ?>
				<?php print $fields['field_biography_portrait_1']->content; ?>
			</div>
		</div>
	</div>
</div>
