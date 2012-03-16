#include "common.h"

#include "templates.h"

namespace DirectFB {

static v8::Persistent<v8::ObjectTemplate>  m_IDirectFBEventBuffer;

/**********************************************************************************************************************/

static v8::Handle<v8::Value>
IDirectFBEventBuffer_Reset( const v8::Arguments& args )
{
     IDirectFBEventBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBEventBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->Reset( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBEventBuffer_WaitForEvent( const v8::Arguments& args )
{
     IDirectFBEventBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBEventBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->WaitForEvent( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBEventBuffer_WaitForEventWithTimeout( const v8::Arguments& args )
{
     IDirectFBEventBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBEventBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     unsigned int seconds = (unsigned int) args[0]->IntegerValue();

     unsigned int milli_seconds = (unsigned int) args[1]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->WaitForEventWithTimeout( thiz, seconds, milli_seconds ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBEventBuffer_GetEvent( const v8::Arguments& args )
{
     IDirectFBEventBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBEventBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBEvent ret_event;

     V8_DIRECTFB_CALL( thiz->GetEvent( thiz, &ret_event ) );

     return DFBEvent_construct( &ret_event );
}

static v8::Handle<v8::Value>
IDirectFBEventBuffer_PeekEvent( const v8::Arguments& args )
{
     IDirectFBEventBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBEventBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBEvent ret_event;

     V8_DIRECTFB_CALL( thiz->PeekEvent( thiz, &ret_event ) );

     return DFBEvent_construct( &ret_event );
}

static v8::Handle<v8::Value>
IDirectFBEventBuffer_HasEvent( const v8::Arguments& args )
{
     IDirectFBEventBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBEventBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->HasEvent( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBEventBuffer_PostEvent( const v8::Arguments& args )
{
     IDirectFBEventBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBEventBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBEvent *_event = NULL;
     DFBEvent event;
     if (args[0]->IsObject()) {
          DFBEvent_read( &event, args[0] );
          _event = &event;
     }

     V8_DIRECTFB_CALL( thiz->PostEvent( thiz, _event ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBEventBuffer_WakeUp( const v8::Arguments& args )
{
     IDirectFBEventBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBEventBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->WakeUp( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBEventBuffer_CreateFileDescriptor( const v8::Arguments& args )
{
     IDirectFBEventBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBEventBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int ret_fd;

     V8_DIRECTFB_CALL( thiz->CreateFileDescriptor( thiz, &ret_fd ) );

     return v8::Integer::New( ret_fd );
}

static v8::Handle<v8::Value>
IDirectFBEventBuffer_EnableStatistics( const v8::Arguments& args )
{
     IDirectFBEventBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBEventBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBBoolean enable = (DFBBoolean) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->EnableStatistics( thiz, enable ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBEventBuffer_GetStatistics( const v8::Arguments& args )
{
     IDirectFBEventBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBEventBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBEventBufferStats ret_stats;

     V8_DIRECTFB_CALL( thiz->GetStatistics( thiz, &ret_stats ) );

     return DFBEventBufferStats_construct( &ret_stats );
}

/**********************************************************************************************************************/

v8::Handle<v8::ObjectTemplate>
IDirectFBEventBuffer_template()
{
     if (m_IDirectFBEventBuffer.IsEmpty()) {
          v8::HandleScope handle_scope;
          v8::Handle<v8::ObjectTemplate> templ;

          templ = v8::ObjectTemplate::New();

          templ->SetInternalFieldCount( 1 );

          templ->Set( v8::String::NewSymbol("Release"), v8::FunctionTemplate::New(IAny_release) );
          templ->Set( v8::String::NewSymbol("Reset"), v8::FunctionTemplate::New(IDirectFBEventBuffer_Reset) );
          templ->Set( v8::String::NewSymbol("WaitForEvent"), v8::FunctionTemplate::New(IDirectFBEventBuffer_WaitForEvent) );
          templ->Set( v8::String::NewSymbol("WaitForEventWithTimeout"), v8::FunctionTemplate::New(IDirectFBEventBuffer_WaitForEventWithTimeout) );
          templ->Set( v8::String::NewSymbol("GetEvent"), v8::FunctionTemplate::New(IDirectFBEventBuffer_GetEvent) );
          templ->Set( v8::String::NewSymbol("PeekEvent"), v8::FunctionTemplate::New(IDirectFBEventBuffer_PeekEvent) );
          templ->Set( v8::String::NewSymbol("HasEvent"), v8::FunctionTemplate::New(IDirectFBEventBuffer_HasEvent) );
          templ->Set( v8::String::NewSymbol("PostEvent"), v8::FunctionTemplate::New(IDirectFBEventBuffer_PostEvent) );
          templ->Set( v8::String::NewSymbol("WakeUp"), v8::FunctionTemplate::New(IDirectFBEventBuffer_WakeUp) );
          templ->Set( v8::String::NewSymbol("CreateFileDescriptor"), v8::FunctionTemplate::New(IDirectFBEventBuffer_CreateFileDescriptor) );
          templ->Set( v8::String::NewSymbol("EnableStatistics"), v8::FunctionTemplate::New(IDirectFBEventBuffer_EnableStatistics) );
          templ->Set( v8::String::NewSymbol("GetStatistics"), v8::FunctionTemplate::New(IDirectFBEventBuffer_GetStatistics) );

          m_IDirectFBEventBuffer = v8::Persistent<v8::ObjectTemplate>::New( handle_scope.Close( templ ) );
     }

     return m_IDirectFBEventBuffer;
}

}
