<?php

/**
 * @file
 * Generate form elments for the Page Layout settings.
 */

// Get an array of device groups with option values
$device_group_options = responsive_page_layouts_device_group_options($theme_name);

// Assign $options for each device group
foreach ($device_group_options as $device_group => $options) {

  // About here we need to call a custom sort function, this is what we got for now
  sort($options, SORT_NUMERIC);

  foreach ($options as $option) {
    if ($device_group === 'bigscreen') {
      $bigscreen_options[$option] = drupal_ucfirst(str_replace('_', ' ', $option)); // human readable option names for accessibility
    }
    if ($device_group === 'tablet_landscape') {
      $tablet_landscape_options[$option] = drupal_ucfirst(str_replace('_', ' ', $option));
    }
    if ($device_group === 'tablet_portrait') {
      $tablet_portrait_options[$option] = drupal_ucfirst(str_replace('_', ' ', $option));
    }
    if ($device_group === 'smartphone_landscape') {
      $smartphone_landscape_options[$option] = drupal_ucfirst(str_replace('_', ' ', $option));
    }
  }
}

// CSS for the layout sprite icons
$page_layout_css_files = responsive_plugins_admin_css($theme_name, $plugin_type = 'page_layout');
foreach ($page_layout_css_files as $filepath) {
  if (file_exists($filepath)) {
    $page_layout_css['css'][] = array('type' => 'file', 'data' => $filepath, 'weight' => 100);
  }
}

// Unit options
$unit_options = array('%' => '%', 'px' => 'px', 'em' => 'em');

// Set a message for when responsive layout is turned off
$disable_message = t('<p>The responsive layout is disabled, only the Standard layout is now used.</p><p>To re-enable uncheck the "Disable responsive layout and styles" checkbox under the "Settings" tab.</p>');


/*****************************************************************************
 *
 * Bigscreen (standard-layout)
 *
 ****************************************************************************/

$form['at-settings']['bigscreen'] = array(
  '#type' => 'fieldset',
  '#title' => t('Standard Layout'),
  '#description' => t('<h3>Standard Layout</h3><p>The standard layout is for desktops, laptops and other large screen devices.'),
  '#attached' => $page_layout_css,
  '#attributes' => array(
    'class' => array('at-layout-form'),
  ),
);

// Bigscreen Layout
$form['at-settings']['bigscreen']['bigscreen-layout-wrapper'] = array(
  '#type' => 'fieldset',
  '#title' => t('Choose sidebar layout'),
);

// Options
$form['at-settings']['bigscreen']['bigscreen-layout-wrapper']['bigscreen_layout'] = array(
  '#type' => 'radios',
  '#title' => t('<strong>Choose sidebar positions</strong>'),
  '#default_value' => str_replace('-', '_', at_get_setting('bigscreen_layout')), // avoid "illigal choice" errors in 7.x-2.x sub-themes.
  '#options' => $bigscreen_options,
);

// Sidebars
$form['at-settings']['bigscreen']['bigscreen-sidebar-wrapper'] = array(
  '#type' => 'fieldset',
  '#title' => t('Set sidebar widths'),
  '#description' => t('<strong>Set the width of each sidebar</strong>'),
);

// Units
$form['at-settings']['bigscreen']['bigscreen-sidebar-wrapper']['bigscreen_sidebar_unit'] = array(
  '#type' => 'select',
  '#title' => t('Unit'),
  '#default_value' => at_get_setting('bigscreen_sidebar_unit'),
  '#options' => $unit_options,
);

// Sidebar first
$form['at-settings']['bigscreen']['bigscreen-sidebar-wrapper']['bigscreen_sidebar_first'] = array(
  '#type' => 'textfield',
  '#title' => t('First sidebar'),
  '#default_value' => check_plain(at_get_setting('bigscreen_sidebar_first')),
  '#size' => 4,
  '#maxlenght' => 4,
  '#states' => array(
    'required' => array(
      array('input[name="bigscreen_layout"]' => array('value' => 'three_col_grail')),
      array('input[name="bigscreen_layout"]' => array('value' => 'two_sidebars_left')),
      array('input[name="bigscreen_layout"]' => array('value' => 'two_sidebars_right')),
    ),
  ),
);

