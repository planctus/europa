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

/*
 * Remove Options from the Table Dialog.
 */
function _removeCkeditorTableOptions(dialogDefinition) {
    var infoTab = dialogDefinition.getContents('info');

    // Remove unwanted options.
    infoTab.remove('txtBorder');
    infoTab.remove('cmbAlign');
    infoTab.remove('txtWidth');
    infoTab.remove('txtHeight');
    infoTab.remove('txtCellSpace');
    infoTab.remove('txtCellPad');

    // Change default Table Headers options to row.
    infoTab.get('selHeaders')['default'] = 'row';
    // Remove the option None.
    infoTab.get('selHeaders')['items'].shift();
}
