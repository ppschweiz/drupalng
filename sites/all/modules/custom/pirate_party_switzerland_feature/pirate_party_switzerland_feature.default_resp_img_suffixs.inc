<?php
/**
 * @file
 * pirate_party_switzerland_feature.default_resp_img_suffixs.inc
 */

/**
 * Implements hook_default_resp_img_suffixs().
 */
function pirate_party_switzerland_feature_default_resp_img_suffixs() {
  $export = array();

  $resp_img_suffix = new stdClass();
  $resp_img_suffix->disabled = FALSE; /* Edit this to true to make a default resp_img_suffix disabled initially */
  $resp_img_suffix->api_version = 1;
  $resp_img_suffix->name = 'desktop';
  $resp_img_suffix->label = 'Desktop';
  $resp_img_suffix->suffix = '_desktop';
  $resp_img_suffix->breakpoint = 1025;
  $export['desktop'] = $resp_img_suffix;

  $resp_img_suffix = new stdClass();
  $resp_img_suffix->disabled = FALSE; /* Edit this to true to make a default resp_img_suffix disabled initially */
  $resp_img_suffix->api_version = 1;
  $resp_img_suffix->name = 'mobileland';
  $resp_img_suffix->label = 'Mobile Landscape';
  $resp_img_suffix->suffix = '_mobileland';
  $resp_img_suffix->breakpoint = 341;
  $export['mobileland'] = $resp_img_suffix;

  $resp_img_suffix = new stdClass();
  $resp_img_suffix->disabled = FALSE; /* Edit this to true to make a default resp_img_suffix disabled initially */
  $resp_img_suffix->api_version = 1;
  $resp_img_suffix->name = 'mobileport';
  $resp_img_suffix->label = 'Mobile Portrait';
  $resp_img_suffix->suffix = '_mobileport';
  $resp_img_suffix->breakpoint = 0;
  $export['mobileport'] = $resp_img_suffix;

  $resp_img_suffix = new stdClass();
  $resp_img_suffix->disabled = FALSE; /* Edit this to true to make a default resp_img_suffix disabled initially */
  $resp_img_suffix->api_version = 1;
  $resp_img_suffix->name = 'tabletland';
  $resp_img_suffix->label = 'Tablet Landscape';
  $resp_img_suffix->suffix = '_tabletland';
  $resp_img_suffix->breakpoint = 769;
  $export['tabletland'] = $resp_img_suffix;

  $resp_img_suffix = new stdClass();
  $resp_img_suffix->disabled = FALSE; /* Edit this to true to make a default resp_img_suffix disabled initially */
  $resp_img_suffix->api_version = 1;
  $resp_img_suffix->name = 'tabletport';
  $resp_img_suffix->label = 'Tablet Portrait';
  $resp_img_suffix->suffix = '_tabletport';
  $resp_img_suffix->breakpoint = 481;
  $export['tabletport'] = $resp_img_suffix;

  return $export;
}
