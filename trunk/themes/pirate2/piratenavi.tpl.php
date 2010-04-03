					<?php global $language; 
						//$language->language; 
						//$val['link']['options']['langcode'];
						$classes = array('navakt','navpos','navpar','navmed', 'navmit');
					?>
					<ul id="hnavkont">
						<li class="navhome"><a class="link" href="/"></a><a class="up" id="navklapbut" onclick="navDoIt($(this))"></a></li>
						<?php
							$submenu = 0;
							while($submenu < 5) 
							{
								list($key, $val) = each($menu);
								if ((isset($val['link']['options']['langcode']) && $val['link']['options']['langcode'] == $language->language) || !isset($key))
								{
									print "<li class=\"".$classes[$submenu]."\">";
									if ($val) 
									{ 
										print l("<span class=\"link\">".t($val['link']['title'])."</span>", $val['link']['href'], array('html' => TRUE)); 
									} 									
									print "</li>";
									$submenu++;
								}
							}
						?>
					</ul>
					<ul id="subnavklapp">
						<li class="navhome"></li>					
						<?php reset($menu); ?>
						<li class="navakt">
							<?php list($key, $val) = each($menu); subnavigation($val['below']); ?>
						</li>
						<li class="navpos">
							<?php list($key, $val) = each($menu); subnavigation($val['below']); ?>
						</li>
						<li class="navpar">
							<?php list($key, $val) = each($menu); subnavigation($val['below']); ?>
						</li>
						<li class="navmed">
							<?php list($key, $val) = each($menu); subnavigation($val['below']); ?>
						</li>
						<li class="navmit">
							<?php list($key, $val) = each($menu); subnavigation($val['below']); ?>
						</li>
					</ul>
					<div class="clear"></div>


<?php 
	function subnavigation($submenu)
	{
		if (!$submenu)
			return;

		print "<ul class=\"subnav\">";
		foreach($submenu as $item) 
		{
			print "<li>";
			print l($item['link']['title'], $item['link']['href']);
			print "</li>";
		}
		print "</ul>";
	}
 ?>