// Sidebar second
$form['at-settings']['bigscreen']['bigscreen-sidebar-wrapper']['bigscreen_sidebar_second'] = array(
  '#type' => 'textfield',
  '#title' => t('Second sidebar'),
  '#default_value' => check_plain(at_get_setting('bigscreen_sidebar_second')),
  '#size' => 4,
  '#maxlenght' => 4,
  '#states' => array(
    'required' => array(
      array('input[name="bigscreen_layout"]' => array('value' => 'three_col_grail')),
      array('input[name="bigscreen_layout"]' => array('value' => 'two_sidebars_left')),
      array('input[name="bigscreen_layout"]' => array('value' => 'two_sidebars_right')),
    ),
  ),
);

// Page width
$form['at-settings']['bigscreen']['bigscreen-width-wrapper'] = array(
  '#type' => 'fieldset',
  '#title' => t('Set the page width'),
  '#description' => t('<strong>Set the page width</strong>'),
);

// Unit
$form['at-settings']['bigscreen']['bigscreen-width-wrapper']['bigscreen_page_unit'] = array(
  '#type' => 'select',
  '#title' => t('Unit'),
  '#default_value' => at_get_setting('bigscreen_page_unit'),
  '#options' => $unit_options,
);

// Width
$form['at-settings']['bigscreen']['bigscreen-width-wrapper']['bigscreen_page_width'] = array(
  '#type'  => 'textfield',
  '#title' => t('Page width'),
  '#default_value' => check_plain(at_get_setting('bigscreen_page_width')),
  '#size' => 4,
  '#maxlenght' => 4,
  '#required' => TRUE,
);

// Max width
$form['at-settings']['bigscreen']['bigscreen-maxwidth-wrapper'] = array(
  '#type' => 'fieldset',
  '#title' => t('Set a max width'),
  '#states' => array(
    'visible' => array('select[name="bigscreen_page_unit"]' => array('value' => '%')),
  ),
);

// Max width checkbox
$form['at-settings']['bigscreen']['bigscreen-maxwidth-wrapper']['bigscreen_set_max_width'] = array(
  '#type' => 'checkbox',
  '#title' => t('Set a max width'),
  '#default_value' => at_get_setting('bigscreen_set_max_width'),
);

// Max width unit
$form['at-settings']['bigscreen']['bigscreen-maxwidth-wrapper']['bigscreen_max_width_unit'] = array(
  '#type' => 'select',
  '#title' => t('Unit'),
  '#default_value' => at_get_setting('bigscreen_max_width_unit'),
  '#options' => array('px' => 'px', 'em' => 'em'),
  '#states' => array(
    'visible' => array('input[name="bigscreen_set_max_width"]' => array('checked' => TRUE)),
  ),
);

// Max width value
$form['at-settings']['bigscreen']['bigscreen-maxwidth-wrapper']['bigscreen_max_width'] = array(
  '#type'  => 'textfield',
  '#title' => t('Max width'),
  '#default_value' => check_plain(at_get_setting('bigscreen_max_width')),
  '#size' => 4,
  '#maxlenght' => 4,
  '#states' => array(
    'visible' => array('input[name="bigscreen_set_max_width"]' => array('checked' => TRUE)),
    'required' => array('input[name="bigscreen_set_max_width"]' => array('checked' => TRUE)),
  ),
);

// Media queries
$form['at-settings']['bigscreen']['media-queries-wrapper'] = array(
  '#type' => 'fieldset',
  '#title' => t('Standard Screen Media Queries'),
  '#weight' => 1,
  '#attributes' => array(
    'class' => array('at-media-queries'),
  ),
);

// Media query
$form['at-settings']['bigscreen']['media-queries-wrapper']['bigscreen_media_query'] = array(
  '#type' => 'textfield',
  '#title' => t('Media query for this layout'),
  '#default_value' => check_plain(at_get_setting('bigscreen_media_query')),
  '#description' => t('Do not include @media, it\'s included automatically.'),
  '#field_prefix' => '@media',
  '#size' => 100,
  '#required' => TRUE,
);


/*****************************************************************************
 *
 * Tablet
 *
 ****************************************************************************/

