; Drush Make settings
; -------------------

api = 2
core = 7.x
projects[drupal][version] = 7.17

; Production Modules
; ------------------

projects[admin_menu][version] = 3.0-rc3
projects[admin_menu][type] = "module"
projects[admin_menu][subdir] = "contrib"

projects[cas][version] = 1.2
projects[cas][type] = "module"
projects[cas][subdir] = "contrib"

projects[cas_attributes][version] = 1.0-rc1
projects[cas_attributes][type] = "module"
projects[cas_attributes][subdir] = "contrib"

projects[colorbox][version] = 2.0
projects[colorbox][type] = "module"
projects[colorbox][subdir] = "contrib"

projects[ctools][version] = 1.2
projects[ctools][type] = "module"
projects[ctools][subdir] = "contrib"

projects[context][version] = 3.0-beta5
projects[context][type] = "module"
projects[context][subdir] = "contrib"

projects[date][version] = 2.6
projects[date][type] = "module"
projects[date][subdir] = "contrib"

projects[domain][version] = 3.5
projects[domain][type] = "module"
projects[domain][subdir] = "contrib"

projects[entity][version] = 1.0-rc3
projects[entity][type] = "module"
projects[entity][subdir] = "contrib"

projects[entityreference][version] = 1.0
projects[entityreference][type] = "module"
projects[entityreference][subdir] = "contrib"

projects[features][version] = 1.0
projects[features][type] = "module"
projects[features][subdir] = "contrib"

projects[features_extra][version] = 1.0-alpha1
projects[features_extra][type] = "module"
projects[features_extra][subdir] = "contrib"

projects[flag][version] = 2.0
projects[flag][type] = "module"
projects[flag][subdir] = "contrib"

projects[flag_weights][version] = 1.0
projects[flag_weights][type] = "module"
projects[flag_weights][subdir] = "contrib"

projects[i18n][version] = 1.7
projects[i18n][type] = "module"
projects[i18n][subdir] = "contrib"

projects[l10n_update][version] = 1.0-beta3
projects[l10n_update][type] = "module"
projects[l10n_update][subdir] = "contrib"

projects[link][version] = 1.0
projects[link][type] = "module"
projects[link][subdir] = "contrib"

projects[libraries][version] = 2.0
projects[libraries][type] = "module"
projects[libraries][subdir] = "contrib"

projects[migrate][version] = 2.5
projects[migrate][type] = "module"
projects[migrate][subdir] = "contrib"

projects[migrate_d2d][version] = 2.0
projects[migrate_d2d][type] = "module"
projects[migrate_d2d][subdir] = "contrib"

projects[panels][version] = 3.3
projects[panels][type] = "module"
projects[panels][subdir] = "contrib"

projects[resp_img][version] = 1.3
projects[resp_img][type] = "module"
projects[resp_img][subdir] = "contrib"

projects[strongarm][version] = 2.0
projects[strongarm][type] = "module"
projects[strongarm][subdir] = "contrib"

projects[taxonomy_menu][version] = 1.4
projects[taxonomy_menu][type] = "module"
projects[taxonomy_menu][subdir] = "contrib"

projects[textile][version] = 2.0-rc11
projects[textile][type] = "module"
projects[textile][subdir] = "contrib"

projects[token][version] = 1.4
projects[token][type] = "module"
projects[token][subdir] = "contrib"

projects[variable][version] = 2.1
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

projects[workbench][version] = 1.1
projects[workbench][type] = "module"
projects[workbench][subdir] = "contrib"

projects[workbench_access][version] = 1.0
projects[workbench_access][type] = "module"
projects[workbench_access][subdir] = "contrib"

projects[workbench_media][version] = 1.1
projects[workbench_media][type] = "module"
projects[workbench_media][subdir] = "contrib"

projects[workbench_moderation][version] = 1.2
projects[workbench_moderation][type] = "module"
projects[workbench_moderation][subdir] = "contrib"

; Themes
; --------

projects[adaptivetheme][version] = 3.1
projects[adaptivetheme][type] = "theme"

; Production libraries
; --------------------

libraries[CAS][download][type] = "git"
libraries[CAS][download][url] = "https://github.com/Jasig/phpCAS.git"
libraries[CAS][download][tag] = "1.3.1"

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
