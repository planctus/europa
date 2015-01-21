
; ========================================================================================
;
; This make file is a hard-merge from the distributed make files contained in each 
; NextEuropa feature. It is meant to be a temporary solution, to be included in the 
; main Multisite building script. Hopefully we will not need it soon enough.
; One main change here is renaming "contrib" into "contributed" in order to
; comply with Multisite conventions.
;
; This file is currently included by multisite_drupal_standard/build.make
; 
; For more information please check: https://webgate.ec.europa.eu/CITnet/jira/browse/MULTISITE-5054
;
; ========================================================================================

;
; Contributed modules =====================================================================
;
projects[bean][subdir] = contributed
projects[bean][version] = 1.7

projects[chosen][subdir] = contributed
projects[chosen][version] = 2.0-beta4

projects[coffee][subdir] = contributed
projects[coffee][version] = 2.2

projects[ds][subdir] = contributed
projects[ds][version] = 2.6

projects[entitycache][subdir] = contributed
projects[entitycache][version] = 1.2

projects[migrate][subdir] = contributed
projects[migrate][version] = 2.6-rc1

projects[registry_autoload][subdir] = contributed
projects[registry_autoload][version] = 1.2

projects[smart_trim][subdir] = contributed
projects[smart_trim][version] = 1.4

projects[taxonomy_revision][subdir] = contributed
projects[taxonomy_revision][version] = 1.2

projects[og][subdir] = contributed
projects[og][version] = 2.7

; Dev branch is necessary in order to solve https://www.drupal.org/node/1911782
; Multisite ships with "dfe9e23e123e225cb2e8a5c8273c73556d1056ba": we override that here.
projects[workbench_moderation][subdir] = contributed
projects[workbench_moderation][version] = 1.x-dev

projects[workbench_og][subdir] = contributed
projects[workbench_og][version] = 2.x-dev

projects[scheduler][subdir] = contributed
projects[scheduler][version] = 1.2 

projects[scheduler_workbench][subdir] = contributed
projects[scheduler_workbench][version] = 1.2

projects[og_linkchecker][type] = module
projects[og_linkchecker][subdir] = contributed
projects[og_linkchecker][download][type] = git
projects[og_linkchecker][download][branch] = 7.x-1.x

projects[entity_translation][subdir] = contributed
projects[entity_translation][version] = 1.x-dev

projects[title][subdir] = contributed
projects[title][version] = 1.x-dev

projects[variable][subdir] = contributed
projects[variable][version] = 2.5

projects[ckeditor_lite][subdir] = contributed
projects[ckeditor_lite][version] = 1.0-rc1

;
; Libraries =====================================================================
;
libraries[chosen][download][type] = "get"
libraries[chosen][download][url] = "https://github.com/harvesthq/chosen/releases/download/v1.1.0/chosen_v1.1.0.zip"
libraries[chosen][directory_name] = "chosen"
libraries[chosen][destination] = "libraries"

libraries[ckeditor_lite][download][type]= svn
libraries[ckeditor_lite][download][url] = https://github.com/loopindex/ckeditor-track-changes/trunk/src/lite
libraries[ckeditor_lite][download][sha1] = "2325e728878c9840c7b2fa59b30c4fc682f7c118"
libraries[ckeditor_lite][subdir] = ckeditor/plugins
libraries[ckeditor_lite][directory_name] = "lite"