$form['at-settings']['tablet'] = array(
  '#type' => 'fieldset',
  '#title' => t('Tablet Layout'),
  '#description' => t('<h3>Tablet Layout</h3><p>Tablet devices such as iPad have two orientations - landscape and portrait. You can configure a different layout for each orientation.</p>'),
  '#attributes' => array(
    'class' => array('at-layout-form'),
  ),
);

// Disabled message
if(at_get_setting('disable_responsive_styles') === 1) {
  $form['at-settings']['tablet']['disabled'] = array(
    '#markup' => '<div class="messages warning">' . $disable_message . '</div>',
  );
}


/*******************
 * Tablet landscape
 ******************/

$form['at-settings']['tablet']['landscape'] = array(
  '#type' => 'fieldset',
  '#title' => t('Landscape'),
  '#description' => t('<h4>Landscape tablet</h4>'),
  '#states' => array(
    'disabled' => array('input[name="disable_responsive_styles"]' => array('checked' => TRUE)),
  ),
);

// Tablet landscape Layout options
$form['at-settings']['tablet']['landscape']['tablet-landscape-layout-wrapper'] = array(
  '#type' => 'fieldset',
  '#title' => t('Choose sidebar layout'),
);

// Options
$form['at-settings']['tablet']['landscape']['tablet-landscape-layout-wrapper']['tablet_landscape_layout'] = array(
  '#type' => 'radios',
  '#title' => t('<strong>Choose sidebar positions</strong>'),
  '#default_value' => str_replace('-', '_', at_get_setting('tablet_landscape_layout')),
  '#options' => $tablet_landscape_options,
);

// Sidebars
$form['at-settings']['tablet']['landscape']['tablet-landscape-sidebar-width-wrapper'] = array(
  '#type' => 'fieldset',
  '#title' => t('Set sidebar widths'),
  '#description' => t('<strong>Set the width of each sidebar</strong>'),
);

// Units
$form['at-settings']['tablet']['landscape']['tablet-landscape-sidebar-width-wrapper']['tablet_landscape_sidebar_unit'] = array(
  '#type' => 'select',
  '#title' => t('Unit'),
  '#default_value' => at_get_setting('tablet_landscape_sidebar_unit'),
  '#options' => $unit_options,
);

// Sidebar first
$form['at-settings']['tablet']['landscape']['tablet-landscape-sidebar-width-wrapper']['tablet_landscape_sidebar_first'] = array(
  '#type' => 'textfield',
  '#title' => t('First sidebar'),
  '#default_value' => check_plain(at_get_setting('tablet_landscape_sidebar_first')),
  '#size' => 4,
  '#maxlenght' => 4,
  '#states' => array(
    'required' => array(
      array('input[name="tablet_landscape_layout"]' => array('value' => 'three_col_grail')),
      array('input[name="tablet_landscape_layout"]' => array('value' => 'two_sidebars_left')),
      array('input[name="tablet_landscape_layout"]' => array('value' => 'two_sidebars_left_stack')),
      array('input[name="tablet_landscape_layout"]' => array('value' => 'two_sidebars_right')),
      array('input[name="tablet_landscape_layout"]' => array('value' => 'two_sidebars_right_stack')),
    ),
  ),
);

// Sidebar second
$form['at-settings']['tablet']['landscape']['tablet-landscape-sidebar-width-wrapper']['tablet_landscape_sidebar_second'] = array(
  '#type' => 'textfield',
  '#title' => t('Second sidebar'),
  '#default_value' => check_plain(at_get_setting('tablet_landscape_sidebar_second')),
  '#size' => 4,
  '#maxlenght' => 4,
  '#states' => array(
    'invisible' => array(
      array('input[name="tablet_landscape_layout"]' => array('value' => 'two_sidebars_left_stack')),
      array('input[name="tablet_landscape_layout"]' => array('value' => 'two_sidebars_right_stack')),
    ),
    'required' => array(
      array('input[name="tablet_landscape_layout"]' => array('value' => 'three_col_grail')),
      array('input[name="tablet_landscape_layout"]' => array('value' => 'two_sidebars_left')),
      array('input[name="tablet_landscape_layout"]' => array('value' => 'two_sidebars_right')),
    ),
  ),
);

