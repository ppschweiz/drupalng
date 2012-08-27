; Core version
; ------------
  
core = 7.x
  
; API version
; ------------
  
api = 2
  
; Core project
; ------------

projects[drupal][version] = 7.15

; Modules
; --------

projects[cas][version] = 1.2
projects[cas][type] = "module"
projects[cas][subdir] = "contrib"

projects[cas_attributes][version] = 1.0-beta2
projects[cas_attributes][type] = "module"
projects[cas_attributes][subdir] = "contrib"

projects[ctools][version] = 1.1
projects[ctools][type] = "module"
projects[ctools][subdir] = "contrib"

projects[context][version] = 3.0-beta3
projects[context][type] = "module"
projects[context][subdir] = "contrib"

projects[date][version] = 2.5
projects[date][type] = "module"
projects[date][subdir] = "contrib"

projects[devel][version] = 1.3
projects[devel][type] = "module"
projects[devel][subdir] = "contrib"

projects[entity][version] = 1.0-rc3
projects[entity][type] = "module"
projects[entity][subdir] = "contrib"

projects[entityreference][version] = 1.0-rc3
projects[entityreference][type] = "module"
projects[entityreference][subdir] = "contrib"

projects[features][version] = 1.0
projects[features][type] = "module"
projects[features][subdir] = "contrib"

projects[features_extra][version] = 1.x-dev
projects[features_extra][type] = "module"
projects[features_extra][subdir] = "contrib"

projects[lightbox2][version] = 1.0-beta1
projects[lightbox2][type] = "module"
projects[lightbox2][subdir] = "contrib"

projects[link][version] = 1.0
projects[link][type] = "module"
projects[link][subdir] = "contrib"

projects[libraries][version] = 1.0
projects[libraries][type] = "module"
projects[libraries][subdir] = "contrib"

projects[nodequeue][version] = 2.0-beta1
projects[nodequeue][type] = "module"
projects[nodequeue][subdir] = "contrib"

projects[panels][version] = 3.2
projects[panels][type] = "module"
projects[panels][subdir] = "contrib"

projects[resp_img][version] = 1.3
projects[resp_img][type] = "module"
projects[resp_img][subdir] = "contrib"

projects[strongarm][version] = 2.0
projects[strongarm][type] = "module"
projects[strongarm][subdir] = "contrib"

projects[textile][version] = 2.0-rc11
projects[textile][type] = "module"
projects[textile][subdir] = "contrib"

projects[token][version] = 1.2
projects[token][type] = "module"
projects[token][subdir] = "contrib"

projects[vars][version] = 2.0-alpha10
projects[vars][type] = "module"
projects[vars][subdir] = "contrib"

projects[views][version] = 3.3
projects[views][type] = "module"
projects[views][subdir] = "contrib"

projects[views_bulk_operations][version] = 3.0-rc1
projects[views_bulk_operations][type] = "module"
projects[views_bulk_operations][subdir] = "contrib"

projects[views_slideshow][version] = 3.0
projects[views_slideshow][type] = "module"
projects[views_slideshow][subdir] = "contrib"

projects[workbench][version] = 1.1
projects[workbench][type] = "module"
projects[workbench][subdir] = "contrib"

projects[workbench_access][version] = 1.x-dev
projects[workbench_access][type] = "module"
projects[workbench_access][subdir] = "contrib"

; Themes
; --------

projects[adaptivetheme][type] = "theme"
projects[adaptivetheme][download][type] = git
projects[adaptivetheme][download][url] = http://git.drupal.org/project/adaptivetheme.git
projects[adaptivetheme][download][branch] = 7.x-3.x
  
; Libraries
; ---------

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
