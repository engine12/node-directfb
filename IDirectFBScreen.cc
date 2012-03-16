#include "common.h"

#include "templates.h"

namespace DirectFB {

static v8::Persistent<v8::ObjectTemplate>  m_IDirectFBScreen;

/**********************************************************************************************************************/

static v8::Handle<v8::Value>
IDirectFBScreen_GetID( const v8::Arguments& args )
{
     IDirectFBScreen *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBScreen );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBScreenID ret_screen_id;

     V8_DIRECTFB_CALL( thiz->GetID( thiz, &ret_screen_id ) );

     return v8::Integer::New( ret_screen_id );
}

static v8::Handle<v8::Value>
IDirectFBScreen_GetDescription( const v8::Arguments& args )
{
     IDirectFBScreen *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBScreen );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBScreenDescription ret_desc;

     V8_DIRECTFB_CALL( thiz->GetDescription( thiz, &ret_desc ) );

     return DFBScreenDescription_construct( &ret_desc );
}

static v8::Handle<v8::Value>
IDirectFBScreen_GetSize( const v8::Arguments& args )
{
     IDirectFBScreen *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBScreen );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int ret_width;

     int ret_height;

     V8_DIRECTFB_CALL( thiz->GetSize( thiz, &ret_width, &ret_height ) );
     #warning unimplemented (second output)

     return v8::Integer::New( ret_width );
}

static v8::Handle<v8::Value>
IDirectFBScreen_EnumDisplayLayers( const v8::Arguments& args )
{
     IDirectFBScreen *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBScreen );

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
IDirectFBScreen_SetPowerMode( const v8::Arguments& args )
{
     IDirectFBScreen *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBScreen );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBScreenPowerMode mode = (DFBScreenPowerMode) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetPowerMode( thiz, mode ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBScreen_WaitForSync( const v8::Arguments& args )
{
     IDirectFBScreen *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBScreen );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->WaitForSync( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBScreen_GetMixerDescriptions( const v8::Arguments& args )
{
     IDirectFBScreen *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBScreen );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBScreenMixerDescription ret_descriptions;

     V8_DIRECTFB_CALL( thiz->GetMixerDescriptions( thiz, &ret_descriptions ) );

     return DFBScreenMixerDescription_construct( &ret_descriptions );
}

static v8::Handle<v8::Value>
IDirectFBScreen_GetMixerConfiguration( const v8::Arguments& args )
{
     IDirectFBScreen *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBScreen );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int mixer = (int) args[0]->IntegerValue();

     DFBScreenMixerConfig ret_config;

     V8_DIRECTFB_CALL( thiz->GetMixerConfiguration( thiz, mixer, &ret_config ) );

     return DFBScreenMixerConfig_construct( &ret_config );
}

static v8::Handle<v8::Value>
IDirectFBScreen_TestMixerConfiguration( const v8::Arguments& args )
{
     IDirectFBScreen *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBScreen );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int mixer = (int) args[0]->IntegerValue();

     DFBScreenMixerConfig *_config = NULL;
     DFBScreenMixerConfig config;
     if (args[1]->IsObject()) {
          DFBScreenMixerConfig_read( &config, args[1] );
          _config = &config;
     }

     DFBScreenMixerConfigFlags ret_failed;

     V8_DIRECTFB_CALL( thiz->TestMixerConfiguration( thiz, mixer, _config, &ret_failed ) );

     return v8::Integer::New( ret_failed );
}