// Conditional messages for sidebar layouts
$form['at-settings']['tablet']['landscape']['tablet-landscape-sidebar-width-wrapper']['tablet-landscape-sidebar-message-wrapper'] = array(
  '#type' => 'fieldset',
  '#states' => array(
    'invisible' => array(
      array('input[name="tablet_landscape_layout"]' => array('value' => 'three_col_grail')),
      array('input[name="tablet_landscape_layout"]' => array('value' => 'two_sidebars_left')),
      array('input[name="tablet_landscape_layout"]' => array('value' => 'two_sidebars_right')),
    ),
  ),
);
$form['at-settings']['tablet']['landscape']['tablet-landscape-sidebar-width-wrapper']['tablet-landscape-sidebar-message-wrapper']['message'] = array(
  '#markup' => t('<div class="description">In this layout <em>Second sidebar</em> wraps below.</div>'),
);

// Page width
$form['at-settings']['tablet']['landscape']['tablet-landscape-page-width-wrapper'] = array(
  '#type' => 'fieldset',
  '#title' => t('Set the page width'),
  '#description' => t('<strong>Set the page width</strong>'),
);

// Unit
$form['at-settings']['tablet']['landscape']['tablet-landscape-page-width-wrapper']['tablet_landscape_page_unit'] = array(
  '#type' => 'select',
  '#title' => t('Unit'),
  '#default_value' => at_get_setting('tablet_landscape_page_unit'),
  '#options' => $unit_options,
);

// Width
$form['at-settings']['tablet']['landscape']['tablet-landscape-page-width-wrapper']['tablet_landscape_page_width'] = array(
  '#type'  => 'textfield',
  '#title' => t('Page width'),
  '#default_value' => check_plain(at_get_setting('tablet_landscape_page_width')),
  '#size' => 4,
  '#maxlenght' => 4,
  '#required' => TRUE,
);

// Media Queries
$form['at-settings']['tablet']['landscape']['tablet-landscape-media-queries-wrapper'] = array(
  '#type' => 'fieldset',
  '#title' => t('Tablet Landscape Media Queries'),
  '#weight' => 1,
  '#attributes' => array(
    'class' => array(
      'at-media-queries',
    ),
  ),
);

// Media query
$form['at-settings']['tablet']['landscape']['tablet-landscape-media-queries-wrapper']['tablet_landscape_media_query'] = array(
  '#type' => 'textfield',
  '#title' => t('Media query for this layout'),
  '#default_value' => check_plain(at_get_setting('tablet_landscape_media_query')),
  '#description' => t('Do not include @media, it\'s included automatically.'),
  '#field_prefix' => '@media',
  '#size' => 100,
  '#required' => TRUE,
);


/******************
 * Tablet portrait
 *****************/

$form['at-settings']['tablet']['portrait'] = array(
  '#type' => 'fieldset',
  '#title' => t('Portrait'),
  '#description' => t('<h4>Portrait tablet</h4>'),
  '#states' => array(
    'disabled' => array('input[name="disable_responsive_styles"]' => array('checked' => TRUE)),
  ),
);

// Tablet portrait Layout options
$form['at-settings']['tablet']['portrait']['tablet-portrait-layout-wrapper'] = array(
  '#type' => 'fieldset',
  '#title' => t('Choose sidebar layout'),
);

// Options
$form['at-settings']['tablet']['portrait']['tablet-portrait-layout-wrapper']['tablet_portrait_layout'] = array(
  '#type' => 'radios',
  '#title' => t('<strong>Choose sidebar positions</strong>'),
  '#default_value' => str_replace('-', '_', at_get_setting('tablet_portrait_layout')),
  '#options' => $tablet_portrait_options,
);

// Tablet portrait Sidebars
$form['at-settings']['tablet']['portrait']['tablet-portrait-sidebar-width-wrapper'] = array(
  '#type' => 'fieldset',
  '#title' => t('Set sidebar widths'),
  '#description' => t('<strong>Set the width of each sidebar</strong>'),
  '#states' => array(
    'invisible' => array('input[name="tablet_portrait_layout"]' => array('value' => 'one_col_stack')),
  ),
);

