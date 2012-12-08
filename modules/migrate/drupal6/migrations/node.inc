<?php

/**
 * Common mappings for the node migrations.
 */
class PPSNodeMigration extends DrupalNode6Migration {

  private $domainMappings = array();

  public function __construct (array $arguments) {
    $this->sourceFields['attachment_fids'] = t('File attachments');
    $this->sourceFields['domain_site'] = t('Sent to all affiliates');
    $this->sourceFields['domains'] = t('Domains');

    parent::__construct ($arguments);

    $this->addFieldMapping('field_attachments', 'attachment_fids')->sourceMigration('Files');
    $this->addFieldMapping('field_attachments:file_class')->defaultValue('MigrateFileFid');
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
 * Press review mappings and handling.
 *
 * @todo Get the attachment description.
 */
class PPSPressReviewMigration extends PPSNodeMigration {
  public function __construct(array $arguments) {
    $this->sourceFields['attachment_fids'] = t('File attachments');

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
