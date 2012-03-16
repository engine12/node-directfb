#include "common.h"

#include "templates.h"

namespace DirectFB {

static v8::Persistent<v8::ObjectTemplate>  m_IDirectFBFont;

/**********************************************************************************************************************/

static v8::Handle<v8::Value>
IDirectFBFont_GetAscender( const v8::Arguments& args )
{
     IDirectFBFont *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBFont );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int ret_ascender;

     V8_DIRECTFB_CALL( thiz->GetAscender( thiz, &ret_ascender ) );

     return v8::Integer::New( ret_ascender );
}

static v8::Handle<v8::Value>
IDirectFBFont_GetDescender( const v8::Arguments& args )
{
     IDirectFBFont *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBFont );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int ret_descender;

     V8_DIRECTFB_CALL( thiz->GetDescender( thiz, &ret_descender ) );

     return v8::Integer::New( ret_descender );
}

static v8::Handle<v8::Value>
IDirectFBFont_GetHeight( const v8::Arguments& args )
{
     IDirectFBFont *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBFont );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int ret_height;

     V8_DIRECTFB_CALL( thiz->GetHeight( thiz, &ret_height ) );

     return v8::Integer::New( ret_height );
}

static v8::Handle<v8::Value>
IDirectFBFont_GetMaxAdvance( const v8::Arguments& args )
{
     IDirectFBFont *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBFont );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int ret_maxadvance;

     V8_DIRECTFB_CALL( thiz->GetMaxAdvance( thiz, &ret_maxadvance ) );

     return v8::Integer::New( ret_maxadvance );
}

static v8::Handle<v8::Value>
IDirectFBFont_GetKerning( const v8::Arguments& args )
{
     IDirectFBFont *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBFont );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     unsigned int prev = (unsigned int) args[0]->IntegerValue();

     unsigned int current = (unsigned int) args[1]->IntegerValue();

     int ret_kern_x;

     int ret_kern_y;

     V8_DIRECTFB_CALL( thiz->GetKerning( thiz, prev, current, &ret_kern_x, &ret_kern_y ) );
     #warning unimplemented (second output)

     return v8::Integer::New( ret_kern_x );
}

static v8::Handle<v8::Value>
IDirectFBFont_GetStringWidth( const v8::Arguments& args )
{
     IDirectFBFont *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBFont );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     const char *text = NULL;
     v8::String::Utf8Value utf8_text(args[0]);
     text = *utf8_text;

     int bytes = (int) args[1]->IntegerValue();

     int ret_width;

     V8_DIRECTFB_CALL( thiz->GetStringWidth( thiz, text, bytes, &ret_width ) );

     return v8::Integer::New( ret_width );
}

static v8::Handle<v8::Value>
IDirectFBFont_GetStringExtents( const v8::Arguments& args )
{
     IDirectFBFont *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBFont );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     const char *text = NULL;
     v8::String::Utf8Value utf8_text(args[0]);
     text = *utf8_text;

     int bytes = (int) args[1]->IntegerValue();

     DFBRectangle ret_logical_rect;

     DFBRectangle ret_ink_rect;

     V8_DIRECTFB_CALL( thiz->GetStringExtents( thiz, text, bytes, &ret_logical_rect, &ret_ink_rect ) );
     #warning unimplemented (second output)

     return DFBRectangle_construct( &ret_logical_rect );
}

static v8::Handle<v8::Value>
IDirectFBFont_GetGlyphExtents( const v8::Arguments& args )
{
     IDirectFBFont *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBFont );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     unsigned int character = (unsigned int) args[0]->IntegerValue();

     DFBRectangle ret_rect;

     int ret_advance;

     V8_DIRECTFB_CALL( thiz->GetGlyphExtents( thiz, character, &ret_rect, &ret_advance ) );
     #warning unimplemented (second output)

     return DFBRectangle_construct( &ret_rect );
}

static v8::Handle<v8::Value>
IDirectFBFont_SetEncoding( const v8::Arguments& args )
{
     IDirectFBFont *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBFont );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBTextEncodingID encoding = (DFBTextEncodingID) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetEncoding( thiz, encoding ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBFont_EnumEncodings( const v8::Arguments& args )
{
     IDirectFBFont *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBFont );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBTextEncodingCallback callback = (DFBTextEncodingCallback) args[0]->IntegerValue();

     void *context;
     #warning unimplemented (context pointer)
     D_UNIMPLEMENTED();

     V8_DIRECTFB_CALL( thiz->EnumEncodings( thiz, callback, context ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBFont_FindEncoding( const v8::Arguments& args )
{
     IDirectFBFont *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBFont );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     const char *name = NULL;
     v8::String::Utf8Value utf8_name(args[0]);
     name = *utf8_name;

     DFBTextEncodingID ret_encoding;

     V8_DIRECTFB_CALL( thiz->FindEncoding( thiz, name, &ret_encoding ) );

     return v8::Integer::New( ret_encoding );
}

/**********************************************************************************************************************/

v8::Handle<v8::ObjectTemplate>
IDirectFBFont_template()
{
     if (m_IDirectFBFont.IsEmpty()) {
          v8::HandleScope handle_scope;
          v8::Handle<v8::ObjectTemplate> templ;

          templ = v8::ObjectTemplate::New();

          templ->SetInternalFieldCount( 1 );

          templ->Set( v8::String::NewSymbol("Release"), v8::FunctionTemplate::New(IAny_release) );
          templ->Set( v8::String::NewSymbol("GetAscender"), v8::FunctionTemplate::New(IDirectFBFont_GetAscender) );
          templ->Set( v8::String::NewSymbol("GetDescender"), v8::FunctionTemplate::New(IDirectFBFont_GetDescender) );
          templ->Set( v8::String::NewSymbol("GetHeight"), v8::FunctionTemplate::New(IDirectFBFont_GetHeight) );
          templ->Set( v8::String::NewSymbol("GetMaxAdvance"), v8::FunctionTemplate::New(IDirectFBFont_GetMaxAdvance) );
          templ->Set( v8::String::NewSymbol("GetKerning"), v8::FunctionTemplate::New(IDirectFBFont_GetKerning) );
          templ->Set( v8::String::NewSymbol("GetStringWidth"), v8::FunctionTemplate::New(IDirectFBFont_GetStringWidth) );
          templ->Set( v8::String::NewSymbol("GetStringExtents"), v8::FunctionTemplate::New(IDirectFBFont_GetStringExtents) );
          templ->Set( v8::String::NewSymbol("GetGlyphExtents"), v8::FunctionTemplate::New(IDirectFBFont_GetGlyphExtents) );
          templ->Set( v8::String::NewSymbol("SetEncoding"), v8::FunctionTemplate::New(IDirectFBFont_SetEncoding) );
          templ->Set( v8::String::NewSymbol("EnumEncodings"), v8::FunctionTemplate::New(IDirectFBFont_EnumEncodings) );
          templ->Set( v8::String::NewSymbol("FindEncoding"), v8::FunctionTemplate::New(IDirectFBFont_FindEncoding) );

          m_IDirectFBFont = v8::Persistent<v8::ObjectTemplate>::New( handle_scope.Close( templ ) );
     }

     return m_IDirectFBFont;
}

}
