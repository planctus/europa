api = 2
core = 7.x

; ===================
; Contributed modules
; ===================

projects[addressfield][subdir] = "contrib"
projects[addressfield][version] = "1.0"

projects[auto_entitylabel][subdir] = "contrib"
projects[auto_entitylabel][version] = "1.3"

projects[auto_nodetitle][subdir] = "contrib"
projects[auto_nodetitle][version] = "1.0"

projects[bootstrap_fieldgroup][subdir] = "contrib"
projects[bootstrap_fieldgroup][version] = "1.2"

projects[breakpoints][subdir] = "contrib"
projects[breakpoints][version] = "1.3"

projects[cer][subdir] = "contrib"
projects[cer][version] = "3.0-alpha7"
projects[cer][patch][] = "https://www.drupal.org/files/issues/cer-2373761-entity_api_exception-6.patch"

; Required by cer module.
projects[table_element][subdir] = "contrib"
projects[table_element][version] = "1.0-beta3"

projects[date_popup_authored][subdir] = "contrib"
projects[date_popup_authored][version] = "1.2"

projects[entityreference_filter][subdir] = "contrib"
projects[entityreference_filter][version] = "1.5"

projects[features_extra][subdir] = "contrib"
projects[features_extra][version] = "1.0"

projects[multiple_selects][subdir] = "contrib"
projects[multiple_selects][version] = "1.2"

projects[nodequeue][subdir] = "contrib"
projects[nodequeue][version] = "2.0-beta1"

projects[node_convert][subdir] = "contrib"
projects[node_convert][version] = "1.2"

projects[og_role_override][subdir] = "contrib"
projects[og_role_override][version] = "2.2"

projects[picture][subdir] = "contrib"
projects[picture][version] = "2.9"

projects[clients][subdir] = "contrib"
projects[clients][version] = "3.1"

projects[entityform][subdir] = "contrib"
projects[entityform][version] = "2.0-rc1"

projects[conditional_fields][subdir] = "contrib"
projects[conditional_fields][version] = "3.0-alpha2"
projects[conditional_fields][patch][] = "https://www.drupal.org/files/issues/conditional_fields-entity-translation-support-2125191-2.patch"
projects[conditional_fields][patch][] = "https://www.drupal.org/files/issues/fix_dependent_fields_in_IE-1373656-21.patch"

projects[retina_images][subdir] = "contrib"
projects[retina_images][version] = "1.0-beta4"

projects[uuid_features][subdir] = "contrib"
projects[uuid_features][version] = "1.0-alpha4"

projects[weight][subdir] = "contrib"
projects[weight][version] = "2.3"

projects[search_api][subdir] = "contrib"
projects[search_api][version] = "1.18"

projects[search_api_db][subdir] = "contrib"
projects[search_api_db][version] = "1.5"

projects[facetapi_bonus][subdir] = "contrib"
projects[facetapi_bonus][version] = "1.2"

projects[custom_formatters][subdir] = "contrib"
projects[custom_formatters][version] = "2.2"
projects[custom_formatters][do_recursion] = 0

projects[entityreference_view_widget][subdir] = "contrib"
projects[entityreference_view_widget][version] = "2.0-rc7"

projects[views_tree][subdir] = "contrib"
projects[views_tree][version] = "2.0"

; Required by custom_formatters.
; Originally these are done via custom_formatters.make but we switched off
; recursion, to avoid duplicate modules.
projects[form_builder][subdir] = "contrib"
projects[form_builder][version] = "1.0"

projects[options_element][subdir] = "contrib"
projects[options_element][version] = "1.7"

projects[wysiwyg_abbr][subdir] = "contrib"
projects[wysiwyg_abbr][version] = "1.0"
projects[wysiwyg_abbr][patch][] = "https://www.drupal.org/files/issues/2362309-2-wysiwyg_abbr_ckeditor_module.patch"

; End custom_formatters specific.

; =========
; Libraries
; =========

libraries[marked][download][type] = "get"
libraries[marked][download][url] = "https://raw.githubusercontent.com/chjj/marked/master/marked.min.js"

libraries[editarea][download][type] = "get"
libraries[editarea][download][url] = "http://downloads.sourceforge.net/project/editarea/EditArea/EditArea%200.8.2/editarea_0_8_2.zip?r=&ts=1334742944&use_mirror=internode"

libraries[areyousure][download][type] = "get"
libraries[areyousure][download][url] = "https://raw.githubusercontent.com/codedance/jquery.AreYouSure/098b3d3a35a0bd09fd3bbab514dd7d2f4159e680/jquery.are-you-sure.js"

; ======
; Themes
; ======
includes[] = "../lib/themes/europa/europa.make"
