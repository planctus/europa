## Project setup
```PHP
#hammertime
T                                    \`.    T
|    T     .--------------.___________) \   |    T
!    |     |//////////////|___________[ ]   !  T |
     !     `--------------'           ) (      | !
                                      '-'      !
```
### 1. Project configuration

The configuration of the project is managed in 3 `build.properties` files:

1.  `build.properties.dist`: This contains default configuration which is
    common for all NextEuropa projects. *This file should never be edited.*
2.  `build.properties`: This is the configuration for your project. In here you
    can override the default configuration with settings that are more suitable
    for your project. Some typical settings would be the site name, the install
    profile to use and the modules/features to enable after installation.
    * In addition to these, we have the following preconfigured files:
      - build.properties.dist.brp
      - build.properties.dist.info
      - build.properties.dist.cwt
      - build.properties.dist.political
3.  `build.properties.local`: This contains configuration which is unique for
    the local development environment. In here you would place things like your
    database credentials and the development modules you would like to install.

    **To get started, copy the relevant preconfigured example file to build.properties.local and modify the data.**

    *This file should never be committed.*

### 2. Project code

* Your custom modules, themes and custom PHP code go in the `lib/` folder. The
  contents of this folder get symlinked into the Drupal website at `sites/all/`.
* Any contrib modules, themes, libraries and patches you use should be put in
  the make file `resources/site.make`. Whenever the site is built these will be
  downloaded and copied into the Drupal website.
* Any development only modules, themes, libraries should be either added to the
  `resources/develop.site.make` file, or loaded using composer (require-dev).  
* If you have any custom Composer dependencies, declare them in
  `resources/composer.json` and `resources/composer.lock`.

### 3. Drupal root

The Drupal site will be placed in the `build/` folder when it is built. Point
your webserver here. This is also where you would execute your Drush commands.
Your custom modules are symlinked from `build/sites/all/modules/custom/` to
`lib/modules/` so you can work in either location, whichever you find the most
comfortable.

### 4. Behat tests

All Behat related files are located in the `tests/` folder.

* `tests/behat.yml`: The Behat configuration file. This file is regenerated
  automatically when the project is built and should never be edited or
   committed.
* `tests/behat.yml.dist`: The template that is used for generating `behat.yml`.
  If you need to tweak the configuration of Behat then this is the place to do
  that.
* `tests/features/`: Put your Behat test scenarios here.
* `tests/src/Context/`: The home of custom Context classes.

For more information about testing within our project, [Read this article](https://github.com/haringsrob/harings.be/blob/master/articles/drupal-behat-testing-guide.md).

### 5. Styleguide

The DT repository contains all the source files needed to generate the Europa styleguide, but it doesn't contain the generated styleguide.
In your local environment, in order to generate the styleguide you will need npm (package manager for JavaScript) to be installed on your system, once you have npm you can run npm install from the root of the europa theme and you will get Kss which is the library we are using to generate the styleguide.
There is a phing task named gen-styleguide which can be used to facilitate the styleguide generation
./bin/phing gen-styleguide
The generated files are excluded in .gitignore, so you should never notice them doing a git diff, in any case do not add those files to the repository, please.

### 6. Other files and folders

* `bin/`: Contains command line executables for the various tools we use such as
  Behat, Drush, Phing, PHP CodeSniffer etc.
* `src/`: Custom PHP code for the build system, such as project specific Phing
  tasks.
* `tmp/`: A temporary folder where the platform tarball is downloaded and
  unpacked during the build process.
  * You should exclude this folder in phpstorm.
* `tmp/build/`: Will contain the build intended for deployment to production. Use
  the `build-dist` Phing target to build it.
* `tmp/deploy-package.tar.gz`: The platform tarball. This file is very large and
  will only be downloaded once. When a new build is started in the future the
  download will be skipped, unless this file is deleted manually.
* `vendor/`: Composer dependencies and autoloader.

### 7. Deployment on acquia cloud
The stage environment for the DT projects is in the acquia cloud, in order to stage also the styleguide we include that in the package we submit to acquia. If you intend to deploy on acquia, you will need npm to be installed on your system and you need to run the npm install in the root folder of the Europa theme before attempting it.

## Tips and tricks

### Digital transformation specific commands

* `./bin/phing rebuild-dev-db` rebuilds the codebase, creates a settings file
  and restores the database.
  This is espeically usefull for peer reviewing tickets.
  
* `./bin/phing snapshot` Creates a dump from the local database.
  
* `./bin/phing restore-snapshot` Restores a database dump previously created
  by `./bin/phing snapshot`

* `drush en dt_dev -y; drush frdt -y` After running those commands, all the
  feature fields will be unlocked.

  **dt_dev** takes care of the manual tasks, it will make sure the bases of our
  qa process are covered by always locking on export, and adding required info
  file parameters.

* `drush en dt_test_content` will enable the "dummy content" feature that
  install preconfigured entities for you to test with.

### Common platform deploy package storage

To avoid the need to download the deploy-package-*.tar.gz multiple times when used
in different instances, optionally you can set up a symlink to a common storage folder.

Ideally you could point this symlink to the folder that is synced with the Google Drive
folder where these files are kept. Like this new version will also be immediately uploaded
and shared with the whole team.

You can set this up by defining your folder in the `platform.package.storage` in your
`build.properties.local`

### Peer reviewing

To enhance our peer reviewing, we have implied a few rules:
  * We integrated a checklist for the reviewer to check after testing.
  * We have a template ready for you to complete so creating a pull request
    will take less time.
  * We use 3 main tags for peer reviews:
    * Validated: This means the code has been tested, but it's waiting for
      continuousphp to complete.
      All validated pull requests can be merged by anyone whenever the
      continuous integration is complete.
    * Needs review / no status: Ticket is ready to be reviewed
    * Needs work: There are issues with the implementation/code and there is
      more work to be done by the author.    

## Environment changelog:

```
26/07/2016 - Updated readme documentation and changed pull request template.
```

## Continuous integration status:

Develop:
[![Build Status](https://status.continuousphp.com/git-hub/ec-europa/digital-transformation-dev?token=f8d249ca-69e4-4490-8c02-afe9d2864a65&branch=develop)](https://continuousphp.com/git-hub/ec-europa/digital-transformation-dev)

Master:
[![Build Status](https://status.continuousphp.com/git-hub/ec-europa/digital-transformation-dev?token=f8d249ca-69e4-4490-8c02-afe9d2864a65&branch=master)](https://continuousphp.com/git-hub/ec-europa/digital-transformation-dev)

## Additional reading material

The documentation below is the original starterkit documentation and is not
maintained by the dttsb team.

This README is divided in different parts, please read the relevant section:

1. [Developer guide](docs/developer-guide.md): Explains day-to-day
   development practices when working on a NextEuropa subsite.
2. [Starting a new project](docs/starting-a-new-project.md): This
   section explains how to set up a brand new project on the NextEuropa
   platform. These instructions need only to be followed once by the lead
   developer at the start of the project.
3. [Converting an existing project](docs/converting-an-existing-project.md):
   If you already have a project that runs on NextEuropa and you want to start
   using Continuous Integration, check out this section.
4. [Merging upstream changes](docs/merging-upstream-changes.md): How to
   merge the latest changes that have been made to the Subsite Starterkit in
   your own project.
5. [Contributing](docs/contributing.md): How to contribute bugfixes and
   new features to the Subsite Starterkit.
