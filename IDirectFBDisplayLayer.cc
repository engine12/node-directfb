#include "common.h"

#include "templates.h"

namespace DirectFB {

static v8::Persistent<v8::ObjectTemplate>  m_IDirectFBDisplayLayer;

/**********************************************************************************************************************/

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_GetID( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBDisplayLayerID ret_layer_id;

     V8_DIRECTFB_CALL( thiz->GetID( thiz, &ret_layer_id ) );

     return v8::Integer::New( ret_layer_id );
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_GetDescription( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBDisplayLayerDescription ret_desc;

     V8_DIRECTFB_CALL( thiz->GetDescription( thiz, &ret_desc ) );

     return DFBDisplayLayerDescription_construct( &ret_desc );
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_GetSourceDescriptions( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBDisplayLayerSourceDescription ret_descriptions;

     V8_DIRECTFB_CALL( thiz->GetSourceDescriptions( thiz, &ret_descriptions ) );

     return DFBDisplayLayerSourceDescription_construct( &ret_descriptions );
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_GetCurrentOutputField( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int ret_field;

     V8_DIRECTFB_CALL( thiz->GetCurrentOutputField( thiz, &ret_field ) );

     return v8::Integer::New( ret_field );
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_GetSurface( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBSurface *ret_interface;

     V8_DIRECTFB_CALL( thiz->GetSurface( thiz, &ret_interface ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBSurface_template();

     return Construct( templ, ret_interface );
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_GetScreen( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBScreen *ret_interface;

     V8_DIRECTFB_CALL( thiz->GetScreen( thiz, &ret_interface ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBScreen_template();

     return Construct( templ, ret_interface );
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_SetCooperativeLevel( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBDisplayLayerCooperativeLevel level = (DFBDisplayLayerCooperativeLevel) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetCooperativeLevel( thiz, level ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_GetConfiguration( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBDisplayLayerConfig ret_config;

     V8_DIRECTFB_CALL( thiz->GetConfiguration( thiz, &ret_config ) );

     return DFBDisplayLayerConfig_construct( &ret_config );
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_TestConfiguration( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBDisplayLayerConfig *_config = NULL;
     DFBDisplayLayerConfig config;
     if (args[0]->IsObject()) {
          DFBDisplayLayerConfig_read( &config, args[0] );
          _config = &config;
     }

     DFBDisplayLayerConfigFlags ret_failed;

     V8_DIRECTFB_CALL( thiz->TestConfiguration( thiz, _config, &ret_failed ) );

     return v8::Integer::New( ret_failed );
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_SetConfiguration( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBDisplayLayerConfig *_config = NULL;
     DFBDisplayLayerConfig config;
     if (args[0]->IsObject()) {
          DFBDisplayLayerConfig_read( &config, args[0] );
          _config = &config;
     }

     V8_DIRECTFB_CALL( thiz->SetConfiguration( thiz, _config ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_SetScreenLocation( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     float x = (float) args[0]->IntegerValue();

     float y = (float) args[1]->IntegerValue();

     float width = (float) args[2]->IntegerValue();

     float height = (float) args[3]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetScreenLocation( thiz, x, y, width, height ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_SetScreenPosition( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int x = (int) args[0]->IntegerValue();

     int y = (int) args[1]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetScreenPosition( thiz, x, y ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_SetScreenRectangle( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int x = (int) args[0]->IntegerValue();

     int y = (int) args[1]->IntegerValue();

     int width = (int) args[2]->IntegerValue();

     int height = (int) args[3]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetScreenRectangle( thiz, x, y, width, height ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_SetOpacity( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     u8 opacity = (u8) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetOpacity( thiz, opacity ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_SetSourceRectangle( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int x = (int) args[0]->IntegerValue();

     int y = (int) args[1]->IntegerValue();

     int width = (int) args[2]->IntegerValue();

     int height = (int) args[3]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetSourceRectangle( thiz, x, y, width, height ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_SetFieldParity( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int field = (int) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetFieldParity( thiz, field ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_SetClipRegions( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBRegion *_regions = NULL;
     DFBRegion regions;
     if (args[0]->IsObject()) {
          DFBRegion_read( &regions, args[0] );
          _regions = &regions;
     }

     int num_regions = (int) args[1]->IntegerValue();

     DFBBoolean positive = (DFBBoolean) args[2]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetClipRegions( thiz, _regions, num_regions, positive ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_SetSrcColorKey( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     u8 r = (u8) args[0]->IntegerValue();

     u8 g = (u8) args[1]->IntegerValue();

     u8 b = (u8) args[2]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetSrcColorKey( thiz, r, g, b ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_SetDstColorKey( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     u8 r = (u8) args[0]->IntegerValue();

     u8 g = (u8) args[1]->IntegerValue();

     u8 b = (u8) args[2]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetDstColorKey( thiz, r, g, b ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_GetLevel( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int ret_level;

     V8_DIRECTFB_CALL( thiz->GetLevel( thiz, &ret_level ) );

     return v8::Integer::New( ret_level );
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_SetLevel( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int level = (int) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetLevel( thiz, level ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_SetBackgroundMode( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBDisplayLayerBackgroundMode mode = (DFBDisplayLayerBackgroundMode) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetBackgroundMode( thiz, mode ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_SetBackgroundImage( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBSurface *surface = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBSurface );

     V8_DIRECTFB_CALL( thiz->SetBackgroundImage( thiz, surface ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_SetBackgroundColor( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     u8 r = (u8) args[0]->IntegerValue();

     u8 g = (u8) args[1]->IntegerValue();

     u8 b = (u8) args[2]->IntegerValue();

     u8 a = (u8) args[3]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetBackgroundColor( thiz, r, g, b, a ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_GetColorAdjustment( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBColorAdjustment ret_adj;

     V8_DIRECTFB_CALL( thiz->GetColorAdjustment( thiz, &ret_adj ) );

     return DFBColorAdjustment_construct( &ret_adj );
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_SetColorAdjustment( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBColorAdjustment *_adj = NULL;
     DFBColorAdjustment adj;
     if (args[0]->IsObject()) {
          DFBColorAdjustment_read( &adj, args[0] );
          _adj = &adj;
     }

     V8_DIRECTFB_CALL( thiz->SetColorAdjustment( thiz, _adj ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_CreateWindow( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBWindowDescription *_desc = NULL;
     DFBWindowDescription desc;
     if (args[0]->IsObject()) {
          DFBWindowDescription_read( &desc, args[0] );
          _desc = &desc;
     }

     IDirectFBWindow *ret_interface;

     V8_DIRECTFB_CALL( thiz->CreateWindow( thiz, _desc, &ret_interface ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBWindow_template();

     return Construct( templ, ret_interface );
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_GetWindow( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBWindowID window_id = (DFBWindowID) args[0]->IntegerValue();

     IDirectFBWindow *ret_interface;

     V8_DIRECTFB_CALL( thiz->GetWindow( thiz, window_id, &ret_interface ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBWindow_template();

     return Construct( templ, ret_interface );
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_EnableCursor( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int enable = (int) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->EnableCursor( thiz, enable ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_GetCursorPosition( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int ret_x;

     int ret_y;

     V8_DIRECTFB_CALL( thiz->GetCursorPosition( thiz, &ret_x, &ret_y ) );
     #warning unimplemented (second output)

     return v8::Integer::New( ret_x );
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_WarpCursor( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int x = (int) args[0]->IntegerValue();

     int y = (int) args[1]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->WarpCursor( thiz, x, y ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_SetCursorAcceleration( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int numerator = (int) args[0]->IntegerValue();

     int denominator = (int) args[1]->IntegerValue();

     int threshold = (int) args[2]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetCursorAcceleration( thiz, numerator, denominator, threshold ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_SetCursorShape( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBSurface *shape = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBSurface );

     int hot_x = (int) args[1]->IntegerValue();

     int hot_y = (int) args[2]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetCursorShape( thiz, shape, hot_x, hot_y ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_SetCursorOpacity( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     u8 opacity = (u8) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetCursorOpacity( thiz, opacity ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_WaitForSync( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->WaitForSync( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_SwitchContext( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBBoolean exclusive = (DFBBoolean) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SwitchContext( thiz, exclusive ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDisplayLayer_SetRotation( const v8::Arguments& args )
{
     IDirectFBDisplayLayer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDisplayLayer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int rotation = (int) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetRotation( thiz, rotation ) );

     return v8::Undefined();
}

/**********************************************************************************************************************/

v8::Handle<v8::ObjectTemplate>
IDirectFBDisplayLayer_template()
{
     if (m_IDirectFBDisplayLayer.IsEmpty()) {
          v8::HandleScope handle_scope;
          v8::Handle<v8::ObjectTemplate> templ;

          templ = v8::ObjectTemplate::New();

          templ->SetInternalFieldCount( 1 );

          templ->Set( v8::String::NewSymbol("Release"), v8::FunctionTemplate::New(IAny_release) );
          templ->Set( v8::String::NewSymbol("GetID"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_GetID) );
          templ->Set( v8::String::NewSymbol("GetDescription"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_GetDescription) );
          templ->Set( v8::String::NewSymbol("GetSourceDescriptions"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_GetSourceDescriptions) );
          templ->Set( v8::String::NewSymbol("GetCurrentOutputField"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_GetCurrentOutputField) );
          templ->Set( v8::String::NewSymbol("GetSurface"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_GetSurface) );
          templ->Set( v8::String::NewSymbol("GetScreen"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_GetScreen) );
          templ->Set( v8::String::NewSymbol("SetCooperativeLevel"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_SetCooperativeLevel) );
          templ->Set( v8::String::NewSymbol("GetConfiguration"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_GetConfiguration) );
          templ->Set( v8::String::NewSymbol("TestConfiguration"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_TestConfiguration) );
          templ->Set( v8::String::NewSymbol("SetConfiguration"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_SetConfiguration) );
          templ->Set( v8::String::NewSymbol("SetScreenLocation"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_SetScreenLocation) );
          templ->Set( v8::String::NewSymbol("SetScreenPosition"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_SetScreenPosition) );
          templ->Set( v8::String::NewSymbol("SetScreenRectangle"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_SetScreenRectangle) );
          templ->Set( v8::String::NewSymbol("SetOpacity"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_SetOpacity) );
          templ->Set( v8::String::NewSymbol("SetSourceRectangle"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_SetSourceRectangle) );
          templ->Set( v8::String::NewSymbol("SetFieldParity"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_SetFieldParity) );
          templ->Set( v8::String::NewSymbol("SetClipRegions"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_SetClipRegions) );
          templ->Set( v8::String::NewSymbol("SetSrcColorKey"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_SetSrcColorKey) );
          templ->Set( v8::String::NewSymbol("SetDstColorKey"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_SetDstColorKey) );
          templ->Set( v8::String::NewSymbol("GetLevel"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_GetLevel) );
          templ->Set( v8::String::NewSymbol("SetLevel"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_SetLevel) );
          templ->Set( v8::String::NewSymbol("SetBackgroundMode"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_SetBackgroundMode) );
          templ->Set( v8::String::NewSymbol("SetBackgroundImage"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_SetBackgroundImage) );
          templ->Set( v8::String::NewSymbol("SetBackgroundColor"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_SetBackgroundColor) );
          templ->Set( v8::String::NewSymbol("GetColorAdjustment"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_GetColorAdjustment) );
          templ->Set( v8::String::NewSymbol("SetColorAdjustment"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_SetColorAdjustment) );
          templ->Set( v8::String::NewSymbol("CreateWindow"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_CreateWindow) );
          templ->Set( v8::String::NewSymbol("GetWindow"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_GetWindow) );
          templ->Set( v8::String::NewSymbol("EnableCursor"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_EnableCursor) );
          templ->Set( v8::String::NewSymbol("GetCursorPosition"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_GetCursorPosition) );
          templ->Set( v8::String::NewSymbol("WarpCursor"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_WarpCursor) );
          templ->Set( v8::String::NewSymbol("SetCursorAcceleration"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_SetCursorAcceleration) );
          templ->Set( v8::String::NewSymbol("SetCursorShape"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_SetCursorShape) );
          templ->Set( v8::String::NewSymbol("SetCursorOpacity"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_SetCursorOpacity) );
          templ->Set( v8::String::NewSymbol("WaitForSync"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_WaitForSync) );
          templ->Set( v8::String::NewSymbol("SwitchContext"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_SwitchContext) );
          templ->Set( v8::String::NewSymbol("SetRotation"), v8::FunctionTemplate::New(IDirectFBDisplayLayer_SetRotation) );

          m_IDirectFBDisplayLayer = v8::Persistent<v8::ObjectTemplate>::New( handle_scope.Close( templ ) );
     }

     return m_IDirectFBDisplayLayer;
}

}