// Units
$form['at-settings']['tablet']['portrait']['tablet-portrait-sidebar-width-wrapper']['tablet_portrait_sidebar_unit'] = array(
  '#type' => 'select',
  '#title' => t('Unit'),
  '#default_value' => at_get_setting('tablet_portrait_sidebar_unit'),
  '#options' => $unit_options,
);

// Sidebar first
$form['at-settings']['tablet']['portrait']['tablet-portrait-sidebar-width-wrapper']['tablet_portrait_sidebar_first'] = array(
  '#type' => 'textfield',
  '#title' => t('First sidebar'),
  '#default_value' => check_plain(at_get_setting('tablet_portrait_sidebar_first')),
  '#size' => 4,
  '#maxlenght' => 4,
  '#states' => array(
    'invisible' => array(
      array('input[name="tablet_portrait_layout"]' => array('value' => 'one_col_stack')),
    ),
    'required' => array(
      array('input[name="tablet_portrait_layout"]' => array('value' => 'one_col_vert')),
      array('input[name="tablet_portrait_layout"]' => array('value' => 'two_sidebars_left_stack')),
      array('input[name="tablet_portrait_layout"]' => array('value' => 'two_sidebars_right_stack')),
    ),
  ),
);

// Sidebar second
$form['at-settings']['tablet']['portrait']['tablet-portrait-sidebar-width-wrapper']['tablet_portrait_sidebar_second'] = array(
  '#type' => 'textfield',
  '#title' => t('Second sidebar'),
  '#default_value' => check_plain(at_get_setting('tablet_portrait_sidebar_second')),
  '#size' => 4,
  '#maxlenght' => 4,
  '#states' => array(
    'invisible' => array(
      array('input[name="tablet_portrait_layout"]' => array('value' => 'one_col_stack')),
      array('input[name="tablet_portrait_layout"]' => array('value' => 'two_sidebars_left_stack')),
      array('input[name="tablet_portrait_layout"]' => array('value' => 'two_sidebars_right_stack')),
    ),
    'required' => array(
      array('input[name="tablet_portrait_layout"]' => array('value' => 'one_col_vert')),
    ),
  ),
);

// Conditional messages for sidebar layouts
$form['at-settings']['tablet']['portrait']['tablet-portrait-sidebar-width-wrapper']['tablet-portrait-sidebar-message-wrapper'] = array(
  '#type' => 'fieldset',
  '#states' => array(
    'invisible' => array(
      array('input[name="tablet_portrait_layout"]' => array('value' => 'one_col_vert')),
      array('input[name="tablet_portrait_layout"]' => array('value' => 'one_col_stack')),
    ),
  ),
);
$form['at-settings']['tablet']['portrait']['tablet-portrait-sidebar-width-wrapper']['tablet-portrait-sidebar-message-wrapper']['message'] = array(
  '#markup' => t('<div class="description">In this layout <em>Second sidebar</em> wraps below.</div>'),
);

// Tablet portrait Page width
$form['at-settings']['tablet']['portrait']['tablet-portrait-page-width-wrapper'] = array(
  '#type' => 'fieldset',
  '#title' => t('Set the page width'),
  '#description' => t('<strong>Set the page width</strong>'),
);

// Unit
$form['at-settings']['tablet']['portrait']['tablet-portrait-page-width-wrapper']['tablet_portrait_page_unit'] = array(
  '#type' => 'select',
  '#title' => t('Unit'),
  '#default_value' => at_get_setting('tablet_portrait_page_unit'),
  '#options' => $unit_options,
);

// Width
$form['at-settings']['tablet']['portrait']['tablet-portrait-page-width-wrapper']['tablet_portrait_page_width'] = array(
  '#type'  => 'textfield',
  '#title' => t('Page width'),
  '#default_value' => check_plain(at_get_setting('tablet_portrait_page_width')),
  '#size' => 4,
  '#maxlenght' => 4,
  '#required' => TRUE,
);


// Tablet portrait Media queries
$form['at-settings']['tablet']['portrait']['tablet-portrait-media-queries-wrapper'] = array(
  '#type' => 'fieldset',
  '#title' => t('Tablet Portrait Media Queries'),
  '#weight' => 1,
  '#attributes' => array(
    'class' => array('at-media-queries'),
  ),
);

