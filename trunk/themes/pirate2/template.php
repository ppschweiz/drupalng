<?php
// $Id: template.php,v 1.17.2.1 2009/02/13 06:47:44 johnalbin Exp $

/**
 * @file
 * Contains theme override functions and preprocess functions for the theme.
 *
 * ABOUT THE TEMPLATE.PHP FILE
 *
 *   The template.php file is one of the most useful files when creating or
 *   modifying Drupal themes. You can add new regions for block content, modify
 *   or override Drupal's theme functions, intercept or make additional
 *   variables available to your theme, and create custom PHP logic. For more
 *   information, please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/theme-guide
 *
 * OVERRIDING THEME FUNCTIONS
 *
 *   The Drupal theme system uses special theme functions to generate HTML
 *   output automatically. Often we wish to customize this HTML output. To do
 *   this, we have to override the theme function. You have to first find the
 *   theme function that generates the output, and then "catch" it and modify it
 *   here. The easiest way to do it is to copy the original function in its
 *   entirety and paste it here, changing the prefix from theme_ to STARTERKIT_.
 *   For example:
 *
 *     original: theme_breadcrumb()
 *     theme override: STARTERKIT_breadcrumb()
 *
 *   where STARTERKIT is the name of your sub-theme. For example, the
 *   zen_classic theme would define a zen_classic_breadcrumb() function.
 *
 *   If you would like to override any of the theme functions used in Zen core,
 *   you should first look at how Zen core implements those functions:
 *     theme_breadcrumbs()      in zen/template.php
 *     theme_menu_item_link()   in zen/template.php
 *     theme_menu_local_tasks() in zen/template.php
 *
 *   For more information, please visit the Theme Developer's Guide on
 *   Drupal.org: http://drupal.org/node/173880
 *
 * CREATE OR MODIFY VARIABLES FOR YOUR THEME
 *
 *   Each tpl.php template file has several variables which hold various pieces
 *   of content. You can modify those variables (or add new ones) before they
 *   are used in the template files by using preprocess functions.
 *
 *   This makes THEME_preprocess_HOOK() functions the most powerful functions
 *   available to themers.
 *
 *   It works by having one preprocess function for each template file or its
 *   derivatives (called template suggestions). For example:
 *     THEME_preprocess_page    alters the variables for page.tpl.php
 *     THEME_preprocess_node    alters the variables for node.tpl.php or
 *                              for node-forum.tpl.php
 *     THEME_preprocess_comment alters the variables for comment.tpl.php
 *     THEME_preprocess_block   alters the variables for block.tpl.php
 *
 *   For more information on preprocess functions and template suggestions,
 *   please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/node/223440
 *   and http://drupal.org/node/190815#template-suggestions
 */

/**
 * Override or insert variables into all templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered (name of the .tpl.php file.)
 */
/* -- Delete this line if you want to use this function
function pirate2_preprocess(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the page templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
/* -- Delete this line if you want to use this function
function pirate2_preprocess_page(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the node templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
/* -- Delete this line if you want to use this function
function pirate2_preprocess_node(&$vars, $hook) {
    print_r($vars);
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function pirate2_preprocess_block(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');
}
// */

// *** Implementation ***

/**
 * Implementation of HOOK_theme().
 */
function pirate2_theme(&$existing, $type, $theme, $path) 
{
	$hooks = zen_theme($existing, $type, $theme, $path);
  
	$hooks['piratenavi'] =  array(
		'template' => 'piratenavi',
		'arguments' => array('menu' => NULL)
	);

	$hooks['piratesubnavi'] =  array(
		'template' => 'piratesubnavi',
		'arguments' => array('menu' => NULL)
	);

	return $hooks;
}


/**
 * Override or insert variables into the comment templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
function pirate2_preprocess_comment(&$vars, $hook)
{
        $vars['day'] = date('j',$vars['comment']->timestamp).'.';
        $vars['month'] = date('M',$vars['comment']->timestamp).'.';
        $vars['year'] = date('Y',$vars['comment']->timestamp).'.';
}


/**
 * Preproccess Search Form 
 */
function pirate2_preprocess_search_theme_form(&$vars, $hook) 
{
	// Set a default value for the search box
	$vars['form']['search_theme_form']['#title'] = '';
	$vars['form']['search_theme_form']['#attributes'] = array('class' => t('suchtext'));
	
	// Rebuild the rendered version (search form only, rest remains unchanged)
	unset($vars['form']['search_theme_form']['#printed']);
	$vars['search']['search_theme_form'] = drupal_render($vars['form']['search_theme_form']);

	// Change the text on the submit button
	$vars['form']['submit']['#attributes'] = array('class' => t('suchen'));

	// Rebuild the rendered version (submit button, rest remains unchanged)
	unset($vars['form']['submit']['#printed']);
	$vars['search']['submit'] = drupal_render($vars['form']['submit']);
}

