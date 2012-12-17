#! /bin/bash

rm -rf www

drush make pps.make www --no-cache --translations=de,fr,it

rm -r www/sites/default
ln -s ../../sites/default www/sites/default

ln -s ../../../../themes/pps-theme-base www/sites/all/themes/pps-theme-base
ln -s ../../../../modules/ www/sites/all/modules/custom
