#include "common.h"

#include "templates.h"

namespace DirectFB {

static v8::Persistent<v8::ObjectTemplate>  m_IDirectFB;

/**********************************************************************************************************************/

static v8::Handle<v8::Value>
IDirectFB_SetCooperativeLevel( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBCooperativeLevel level = (DFBCooperativeLevel) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetCooperativeLevel( thiz, level ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFB_SetVideoMode( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int width = (int) args[0]->IntegerValue();

     int height = (int) args[1]->IntegerValue();

     int bpp = (int) args[2]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetVideoMode( thiz, width, height, bpp ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFB_GetDeviceDescription( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBGraphicsDeviceDescription ret_desc;

     V8_DIRECTFB_CALL( thiz->GetDeviceDescription( thiz, &ret_desc ) );

     return DFBGraphicsDeviceDescription_construct( &ret_desc );
}

static v8::Handle<v8::Value>
IDirectFB_EnumVideoModes( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBVideoModeCallback callback = (DFBVideoModeCallback) args[0]->IntegerValue();

     void *callbackdata;
     #warning unimplemented (context pointer)
     D_UNIMPLEMENTED();

     V8_DIRECTFB_CALL( thiz->EnumVideoModes( thiz, callback, callbackdata ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFB_CreateSurface( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBSurfaceDescription *_desc = NULL;
     DFBSurfaceDescription desc;
     if (args[0]->IsObject()) {
          DFBSurfaceDescription_read( &desc, args[0] );
          _desc = &desc;
     }

     IDirectFBSurface *ret_interface;

     V8_DIRECTFB_CALL( thiz->CreateSurface( thiz, _desc, &ret_interface ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBSurface_template();

     return Construct( templ, ret_interface );
}

static v8::Handle<v8::Value>
IDirectFB_CreatePalette( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBPaletteDescription *_desc = NULL;
     DFBPaletteDescription desc;
     if (args[0]->IsObject()) {
          DFBPaletteDescription_read( &desc, args[0] );
          _desc = &desc;
     }

     IDirectFBPalette *ret_interface;

     V8_DIRECTFB_CALL( thiz->CreatePalette( thiz, _desc, &ret_interface ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBPalette_template();

     return Construct( templ, ret_interface );
}

static v8::Handle<v8::Value>
IDirectFB_EnumScreens( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBScreenCallback callback = (DFBScreenCallback) args[0]->IntegerValue();

     void *callbackdata;
     #warning unimplemented (context pointer)
     D_UNIMPLEMENTED();

     V8_DIRECTFB_CALL( thiz->EnumScreens( thiz, callback, callbackdata ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFB_GetScreen( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBScreenID screen_id = (DFBScreenID) args[0]->IntegerValue();

     IDirectFBScreen *ret_interface;

     V8_DIRECTFB_CALL( thiz->GetScreen( thiz, screen_id, &ret_interface ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBScreen_template();

     return Construct( templ, ret_interface );
}

static v8::Handle<v8::Value>
IDirectFB_EnumDisplayLayers( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBDisplayLayerCallback callback = (DFBDisplayLayerCallback) args[0]->IntegerValue();

     void *callbackdata;
     #warning unimplemented (context pointer)
     D_UNIMPLEMENTED();

     V8_DIRECTFB_CALL( thiz->EnumDisplayLayers( thiz, callback, callbackdata ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFB_GetDisplayLayer( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBDisplayLayerID layer_id = (DFBDisplayLayerID) args[0]->IntegerValue();

     IDirectFBDisplayLayer *ret_interface;

     V8_DIRECTFB_CALL( thiz->GetDisplayLayer( thiz, layer_id, &ret_interface ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBDisplayLayer_template();

     return Construct( templ, ret_interface );
}

static v8::Handle<v8::Value>
IDirectFB_EnumInputDevices( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBInputDeviceCallback callback = (DFBInputDeviceCallback) args[0]->IntegerValue();

     void *callbackdata;
     #warning unimplemented (context pointer)
     D_UNIMPLEMENTED();

     V8_DIRECTFB_CALL( thiz->EnumInputDevices( thiz, callback, callbackdata ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFB_GetInputDevice( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBInputDeviceID device_id = (DFBInputDeviceID) args[0]->IntegerValue();

     IDirectFBInputDevice *ret_interface;

     V8_DIRECTFB_CALL( thiz->GetInputDevice( thiz, device_id, &ret_interface ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBInputDevice_template();

     return Construct( templ, ret_interface );
}

static v8::Handle<v8::Value>
IDirectFB_CreateEventBuffer( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBEventBuffer *ret_buffer;

     V8_DIRECTFB_CALL( thiz->CreateEventBuffer( thiz, &ret_buffer ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBEventBuffer_template();

     return Construct( templ, ret_buffer );
}

static v8::Handle<v8::Value>
IDirectFB_CreateInputEventBuffer( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBInputDeviceCapabilities caps = (DFBInputDeviceCapabilities) args[0]->IntegerValue();

     DFBBoolean global = (DFBBoolean) args[1]->IntegerValue();

     IDirectFBEventBuffer *ret_buffer;

     V8_DIRECTFB_CALL( thiz->CreateInputEventBuffer( thiz, caps, global, &ret_buffer ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBEventBuffer_template();

     return Construct( templ, ret_buffer );
}

static v8::Handle<v8::Value>
IDirectFB_CreateImageProvider( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     const char *filename = NULL;
     v8::String::Utf8Value utf8_filename(args[0]);
     filename = *utf8_filename;

     IDirectFBImageProvider *ret_interface;

     V8_DIRECTFB_CALL( thiz->CreateImageProvider( thiz, filename, &ret_interface ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBImageProvider_template();

     return Construct( templ, ret_interface );
}

static v8::Handle<v8::Value>
IDirectFB_CreateVideoProvider( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     const char *filename = NULL;
     v8::String::Utf8Value utf8_filename(args[0]);
     filename = *utf8_filename;

     IDirectFBVideoProvider *ret_interface;

     V8_DIRECTFB_CALL( thiz->CreateVideoProvider( thiz, filename, &ret_interface ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBVideoProvider_template();

     return Construct( templ, ret_interface );
}

static v8::Handle<v8::Value>
IDirectFB_CreateFont( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     const char *filename = NULL;
     v8::String::Utf8Value utf8_filename(args[0]);
     filename = *utf8_filename;

     DFBFontDescription *_desc = NULL;
     DFBFontDescription desc;
     if (args[1]->IsObject()) {
          DFBFontDescription_read( &desc, args[1] );
          _desc = &desc;
     }

     IDirectFBFont *ret_interface;

     V8_DIRECTFB_CALL( thiz->CreateFont( thiz, filename, _desc, &ret_interface ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBFont_template();

     return Construct( templ, ret_interface );
}

static v8::Handle<v8::Value>
IDirectFB_CreateDataBuffer( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBDataBufferDescription *_desc = NULL;
     DFBDataBufferDescription desc;
     if (args[0]->IsObject()) {
          DFBDataBufferDescription_read( &desc, args[0] );
          _desc = &desc;
     }

     IDirectFBDataBuffer *ret_interface;

     V8_DIRECTFB_CALL( thiz->CreateDataBuffer( thiz, _desc, &ret_interface ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBDataBuffer_template();

     return Construct( templ, ret_interface );
}

static v8::Handle<v8::Value>
IDirectFB_GetClipboardData( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     char *ret_mimetype;
     #warning unimplemented (return string)
     D_UNIMPLEMENTED();

     void *ret_data;
     #warning unimplemented (return pointer)
     D_UNIMPLEMENTED();

     unsigned int ret_size;

     V8_DIRECTFB_CALL( thiz->GetClipboardData( thiz, &ret_mimetype, &ret_data, &ret_size ) );

     return v8::Integer::New( ret_size );
}

static v8::Handle<v8::Value>
IDirectFB_Suspend( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->Suspend( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFB_Resume( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->Resume( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFB_WaitIdle( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->WaitIdle( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFB_WaitForSync( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->WaitForSync( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFB_GetInterface( const v8::Arguments& args )
{
     IDirectFB *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFB );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     const char *type = NULL;
     v8::String::Utf8Value utf8_type(args[0]);
     type = *utf8_type;

     const char *implementation = NULL;
     v8::String::Utf8Value utf8_implementation(args[1]);
     implementation = *utf8_implementation;

     void *arg;
     #warning unimplemented (context pointer)
     D_UNIMPLEMENTED();

     void *ret_interface;
     #warning unimplemented (return pointer)
     D_UNIMPLEMENTED();

     V8_DIRECTFB_CALL( thiz->GetInterface( thiz, type, implementation, arg, &ret_interface ) );

     return v8::Undefined();
}

/**********************************************************************************************************************/

v8::Handle<v8::ObjectTemplate>
IDirectFB_template()
{
     if (m_IDirectFB.IsEmpty()) {
          v8::HandleScope handle_scope;
          v8::Handle<v8::ObjectTemplate> templ;

          templ = v8::ObjectTemplate::New();

          templ->SetInternalFieldCount( 1 );

          templ->Set( v8::String::NewSymbol("Release"), v8::FunctionTemplate::New(IAny_release) );
          templ->Set( v8::String::NewSymbol("SetCooperativeLevel"), v8::FunctionTemplate::New(IDirectFB_SetCooperativeLevel) );
          templ->Set( v8::String::NewSymbol("SetVideoMode"), v8::FunctionTemplate::New(IDirectFB_SetVideoMode) );
          templ->Set( v8::String::NewSymbol("GetDeviceDescription"), v8::FunctionTemplate::New(IDirectFB_GetDeviceDescription) );
          templ->Set( v8::String::NewSymbol("EnumVideoModes"), v8::FunctionTemplate::New(IDirectFB_EnumVideoModes) );
          templ->Set( v8::String::NewSymbol("CreateSurface"), v8::FunctionTemplate::New(IDirectFB_CreateSurface) );
          templ->Set( v8::String::NewSymbol("CreatePalette"), v8::FunctionTemplate::New(IDirectFB_CreatePalette) );
          templ->Set( v8::String::NewSymbol("EnumScreens"), v8::FunctionTemplate::New(IDirectFB_EnumScreens) );
          templ->Set( v8::String::NewSymbol("GetScreen"), v8::FunctionTemplate::New(IDirectFB_GetScreen) );
          templ->Set( v8::String::NewSymbol("EnumDisplayLayers"), v8::FunctionTemplate::New(IDirectFB_EnumDisplayLayers) );
          templ->Set( v8::String::NewSymbol("GetDisplayLayer"), v8::FunctionTemplate::New(IDirectFB_GetDisplayLayer) );
          templ->Set( v8::String::NewSymbol("EnumInputDevices"), v8::FunctionTemplate::New(IDirectFB_EnumInputDevices) );
          templ->Set( v8::String::NewSymbol("GetInputDevice"), v8::FunctionTemplate::New(IDirectFB_GetInputDevice) );
          templ->Set( v8::String::NewSymbol("CreateEventBuffer"), v8::FunctionTemplate::New(IDirectFB_CreateEventBuffer) );
          templ->Set( v8::String::NewSymbol("CreateInputEventBuffer"), v8::FunctionTemplate::New(IDirectFB_CreateInputEventBuffer) );
          templ->Set( v8::String::NewSymbol("CreateImageProvider"), v8::FunctionTemplate::New(IDirectFB_CreateImageProvider) );
          templ->Set( v8::String::NewSymbol("CreateVideoProvider"), v8::FunctionTemplate::New(IDirectFB_CreateVideoProvider) );
          templ->Set( v8::String::NewSymbol("CreateFont"), v8::FunctionTemplate::New(IDirectFB_CreateFont) );
          templ->Set( v8::String::NewSymbol("CreateDataBuffer"), v8::FunctionTemplate::New(IDirectFB_CreateDataBuffer) );
          templ->Set( v8::String::NewSymbol("GetClipboardData"), v8::FunctionTemplate::New(IDirectFB_GetClipboardData) );
          templ->Set( v8::String::NewSymbol("Suspend"), v8::FunctionTemplate::New(IDirectFB_Suspend) );
          templ->Set( v8::String::NewSymbol("Resume"), v8::FunctionTemplate::New(IDirectFB_Resume) );
          templ->Set( v8::String::NewSymbol("WaitIdle"), v8::FunctionTemplate::New(IDirectFB_WaitIdle) );
          templ->Set( v8::String::NewSymbol("WaitForSync"), v8::FunctionTemplate::New(IDirectFB_WaitForSync) );
          templ->Set( v8::String::NewSymbol("GetInterface"), v8::FunctionTemplate::New(IDirectFB_GetInterface) );

          m_IDirectFB = v8::Persistent<v8::ObjectTemplate>::New( handle_scope.Close( templ ) );
     }

     return m_IDirectFB;
}

}
