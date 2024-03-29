; Drush Make settings
; -------------------

api = 2
core = 7.x
projects[drupal][version] = 7.19

; Map Modules
; -----------
; Modules that may help for displaying maps of sections and regular
; tables
;
; simple-pin-map
; openlayers, countries_borders, openlayers_taxonomy
; svg_embed
; jsmap
; jq_maphilight
; leaflet_geojson


; Newsletter Modules
; ------------------
; newsletter
; simplenews && simplenews_content_selection
; http://drupal.stackexchange.com/questions/18871/which-newsletter-module-will-fit-my-requirements


; Production Modules
; ------------------

projects[admin_menu][version] = 3.0-rc4
projects[admin_menu][type] = "module"
projects[admin_menu][subdir] = "contrib"

; apply_for_role
; auto_entitylabel
; bounce

projects[bueditor][version] = 1.5
projects[bueditor][type] = "module"
projects[bueditor][subdir] = "contrib"

; calendar

projects[cas][version] = 1.2
projects[cas][type] = "module"
projects[cas][subdir] = "contrib"

projects[cas_attributes][version] = 1.0-rc2
projects[cas_attributes][type] = "module"
projects[cas_attributes][subdir] = "contrib"

; cas_roles

projects[colorbox][version] = 2.0
projects[colorbox][type] = "module"
projects[colorbox][subdir] = "contrib"

projects[ctools][version] = 1.2
projects[ctools][type] = "module"
projects[ctools][subdir] = "contrib"

projects[domain_ctools][version] = 1.3
projects[domain_ctools][type] = "module"
projects[domain_ctools][subdir] = "contrib"

; coffee

projects[context][version] = 3.0-beta6
projects[context][type] = "module"
projects[context][subdir] = "contrib"

projects[date][version] = 2.6
projects[date][type] = "module"
projects[date][subdir] = "contrib"

; date_repeat_instance
; date_repeat_presets

projects[domain][version] = 3.8
projects[domain][type] = "module"
projects[domain][subdir] = "contrib"

; domain_admin
; domain_blocks
; domain_fields

projects[domain_locale][version] = 1.0-alpha4
projects[domain_locale][type] = "module"
projects[domain_locale][subdir] = "contrib"

projects[domain_path][version] = 1.0-beta3
projects[domain_path][type] = "module"
projects[domain_path][subdir] = "contrib"

; domain_roles
; domain_taxonomy

projects[domain_types][version] = 1.1
projects[domain_types][type] = "module"
projects[domain_types][subdir] = "contrib"

; domain_views
; domain_variable

; smartqueue_domain

projects[entity][version] = 1.0-rc3
projects[entity][type] = "module"
projects[entity][subdir] = "contrib"

projects[entity_translation][version] = 1.0-beta2
projects[entity_translation][type] = "module"
projects[entity_translation][subdir] = "contrib"

projects[entityreference][version] = 1.0
projects[entityreference][type] = "module"
projects[entityreference][subdir] = "contrib"

projects[features][version] = 1.0
projects[features][type] = "module"
projects[features][subdir] = "contrib"

projects[features_extra][version] = 1.0-alpha2
projects[features_extra][type] = "module"
projects[features_extra][subdir] = "contrib"

projects[flag][version] = 2.0
projects[flag][type] = "module"
projects[flag][subdir] = "contrib"

projects[flag_weights][version] = 1.0
projects[flag_weights][type] = "module"
projects[flag_weights][subdir] = "contrib"

projects[footnotes][version] = 2.5
projects[footnotes][type] = "module"
projects[footnotes][subdir] = "contrib"

projects[htmlpurifier][version] = 1.0
projects[htmlpurifier][type] = "module"
projects[htmlpurifier][subdir] = "contrib"

projects[i18n][version] = 1.8
projects[i18n][type] = "module"
projects[i18n][subdir] = "contrib"

; i18_page_views
; i18nviews

projects[l10n_client][version] = 1.1
projects[l10n_client][type] = "module"
projects[l10n_client][subdir] = "contrib"

projects[imce][version] = 1.6
projects[imce][type] = "module"
projects[imce][subdir] = "contrib"

; imce_crop
; imce_filefield / imce_plupload / filefield_sources
; imce_mkdir
; imce_rename
; imce_tools
; imce_watermark

projects[l10n_update][version] = 1.0-beta3
projects[l10n_update][type] = "module"
projects[l10n_update][subdir] = "contrib"

projects[link][version] = 1.0
projects[link][type] = "module"
projects[link][subdir] = "contrib"

projects[libraries][version] = 2.0
projects[libraries][type] = "module"
projects[libraries][subdir] = "contrib"

