<?php
/**
 * Text field handler for migrate
 *
 * Custom clean up an conversion for migrations.
 */

class PPSMigrateTextFieldHandler extends MigrateTextFieldHandler {
  public function prepare ($entity, array $field_info, array $instance, array $values) {
    $format = isset($values['arguments']['format']) ? $values['arguments']['format'] : 'plain_text';

    foreach ($values as $key => $text) {
      if (is_numeric($key) && !empty($text)) {

        $converted_text = $this->convert($text, $format);
        if (!empty($text) && empty($converted_text)) {
          $values[$key] = $text;
          $message = 'Could not convert field %field of entity %title to format %format.';
          $variables = array(
            '%field' => $instance['label'],
            '%title' => entity_label($instance['entity_type'], $entity),
            '%format' => $format,
          );
          watchdog(__CLASS__, $message, $variables, WATCHDOG_ERROR);
        }
        else {
          $values[$key] = $converted_text;
        }
      }
    }
    if (!empty($values['arguments']['summary'])) {
      $values['arguments']['summary'] = $this->convert($values['arguments']['summary'], $format);
    }
    return parent::prepare ($entity, $field_info, $instance, $values);
  }

  /**
   * Convert to target format
   *
   * @param $text
   *   The text to be converted.
   * @param $format
   *   The target format.
   * @return
   *   The converted text.
   */
  private function convert($text, $format) {
    switch ($format) {
      case 'textile':
        $text = preg_replace( '|<br[^>]+>\n?<br[^>]+>|', '</p><p>', $text);
        $text = check_markup($text, 'migrate', NULL, FALSE);
        $text = $this->convertToTextile($text);
        $text = $this->footnotes_filter($text);
        break;
      default:
        $text = check_markup($text, 'migrate_plain', NULL, FALSE);
    }
    $text = htmlspecialchars_decode($text);
    return $text;
  }

  /**
   * Convert HTML to Textile
   *
   * Uses pandoc to convert any HTML to Textile.
   *
   * The text ist stored to a temporary file in order to prevent command
   * line escaping pitfalls.
   *
   * @param $text
   *   The text to be converted.
   * @return
   *   Teh resulting textile text.
   */
  private function convertToTextile($text) {
    $file = tmpfile();
    $meta_data = stream_get_meta_data($file);
    $filename = $meta_data['uri'];
    fwrite($file, $text);
    $pandoc = variable_get('shell_cmd_pandoc', '/usr/bin/pandoc');
    $text = shell_exec("$pandoc -f html -t textile $filename");
    fclose($file);
    return $text;
  }

  /**
   * Parse footnotes
   *
   * @see _footnotes_filter()
   */
  function footnotes_filter($text = '') {
    $text = preg_replace( '|\[fn([^\]]*)\]|', '<fn$1>', $text);
    $text = preg_replace( '|\[/fn\]|', '</fn>', $text);
    $text = preg_replace( '|\[footnotes([^\]]*)\]|', '<footnotes$1>', $text);

    $open_tags = preg_match_all("|<fn([^>]*)>|", $text, $foo);
    $close_tags = preg_match_all("|</fn>|", $text, $foo);

    if ($open_tags == $close_tags + 1) {
      $text = $text . '</fn>';
    }
    elseif ($open_tags > $close_tags + 1) {
      watchdog(__FUNCTION__, 'You have unclosed fn tags. This is invalid and will produce unpredictable results.', WATCHDOG_NOTICE);
    }

    $pattern = '|<fn([^>]*)>(.*?)</fn>|s';
    $text = preg_replace_callback($pattern , 'pps_migrate_d6_footnotes_replace_callback', $text);

    $footer = pps_migrate_d6_footnotes_replace_callback(NULL, 'output footer');
    $pattern = '|(<footnotes([^\]]*)>)|';
    if (preg_match($pattern, $text) > 0) {
      $text = preg_replace($pattern, $footer, $text, 1);
      return $text;
    }
    else {
      return $text . "\n\n" . $footer;
    }
  }
}

/**
 * Helper function called from preg_replace_callback() above
 *
 * @see _footnotes_replace_callback()
 * @todo Remove obsolete code.
 */
