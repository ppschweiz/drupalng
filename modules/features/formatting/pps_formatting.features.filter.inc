<?php
/**
 * @file
 * pps_formatting.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function pps_formatting_filter_default_formats() {
  $formats = array();

  // Exported format: Migrate HTML.
  $formats['migrate_html'] = array(
    'format' => 'migrate_html',
    'name' => 'Migrate HTML',
    'cache' => '1',
    'status' => '1',
    'weight' => '0',
    'filters' => array(
      'htmlpurifier_advanced' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(
          'htmlpurifier_help' => 1,
          'htmlpurifier_advanced_config' => array(
            'Attr.AllowedClasses' => '',
            'Attr.AllowedFrameTargets' => '',
            'Attr.AllowedRel' => '',
            'Attr.AllowedRev' => '',
            'Attr.ClassUseCDATA' => '0',
            'Null_Attr.DefaultImageAlt' => '1',
            'Attr.DefaultInvalidImage' => '',
            'Attr.DefaultInvalidImageAlt' => 'Invalid image',
            'Attr.DefaultTextDir' => 'ltr',
            'Attr.EnableID' => '0',
            'Attr.ForbiddenClasses' => '',
            'Attr.IDBlacklist' => '',
            'Attr.IDBlacklistRegexp' => '.+',
            'Attr.IDPrefix' => '',
            'Attr.IDPrefixLocal' => '',
            'AutoFormat.AutoParagraph' => '1',
            'AutoFormat.Custom' => '',
            'AutoFormat.DisplayLinkURI' => '0',
            'AutoFormat.Linkify' => '0',
            'AutoFormat.PurifierLinkify.DocURL' => '#%s',
            'AutoFormat.PurifierLinkify' => '0',
            'AutoFormat.RemoveEmpty.RemoveNbsp.Exceptions' => 'td
th',
            'AutoFormat.RemoveEmpty.RemoveNbsp' => '1',
            'AutoFormat.RemoveEmpty' => '1',
            'AutoFormat.RemoveSpansWithoutAttributes' => '1',
            'CSS.AllowImportant' => '0',
            'CSS.AllowTricky' => '0',
            'CSS.AllowedFonts' => '',
            'CSS.AllowedProperties' => '',
            'CSS.ForbiddenProperties' => '',
            'CSS.MaxImgLength' => '1200px',
            'CSS.Proprietary' => '0',
            'CSS.Trusted' => '0',
            'Cache.DefinitionImpl' => 'Drupal',
            'Null_Cache.SerializerPath' => '1',
            'Cache.SerializerPermissions' => '493',
            'Core.AggressivelyFixLt' => '1',
            'Core.CollectErrors' => '0',
            'Core.ColorKeywords' => 'maroon:#800000
red:#FF0000
orange:#FFA500
yellow:#FFFF00
olive:#808000
purple:#800080
fuchsia:#FF00FF
white:#FFFFFF
lime:#00FF00
green:#008000
navy:#000080
blue:#0000FF
aqua:#00FFFF
teal:#008080
black:#000000
silver:#C0C0C0
gray:#808080
',
            'Core.ConvertDocumentToFragment' => '1',
            'Core.DirectLexLineNumberSyncInterval' => '0',
            'Core.EnableIDNA' => '0',
            'Core.Encoding' => 'utf-8',
            'Core.EscapeInvalidChildren' => '0',
            'Core.EscapeInvalidTags' => '0',
            'Core.EscapeNonASCIICharacters' => '0',
            'Core.HiddenElements' => 'script
style',
            'Core.Language' => 'en',
            'Null_Core.LexerImpl' => '1',
            'Null_Core.MaintainLineNumbers' => '1',
            'Core.NormalizeNewlines' => '1',
            'Core.RemoveInvalidImg' => '1',
            'Core.RemoveProcessingInstructions' => '1',
            'Core.RemoveScriptContents' => '1',
            'Filter.Custom' => '',
            'Filter.ExtractStyleBlocks.Escaping' => '1',
            'Null_Filter.ExtractStyleBlocks.Scope' => '1',
            'Null_Filter.ExtractStyleBlocks.TidyImpl' => '1',
            'Filter.ExtractStyleBlocks' => '0',
            'Filter.YouTube' => '1',
            'Null_HTML.Allowed' => '1',
            'Null_HTML.AllowedAttributes' => '1',
            'HTML.AllowedComments' => '<!--break-->',
            'Null_HTML.AllowedCommentsRegexp' => '1',
            'Null_HTML.AllowedElements' => '1',
            'Null_HTML.AllowedModules' => '1',
            'HTML.Attr.Name.UseCDATA' => '0',
            'HTML.BlockWrapper' => 'p',
            'HTML.CoreModules' => 'Structure
Text
Hypertext
List
NonXMLCommonAttributes
XMLCommonAttributes
CommonAttributes',
            'Null_HTML.CustomDoctype' => '1',
            'HTML.Doctype' => 'XHTML 1.0 Transitional',
            'HTML.FlashAllowFullScreen' => '0',
            'HTML.ForbiddenAttributes' => 'id
class
style',
            'HTML.ForbiddenElements' => '',
            'HTML.MaxImgLength' => '1200',
            'HTML.Nofollow' => '0',
            'HTML.Parent' => 'div',
            'HTML.Proprietary' => '0',
            'HTML.SafeEmbed' => '0',
            'HTML.SafeIframe' => '0',
            'HTML.SafeObject' => '0',
            'HTML.Strict' => '0',
            'HTML.TargetBlank' => '0',
            'HTML.TidyAdd' => '',
            'HTML.TidyLevel' => 'heavy',
            'HTML.TidyRemove' => '',
            'HTML.Trusted' => '0',
            'HTML.XHTML' => '1',
            'Output.CommentScriptContents' => '1',
            'Output.FixInnerHTML' => '1',
            'Output.FlashCompat' => '0',
            'Null_Output.Newline' => '1',
            'Output.SortAttr' => '0',
            'Output.TidyFormat' => '0',
            'Test.ForceNoIconv' => '0',
            'URI.AllowedSchemes' => 'http
https
mailto',
            'Null_URI.Base' => '1',
            'URI.DefaultScheme' => 'http',
            'URI.Disable' => '0',
            'URI.DisableExternal' => '0',
            'URI.DisableExternalResources' => '0',
            'URI.DisableResources' => '0',
            'URI.Host' => 'piratenpartei.dev',
            'URI.HostBlacklist' => '',
            'URI.MakeAbsolute' => '0',
            'Null_URI.Munge' => '1',
            'URI.MungeResources' => '0',
            'Null_URI.MungeSecretKey' => '1',
            'URI.OverrideAllowedSchemes' => '1',
            'Null_URI.SafeIframeRegexp' => '1',
          ),
        ),
      ),
    ),
  );

  // Exported format: Migrate Plain.
  $formats['migrate_plain'] = array(
    'format' => 'migrate_plain',
    'name' => 'Migrate Plain',
    'cache' => '1',
    'status' => '1',
    'weight' => '0',
    'filters' => array(
      'filter_footnotes' => array(
        'weight' => '-50',
        'status' => '1',
        'settings' => array(
          'footnotes_collapse' => 0,
        ),
      ),
      'textile' => array(
        'weight' => '-48',
        'status' => '1',
        'settings' => array(
          'textile_tags' => 0,
        ),
      ),
      'filter_html' => array(
        'weight' => '-46',
        'status' => '1',
        'settings' => array(
          'allowed_html' => '',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
    ),
  );

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => '1',
    'status' => '1',
    'weight' => '10',
    'filters' => array(
      'filter_html_escape' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => '1',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => '72',
        ),
      ),
      'filter_autop' => array(
        'weight' => '2',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Textile.
  $formats['textile'] = array(
    'format' => 'textile',
    'name' => 'Textile',
    'cache' => '1',
    'status' => '1',
    'weight' => '0',
    'filters' => array(
      'filter_html' => array(
        'weight' => '-50',
        'status' => '1',
        'settings' => array(
          'allowed_html' => '<dl> <dt> <dd>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'textile' => array(
        'weight' => '-46',
        'status' => '1',
        'settings' => array(
          'textile_tags' => 0,
        ),
      ),
      'filter_url' => array(
        'weight' => '-45',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => '72',
        ),
      ),
    ),
  );

  return $formats;
}
