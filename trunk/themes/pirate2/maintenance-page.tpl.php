<?php
// $Id: maintenance-page.tpl.php,v 1.1.2.2 2009/05/03 11:12:28 johnalbin Exp $

/**
 * @file maintenance-page.tpl.php
 *
 * Theme implementation to display a single Drupal page while off-line.
 *
 * All the available variables are mirrored in page.tpl.php. Some may be left
 * blank but they are provided for consistency.
 *
 *
 * @see template_preprocess()
 * @see template_preprocess_maintenance_page()
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">

<head>
  <title>Pirates Offline :: Maintenance </title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body class="<?php print $body_classes; ?>" onload="initPage();">
	<div id="decortop">
        	<div id="topwrapper">
			<table><tr><td id="servicenavleft">
	                </td>
					<td id="servicenavright">
	       	        </td>
                       <td id="servicenavfix">
                                <ul>
                                        <li>Offline</li>
                                </ul>
                        </td></tr></table>
            	</div>
        </div>
	<div id="decormid">
		<div id="header">
       			<div id="pplogo"><a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><img src="/<?php print path_to_theme(TRUE)."/images/logo/".$language->language.".png"; ?>" alt="<?php print t('Home'); ?>" id="logo-image" /></a></div>
		</div>
			<div class="error-message">
				<div class="messages warning">
			        <?php print $content ?>
				</div>
			</div>
		</div>
		<div id="boardfot"></div>
	</div>
	<div id="decorfot">
		<div class="wrapper">
			<div id="fooleft">
				<a class="imgcc" href="http://creativecommons.org"></a>
				<?php switch($language->language) { 
				case "de": ?>			
					<p><b>Design: </b><a href="http://www.piratenpartei.ch">Piratenpartei Schweiz</a> <br /><a class="impressum" href="http://creativecommons.org/licenses/by/2.5/ch/deed.de">CC-BY 2.5 Schweiz</a></p>
				<?php break; case "fr": ?>			
					<p><b>Design: </b><a href="http://www.partipirate.ch">Parti Pirate Suisse</a> <br /><a class="impressum" href="http://creativecommons.org/licenses/by/2.5/ch/deed.fr">CC-BY 2.5 Suisse</a></p>
				<?php break; case "it": ?>			
					<p><b>Design: </b><a href="http://www.partitopirata.ch">Partito Pirata Svizzera</a> <br /><a class="impressum" href="http://creativecommons.org/licenses/by/2.5/ch/deed.it">CC-BY 2.5 Svizzera</a></p>
				<?php break; default: ?>			
					<p><b>Design: </b><a href="http://www.pirateparty.ch">Pirate Party Switzerland</a> <br /><a class="impressum" href="http://creativecommons.org/licenses/by/2.5/ch/deed.en">CC-BY 2.5 Switerland</a></p>				
				<?php } ?>

			</div>
			<div id="foocenter">
			</div>			
			<ul id="fooright">
			</ul>
		</div>
	</div>
	<?php print $closure; ?>
</body>
</html>
