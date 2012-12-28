<?php

/**
 * @file
 * Drupal settings
 */

/**
 * Database
 */
$databases = array (
  'default' => array (
    'default' => array (
      'database' => 'drupal',
      'username' => 'drupal',
      'password' => '',
      'host' => 'localhost',
      'port' => '',
      'driver' => 'mysql',
      'prefix' => '',
    ),
  ),
);

/**
 * No access to update.php
 */
$update_free_access = FALSE;

/**
 * Salt for one-time login links and cancel links, form tokens, etc.
 */
$drupal_hash_salt = 'EqplikHf17BrH6COUStvPOttilhlUKz4XkmuliLhbXQ';

/**
 * PHP settings:
 */

/**
 * Ensure garbage collection is enabled
 */
ini_set('session.gc_probability', 1);
ini_set('session.gc_divisor', 100);

/**
 * Set session lifetime (in seconds)
 */
ini_set('session.gc_maxlifetime', 200000);

/**
 * Set session cookie lifetime (in seconds)
 */
ini_set('session.cookie_lifetime', 2000000);

/**
 * Variable overrides:
 */
// admin/appearance
$conf['admin_theme'] = 'seven';

// Misc
$conf['maintenance_theme'] = 'seven';

/**
 * Reverse Proxy Configuration:
 */
# $conf['reverse_proxy'] = TRUE;
# $conf['reverse_proxy_addresses'] = array('a.b.c.d', ...);
# $conf['reverse_proxy_header'] = 'HTTP_X_CLUSTER_CLIENT_IP';


/**
 * String overrides:
 */
# $conf['locale_custom_strings_en'][''] = array(
#   'forum'      => 'Discussion board',
#   '@count min' => '@count minutes',
# );

/**
 *
 * IP blocking:
 */
$conf['blocked_ips'] = array();

/**
 * Fast 404 pages:
 */
$conf['404_fast_paths_exclude'] = '/\/(?:styles)\//';
$conf['404_fast_paths'] = '/\.(?:txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp)$/i';
$conf['404_fast_html'] = '<html xmlns="http://www.w3.org/1999/xhtml"><head><title>404 Not Found</title></head><body><h1>Not Found</h1><p>The requested URL "@path" was not found on this server.</p></body></html>';

/**
 * No file system operations
 */
$conf['allow_authorize_operations'] = FALSE;

/**
 * Stop words
 *
 * http://www.ranks.nl/stopwords was used as template for the non
 * english languages. The lists itself were slightly changed.
 *
 * The english list was taken from
 * http://www.textfixer.com/resources/common-english-words.txt and was
 * merged with the default list.
 */
