# Build

       T                                    \`.    T
       |    T     .--------------.___________) \   |    T
       !    |     |//////////////|___________[ ]   !  T |
            !     `--------------'           ) (      | !
                                             '-'      !


## Set up developer environment:

Please run the following codes in your development environment (Linux or OS X).

```bash
# Installing composer.
composer install

# Copy from build.properties.dist to your local setting build.properties.[project name].local depending on which project you are building.
cp build.properties.dist.[project name].local build.properties.local
# Change settings in build.properties.local to match your environments

# Initalize platform for your project:
git submodule init
git submodule update
```



#### This will:
*   Initialize the submodule <code>platform</code> that contains the **Next EUROPA WCM** platform.  
By default the submodule is using the latest release tag of the platform-dev repository that corresponds to the production environment.
*   Initialize the submodule <code>acquia-cloud</code> that contains the acceptance environment's repository in the Acquia Cloud. By default the submodule is using the master branch of the Acquia Cloud repository. All pushes to the master branch of this repository will deploy the code on the development environment of our Acquia Cloud test server.

##### In case the platform needs to be updated:
```bash
# In the platform folder perform the update. Checkout a new tag for example.
cd platform
git pull
git checkout [tag name]
# In the root folder add the change to the project's repository
cd ..
git add platform
git commit -m "Platform updated to [tag name]"
```
More on git submodules here: http://git-scm.com/book/en/v2/Git-Tools-Submodules

##### In cases when the platform needs to be altered (quick bug fixes etc)

Changes should be stored in the form of patch files in the patches folder of the project. To apply patches after your platform is initalized run:

```bash
bin/phing patch-platform
```

## To build your local dev site:

```bash
bin/phing build-dev
```

#### This will:

*   Make the Drupal profile into the build folder based on the build.make file of the installation profile of the platform set in <code>drupal.profile.name</code> property.
*   Symlink your project folder into the sites folder of your built Drupal instance with the name set in the <code>drupal.site.name</code> property.

## To install your local dev site:

```bash
bin/phing install-dev
```

## Package your production codebase:
```bash
bin/phing package
```

#### This will:

*   Make the Drupal profile into the <code>phing.project.distro.dir</code> folder based on the build.make file of the installation profile set in <code>drupal.profile.name</code>.
*   Copy your custom modules, themes and libraries into the built Drupal instance

### Deliver production codebase to the Acquia Cloud:

In order to do this you need to have read/write access to the Acquia Cloud repository and the acquia-cloud submodule has to be properly initialized.

```bash
bin/phing deliver
```

#### This will:

*   Copy your previously packaged (!) codebase from <code>phing.project.distro.dir</code> to the acquia-cloud/docroot in the acquia-cloud submodule.

##### From the submodule:

*   Stages all changes
*   Commits changes to <code>acquia.repo.project.branch</code> branch of the Acquia Cloud repository
*   Creates a tag with a name you input when prompted
*   Pushes your changes to the Acquia Cloud repository remote. (In case the proper branch is selected on the DEV instance the code will be automatically deployed, otherwise you can always choose a tag. See Acquia Cloud back office.)

#### Important!

I would suggest deliveries to be made only from the develop or master branch. Submodule needs to be first initialized/updated in every branch separately.

After delivering the code to the Acquia Cloud the submodule needs to be updated to the current commit of the <code>acquia.repo.project.branch</code> branch by running <code>git add acquia-cloud</code> so we have a trace of every delivery in our project as well, not only in the Acquia Cloud repository.

### Restore your local instance using the Acquia Cloud database:

In order to be able to perform this task, you will need working drush aliases pointing to the Acquia Cloud instance and also to your local instance. You can set up your aliases using the <code>drush.alias.local</code> and the <code>drush.alias.acquia</code> properties.

This will restore the local database from *./_db_dumps/ac-dump.mysql* if it exists. If the database is not yet exported it will attempt to download it.

*You will need to have registry-rebuild installed globally.
TODO: add rebuild-registry via composer*

```bash
bin/phing restore-ac-db
```

#### Download the Acquia Cloud database:

This will download the Acquia Cloud database into *./_db_dumps/ac-dump.mysql*

```bash
bin/phing fetch-ac-db
```
