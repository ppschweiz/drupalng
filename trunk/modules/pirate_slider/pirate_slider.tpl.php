<div class="coda-slider-wrapper">
  <div class="coda-slider preload" id="coda-slider-1" style="display: none">
    <noscript>
      Turn on Javascript
    </noscript>
<?php    
  $current_domain = domain_resolve_host();
  $domain_id = $current_domain['domain_id'];
?>
    <?php for ( $i = 1; variable_get('pirate_slider_slide'.$i.'_title', ''); $i++)
    { 
      $slide_prefix = 'pirate_slider_slide'.$domain_id.'_'.$i.'_';
?>
      <div class="panel">
        <div class="panel-wrapper slider1" style="background-image:url(<?php print variable_get($slide_prefix.'image', '') ?>)" onclick="self.location.href='<?php print variable_get($slide_prefix.'url', 'none') ?>'">
          <h2><?php print variable_get($slide_prefix.'title', '') ?></h2>
          <h1><?php print variable_get($slide_prefix.'subtitle', '') ?></h1>
          <p><?php print variable_get($slide_prefix.'linktext', '') ?><a href="<?php print variable_get($slide_prefix.'url', 'none') ?>" class="weiter">&nbsp;&nbsp;&nbsp;</a></p>
        </div>
      </div>
    <?php } ?>
  </div>
</div>