projects[menu_attributes][version] = 1.0-rc2
projects[menu_attributes][type] = "module"
projects[menu_attributes][subdir] = "contrib"

projects[migrate][version] = 2.5
projects[migrate][type] = "module"
projects[migrate][subdir] = "contrib"

projects[migrate_d2d][version] = 2.0
projects[migrate_d2d][type] = "module"
projects[migrate_d2d][subdir] = "contrib"

projects[nodequeue][version] = 2.0-beta1
projects[nodequeue][type] = "module"
projects[nodequeue][subdir] = "contrib"

; nodequeue_scheduler

projects[panels][version] = 3.3
projects[panels][type] = "module"
projects[panels][subdir] = "contrib"

projects[pathauto][version] = 1.2
projects[pathauto][type] = "module"
projects[pathauto][subdir] = "contrib"

projects[redirect][version] = 1.0-rc1
projects[redirect][type] = "module"
projects[redirect][subdir] = "contrib"

projects[resp_img][version] = 1.3
projects[resp_img][type] = "module"
projects[resp_img][subdir] = "contrib"

; schemaorg

projects[smartqueue_domain][version] = 1.0
projects[smartqueue_domain][type] = "module"
projects[smartqueue_domain][subdir] = "contrib"

projects[strongarm][version] = 2.0
projects[strongarm][type] = "module"
projects[strongarm][subdir] = "contrib"

projects[taxonomy_csv][version] = 5.x-dev
projects[taxonomy_csv][type] = "module"
projects[taxonomy_csv][subdir] = "contrib"

; taxonomy_manager

projects[taxonomy_menu][version] = 1.4
projects[taxonomy_menu][type] = "module"
projects[taxonomy_menu][subdir] = "contrib"

projects[textile][version] = 2.0-rc11
projects[textile][type] = "module"
projects[textile][subdir] = "contrib"

; timelinemap for displaying party statistics.

projects[title][version] = title
projects[title][type] = "module"
projects[title][subdir] = "contrib"

projects[token][version] = 1.4
projects[token][type] = "module"
projects[token][subdir] = "contrib"

projects[transliteration][version] = 3.1
projects[transliteration][type] = "module"
projects[transliteration][subdir] = "contrib"

projects[variable][version] = 2.2
projects[variable][type] = "module"
projects[variable][subdir] = "contrib"

projects[vars][version] = 2.0-alpha10
projects[vars][type] = "module"
projects[vars][subdir] = "contrib"

projects[views][version] = 3.5
projects[views][type] = "module"
projects[views][subdir] = "contrib"

projects[views_bulk_operations][version] = 3.1
projects[views_bulk_operations][type] = "module"
projects[views_bulk_operations][subdir] = "contrib"

projects[views_slideshow][version] = 3.0
projects[views_slideshow][type] = "module"
projects[views_slideshow][subdir] = "contrib"

projects[workbench][version] = 1.2
projects[workbench][type] = "module"
projects[workbench][subdir] = "contrib"

projects[workbench_access][version] = 1.2
projects[workbench_access][type] = "module"
projects[workbench_access][subdir] = "contrib"

projects[workbench_moderation][version] = 1.2
projects[workbench_moderation][type] = "module"
projects[workbench_moderation][subdir] = "contrib"

; workbench_nodequeue

; Themes
; --------

projects[adaptivetheme][version] = 3.1
projects[adaptivetheme][type] = "theme"

; Production libraries
; --------------------

libraries[CAS][download][type] = "git"
libraries[CAS][download][url] = "https://github.com/Jasig/phpCAS.git"
libraries[CAS][download][tag] = "1.3.2"

libraries[htmlpurifier][download][type] = "file"
libraries[htmlpurifier][download][url] = "http://htmlpurifier.org/releases/htmlpurifier-4.4.0-lite.tar.gz"
libraries[htmlpurifier][download][filename] = "htmlpurifier"

libraries[jquery.cycle][download][type] = "file"
libraries[jquery.cycle][download][url] = "https://github.com/downloads/malsup/cycle/jquery.cycle.all.latest.min.js"
libraries[jquery.cycle][download][filename] = "jquery.cycle.all.min.js"

libraries[textile][download][type] = "svn"
libraries[textile][download][url] = "http://textpattern.googlecode.com/svn/releases/4.3.0/source/textpattern/lib/"
libraries[textile][destination] = "modules/contrib/textile/"
libraries[textile][directory_name] = "include"

; Development Modules
; -------------------

projects[devel][version] = 1.3
projects[devel][type] = "module"
projects[devel][subdir] = "contrib"

projects[diff][version] = 3.2
projects[diff][type] = "module"
projects[diff][subdir] = "contrib"
