/**
 * @file
 */

CKEDITOR.dialog.add('dt_headings', function (editor) {
    return {
        title: Drupal.t('DT detailed headings generator'),
        minWidth: 400,
        minHeight: 200,
        contents: [{
            title: Drupal.t('Default configuration for dt_headings.'),
            label: Drupal.t('Default'),
            id: 'dt_headings_dialog',
            elements: [
                {
                    type: 'select',
                    id: 'dt_headings_element',
                    label: Drupal.t('Choose an element (h2 by default)'),
                    items: [
                        ['Heading 1', 'h1'],
                        ['Heading 2', 'h2'],
                        ['Heading 3', 'h3'],
                        ['Heading 4', 'h4'],
                        ['Heading 5', 'h5'],
                        ['Heading 6', 'h6']
                    ],
                    default: 'h2',
                    setup: function (element) {
                        if (element) {
                            var tag = element.getName();
                            var elements = ['h1', 'h2', 'h3', 'h4', 'h5', 'h6'];

                            if (elements.indexOf(tag) > -1) {
                                this.setValue(element.getName());
                            }
                        }
                    },
                    commit: function (element) {
                        element.renameNode(this.getValue());
                        element.addClass('dt_group__heading');
                    }
                },
                {
                    type: 'text',
                    id: 'dt_headings_text',
                    label: Drupal.t('Heading text'),
                    validate: function () {
                        var c = CKEDITOR.dialog.getCurrent();
                        var dt_headings_text = c.getValueOf('dt_headings_dialog', 'dt_headings_text');

                        if (!dt_headings_text) {
                            alert(Drupal.t('Heading text field must be filled in.'));
                            return false;
                        }
                        // Check for html tags.
                        return _dt_headers_check_string(dt_headings_text, 'tags');
                    },
                    setup: function (element) {
                        this.setValue(element.getText());
                    },
                    commit: function (element) {
                        element.setText(this.getValue());
                    }
                },
                {
                    type: 'text',
                    id: 'dt_headings_id',
                    label: Drupal.t('Choose an id (must contain at least one character. Spaces are not allowed)'),
                    validate:  function (element) {
                        var c = CKEDITOR.dialog.getCurrent();
                        var dt_headings_id = c.getValueOf('dt_headings_dialog', 'dt_headings_id');
                        var dt_headings_element = c.getValueOf('dt_headings_dialog', 'dt_headings_element');

                        if (!dt_headings_id) {
                            // This is a requirement, there must be an id associated with an h2.
                            if (dt_headings_element == 'h2') {
                                alert(Drupal.t('Id field must be filled in while generating a h2 element'));
                                return false;
                            }
                        }
                        else {
                            // Check tags and validity of the html attribute.
                            return _dt_headers_check_string(dt_headings_id, 'id');
                        }
                    },
                    setup: function (element) {
                        var c = CKEDITOR.dialog.getCurrent();
                        var dt_headings_text = c.getValueOf('dt_headings_dialog', 'dt_headings_text');
                        var dt_headings_element = c.getValueOf('dt_headings_dialog', 'dt_headings_element');

                        if (!element.getAttribute('id') && dt_headings_text && dt_headings_element == 'h2') {
                            var string = dt_headings_text.replace(/\s/g, "");
                            string = string.replace(/[^a-zA-Z0-9]+/g, "");
                            this.setValue(string.toLowerCase());
                        }
                        else {
                            this.setValue(element.getAttribute('id'));
                        }
                    },
                    commit: function (element) {
                        element.setAttribute('id', this.getValue());
                    },
                },
                {
                    type: 'text',
                    id: 'dt_headings_class',
                    hidden: true,
                    label: Drupal.t('Choose one or more classes (Each class must contain at least one character)'),
                    description: 'Insert classes one after the other',
                    validate:  function (element) {
                        var c = CKEDITOR.dialog.getCurrent();
                        var dt_headings_class = c.getValueOf('dt_headings_dialog', 'dt_headings_class');

                        if (dt_headings_class) {
                            // Check tags and validity of the html attribute.
                            return _dt_headers_check_string(dt_headings_class, 'class');
                        }
                    },
                    setup: function (element) {
                        this.setValue(element.getAttribute('class'));
                    },
                    commit: function (element) {
                        element.setAttribute('class', this.getValue());
                    },
                }]
        }],
        onShow: function () {
            var selection = editor.getSelection();
            var element = selection.getStartElement();
            this.element = element;
            this.setupContent(this.element);
        },
        onOk: function () {
            var txt = this.element;
            this.commitContent(txt);
            if (this.insertMode) {
                editor.insertElement(txt);
            }
        },
    };
});

/**
 * Check string for special chars.
 *
 * @param string
 *   string.
 * @param context
 *   string.
 *
 * @returns {boolean}
 */
function _dt_headers_check_string(string, context) {
    if (string != string.replace(/(<([^>]+)>)/ig,"")) {
        alert(Drupal.t('Tags are not allowed here!'));
        return false;
    }

    if (context == 'id' || context == 'class') {
        var regex = new RegExp(/^[A-Za-z]+[\w\-\:\.]*$/);

        // We allow multiple classes.
        if ((context) == 'class') {
            string = string.replace(/\s/g, '');
        }

        if (!regex.test(string)) {
            alert(Drupal.t('Please use only alphanumeric characters, underscore or hyphens'));
            return false;
        }
    }
}
