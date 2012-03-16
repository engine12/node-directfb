
var DFB = require('./directfb');

var dfb = DFB.DirectFBCreate();
var keybrd = dfb.GetInputDevice(0);
var font = dfb.CreateFont( "./decker.ttf", { 
							flags: DFB.DFDESC_HEIGHT, 
							height: 10  });

var layer = dfb.GetDisplayLayer(0); //DLID_PRIMARY

	layer.SetCooperativeLevel(DFB.DLSCL_ADMINISTRATIVE);

var layer_config = layer.GetConfiguration();
var rotation = 90;

	layer.EnableCursor(1);
     
var provider = dfb.CreateImageProvider("./desktop.png");

var bgsurface = dfb.CreateSurface({
						flags: DFB.DSDESC_WIDTH | DFB.DSDESC_HEIGHT | DFB.DSDESC_CAPS,
						width: 240,
						height: 320,
						caps: DFB.DSCAPS_SHARED    });
	
	provider.RenderTo(bgsurface);
	provider.Release();

	layer.SetBackgroundImage(bgsurface);
	layer.SetBackgroundMode(DFB.DLBM_IMAGE);
	    
var window2 = layer.CreateWindow({
					flags: DFB.DWDESC_POSX | DFB.DWDESC_POSY |
							DFB.DWDESC_WIDTH | DFB.DWDESC_HEIGHT | 
							DFB.DWDESC_STACKING | DFB.DWDESC_CAPS | 
							DFB.DWDESC_SURFACE_CAPS,

					caps: DFB.DWCAPS_ALPHACHANNEL,
					surface_caps: DFB.DSCAPS_PREMULTIPLIED,
					width: 150,
					height: 100,
					posx: 50,
					posy: 50,
					stacking: DFB.DWSC_UPPER });
					
var window_surface2 = window2.GetSurface();
var	buffer = window2.CreateEventBuffer();

	window_surface2.SetFont(font);
	window_surface2.SetDrawingFlags(DFB.DSDRAW_SRC_PREMULTIPLY );
	window_surface2.SetColor(0x00, 0x30, 0x10, 0xc0 );
	window_surface2.DrawRectangle(0, 0, 300, 200);
	window_surface2.SetColor(0x80, 0xa0, 0x00, 0x90 );
	window_surface2.FillRectangle(1, 1, 300-2, 200-2 );
	window_surface2.SetColor(0x40, 0x30, 0x10, 0xc0 );
	window_surface2.DrawString( "This is text on", -1, 5, 25, DFB.DSTF_LEFT );       
	window_surface2.DrawString( "window surface1", -1, 25, 45, DFB.DSTF_LEFT );       
	window_surface2.Flip();
	window2.SetOpacity(0xFF);

var window1 = layer.CreateWindow({
					  flags: DFB.DWDESC_POSX | DFB.DWDESC_POSY | 
								DFB.DWDESC_WIDTH | DFB.DWDESC_HEIGHT | 
								DFB.DWDESC_CAPS | DFB.DWDESC_STACKING | DFB.DWDESC_SURFACE_CAPS,
					  posx: 20,
					  posy: 20,
					  width: 120,
					  height: 60,
					  caps: DFB.DWCAPS_ALPHACHANNEL,
					  surface_caps: DFB.DSCAPS_PREMULTIPLIED,
					  stacking: DFB.DWSC_UPPER  });

var window_surface1 = window1.GetSurface();
	
	provider = dfb.CreateImageProvider("./dfblogo.png");
	provider.RenderTo(window_surface1);

	window_surface1.SetFont(font);
	window_surface1.SetDrawingFlags(DFB.DSDRAW_SRC_PREMULTIPLY );
	window_surface1.SetColor(0xFF, 0x20, 0x20, 0x90);
	window_surface1.DrawRectangle(0, 0, 120, 60);
	window_surface1.Flip();
	
	provider.Release();

	window1.AttachEventBuffer(buffer);
	
	window1.SetOpacity(0xFF );

var id1 = window1.GetID();
	console.log("window1_ID: "+id1);

	window1.RequestFocus();
	window1.RaiseToTop();
	upper = window1;

