# BRP Web service Client - documentation and notes
  Custom module brp_ws_client provides set of tools to consume BRP Web service resources.

## Code structure and organization
  - **/includes** - folder with files which are integrating Drupal API with custom BRP client functionality.
      - client_entityform_integration.inc - integration for entityform entity.
      - client_fields_integration.inc - integration for Drupal Fields API.
      - client_node_integration.inc - integration for Drupal Node API.
  - **/rules** - folder which is storing all custom RULES module elements.
      - brp_ws_client_rules_actions.inc - custom RULES actions
      - brp_ws_client_rules_conditions.inc - custom RULES conditions
      - brp_ws_client_rules_data_types.inc - custom RULES data types info. Here you can set structure of 
      remote responses like remote initiative. If you need in RULES additional values you can set them here.
      - brp_ws_client_send_feedback.rule - custom RULES rule for sending feedback.
      - brp_ws_client_send_report.rule - custom RULES rule for sending report.
  - **/src** - folder which is storing classes which are providing BRP client functionality.
  - **/src/Client/BrpClient** - main class which extends class provided by "clients" module. This is main
  web service client class which is exposing all of methods and properties which are needed by
  other parts of the project.
  - **/src/Client/BrpClientApi** - engine which is used by BrpClient class. This class is a collection
  of low level calls to BRP web service. Here you will find functions responsible for sending and
  receiving data. If you want to debug HTTP request this is the best place for it.
  - **/src/Exceptions** - extends main Exception class to be aware from were exception is coming from.
  - **/src/FormTools/BrpEntityformFields** - class with methods which are implementing integration BRP client
  with entityform fields. Here you will find methods which are injecting select field values to mapped
  fields from web service. Those values are injected to the entityform submission form.
  - **/src/FormTools/BrpEntityforms** - class with methods which are injecting BRP client settings
  on the entityform entity level. You can select connection which should be used.
  - **/src/FormTools/BrpFields** - class with methods which are injecting fields API settings. Here
  you will find engine for mapping fields from Drupal to the BRP webservice
  - **/src/FormTools/FormToolsFactory** - factory pattern implementation for providing objects which are
  responsible for integration between Entity API and Field API with BRP Client
  - **/src/Tests** - classes which are implementing tests methods according to the client module
  way. You can check how they are working at this url `admin/structure/clients/connections/manage/conn_name/test`.

## Custom callbacks - hook_menu_implementation
####1. **Get attachment** - 'initiative/%/attachment/%
This custom callback is responsible for streaming attachments from BRP web service to the client
browser. There are two arguments which needs to be present:

  - initiative_id - BRP initiative ID
  - attachment_id - BRP initiative attachment ID
  
Callback implementation will check if give initiative ID exist and if given attachment ID belongs
to it. If imitative id is not a number or other conditions are not fulfilled access denied page will
appear


## Custom RULES elements
1. **Conditions**
  - **Check connection status** - custom condition to check whether connection to web service is ok or not.
      - Condition require following parameters:
          - **connection_name** - BRP WS Client connection name.
2. **Actions**
  - **Get all initiatives IDs list** - custom action for fetching all of Initiative IDs form BRP webservice.
      - Action require following parameters:
          - **connection_name** - BRP WS Client connection name.
      - Action provides following providers:
          - **initiatives_id_list** - List of all BRP web service initiatives IDs.
  - **Get initiative by ID** - custom action for fetching BRP initiative by given ID.
      - Action require following parameters:
          - **connection_name** - BRP WS Client connection name.
          - **initiative_id** - BRP initiative ID.
      - Action provides following providers:
          - **remote_initiative** - Remote initiative data which are exposed via custom data type.
          You can process data in further steps of given rule.
  - **Send feedback**
      - Action require following parameters:
          - **ef_submission** - BRP feedback entity form submission.
      - Action provides following providers:
          - **response** - HTTP Response - remote feedback data.
  - **Send report**
      - Action require following parameters:
          - **ef_submission** - BRP report entity form submission.
      - Action provides following providers:
          - **response** - HTTP Response - remote report data.
3. **Custom rules**
  - **BRP Client | Send feedback** - custom rule for sending feedback submission forms.
  - **BRP Client | Send report** - custom rule for sending report submission forms.

##TODO List:

- Write some test (use brp_ws_mock module which is providing mock of BRP web service).
- If mock is not providing correct response please perform dump with BRP client on the test page
and paste it in correct place on mock folder structure. If this is not enough ask Jorge.
- Update this doc after your task is done.