var dfblib = require('./directfb');
var dfb = dfblib.DirectFBCreate();

dfb.SetCooperativeLevel( dfblib.DFSCL_FULLSCREEN );


var surface = dfb.CreateSurface( {
    flags:  dfblib.DSDESC_CAPS | dfblib.DSDESC_WIDTH | dfblib.DSDESC_HEIGHT,
    caps:   dfblib.DSCAPS_PRIMARY | dfblib.DSCAPS_FLIPPING,
    width:  240,
    height: 320
} );



var fonts = {};

for (i=0; i<1; i++)
    fonts[i] = dfb.CreateFont( "/root/fbtexture/decker.ttf", { flags: dfblib.DFDESC_HEIGHT, height:10 } );


surface.SetColor( 0xff, 0xff, 0xff, 0xff );

for (i=0; i<1000; i++) {
    surface.Clear();

//    surface.SetFont( fonts[rand() % 200] );
    surface.SetFont( fonts[0] );
    surface.DrawString( "ABCDEFGHIJHKLMNOPQRSTUVWXYZ", -1, 100, 100, dfblib.DSTF_LEFT );
//    surface.DrawString( "ABCDEFGHIJHKLMNOPQRSTUVWXYZ");

    surface.Flip();
}



for (i=0; i<1; i++)
    fonts[i].Release();

surface.Release();
dfb.Release();

