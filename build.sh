#! /bin/bash

rm -rf public

drush make pps.make public --translations=de,fr,it

rm -r public/sites/default
ln -s ../../default public/sites/default

ln -s ../../../../themes/pps_default public/sites/all/themes/pps_default
ln -s ../../../../modules/ public/sites/all/modules/custom

if [ -f ./envbuild.sh ]
then
  ./envbuild.sh
fi