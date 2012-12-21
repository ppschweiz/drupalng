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
        $text = check_markup($text, 'migrate_html', NULL, FALSE);
        $text = pps_migrate_d6_to_textile($text);
        $text = pps_migrate_d6_footnotes_filter($text);
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
}
