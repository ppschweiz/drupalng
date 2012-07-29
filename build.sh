#! /bin/bash

rm -rf public
drush make pps.make public
rm -rf public/sites/default
ln -s ../../sites/default public/sites/default
ln -s ../../../../themes/pps_default public/sites/all/themes/pps_default
ln -s ../../../../modules/ public/sites/all/modules/custom
svn export http://textpattern.googlecode.com/svn/releases/4.3.0/source/textpattern/lib/classTextile.php public/sites/all/modules/contrib/textile/include/classTextile.php
