<?php

/**
 * @file
 * Custom theme functions and theme function overrides.
 *
 * If you need to add or modify theme functions do it in your sub-theme.
 */

/**
 * Implements hook_theme()
 *
 * @param $existing
 * @param $type
 * @param $theme
 * @param $path
 *
 * @see http://api.drupal.org/api/drupal/modules!system!system.api.php/function/hook_theme/7
 */
function adaptivetheme_theme($existing, $type, $theme, $path) {
  return array(
    'menubar' => array(
      'render element' => 'element',
    ),
  );
}

/**
 * Returns HTML for a menubar.
 *
 * The contents is normally one of Drupals magic menu variables, such as the
 * Main menu or User menu (secondary menu), but could be any menu you wish to
 * wrap in navigation menu type markup and classes.
 *
 * @param $vars
 * An array containing:
 *  - $menubar_id: CSS id for theming the menubar
 *  - $menu: Holds the themed menu (normally using theme_links())
 *  - the usual $classes, $attributes, $content attributes etc
 *
 * @see adaptivetheme_preprocess_menubar()
 * @see adaptivetheme_process_menubar()
 */
function adaptivetheme_menubar($vars) {
  $output = '';
  $output .= '<div id="' . $vars['menubar_id'] . '" class="' . $vars['classes'] . '"' . $vars['attributes'] . '>';
  $output .= '<nav ' . $vars['content_attributes'] . '>';
  $output .= $vars['menu'];
  $output .= '</nav></div>';
  return $output;
}

/**
 * Helper function for theming main and secondary variables.
 * Provides 7.x-2.x backward compatibility, not used in 7.x-3.x, instead we now
 * use a proper theme function so themers can override it.
 *
 * @param $menu
 * @param $type
 */
function _theme_menu_variables($menu, $type) {
  $output = '<div id="' . $type . '-menu-bar" class="nav"><nav class="clearfix">' . $menu . '</nav></div>';
  return $output;
}

/**
 * Returns HTML for a breadcrumb trail.
 *
 * Adaptivetheme impliments breadcrumb trails as an ordered list, wrapping each
 * crumb in li elements and the seperators in span elements to make life easier
 * for themers. Additionally .crumb, .crumb-first and .crumb-last classes are
 * printed on the li elements.
 *
 * @param $vars
 *   An associative array containing:
 *   - breadcrumb: An array containing the breadcrumb links.
 */
function adaptivetheme_breadcrumb($vars) {
  global $theme_key;
  $theme_name = $theme_key;

  $breadcrumb = $vars['breadcrumb'];

  if (at_get_setting('breadcrumb_display', $theme_name) == 1) {

    if (at_get_setting('breadcrumb_home', $theme_name) == 0) {
      array_shift($breadcrumb);
    }

    // Remove the rather pointless breadcrumbs for reset password and user
    // register pages, they link to the page you are on.
    if (arg(0) === 'user' && (arg(1) === 'password' || arg(1) === 'register')) {
      array_pop($breadcrumb);
    }

    if (!empty($breadcrumb)) {

      $separator = filter_xss_admin(at_get_setting('breadcrumb_separator', $theme_name));

      // Push the page title onto the end of the breadcrumb array
      if (at_get_setting('breadcrumb_title', $theme_name) == 1) {
        $breadcrumb[] = '<span class="crumb-title">' . drupal_get_title() . '</span>';
      }

      $class = 'crumb';
      end($breadcrumb);
      $last = key($breadcrumb);

      $output = '';
      if (at_get_setting('breadcrumb_label', $theme_name) == 1) {
        $output = '<div id="breadcrumb" class="clearfix"><nav class="breadcrumb-wrapper with-breadcrumb-label clearfix" role="navigation">';
        $output .= '<h2 class="breadcrumb-label">' . t('You are here') . '</h2>';
      }
      else {
        $output = '<div id="breadcrumb" class="clearfix"><nav class="breadcrumb-wrapper clearfix" role="navigation">';
        $output .= '<h2 class="element-invisible">' . t('You are here') . '</h2>';
      }
      $output .= '<ol id="crumbs" class="clearfix">';
      foreach ($breadcrumb as $key => $val) {
        if ($key == $last && count($breadcrumb) != 1) {
          $class = 'crumb crumb-last';
        }
        if ($key == 0) {
          $output .= '<li class="' . $class . ' crumb-first">' . $val . '</li>';
        }
        else {
          $output .= '<li class="' . $class . '"><span class="crumb-sepreator">' . $separator . '</span>' . $val . '</li>';
        }
      }
      $output .= '</ol></nav></div>';

      return $output;
    }
  }
  else {
    return;
  }
}

