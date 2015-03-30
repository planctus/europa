# Build

       T                                    \`.    T
       |    T     .--------------.___________) \   |    T
       !    |     |//////////////|___________[ ]   !  T |
            !     `--------------'           ) (      | !
                                             '-'      !

## Set up your environment:

*   RUN: composer install
*   Create your build.properties.local from build.properties.dist
*   Change settings in build.properties.local to match your environments

## To build your local dev site:

*   RUN: <code>bin/phing build-dev</code>

### This will:

*   Check out the branch of MULTISITE set in the properties file from SVN.
*   Make the Drupal profile into the build folder based on the build.make file of the installation profile set in the properties file.
*   Symlink your custom modules, themes and libraries into the built Drupal instance

## To install your local dev site:

*   RUN: <code>bin/phing install-dev</code>

## Re-build the environment:

*   RUN: <code>bin/phing rebuild-dev</code>

### This will:

*   Backup settings.php
*   Update the branch of MULTISITE set in the properties file from SVN.
*   Make the Drupal profile into the build folder based on the build.make file of the installation profile set in the properties file.
*   Restore settings.php

## To build your production codebase:
*   RUN: <code>bin/phing build-distr</code>

### This will:

*   Check out the branch of MULTISITE set in the properties file from SVN.
*   Make the Drupal profile into the distro folder based on the build.make file of the installation profile set in the properties file.
*   Copy your custom modules, themes and libraries into the built Drupal instance

## To install your production site:

*   RUN: <code>bin/phing install-distr</code>