$stop_wods = array(
// English
  'a', 'able', 'about', 'across', 'after', 'all', 'almost', 'also',
  'am', 'among', 'an', 'and', 'any', 'are', 'as', 'at', 'be', 'because',
  'been', 'before', 'but', 'by', 'can', 'cannot', 'could', 'dear',
  'did', 'do', 'does', 'either', 'else', 'ever', 'every', 'for', 'from',
  'get', 'got', 'had', 'has', 'have', 'he', 'her', 'hers', 'him', 'his',
  'how', 'however', 'i', 'if', 'in', 'into', 'is', 'it', 'its', 'just',
  'least', 'let', 'like', 'likely', 'may', 'me', 'might', 'most',
  'must', 'my', 'neither', 'no', 'nor', 'not', 'of', 'off', 'often',
  'on', 'only', 'onto', 'or', 'other', 'our', 'own', 'per', 'rather',
  'said', 'say', 'says', 'she', 'should', 'since', 'so', 'some', 'than',
  'that', 'the', 'their', 'them', 'then', 'there', 'these', 'they',
  'this', 'tis', 'to', 'too', 'twas', 'up', 'us', 'via', 'wants', 'was',
  'we', 'were', 'what', 'when', 'where', 'which', 'while', 'who',
  'whom', 'why', 'will', 'with', 'would', 'yet', 'you', 'your',

// German
  'aber', 'als', 'am', 'an', 'auch', 'auf','aus', 'bei', 'beim', 'bin',
  'bis', 'bist', 'da', 'dadurch', 'daher', 'darum', 'das', 'daß',
  'dass', 'dein', 'deine', 'dem', 'den', 'der', 'des', 'dessen',
  'deshalb', 'die', 'dies', 'diese', 'dieser', 'dieses', 'doch', 'dort',
  'du', 'durch', 'ein', 'eine', 'einem', 'einen', 'einer', 'eines', 'er',
  'es', 'euer', 'eure', 'für', 'fuer', 'hatte', 'hatten', 'hattest',
  'hattet', 'hier', 'hinter', 'ich', 'ihr', 'ihre', 'im', 'in', 'ist',
  'ja', 'jede', 'jedem', 'jeden', 'jeder', 'jedes', 'jener', 'jenes',
  'jetzt', 'kann', 'kannst', 'können', 'könnt', 'machen', 'mein',
  'meine', 'mit', 'muß',
  'mußt', 'musst', 'müssen', 'müßt', 'nach', 'nachdem', 'nein', 'nicht',
  'nun', 'oder', 'seid', 'sein', 'seine', 'sich', 'sie', 'sind', 'soll',
  'sollen', 'sollst', 'sollt', 'sonst', 'soweit', 'sowie', 'und',
  'unser', 'unsere', 'unter', 'vom', 'von', 'vor', 'wann', 'warum',
  'was', 'weiter', 'weitere', 'wenn', 'wer', 'werde', 'werden',
  'werdet', 'weshalb', 'wie', 'wieder', 'wieso', 'wir', 'wird', 'wirst',
  'wo', 'woher', 'wohin', 'zu', 'zum', 'zur', 'über',

// French
  'alors', 'au', 'aucuns', 'aussi', 'autre', 'avant', 'avec', 'avoir',
  'bon', 'car', 'ce', 'cela', 'ces', 'ceux', 'chaque', 'ci', 'comme',
  'comment', 'dans', 'des', 'du', 'dedans', 'dehors', 'depuis', 'deux',
  'devrait', 'doit', 'donc', 'dos', 'droite', 'début', 'elle', 'elles',
  'en', 'encore', 'essai', 'est', 'et', 'eu', 'fait', 'faites', 'fois',
  'font', 'force', 'haut', 'hors', 'ici', 'il', 'ils', 'je', 'juste',
  'la', 'le', 'les', 'leur', 'là', 'ma', 'maintenant', 'mais', 'mes',
  'mine', 'moins', 'mon', 'mot', 'même', 'ni', 'nommés', 'notre',
  'nous', 'nouveaux', 'ou', 'où', 'par', 'parce', 'parole', 'pas',
  'personnes', 'peut', 'peu', 'pièce', 'plupart', 'pour', 'pourquoi',
  'quand', 'que', 'quel', 'quelle', 'quelles', 'quels', 'qui', 'sa',
  'sans', 'ses', 'seulement', 'si', 'sien', 'son', 'sont', 'sous',
  'soyez', 'sujet', 'sur', 'ta', 'tandis', 'tellement', 'tels', 'tes',
  'ton', 'tous', 'tout', 'trop', 'très', 'tu', 'un', 'une', 'valeur',
  'voie', 'voient', 'vont', 'votre', 'vous', 'vu', 'ça', 'étaient',
  'état', 'étions', 'été', 'être',

// Italian
  'a', 'adesso', 'ai', 'al', 'alla', 'allo', 'allora', 'altre', 'altri',
  'altro', 'anche', 'ancora', 'avere', 'aveva', 'avevano', 'ben',
  'buono', 'che', 'chi', 'cinque', 'comprare', 'con', 'consecutivi',
  'consecutivo', 'cosa', 'cui', 'da', 'del', 'della', 'dello', 'dentro',
  'deve', 'devo', 'di', 'doppio', 'due', 'e', 'ecco', 'fare', 'fine',
  'fino', 'fra', 'gente', 'giu', 'ha', 'hai', 'hanno', 'ho', 'il',
  'indietro', 'invece', 'io', 'la', 'lavoro', 'le', 'lei', 'lo', 'loro',
  'lui', 'lungo', 'ma', 'me', 'meglio', 'molta', 'molti', 'molto',
  'nei', 'nella', 'no', 'noi', 'nome', 'nostro', 'nove', 'nuovi',
  'nuovo', 'o', 'oltre', 'ora', 'otto', 'peggio', 'pero', 'persone',
  'piu', 'poco', 'primo', 'promesso', 'qua', 'quarto', 'quasi',
  'quattro', 'quello', 'questo', 'qui', 'quindi', 'quinto', 'rispetto',
  'sara', 'secondo', 'sei', 'sembra', 'sembrava', 'senza', 'sette',
  'sia', 'siamo', 'siete', 'solo', 'sono', 'sopra', 'soprattutto',
  'sotto', 'stati', 'stato', 'stesso', 'su', 'subito', 'sul', 'sulla',
  'tanto', 'te', 'tempo', 'terzo', 'tra', 'tre', 'triplo', 'ultimo',
  'un', 'una', 'uno', 'va', 'vai', 'voi', 'volte', 'vostro',
);
// Deduplicate
$stop_wods = array_unique($stop_wods);
// Set to variable
$conf['pathauto_ignore_words'] = implode(', ', $stop_wods);

/**
 * No file system operations
 */
$conf['allow_authorize_operations'] = FALSE;

/**
 * Allow environment specific overrides
 */
$local_settings_filename = dirname(__FILE__) . DIRECTORY_SEPARATOR . 'local.settings.php';
if (file_exists($local_settings_filename)) {
  require_once $local_settings_filename;
}
