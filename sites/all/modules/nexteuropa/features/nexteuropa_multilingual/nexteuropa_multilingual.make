; =====================================================================
; This makefile is not actually used at the moment.
; For more information please visit:
; https://webgate.ec.europa.eu/CITnet/jira/browse/MULTISITE-5238
; =====================================================================

api = 2
core = 7.x

;
; Contributed modules =====================================================================
;
projects[entity_translation][subdir] = contrib
projects[entity_translation][version] = 1.x-dev

projects[title][subdir] = contrib
projects[title][version] = 1.x-dev

projects[variable][subdir] = contrib
projects[variable][version] = 2.5

;
; Custom modules =====================================================================
;
projects[tmgmt_workbench][type] = module
projects[tmgmt_workbench][subdir] = custom
projects[tmgmt_workbench][download][type] = svn
projects[tmgmt_workbench][download][url] = https://webgate.ec.europa.eu/CITnet/svn/NEXTEUROPA/trunk/profiles/nexteuropa/modules/custom/tmgmt_workbench

