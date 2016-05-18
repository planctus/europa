# Devel content generation

To easily test this, the following commands can be run:

```
drush en devel_generate -y;
drush gent event_types 5;
drush gent social_networks 5;
drush genc 5 --types=topic;
drush genc 5 --types=contact;
drush genc 5 --types=department;
drush genc 5 --types=person;
drush genc 5 --types=event;
drush genc 5 --types=event;
drush sqlc --extra="-e'UPDATE node SET status = 1;'"
```
