# Tests

## Uploading files

We can utilize behat to work with file uploads.

There is a directory called `dummy_files` inside the tests folder.

To upload files in these directory's you can use:

`And I attach the file "test.pdf" to "files[upload]"`

## Selenium

Selenium is a tool that will emulate the clicks. It uses [firefox](https://www.mozilla.org/nl/firefox/new/) to emulate
real browser behaviour and allows you to use javascript in automated tests.

Selenium should not be active at all times, only for testing purposes.

When running tests using selenium (see usage below) keep in mind that every hidden elements cannot
be used, for example: When a link is on a tab, you first have to click the tab, then click the link.

## PhantomJS

PhantomJS is a headless browser that allows us to run javascript based tests in the background.

### Installation

To install and run Selenium and PhantomJS use the following steps:

** OS X **

```bash
$ brew install selenium-server-standalone
$ brew install phantomjs
```

__Running it__
```bash
$ selenium-server -port 8643
```

#### Troubleshooting

Error:
> `No Java runtime present, requesting install.`

Solution:
> [download and install java sdk](http://www.oracle.com/technetwork/java/javase/downloads/jdk8-downloads-2133151.html)

_____________

Error:
> `Could not open connection: Cannot find firefox binary in PATH. Make sure firefox is installed. OS appears to be: MAC`

Solution:

> [Download and install firefox.](https://www.mozilla.org/nl/firefox/new/)
> And run it at least once!

** Linux **

[Source](http://www.thelinuxdaily.com/2011/07/how-to-install-and-use-selenium-server-in-linux/)

As this might differ for linux distributions, please search for installation guidelines for your distribution.

For the installation of phantomJS please look at this article:
[Download and install phantomJS](http://stackoverflow.com/questions/8778513/how-can-i-setup-run-phantomjs-on-ubuntu)

__Setup__
```bash
$ su -c 'yum install -y selenium-server python-setuptools'
$ su -c 'easy_install selenium'
```

__Running it__
```bash
$ selenium-server -port 8643
```

### Usage

To use javascript in tests, you can just write them as usual.
The only new thing is an additional tag:

(Example to upload a file using media browser)

```cucumber
@javascript
Scenario: I can upload files using Media
    Given I am logged in as a user with the "administrator" role
    And I am viewing a "file" content:
      | title           | File Title |
      | status          | 1          |
    And I edit the node
    And I click "Browse"
    And I switch to the frame "mediaBrowser"
        And I attach the file "test.pdf" to "files[upload]"
        And I press "Upload"
        And I press "Next"
        And I press "Next"
        And I press "Save"
    And I switch out of all frames
    And I select "Published" from "Moderation state"
    And I press "Save"
```
