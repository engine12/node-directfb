
var DFB = require('./directfb');

var dfb = DFB.DirectFBCreate();
var keybrd = dfb.GetInputDevice(0);
var font = dfb.CreateFont( "./decker.ttf", { 
							flags: DFB.DFDESC_HEIGHT, 
							height: 10  });

var image = dfb.CreateImageProvider("/pics/linux_tipi.png");
var image_desc = image.GetSurfaceDescription();

var layer = dfb.GetDisplayLayer(0); //DLID_PRIMARY

	layer.SetCooperativeLevel(DFB.DLSCL_ADMINISTRATIVE);

var layer_config = layer.GetConfiguration();

var window1 = layer.CreateWindow({
		  flags: DFB.DWDESC_POSX | DFB.DWDESC_POSY | 
				DFB.DWDESC_WIDTH | DFB.DWDESC_HEIGHT | 
				DFB.DWDESC_CAPS | DFB.DWDESC_STACKING | DFB.DWDESC_SURFACE_CAPS,
		  posx: 0,
		  posy: 0,
		  width: image_desc.width,
		  height: image_desc.height,
		  caps: DFB.DWCAPS_ALPHACHANNEL,
		  surface_caps: DFB.DSCAPS_PREMULTIPLIED,
		  stacking: DFB.DWSC_UPPER  });

var window_surface1 = window1.GetSurface();
	window_surface1.SetFont(font);

	image.RenderTo(window_surface1);

	window_surface1.SetDrawingFlags(DFB.DSDRAW_SRC_PREMULTIPLY );
	window_surface1.SetColor(0xFF, 0x20, 0x20, 0x90 );
	window_surface1.DrawRectangle(0, 0, image_desc.width, image_desc.height );

	window_surface1.Flip();

	image.Release();

var buffer = window1.CreateEventBuffer()
	window1.AttachEventBuffer(buffer);

	window1.SetOpacity(0xFF);

var id1 = window1.GetID();

	window1.RequestFocus();
	window1.RaiseToTop();


var events = dfb.CreateInputEventBuffer( DFB.DICAPS_ALL );


var quit = DFB.DIKS_UP;

	while (quit == DFB.DIKS_UP) {
		console.log( "Waiting for event...\n" );

		quit=keybrd.GetKeyState(DFB.DIKI_ESCAPE);
		
		events.WaitForEvent();

		var event = events.GetEvent();
		if(event.type == DFB.DIET_BUTTONRELEASE)
		quit = DFB.DIKS_DOWN
		
		console.log("eventWin_ID: "+event.window_id);
		console.log( "Got " + event.clazz + "\n" );
	}

	buffer.Release();
	font.Release();

	window_surface1.Release();
	window1.Release();
	layer.Release();
	dfb.Release();