/**
 * Returns HTML for status and/or error messages, grouped by type.
 *
 * Adaptivetheme adds a div wrapper with CSS id.
 *
 * An invisible heading identifies the messages for assistive technology.
 * Sighted users see a colored box. See http://www.w3.org/TR/WCAG-TECHS/H69.html
 * for info.
 *
 * @param $vars
 *   An associative array containing:
 *   - display: (optional) Set to 'status' or 'error' to display only messages
 *     of that type.
 */
function adaptivetheme_status_messages($vars) {
  $display = $vars['display'];
  $output = '';

  $status_heading = array(
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
  );
  foreach (drupal_get_messages($display) as $type => $messages) {
    $output .= "<div id=\"messages\"><div class=\"messages $type\">";
    if (!empty($status_heading[$type])) {
      $output .= '<h2 class="element-invisible">' . $status_heading[$type] . "</h2>";
    }
    if (count($messages) > 1) {
      $output .= " <ul>";
      foreach ($messages as $message) {
        $output .= '  <li>' . $message . "</li>";
      }
      $output .= " </ul>";
    }
    else {
      $output .= $messages[0];
    }
    $output .= "</div></div>";
  }
  return $output;
}

/**
 * Returns HTML for a list or nested list of items.
 *
 * Adaptivetheme overrides this in order to insert extra classes into list
 * items, including first, last and odd/even zebra classes.
 *
 * @param $vars
 *   An associative array containing:
 *   - items: An array of items to be displayed in the list. If an item is a
 *     string, then it is used as is. If an item is an array, then the "data"
 *     element of the array is used as the contents of the list item. If an item
 *     is an array with a "children" element, those children are displayed in a
 *     nested list. All other elements are treated as attributes of the list
 *     item element.
 *   - title: The title of the list.
 *   - type: The type of list to return (e.g. "ul", "ol").
 *   - attributes: The attributes applied to the list element.
 */
function adaptivetheme_item_list($vars) {
  global $theme_key;
  $theme_name = $theme_key;

  $items = $vars['items'];
  $title = $vars['title'];
  $type = $vars['type'];
  $attributes = $vars['attributes'];

  $output = '<div class="item-list">';

  if (isset($title) && $title !== '') {
    $output .= '<h3>' . $title . '</h3>';
  }

  if (!empty($items)) {
    $output .= "<$type" . drupal_attributes($attributes) . '>';
    $num_items = count($items);
    foreach ($items as $i => $item) {
      $attributes = array();
      $children = array();
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }

      if (count($children) > 0) {
        // Render nested list.
        $data .= theme_item_list(array('items' => $children, 'title' => NULL, 'type' => $type, 'attributes' => $attributes));
      }

      if (at_get_setting('extra_item_list_classes', $theme_name) == 1) {
        if ($i & 1) {
          $attributes['class'][] = 'odd';
        }
        else {
          $attributes['class'][] = 'even';
        }
        if ($i == 0) {
          $attributes['class'][] = 'first';
        }
        if ($i == $num_items - 1) {
          $attributes['class'][] = 'last';
        }
      }
      $output .= '<li' . drupal_attributes($attributes) . '>' . $data . "</li>"; // no new line!
    }
    $output .= "</$type>";
  }
  $output .= '</div>';

  return $output;
}