// Media query
$form['at-settings']['tablet']['portrait']['tablet-portrait-media-queries-wrapper']['tablet_portrait_media_query'] = array(
  '#type' => 'textfield',
  '#title' => t('Media query for this layout'),
  '#default_value' => check_plain(at_get_setting('tablet_portrait_media_query')),
  '#description' => t('Do not include @media, it\'s included automatically.'),
  '#field_prefix' => '@media',
  '#size' => 100,
  '#required' => TRUE,
);


/*****************************************************************************
 *
 * Smartphone
 *
 ****************************************************************************/

$form['at-settings']['smartphone'] = array(
  '#type' => 'fieldset',
  '#title' => t('Smartphone Layout'),
  '#description' => t('<h3>Smartphone Layout</h3><p>Smartphone devices such as iPhone, Android and Windows phones have two orientations - landscape and portrait. You can configure a layout for landscape orientation only - portrait orientation always displays in one column with sidebars stacked below the main content.</p>'),
  '#attributes' => array(
    'class' => array('at-layout-form'),
  ),
);

// Disabled message
if(at_get_setting('disable_responsive_styles') === 1) {
  $form['at-settings']['smartphone']['disabled'] = array(
    '#markup' => '<div class="messages warning">' . $disable_message . '</div>',
  );
}


/***********************
 * Smartphone landscape
 **********************/

$form['at-settings']['smartphone']['landscape'] = array(
  '#type' => 'fieldset',
  '#title' => t('Landscape'),
  '#description' => t('<h4>Landscape smartphone</h4>'),
  '#states' => array(
    'disabled' => array('input[name="disable_responsive_styles"]' => array('checked' => TRUE)),
  ),
);

$form['at-settings']['smartphone']['landscape']['smartphone-landscape-layout-wrapper'] = array(
  '#type' => 'fieldset',
  '#title' => t('Choose sidebar layout'),
);

$form['at-settings']['smartphone']['landscape']['smartphone-landscape-layout-wrapper']['smartphone_landscape_layout'] = array(
  '#type' => 'radios',
  '#title' => t('<strong>Choose sidebar positions</strong>'),
  '#default_value' => str_replace('-', '_', at_get_setting('smartphone_landscape_layout')),
  '#options' => $smartphone_landscape_options,
);

$form['at-settings']['smartphone']['landscape']['smartphone-landscape-sidebar-width-wrapper'] = array(
  '#type' => 'fieldset',
  '#title' => t('Set sidebar widths'),
  '#description' => t('<strong>Set the width of each sidebar</strong>'),
  '#states' => array(
    '!visible' => array('input[name="smartphone_landscape_layout"]' => array('value' => 'one_col_stack')),
  ),
);

$form['at-settings']['smartphone']['landscape']['smartphone-landscape-sidebar-width-wrapper']['smartphone_landscape_sidebar_unit'] = array(
  '#type' => 'select',
  '#title' => t('Unit'),
  '#default_value' => at_get_setting('smartphone_landscape_sidebar_unit'),
  '#options' => $unit_options,
);

$form['at-settings']['smartphone']['landscape']['smartphone-landscape-sidebar-width-wrapper']['smartphone_landscape_sidebar_first'] = array(
  '#type' => 'textfield',
  '#title' => t('First sidebar'),
  '#default_value' => check_plain(at_get_setting('smartphone_landscape_sidebar_first')),
  '#size' => 4,
  '#maxlenght' => 4,
  '#states' => array(
    'required' => array('input[name="smartphone_landscape_layout"]' => array('value' => 'one_col_vert')),
  ),
);

$form['at-settings']['smartphone']['landscape']['smartphone-landscape-sidebar-width-wrapper']['smartphone_landscape_sidebar_second'] = array(
  '#type' => 'textfield',
  '#title' => t('Second sidebar'),
  '#default_value' => check_plain(at_get_setting('smartphone_landscape_sidebar_second')),
  '#size' => 4,
  '#maxlenght' => 4,
  '#states' => array(
    'required' => array('input[name="smartphone_landscape_layout"]' => array('value' => 'one_col_vert')),
  ),
);

