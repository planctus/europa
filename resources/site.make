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

# Required by cer module.
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

projects[picture][subdir] = "contrib"
projects[picture][version] = "2.9"

projects[conditional_fields][subdir] = "contrib"
projects[conditional_fields][version] = "3.0-alpha2"
projects[conditional_fields][patch][] = "https://www.drupal.org/files/issues/conditional_fields-entity-translation-support-2125191-2.patch"

projects[retina_images][subdir] = "contrib"
projects[retina_images][version] = "1.0-beta4"

projects[uuid_features][subdir] = "contrib"
projects[uuid_features][version] = "1.0-alpha4"

projects[weight][subdir] = "contrib"
projects[weight][version] = "2.3"

projects[custom_formatters][subdir] = "contrib"
projects[custom_formatters][version] = "2.2"
projects[custom_formatters][do_recursion] = 0

## Required by custom_formatters.
## Originally these are done via custom_formatters.make but we switched off
## recursion, to avoid duplicate modules.
projects[form_builder][subdir] = "contrib"
projects[form_builder][version] = "1.0"

projects[options_element][subdir] = "contrib"
projects[options_element][version] = "1.7"

libraries[editarea][download][type] = "get"
libraries[editarea][download][url] = "http://downloads.sourceforge.net/project/editarea/EditArea/EditArea%200.8.2/editarea_0_8_2.zip?r=&ts=1334742944&use_mirror=internode"
## End custom_formatters specific.

; =========
; Libraries
; =========
libraries[marked][download][type] = "get"
libraries[marked][download][url] = "https://raw.githubusercontent.com/chjj/marked/master/marked.min.js"

; ======
; Themes
; ======
includes[] = "../lib/themes/europa/europa.make"