// Dont run this if the DHTML module is running, it borks its output!
if (!function_exists('dhtml_menu_init')) {
  /**
   * Returns HTML for a wrapper for a menu sub-tree.
   *
   * Adaptivetheme overrides this to insert the clearfix class.
   *
   * @param $vars
   *   An associative array containing:
   *   - tree: An HTML string containing the tree's items.
   *
   * @see template_preprocess_menu_tree()
   */
  function adaptivetheme_menu_tree($vars) {
    return '<ul class="menu clearfix">' . $vars['tree'] . '</ul>';
  }

  /**
   * Returns HTML for a menu link and submenu.
   *
   * Adaptivetheme overrides this to insert extra classes including a depth
   * class and a menu id class. It can also wrap menu items in span elements.
   *
   * @param $vars
   *   An associative array containing:
   *   - element: Structured array data for a menu link.
   */
  function adaptivetheme_menu_link(array $vars) {
    global $theme_key;
    $theme_name = $theme_key;

    $element = $vars['element'];
    $sub_menu = '';

    if ($element['#below']) {
      $sub_menu = drupal_render($element['#below']);
    }

    if (at_get_setting('extra_menu_classes', $theme_name) == 1 && !empty($element['#original_link'])) {
      if (!empty($element['#original_link']['depth'])) {
        $element['#attributes']['class'][] = 'menu-depth-' . $element['#original_link']['depth'];
      }
      if (!empty($element['#original_link']['mlid'])) {
        $element['#attributes']['class'][] = 'menu-item-' . $element['#original_link']['mlid'];
      }
    }

    if (at_get_setting('menu_item_span_elements', $theme_name) == 1 && !empty($element['#title'])) {
      $element['#title'] = '<span>' . $element['#title'] . '</span>';
      $element['#localized_options']['html'] = TRUE;
    }

    if (at_get_setting('unset_menu_titles', $theme_name) == 1 && !empty($element['#localized_options']['attributes']['title'])) {
      unset($element['#localized_options']['attributes']['title']);
    }

    $output = l($element['#title'], $element['#href'], $element['#localized_options']);
    return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>";
  }
}

/**
 * Returns HTML for a field.
 *
 * Adaptivetheme overrides this in order to better support HTML5 by setting the
 * wrapper as section or div element depending on whether a title is used or not.
 * Fields have no title, instead it treats the field lable as if it were a title
 * and wraps it in h2 elements.
 *
 * This is the default theme implementation to display the value of a field.
 * Theme developers who are comfortable with overriding theme functions may do
 * so in order to customize this markup. This function can be overridden with
 * varying levels of specificity. For example, for a field named 'body'
 * displayed on the 'article' content type, any of the following functions will
 * override this default implementation. The first of these functions that
 * exists is used:
 * - THEMENAME_field__body__article()
 * - THEMENAME_field__article()
 * - THEMENAME_field__body()
 * - THEMENAME_field()
 *
 * Theme developers who prefer to customize templates instead of overriding
 * functions may copy the "field.tpl.php" from the "modules/field/theme" folder
 * of the Drupal installation to somewhere within the theme's folder and
 * customize it, just like customizing other Drupal templates such as
 * page.tpl.php or node.tpl.php. However, it takes longer for the server to
 * process templates than to call a function, so for websites with many fields
 * displayed on a page, this can result in a noticeable slowdown of the website.
 * For these websites, developers are discouraged from placing a field.tpl.php
 * file into the theme's folder, but may customize templates for specific
 * fields. For example, for a field named 'body' displayed on the 'article'
 * content type, any of the following templates will override this default
 * implementation. The first of these templates that exists is used:
 * - field--body--article.tpl.php
 * - field--article.tpl.php
 * - field--body.tpl.php
 * - field.tpl.php
 * So, if the body field on the article content type needs customization, a
 * field--body--article.tpl.php file can be added within the theme's folder.
 * Because it's a template, it will result in slightly more time needed to
 * display that field, but it will not impact other fields, and therefore,
 * is unlikely to cause a noticeable change in website performance. A very rough
 * guideline is that if a page is being displayed with more than 100 fields and
 * they are all themed with a template instead of a function, it can add up to
 * 5% to the time it takes to display that page. This is a guideline only and
 * the exact performance impact depends on the server configuration and the
 * details of the website.
 *
 * @param $vars
 *   An associative array containing:
 *   - label_hidden: A boolean indicating to show or hide the field label.
 *   - title_attributes: A string containing the attributes for the title.
 *   - label: The label for the field.
 *   - content_attributes: A string containing the attributes for the content's
 *     div.
 *   - items: An array of field items.
 *   - item_attributes: An array of attributes for each item.
 *   - classes: A string containing the classes for the wrapping div.
 *   - attributes: A string containing the attributes for the wrapping div.
 *
 * @see template_preprocess_field()
 * @see template_process_field()
 * @see field.tpl.php
 */
