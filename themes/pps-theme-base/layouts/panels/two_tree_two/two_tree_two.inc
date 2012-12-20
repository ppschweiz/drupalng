<?php

/**
 * @file
 * Implementation of hook_panels_layouts
 */
function pps_theme_base_two_tree_two_panels_layouts() {
  $items['two_tree_two'] = array(
    'title'    => t('Seven in three'),
    'category' => t('Pirate Party Switzerland'),
    'icon'     => 'two_tree_two.png',
    'theme'    => 'two_tree_two',
    'admin css' => 'two_tree_two.admin.css',
    'theme arguments' => array('id', 'content'),
    'regions' => array(
      'two_tree_two_above_first' => t('Above Left'),
      'two_tree_two_above_second' => t('Above Right'),
      'two_tree_two_first'  => t('Left'),
      'two_tree_two_second' => t('Center'),
      'two_tree_two_third'  => t('Right'),
      'two_tree_two_below_first' => t('Below Left'),
      'two_tree_two_below_second' => t('Below Right'),
    ),
    // AT Core
    'type' => 'seven',
    'options' => array(
      'two_tree_two' => 'default',
    ),
    'styles' => array(
      'two_tree_two' => array(
        'css' => array(
          '232' => array('.two_tree_two > .region' => 'width:33.333333%'),
          '232af' => array('.two_tree_two > .region-two-tree-two-above-first' => 'width:66.666666%'),
          '232as' => array('.two_tree_two > .region-two-tree-two-above-second' => 'width:33.333333%'),
          '232bf' => array('.two_tree_two > .region-two-tree-two-below-first' => 'width:33.333333%'),
          '232bs' => array('.two_tree_two > .region-two-tree-two-below-second' => 'width:66.666666%'),
        ),
      ),
    ),
  );

  return $items;
}

/**
 * Preprocess variables for two_tree_two.tpl.php
 */
function template_preprocess_two_tree_two(&$vars) {
  $vars['panel_prefix'] = '';
  $vars['panel_suffix'] = '';
}