var quit = 0;
var grabbed = 0;
var startx = 0;
var starty = 0;
var endx = 0;
var endy = 0;
var winupdate = 0; 
var winx = 0; 
var winy = 0;
var active = 0;
var x2;
var buf = "x/y: xxx,xxx";

var rect = font.GetStringExtents(buf, -1);			
	rect.x = 1;
	rect.y = 1;
	rect.w += rect.w / 3;
	rect.h += 10;
	
var regx = eval(rect.x)+eval(rect.w)-1;
var regy = eval(rect.y)+eval(rect.h)-1;
					
	while (quit == 0) {

//		buffer.WaitForEventWithTimeout(0, 10 );
		buffer.WaitForEvent();
		var evt = buffer.GetEvent().window;
		
		   var window;

		   if (evt.window_id == id1)
				window = window1;
		   else
				window = window2;

		   if (evt.type == DFB.DWET_GOTFOCUS) {
				active = window;
		   }
		   else if (active != 0) {
				switch (evt.type) {

				case DFB.DWET_BUTTONDOWN:
					 if (!grabbed) {
						  grabbed = evt.buttons;
						  startx  = evt.cx;
						  starty  = evt.cy;
						  window.GrabPointer();
					 }
					 break;

				case DFB.DWET_BUTTONUP:
					 switch (evt.button) {
						  case DFB.DIBI_LEFT:
							   if (grabbed && !evt.buttons) {
									window.UngrabPointer();
									grabbed = 0;
							   }
							   break;
						  case DFB.DIBI_MIDDLE:
							   upper.LowerToBottom( upper );
							   upper =
								 (upper == window1) ? window2 : window1;
							   break;
						  case DFB.DIBI_RIGHT:
							   quit = DFB.DIKS_DOWN;
							   break;
						  default:
							   break;
					 }
					 break;

				case DFB.DWET_KEYDOWN:
					 if (grabbed)
						  break;
					 switch (evt.key_id) {
						  case DFB.DIKI_RIGHT:
							   active.Move (1, 0);
							   break;
						  case DFB.DIKI_LEFT:
							   active.Move (-1, 0);
							   break;
						  case DFB.DIKI_UP:
							   active.Move (0, -1);
							   break;
						  case DFB.DIKI_DOWN:
							   active.Move (0, 1);
							   break;
						  default:
							   break;
					 }
					 break;

				case DFB.DWET_LOSTFOCUS:
					 if (!grabbed && active == window)
						  active = 0;
					 break;

				default:
					 break;

				}
		   }

		   switch (evt.type) {

		   case DFB.DWET_MOTION:
				endx = evt.cx;
				endy = evt.cy;
				winx = evt.x;
				winy = evt.y;
				winupdate = 1;
				break;

		   case DFB.DWET_KEYDOWN:
				switch (evt.key_symbol) {
				case DFB.DIKS_ESCAPE:
				case DFB.DIKS_SMALL_Q:
				case DFB.DIKS_CAPITAL_Q:
				case DFB.DIKS_BACK:
				case DFB.DIKS_STOP:
					 quit = 1;
					 break;
				case DFB.DIKS_SMALL_R:
					 if (active) {
						  rotation = (rotation + 90) % 360;

						  active.SetRotation(rotation );
					 }
					 break;
				default:
					 break;
				}
				break;

		   default:
				break;
		   }
		


	  if (active) {
		   if (grabbed == 1) {
				active.Move(endx - startx, endy - starty);
				startx = endx;
				starty = endy;
		   }
		   else if (winupdate) {
				buf = "x/y: " + winx + "," + winy;

				window_surface1.SetColor(0x10, 0x10, 0x10, 0x77);
				window_surface1.FillRectangles(rect,1);
				window_surface1.SetColor(0x88, 0xCC, 0xFF, 0xAA );
				window_surface1.DrawString(buf, -1, rect.h/4, 5, DFB.DSTF_TOPLEFT );
				window_surface1.Flip({	x1: rect.x, y1: rect.y, x2: regx,  y2: regy		},0);
		
				winupdate = 0;
		   }
	  }
	}


	buffer.Release();
	font.Release();
	window_surface2.Release();
	window_surface1.Release();
	window2.Release();
	window1.Release();
	layer.Release();
	bgsurface.Release();
	dfb.Release();