function pps_migrate_d6_footnotes_replace_callback( $matches, $op = '' ) {
  static $opt_collapse = 0;
  static $n = 0;
  static $store_matches = array();
  static $used_values = array();
  $str = '';

  if ($op == 'prepare') {
    // In the 'prepare' case, the first argument contains the options to use.
    // The name 'matches' is incorrect, we just use the variable anyway.
    $opt_collapse = $matches;
    return 0;
  }

  if( $op == 'output footer' ) {
    $str = '';
    if (count($store_matches) > 0) {
      foreach ($store_matches as $match) {
        $value = $match['value'];
        $text = $match['text'];
        $str .= "fn$value. $text\n\n";
      }

    }
    // Reset the static variables so they can be used again next time
    $n = 0;
    $store_matches = array();
    $used_values = array();
    return $str;
  }


  // Default op: act as called by preg_replace_callback()
  // Random string used to ensure footnote id's are unique, even
  // when contents of multiple nodes reside on same page. (fixes http://drupal.org/node/194558)
  $randstr = _footnotes_helper_randstr();

  $value = '';
  // Did the pattern match anything in the <fn> tag?
  if ($matches[1]) {
    // See if value attribute can parsed, either well-formed in quotes eg <fn value="3">
    if (preg_match('|value=["\'](.*?)["\']|',$matches[1],$value_match)) {
      $value = $value_match[1];
      // Or without quotes eg <fn value=8>
    } elseif (preg_match('|value=(\S*)|',$matches[1],$value_match)) {
      $value = $value_match[1];
    }
  }

  if ($value) {
    // A value label was found. If it is numeric, record it in $n so further notes
    // can increment from there.
    // After adding support for multiple references to same footnote in the body (http://drupal.org/node/636808)
    // also must check that $n is monotonously increasing
    if ( is_numeric($value) && $n < $value ) {
      $n = $value;
    }
  } else {
    // No value label, either a plain <fn> or unparsable attributes. Increment the
    // footnote counter, set label equal to it.
    $n++;
    $value = $n;
  }

  // Remove illegal characters from $value so it can be used as an HTML id attribute.
  $value_id = preg_replace('|[^\w\-]|', '', $value);

  // Create a sanitized version of $text that is suitable for using as HTML attribute
  // value. (In particular, as the title attribute to the footnote link.)
  $allowed_tags = array();
  $text_clean = filter_xss($matches['2'], $allowed_tags);
  // HTML attribute cannot contain quotes
  $text_clean = str_replace('"', "&quot;", $text_clean);
  // Remove newlines. Browsers don't support them anyway and they'll confuse line break converter in filter.module
  $text_clean = str_replace("\n", " ", $text_clean);
  $text_clean = str_replace("\r", "", $text_clean);


  // Create a footnote item as an array.
  $fn = array(
    'value' => $value,
    'text' => $matches[2],
    'text_clean' => $text_clean,
    'fn_id' => 'footnote' . $value_id . '_' . $randstr,
    'ref_id' => 'footnoteref' . $value_id . '_' . $randstr
  );

  // We now allow to repeat the footnote value label, in which case the link to the previously
  // existing footnote is returned. Content of the current footnote is ignored.
  // See http://drupal.org/node/636808
  if( ! in_array( $value, $used_values ) )
  {
    // This is the normal case, add the footnote to $store_matches

    // Store the footnote item.
    array_push( $store_matches, $fn );
    array_push( $used_values, $value );
  }
  else
  {
    // A footnote with the same label already exists

    // Use the text and id from the first footnote with this value.
    // Any text in this footnote is discarded.
    $i = array_search( $value, $used_values );
    $fn['text'] = $store_matches[$i]['text'];
    $fn['text_clean'] = $store_matches[$i]['text_clean'];
    $fn['fn_id'] = $store_matches[$i]['fn_id'];
    // Push the new ref_id into the first occurence of this footnote label
    // The stored footnote thus holds a list of ref_id's rather than just one id
    $ref_array = is_array($store_matches[$i]['ref_id']) ? $store_matches[$i]['ref_id'] : array( $store_matches[$i]['ref_id'] );
    array_push( $ref_array, $fn['ref_id'] );
    $store_matches[$i]['ref_id'] = $ref_array;
  }

  $fn_id = $fn['value'];
  return "[$fn_id]";
}
