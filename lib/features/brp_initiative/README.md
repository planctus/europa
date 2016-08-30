# BRP Initiative feature documentation and notes
 
 BRP Initiative feature was created to collect all of needed elements
 to store process and manipulate BRP Initiative content type.
 
## Custom RULES elements
1. **Conditions**
  - **Check if initiative is up to date** - custom condition which is checking if given
  BRP Initiative node is up to date with remote one. This condition is used as a part of
  "BRP Initiative | Comp. | Check & Update" component
  Condition require two parameters:
    - **initaitve** - BRP Initiative node
    - **remote_initiative** - Remote BRP Initiative provided by BRP Client custom action
2. **Actions**
  - **Create initiative node from given remote initiative** - custom action designed to create
  BRP Initiative node from give remote initiative provided by custom BRP Client action.
    - Action require following parameters:
        - **remote_initiative** - Remote BRP Initiative provided by BRP Client custom action
  - **Update initiative node from given remote initiative** - custom action designed to update
  BRP Initiative based on give remote initiative provided by custom BRP Client action.
  This action is used as a part of "BRP Initiative | Comp. | Check & Update" component.
  After checking if initiative is up to date when modification dates are different it will be
  triggered.
    - Action require following parameters:
        - **initiative** - BRP Initiative node
        - **remote_initiative** - Remote BRP Initiative provided by BRP Client custom action
3. **Components**
  - **BRP Initiative | Comp. | Check & Update** - component build from UI and exported to BRP Initiative
  feature. It was design to achieve one request call for check and update operation. It is
  a part of "BRP Initiative | Update" rule. Main rule is requesting remote initiative and then
  passing it to component which is checking and if needed updating BRP Initiative node.
    - Component require following parameters:
        - **initiative** - BRP Initiative node
        - **remote_initiative** - Remote BRP Initiative provided by BRP Client custom action
  - **BRP Initiative | Comp. | Create** - component build from UI and exported to BRP Initiative
   feature. This component is made to simplify import process. Component will create BRP Initiative
   node based on remote initiative of given ID.
   - Component require following parameters:
       - **initiative_id** - BRP Initiative ID
       
## TODO List:
- Performing mapping of fields via BRP Client integration for BRP Initiative content type.
- Checking if initiative ID field is available in BRP Initiative node
- Finalizing of implementation of create function (brp_initiative_rules_actions.inc - line 113)
- Building and exporting from UI rule for importing initiatives
     - Rule with "BRP Initiative | Comp. | Create" in loop sourced by custom BRP Client action
       "Get all initiatives IDs list"
     - Providing custom event or setting other trigger for created rule
- Finalizing of implementation of update function (brp_initiative_rules_actions.inc - line 141)
  -- fetching mapped fields and performing foreach loop with population of updated values
  -- investigating if we need to have separate field like now - brp_inve_modified_date
- Checking hook_node_view implementation (brp_initiative.module - line 54)
- Hide fields Initiative ID and Initiative modified date from UI
- Write some tests (now we have mock which can be used for that)
- Update this doc with other elements related to this feature 
- Update this doc after your task is done
  
## Developer notes:
- (netlooker) - I've added two new fields: one for ID another one for modification date. Second one
  is used to store latest modification date and based on that we should be able to check weather initiative
  is up to date or not. Maybe someone will find better solution.
