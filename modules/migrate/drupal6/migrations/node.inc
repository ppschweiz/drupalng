<?php

/**
 * Common mappings for the node migrations.
 *
 * @todo Get the attachment description.
 * @todo Probably we nee to deal with attachments in different way.
 */
class PPSNodeMigration extends DrupalNode6Migration {

  private $domainMappings = array();

  public function __construct (array $arguments) {
    $this->sourceFields['attachment_fids'] = t('File attachments');
    $this->sourceFields['domain_site'] = t('Sent to all affiliates');
    $this->sourceFields['domains'] = t('Domains');

    parent::__construct ($arguments);

    $this->addFieldMapping('field_attachments', 'attachment_fids')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_attachments:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('domain_site')->defaultValue(FALSE);
    $this->addFieldMapping('domains', 'domains');

    $this->addUnmigratedDestinations(array(
      'field_attachments:language',
      'field_attachments:description',
      'field_attachments:display',
    ));

    if (!empty($arguments['domain_mappings'])) {
      $this->domainMappings = $arguments['domain_mappings'];
    }
  }

  protected function query () {
    $query = parent::query ();
    $query->addField('na_site', 'grant_view', 'domain_site');
    $query->addField('na_id', 'gid', 'domains');
    $query->leftJoin('node_access', 'na_site', "na_site.nid = n.nid and na_site.realm = 'domain_site'");
    $query->leftJoin('node_access', 'na_id', "na_id.nid = n.nid and na_id.realm = 'domain_id'");
    $query->groupBy('n.nid');
    return $query;
  }


  public function prepareRow ($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $row->attachment_fids = Database::getConnection('default', $this->sourceConnection)
      ->select('upload', 'u')
      ->fields('u', array('fid'))
      ->condition('nid', $row->nid)
      ->condition('vid', $row->vid)
      ->orderBy('weight')
      ->execute()
      ->fetchCol();

    $domain_id = $row->domains;
    $row->domains = array();
    if (array_key_exists($domain_id, $this->domainMappings)) {
      $row->domains[] = $this->domainMappings[$domain_id];
    }
  }
}

/**
 * Minutes migration
 */
class PPSMinutesMigration extends PPSNodeMigration {
  private $parents = array();

  public function __construct(array $arguments) {
    $this->sourceFields['field_date'] = t('Date');
    if (isset($arguments['parents'])) {
      if (is_array($arguments['parents'])) {
        $this->parents = $arguments['parents'];
      }
      else {
        $this->parents = array($arguments['parents']);
      }
    }
    parent::__construct($arguments);

    $this->removeFieldMapping('promote', 'promote');
    $this->addFieldMapping('promote')->defaultValue(FALSE);
    $this->addSimpleMappings(array('field_date'));

    $this->addUnmigratedSources(array(
      'domain_site',
      'promote',
    ));
  }

  protected function query() {
    $query = parent::query();
    $query->rightJoin('nodehierarchy', 'nh', 'n.nid = nh.nid');
    $query->condition('nh.parent', $this->parents, 'IN');
    return $query;
  }

  public function prepareRow ($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $date = date_parse($row->title);
    if (isset($date['year']) && isset($date['month']) && isset($date['day'])) {
      $row->field_date = format_string('!year-!month-!day', array(
        '!year' => $date['year'],
        '!month' => $date['month'],
        '!day' => $date['day'],
      ));
    }
  }
}

/**
 * Press review mappings and handling.
 */
class PPSPressReviewMigration extends PPSNodeMigration {
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

class PPSEventMigration extends PPSNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('field_event_type', 1)
      ->sourceMigration('EventTypes')
      ->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping('field_time', 'field_event');

    $this->addUnmigratedSources(array(
      'domain_site',
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

class PPSGalleryMigration extends DrupalNode6Migration {
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

    $this->addFieldMapping('domain_site')->defaultValue(TRUE);
    $this->addFieldMapping('domains')->defaultValue(array('piratenpartei_ch'));

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
