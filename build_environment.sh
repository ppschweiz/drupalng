#! /bin/bash

# ./build_environment.sh piratenpartei.ch mysql://root:@127.0.0.1/drupal ~/Library/Haskell/bin

usage()
{
cat <<EOF
Call script with arguments: domain db_url
Example:
./build_environment.sh example.com mysql://root:password@localhost/database

If no database url is provided mysql://root:@127.0.0.1/drupal will be used.

If pandoc can not be found in your path ypu can provide the path to pandoc
as a third argument.
EOF
}

if [ $# -eq 0 ]; then
  usage
  exit
fi

DOMAIN=$1
DB_URL=$2
if [ -z $DB_URL ]; then
  DB_URL=mysql://root:@127.0.0.1/drupal
fi
PANDOC=$3

chmod +w sites/default
rm sites/default/settings.php


# In case the work space path does not exists, build the codebase
if [ ! -d "www" ]; then
  ./build_codebase.sh
fi

cd www/sites/default

cat <<EOF

================ Install sites ================
EOF

drush si --db-url=${DB_URL} --account-name=admin --account-pass=q -y minimal

cat <<EOF

============= Enable misc modules =============
EOF

drush en admin_menu_toolbar -y
drush en diff -y

cat <<EOF

================= Enable i18n =================
EOF

drush en pps_i18n -y
drush cc all
drush fr pps_i18n -y
drush l10n-update
drush cc all

cat <<EOF

================ Enable domain ================
EOF

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

cat <<EOF

================== Enable CAS ==================
EOF

drush en pps_cas_auth -y
drush cc all

cat <<EOF

========= Enable content related stuff =========
EOF

drush en pps_formatting -y
drush cc all
drush en pps_content_types -y
drush cc all

cat <<EOF

================ Migrate content ===============
EOF

drush en pps_migrate_d6 -y
if [ -n $PANDOC ]; then
  drush vset shell_cmd_pandoc ${PANDOC}/pandoc
fi
drush vset migrate_disabled_handlers 'a:1:{i:0;s:23:"MigrateTextFieldHandler";}'
drush cc all
drush mi --all

cd -