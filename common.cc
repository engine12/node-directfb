#include "common.h"


//namespace DirectFB 
//{

v8::Handle<v8::Object>
Construct( v8::Handle<v8::ObjectTemplate> templ, void *interface )
{
     v8::HandleScope handle_scope;

     v8::Handle<v8::Object> obj = templ->NewInstance();
     D_ASSERT( !obj.IsEmpty() );

     obj->SetPointerInInternalField( 0, interface );

     return handle_scope.Close( obj );
}

v8::Handle<v8::Value>
IAny_release( const v8::Arguments& args )
{
     v8::Handle<v8::Object> obj = args.This();

     IAny *thiz = V8_DIRECTFB_INTERFACE( obj, IAny );

     V8_DIRECTFB_CALL( thiz->Release( thiz ) );

     obj->SetPointerInInternalField( 0, NULL );

     return v8::Undefined();
}


//}

