<?php

include_once(drupal_get_path('theme', 'pps_theme_base') . '/includes/theme.inc');

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
 * 1. Rename each function and instance of "pps_theme_base" to match
 *    your subthemes name, e.g. if your theme name is "footheme" then the function
 *    name will be "footheme_preprocess_hook". Tip - you can search/replace
 *    on "pps_theme_base".
 * 2. Uncomment the required function to use.
 */


/**
 * Preprocess variables for the html template.
 */
/* -- Delete this line to enable.
function pps_theme_base_preprocess_html(&$vars) {
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
function pps_theme_base_process_html(&$vars) {
}
// */


/**
 * Override or insert variables for the page templates.
 */
/* -- Delete this line if you want to use these functions
function pps_theme_base_preprocess_page(&$vars) {
}
function pps_theme_base_process_page(&$vars) {
}
// */


/**
 * Override or insert variables into the node templates.
 */
function pps_theme_base_preprocess_node(&$vars) {
  // Build the date_icon variable used in node templates
  $node_type = $vars['node']->type;
  $show_submitted = variable_get('node_submitted_' . $node_type , TRUE);
  $always_show_date_icon = variable_get('node_date_icon_show_always_' . $node_type , FALSE);
  $show_date_icon = $show_submitted || $always_show_date_icon;

  // Prevent the date icon to appear twice if the rendered node is placed
  // inside a region.
  if ($node_type == 'panel') {
    if (!empty($vars['content']['#bundle'])) {
      $show_date_icon = FALSE;
      $vars['display_submitted'] = FALSE;
    }
  }

  if ($show_date_icon) {
    $date_template =<<<EOF
<time datetime="!datetime" pubdate="pubdate" title='!title' class="icon">
  <span class='month'>!month</span>
  <span class='day'>!day</span>
  <span class='year'>!year</span>
</time>
EOF;
    $date_time = $vars['datetime'];
    $date = $vars['date'];
    $created = $vars['created'];
    $field_name = variable_get('node_date_icon_use_field_' . $node_type , FALSE);
    if ($field_name) {
      $field_date = field_get_items('node', $vars['node'], $field_name);
      $field_date = $field_date[0];
      $date_time = format_date($vars['created'], 'custom', 'Y-m-d\TH:i:sO'); // PHP 'c' format is not proper ISO8601!
      $date = format_date($field_date['value']);
      $created = $field_date['value'];
    }

    $date_args = array(
      '!datetime' => $date_time,
      '!title' => $date,
      '!year' => format_date($created, 'custom', 'Y'),
      '!month' => format_date($created, 'custom', 'M'),
      '!day' => format_date($created, 'custom', 'd'),
    );
    $vars['date_icon'] = format_string($date_template, $date_args);
    $vars['classes_array'][] = 'with-date-icon';
  }
  else {
    $vars['date_icon'] = '';
    $vars['classes_array'][] = 'without-date-icon';
  }
}
/* -- Delete this line if you want to use these functions
function pps_theme_base_process_node(&$vars) {
}
// */


/**
 * Override or insert variables into the comment templates.
 */
/* -- Delete this line if you want to use these functions
function pps_theme_base_preprocess_comment(&$vars) {
}
function pps_theme_base_process_comment(&$vars) {
}
// */

/**
 * Override or insert variables into the region templates.
 */
/* -- Delete this line if you want to use these functions
function pps_theme_base_preprocess_region(&$vars) {
}
// */
function pps_theme_base_process_region(&$vars) {
  $regions = array(
    'footer',
    'leaderboard',
  );
  if (in_array($vars['region'], $regions)) {
    $vars['inner_prefix'] = '<div class="region-inner container clearfix">';
  }
}
// */

/**
 * Override or insert variables into the block templates.
 */
/* -- Delete this line if you want to use these functions
function pps_theme_base_preprocess_block(&$vars) {
}
function pps_theme_base_process_block(&$vars) {
}
// */