static v8::Handle<v8::Value>
IDirectFBScreen_SetMixerConfiguration( const v8::Arguments& args )
{
     IDirectFBScreen *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBScreen );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int mixer = (int) args[0]->IntegerValue();

     DFBScreenMixerConfig *_config = NULL;
     DFBScreenMixerConfig config;
     if (args[1]->IsObject()) {
          DFBScreenMixerConfig_read( &config, args[1] );
          _config = &config;
     }

     V8_DIRECTFB_CALL( thiz->SetMixerConfiguration( thiz, mixer, _config ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBScreen_GetEncoderDescriptions( const v8::Arguments& args )
{
     IDirectFBScreen *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBScreen );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBScreenEncoderDescription ret_descriptions;

     V8_DIRECTFB_CALL( thiz->GetEncoderDescriptions( thiz, &ret_descriptions ) );

     return DFBScreenEncoderDescription_construct( &ret_descriptions );
}

static v8::Handle<v8::Value>
IDirectFBScreen_GetEncoderConfiguration( const v8::Arguments& args )
{
     IDirectFBScreen *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBScreen );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int encoder = (int) args[0]->IntegerValue();

     DFBScreenEncoderConfig ret_config;

     V8_DIRECTFB_CALL( thiz->GetEncoderConfiguration( thiz, encoder, &ret_config ) );

     return DFBScreenEncoderConfig_construct( &ret_config );
}

static v8::Handle<v8::Value>
IDirectFBScreen_TestEncoderConfiguration( const v8::Arguments& args )
{
     IDirectFBScreen *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBScreen );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int encoder = (int) args[0]->IntegerValue();

     DFBScreenEncoderConfig *_config = NULL;
     DFBScreenEncoderConfig config;
     if (args[1]->IsObject()) {
          DFBScreenEncoderConfig_read( &config, args[1] );
          _config = &config;
     }

     DFBScreenEncoderConfigFlags ret_failed;

     V8_DIRECTFB_CALL( thiz->TestEncoderConfiguration( thiz, encoder, _config, &ret_failed ) );

     return v8::Integer::New( ret_failed );
}

static v8::Handle<v8::Value>
IDirectFBScreen_SetEncoderConfiguration( const v8::Arguments& args )
{
     IDirectFBScreen *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBScreen );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int encoder = (int) args[0]->IntegerValue();

     DFBScreenEncoderConfig *_config = NULL;
     DFBScreenEncoderConfig config;
     if (args[1]->IsObject()) {
          DFBScreenEncoderConfig_read( &config, args[1] );
          _config = &config;
     }

     V8_DIRECTFB_CALL( thiz->SetEncoderConfiguration( thiz, encoder, _config ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBScreen_GetOutputDescriptions( const v8::Arguments& args )
{
     IDirectFBScreen *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBScreen );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBScreenOutputDescription ret_descriptions;

     V8_DIRECTFB_CALL( thiz->GetOutputDescriptions( thiz, &ret_descriptions ) );

     return DFBScreenOutputDescription_construct( &ret_descriptions );
}

static v8::Handle<v8::Value>
IDirectFBScreen_GetOutputConfiguration( const v8::Arguments& args )
{
     IDirectFBScreen *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBScreen );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int output = (int) args[0]->IntegerValue();

     DFBScreenOutputConfig ret_config;

     V8_DIRECTFB_CALL( thiz->GetOutputConfiguration( thiz, output, &ret_config ) );

     return DFBScreenOutputConfig_construct( &ret_config );
}

static v8::Handle<v8::Value>
IDirectFBScreen_TestOutputConfiguration( const v8::Arguments& args )
{
     IDirectFBScreen *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBScreen );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int output = (int) args[0]->IntegerValue();

     DFBScreenOutputConfig *_config = NULL;
     DFBScreenOutputConfig config;
     if (args[1]->IsObject()) {
          DFBScreenOutputConfig_read( &config, args[1] );
          _config = &config;
     }

     DFBScreenOutputConfigFlags ret_failed;

     V8_DIRECTFB_CALL( thiz->TestOutputConfiguration( thiz, output, _config, &ret_failed ) );

     return v8::Integer::New( ret_failed );
}

static v8::Handle<v8::Value>
IDirectFBScreen_SetOutputConfiguration( const v8::Arguments& args )
{
     IDirectFBScreen *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBScreen );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int output = (int) args[0]->IntegerValue();

     DFBScreenOutputConfig *_config = NULL;
     DFBScreenOutputConfig config;
     if (args[1]->IsObject()) {
          DFBScreenOutputConfig_read( &config, args[1] );
          _config = &config;
     }

     V8_DIRECTFB_CALL( thiz->SetOutputConfiguration( thiz, output, _config ) );

     return v8::Undefined();
}