$form['at-settings']['smartphone']['landscape']['smartphone-landscape-media-queries-wrapper'] = array(
  '#type' => 'fieldset',
  '#title' => t('Smartphone Landscape Media Queries'),
  '#weight' => 1,
  '#attributes' => array(
    'class' => array('at-media-queries'),
  ),
);

$form['at-settings']['smartphone']['landscape']['smartphone-landscape-media-queries-wrapper']['smartphone_landscape_media_query'] = array(
  '#type' => 'textfield',
  '#title' => t('Media query for this layout'),
  '#default_value' => check_plain(at_get_setting('smartphone_landscape_media_query')),
  '#description' => t('Do not include @media, it\'s included automatically.'),
  '#field_prefix' => '@media',
  '#size' => 100,
  '#required' => TRUE,
);

// Pass hidden values to the sumbit function, these values are required but the user can't change them via the UI
$form['at-settings']['smartphone']['landscape']['hidden']['smartphone_landscape_page_width'] = array(
  '#type' => 'hidden',
  '#default_value' => check_plain(at_get_setting('smartphone_landscape_page_width')),
);
$form['at-settings']['smartphone']['landscape']['hidden']['smartphone_landscape_page_unit'] = array(
  '#type' => 'hidden',
  '#default_value' => at_get_setting('smartphone_landscape_page_unit'),
);


/**********************
 * Smartphone portrait
 *********************/

$form['at-settings']['smartphone']['portrait'] = array(
  '#type' => 'fieldset',
  '#title' => t('Portrait'),
  '#description' => t('<h4>Portrait smartphone</h4><div class="smartphone-portrait-layout">One column</div><p>The smartphone portrait layout always displays in one column with sidebars stacked horizontally below the main content. All widths are always 100%.</p>'),
  '#states' => array(
    'disabled' => array('input[name="disable_responsive_styles"]' => array('checked' => TRUE)),
  ),
);

$form['at-settings']['smartphone']['portrait']['smartphone-portrait-media-queries-wrapper'] = array(
  '#type' => 'fieldset',
  '#title' => t('Smartphone Portrait Media Queries'),
  '#weight' => 1,
  '#attributes' => array(
    'class' => array('at-media-queries'),
  ),
);

$form['at-settings']['smartphone']['portrait']['smartphone-portrait-media-queries-wrapper']['smartphone_portrait_media_query'] = array(
  '#type' => 'textfield',
  '#title' => t('Media query for this layout'),
  '#default_value' => check_plain(at_get_setting('smartphone_portrait_media_query')),
  '#description' => t('Do not include @media, it\'s included automatically.'),
  '#field_prefix' => '@media',
  '#size' => 100,
);

// Pass hidden values to the sumbit function, these values are required but the user can't change them via the UI
$form['at-settings']['smartphone']['portrait']['hidden']['smartphone_portrait_page_width'] = array(
  '#type' => 'hidden',
  '#default_value' => check_plain(at_get_setting('smartphone_portrait_page_width')),
);

$form['at-settings']['smartphone']['portrait']['hidden']['smartphone_portrait_page_unit'] = array(
  '#type' => 'hidden',
  '#default_value' => at_get_setting('smartphone_portrait_page_unit'),
);

$form['at-settings']['smartphone']['portrait']['hidden']['smartphone_portrait_sidebar_first'] = array(
  '#type' => 'hidden',
  '#default_value' => check_plain(at_get_setting('smartphone_portrait_sidebar_first')),
);

$form['at-settings']['smartphone']['portrait']['hidden']['smartphone_portrait_sidebar_second'] = array(
  '#type' => 'hidden',
  '#default_value' => check_plain(at_get_setting('smartphone_portrait_sidebar_second')),
);

$form['at-settings']['smartphone']['portrait']['hidden']['smartphone_portrait_sidebar_unit'] = array(
  '#type' => 'hidden',
  '#default_value' => check_plain(at_get_setting('smartphone_portrait_sidebar_unit')),
);

$form['at-settings']['smartphone']['portrait']['hidden']['smartphone_portrait_layout'] = array(
  '#type' => 'hidden',
  '#default_value' => str_replace('-', '_', at_get_setting('smartphone_portrait_layout')),
);