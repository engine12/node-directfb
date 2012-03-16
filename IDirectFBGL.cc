#include "common.h"

#include "templates.h"

namespace DirectFB {

static v8::Persistent<v8::ObjectTemplate>  m_IDirectFBGL;

/**********************************************************************************************************************/

static v8::Handle<v8::Value>
IDirectFBGL_Lock( const v8::Arguments& args )
{
     IDirectFBGL *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBGL );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->Lock( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBGL_Unlock( const v8::Arguments& args )
{
     IDirectFBGL *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBGL );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->Unlock( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBGL_GetAttributes( const v8::Arguments& args )
{
     IDirectFBGL *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBGL );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBGLAttributes attributes;

     V8_DIRECTFB_CALL( thiz->GetAttributes( thiz, &attributes ) );

     return DFBGLAttributes_construct( &attributes );
}

static v8::Handle<v8::Value>
IDirectFBGL_GetProcAddress( const v8::Arguments& args )
{
     IDirectFBGL *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBGL );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     const char *name = NULL;
     v8::String::Utf8Value utf8_name(args[0]);
     name = *utf8_name;

     void *ret_address;
     #warning unimplemented (return pointer)
     D_UNIMPLEMENTED();

     V8_DIRECTFB_CALL( thiz->GetProcAddress( thiz, name, &ret_address ) );

     return v8::Undefined();
}

/**********************************************************************************************************************/

v8::Handle<v8::ObjectTemplate>
IDirectFBGL_template()
{
     if (m_IDirectFBGL.IsEmpty()) {
          v8::HandleScope handle_scope;
          v8::Handle<v8::ObjectTemplate> templ;

          templ = v8::ObjectTemplate::New();

          templ->SetInternalFieldCount( 1 );

          templ->Set( v8::String::NewSymbol("Release"), v8::FunctionTemplate::New(IAny_release) );
          templ->Set( v8::String::NewSymbol("Lock"), v8::FunctionTemplate::New(IDirectFBGL_Lock) );
          templ->Set( v8::String::NewSymbol("Unlock"), v8::FunctionTemplate::New(IDirectFBGL_Unlock) );
          templ->Set( v8::String::NewSymbol("GetAttributes"), v8::FunctionTemplate::New(IDirectFBGL_GetAttributes) );
          templ->Set( v8::String::NewSymbol("GetProcAddress"), v8::FunctionTemplate::New(IDirectFBGL_GetProcAddress) );

          m_IDirectFBGL = v8::Persistent<v8::ObjectTemplate>::New( handle_scope.Close( templ ) );
     }

     return m_IDirectFBGL;
}

}
