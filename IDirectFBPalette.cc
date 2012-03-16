#include "common.h"

#include "templates.h"

namespace DirectFB {

static v8::Persistent<v8::ObjectTemplate>  m_IDirectFBPalette;

/**********************************************************************************************************************/

static v8::Handle<v8::Value>
IDirectFBPalette_GetCapabilities( const v8::Arguments& args )
{
     IDirectFBPalette *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBPalette );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBPaletteCapabilities ret_caps;

     V8_DIRECTFB_CALL( thiz->GetCapabilities( thiz, &ret_caps ) );

     return v8::Integer::New( ret_caps );
}

static v8::Handle<v8::Value>
IDirectFBPalette_GetSize( const v8::Arguments& args )
{
     IDirectFBPalette *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBPalette );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     unsigned int ret_size;

     V8_DIRECTFB_CALL( thiz->GetSize( thiz, &ret_size ) );

     return v8::Integer::New( ret_size );
}

static v8::Handle<v8::Value>
IDirectFBPalette_SetEntries( const v8::Arguments& args )
{
     IDirectFBPalette *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBPalette );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBColor *_entries = NULL;
     DFBColor entries;
     if (args[0]->IsObject()) {
          DFBColor_read( &entries, args[0] );
          _entries = &entries;
     }

     unsigned int num_entries = (unsigned int) args[1]->IntegerValue();

     unsigned int offset = (unsigned int) args[2]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetEntries( thiz, _entries, num_entries, offset ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBPalette_GetEntries( const v8::Arguments& args )
{
     IDirectFBPalette *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBPalette );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBColor ret_entries;

     unsigned int num_entries = (unsigned int) args[1]->IntegerValue();

     unsigned int offset = (unsigned int) args[2]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->GetEntries( thiz, &ret_entries, num_entries, offset ) );

     return DFBColor_construct( &ret_entries );
}

static v8::Handle<v8::Value>
IDirectFBPalette_FindBestMatch( const v8::Arguments& args )
{
     IDirectFBPalette *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBPalette );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     u8 r = (u8) args[0]->IntegerValue();

     u8 g = (u8) args[1]->IntegerValue();

     u8 b = (u8) args[2]->IntegerValue();

     u8 a = (u8) args[3]->IntegerValue();

     unsigned int ret_index;

     V8_DIRECTFB_CALL( thiz->FindBestMatch( thiz, r, g, b, a, &ret_index ) );

     return v8::Integer::New( ret_index );
}

static v8::Handle<v8::Value>
IDirectFBPalette_CreateCopy( const v8::Arguments& args )
{
     IDirectFBPalette *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBPalette );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBPalette *ret_interface;

     V8_DIRECTFB_CALL( thiz->CreateCopy( thiz, &ret_interface ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBPalette_template();

     return Construct( templ, ret_interface );
}

static v8::Handle<v8::Value>
IDirectFBPalette_SetEntriesYUV( const v8::Arguments& args )
{
     IDirectFBPalette *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBPalette );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBColorYUV *_entries = NULL;
     DFBColorYUV entries;
     if (args[0]->IsObject()) {
          DFBColorYUV_read( &entries, args[0] );
          _entries = &entries;
     }

     unsigned int num_entries = (unsigned int) args[1]->IntegerValue();

     unsigned int offset = (unsigned int) args[2]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetEntriesYUV( thiz, _entries, num_entries, offset ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBPalette_GetEntriesYUV( const v8::Arguments& args )
{
     IDirectFBPalette *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBPalette );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBColorYUV ret_entries;

     unsigned int num_entries = (unsigned int) args[1]->IntegerValue();

     unsigned int offset = (unsigned int) args[2]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->GetEntriesYUV( thiz, &ret_entries, num_entries, offset ) );

     return DFBColorYUV_construct( &ret_entries );
}

static v8::Handle<v8::Value>
IDirectFBPalette_FindBestMatchYUV( const v8::Arguments& args )
{
     IDirectFBPalette *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBPalette );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     u8 y = (u8) args[0]->IntegerValue();

     u8 u = (u8) args[1]->IntegerValue();

     u8 v = (u8) args[2]->IntegerValue();

     u8 a = (u8) args[3]->IntegerValue();

     unsigned int ret_index;

     V8_DIRECTFB_CALL( thiz->FindBestMatchYUV( thiz, y, u, v, a, &ret_index ) );

     return v8::Integer::New( ret_index );
}

/**********************************************************************************************************************/

v8::Handle<v8::ObjectTemplate>
IDirectFBPalette_template()
{
     if (m_IDirectFBPalette.IsEmpty()) {
          v8::HandleScope handle_scope;
          v8::Handle<v8::ObjectTemplate> templ;

          templ = v8::ObjectTemplate::New();

          templ->SetInternalFieldCount( 1 );

          templ->Set( v8::String::NewSymbol("Release"), v8::FunctionTemplate::New(IAny_release) );
          templ->Set( v8::String::NewSymbol("GetCapabilities"), v8::FunctionTemplate::New(IDirectFBPalette_GetCapabilities) );
          templ->Set( v8::String::NewSymbol("GetSize"), v8::FunctionTemplate::New(IDirectFBPalette_GetSize) );
          templ->Set( v8::String::NewSymbol("SetEntries"), v8::FunctionTemplate::New(IDirectFBPalette_SetEntries) );
          templ->Set( v8::String::NewSymbol("GetEntries"), v8::FunctionTemplate::New(IDirectFBPalette_GetEntries) );
          templ->Set( v8::String::NewSymbol("FindBestMatch"), v8::FunctionTemplate::New(IDirectFBPalette_FindBestMatch) );
          templ->Set( v8::String::NewSymbol("CreateCopy"), v8::FunctionTemplate::New(IDirectFBPalette_CreateCopy) );
          templ->Set( v8::String::NewSymbol("SetEntriesYUV"), v8::FunctionTemplate::New(IDirectFBPalette_SetEntriesYUV) );
          templ->Set( v8::String::NewSymbol("GetEntriesYUV"), v8::FunctionTemplate::New(IDirectFBPalette_GetEntriesYUV) );
          templ->Set( v8::String::NewSymbol("FindBestMatchYUV"), v8::FunctionTemplate::New(IDirectFBPalette_FindBestMatchYUV) );

          m_IDirectFBPalette = v8::Persistent<v8::ObjectTemplate>::New( handle_scope.Close( templ ) );
     }

     return m_IDirectFBPalette;
}

}
