
#include "directfb_v8.h"


extern "C" {

static void InitAll(Handle<Object> target) {

	DFBResult ret = DirectFBInit(NULL, NULL);
		if (ret) {
			D_DERROR( (DirectResult) ret, "DirectFBInit() failed!\n" );
			return;
		}  

	DirectFB::Initialize(target);

}


NODE_MODULE(directfb, InitAll)

}
