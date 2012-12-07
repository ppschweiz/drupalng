#! /bin/bash

rm -rf www

drush make pps.make www --translations=de,fr,it

rm -r www/sites/default
ln -s ../../sites/default www/sites/default

ln -s ../../../../themes/pps_default www/sites/all/themes/pps_default
ln -s ../../../../modules/ www/sites/all/modules/custom
