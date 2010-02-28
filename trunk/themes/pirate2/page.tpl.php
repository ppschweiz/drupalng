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
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">

<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body class="<?php print $body_classes; ?>">
	<div id="decortop">
        	<div id="topwrapper">
			<div id="interlinks">
				<?php print $interlink ?>
	                </div>
        	        <ul id="servicenav">
				<li title="English"><a href="http://stage.pirateparty.ch">en</a></li>
                		<li title="Italiano"><a href="http://stage.partitopirata.ch">it</a></li>
				<li title="Français"><a href="http://stage.partipirate.ch">fr</a></li>
                		<li title="Deutsch"><a href="http://stage.piratenpartei.ch">de</a></li>

	                    	<li><a href="/kontaktformular" class="kontakt"><?php print $conttext ?></a></li>
        	            	<?php if ($logged_in) { ?>
					<li title="Logout"><?php print l(t('Logout'), 'logout', array('attributes'=>array('class'=>'logout'))); ?></li>
        	        	<?php } else { ?>
                 	   		<li title="Login"><a href="/user" class="login">Login</a></li>
		                <?php } ?>
        	        </ul>
            	</div>
        </div>
	<div id="decormid">
		<div id="header">
       			<div id="pplogo"><a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><img src="/<?php print path_to_theme(TRUE)."/images/logo/".$language->language.".png"; ?>" alt="<?php print t('Home'); ?>" id="logo-image" /></a></div>
			<?php print $search_box; ?>
		</div>
	        <?php if ($messages) { ?>
			<div class="error-message">
			        <?php print $messages ?>
			</div>
        	<?php } ?>
		<div id="boardtop"></div>
		<div id="boardmid">
			<div id="navigation">
				<div class="navwrapper">
					<ul id="hnavkont">
						<li class="navhome"><a class="link" href="<?php print $front_page; ?>"></a>
							<a href="javascript:void(0);" class="down" id="navklapbut" onclick="$('ul#subnavklapp>li').slideToggle();$(this).toggleClass('up');$(this).toggleClass('down'); return false;"></a>
						</li>
						<li class="navakt"><a href="in_blog.html"><span class="link">Aktuell</span></a></li>
						<li class="navpos"><a href="in_blog_detail.html"><span class="link">Positionen</span></a></li>
						<li class="navpar"><a href="in_content.html"><span class="link">Partei</span></a></li>
						<li class="navmed"><a href="in_formular.html"><span class="link">Medien</span></a></li>
						<li class="navmit"><a href="#"><span class="link">Mitmachen</span></a></li>
					</ul>
					<ul id="subnavklapp">
						<li class="navhome" style="display: none"></li>
						<li class="navakt" style="display: none">
							<ul class="subnav">
								<li><a href="#">Communiqués</a></li>
								<li><a href="#">Politblog</a></li>
								<li><a href="#">Termine/Events</a></li>
							</ul>
						</li>
						<li class="navpos" style="display: none">
							<ul class="subnav">
								<li><a href="#">Parteiprogramm</a></li>
								<li><a href="#">Themen</a></li>
								<li><a href="#">Positionspapiere</a></li>
								<li><a href="#">Vorstösse</a></li>
							</ul>
						</li>
						<li class="navpar" style="display: none">
							<ul class="subnav">
								<li><a href="#">Organe</a></li>
								<li><a href="#">Statuten</a></li>
								<li><a href="#">Netzwerk</a></li>
								<li><a href="#">Beitritt</a></li>
								<li><a href="#">Spenden</a></li>
							</ul>
						</li>
						<li class="navmed" style="display: none">
							<ul class="subnav">
								<li><a href="#">Pressdienst</a></li>
								<li><a href="#">Bilder</a></li>
								<li><a href="#">Downloads</a></li>
								<li><a href="#">Pressespiegel</a></li>
							</ul>
						</li>
						<li class="navmit" style="display: none">
							<ul class="subnav">
								<li><a href="">Mitmachen</a></li>
								<li><a href="">Community</a></li>
								<li class="extern"><a href="#">Forum</a></li>
								<li class="extern"><a href="#">Wiki</a></li>
							</ul>
						</li>
					</ul>
					<div class="clear"></div>
				</div>	
			</div>	
			<div class="body" id="content">
				<div class="contbodykopf"><div class="kopf"><a class="rss" href="#"></a><div id="breadcrump"><a class="home" href="#"></a><em>/</em><a href="#">Aktuell</a><em>/</em><a href="#">News</a></div></div></div>
				<div class="contsitekopf"><div class="kopf"><h1>Subnavigation</h1></div></div>
			
			
				<div class="contbody">
					<?php print $tabs ?>
					<?php print $content ?>
				</div>	
				<div id="contsite">
					<ul class="cosubnav">
						<li><a href="#"><em>News</em></a></li>
						<li><a href="#"><em>News</em></a></li>
						<li class="aktiv"><hr><p>News</p></li>
							<ul>
								<li><a href="#"><em>News</em></a></li>
								<li class="aktiv"><hr><p>News</p></li>
							</ul>
						<li><a href="#"><em>News</em></a></li>
						<li class="end"></li>
					</ul>
					<ul class="subactionbut">
						<li><a href="#"><img height="73px" width="64px" alt="Mitmachen bei den Piraten" src="/<?php print path_to_theme(TRUE); ?>/images/subacbut_mitmach.png">
							<span class="headone">Jetzt mitmachen!</span><span class="headtwo">Werde auch du ein Pirat.</span></a></li>
						<li><a href="#"><img height="73px" width="64px" alt="Jetzt mitmachen" src="/<?php print path_to_theme(TRUE); ?>/images/subacbut_shop.png">
							<span class="headone">Werbematerial</span><span class="headtwo">Piraten - an die Kanonen!</span></a></li>
						<li><a href="#"><img height="73px" width="64px" alt="Spenden" src="/<?php print path_to_theme(TRUE); ?>/images/subacbut_spende.png">
							<span class="headone">Unterstütze uns ...</span><span class="headtwo">...mit deiner Spende.</span></a></li>
					</ul>
				</div>
				<div class="clear"></div>		
			</div>
		</div>
		<div id="boardfot"></div>
	</div>
	<div id="decorfot">
		<div class="wrapper">
			<div id="fooleft">
				<a class="imgcc" href="#"></a><p>Piratenpartei Schweiz, Postfach, 1337 Vallorbe, info@piratenpartei.ch <br><a class="impressum" href="#">CC-BY 2.5 Switerland</a> | <a class="impressum" href="#">Impressum</a> | <a class="impressum" href="#">Kontakt</a></p>
			</div>
			<ul id="fooright">
				<li><a class="medico flick" href="#"><span class="tip"><b>PP bei Identica</b></span></a></li>
				<li><a class="medico mysp" href="#"><span class="tip"><b>PP bei Facebook</b></span></a></li>
				<li><a class="medico yout" href="#"><span class="tip"><b>PP bei Twitter</b></span></a></li>
				<li><a class="medico twit" href="#"><span class="tip"><b>PP bei YouTube</b></span></a></li>
				<li><a class="medico face" href="#"><span class="tip"><b>PP bei MySpace</b></span></a></li>
				<li><a class="medico ident" href="#"><span class="tip"><b>PP bei Flicker</b></span></a></li>
				<li><a class="medico rss" href="#"><span class="tip"><b>RSS-Newsfeed</b></span></a></li>
			</ul>
		</div>
	</div>
	<?php print $closure; ?>
</body>
</html>