/**********************************************************************************************************************/

v8::Handle<v8::ObjectTemplate>
IDirectFBScreen_template()
{
     if (m_IDirectFBScreen.IsEmpty()) {
          v8::HandleScope handle_scope;
          v8::Handle<v8::ObjectTemplate> templ;

          templ = v8::ObjectTemplate::New();

          templ->SetInternalFieldCount( 1 );

          templ->Set( v8::String::NewSymbol("Release"), v8::FunctionTemplate::New(IAny_release) );
          templ->Set( v8::String::NewSymbol("GetID"), v8::FunctionTemplate::New(IDirectFBScreen_GetID) );
          templ->Set( v8::String::NewSymbol("GetDescription"), v8::FunctionTemplate::New(IDirectFBScreen_GetDescription) );
          templ->Set( v8::String::NewSymbol("GetSize"), v8::FunctionTemplate::New(IDirectFBScreen_GetSize) );
          templ->Set( v8::String::NewSymbol("EnumDisplayLayers"), v8::FunctionTemplate::New(IDirectFBScreen_EnumDisplayLayers) );
          templ->Set( v8::String::NewSymbol("SetPowerMode"), v8::FunctionTemplate::New(IDirectFBScreen_SetPowerMode) );
          templ->Set( v8::String::NewSymbol("WaitForSync"), v8::FunctionTemplate::New(IDirectFBScreen_WaitForSync) );
          templ->Set( v8::String::NewSymbol("GetMixerDescriptions"), v8::FunctionTemplate::New(IDirectFBScreen_GetMixerDescriptions) );
          templ->Set( v8::String::NewSymbol("GetMixerConfiguration"), v8::FunctionTemplate::New(IDirectFBScreen_GetMixerConfiguration) );
          templ->Set( v8::String::NewSymbol("TestMixerConfiguration"), v8::FunctionTemplate::New(IDirectFBScreen_TestMixerConfiguration) );
          templ->Set( v8::String::NewSymbol("SetMixerConfiguration"), v8::FunctionTemplate::New(IDirectFBScreen_SetMixerConfiguration) );
          templ->Set( v8::String::NewSymbol("GetEncoderDescriptions"), v8::FunctionTemplate::New(IDirectFBScreen_GetEncoderDescriptions) );
          templ->Set( v8::String::NewSymbol("GetEncoderConfiguration"), v8::FunctionTemplate::New(IDirectFBScreen_GetEncoderConfiguration) );
          templ->Set( v8::String::NewSymbol("TestEncoderConfiguration"), v8::FunctionTemplate::New(IDirectFBScreen_TestEncoderConfiguration) );
          templ->Set( v8::String::NewSymbol("SetEncoderConfiguration"), v8::FunctionTemplate::New(IDirectFBScreen_SetEncoderConfiguration) );
          templ->Set( v8::String::NewSymbol("GetOutputDescriptions"), v8::FunctionTemplate::New(IDirectFBScreen_GetOutputDescriptions) );
          templ->Set( v8::String::NewSymbol("GetOutputConfiguration"), v8::FunctionTemplate::New(IDirectFBScreen_GetOutputConfiguration) );
          templ->Set( v8::String::NewSymbol("TestOutputConfiguration"), v8::FunctionTemplate::New(IDirectFBScreen_TestOutputConfiguration) );
          templ->Set( v8::String::NewSymbol("SetOutputConfiguration"), v8::FunctionTemplate::New(IDirectFBScreen_SetOutputConfiguration) );

          m_IDirectFBScreen = v8::Persistent<v8::ObjectTemplate>::New( handle_scope.Close( templ ) );
     }

     return m_IDirectFBScreen;
}

}
