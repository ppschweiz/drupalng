#! /bin/bash

rm -rf public

drush make pps.make public --translations=de,fr,it

rm -r public/sites/default
ln -s ../../default public/sites/default

ln -s ../../../../themes/pps_default public/sites/all/themes/pps_default
ln -s ../../../../modules/ public/sites/all/modules/custom

svn export http://textpattern.googlecode.com/svn/releases/4.3.0/source/textpattern/lib/classTextile.php public/sites/all/modules/contrib/textile/include/classTextile.php

curl http://downloads.jasig.org/cas-clients/php/current.tgz | tar xzC public/sites/all/libraries
read -r name < <(curl -s http://downloads.jasig.org/cas-clients/php/current.tgz | tar tz)
ln -s ./$name public/sites/all/libraries/CAS
