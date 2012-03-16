var DFB = require('./directfb');

var dfb = DFB.DirectFBCreate();
	dfb.SetCooperativeLevel( DFB.DFSCL_FULLSCREEN );

var surface = dfb.CreateSurface( {
    flags:  DFB.DSDESC_CAPS | DFB.DSDESC_WIDTH | DFB.DSDESC_HEIGHT,
    caps:   DFB.DSCAPS_PRIMARY | DFB.DSCAPS_FLIPPING,
    width:  240,
    height: 320
	} );


var image = dfb.CreateImageProvider( "dfbtest2.png" );

var desc = image.GetSurfaceDescription();

var source = dfb.CreateSurface( desc );

	image.RenderTo( source );
	
	surface.Clear( 0x20, 0xc0, 0xf0, 0xff );
	while(true){
		for (i=0; i<500; i++) {
			var x = Math.random() % 241;
			var y = Math.random() % 321;
		
			surface.Blit( source, null, x, y );
		}

		surface.Flip();
	}

	surface.Release();
	dfb.Release();
