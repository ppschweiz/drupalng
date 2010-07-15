<?php
global $language;
$classes = array('navakt', 'navpos', 'navpar', 'navmed', 'navmit');
?>

<script type="text/javascript">
    $(function() {
        $("#navklap").click(function(){
            $(".bignavigation").switchClass('bignavigation', 'smallnavigation', 500);
            $(".smallnavigation").switchClass('smallnavigation', 'bignavigation', 500);
            return false;
        });
    });
</script>

<ul class="clearfix">
    <li class="navhome">
        <a class="link" href="/"></a>
        <a href="#" id="navklap"></a>
    </li>
    <?php
    $submenu = 0;
    while ($submenu < 5) {
        list($key, $val) = each($menu);
        if ((!isset($val['link']['options']['langcode']) || $val['link']['options']['langcode'] == $language->language) || !isset($key)) {
            print "<li class=\"" . $classes[$submenu] . "\">";
            if ($val) {
                print l( $val['link']['title'] , $val['link']['href'], array('html' => TRUE));
            }
            subnavigation($val['below']);
            print "</li>";
            $submenu++;
        }
    }
    ?>
</ul>


<?php

    function subnavigation($submenu) {
        global $language;
        if (!is_array($submenu)) {
            return;
        }

        print "<ul>";
        foreach ($submenu as $item) {
            if ((!isset($val['link']['options']['langcode']) || $val['link']['options']['langcode'] == $language->language)) {
                print "<li>";
                print l($item['link']['title'], $item['link']['href']);
                print "</li>";
            }
        }
        print "</ul>";
    }
?>
