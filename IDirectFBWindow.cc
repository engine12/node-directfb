#include "common.h"

#include "templates.h"

namespace DirectFB {

static v8::Persistent<v8::ObjectTemplate>  m_IDirectFBWindow;

/**********************************************************************************************************************/

static v8::Handle<v8::Value>
IDirectFBWindow_GetID( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBWindowID ret_window_id;

     V8_DIRECTFB_CALL( thiz->GetID( thiz, &ret_window_id ) );

     return v8::Integer::New( ret_window_id );
}

static v8::Handle<v8::Value>
IDirectFBWindow_GetPosition( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int ret_x;

     int ret_y;

     V8_DIRECTFB_CALL( thiz->GetPosition( thiz, &ret_x, &ret_y ) );
     #warning unimplemented (second output)

     return v8::Integer::New( ret_x );
}

static v8::Handle<v8::Value>
IDirectFBWindow_GetSize( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int ret_width;

     int ret_height;

     V8_DIRECTFB_CALL( thiz->GetSize( thiz, &ret_width, &ret_height ) );
     #warning unimplemented (second output)

     return v8::Integer::New( ret_width );
}

static v8::Handle<v8::Value>
IDirectFBWindow_CreateEventBuffer( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBEventBuffer *ret_buffer;

     V8_DIRECTFB_CALL( thiz->CreateEventBuffer( thiz, &ret_buffer ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBEventBuffer_template();

     return Construct( templ, ret_buffer );
}

static v8::Handle<v8::Value>
IDirectFBWindow_AttachEventBuffer( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBEventBuffer *buffer = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBEventBuffer );

     V8_DIRECTFB_CALL( thiz->AttachEventBuffer( thiz, buffer ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_DetachEventBuffer( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBEventBuffer *buffer = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBEventBuffer );

     V8_DIRECTFB_CALL( thiz->DetachEventBuffer( thiz, buffer ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_EnableEvents( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBWindowEventType mask = (DFBWindowEventType) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->EnableEvents( thiz, mask ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_DisableEvents( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBWindowEventType mask = (DFBWindowEventType) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->DisableEvents( thiz, mask ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_GetSurface( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBSurface *ret_surface;

     V8_DIRECTFB_CALL( thiz->GetSurface( thiz, &ret_surface ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBSurface_template();

     return Construct( templ, ret_surface );
}

static v8::Handle<v8::Value>
IDirectFBWindow_SetProperty( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     const char *key = NULL;
     v8::String::Utf8Value utf8_key(args[0]);
     key = *utf8_key;

     void *value;
     #warning unimplemented (context pointer)
     D_UNIMPLEMENTED();

     void *ret_old_value;
     #warning unimplemented (return pointer)
     D_UNIMPLEMENTED();

     V8_DIRECTFB_CALL( thiz->SetProperty( thiz, key, value, &ret_old_value ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_GetProperty( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     const char *key = NULL;
     v8::String::Utf8Value utf8_key(args[0]);
     key = *utf8_key;

     void *ret_value;
     #warning unimplemented (return pointer)
     D_UNIMPLEMENTED();

     V8_DIRECTFB_CALL( thiz->GetProperty( thiz, key, &ret_value ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_RemoveProperty( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     const char *key = NULL;
     v8::String::Utf8Value utf8_key(args[0]);
     key = *utf8_key;

     void *ret_value;
     #warning unimplemented (return pointer)
     D_UNIMPLEMENTED();

     V8_DIRECTFB_CALL( thiz->RemoveProperty( thiz, key, &ret_value ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_SetOptions( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBWindowOptions options = (DFBWindowOptions) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetOptions( thiz, options ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_GetOptions( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBWindowOptions ret_options;

     V8_DIRECTFB_CALL( thiz->GetOptions( thiz, &ret_options ) );

     return v8::Integer::New( ret_options );
}

static v8::Handle<v8::Value>
IDirectFBWindow_SetColorKey( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     u8 r = (u8) args[0]->IntegerValue();

     u8 g = (u8) args[1]->IntegerValue();

     u8 b = (u8) args[2]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetColorKey( thiz, r, g, b ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_SetColorKeyIndex( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     unsigned int index = (unsigned int) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetColorKeyIndex( thiz, index ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_SetOpacity( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     u8 opacity = (u8) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetOpacity( thiz, opacity ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_SetOpaqueRegion( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int x1 = (int) args[0]->IntegerValue();

     int y1 = (int) args[1]->IntegerValue();

     int x2 = (int) args[2]->IntegerValue();

     int y2 = (int) args[3]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetOpaqueRegion( thiz, x1, y1, x2, y2 ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_GetOpacity( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     u8 ret_opacity;

     V8_DIRECTFB_CALL( thiz->GetOpacity( thiz, &ret_opacity ) );

     return v8::Integer::New( ret_opacity );
}

static v8::Handle<v8::Value>
IDirectFBWindow_SetCursorShape( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBSurface *shape = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBSurface );

     int hot_x = (int) args[1]->IntegerValue();

     int hot_y = (int) args[2]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetCursorShape( thiz, shape, hot_x, hot_y ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_RequestFocus( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->RequestFocus( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_GrabKeyboard( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->GrabKeyboard( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_UngrabKeyboard( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->UngrabKeyboard( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_GrabPointer( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->GrabPointer( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_UngrabPointer( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->UngrabPointer( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_GrabKey( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBInputDeviceKeySymbol symbol = (DFBInputDeviceKeySymbol) args[0]->IntegerValue();

     DFBInputDeviceModifierMask modifiers = (DFBInputDeviceModifierMask) args[1]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->GrabKey( thiz, symbol, modifiers ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_UngrabKey( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBInputDeviceKeySymbol symbol = (DFBInputDeviceKeySymbol) args[0]->IntegerValue();

     DFBInputDeviceModifierMask modifiers = (DFBInputDeviceModifierMask) args[1]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->UngrabKey( thiz, symbol, modifiers ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_Move( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int dx = (int) args[0]->IntegerValue();

     int dy = (int) args[1]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->Move( thiz, dx, dy ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_MoveTo( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int x = (int) args[0]->IntegerValue();

     int y = (int) args[1]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->MoveTo( thiz, x, y ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_Resize( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int width = (int) args[0]->IntegerValue();

     int height = (int) args[1]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->Resize( thiz, width, height ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_SetStackingClass( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBWindowStackingClass stacking_class = (DFBWindowStackingClass) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetStackingClass( thiz, stacking_class ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_Raise( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->Raise( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_Lower( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->Lower( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_RaiseToTop( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->RaiseToTop( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_LowerToBottom( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->LowerToBottom( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_PutAtop( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBWindow *lower = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBWindow );

     V8_DIRECTFB_CALL( thiz->PutAtop( thiz, lower ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_PutBelow( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBWindow *upper = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBWindow );

     V8_DIRECTFB_CALL( thiz->PutBelow( thiz, upper ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_Close( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->Close( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_Destroy( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->Destroy( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_SetBounds( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int x = (int) args[0]->IntegerValue();

     int y = (int) args[1]->IntegerValue();

     int width = (int) args[2]->IntegerValue();

     int height = (int) args[3]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetBounds( thiz, x, y, width, height ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_ResizeSurface( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int width = (int) args[0]->IntegerValue();

     int height = (int) args[1]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->ResizeSurface( thiz, width, height ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_Bind( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBWindow *window = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBWindow );

     int x = (int) args[1]->IntegerValue();

     int y = (int) args[2]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->Bind( thiz, window, x, y ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_Unbind( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBWindow *window = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBWindow );

     V8_DIRECTFB_CALL( thiz->Unbind( thiz, window ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_SetKeySelection( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBWindowKeySelection selection = (DFBWindowKeySelection) args[0]->IntegerValue();

     DFBInputDeviceKeySymbol keys;
     #warning unimplemented (array input?)
     D_UNIMPLEMENTED();

     unsigned int num_keys = (unsigned int) args[2]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetKeySelection( thiz, selection, &keys, num_keys ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_GrabUnselectedKeys( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->GrabUnselectedKeys( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_UngrabUnselectedKeys( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->UngrabUnselectedKeys( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_SetSrcGeometry( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBWindowGeometry *_geometry = NULL;
     DFBWindowGeometry geometry;
     if (args[0]->IsObject()) {
          DFBWindowGeometry_read( &geometry, args[0] );
          _geometry = &geometry;
     }

     V8_DIRECTFB_CALL( thiz->SetSrcGeometry( thiz, _geometry ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_SetDstGeometry( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBWindowGeometry *_geometry = NULL;
     DFBWindowGeometry geometry;
     if (args[0]->IsObject()) {
          DFBWindowGeometry_read( &geometry, args[0] );
          _geometry = &geometry;
     }

     V8_DIRECTFB_CALL( thiz->SetDstGeometry( thiz, _geometry ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBWindow_SetRotation( const v8::Arguments& args )
{
     IDirectFBWindow *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBWindow );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


	int rotation = (unsigned int) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetRotation( thiz, rotation ) );

     return v8::Undefined();
}

/**********************************************************************************************************************/

v8::Handle<v8::ObjectTemplate>
IDirectFBWindow_template()
{
     if (m_IDirectFBWindow.IsEmpty()) {
          v8::HandleScope handle_scope;
          v8::Handle<v8::ObjectTemplate> templ;

          templ = v8::ObjectTemplate::New();

          templ->SetInternalFieldCount( 1 );

          templ->Set( v8::String::NewSymbol("SetRotation"), v8::FunctionTemplate::New(IDirectFBWindow_SetRotation) );
          templ->Set( v8::String::NewSymbol("Release"), v8::FunctionTemplate::New(IAny_release) );
          templ->Set( v8::String::NewSymbol("GetID"), v8::FunctionTemplate::New(IDirectFBWindow_GetID) );
          templ->Set( v8::String::NewSymbol("GetPosition"), v8::FunctionTemplate::New(IDirectFBWindow_GetPosition) );
          templ->Set( v8::String::NewSymbol("GetSize"), v8::FunctionTemplate::New(IDirectFBWindow_GetSize) );
          templ->Set( v8::String::NewSymbol("CreateEventBuffer"), v8::FunctionTemplate::New(IDirectFBWindow_CreateEventBuffer) );
          templ->Set( v8::String::NewSymbol("AttachEventBuffer"), v8::FunctionTemplate::New(IDirectFBWindow_AttachEventBuffer) );
          templ->Set( v8::String::NewSymbol("DetachEventBuffer"), v8::FunctionTemplate::New(IDirectFBWindow_DetachEventBuffer) );
          templ->Set( v8::String::NewSymbol("EnableEvents"), v8::FunctionTemplate::New(IDirectFBWindow_EnableEvents) );
          templ->Set( v8::String::NewSymbol("DisableEvents"), v8::FunctionTemplate::New(IDirectFBWindow_DisableEvents) );
          templ->Set( v8::String::NewSymbol("GetSurface"), v8::FunctionTemplate::New(IDirectFBWindow_GetSurface) );
          templ->Set( v8::String::NewSymbol("SetProperty"), v8::FunctionTemplate::New(IDirectFBWindow_SetProperty) );
          templ->Set( v8::String::NewSymbol("GetProperty"), v8::FunctionTemplate::New(IDirectFBWindow_GetProperty) );
          templ->Set( v8::String::NewSymbol("RemoveProperty"), v8::FunctionTemplate::New(IDirectFBWindow_RemoveProperty) );
          templ->Set( v8::String::NewSymbol("SetOptions"), v8::FunctionTemplate::New(IDirectFBWindow_SetOptions) );
          templ->Set( v8::String::NewSymbol("GetOptions"), v8::FunctionTemplate::New(IDirectFBWindow_GetOptions) );
          templ->Set( v8::String::NewSymbol("SetColorKey"), v8::FunctionTemplate::New(IDirectFBWindow_SetColorKey) );
          templ->Set( v8::String::NewSymbol("SetColorKeyIndex"), v8::FunctionTemplate::New(IDirectFBWindow_SetColorKeyIndex) );
          templ->Set( v8::String::NewSymbol("SetOpacity"), v8::FunctionTemplate::New(IDirectFBWindow_SetOpacity) );
          templ->Set( v8::String::NewSymbol("SetOpaqueRegion"), v8::FunctionTemplate::New(IDirectFBWindow_SetOpaqueRegion) );
          templ->Set( v8::String::NewSymbol("GetOpacity"), v8::FunctionTemplate::New(IDirectFBWindow_GetOpacity) );
          templ->Set( v8::String::NewSymbol("SetCursorShape"), v8::FunctionTemplate::New(IDirectFBWindow_SetCursorShape) );
          templ->Set( v8::String::NewSymbol("RequestFocus"), v8::FunctionTemplate::New(IDirectFBWindow_RequestFocus) );
          templ->Set( v8::String::NewSymbol("GrabKeyboard"), v8::FunctionTemplate::New(IDirectFBWindow_GrabKeyboard) );
          templ->Set( v8::String::NewSymbol("UngrabKeyboard"), v8::FunctionTemplate::New(IDirectFBWindow_UngrabKeyboard) );
          templ->Set( v8::String::NewSymbol("GrabPointer"), v8::FunctionTemplate::New(IDirectFBWindow_GrabPointer) );
          templ->Set( v8::String::NewSymbol("UngrabPointer"), v8::FunctionTemplate::New(IDirectFBWindow_UngrabPointer) );
          templ->Set( v8::String::NewSymbol("GrabKey"), v8::FunctionTemplate::New(IDirectFBWindow_GrabKey) );
          templ->Set( v8::String::NewSymbol("UngrabKey"), v8::FunctionTemplate::New(IDirectFBWindow_UngrabKey) );
          templ->Set( v8::String::NewSymbol("Move"), v8::FunctionTemplate::New(IDirectFBWindow_Move) );
          templ->Set( v8::String::NewSymbol("MoveTo"), v8::FunctionTemplate::New(IDirectFBWindow_MoveTo) );
          templ->Set( v8::String::NewSymbol("Resize"), v8::FunctionTemplate::New(IDirectFBWindow_Resize) );
          templ->Set( v8::String::NewSymbol("SetStackingClass"), v8::FunctionTemplate::New(IDirectFBWindow_SetStackingClass) );
          templ->Set( v8::String::NewSymbol("Raise"), v8::FunctionTemplate::New(IDirectFBWindow_Raise) );
          templ->Set( v8::String::NewSymbol("Lower"), v8::FunctionTemplate::New(IDirectFBWindow_Lower) );
          templ->Set( v8::String::NewSymbol("RaiseToTop"), v8::FunctionTemplate::New(IDirectFBWindow_RaiseToTop) );
          templ->Set( v8::String::NewSymbol("LowerToBottom"), v8::FunctionTemplate::New(IDirectFBWindow_LowerToBottom) );
          templ->Set( v8::String::NewSymbol("PutAtop"), v8::FunctionTemplate::New(IDirectFBWindow_PutAtop) );
          templ->Set( v8::String::NewSymbol("PutBelow"), v8::FunctionTemplate::New(IDirectFBWindow_PutBelow) );
          templ->Set( v8::String::NewSymbol("Close"), v8::FunctionTemplate::New(IDirectFBWindow_Close) );
          templ->Set( v8::String::NewSymbol("Destroy"), v8::FunctionTemplate::New(IDirectFBWindow_Destroy) );
          templ->Set( v8::String::NewSymbol("SetBounds"), v8::FunctionTemplate::New(IDirectFBWindow_SetBounds) );
          templ->Set( v8::String::NewSymbol("ResizeSurface"), v8::FunctionTemplate::New(IDirectFBWindow_ResizeSurface) );
          templ->Set( v8::String::NewSymbol("Bind"), v8::FunctionTemplate::New(IDirectFBWindow_Bind) );
          templ->Set( v8::String::NewSymbol("Unbind"), v8::FunctionTemplate::New(IDirectFBWindow_Unbind) );
          templ->Set( v8::String::NewSymbol("SetKeySelection"), v8::FunctionTemplate::New(IDirectFBWindow_SetKeySelection) );
          templ->Set( v8::String::NewSymbol("GrabUnselectedKeys"), v8::FunctionTemplate::New(IDirectFBWindow_GrabUnselectedKeys) );
          templ->Set( v8::String::NewSymbol("UngrabUnselectedKeys"), v8::FunctionTemplate::New(IDirectFBWindow_UngrabUnselectedKeys) );
          templ->Set( v8::String::NewSymbol("SetSrcGeometry"), v8::FunctionTemplate::New(IDirectFBWindow_SetSrcGeometry) );
          templ->Set( v8::String::NewSymbol("SetDstGeometry"), v8::FunctionTemplate::New(IDirectFBWindow_SetDstGeometry) );

          m_IDirectFBWindow = v8::Persistent<v8::ObjectTemplate>::New( handle_scope.Close( templ ) );
     }

     return m_IDirectFBWindow;
}

}
