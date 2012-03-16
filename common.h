#ifndef __V8_DIRECTFB__COMMON_H__
#define __V8_DIRECTFB__COMMON_H__

#include <v8.h>
#include <directfb.h>
#include <directfbgl.h>
#include <directfb_util.h>


//namespace DirectFB 
//{

/**********************************************************************************************************************/

#define V8_DIRECTFB_INTERFACE( obj, type )                                                          \
     (static_cast<type*>( (obj)->GetPointerFromInternalField( 0 )))

#define V8_DIRECTFB_CALL( expr )                                                                    \
     do {                                                                                           \
          DFBResult ret = (DFBResult)(expr);                                                        \
                                                                                                    \
          if (ret) {                                                                                \
               D_DERROR( (DirectResult) ret, "V8: %s\n", #expr );                                   \
               return v8::ThrowException( v8::String::New( DirectFBErrorString(ret) ) );            \
          }                                                                                         \
     } while (0)

/**********************************************************************************************************************/

v8::Handle<v8::Object> Construct( v8::Handle<v8::ObjectTemplate> templ, void *interface );

v8::Handle<v8::Value>  IAny_release( const v8::Arguments& args );

//}


#endif

