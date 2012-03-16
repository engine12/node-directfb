var DFB = require('./directfb');

var dfb = DFB.DirectFBCreate();

var surface = dfb.CreateSurface({
    flags:  DFB.DSDESC_CAPS | DFB.DSDESC_WIDTH | DFB.DSDESC_HEIGHT,
    caps:   DFB.DSCAPS_PRIMARY | DFB.DSCAPS_FLIPPING,
    width:  140,
    height: 220
	} );

	surface.Clear();
	surface.Flip();

var events = dfb.CreateInputEventBuffer( DFB.DICAPS_ALL );

while (true) {
    console.log( "Waiting for event...\n" );

    events.WaitForEvent();


    var event = events.GetEvent();

    console.log( "Got " + event.clazz + "\n" );
}
