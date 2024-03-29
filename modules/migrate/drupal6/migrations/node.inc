<?php

class PPSNodeMigration extends DrupalNode6Migration {

  protected $autotagging_fields = array();
  protected $access_mapping = array();

  public function __construct (array $arguments) {
    $map_access = !empty($arguments['access mappings']);
    $map_structural = !empty($arguments['structural']);

    if ($map_access || $map_structural) {
      $this->sourceFields['field_access'] = t('Workbench Access');
    }
    $this->sourceFields['tag_all'] = t('Concatenation of all tags except language');
    $this->sourceFields['tag_topic'] = t('tag topic');
    $this->sourceFields['tag_person'] = t('Tag person');
    $this->sourceFields['tag_location'] = t('Tag location');
    $this->sourceFields['tag_language'] = t('Tag language');
    if ($map_access) {
      $this->access_mapping = $arguments['access mappings'];
    }

    parent::__construct ($arguments);

    // The body field needs to have the same language as the node or the
    // text will not show up in the edit form.
    $this->removeFieldMapping('body:language');
    $this->addFieldMapping('body:language', 'language');

    // Keep existing translation sets.
    // @todo: Get rid of the stub records that are created when the
    // tnid is zero.
    $this->addFieldMapping('tnid', 'tnid', FALSE)
      ->sourceMigration($arguments['machine_name']);

    if ($map_access && !$map_structural) {
      $this->addSimpleMappings(array('field_access'));
    }
    else if ($map_access && $map_structural) {
      $this->addFieldMapping('field_access', 'field_access')
        ->defaultValue($arguments['structural']);
    }
    else if ($map_structural) {
      $this->addUnmigratedSources(array('field_access'));
      $this->addFieldMapping('field_access')
        ->defaultValue($arguments['structural']);
    }

    if ($map_structural || $map_access) {
      $this->addFieldMapping('field_access:create_term')->defaultValue(TRUE);
      $this->addFieldMapping('field_access:ignore_case')->defaultValue(TRUE);
      $this->addUnmigratedDestinations(array('field_access:source_type'));
    }

    $this->addFieldMapping('domains')->defaultValue(array(
      'piratenpartei_ch',
    ));
    $this->addFieldMapping('domain_site')->defaultValue(FALSE);

    $this->removeFieldMapping('path');
    $this->removeFieldMapping('pathauto');
    $this->addUnmigratedSources(array(
      'path',
      'nid',
    ));

    $this->addUnmigratedDestinations(array('path'));

    $tagging_fields = array(
      'tag_all',
      'tag_topic',
      'tag_person',
      'tag_location',
      'tag_language',
    );
    if (!empty($arguments['tag mappings'])) {
      $this->autotagging_fields = array('title', 'body');
      foreach ($arguments['tag mappings'] as $destination_field => $source_field) {
        $this->addFieldMapping($destination_field, $source_field);
        $this->addUnmigratedDestinations(array($destination_field . ':source_type'));
        $this->addFieldMapping($destination_field . ':create_term')
          ->defaultValue(TRUE);
        $this->addFieldMapping($destination_field . ':ignore_case')
          ->defaultValue(FALSE);
        unset($tagging_fields[$destination_field]);
      }
    }
    $this->addUnmigratedSources($tagging_fields);
  }

  protected function promote($promote) {
    $this->removeFieldMapping('promote');
    $this->addFieldMapping('promote')->defaultValue($promote);
    $this->addUnmigratedSources(array('promote'));
  }

  /**
   * Overrides Migration::query()
   *
   * We need to fetch the translations before the source node in order
   * to persist translation sets correctly.
   */
  protected function query() {
   $query = parent::query();
    $order = &$query->getOrderBy();
    $order = array(
      'created' => 'DESC'
    );
    return $query;
  }

  public function prepareRow ($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    // Prevent unnecessary stubs.
    if ($row->tnid == 0) {
      $row->tnid = NULL;
    }
    if (!empty($this->autotagging_fields)) {
      $text = array();
      foreach ($this->autotagging_fields as $field) {
        if (isset($row->$field)){
          $text[] = $row->$field;
        }
      }
      $text = implode(' ', $text);
      if (!empty($text)){
        $all_tags = pps_migrate_d6_fetch_tags($text);
        foreach ( $all_tags as $key => $tags) {
          $attribute = 'tag_' . $key;
          array_filter($tags, 'drupal_ucfirst');
          $row->$attribute = $tags;
        }
      }
    }

    if (isset($this->access_mapping['nid']) && array_key_exists($row->nid, $this->access_mapping['nid'])) {
      $row->field_access = $this->access_mapping['nid'][$row->nid];
    }
  }