function adaptivetheme_field($vars) {
  $output = '';

  // Render the label, if it's not hidden.
  if (!$vars['label_hidden']) {
    $output .= '<h2 class="field-label"' . $vars['title_attributes'] . '>' . $vars['label'] . ':&nbsp;</h2>';
  }

  // Render the items.
  $output .= '<div class="field-items"' . $vars['content_attributes'] . '>';
  foreach ($vars['items'] as $delta => $item) {
    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= '<div class="' . $classes . '"' . $vars['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
  }
  $output .= '</div>';

  // Render the top-level wrapper element.
  $tag = $vars['tag'];
  $output = "<$tag class=\"" . $vars['classes'] . '"' . $vars['attributes'] . '>' . $output . "</$tag>";

  return $output;
}

/**
 * Returns HTML for a taxonomy field.
 *
 * Output taxonomy term fields as unordered lists.
 */
function adaptivetheme_field__taxonomy_term_reference($vars) {
  $output = '';

  // Render the label, if it's not hidden.
  if (!$vars['label_hidden']) {
    $output .= '<h2 class="field-label"' . $vars['title_attributes'] . '>' . $vars['label'] . ':&nbsp;</h2>';
  }

  // Render the items.
  $output .= '<ul class="field-items"' . $vars['content_attributes'] . '>';
  foreach ($vars['items'] as $delta => $item) {
    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= '<li class="' . $classes . '"' . $vars['item_attributes'][$delta] . '>' . drupal_render($item) . '</li>';
  }

  $output .= '</ul>';

  // Render the top-level wrapper element.
  $tag = $vars['tag'];
  $output = "<$tag class=\"" . $vars['classes'] . '"' . $vars['attributes'] . '>' . $output . "</$tag>";

  return $output;
}

/**
 * Returns HTML for an image field.
 *
 * Output image fields as figure with figcaption for captioning.
 */
function adaptivetheme_field__image($vars) {
  global $theme_key;
  $theme_name = $theme_key;

  // Check if image settings are enabled, otherwise captions might print unexpectedly
  $image_settings_enabled = at_get_setting('enable_image_settings', $theme_name) === 1 ? TRUE : FALSE;
  $caption_full = at_get_setting('image_caption_full', $theme_name) === 1 ? TRUE : FALSE;
  $caption_teaser = at_get_setting('image_caption_teaser', $theme_name) === 1 ? TRUE : FALSE;

  $output = '';

  // Render the label, if it's not hidden.
  if (!$vars['label_hidden']) {
    $output .= '<h2 class="field-label"' . $vars['title_attributes'] . '>' . $vars['label'] . ':&nbsp;</h2>';
  }

  // Render the items.
  $output .= '<div class="field-items"' . $vars['content_attributes'] . '>';

  foreach ($vars['items'] as $delta => $item) {

    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= '<figure class="' . $classes . '"' . $vars['item_attributes'][$delta] . '>';
    $output .= drupal_render($item);

    if (isset($item['#item']['title'])) {
      if ($vars['field_view_mode'] == 'full') {
        if ($caption_full == TRUE && $image_settings_enabled == TRUE) {
          $output .= '<figcaption class="caption full-caption">' . $item['#item']['title'] . '</figcaption>';
        }
      }
      if ($vars['field_view_mode'] == 'teaser') {
        if ($caption_teaser == TRUE && $image_settings_enabled == TRUE) {
          $output .= '<figcaption class="caption teaser-caption">' . $item['#item']['title'] . '</figcaption>';
        }
      }
    }

    $output .= '</figure>';
  }

  $output .= '</div>';

  // Render the top-level wrapper element.
  $tag = $vars['tag'];
  $output = "<$tag class=\"" . $vars['classes'] . '"' . $vars['attributes'] . '>' . $output . "</$tag>";

  return $output;
}