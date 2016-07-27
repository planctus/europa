# EuroVoc for DTT

This module facilitates the import and usage of [EuroVoc](http://publications.europa.eu/mdr/eurovoc/) in Drupal 7.

## Drush commands

**Quick-start the project**

This will do everything necessary:
- clear the vocabulary if necessary
- download the archive with XML files
- un-zip the archive and clear up unnecessary files
- import all concepts (long operation)
- import translations for the imported concepts

```
$ drush eurovoc

// Alternatives:
$ drush eurovoc quickstart
```

Clear the terms in the vocabulary
```
$ drush eurovoc clear

// Alternatives:
$ drush eurovoc c
```

Download EuroVoc [zip file](http://publications.europa.eu/mdr/resource/thesaurus/eurovoc-20160630-0/xml/eurovoc_xml.zip) from the Metadata Registry:
```
$ drush eurovoc data

// Alternatives:
$ drush eurovoc d
```

Import concepts (Works only if the necessary files are present in the correct folder)
```
$ drush eurovoc import
Please select a concept:
 [0]  :  Cancel      
 [1]  :  All         
 [2]  :  Domains     
 [3]  :  Thesauri    
 [4]  :  Descriptors
 
 // Alternatives:
 $ drush eurovoc i
```

Translate terms (Works only if the concepts are present in the database)
```
$ drush eurovoc translate

// Alternatives:
$ drush eurovoc t
```

Rollback examples
```
$ drush mi --rollback EuroVocDomainsMigration
$ drush mi --rollback EuroVocThesauriMigration
$ drush mi --rollback EuroVocDescriptorsMigration

// This is only for development purposes!
$ drush mi --rollback --all
```

Keep in mind that the importers are based on [Migrate](https://www.drupal.org/project/migrate) which means that you can use its own cli to revert importers after import or clear operations!

For more details, read the [Migrate Drush commands wiki page](https://www.drupal.org/node/1561820)

## CLI configurations

To change the main variables of the Drush commands, update the `nexteuropa_eurovoc.config.php` file:

The most important variables are:
- `EUROVOC_ZIP_URL` - change when the packaged EuroVoc information has been updated.
- `EUROVOC_DATA_FOLDER` - the folder which [Migrate](https://www.drupal.org/project/migrate) loads XML files to run the importers. 

## Module guidelines
- Migrate API classes and importers are in `nexteuropa_eurovoc.migrate.inc` and `nexteuropa_eurovoc.inc` files.
- Drupal-specific helper functions are in `nexteuropa_eurovoc.helpers.inc`
- General-purpose PHP classes and methods are in the autoload `src/` folder.

## EuroVoc Resources
- [EuroVoc at the Metadata Registry](http://publications.europa.eu/mdr/eurovoc/)
- [EuroVoc at europa.eu domain](http://eurovoc.europa.eu/)

## Important rules for content editors:
- Never use Domain concepts for categorization of any content.