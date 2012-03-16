#include "common.h"

#include "templates.h"

namespace DirectFB {

static v8::Persistent<v8::ObjectTemplate>  m_IDirectFBInputDevice;

/**********************************************************************************************************************/

static v8::Handle<v8::Value>
IDirectFBInputDevice_GetID( const v8::Arguments& args )
{
     IDirectFBInputDevice *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBInputDevice );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBInputDeviceID ret_device_id;

     V8_DIRECTFB_CALL( thiz->GetID( thiz, &ret_device_id ) );

     return v8::Integer::New( ret_device_id );
}

static v8::Handle<v8::Value>
IDirectFBInputDevice_GetDescription( const v8::Arguments& args )
{
     IDirectFBInputDevice *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBInputDevice );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBInputDeviceDescription ret_desc;

     V8_DIRECTFB_CALL( thiz->GetDescription( thiz, &ret_desc ) );

     return DFBInputDeviceDescription_construct( &ret_desc );
}

static v8::Handle<v8::Value>
IDirectFBInputDevice_GetKeymapEntry( const v8::Arguments& args )
{
     IDirectFBInputDevice *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBInputDevice );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int keycode = (int) args[0]->IntegerValue();

     DFBInputDeviceKeymapEntry ret_entry;

     V8_DIRECTFB_CALL( thiz->GetKeymapEntry( thiz, keycode, &ret_entry ) );

     return DFBInputDeviceKeymapEntry_construct( &ret_entry );
}

static v8::Handle<v8::Value>
IDirectFBInputDevice_CreateEventBuffer( const v8::Arguments& args )
{
     IDirectFBInputDevice *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBInputDevice );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBEventBuffer *ret_buffer;

     V8_DIRECTFB_CALL( thiz->CreateEventBuffer( thiz, &ret_buffer ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBEventBuffer_template();

     return Construct( templ, ret_buffer );
}

static v8::Handle<v8::Value>
IDirectFBInputDevice_AttachEventBuffer( const v8::Arguments& args )
{
     IDirectFBInputDevice *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBInputDevice );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBEventBuffer *buffer = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBEventBuffer );

     V8_DIRECTFB_CALL( thiz->AttachEventBuffer( thiz, buffer ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBInputDevice_DetachEventBuffer( const v8::Arguments& args )
{
     IDirectFBInputDevice *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBInputDevice );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBEventBuffer *buffer = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBEventBuffer );

     V8_DIRECTFB_CALL( thiz->DetachEventBuffer( thiz, buffer ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBInputDevice_GetKeyState( const v8::Arguments& args )
{
     IDirectFBInputDevice *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBInputDevice );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBInputDeviceKeyIdentifier key_id = (DFBInputDeviceKeyIdentifier) args[0]->IntegerValue();

     DFBInputDeviceKeyState ret_state;

     V8_DIRECTFB_CALL( thiz->GetKeyState( thiz, key_id, &ret_state ) );

     return v8::Integer::New( ret_state );
}

static v8::Handle<v8::Value>
IDirectFBInputDevice_GetModifiers( const v8::Arguments& args )
{
     IDirectFBInputDevice *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBInputDevice );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBInputDeviceModifierMask ret_modifiers;

     V8_DIRECTFB_CALL( thiz->GetModifiers( thiz, &ret_modifiers ) );

     return v8::Integer::New( ret_modifiers );
}

static v8::Handle<v8::Value>
IDirectFBInputDevice_GetLockState( const v8::Arguments& args )
{
     IDirectFBInputDevice *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBInputDevice );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBInputDeviceLockState ret_locks;

     V8_DIRECTFB_CALL( thiz->GetLockState( thiz, &ret_locks ) );

     return v8::Integer::New( ret_locks );
}

static v8::Handle<v8::Value>
IDirectFBInputDevice_GetButtons( const v8::Arguments& args )
{
     IDirectFBInputDevice *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBInputDevice );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBInputDeviceButtonMask ret_buttons;

     V8_DIRECTFB_CALL( thiz->GetButtons( thiz, &ret_buttons ) );

     return v8::Integer::New( ret_buttons );
}

