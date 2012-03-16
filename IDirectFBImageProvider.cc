#include "common.h"

#include "templates.h"

namespace DirectFB {

static v8::Persistent<v8::ObjectTemplate>  m_IDirectFBImageProvider;

/**********************************************************************************************************************/

static v8::Handle<v8::Value>
IDirectFBImageProvider_GetSurfaceDescription( const v8::Arguments& args )
{
     IDirectFBImageProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBImageProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBSurfaceDescription ret_dsc;

     V8_DIRECTFB_CALL( thiz->GetSurfaceDescription( thiz, &ret_dsc ) );

     return DFBSurfaceDescription_construct( &ret_dsc );
}

static v8::Handle<v8::Value>
IDirectFBImageProvider_GetImageDescription( const v8::Arguments& args )
{
     IDirectFBImageProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBImageProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBImageDescription ret_dsc;

     V8_DIRECTFB_CALL( thiz->GetImageDescription( thiz, &ret_dsc ) );

     return DFBImageDescription_construct( &ret_dsc );
}

static v8::Handle<v8::Value>
IDirectFBImageProvider_RenderTo( const v8::Arguments& args )
{
     IDirectFBImageProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBImageProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBSurface *destination = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBSurface );

     DFBRectangle *_destination_rect = NULL;
     DFBRectangle destination_rect;
     if (args[1]->IsObject()) {
          DFBRectangle_read( &destination_rect, args[1] );
          _destination_rect = &destination_rect;
     }

     V8_DIRECTFB_CALL( thiz->RenderTo( thiz, destination, _destination_rect ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBImageProvider_SetRenderCallback( const v8::Arguments& args )
{
     IDirectFBImageProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBImageProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DIRenderCallback callback = (DIRenderCallback) args[0]->IntegerValue();

     void *callback_data;
     #warning unimplemented (context pointer)
     D_UNIMPLEMENTED();

     V8_DIRECTFB_CALL( thiz->SetRenderCallback( thiz, callback, callback_data ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBImageProvider_WriteBack( const v8::Arguments& args )
{
     IDirectFBImageProvider *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBImageProvider );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBSurface *surface = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBSurface );

     DFBRectangle *_src_rect = NULL;
     DFBRectangle src_rect;
     if (args[1]->IsObject()) {
          DFBRectangle_read( &src_rect, args[1] );
          _src_rect = &src_rect;
     }

     const char *filename = NULL;
     v8::String::Utf8Value utf8_filename(args[2]);
     filename = *utf8_filename;

     V8_DIRECTFB_CALL( thiz->WriteBack( thiz, surface, _src_rect, filename ) );

     return v8::Undefined();
}

/**********************************************************************************************************************/

v8::Handle<v8::ObjectTemplate>
IDirectFBImageProvider_template()
{
     if (m_IDirectFBImageProvider.IsEmpty()) {
          v8::HandleScope handle_scope;
          v8::Handle<v8::ObjectTemplate> templ;

          templ = v8::ObjectTemplate::New();

          templ->SetInternalFieldCount( 1 );

          templ->Set( v8::String::NewSymbol("Release"), v8::FunctionTemplate::New(IAny_release) );
          templ->Set( v8::String::NewSymbol("GetSurfaceDescription"), v8::FunctionTemplate::New(IDirectFBImageProvider_GetSurfaceDescription) );
          templ->Set( v8::String::NewSymbol("GetImageDescription"), v8::FunctionTemplate::New(IDirectFBImageProvider_GetImageDescription) );
          templ->Set( v8::String::NewSymbol("RenderTo"), v8::FunctionTemplate::New(IDirectFBImageProvider_RenderTo) );
          templ->Set( v8::String::NewSymbol("SetRenderCallback"), v8::FunctionTemplate::New(IDirectFBImageProvider_SetRenderCallback) );
          templ->Set( v8::String::NewSymbol("WriteBack"), v8::FunctionTemplate::New(IDirectFBImageProvider_WriteBack) );

          m_IDirectFBImageProvider = v8::Persistent<v8::ObjectTemplate>::New( handle_scope.Close( templ ) );
     }

     return m_IDirectFBImageProvider;
}

}
