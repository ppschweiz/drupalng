var BUTTONTEXT = [ "Hide" , "Show" ];

function initPage() // ...wird nach dem Laden der Seite aufgerufen
{
    jquery_ui_add(array('ui.effects'));

    // "Shortcuts" für die benutzten HTML-Elemente
    oMyDiv = document.getElementById( "subnavklapp" );
    oMyButton = document.getElementById( "navklapbut" );

    // Gibt's hier Cookie? Wenn ja, speichere sie in einem assoziativen Array
    myCookies = getCookies();
	
    // Gibt's ein Cookie mit Namen "HIDEDIV"? Wenn dieser den Wert "0" hat, blende den Layer ein
    if ( myCookies[ "HIDEDIV" ] == 0 )
    {
        oMyDiv.style.display = "block";
        oMyButton.firstChild.nodeValue = BUTTONTEXT[ 0 ];
    }
};

function navKlap() {
    $(".bignavigation").switchClass('bignavigation', 'smallnavigation', 500);
    $(".smallnavigation").switchClass('smallnavigation', 'bignavigation', 500);
    return false;
}

function navDoIt(self) 
{
    $('#subnavklapp>li').slideToggle();
    self.toggleClass('up');
    self.toggleClass('down');
    return false;
}

function navDoItOld()
{

    var isHidden = ( oMyDiv.style.display != "none" ) ? 1 : 0;
    oMyDiv.style.display = ( isHidden ) ? "none" : "block";
    oMyButton.firstChild.nodeValue = BUTTONTEXT[ isHidden ];
	
    // Ich habe den Button gedrückt. Je nach Status ist "isHidden" 1 oder 0. Dieser Wert wird gespeichert.
    setCookie( "HIDEDIV" , isHidden );
}

// ********************** cookie Funktionen ************************
function getCookies()
{
    var result = [] , i , values ,
    storedCookies = document.cookie.split(";");
    
    for ( i=0;i<storedCookies.length;i++)
    {
        values = storedCookies[ i ].split("=");
        result[ values[0].replace(/^ /,'') ] = values[ 1 ]; // Leerzeichen entfernen
    };
    return result;
}

function setCookieTime( days )
{
    if ( !days ) // Wenn keine Anzahl Tage angeben wurde, nehmen einen sehr weit entfernten Tag, d.h. der Cookie bleibt sehr lange gültig
        return ( new Date( 2037 , 0 , 1 )).toGMTString();
       
    return new Date( ( new Date().getTime() + 1000 * 3600 * 24 * days ) ).toGMTString();
}

function setCookie( name , value )
{
    // Hier wird ein  Cookie gesetzt, der "ewig" bestehen bleibt
    document.cookie = name + "=" + unescape( value ) + ";"+
    "expires=" + setCookieTime()  + ";";
}

function deleteCookie( cookieName )
{
    // Lösche den Cookie: Das Ablaufdatum ist gestern und somit wird der Cookie gelöscht
    document.cookie = coookieName + "=;expires=" + setCookieTime( -1 );
}
