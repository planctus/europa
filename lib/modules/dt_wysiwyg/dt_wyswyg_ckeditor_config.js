/**
 * @file
 * DT wysiwyg overrides ckeditor related table dialogs and options.
 */

// Remove the cell properties plugin.
CKEDITOR.config.menu_groups = 'clipboard,form,tablecell,tablerow,tablecolumn,table,anchor,link,image,flash,' +
    'checkbox,radio,textfield,hiddenfield,imagebutton,button,select,textarea,div';

CKEDITOR.on('dialogDefinition', function (event) {

    // Get the dialog name.
    var dialogName = event.data.name;

    if (dialogName == 'table' || dialogName == 'tableProperties') {
        _removeCkeditorTableOptions(event.data.definition);
    }
});

/**
 * Clean unwanted Ids from paragraphs.
 */
CKEDITOR.on('instanceReady', function (CK) {
    var editor = CK.editor;
    _setEvents(editor);
});

function _setEvents(editor) {
    editor.on('blur', function (e) {
        if (editor.checkDirty()) {
            var content = editor.getData();
            // Remove Ids from paragraph.
            editor.setData(content.replace(/<(p)[^>]+>/ig, '<$1>'));
        }
    });
}

/*
 * Remove Options from the Table Dialog.
 */
function _removeCkeditorTableOptions(dialogDefinition) {
    var infoTab = dialogDefinition.getContents('info');

    // Remove unwanted options.
    infoTab.remove('txtBorder');
    infoTab.remove('txtHeight');
    infoTab.remove('txtCellSpace');
    infoTab.remove('txtCellPad');

    // Change default Table Headers options to row.
    infoTab.get('selHeaders')['default'] = 'row';
    // Remove the option None.
    infoTab.get('selHeaders')['items'].shift();

    var align = infoTab.get('cmbAlign');
    align['default'] = 'left';
    align['hidden'] = true;

    // Set with to 100% by default and hide the field.
    var tabWidth = infoTab.get('txtWidth');
    tabWidth['default'] = '100%';
    tabWidth['hidden'] = true;

    // Get the advanced dialog object.
    var advTab = dialogDefinition.getContents('advanced');

    // Add our component class.
    var styleClassesField = advTab.get('advCSSClasses');
    styleClassesField['default'] = 'table-responsive';
    styleClassesField['hidden'] = true;

}
