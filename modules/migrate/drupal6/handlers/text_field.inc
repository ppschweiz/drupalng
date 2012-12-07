<?php
/**
 * Created by JetBrains PhpStorm.
 * User: christian
 * Date: 06.12.12
 * Time: 15:04
 * To change this template use File | Settings | File Templates.
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

  private function convert($text, $format) {
    switch ($format) {
      case 'textile':
        $text = $this->convertToTextile($text);
        break;
      default:
        $text = strip_tags($text);
    }
    return $text;
  }

  private function convertToTextile($text) {
    $echo = variable_get('shell_cmd_echo', '/bin/echo');
    $pandoc = variable_get('shell_cmd_pandoc', '/usr/bin/pandoc');
    $text = shell_exec("$echo '$text' | $pandoc -f html -t textile -");
    return $text;
  }
}