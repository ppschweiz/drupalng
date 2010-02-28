<div class="coda-slider-wrapper">
  <div class="coda-slider preload" id="coda-slider-1" style="display: none">
    <noscript>
      Turn on Javascript
    </noscript>
    <?php for ( $i = 1; variable_get('pirate_slider_slide'.$i.'_title', ''); $i++)
    { ?>
      <div class="panel">
        <div class="panel-wrapper slider1" style="background-image:url(<?php print variable_get('pirate_slider_slide'.$i.'_image', '') ?>)" onclick="self.location.href='<?php print variable_get('pirate_slider_slide'.$i.'_url', 'none') ?>'">
          <h2><?php print variable_get('pirate_slider_slide'.$i.'_title', '') ?></h2>
          <h1><?php print variable_get('pirate_slider_slide'.$i.'_subtitle', '') ?></h1>
          <p><?php print variable_get('pirate_slider_slide'.$i.'_linktext', '') ?><a href="<?php print variable_get('pirate_slider_slide'.$i.'_url', 'none') ?>" class="weiter">&nbsp;&nbsp;&nbsp;</a></p>
        </div>
      </div>
    <?php } ?>
  </div>
</div>
