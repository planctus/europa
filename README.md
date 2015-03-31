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

* Run <code>bin/phing init-platform</code>

#### This will:

*   Check out the branch of MULTISITE set in the properties file from SVN into the platform folder.
*   Delete unnecessary folders from the platform folder.

The platform folder is version controlled so changes to the platform files can be applied and versioned. These changes should be stored in the form of patch files in the patches folder of the project. To apply patches after your platform is initalized run:  <code>bin/phing patch-platform</code>

## To build your local dev site:

*   RUN: <code>bin/phing build-dev</code>

#### This will:

*   Make the Drupal profile into the build folder based on the build.make file of the installation profile of the platform set in <code>drupal.profile.name</code> property.
*   Symlink your project folder into the sites folder of your built Drupal instance with the name set in the <code>drupal.site.name</code> property.

## To install your local dev site:

*   RUN: <code>bin/phing install-dev</code>

## Re-build the environment:

*   RUN: <code>bin/phing rebuild-dev</code>

#### This will:

*   Backup settings.php
*   Update the branch of MULTISITE set in the properties file from SVN.
*   Make the Drupal profile into the build folder based on the build.make file of the installation profile set in the properties file.
*   Restore settings.php

## To build your production codebase:
*   RUN: <code>bin/phing build-distr</code>

#### This will:

*   Check out the branch of MULTISITE set in the properties file from SVN.
*   Make the Drupal profile into the distro folder based on the build.make file of the installation profile set in the properties file.
*   Copy your custom modules, themes and libraries into the built Drupal instance

## To install your production site:

*   RUN: <code>bin/phing install-distr</code>
