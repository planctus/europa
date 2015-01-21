NextEuropa
==========

Reference: https://webgate.ec.europa.eu/CITnet/jira/browse/MULTISITE-4832

The main objective is to include NextEuropa code and functionality into Multisite.
These three features represent NextEuropa core-business:

* NextEuropa Core: responsible for staging all initial configuration in a 
  NextEuropa distribution, all other features can and do depend on the Core feature. 
  At this time the Core feature also exposes a configuration staging API that all
  features can use in their hook_install() / hook_update().

* NextEuropa Multilingual: provides integration with Entity Translation and TMGMT
  and implements custom URL rewrite rules to append language code at the end of URL. 
  It also stages multilingual-related configuration in its hook_install().
  It exposes multilingual-related configuration staging APIs (this might change in future)

* NextEuropa Editorial: provides the Editorial Team content type, integration 
  with Workbench moderation  and other related settings. This feature constitutes 
  the foundation of editorial workflow in NextEuropa.