  /**
   * Add redirect for old path.
   */
  public function complete ($node, $row) {
    if (!empty($row->path)) {
      $redirect = new stdClass();
      $redirect->type =  'redirect';
      $redirect->language =  'und';
      $redirect->status_code =  0;
      $redirect->override =  FALSE;
      $redirect->source_options = array();
      $redirect->redirect_options = array();

      $redirect->source = $row->path;
      $redirect->redirect = 'node/' . $node->nid;
      redirect_save($redirect);
    }
  }

  /**
   * Remove redirects.
   */
  public function completeRollback($entity) {
    redirect_delete_by_path('node/' . $entity->nid);
  }
}

/**
 * Common mappings for the node migrations.
 *
 * @todo Get the attachment description.
 * @todo Probably we need to deal with attachments in different way.
 */
class PPSAttachmentNodeMigration extends PPSNodeMigration {

  public function __construct (array $arguments) {
    $this->sourceFields['attachment_fids'] = t('File attachments');

    parent::__construct ($arguments);

    $this->addFieldMapping('field_attachments', 'attachment_fids')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_attachments:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addUnmigratedDestinations(array(
      'field_attachments:language',
      'field_attachments:description',
      'field_attachments:display',
    ));
  }

  protected function noAttachment() {
    $this->removeFieldMapping('field_attachments');
    $this->removeFieldMapping('field_attachments:file_class');
    $this->removeFieldMapping('field_attachments:language');
    $this->removeFieldMapping('field_attachments:description');
    $this->removeFieldMapping('field_attachments:display');
    $this->addUnmigratedSources(array(
      'attachment_fids',
    ));
  }
}

/**
 * Minutes migration
 */
class PPSNodehierarchyMigration extends PPSAttachmentNodeMigration {
  private $parents = array();

  public function __construct(array $arguments) {
    if (isset($arguments['parents'])) {
      if (is_array($arguments['parents'])) {
        $this->parents = $arguments['parents'];
      }
      else {
        $this->parents = array($arguments['parents']);
      }
    }
    parent::__construct($arguments);

    $this->addUnmigratedSources(array('parent'));
  }

  protected function query() {
    $query = parent::query();
    $query->rightJoin('nodehierarchy', 'nh', 'n.nid = nh.nid');
    $query->condition('nh.parent', $this->parents, 'IN');
    $query->fields('nh', array('parent'));
    return $query;
  }

  public function prepareRow ($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    if (isset($row->field_access)) {
      return;
    }

    $parent_exists = !empty($row->parent);
    $mapping_exists = !empty($this->access_mapping['parent']);

    if ( $parent_exists && $mapping_exists && array_key_exists($row->parent, $this->access_mapping['parent'])) {
      $row->field_access = $this->access_mapping['parent'][$row->parent];
    }
  }
}

class PPSTeamMigration extends PPSNodehierarchyMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->noAttachment();
    $this->promote(FALSE);

  }
}

/**
 * Minutes migration
 */
class PPSMinutesMigration extends PPSNodehierarchyMigration {

  public function __construct(array $arguments) {
    $this->sourceFields['field_date'] = t('Date');

    parent::__construct($arguments);

    $this->removeFieldMapping('promote', 'promote');
    $this->addFieldMapping('promote')->defaultValue(FALSE);
    $this->addSimpleMappings(array('field_date'));

    $this->addUnmigratedSources(array(
      'promote',
    ));
  }

  public function prepareRow ($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $date = date_parse($row->title);
    if (!empty($date['year']) && !empty($date['month']) && !empty($date['day'])) {
      $row->field_date = format_string('!year-!month-!day', array(
        '!year' => $date['year'],
        '!month' => $date['month'],
        '!day' => $date['day'],
      ));
    }
  }
}

/**
 * Minutes migration
 */
class PPSNewsletterMigration extends PPSNodehierarchyMigration {

  public function __construct(array $arguments) {
    $this->sourceFields['field_month'] = t('Date');

    parent::__construct($arguments);

    $this->removeFieldMapping('promote', 'promote');
    $this->addFieldMapping('promote')->defaultValue(FALSE);
    $this->addSimpleMappings(array('field_month'));

    $this->addUnmigratedSources(array(
      'promote',
    ));
  }

