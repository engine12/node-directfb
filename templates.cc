#include "common.h"

#include <string.h>

#include "templates.h"

namespace DirectFB {


v8::Handle<v8::Object>
DFBInputDeviceKeymapEntry_construct( const DFBInputDeviceKeymapEntry *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBInputDeviceKeymapEntry_read( DFBInputDeviceKeymapEntry *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBInputDeviceKeymapEntry) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBPoint_construct( const DFBPoint *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBPoint_read( DFBPoint *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBPoint) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBSpan_construct( const DFBSpan *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBSpan_read( DFBSpan *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBSpan) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBDimension_construct( const DFBDimension *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBDimension_read( DFBDimension *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBDimension) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBRectangle_construct( const DFBRectangle *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();

     obj->Set( v8::String::NewSymbol( "x" ), v8::Integer::New(src->x) );
     obj->Set( v8::String::NewSymbol( "y" ), v8::Integer::New(src->y) );
     obj->Set( v8::String::NewSymbol( "w" ), v8::Integer::New(src->w) );
     obj->Set( v8::String::NewSymbol( "h" ), v8::Integer::New(src->h) );

     return obj;
}

void
DFBRectangle_read( DFBRectangle *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBRectangle) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

     dst->x = (int) obj->Get( v8::String::NewSymbol("x") )->IntegerValue();
     dst->y = (int) obj->Get( v8::String::NewSymbol("y") )->IntegerValue();
     dst->w = (int) obj->Get( v8::String::NewSymbol("w") )->IntegerValue();
     dst->h = (int) obj->Get( v8::String::NewSymbol("h") )->IntegerValue();
}

v8::Handle<v8::Object>
DFBLocation_construct( const DFBLocation *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBLocation_read( DFBLocation *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBLocation) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBRegion_construct( const DFBRegion *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();

     obj->Set( v8::String::NewSymbol( "x1" ), v8::Integer::New(src->x1) );
     obj->Set( v8::String::NewSymbol( "y1" ), v8::Integer::New(src->y1) );
     obj->Set( v8::String::NewSymbol( "x2" ), v8::Integer::New(src->x2) );
     obj->Set( v8::String::NewSymbol( "y2" ), v8::Integer::New(src->y2) );

     return obj;
}

void
DFBRegion_read( DFBRegion *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBRegion) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

     dst->x1 = (int) obj->Get( v8::String::NewSymbol("x1") )->IntegerValue();
     dst->y1 = (int) obj->Get( v8::String::NewSymbol("y1") )->IntegerValue();
     dst->x2 = (int) obj->Get( v8::String::NewSymbol("x2") )->IntegerValue();
     dst->y2 = (int) obj->Get( v8::String::NewSymbol("y2") )->IntegerValue();
}

v8::Handle<v8::Object>
DFBInsets_construct( const DFBInsets *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBInsets_read( DFBInsets *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBInsets) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBTriangle_construct( const DFBTriangle *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBTriangle_read( DFBTriangle *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBTriangle) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBColor_construct( const DFBColor *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();

     obj->Set( v8::String::NewSymbol( "a" ), v8::Integer::New(src->a) );
     obj->Set( v8::String::NewSymbol( "r" ), v8::Integer::New(src->r) );
     obj->Set( v8::String::NewSymbol( "g" ), v8::Integer::New(src->g) );
     obj->Set( v8::String::NewSymbol( "b" ), v8::Integer::New(src->b) );

     return obj;
}

void
DFBColor_read( DFBColor *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBColor) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

     dst->a = (u8) obj->Get( v8::String::NewSymbol("a") )->IntegerValue();
     dst->r = (u8) obj->Get( v8::String::NewSymbol("r") )->IntegerValue();
     dst->g = (u8) obj->Get( v8::String::NewSymbol("g") )->IntegerValue();
     dst->b = (u8) obj->Get( v8::String::NewSymbol("b") )->IntegerValue();
}

v8::Handle<v8::Object>
DFBColorKey_construct( const DFBColorKey *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBColorKey_read( DFBColorKey *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBColorKey) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBColorYUV_construct( const DFBColorYUV *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBColorYUV_read( DFBColorYUV *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBColorYUV) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBFontDescription_construct( const DFBFontDescription *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();

     obj->Set( v8::String::NewSymbol( "flags" ), v8::Integer::New(src->flags) );
     obj->Set( v8::String::NewSymbol( "attributes" ), v8::Integer::New(src->attributes) );
     obj->Set( v8::String::NewSymbol( "height" ), v8::Integer::New(src->height) );
     obj->Set( v8::String::NewSymbol( "width" ), v8::Integer::New(src->width) );
     obj->Set( v8::String::NewSymbol( "index" ), v8::Integer::New(src->index) );
     obj->Set( v8::String::NewSymbol( "fixed_advance" ), v8::Integer::New(src->fixed_advance) );
     obj->Set( v8::String::NewSymbol( "fract_height" ), v8::Integer::New(src->fract_height) );
     obj->Set( v8::String::NewSymbol( "fract_width" ), v8::Integer::New(src->fract_width) );

     return obj;
}

void
DFBFontDescription_read( DFBFontDescription *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBFontDescription) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

     dst->flags = (DFBFontDescriptionFlags) obj->Get( v8::String::NewSymbol("flags") )->IntegerValue();
     dst->attributes = (DFBFontAttributes) obj->Get( v8::String::NewSymbol("attributes") )->IntegerValue();
     dst->height = (int) obj->Get( v8::String::NewSymbol("height") )->IntegerValue();
     dst->width = (int) obj->Get( v8::String::NewSymbol("width") )->IntegerValue();
     dst->index = (unsigned int) obj->Get( v8::String::NewSymbol("index") )->IntegerValue();
     dst->fixed_advance = (int) obj->Get( v8::String::NewSymbol("fixed_advance") )->IntegerValue();
     dst->fract_height = (int) obj->Get( v8::String::NewSymbol("fract_height") )->IntegerValue();
     dst->fract_width = (int) obj->Get( v8::String::NewSymbol("fract_width") )->IntegerValue();
}

v8::Handle<v8::Object>
DFBSurfaceDescription_construct( const DFBSurfaceDescription *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();

     obj->Set( v8::String::NewSymbol( "flags" ), v8::Integer::New(src->flags) );
     obj->Set( v8::String::NewSymbol( "caps" ), v8::Integer::New(src->caps) );
     obj->Set( v8::String::NewSymbol( "width" ), v8::Integer::New(src->width) );
     obj->Set( v8::String::NewSymbol( "height" ), v8::Integer::New(src->height) );
     obj->Set( v8::String::NewSymbol( "pixelformat" ), v8::Integer::New(src->pixelformat) );
     obj->Set( v8::String::NewSymbol( "resource_id" ), v8::Integer::New(src->resource_id) );

     return obj;
}

void
DFBSurfaceDescription_read( DFBSurfaceDescription *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBSurfaceDescription) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

     dst->flags = (DFBSurfaceDescriptionFlags) obj->Get( v8::String::NewSymbol("flags") )->IntegerValue();
     dst->caps = (DFBSurfaceCapabilities) obj->Get( v8::String::NewSymbol("caps") )->IntegerValue();
     dst->width = (int) obj->Get( v8::String::NewSymbol("width") )->IntegerValue();
     dst->height = (int) obj->Get( v8::String::NewSymbol("height") )->IntegerValue();
     dst->pixelformat = (DFBSurfacePixelFormat) obj->Get( v8::String::NewSymbol("pixelformat") )->IntegerValue();
     dst->resource_id = (unsigned long) obj->Get( v8::String::NewSymbol("resource_id") )->IntegerValue();
}

v8::Handle<v8::Object>
DFBPaletteDescription_construct( const DFBPaletteDescription *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBPaletteDescription_read( DFBPaletteDescription *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBPaletteDescription) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBDisplayLayerDescription_construct( const DFBDisplayLayerDescription *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBDisplayLayerDescription_read( DFBDisplayLayerDescription *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBDisplayLayerDescription) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBDisplayLayerSourceDescription_construct( const DFBDisplayLayerSourceDescription *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBDisplayLayerSourceDescription_read( DFBDisplayLayerSourceDescription *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBDisplayLayerSourceDescription) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBScreenDescription_construct( const DFBScreenDescription *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBScreenDescription_read( DFBScreenDescription *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBScreenDescription) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBInputDeviceDescription_construct( const DFBInputDeviceDescription *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBInputDeviceDescription_read( DFBInputDeviceDescription *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBInputDeviceDescription) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBInputDeviceAxisInfo_construct( const DFBInputDeviceAxisInfo *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBInputDeviceAxisInfo_read( DFBInputDeviceAxisInfo *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBInputDeviceAxisInfo) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBGraphicsDriverInfo_construct( const DFBGraphicsDriverInfo *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBGraphicsDriverInfo_read( DFBGraphicsDriverInfo *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBGraphicsDriverInfo) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBGraphicsDeviceDescription_construct( const DFBGraphicsDeviceDescription *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBGraphicsDeviceDescription_read( DFBGraphicsDeviceDescription *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBGraphicsDeviceDescription) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBWindowDescription_construct( const DFBWindowDescription *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();

     obj->Set( v8::String::NewSymbol( "flags" ), v8::Integer::New(src->flags) );
     obj->Set( v8::String::NewSymbol( "caps" ), v8::Integer::New(src->caps) );
     obj->Set( v8::String::NewSymbol( "width" ), v8::Integer::New(src->width) );
     obj->Set( v8::String::NewSymbol( "height" ), v8::Integer::New(src->height) );
     obj->Set( v8::String::NewSymbol( "pixelformat" ), v8::Integer::New(src->pixelformat) );
     obj->Set( v8::String::NewSymbol( "posx" ), v8::Integer::New(src->posx) );
     obj->Set( v8::String::NewSymbol( "posy" ), v8::Integer::New(src->posy) );
     obj->Set( v8::String::NewSymbol( "surface_caps" ), v8::Integer::New(src->surface_caps) );
     obj->Set( v8::String::NewSymbol( "parent_id" ), v8::Integer::New(src->parent_id) );
     obj->Set( v8::String::NewSymbol( "options" ), v8::Integer::New(src->options) );
     obj->Set( v8::String::NewSymbol( "stacking" ), v8::Integer::New(src->stacking) );
     obj->Set( v8::String::NewSymbol( "resource_id" ), v8::Integer::New(src->resource_id) );

     return obj;
}

void
DFBWindowDescription_read( DFBWindowDescription *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBWindowDescription) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

     dst->flags = (DFBWindowDescriptionFlags) obj->Get( v8::String::NewSymbol("flags") )->IntegerValue();
     dst->caps = (DFBWindowCapabilities) obj->Get( v8::String::NewSymbol("caps") )->IntegerValue();
     dst->width = (int) obj->Get( v8::String::NewSymbol("width") )->IntegerValue();
     dst->height = (int) obj->Get( v8::String::NewSymbol("height") )->IntegerValue();
     dst->pixelformat = (DFBSurfacePixelFormat) obj->Get( v8::String::NewSymbol("pixelformat") )->IntegerValue();
     dst->posx = (int) obj->Get( v8::String::NewSymbol("posx") )->IntegerValue();
     dst->posy = (int) obj->Get( v8::String::NewSymbol("posy") )->IntegerValue();
     dst->surface_caps = (DFBSurfaceCapabilities) obj->Get( v8::String::NewSymbol("surface_caps") )->IntegerValue();
     dst->parent_id = (DFBWindowID) obj->Get( v8::String::NewSymbol("parent_id") )->IntegerValue();
     dst->options = (DFBWindowOptions) obj->Get( v8::String::NewSymbol("options") )->IntegerValue();
     dst->stacking = (DFBWindowStackingClass) obj->Get( v8::String::NewSymbol("stacking") )->IntegerValue();
     dst->resource_id = (unsigned long) obj->Get( v8::String::NewSymbol("resource_id") )->IntegerValue();
}

v8::Handle<v8::Object>
DFBDataBufferDescription_construct( const DFBDataBufferDescription *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBDataBufferDescription_read( DFBDataBufferDescription *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBDataBufferDescription) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBColorAdjustment_construct( const DFBColorAdjustment *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBColorAdjustment_read( DFBColorAdjustment *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBColorAdjustment) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBDisplayLayerConfig_construct( const DFBDisplayLayerConfig *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBDisplayLayerConfig_read( DFBDisplayLayerConfig *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBDisplayLayerConfig) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBScreenMixerDescription_construct( const DFBScreenMixerDescription *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBScreenMixerDescription_read( DFBScreenMixerDescription *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBScreenMixerDescription) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBScreenMixerConfig_construct( const DFBScreenMixerConfig *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBScreenMixerConfig_read( DFBScreenMixerConfig *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBScreenMixerConfig) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBScreenOutputDescription_construct( const DFBScreenOutputDescription *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBScreenOutputDescription_read( DFBScreenOutputDescription *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBScreenOutputDescription) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBScreenOutputConfig_construct( const DFBScreenOutputConfig *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBScreenOutputConfig_read( DFBScreenOutputConfig *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBScreenOutputConfig) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBScreenEncoderDescription_construct( const DFBScreenEncoderDescription *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBScreenEncoderDescription_read( DFBScreenEncoderDescription *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBScreenEncoderDescription) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBScreenEncoderConfig_construct( const DFBScreenEncoderConfig *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBScreenEncoderConfig_read( DFBScreenEncoderConfig *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBScreenEncoderConfig) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBVertex_construct( const DFBVertex *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBVertex_read( DFBVertex *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBVertex) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBInputEvent_construct( const DFBInputEvent *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBInputEvent_read( DFBInputEvent *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBInputEvent) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBWindowEvent_construct( const DFBWindowEvent *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();

     obj->Set( v8::String::NewSymbol( "clazz" ), v8::Integer::New(src->clazz) );
     obj->Set( v8::String::NewSymbol( "type" ), v8::Integer::New( src->type ) );
     obj->Set( v8::String::NewSymbol( "flags" ), v8::Integer::New( src->flags ) );
     obj->Set( v8::String::NewSymbol( "window_id" ), v8::Integer::New( src->window_id ) );
     obj->Set( v8::String::NewSymbol( "x" ),v8::Integer::New( src->x ) );
     obj->Set( v8::String::NewSymbol( "y" ), v8::Integer::New( src->y ) );
     obj->Set( v8::String::NewSymbol( "cx" ),v8::Integer::New( src->cx ) );
     obj->Set( v8::String::NewSymbol( "cy" ), v8::Integer::New( src->cy ) );
     obj->Set( v8::String::NewSymbol( "step" ),v8::Integer::New( src->step ) );
     obj->Set( v8::String::NewSymbol( "w" ), v8::Integer::New( src->w ) );
     obj->Set( v8::String::NewSymbol( "h" ),v8::Integer::New( src->h ) );
     obj->Set( v8::String::NewSymbol( "key_code" ), v8::Integer::New( src->key_code ) );
     obj->Set( v8::String::NewSymbol( "key_id" ), v8::Integer::New( src->key_id ) );
     obj->Set( v8::String::NewSymbol( "key_symbol" ), v8::Integer::New( src->key_symbol ) );
     obj->Set( v8::String::NewSymbol( "modifiers" ), v8::Integer::New( src->modifiers ) );
     obj->Set( v8::String::NewSymbol( "locks" ), v8::Integer::New( src->locks ) );
     obj->Set( v8::String::NewSymbol( "button" ), v8::Integer::New( src->button ) );
     obj->Set( v8::String::NewSymbol( "buttons" ), v8::Integer::New( src->buttons ) );
  //   obj->Set( v8::String::NewSymbol( "timestamp" ), v8::Integer::New( src->timestamp ) );


//     struct timeval                  timestamp;  /* always set */


     return obj;
}

void
DFBWindowEvent_read( DFBWindowEvent *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBWindowEvent) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBVideoProviderEvent_construct( const DFBVideoProviderEvent *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBVideoProviderEvent_read( DFBVideoProviderEvent *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBVideoProviderEvent) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBUserEvent_construct( const DFBUserEvent *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBUserEvent_read( DFBUserEvent *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBUserEvent) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBUniversalEvent_construct( const DFBUniversalEvent *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBUniversalEvent_read( DFBUniversalEvent *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBUniversalEvent) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBEvent_construct( const DFBEvent *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();

     obj->Set( v8::String::NewSymbol( "clazz" ), v8::Integer::New(src->clazz) );
     obj->Set( v8::String::NewSymbol( "input" ), DFBInputEvent_construct( &src->input ) );
     obj->Set( v8::String::NewSymbol( "window" ), DFBWindowEvent_construct( &src->window ) );
     obj->Set( v8::String::NewSymbol( "user" ), DFBUserEvent_construct( &src->user ) );
     obj->Set( v8::String::NewSymbol( "universal" ), DFBUniversalEvent_construct( &src->universal ) );
     obj->Set( v8::String::NewSymbol( "videoprovider" ), DFBVideoProviderEvent_construct( &src->videoprovider ) );
/*
     switch (src->clazz) {
          case DFEC_INPUT:
                obj->Set( v8::String::NewSymbol( "input" ), DFBInputEvent_construct( &src->input ) );
               break;

          case DFEC_WINDOW:
               obj->Set( v8::String::NewSymbol( "window" ), DFBWindowEvent_construct( &src->window ) );
               break;

          case DFEC_USER:
               obj->Set( v8::String::NewSymbol( "user" ), DFBUserEvent_construct( &src->user ) );
               break;

          case DFEC_VIDEOPROVIDER:
               obj->Set( v8::String::NewSymbol( "videoprovider" ), DFBVideoProviderEvent_construct( &src->videoprovider ) );
               break;

          case DFEC_UNIVERSAL:
               obj->Set( v8::String::NewSymbol( "universal" ), DFBUniversalEvent_construct( &src->universal ) );
               break;

          default:
				break;
              // D_BUG("unknown event class");
     }
	*/ 
     return obj;
}

void
DFBEvent_read( DFBEvent *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBEvent) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

     dst->clazz = (DFBEventClass) obj->Get( v8::String::NewSymbol("clazz") )->IntegerValue();
     DFBInputEvent_read( &dst->input, obj->Get( v8::String::NewSymbol("input") )->ToObject() );
     DFBWindowEvent_read( &dst->window, obj->Get( v8::String::NewSymbol("window") )->ToObject() );
     DFBUserEvent_read( &dst->user, obj->Get( v8::String::NewSymbol("user") )->ToObject() );
     DFBUniversalEvent_read( &dst->universal, obj->Get( v8::String::NewSymbol("universal") )->ToObject() );
     DFBVideoProviderEvent_read( &dst->videoprovider, obj->Get( v8::String::NewSymbol("videoprovider") )->ToObject() );
}

v8::Handle<v8::Object>
DFBEventBufferStats_construct( const DFBEventBufferStats *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBEventBufferStats_read( DFBEventBufferStats *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBEventBufferStats) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBWindowGeometry_construct( const DFBWindowGeometry *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBWindowGeometry_read( DFBWindowGeometry *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBWindowGeometry) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBImageDescription_construct( const DFBImageDescription *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBImageDescription_read( DFBImageDescription *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBImageDescription) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBStreamDescription_construct( const DFBStreamDescription *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBStreamDescription_read( DFBStreamDescription *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBStreamDescription) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBStreamAttributes_construct( const DFBStreamAttributes *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBStreamAttributes_read( DFBStreamAttributes *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBStreamAttributes) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBBufferOccupancy_construct( const DFBBufferOccupancy *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBBufferOccupancy_read( DFBBufferOccupancy *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBBufferOccupancy) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBBufferThresholds_construct( const DFBBufferThresholds *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBBufferThresholds_read( DFBBufferThresholds *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBBufferThresholds) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBGLAttributes_construct( const DFBGLAttributes *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBGLAttributes_read( DFBGLAttributes *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBGLAttributes) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

v8::Handle<v8::Object>
DFBUpdates_construct( const DFBUpdates *src )
{
     v8::Handle<v8::Object> obj = v8::Object::New();


     return obj;
}

void
DFBUpdates_read( DFBUpdates *dst, v8::Handle<v8::Value> src )
{
     if (src.IsEmpty()) { memset( dst, 0, sizeof(DFBUpdates) ); return; }

     v8::Handle<v8::Object> obj = src->ToObject();

}

}
