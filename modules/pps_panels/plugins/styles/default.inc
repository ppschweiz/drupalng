<?php
/**
 * @file
 * Default pps panel style
 */

// Plugin definition.
$plugin = array(
  'title' => t('PPS Display'),
  'description' => t('Default display style for the pps theme.'),
  'render region' => 'pps_panels_default_region',
  'render pane' => 'pps_panels_default_pane',
  'settings form' => 'pps_panels_default_settings_form',
  'pane settings form' => 'pps_panels_default_settings_form',
);

/**
 * Region settings form callback.
 */
function pps_panels_default_settings_form($style_settings) {
  $default_value = isset($style_settings['style']) ? $style_settings['style'] : 'neutral';
  $form['style'] = array(
    '#title' => t('Style'),
    '#description' => t('Select the style.'),
    '#type' => 'select',
    '#default_value' => $default_value,
    '#options' => array(
      'neutral' => t('Neutral') ,
      'colored' => t('Colored') ,
    ),
  );
  return $form;
}