  public function prepareRow ($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $date = date_parse($row->title);
    if (!empty($date['year']) && !empty($date['month'])) {
      $row->field_month = format_string('!year-!month', array(
        '!year' => $date['year'],
        '!month' => $date['month'],
      ));
    }
  }
}

/**
 * Press review mappings and handling.
 */
class PPSPressReviewMigration extends PPSAttachmentNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('field_media_company', 2)
      ->sourceMigration('MediaCompanies')
      ->arguments(array('source_type' => 'tid'));
    $this->removeFieldMapping('promote', 'promote');
    $this->addFieldMapping('promote')->defaultValue(TRUE);

    $this->addFieldMapping('field_date', 'field_date');
    $this->addUnmigratedSources(array(
      'field_date:value2',
      'promote',
    ));
    $this->addUnmigratedDestinations(array(
      'field_media_company:source_type',
      'field_media_company:create_term',
      'field_media_company:ignore_case',
    ));
  }
}

class PPSEventMigration extends PPSAttachmentNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('field_event_type', 1)
      ->sourceMigration('EventTypes')
      ->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping('field_time', 'field_event');

    $this->addUnmigratedSources(array(
      'field_event:value2',
      'field_event:rrule',
    ));
    $this->addUnmigratedDestinations(array(
      'field_event_type:source_type',
      'field_event_type:create_term',
      'field_event_type:ignore_case',
    ));
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $row_array = (array)$row;
    $row->field_event = drupal_json_encode(array(
      'from' => $row->field_event[0],
      'to' => $row_array['field_event:value2'][0],
      'rrule' => $row_array['field_event:rrule'][0],
    ));
  }
}

class PPSGalleryMigration extends PPSNodeMigration {
  public function __construct(array $arguments) {
    $this->sourceFields['image_fids'] = t('Images');
    $this->sourceFields['image_alts'] = t('Image alternatives');
    $this->sourceFields['image_titles'] = t('Image titles');
    parent::__construct($arguments);

    $this->addFieldMapping('field_images', 'image_fids')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_images:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_images:alt', 'image_alts');
    $this->addFieldMapping('field_images:title', 'image_titles');

    $this->addUnmigratedDestinations(array(
      'field_images:language',
    ));
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('node', 'n')
      ->fields('n', array('nid', 'title'))
      ->condition('type', 'gallery_image')
      ->orderBy('f.field_sort_value');
    $query->innerJoin('node_revisions', 'nr', 'n.vid=nr.vid');
    $query->join('content_type_gallery_image', 'f', 'n.vid=f.vid and f.field_gallery_nid = :nid', array(':nid' => $row->nid));
    $query->fields('f', array('field_gallery_image_fid'));
    $results = $query->execute()->fetchAllAssoc('nid');

    $row->image_fids = array();
    $row->image_alts = array();
    $row->image_titles = array();
    foreach ($results as $result) {
      $row->image_fids[] = $result->field_gallery_image_fid;
      $row->image_alts[] = $result->title;
      $row->image_titles[] = $result->title;
    }
  }
}

class PPSPageMigration extends PPSAttachmentNodeMigration {
  protected $exclusions = array();

  public function __construct(array $arguments) {
    if (!empty($arguments['excluded nids'])) {
      $this->exclusions['nids'] = $arguments['excluded nids'];
    }
    if (!empty($arguments['dependencies'])) {
      $dependencies = $arguments['dependencies'];
      $this->exclusions['migrations'] = $dependencies;
    }
    parent::__construct($arguments);
  }

  protected function query() {
    $query = parent::query();
    $tables = db_query("show tables like 'migrate_map_%'")->fetchCol();
    if (!empty($this->exclusions['migrations']) && !empty($tables)) {
      $selects = array();
      foreach ($this->exclusions['migrations'] as $migration) {
        $table = 'migrate_map_' . drupal_strtolower($migration);
        if (in_array($table, $tables)) {
          $selects[] = "(select sourceid1 from $table)";
        }
      }
      if (!empty($selects)) {
        $imported = db_query(implode('union', $selects))->fetchCol();
        $query->condition('n.nid', $imported, 'NOT IN');
      }
    }
    if (!empty($this->exclusions['nids'])) {
      $query->condition('n.nid', $this->exclusions['nids'], 'NOT IN');
    }
    return $query;
  }

}
