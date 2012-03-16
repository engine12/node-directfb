#include "common.h"

#include "templates.h"

namespace DirectFB {

static v8::Persistent<v8::ObjectTemplate>  m_IDirectFBDataBuffer;

/**********************************************************************************************************************/

static v8::Handle<v8::Value>
IDirectFBDataBuffer_Flush( const v8::Arguments& args )
{
     IDirectFBDataBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDataBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->Flush( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDataBuffer_Finish( const v8::Arguments& args )
{
     IDirectFBDataBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDataBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->Finish( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDataBuffer_SeekTo( const v8::Arguments& args )
{
     IDirectFBDataBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDataBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     unsigned int offset = (unsigned int) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SeekTo( thiz, offset ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDataBuffer_GetPosition( const v8::Arguments& args )
{
     IDirectFBDataBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDataBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     unsigned int ret_offset;

     V8_DIRECTFB_CALL( thiz->GetPosition( thiz, &ret_offset ) );

     return v8::Integer::New( ret_offset );
}

static v8::Handle<v8::Value>
IDirectFBDataBuffer_GetLength( const v8::Arguments& args )
{
     IDirectFBDataBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDataBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     unsigned int ret_length;

     V8_DIRECTFB_CALL( thiz->GetLength( thiz, &ret_length ) );

     return v8::Integer::New( ret_length );
}

static v8::Handle<v8::Value>
IDirectFBDataBuffer_WaitForData( const v8::Arguments& args )
{
     IDirectFBDataBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDataBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     unsigned int length = (unsigned int) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->WaitForData( thiz, length ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDataBuffer_WaitForDataWithTimeout( const v8::Arguments& args )
{
     IDirectFBDataBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDataBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     unsigned int length = (unsigned int) args[0]->IntegerValue();

     unsigned int seconds = (unsigned int) args[1]->IntegerValue();

     unsigned int milli_seconds = (unsigned int) args[2]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->WaitForDataWithTimeout( thiz, length, seconds, milli_seconds ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDataBuffer_GetData( const v8::Arguments& args )
{
     IDirectFBDataBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDataBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     unsigned int length = (unsigned int) args[0]->IntegerValue();

     void *ret_data;
     #warning unimplemented (context pointer)
     D_UNIMPLEMENTED();

     unsigned int ret_read;

     V8_DIRECTFB_CALL( thiz->GetData( thiz, length, ret_data, &ret_read ) );

     return v8::Integer::New( ret_read );
}

static v8::Handle<v8::Value>
IDirectFBDataBuffer_PeekData( const v8::Arguments& args )
{
     IDirectFBDataBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDataBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     unsigned int length = (unsigned int) args[0]->IntegerValue();

     int offset = (int) args[1]->IntegerValue();

     void *ret_data;
     #warning unimplemented (context pointer)
     D_UNIMPLEMENTED();

     unsigned int ret_read;

     V8_DIRECTFB_CALL( thiz->PeekData( thiz, length, offset, ret_data, &ret_read ) );

     return v8::Integer::New( ret_read );
}

static v8::Handle<v8::Value>
IDirectFBDataBuffer_HasData( const v8::Arguments& args )
{
     IDirectFBDataBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDataBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->HasData( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDataBuffer_PutData( const v8::Arguments& args )
{
     IDirectFBDataBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDataBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     void *data;
     #warning unimplemented (buffer input)
     D_UNIMPLEMENTED();

     unsigned int length = (unsigned int) args[1]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->PutData( thiz, data, length ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBDataBuffer_CreateImageProvider( const v8::Arguments& args )
{
     IDirectFBDataBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDataBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBImageProvider *interface;

     V8_DIRECTFB_CALL( thiz->CreateImageProvider( thiz, &interface ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBImageProvider_template();

     return Construct( templ, interface );
}

static v8::Handle<v8::Value>
IDirectFBDataBuffer_CreateVideoProvider( const v8::Arguments& args )
{
     IDirectFBDataBuffer *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBDataBuffer );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBVideoProvider *interface;

     V8_DIRECTFB_CALL( thiz->CreateVideoProvider( thiz, &interface ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBVideoProvider_template();

     return Construct( templ, interface );
}

/**********************************************************************************************************************/

v8::Handle<v8::ObjectTemplate>
IDirectFBDataBuffer_template()
{
     if (m_IDirectFBDataBuffer.IsEmpty()) {
          v8::HandleScope handle_scope;
          v8::Handle<v8::ObjectTemplate> templ;

          templ = v8::ObjectTemplate::New();

          templ->SetInternalFieldCount( 1 );

          templ->Set( v8::String::NewSymbol("Release"), v8::FunctionTemplate::New(IAny_release) );
          templ->Set( v8::String::NewSymbol("Flush"), v8::FunctionTemplate::New(IDirectFBDataBuffer_Flush) );
          templ->Set( v8::String::NewSymbol("Finish"), v8::FunctionTemplate::New(IDirectFBDataBuffer_Finish) );
          templ->Set( v8::String::NewSymbol("SeekTo"), v8::FunctionTemplate::New(IDirectFBDataBuffer_SeekTo) );
          templ->Set( v8::String::NewSymbol("GetPosition"), v8::FunctionTemplate::New(IDirectFBDataBuffer_GetPosition) );
          templ->Set( v8::String::NewSymbol("GetLength"), v8::FunctionTemplate::New(IDirectFBDataBuffer_GetLength) );
          templ->Set( v8::String::NewSymbol("WaitForData"), v8::FunctionTemplate::New(IDirectFBDataBuffer_WaitForData) );
          templ->Set( v8::String::NewSymbol("WaitForDataWithTimeout"), v8::FunctionTemplate::New(IDirectFBDataBuffer_WaitForDataWithTimeout) );
          templ->Set( v8::String::NewSymbol("GetData"), v8::FunctionTemplate::New(IDirectFBDataBuffer_GetData) );
          templ->Set( v8::String::NewSymbol("PeekData"), v8::FunctionTemplate::New(IDirectFBDataBuffer_PeekData) );
          templ->Set( v8::String::NewSymbol("HasData"), v8::FunctionTemplate::New(IDirectFBDataBuffer_HasData) );
          templ->Set( v8::String::NewSymbol("PutData"), v8::FunctionTemplate::New(IDirectFBDataBuffer_PutData) );
          templ->Set( v8::String::NewSymbol("CreateImageProvider"), v8::FunctionTemplate::New(IDirectFBDataBuffer_CreateImageProvider) );
          templ->Set( v8::String::NewSymbol("CreateVideoProvider"), v8::FunctionTemplate::New(IDirectFBDataBuffer_CreateVideoProvider) );

          m_IDirectFBDataBuffer = v8::Persistent<v8::ObjectTemplate>::New( handle_scope.Close( templ ) );
     }

     return m_IDirectFBDataBuffer;
}

}
