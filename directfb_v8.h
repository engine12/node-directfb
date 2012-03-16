
#include <node.h>
#include <node_object_wrap.h>

#include "common.h"

#include "templates.h"

using namespace v8;
using namespace node;

namespace DirectFB {

	extern void  Initialize( v8::Handle<v8::Object> );
	extern v8::Handle<v8::Value> Create( const v8::Arguments& args );

}