static v8::Handle<v8::Value>
IDirectFBInputDevice_GetButtonState( const v8::Arguments& args )
{
     IDirectFBInputDevice *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBInputDevice );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBInputDeviceButtonIdentifier button = (DFBInputDeviceButtonIdentifier) args[0]->IntegerValue();

     DFBInputDeviceButtonState ret_state;

     V8_DIRECTFB_CALL( thiz->GetButtonState( thiz, button, &ret_state ) );

     return v8::Integer::New( ret_state );
}

static v8::Handle<v8::Value>
IDirectFBInputDevice_GetAxis( const v8::Arguments& args )
{
     IDirectFBInputDevice *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBInputDevice );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBInputDeviceAxisIdentifier axis = (DFBInputDeviceAxisIdentifier) args[0]->IntegerValue();

     int ret_pos;

     V8_DIRECTFB_CALL( thiz->GetAxis( thiz, axis, &ret_pos ) );

     return v8::Integer::New( ret_pos );
}

static v8::Handle<v8::Value>
IDirectFBInputDevice_GetXY( const v8::Arguments& args )
{
     IDirectFBInputDevice *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBInputDevice );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int ret_x;

     int ret_y;

     V8_DIRECTFB_CALL( thiz->GetXY( thiz, &ret_x, &ret_y ) );
     #warning unimplemented (second output)

     return v8::Integer::New( ret_x );
}

/**********************************************************************************************************************/

v8::Handle<v8::ObjectTemplate>
IDirectFBInputDevice_template()
{
     if (m_IDirectFBInputDevice.IsEmpty()) {
          v8::HandleScope handle_scope;
          v8::Handle<v8::ObjectTemplate> templ;

          templ = v8::ObjectTemplate::New();

          templ->SetInternalFieldCount( 1 );

          templ->Set( v8::String::NewSymbol("Release"), v8::FunctionTemplate::New(IAny_release) );
          templ->Set( v8::String::NewSymbol("GetID"), v8::FunctionTemplate::New(IDirectFBInputDevice_GetID) );
          templ->Set( v8::String::NewSymbol("GetDescription"), v8::FunctionTemplate::New(IDirectFBInputDevice_GetDescription) );
          templ->Set( v8::String::NewSymbol("GetKeymapEntry"), v8::FunctionTemplate::New(IDirectFBInputDevice_GetKeymapEntry) );
          templ->Set( v8::String::NewSymbol("CreateEventBuffer"), v8::FunctionTemplate::New(IDirectFBInputDevice_CreateEventBuffer) );
          templ->Set( v8::String::NewSymbol("AttachEventBuffer"), v8::FunctionTemplate::New(IDirectFBInputDevice_AttachEventBuffer) );
          templ->Set( v8::String::NewSymbol("DetachEventBuffer"), v8::FunctionTemplate::New(IDirectFBInputDevice_DetachEventBuffer) );
          templ->Set( v8::String::NewSymbol("GetKeyState"), v8::FunctionTemplate::New(IDirectFBInputDevice_GetKeyState) );
          templ->Set( v8::String::NewSymbol("GetModifiers"), v8::FunctionTemplate::New(IDirectFBInputDevice_GetModifiers) );
          templ->Set( v8::String::NewSymbol("GetLockState"), v8::FunctionTemplate::New(IDirectFBInputDevice_GetLockState) );
          templ->Set( v8::String::NewSymbol("GetButtons"), v8::FunctionTemplate::New(IDirectFBInputDevice_GetButtons) );
          templ->Set( v8::String::NewSymbol("GetButtonState"), v8::FunctionTemplate::New(IDirectFBInputDevice_GetButtonState) );
          templ->Set( v8::String::NewSymbol("GetAxis"), v8::FunctionTemplate::New(IDirectFBInputDevice_GetAxis) );
          templ->Set( v8::String::NewSymbol("GetXY"), v8::FunctionTemplate::New(IDirectFBInputDevice_GetXY) );

          m_IDirectFBInputDevice = v8::Persistent<v8::ObjectTemplate>::New( handle_scope.Close( templ ) );
     }

     return m_IDirectFBInputDevice;
}

}
