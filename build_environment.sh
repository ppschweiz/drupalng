#! /bin/bash

chmod +w sites/default
rm sites/default/settings.php

cd www/sites/default

drush si --db-url=mysql://root:@127.0.0.1/drupal --account-pass=q -y minimal

drush en admin_menu_toolbar -y
drush en diff -y

drush en pps_i18n -y
drush cc all
drush fr pps_i18n -y
drush l10n-update
drush cc all

drush en domain --uri=http://piratenpartei.ch -y
chmod +w ../../sites/default ../../sites/default/settings.php
cat <<EOF >> settings.php

/**
 * Enable Domain Access
 */
include DRUPAL_ROOT . '/sites/all/modules/contrib/domain/settings.inc';

EOF

drush en pps_domain -y
drush cc nodeaccess
drush cc all
drush fr pps_domain -y
drush cc all

cd -