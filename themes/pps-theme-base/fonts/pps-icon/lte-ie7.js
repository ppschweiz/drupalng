/* Use this script if you need to support IE 7 and IE 6. */

window.onload = function() {
	function addIcon(el, entity) {
		var html = el.innerHTML;
		el.innerHTML = '<span style="font-family: \'pps-icon\'">' + entity + '</span>' + html;
	}
	var icons = {
			'icon-comment' : '&#xe000;',
			'icon-users' : '&#xe001;',
			'icon-user' : '&#xe002;',
			'icon-feed' : '&#xe003;',
			'icon-plus' : '&#xe004;',
			'icon-cross' : '&#xe005;',
			'icon-arrow-right' : '&#xe006;',
			'icon-arrow-left' : '&#xe007;',
			'icon-pencil' : '&#xe008;',
			'icon-search' : '&#xe009;',
			'icon-grid' : '&#xe00a;',
			'icon-list' : '&#xe00b;',
			'icon-star' : '&#xe00c;',
			'icon-heart' : '&#xe00d;',
			'icon-map-marker' : '&#xe00e;',
			'icon-home' : '&#xe00f;',
			'icon-phone' : '&#xe010;',
			'icon-camera' : '&#xe011;',
			'icon-arrow-left-2' : '&#xe012;',
			'icon-arrow-right-2' : '&#xe013;',
			'icon-arrow-up' : '&#xe014;',
			'icon-arrow-down' : '&#xe015;',
			'icon-cog' : '&#xe016;',
			'icon-wrench' : '&#xe017;',
			'icon-bars' : '&#xe018;',
			'icon-chart' : '&#xe019;',
			'icon-stats' : '&#xe01a;',
			'icon-eye' : '&#xe01b;',
			'icon-zoom-out' : '&#xe01c;',
			'icon-zoom-in' : '&#xe01d;',
			'icon-export' : '&#xe01e;',
			'icon-mail' : '&#xe01f;',
			'icon-delete' : '&#xe020;',
			'icon-thumbs-up' : '&#xe021;',
			'icon-thumbs-down' : '&#xe022;',
			'icon-tag' : '&#xe023;',
			'icon-warning' : '&#xe024;',
			'icon-unlocked' : '&#xe025;',
			'icon-locked' : '&#xe026;',
			'icon-cancel' : '&#xe027;',
			'icon-compass' : '&#xe028;',
			'icon-pin' : '&#xe029;',
			'icon-globe' : '&#xe02a;',
			'icon-flag' : '&#xe02b;',
			'icon-info' : '&#xe02c;',
			'icon-question' : '&#xe02d;',
			'icon-chat' : '&#xe02e;',
			'icon-trashcan' : '&#xe02f;',
			'icon-expand' : '&#xe030;',
			'icon-electricity' : '&#xe031;',
			'icon-directions' : '&#xe032;',
			'icon-pencil-2' : '&#xe033;',
			'icon-minus' : '&#xe034;',
			'icon-equals' : '&#xe035;',
			'icon-list-2' : '&#xe036;',
			'icon-clock' : '&#xe037;',
			'icon-calendar' : '&#xe038;',
			'icon-sun' : '&#xe039;',
			'icon-download' : '&#xe03a;',
			'icon-puzzle' : '&#xe03b;',
			'icon-bookmark' : '&#xe03c;',
			'icon-anchor' : '&#xe03d;',
			'icon-checkmark' : '&#xe03e;',
			'icon-pirate-flag' : '&#xe03f;',
			'icon-cc-by' : '&#xe041;',
			'icon-cc-sa' : '&#xe043;',
			'icon-cc-nd' : '&#xe045;',
			'icon-cc-nc-eu' : '&#xe042;',
			'icon-cc' : '&#xe040;'
		},
		els = document.getElementsByTagName('*'),
		i, attr, html, c, el;
	for (i = 0; i < els.length; i += 1) {
		el = els[i];
		attr = el.getAttribute('data-icon');
		if (attr) {
			addIcon(el, attr);
		}
		c = el.className;
		c = c.match(/icon-[^\s'"]+/);
		if (c && icons[c[0]]) {
			addIcon(el, icons[c[0]]);
		}
	}
};