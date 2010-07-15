<?php
global $language;
//$language->language;
//$val['link']['options']['langcode'];
$classes = array('navakt', 'navpos', 'navpar', 'navmed', 'navmit');
?>

<!--ul class="clearfix">
    <li class="navhome">
        <a href="/"></a>
        <a href="#" id="navklap"></a>
    </li>
    <li class="navakt">
        <a href="#" class="active">Aktuell</a>
        <ul>
            <li><a href="#">Communiques</a></li>
            <li><a href="#">Politblog</a></li>
            <li><a href="#">Piratenevents</a></li>
        </ul>
    </li>
    <li class="navpos">
        <a href="#">Position</a>
        <ul>
            <li><a href="#">Parteiprogramm</a></li>
            <li><a href="#">Wahlen</a></li>
        </ul>
    </li>
    <li class="navpar">
        <a href="#">Partei</a>
        <ul>
            <li><a href="#">Spenden</a></li>
            <li><a href="#">Statuten</a></li>
            <li><a href="#">Vorstand</a></li>
            <li><a href="#">Dokumente</a></li>
        </ul>
    </li>
    <li class="navmed">
        <a href="#">Medien</a>
        <ul>
            <li><a href="#">Pressedienst</a></li>
            <li><a href="#">Bilder</a></li>
            <li><a href="#">Logos</a></li>
            <li><a href="#">Pressespiegel</a></li>
        </ul>
    </li>
    <li class="navmit">
        <a href="#">Mitmachen</a>
        <ul>
            <li><a href="#">Werde Mitglied</a></li>
            <li><a href="#">Forum</a></li>
            <li><a href="#">Wiki</a></li>
            <li><a href="#">Chat</a></li>
            <li><a href="#">Gruppen</a></li>
        </ul>
    </li>
</ul-->
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
            //print "<ul class=\"subnav\"><li></li></ul>";
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
