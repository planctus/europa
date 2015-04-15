# Build

       T                                    \`.    T
       |    T     .--------------.___________) \   |    T
       !    |     |//////////////|___________[ ]   !  T |
            !     `--------------'           ) (      | !
                                             '-'      !


## Set up your environment:

*   RUN: <code>composer install</code>
*   Create your build.properties.local from build.properties.dist
*   Change settings in build.properties.local to match your environments

### Initalize platform for your project:

* Run <code>git submodule init</code>
* Run <code>git submodule update</code>

#### This will:

*   Initialize the submodule <code>platform</code> that contains the MULTISITE platform. By default the submodule is using the develop branch of the platform-dev repository.
*   Initialize the submodule <code>acquia-cloud</code> that contains the test environments repository in the Acquia Cloud. By default the submodule is using the master branch of the Acquia Cloud repository. All pushes to the master branch of this repository will deploy the code on the development environment of our Acquia Cloud test server.

##### In case the platform needs to be updated:
*   Maybe the platform is not in the *development* branch, so do this `cd platform; git checkout develop`.
*   In the platform folder: <code>git pull</code> (or whatever the update means, checkout another branch for example).
*   In the root folder: <code>git add platform</code> to add the change to the projects repository.

More on git submodules here: http://git-scm.com/book/en/v2/Git-Tools-Submodules

##### In cases when the platform needs to be altered (quick bug fixes etc)

Changes should be stored in the form of patch files in the patches folder of the project. To apply patches after your platform is initalized run:  <code>bin/phing patch-platform</code>

## To build your local dev site:

*   RUN: <code>bin/phing build-dev</code>

#### This will:

*   Make the Drupal profile into the build folder based on the build.make file of the installation profile of the platform set in <code>drupal.profile.name</code> property.
*   Symlink your project folder into the sites folder of your built Drupal instance with the name set in the <code>drupal.site.name</code> property.

## To install your local dev site:

*   RUN: <code>bin/phing install-dev</code>

## Re-build the environment:

This needs to be performed in case you want to rebuild your development environment without re-installing the database. (Updating the platform for example.)

*   RUN: <code>bin/phing rebuild-dev</code>

#### This will:

*   Backup settings.php
*   Make the Drupal profile into the build folder based on the build.make file of the installation profile set in the properties file.
*   Restore settings.php

## Package your production codebase:
*   RUN: <code>bin/phing package</code>

#### This will:

*   Make the Drupal profile into the distro folder based on the build.make file of the installation profile set in the properties file.
*   Copy your custom modules, themes and libraries into the built Drupal instance

## To install your production site:

*   RUN: <code>bin/phing install-distr</code>

## Deliver production codebase to the Acquia Cloud:

In order to do this you need to have read/write access to the Acquia Cloud repository and you need to <code>git submodule init</code> for the first time the acquia-cloud submodule in the project.

*   RUN: <code>bin/phing deliver</code>

#### This will:

*   Copy your previously packaged (!) codebase from docroot to the acquia-cloud/docroot in the acquia-cloud submodule.

#####From the submodule:

*   Stages all changes
*   Commits changes to master branch of the Acquia Cloud repository
*   Creates a tag with a name you input when prompted
*   Pushes your changes to the Acquia Cloud repository remote. (In case the proper branch is selected on the DEV instance the code will be automatically deployed, otherwise you can always choose a tag. See Acquia Cloud back office.)

#### Important!

I would suggest deliveries to be made only from the develop or master branch. Submodule needs to be first initialized in every branch separately. (AFAIK not tested).

After delivering the code to the Acquia Cloud the submodule needs to be updated to the current commit of the master branch by running <code>git add acquia-cloud</code> so we have a trace of every delivery in our project as well, not only in the Acquia Cloud repository.
