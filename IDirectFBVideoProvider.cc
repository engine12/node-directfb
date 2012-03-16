#include "common.h"

#include "templates.h"

namespace DirectFB {

static v8::Persistent<v8::ObjectTemplate>  m_IDirectFBVideoProvider;

/**********************************************************************************************************************/

static v8::Handle<v8::Value>
IDirectFBVideoProvider_GetCapabilities( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBVideoProviderCapabilities ret_caps;

     V8_DIRECTFB_CALL( thiz->GetCapabilities( thiz, &ret_caps ) );

     return v8::Integer::New( ret_caps );
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_GetSurfaceDescription( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBSurfaceDescription ret_dsc;

     V8_DIRECTFB_CALL( thiz->GetSurfaceDescription( thiz, &ret_dsc ) );

     return DFBSurfaceDescription_construct( &ret_dsc );
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_GetStreamDescription( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBStreamDescription ret_dsc;

     V8_DIRECTFB_CALL( thiz->GetStreamDescription( thiz, &ret_dsc ) );

     return DFBStreamDescription_construct( &ret_dsc );
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_PlayTo( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBSurface *destination = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBSurface );

     DFBRectangle *_destination_rect = NULL;
     DFBRectangle destination_rect;
     if (args[1]->IsObject()) {
          DFBRectangle_read( &destination_rect, args[1] );
          _destination_rect = &destination_rect;
     }

     DVFrameCallback callback = (DVFrameCallback) args[2]->IntegerValue();

     void *ctx;
     #warning unimplemented (context pointer)
     D_UNIMPLEMENTED();

     V8_DIRECTFB_CALL( thiz->PlayTo( thiz, destination, _destination_rect, callback, ctx ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_Stop( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->Stop( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_GetStatus( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBVideoProviderStatus ret_status;

     V8_DIRECTFB_CALL( thiz->GetStatus( thiz, &ret_status ) );

     return v8::Integer::New( ret_status );
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_SeekTo( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     double seconds = (double) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SeekTo( thiz, seconds ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_GetPos( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     double ret_seconds;

     V8_DIRECTFB_CALL( thiz->GetPos( thiz, &ret_seconds ) );

     return v8::Integer::New( ret_seconds );
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_GetLength( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     double ret_seconds;

     V8_DIRECTFB_CALL( thiz->GetLength( thiz, &ret_seconds ) );

     return v8::Integer::New( ret_seconds );
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_GetColorAdjustment( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBColorAdjustment ret_adj;

     V8_DIRECTFB_CALL( thiz->GetColorAdjustment( thiz, &ret_adj ) );

     return DFBColorAdjustment_construct( &ret_adj );
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_SetColorAdjustment( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

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
IDirectFBVideoProvider_SendEvent( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBEvent *_event = NULL;
     DFBEvent event;
     if (args[0]->IsObject()) {
          DFBEvent_read( &event, args[0] );
          _event = &event;
     }

     V8_DIRECTFB_CALL( thiz->SendEvent( thiz, _event ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_SetPlaybackFlags( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBVideoProviderPlaybackFlags flags = (DFBVideoProviderPlaybackFlags) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetPlaybackFlags( thiz, flags ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_SetSpeed( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     double multiplier = (double) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetSpeed( thiz, multiplier ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_GetSpeed( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     double ret_multiplier;

     V8_DIRECTFB_CALL( thiz->GetSpeed( thiz, &ret_multiplier ) );

     return v8::Integer::New( ret_multiplier );
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_SetVolume( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     float level = (float) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetVolume( thiz, level ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_GetVolume( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     float ret_level;

     V8_DIRECTFB_CALL( thiz->GetVolume( thiz, &ret_level ) );

     return v8::Integer::New( ret_level );
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_SetAudioOutputs( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBVideoProviderAudioUnits audioUnits;

     V8_DIRECTFB_CALL( thiz->SetAudioOutputs( thiz, &audioUnits ) );

     return v8::Integer::New( audioUnits );
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_GetAudioOutputs( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBVideoProviderAudioUnits audioUnits;

     V8_DIRECTFB_CALL( thiz->GetAudioOutputs( thiz, &audioUnits ) );

     return v8::Integer::New( audioUnits );
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_SetAudioDelay( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     long delay = (long) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetAudioDelay( thiz, delay ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_CreateEventBuffer( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBEventBuffer *ret_buffer;

     V8_DIRECTFB_CALL( thiz->CreateEventBuffer( thiz, &ret_buffer ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBEventBuffer_template();

     return Construct( templ, ret_buffer );
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_AttachEventBuffer( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBEventBuffer *buffer = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBEventBuffer );

     V8_DIRECTFB_CALL( thiz->AttachEventBuffer( thiz, buffer ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_EnableEvents( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBVideoProviderEventType mask = (DFBVideoProviderEventType) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->EnableEvents( thiz, mask ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_DisableEvents( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBVideoProviderEventType mask = (DFBVideoProviderEventType) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->DisableEvents( thiz, mask ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_DetachEventBuffer( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBEventBuffer *buffer = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBEventBuffer );

     V8_DIRECTFB_CALL( thiz->DetachEventBuffer( thiz, buffer ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_GetBufferOccupancy( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBBufferOccupancy ret_occ;

     V8_DIRECTFB_CALL( thiz->GetBufferOccupancy( thiz, &ret_occ ) );

     return DFBBufferOccupancy_construct( &ret_occ );
}

static v8::Handle<v8::Value>
IDirectFBVideoProvider_GetBufferThresholds( const v8::Arguments& args )
{
     IDirectFBVideoProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBVideoProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBBufferThresholds ret_thresh;

     V8_DIRECTFB_CALL( thiz->GetBufferThresholds( thiz, &ret_thresh ) );

     return DFBBufferThresholds_construct( &ret_thresh );
}

/**********************************************************************************************************************/

v8::Handle<v8::ObjectTemplate>
IDirectFBVideoProvider_template()
{
     if (m_IDirectFBVideoProvider.IsEmpty()) {
          v8::HandleScope handle_scope;
          v8::Handle<v8::ObjectTemplate> templ;

          templ = v8::ObjectTemplate::New();

          templ->SetInternalFieldCount( 1 );

          templ->Set( v8::String::NewSymbol("Release"), v8::FunctionTemplate::New(IAny_release) );
          templ->Set( v8::String::NewSymbol("GetCapabilities"), v8::FunctionTemplate::New(IDirectFBVideoProvider_GetCapabilities) );
          templ->Set( v8::String::NewSymbol("GetSurfaceDescription"), v8::FunctionTemplate::New(IDirectFBVideoProvider_GetSurfaceDescription) );
          templ->Set( v8::String::NewSymbol("GetStreamDescription"), v8::FunctionTemplate::New(IDirectFBVideoProvider_GetStreamDescription) );
          templ->Set( v8::String::NewSymbol("PlayTo"), v8::FunctionTemplate::New(IDirectFBVideoProvider_PlayTo) );
          templ->Set( v8::String::NewSymbol("Stop"), v8::FunctionTemplate::New(IDirectFBVideoProvider_Stop) );
          templ->Set( v8::String::NewSymbol("GetStatus"), v8::FunctionTemplate::New(IDirectFBVideoProvider_GetStatus) );
          templ->Set( v8::String::NewSymbol("SeekTo"), v8::FunctionTemplate::New(IDirectFBVideoProvider_SeekTo) );
          templ->Set( v8::String::NewSymbol("GetPos"), v8::FunctionTemplate::New(IDirectFBVideoProvider_GetPos) );
          templ->Set( v8::String::NewSymbol("GetLength"), v8::FunctionTemplate::New(IDirectFBVideoProvider_GetLength) );
          templ->Set( v8::String::NewSymbol("GetColorAdjustment"), v8::FunctionTemplate::New(IDirectFBVideoProvider_GetColorAdjustment) );
          templ->Set( v8::String::NewSymbol("SetColorAdjustment"), v8::FunctionTemplate::New(IDirectFBVideoProvider_SetColorAdjustment) );
          templ->Set( v8::String::NewSymbol("SendEvent"), v8::FunctionTemplate::New(IDirectFBVideoProvider_SendEvent) );
          templ->Set( v8::String::NewSymbol("SetPlaybackFlags"), v8::FunctionTemplate::New(IDirectFBVideoProvider_SetPlaybackFlags) );
          templ->Set( v8::String::NewSymbol("SetSpeed"), v8::FunctionTemplate::New(IDirectFBVideoProvider_SetSpeed) );
          templ->Set( v8::String::NewSymbol("GetSpeed"), v8::FunctionTemplate::New(IDirectFBVideoProvider_GetSpeed) );
          templ->Set( v8::String::NewSymbol("SetVolume"), v8::FunctionTemplate::New(IDirectFBVideoProvider_SetVolume) );
          templ->Set( v8::String::NewSymbol("GetVolume"), v8::FunctionTemplate::New(IDirectFBVideoProvider_GetVolume) );
          templ->Set( v8::String::NewSymbol("SetAudioOutputs"), v8::FunctionTemplate::New(IDirectFBVideoProvider_SetAudioOutputs) );
          templ->Set( v8::String::NewSymbol("GetAudioOutputs"), v8::FunctionTemplate::New(IDirectFBVideoProvider_GetAudioOutputs) );
          templ->Set( v8::String::NewSymbol("SetAudioDelay"), v8::FunctionTemplate::New(IDirectFBVideoProvider_SetAudioDelay) );
          templ->Set( v8::String::NewSymbol("CreateEventBuffer"), v8::FunctionTemplate::New(IDirectFBVideoProvider_CreateEventBuffer) );
          templ->Set( v8::String::NewSymbol("AttachEventBuffer"), v8::FunctionTemplate::New(IDirectFBVideoProvider_AttachEventBuffer) );
          templ->Set( v8::String::NewSymbol("EnableEvents"), v8::FunctionTemplate::New(IDirectFBVideoProvider_EnableEvents) );
          templ->Set( v8::String::NewSymbol("DisableEvents"), v8::FunctionTemplate::New(IDirectFBVideoProvider_DisableEvents) );
          templ->Set( v8::String::NewSymbol("DetachEventBuffer"), v8::FunctionTemplate::New(IDirectFBVideoProvider_DetachEventBuffer) );
          templ->Set( v8::String::NewSymbol("GetBufferOccupancy"), v8::FunctionTemplate::New(IDirectFBVideoProvider_GetBufferOccupancy) );
          templ->Set( v8::String::NewSymbol("GetBufferThresholds"), v8::FunctionTemplate::New(IDirectFBVideoProvider_GetBufferThresholds) );

          m_IDirectFBVideoProvider = v8::Persistent<v8::ObjectTemplate>::New( handle_scope.Close( templ ) );
     }

     return m_IDirectFBVideoProvider;
}

}
