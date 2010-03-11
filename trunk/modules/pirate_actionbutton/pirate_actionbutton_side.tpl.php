<?php
  $current_domain = domain_resolve_host();
  $domain_id = $current_domain['domain_id'];
?>
<ul class="subactionbut">
	<li>
		<a href="<?php print variable_get('d'.$domain_id.'pirate_actionbutton_top_link', ''); ?>">
			<img alt="<?php print variable_get('d'.$domain_id.'pirate_actionbutton_top_title', ''); ?>" src="/<?php print path_to_theme(TRUE); ?>/images/subacbut_mitmach.png">
			<span class="headone"><?php print variable_get('d'.$domain_id.'pirate_actionbutton_top_title', ''); ?></span>
			<span class="headtwo"><?php print variable_get('d'.$domain_id.'pirate_actionbutton_top_subtitle', ''); ?></span>
		</a>
	</li>
	<li>
		<a href="<?php print variable_get('d'.$domain_id.'pirate_actionbutton_middle_link', ''); ?>">
			<img alt="<?php print variable_get('d'.$domain_id.'pirate_actionbutton_middle_title', ''); ?>" src="/<?php print path_to_theme(TRUE); ?>/images/subacbut_werbe.png">
			<span class="headone"><?php print variable_get('d'.$domain_id.'pirate_actionbutton_middle_title', ''); ?></span>
			<span class="headtwo"><?php print variable_get('d'.$domain_id.'pirate_actionbutton_middle_subtitle', ''); ?></span>
		</a>
	</li>
	<li>
		<a href="<?php print variable_get('d'.$domain_id.'pirate_actionbutton_bottom_link', ''); ?>">
			<img alt="<?php print variable_get('d'.$domain_id.'pirate_actionbutton_bottom_title', ''); ?>" src="/<?php print path_to_theme(TRUE); ?>/images/subacbut_spende.png">
			<span class="headone"><?php print variable_get('d'.$domain_id.'pirate_actionbutton_bottom_title', ''); ?></span>
			<span class="headtwo"><?php print variable_get('d'.$domain_id.'pirate_actionbutton_bottom_subtitle', ''); ?></span>
		</a>
	</li>
</ul>

