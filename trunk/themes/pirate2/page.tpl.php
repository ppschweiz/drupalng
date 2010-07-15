<?php
// $Id: page.tpl.php,v 1.14.2.10 2009/11/05 14:26:26 johnalbin Exp $

/**
 * @file page.tpl.php
 *
 * Theme implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $css: An array of CSS files for the current page.
 * - $directory: The directory the theme is located in, e.g. themes/garland or
 *   themes/garland/minelli.
 * - $is_front: TRUE if the current page is the front page. Used to toggle the mission statement.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Page metadata:
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or 'rtl'.
 * - $head_title: A modified version of the page title, for use in the TITLE tag.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $body_classes: A set of CSS classes for the BODY tag. This contains flags
 *   indicating the current layout (multiple columns, single column), the current
 *   path, whether the user is logged in, and so on.
 * - $body_classes_array: An array of the body classes. This is easier to
 *   manipulate then the string in $body_classes.
 * - $node: Full node object. Contains data that may not be safe. This is only
 *   available if the current page is on the node's primary url.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 * - $mission: The text of the site mission, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $search_box: HTML to display the search box, empty if search has been disabled.
 * - $primary_links (array): An array containing primary navigation links for the
 *   site, if they have been configured.
 * - $secondary_links (array): An array containing secondary navigation links for
 *   the site, if they have been configured.
 *
 * Page content (in order of occurrance in the default page.tpl.php):
 * - $left: The HTML for the left sidebar.
 *
 * - $breadcrumb: The breadcrumb trail for the current page.
 * - $title: The page title, for use in the actual HTML content.
 * - $help: Dynamic help text, mostly for admin pages.
 * - $messages: HTML for status and error messages. Should be displayed prominently.
 * - $tabs: Tabs linking to any sub-pages beneath the current page (e.g., the view
 *   and edit tabs when displaying a node).
 *
 * - $content: The main content of the current Drupal page.
 *
 * - $right: The HTML for the right sidebar.
 *
 * Footer/closing data:
 * - $feed_icons: A string of all feed icons for the current page.
 * - $footer_message: The footer message as defined in the admin settings.
 * - $footer : The footer region.
 * - $closure: Final closing markup from any modules that have altered the page.
 *   This variable should always be output last, after all other dynamic content.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml"
      xml:lang="<?php print $language->language; ?>"
      lang="<?php print $language->language; ?>"
      dir="<?php print $language->dir; ?>">

    <head>
        <title><?php print $head_title; ?></title>
        <?php print $head; ?>
        <?php print $styles; ?>
        <?php print $scripts; ?>
    </head>
    <body class="<?php print $body_classes; ?>" onload="initPage();">

        <div id="header" class="wrapper">
            <div id="logo">
                <h1 class="hidden"><a href="">Pirateparty Switzerland</a></h1>
            </div>

            <!--?php print $search_box; ?-->

        </div>

        <div id="servicenav">
            <div  class="wrapper" class="clearfix">
                <h2 class="hidden">Service navigation</h2>
                <?php print $servicenavleft ?>
                <!--ul id="servicenavleft" class="menu">
                    <li class="leaf first Chat" id=" menu-item-custom-id-5"><a href="#" title="">Chat</a></li>
                    <li class="leaf Forum" id=" menu-item-custom-id-6"><a href="#" title="Forum">Forum</a></li>
                    <li class="leaf Wiki" id=" menu-item-custom-id-7"><a href="#" title="Piratenwiki">Wiki</a></li>
                    <li class="leaf last www" id="menu-item-custom-id-8"><a href="#" title="">www</a></li>
                </ul-->
                <ul id="servicenavmid">
                    <li><a href="/contact" class="kontakt"><?php print t("Contact"); ?></a></li>
                    <?php if ($logged_in) {
                    ?>
                        <li title="<?php print t("Logout"); ?>"><?php print l(t('Logout'), 'logout', array('attributes' => array('class' => 'logout'))); ?></li>
                        <li title="<?php print t("User Page"); ?>"><?php print l(t('My Account'), 'user'); ?></li>
                    <?php } else {
                    ?>
                        <li title="<?php print t("Login"); ?>"><?php print l(t('Login'), 'user', array('attributes' => array('class' => 'login'))); ?></li>
                        <li title="<?php print t("Register User"); ?>"><?php print l(t('Register'), 'user/register'); ?></li>
                    <?php } ?>
                    <!--li title="Contact"><a href="#" class="kontakt">Kontakt</a></li>
                    <li title="Logout"><a href="#" class="logout">Logout</a></li>
                    <li title="User Page"><a href="#">My Account</a></li-->
                </ul>
                <?php print $servicenavright ?>
                    <!--ul id="servicenavright">
                        <li class="en first"><a href="http://www.pirateparty.ch/user/38" class="language-link">EN</a></li>
                        <li class="fr"><a href="http://www.partipirate.ch/user/38" class="language-link">FR</a></li>
                        <li class="de last active"><a href="http://www.piratenpartei.ch/user/38" class="language-link active">DE</a></li>
                    </ul-->
                </div>
            </div>
<!--
        <?php if ($messages) {
        ?>
                        <div class="wrapper error-message">
            <?php print $messages ?>
                    </div>
        <?php } ?>
-->
        <?php if ($tabs) {
 ?>
                        <div class="wrapper">
                            <!--?php print $tabs ?-->
                            <ul class="tabs primary clear-block">
                                <li><a href="#"><span class="tab">Create new account</span></a></li>
                                <li class="active"><a href="#" class="active"><span class="tab">Log in</span></a></li>
                                <li><a href="#"><span class="tab">Request new password</span></a></li>
                                <li><a href="#"><span class="tab">Validate e-mail</span></a></li>
                            </ul>
                        </div>
<?php } else { ?>
                        <div id="boardtop"></div>
<?php } ?>

                    <div id="boardmid">
                        <script type="text/javascript">
                            $(function() {
                                $("#navklap").click(function(){
                                    $(".bignavigation").switchClass('bignavigation', 'smallnavigation', 500);
                                    $(".smallnavigation").switchClass('smallnavigation', 'bignavigation', 500);
                                    return false;
                                });
                            });
                        </script>

                        <div id="navigation" class="bignavigation wrapper">
                <?php if ($primary_links) {
                ?>
                <?php print theme('piratenavi', menu_tree_page_data(variable_get('menu_primary_links_source', 'primary-links'))); ?>
<?php } ?>
                </div>

                <div class="body" id="content">
<?php print $breadcrumb ?>
                    <div class="contsitekopf"><div class="kopf"><h1><?php print t('Subnavigation'); ?></h1></div></div>
                    <div class="contbody">
                    <?php if ($content) {
                    ?>
                    <?php print $content; ?>
<?php } ?>
                </div>
                <div id="contsite">
                    <?php print theme('piratesubnavi', menu_tree_page_data('navigation')); ?>
<?php print $content_right ?>
                </div>
                <div class="clear"></div>
            </div>


        </div>
        <div id="boardfot"></div>

        <div id="decorfot">
            <div class="wrapper">
                <div id="fooleft">
                    <a class="imgcc" href="#"></a>
                    <!--p><b>Design: </b><a href="http://www.piratenpartei.ch">Piratenpartei Schweiz</a> <br /><a class="impressum" href="http://creativecommons.org/licenses/by/2.5/ch/deed.de">CC-BY 2.5 Schweiz</a></p-->
                    <?php switch ($language->language) {
                        case "de": ?>
                            <p><b>Design: </b><a href="http://www.piratenpartei.ch">Piratenpartei Schweiz</a> <br /><a class="impressum" href="http://creativecommons.org/licenses/by/2.5/ch/deed.de">CC-BY 2.5 Schweiz</a></p>
                    <?php break;
                        case "fr": ?>
                            <p><b>Design: </b><a href="http://www.partipirate.ch">Parti Pirate Suisse</a> <br /><a class="impressum" href="http://creativecommons.org/licenses/by/2.5/ch/deed.fr">CC-BY 2.5 Suisse</a></p>
                    <?php break;
                        case "it": ?>
                            <p><b>Design: </b><a href="http://www.partitopirata.ch">Partito Pirata Svizzera</a> <br /><a class="impressum" href="http://creativecommons.org/licenses/by/2.5/ch/deed.it">CC-BY 2.5 Svizzera</a></p>
                    <?php break;
                        default: ?>
                            <p><b>Design: </b><a href="http://www.pirateparty.ch">Pirate Party Switzerland</a> <br /><a class="impressum" href="http://creativecommons.org/licenses/by/2.5/ch/deed.en">CC-BY 2.5 Switerland</a></p>
<?php } ?>

                    </div>
                    <!--div id="foocenter"><?php print $footer; ?></div-->
                    <ul id="fooright">
                        <!--li><a class="medico pnetz" href="#"><span class="tip"><b>politnetz</b></span></a></li>
                        <li><a class="medico flick" href="#"><span class="tip"><b>identica</b></span></a></li>
                        <li><a class="medico mysp" href="#"><span class="tip"><b>facebook</b></span></a></li>
                        <li><a class="medico yout" href="#"><span class="tip"><b>twitter</b></span></a></li>
                        <li><a class="medico twit" href="#"><span class="tip"><b>youtube</b></span></a></li>
                        <li><a class="medico face" href="#"><span class="tip"><b>myspace</b></span></a></li>
                        <li><a class="medico ident" href="#"><span class="tip"><b>flickr</b></span></a></li>
                        <li><a class="medico rss" href="#"><span class="tip"><b>rss</b></span></a></li-->
                    <?php if (theme_get_setting('politnetz_available_' . $language->language)) { ?>
                            <li><a class="medico pnetz" href="<?php print theme_get_setting('politnetz_link_' . $language->language); ?>"><span class="tip"><b><?php print theme_get_setting('politnetz_hover_' . $language->language); ?></b></span></a></li>
                    <?php } ?>
                    <?php if (theme_get_setting('identica_available_' . $language->language)) {
                    ?>
                            <li><a class="medico flick" href="<?php print theme_get_setting('identica_link_' . $language->language); ?>"><span class="tip"><b><?php print theme_get_setting('identica_hover_' . $language->language); ?></b></span></a></li>
                    <?php } ?>
                    <?php if (theme_get_setting('facebook_available_' . $language->language)) {
                    ?>
                            <li><a class="medico mysp" href="<?php print theme_get_setting('facebook_link_' . $language->language); ?>"><span class="tip"><b><?php print theme_get_setting('facebook_hover_' . $language->language); ?></b></span></a></li>
                    <?php } ?>
                    <?php if (theme_get_setting('twitter_available_' . $language->language)) {
                    ?>
                            <li><a class="medico yout" href="<?php print theme_get_setting('twitter_link_' . $language->language); ?>"><span class="tip"><b><?php print theme_get_setting('twitter_hover_' . $language->language); ?></b></span></a></li>
                    <?php } ?>
                    <?php if (theme_get_setting('youtube_available_' . $language->language)) {
 ?>
                            <li><a class="medico twit" href="<?php print theme_get_setting('youtube_link_' . $language->language); ?>"><span class="tip"><b><?php print theme_get_setting('youtube_hover_' . $language->language); ?></b></span></a></li>
                    <?php } ?>
<?php if (theme_get_setting('myspace_available_' . $language->language)) { ?>
                            <li><a class="medico face" href="<?php print theme_get_setting('myspace_link_' . $language->language); ?>"><span class="tip"><b><?php print theme_get_setting('myspace_hover_' . $language->language); ?></b></span></a></li>
                    <?php } ?>
<?php if (theme_get_setting('flickr_available_' . $language->language)) { ?>
                            <li><a class="medico ident" href="<?php print theme_get_setting('flickr_link_' . $language->language); ?>"><span class="tip"><b><?php print theme_get_setting('flickr_hover_' . $language->language); ?></b></span></a></li>
                    <?php } ?>
<?php if (theme_get_setting('rss_available_' . $language->language)) { ?>
                            <li><a class="medico rss" href="<?php print theme_get_setting('rss_link_' . $language->language); ?>"><span class="tip"><b><?php print theme_get_setting('rss_hover_' . $language->language); ?></b></span></a></li>
<?php } ?>
                    </ul>
                </div>
            </div>
<?php print $closure; ?>
    </body>
</html>