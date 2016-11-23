# BRP Mock
## Usage

Before running the tests, you need to enable the mock module. This can be done by running the phing
target:
`./bin/phing enable-mocks`

To use the mock, you can tag your tests with `@brpMock` this will make sure that the context gets
altered before running the tests, and cleans up after itself afterwards.

There are 2 feedbacks that can be used for testing:
* ARMEN TEST ON ACCEPTANCE
    * Feedback open
    * on `/initiatives` page 1
    * Contains no feedback
* Clean air and water quality improvement
    * on `/initiatives` page 2
    * Contains 2 feedback
        * 1 reported
        * 1 normal

There are some example steps in `tests/features/brp/mock.php`

Opening other initiatives will fail due to validation errors as the mock data for those is not provided.

If you do need to have additional feedback, this is explained later in the document.

## Adding data to the Mock

### Folder structure

The directory structure of the `mock_data` is the following:

Example:
```
brp_api (main folder, or the "root" of the webservice)
  * default.json (The webservice's endpoint list)
  * initiativesV1.json (The initiatives endpoint)
  * initiativesV1.json?*** (The initiatives endpoint with arguments)
    - initiativesV1
      * default.json (the fallback initative, will be populated from code)
      * 2061.json (Initiative with id)
      * ...
    - feedbackV11
      * default.json (the fallback feedback, will be populated from code)
...
```

Each subfolder represents an endpoint, each file represents a specific node.

### Adding data

Data can be added using the following steps:
1. Visit the Clients test page
2. In the last segment, there is a checkbox to create a dump of the request.
3. The request data will be added to the sites files.
4. Copy the file and rename it using the folder structure.

The mock should only contain default and content that we are testing around. There is no point in dumping the full
webservice.