/**
 * Theme override for theme_menu_item
 */
function pirate2_menu_item($link, $has_children, $menu = '', $in_active_trail = FALSE, $extra_class = NULL) 
{
	$class = ($menu ? 'expanded' : ($has_children ? 'collapsed' : 'leaf'));
	if (!empty($extra_class)) {
		$class .= ' '. $extra_class;
	}
	if ($in_active_trail) {
		$class .= ' active-trail';
	}
	
	// Add unique identifier
	static $item_id = 0;
	$item_id += 1;
	$id .= ' ' . 'menu-item-custom-id-' . $item_id;

	// Add semi-unique class
	$class .= ' ' . preg_replace("/[^a-zA-Z0-9]/", "", strip_tags($link));
 
	return '<li class="'. $class .'" id="' . $id . '">'. $link . $menu ."</li>\n";

}

/**
 * Theme override for theme_menu_item_link
 */
function pirate2_menu_item_link($link) 
{
	if (empty($link['localized_options'])) {
		$link['localized_options'] = array();
	}

	// If an item is a LOCAL TASK, render it as a tab
	if ($link['type'] & MENU_IS_LOCAL_TASK) {
		$link['title'] = '<span class="tab">' . check_plain($link['title']) . '</span>';
		$link['localized_options']['html'] = TRUE;
	} else {

	}

	return l($link['title'], $link['href'], $link['localized_options']);
}

/**
 * Theme override for theme_menu_item_tree
 */
function pirate2_menu_tree($tree) 
{
	return '<ul class="menu">'. $tree .'</ul>';
}

/**
 * Theme override for theme_breadcrumb
 */
function pirate2_breadcrumb($breadcrumb) {
	$breadcrumb_separator = "<em> / </em>";

	$html = '<div class="contbodykopf"><div class="kopf"><div id="breadcrumb">';
	array_shift($breadcrumb);
	$html.= l('', $front_page, array('attributes' => array('class'=>'home')));
	$html.= $breadcrumb_separator;

	if (count($breadcrumb) > 0) 
	{
        	$html.= implode($breadcrumb_separator, $breadcrumb);
		$html.= $breadcrumb_separator;
	}

        $html.= drupal_get_title();
	$html.= '</div></div></div>';

	return $html;
}

function pirateparty_preprocess_node(&$vars)
{
}

$handle_multiple_dates = array();

function pirate2_preprocess_node(&$vars, $hook) 
{
    $nodetype = content_types($vars['type']);

    foreach($nodetype['fields'] as $fields) 
    {
            if ($fields['type'] == 'datetime')  
            {
                    $fieldname = $fields['field_name'];
            }
    }

	// Special classes for nodes
	$classes = array('node');
	if ($vars['sticky']) {
		$classes[] = 'sticky';
	}
	if (!$vars['status']) {
		$classes[] = 'node-unpublished';
		$vars['unpublished'] = TRUE;
	}
	else 
	{
		$vars['unpublished'] = FALSE;
	}
	if ($vars['uid'] && $vars['uid'] == $GLOBALS['user']->uid) {
		$classes[] = 'node-mine'; // Node is authored by current user.
	}
	if ($vars['teaser']) {
		$classes[] = 'node-teaser'; // Node is displayed as teaser.
	}
	
	// Class for node type: "node-type-page", "node-type-story", "node-type-my-custom-type", etc.
	$classes[] = zen_id_safe('node-type-' . $vars['type']);
	$vars['classes'] = implode(' ', $classes); // Concatenate with spaces

	if (isset($fieldname))
	{
		global $handle_multiple_dates;
		if(!isset($handle_multiple_dates[$vars['nid']]))
		{
			$handle_multiple_dates[$vars['nid']] = 0;
		}
		do
		{
			print $handle_multiple_dates[$vars['nid']];
			print $vars[$fieldname][$handle_multiple_dates[$vars['nid']]]['value'];
			$handle_multiple_dates[$vars['nid']]++;
			$xtime = strtotime($vars[$fieldname][$handle_multiple_dates[$vars['nid']]-1]['value']);
			$vars['day'] = date('j', $xtime).'.';
			$vars['month'] = date('M', $xtime).'.';
			$vars['year'] = date('Y', $xtime).'.';
		} 
		while($xtime < time() - (24 * 60 * 60) && $vars[$fieldname][$handle_multiple_dates[$vars['nid']]]);
	}
	else
	{
		$vars['day'] = date('j',$vars['created']).'.';
		$vars['month'] = date('M',$vars['created']).'.';
        $vars['year'] = date('Y',$vars['created']).'.';
	}
}
