
 #drupal
 wget http://ftp.drupal.org/files/projects/drupal-6.15.tar.gz
 tar xvzf drupal-6.15.tar.gz
 rm drupal-6.15.tar.gz
 mv drupal-6.15 drupal
 cd drupal

 #modules
 mkdir -p sites/all/modules
 mkdir -p sites/all/modules/pirate-slider
 mkdir -p sites/all/modules/pirate-donate
 mkdir -p sites/all/libraries/ckeditor
 mkdir -p sites/all/libraries/tinymce
 mkdir -p sites/all/libraries/
 mkdir -p sites/all/themes/pirate
 mkdir -p sites/all/themes/pirate2
 mkdir -p sites/default/files
 chmod 777 sites/default/files/
 
 cd sites/all/themes

 wget http://ftp.drupal.org/files/projects/zen-6.x-1.1.tar.gz
 tar xvzf zen-6.x-1.1.tar.gz
 rm zen-6.x-1.1.tar.gz

 cd ../modules

 wget http://ftp.drupal.org/files/projects/panels-6.x-3.3.tar.gz
 tar xvzf panels-6.x-3.3.tar.gz
 rm panels-6.x-3.3.tar.gz
 
 wget http://ftp.drupal.org/files/projects/ctools-6.x-1.3.tar.gz
 tar xvzf ctools-6.x-1.3.tar.gz
 rm ctools-6.x-1.3.tar.gz
 
 wget http://ftp.drupal.org/files/projects/calendar-6.x-2.2.tar.gz
 tar xvzf calendar-6.x-2.2.tar.gz
 rm calendar-6.x-2.2.tar.gz

 wget http://ftp.drupal.org/files/projects/date-6.x-2.4.tar.gz
 tar xvzf date-6.x-2.4.tar.gz
 rm date-6.x-2.4.tar.gz

 wget http://ftp.drupal.org/files/projects/jquery_ui-6.x-1.3.tar.gz
 tar xvzf jquery_ui-6.x-1.3.tar.gz
 rm jquery_ui-6.x-1.3.tar.gz
 
 wget http://jquery-ui.googlecode.com/files/jquery.ui-1.6.zip
 unzip jquery.ui-1.6.zip
 rm jquery.ui-1.6.zip
 mv jquery.ui-1.6/ jquery_ui/jquery.ui
 
 wget http://ftp.drupal.org/files/projects/signup-6.x-1.0-rc6.tar.gz
 tar xvzf signup-6.x-1.0-rc6.tar.gz
 rm signup-6.x-1.0-rc6.tar.gz
 
 wget http://ftp.drupal.org/files/projects/view_unpublished-6.x-1.0.tar.gz
 tar xvzf view_unpublished-6.x-1.0.tar.gz
 rm view_unpublished-6.x-1.0.tar.gz
 
 wget http://ftp.drupal.org/files/projects/og-6.x-2.1.tar.gz
 tar xvzf og-6.x-2.1.tar.gz
 rm og-6.x-2.1.tar.gz
 
 wget http://ftp.drupal.org/files/projects/domain-6.x-2.4.tar.gz
 tar xvzf domain-6.x-2.4.tar.gz
 rm domain-6.x-2.4.tar.gz
 
 wget http://ftp.drupal.org/files/projects/domain_ctools-6.x-1.1.tar.gz
 tar xvzf domain_ctools-6.x-1.1.tar.gz
 rm domain_ctools-6.x-1.1.tar.gz

 wget http://ftp.drupal.org/files/projects/wysiwyg-6.x-2.1.tar.gz
 tar xvzf wysiwyg-6.x-2.1.tar.gz
 rm wysiwyg-6.x-2.1.tar.gz
 
 cd ../libraries/ckeditor
 wget http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.1/ckeditor_3.1.tar.gz
 tar xvzf ckeditor_3.1.tar.gz
 rm ckeditor_3.1.tar.gz
 mv -f ckeditor/* .
 mv -f ckeditor/.htaccess .
 rmdir ckeditor
 
 cd ../tinymce
 wget http://downloads.sourceforge.net/project/tinymce/TinyMCE/3.3b2/tinymce_3_3b2.zip?use_mirror=mesh
 unzip tinymce_3_3b2.zip
 rm tinymce_3_3b2.zip
 mv -f tinymce/* .
 rmdir tinymce
 
 cd ../../modules

 wget http://ftp.drupal.org/files/projects/nodehierarchy-6.x-2.0-dev.tar.gz
 tar xvzf nodehierarchy-6.x-2.0-dev.tar.gz
 rm nodehierarchy-6.x-2.0-dev.tar.gz
 
 wget http://ftp.drupal.org/files/projects/ldap_integration-6.x-1.0-beta2.tar.gz
 tar xvzf ldap_integration-6.x-1.0-beta2.tar.gz
 rm ldap_integration-6.x-1.0-beta2.tar.gz
 
 wget http://ftp.drupal.org/files/projects/ldap_provisioning-6.x-1.0-beta1.tar.gz
 tar xvzf ldap_provisioning-6.x-1.0-beta1.tar.gz
 rm ldap_provisioning-6.x-1.0-beta1.tar.gz
 
 wget http://ftp.drupal.org/files/projects/diff-6.x-2.1-alpha3.tar.gz
 tar xvzf diff-6.x-2.1-alpha3.tar.gz
 rm diff-6.x-2.1-alpha3.tar.gz
 
 wget http://ftp.drupal.org/files/projects/twitter-6.x-3.0-beta2.tar.gz
 tar xvzf twitter-6.x-3.0-beta2.tar.gz
 rm twitter-6.x-3.0-beta2.tar.gz

 wget http://ftp.drupal.org/files/projects/share-6.x-2.0-alpha2.tar.gz
 tar xvzf share-6.x-2.0-alpha2.tar.gz
 rm share-6.x-2.0-alpha2.tar.gz
 
 wget http://ftp.drupal.org/files/projects/sharethis-6.x-1.8.tar.gz
 tar xvzf sharethis-6.x-1.8.tar.gz
 rm sharethis-6.x-1.8.tar.gz
 
 wget http://ftp.drupal.org/files/projects/captcha-6.x-2.1.tar.gz
 tar xvzf captcha-6.x-2.1.tar.gz
 rm captcha-6.x-2.1.tar.gz
 
 wget http://ftp.drupal.org/files/projects/recaptcha-6.x-1.4.tar.gz
 tar xvzf recaptcha-6.x-1.4.tar.gz
 rm recaptcha-6.x-1.4.tar.gz
 
 wget http://ftp.drupal.org/files/projects/cck-6.x-3.x-dev.tar.gz
 tar xvzf cck-6.x-3.x-dev.tar.gz
 rm cck-6.x-3.x-dev.tar.gz
 
 wget http://ftp.drupal.org/files/projects/views-6.x-3.0-alpha2.tar.gz
 tar xvzf views-6.x-3.0-alpha2.tar.gz
 rm views-6.x-3.0-alpha2.tar.gz
 
 wget http://ftp.drupal.org/files/projects/i18n-6.x-1.3.tar.gz
 tar xvzf i18n-6.x-1.3.tar.gz
 rm i18n-6.x-1.3.tar.gz
 
 wget http://ftp.drupal.org/files/projects/taxonomy_access-6.x-1.0.tar.gz
 tar xvzf taxonomy_access-6.x-1.0.tar.gz
 rm taxonomy_access-6.x-1.0.tar.gz
 
 wget http://ftp.drupal.org/files/projects/admin_menu-6.x-3.0-alpha4.tar.gz
 tar xvzf admin_menu-6.x-3.0-alpha4.tar.gz
 rm admin_menu-6.x-3.0-alpha4.tar.gz

 wget http://ftp.drupal.org/files/projects/corner-6.x-2.1.tar.gz
 tar xvzf corner-6.x-2.1.tar.gz
 rm corner-6.x-2.1.tar.gz

 # multisite  setup (via domain access rather than a real multisite setup)
 
 wget http://ftp.drupal.org/files/projects/domain-6.x-2.1.tar.gz
 tar xvzf domain-6.x-2.1.tar.gz
 rm domain-6.x-2.1.tar.gz

 # domain setup has to be done in the next step.
 cd ../../..
 cp sites/default/default.settings.php sites/default/settings.php
 chmod a+w sites/default/settings.php