					<?php print_r($menu); $language; ?>
					<ul id="hnavkont">
						<li class="navhome"><a class="link" href="/"></a><a class="up" id="navklapbut" onclick="navDoIt($(this))"></a></li>
						<?php list($key, $val) = each($menu);?>
						<li class="navakt">
							<?php if ($val) { print l("<span class=\"link\">".t($val['link']['title'])."(".$val['link']['options']['langcode'].")</span>", $val['link']['href'], array('html' => TRUE)); } ?>
						</li>
						<?php list($key, $val) = each($menu); ?>
						<li class="navpos">
							<?php if ($val) { print l("<span class=\"link\">".t($val['link']['title'])."(".$val['link']['options']['langcode'].")</span>", $val['link']['href'], array('html' => TRUE)); } ?>
						</li>
						<?php list($key, $val) = each($menu); ?>
						<li class="navpar">
							<?php if ($val) { print l("<span class=\"link\">".t($val['link']['title'])."(".$val['link']['options']['langcode'].")</span>", $val['link']['href'], array('html' => TRUE)); } ?>
						</li>
						<?php list($key, $val) = each($menu); ?>
						<li class="navmed">
							<?php if ($val) { print l("<span class=\"link\">".t($val['link']['title'])."(".$val['link']['options']['langcode'].")</span>", $val['link']['href'], array('html' => TRUE)); } ?>
						</li>
						<?php list($key, $val) = each($menu); ?>
						<li class="navmit">
							<?php if ($val) { print l("<span class=\"link\">".t($val['link']['title'])."(".$val['link']['options']['langcode'].")</span>", $val['link']['href'], array('html' => TRUE)); } ?>
						</li>
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
