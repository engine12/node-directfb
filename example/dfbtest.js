var DFB = require('./directfb');

var dfb = DFB.DirectFBCreate();

	dfb.SetCooperativeLevel( DFB.DFSCL_FULLSCREEN );


var surface = dfb.CreateSurface( {
    flags:  DFB.DSDESC_CAPS | DFB.DSDESC_WIDTH | DFB.DSDESC_HEIGHT,
    caps:   DFB.DSCAPS_PRIMARY | DFB.DSCAPS_FLIPPING,
    width:  240,
    height: 320
	} );

	surface.Clear( 0x20, 0xc0, 0xf0, 0xff );
	while(true){

    for (i=0; i<300; i++) {

        var x = Math.random() % 241;
        var y = Math.random() % 321;
    
        surface.SetColor( i*2, i*3, i*4, i*5 );
        surface.FillRectangle( x, y, 30, 30 );
    }

    surface.Flip();

	}

	surface.Release();
	dfb.Release();

