<?php

/**
 * @file
 * Process theme data.
 *
 * Use this file to run your theme specific implimentations of theme functions,
 * such preprocess, process, alters, and theme function overrides.
 *
 * Preprocess and process functions are used to modify or create variables for
 * templates and theme functions. They are a common theming tool in Drupal, often
 * used as an alternative to directly editing or adding code to templates. Its
 * worth spending some time to learn more about these functions - they are a
 * powerful way to easily modify the output of any template variable.
 * 
 * Preprocess and Process Functions SEE: http://drupal.org/node/254940#variables-processor
 * 1. Rename each function and instance of "pps_default" to match
 *    your subthemes name, e.g. if your theme name is "footheme" then the function
 *    name will be "footheme_preprocess_hook". Tip - you can search/replace
 *    on "pps_default".
 * 2. Uncomment the required function to use.
 */


/**
 * Preprocess variables for the html template.
 */
/* -- Delete this line to enable.
function pps_default_preprocess_html(&$vars) {
  global $theme_key;

  // Two examples of adding custom classes to the body.
  
  // Add a body class for the active theme name.
  // $vars['classes_array'][] = drupal_html_class($theme_key);

  // Browser/platform sniff - adds body classes such as ipad, webkit, chrome etc.
  // $vars['classes_array'][] = css_browser_selector();

}
// */


/**
 * Process variables for the html template.
 */
/* -- Delete this line if you want to use this function
function pps_default_process_html(&$vars) {
}
// */


/**
 * Override or insert variables for the page templates.
 */
/* -- Delete this line if you want to use these functions
function pps_default_preprocess_page(&$vars) {
}
function pps_default_process_page(&$vars) {
}
// */


/**
 * Override or insert variables into the node templates.
 */

function pps_default_preprocess_node(&$vars) {
	$date['month'] = '<span class="month">' . format_date($vars['created'], 'custom', 'M') . '</span>';
	$date['day'] = '<span class="day">' . format_date($vars['created'], 'custom', 'd') . '</span>';
	$date['year'] = '<span class="year">' . format_date($vars['created'], 'custom', 'Y') . '</span>';
	
	// Publication date, formatted with time element
  $vars['publication_date'] = '<time class="icon" datetime="' . $vars['datetime'] . '" pubdate="pubdate">' . implode('', $date) . '</time>';
  // $vars['comment_count'] = $vars['comment_count'] + 12323;
  if ($vars['comment_count'] > 0 ) {
    $vars['comment_badge'] = '<span class="comment_count">' . $vars['comment_count'] . '</span>';
  }
  else {
    $vars['comment_badge'] = '';
  }
	
	// Build the submitted variable used by default in node templates
  if (variable_get('node_submitted_' . $vars['node']->type, TRUE)) {
    $vars['submitted'] = $vars['name'] . $vars['publication_date'] . $vars['comment_badge'];
  }
  else {
    $vars['submitted'] = '';
  }
}
/* -- Delete this line if you want to use these functions
function pps_default_process_node(&$vars) { 
}
// */


/**
 * Override or insert variables into the comment templates.
 */
/* -- Delete this line if you want to use these functions
function pps_default_preprocess_comment(&$vars) {
}
function pps_default_process_comment(&$vars) {
}
// */


/**
 * Override or insert variables into the block templates.
 */
/* -- Delete this line if you want to use these functions
function pps_default_preprocess_block(&$vars) {
}

function pps_default_process_block(&$vars) {
}
// */
