
       T                                    \`.    T
       |    T     .--------------.___________) \   |    T
       !    |     |//////////////|___________[ ]   !  T |
            !     `--------------'           ) (      | !
                                             '-'      !

Set up your environment:
*   RUN: composer install


To build your local environment:
*   Create your build.properties.local from build.properties.dist
*   Change settings in build.properties.local to match your environment.
*   RUN: bin/phing build-dev install

This will:
*   Check out the branch of MULTISITE set in the properties file from SVN.
*   Make the Drupal installation into the build folder based on the build.make file of the installation profile set in the properties file.
*   Install the Drupal site.


Re-build the environment:
*   RUN: bin/phing rebuild-dev

This will:
*   Backup settings.php
*   Update the branch of MULTISITE set in the properties file from SVN.
*   Make the Drupal installation into the build folder based on the build.make file of the installation profile set in the properties file.
*   Restore settings.php
