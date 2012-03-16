#include "common.h"

#include "templates.h"

namespace DirectFB {

static v8::Persistent<v8::ObjectTemplate>  m_IDirectFBSurface;

/**********************************************************************************************************************/

static v8::Handle<v8::Value>
IDirectFBSurface_GetCapabilities( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBSurfaceCapabilities ret_caps;

     V8_DIRECTFB_CALL( thiz->GetCapabilities( thiz, &ret_caps ) );

     return v8::Integer::New( ret_caps );
}

static v8::Handle<v8::Value>
IDirectFBSurface_GetPosition( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int ret_x;

     int ret_y;

     V8_DIRECTFB_CALL( thiz->GetPosition( thiz, &ret_x, &ret_y ) );
     #warning unimplemented (second output)

     return v8::Integer::New( ret_x );
}

static v8::Handle<v8::Value>
IDirectFBSurface_GetSize( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int ret_width;

     int ret_height;

     V8_DIRECTFB_CALL( thiz->GetSize( thiz, &ret_width, &ret_height ) );
     #warning unimplemented (second output)

     return v8::Integer::New( ret_width );
}

static v8::Handle<v8::Value>
IDirectFBSurface_GetVisibleRectangle( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBRectangle ret_rect;

     V8_DIRECTFB_CALL( thiz->GetVisibleRectangle( thiz, &ret_rect ) );

     return DFBRectangle_construct( &ret_rect );
}

static v8::Handle<v8::Value>
IDirectFBSurface_GetPixelFormat( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBSurfacePixelFormat ret_format;

     V8_DIRECTFB_CALL( thiz->GetPixelFormat( thiz, &ret_format ) );

     return v8::Integer::New( ret_format );
}

static v8::Handle<v8::Value>
IDirectFBSurface_GetAccelerationMask( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBSurface *source = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBSurface );

     DFBAccelerationMask ret_mask;

     V8_DIRECTFB_CALL( thiz->GetAccelerationMask( thiz, source, &ret_mask ) );

     return v8::Integer::New( ret_mask );
}

static v8::Handle<v8::Value>
IDirectFBSurface_GetPalette( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBPalette *ret_interface;

     V8_DIRECTFB_CALL( thiz->GetPalette( thiz, &ret_interface ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBPalette_template();

     return Construct( templ, ret_interface );
}

static v8::Handle<v8::Value>
IDirectFBSurface_SetPalette( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBPalette *palette = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBPalette );

     V8_DIRECTFB_CALL( thiz->SetPalette( thiz, palette ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_SetAlphaRamp( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     u8 a0 = (u8) args[0]->IntegerValue();

     u8 a1 = (u8) args[1]->IntegerValue();

     u8 a2 = (u8) args[2]->IntegerValue();

     u8 a3 = (u8) args[3]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetAlphaRamp( thiz, a0, a1, a2, a3 ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_Lock( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBSurfaceLockFlags flags = (DFBSurfaceLockFlags) args[0]->IntegerValue();

     void *ret_ptr;
     #warning unimplemented (return pointer)
     D_UNIMPLEMENTED();

     int ret_pitch;

     V8_DIRECTFB_CALL( thiz->Lock( thiz, flags, &ret_ptr, &ret_pitch ) );

     return v8::Integer::New( ret_pitch );
}

static v8::Handle<v8::Value>
IDirectFBSurface_GetFramebufferOffset( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int offset;

     V8_DIRECTFB_CALL( thiz->GetFramebufferOffset( thiz, &offset ) );

     return v8::Integer::New( offset );
}

static v8::Handle<v8::Value>
IDirectFBSurface_Unlock( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->Unlock( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_Flip( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBRegion *_region = NULL;
     DFBRegion region;
     if (args[0]->IsObject()) {
          DFBRegion_read( &region, args[0] );
          _region = &region;
     }

     DFBSurfaceFlipFlags flags = (DFBSurfaceFlipFlags) args[1]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->Flip( thiz, _region, flags ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_SetField( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int field = (int) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetField( thiz, field ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_Clear( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     u8 r = (u8) args[0]->IntegerValue();

     u8 g = (u8) args[1]->IntegerValue();

     u8 b = (u8) args[2]->IntegerValue();

     u8 a = (u8) args[3]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->Clear( thiz, r, g, b, a ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_SetClip( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBRegion *_clip = NULL;
     DFBRegion clip;
     if (args[0]->IsObject()) {
          DFBRegion_read( &clip, args[0] );
          _clip = &clip;
     }

     V8_DIRECTFB_CALL( thiz->SetClip( thiz, _clip ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_GetClip( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBRegion ret_clip;

     V8_DIRECTFB_CALL( thiz->GetClip( thiz, &ret_clip ) );

     return DFBRegion_construct( &ret_clip );
}

static v8::Handle<v8::Value>
IDirectFBSurface_SetColor( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     u8 r = (u8) args[0]->IntegerValue();

     u8 g = (u8) args[1]->IntegerValue();

     u8 b = (u8) args[2]->IntegerValue();

     u8 a = (u8) args[3]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetColor( thiz, r, g, b, a ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_SetColorIndex( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     unsigned int index = (unsigned int) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetColorIndex( thiz, index ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_SetSrcBlendFunction( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBSurfaceBlendFunction function = (DFBSurfaceBlendFunction) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetSrcBlendFunction( thiz, function ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_SetDstBlendFunction( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBSurfaceBlendFunction function = (DFBSurfaceBlendFunction) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetDstBlendFunction( thiz, function ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_SetPorterDuff( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBSurfacePorterDuffRule rule = (DFBSurfacePorterDuffRule) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetPorterDuff( thiz, rule ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_SetSrcColorKey( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     u8 r = (u8) args[0]->IntegerValue();

     u8 g = (u8) args[1]->IntegerValue();

     u8 b = (u8) args[2]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetSrcColorKey( thiz, r, g, b ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_SetSrcColorKeyIndex( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     unsigned int index = (unsigned int) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetSrcColorKeyIndex( thiz, index ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_SetDstColorKey( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     u8 r = (u8) args[0]->IntegerValue();

     u8 g = (u8) args[1]->IntegerValue();

     u8 b = (u8) args[2]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetDstColorKey( thiz, r, g, b ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_SetDstColorKeyIndex( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     unsigned int index = (unsigned int) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetDstColorKeyIndex( thiz, index ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_SetBlittingFlags( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBSurfaceBlittingFlags flags = (DFBSurfaceBlittingFlags) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetBlittingFlags( thiz, flags ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_Blit( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBSurface *source = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBSurface );

     DFBRectangle *_source_rect = NULL;
     DFBRectangle source_rect;
     if (args[1]->IsObject()) {
          DFBRectangle_read( &source_rect, args[1] );
          _source_rect = &source_rect;
     }

     int x = (int) args[2]->IntegerValue();

     int y = (int) args[3]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->Blit( thiz, source, _source_rect, x, y ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_TileBlit( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBSurface *source = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBSurface );

     DFBRectangle *_source_rect = NULL;
     DFBRectangle source_rect;
     if (args[1]->IsObject()) {
          DFBRectangle_read( &source_rect, args[1] );
          _source_rect = &source_rect;
     }

     int x = (int) args[2]->IntegerValue();

     int y = (int) args[3]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->TileBlit( thiz, source, _source_rect, x, y ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_BatchBlit( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBSurface *source = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBSurface );

     DFBRectangle *_source_rects = NULL;
     DFBRectangle source_rects;
     if (args[1]->IsObject()) {
          DFBRectangle_read( &source_rects, args[1] );
          _source_rects = &source_rects;
     }

     DFBPoint *_dest_points = NULL;
     DFBPoint dest_points;
     if (args[2]->IsObject()) {
          DFBPoint_read( &dest_points, args[2] );
          _dest_points = &dest_points;
     }

     int num = (int) args[3]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->BatchBlit( thiz, source, _source_rects, _dest_points, num ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_StretchBlit( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBSurface *source = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBSurface );

     DFBRectangle *_source_rect = NULL;
     DFBRectangle source_rect;
     if (args[1]->IsObject()) {
          DFBRectangle_read( &source_rect, args[1] );
          _source_rect = &source_rect;
     }

     DFBRectangle *_destination_rect = NULL;
     DFBRectangle destination_rect;
     if (args[2]->IsObject()) {
          DFBRectangle_read( &destination_rect, args[2] );
          _destination_rect = &destination_rect;
     }

     V8_DIRECTFB_CALL( thiz->StretchBlit( thiz, source, _source_rect, _destination_rect ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_TextureTriangles( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBSurface *texture = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBSurface );

     DFBVertex *_vertices = NULL;
     DFBVertex vertices;
     if (args[1]->IsObject()) {
          DFBVertex_read( &vertices, args[1] );
          _vertices = &vertices;
     }

     int indices;
     #warning unimplemented (array input?)
     D_UNIMPLEMENTED();

     int num = (int) args[3]->IntegerValue();

     DFBTriangleFormation formation = (DFBTriangleFormation) args[4]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->TextureTriangles( thiz, texture, _vertices, &indices, num, formation ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_SetDrawingFlags( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBSurfaceDrawingFlags flags = (DFBSurfaceDrawingFlags) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetDrawingFlags( thiz, flags ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_FillRectangle( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int x = (int) args[0]->IntegerValue();

     int y = (int) args[1]->IntegerValue();

     int w = (int) args[2]->IntegerValue();

     int h = (int) args[3]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->FillRectangle( thiz, x, y, w, h ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_DrawRectangle( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int x = (int) args[0]->IntegerValue();

     int y = (int) args[1]->IntegerValue();

     int w = (int) args[2]->IntegerValue();

     int h = (int) args[3]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->DrawRectangle( thiz, x, y, w, h ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_DrawLine( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int x1 = (int) args[0]->IntegerValue();

     int y1 = (int) args[1]->IntegerValue();

     int x2 = (int) args[2]->IntegerValue();

     int y2 = (int) args[3]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->DrawLine( thiz, x1, y1, x2, y2 ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_DrawLines( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBRegion *_lines = NULL;
     DFBRegion lines;
     if (args[0]->IsObject()) {
          DFBRegion_read( &lines, args[0] );
          _lines = &lines;
     }

     unsigned int num_lines = (unsigned int) args[1]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->DrawLines( thiz, _lines, num_lines ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_FillTriangle( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int x1 = (int) args[0]->IntegerValue();

     int y1 = (int) args[1]->IntegerValue();

     int x2 = (int) args[2]->IntegerValue();

     int y2 = (int) args[3]->IntegerValue();

     int x3 = (int) args[4]->IntegerValue();

     int y3 = (int) args[5]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->FillTriangle( thiz, x1, y1, x2, y2, x3, y3 ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_FillRectangles( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBRectangle *_rects = NULL;
     DFBRectangle rects;
     if (args[0]->IsObject()) {
          DFBRectangle_read( &rects, args[0] );
          _rects = &rects;
     }

     unsigned int num = (unsigned int) args[1]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->FillRectangles( thiz, _rects, num ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_FillSpans( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int y = (int) args[0]->IntegerValue();

     DFBSpan *_spans = NULL;
     DFBSpan spans;
     if (args[1]->IsObject()) {
          DFBSpan_read( &spans, args[1] );
          _spans = &spans;
     }

     unsigned int num = (unsigned int) args[2]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->FillSpans( thiz, y, _spans, num ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_FillTriangles( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBTriangle *_tris = NULL;
     DFBTriangle tris;
     if (args[0]->IsObject()) {
          DFBTriangle_read( &tris, args[0] );
          _tris = &tris;
     }

     unsigned int num = (unsigned int) args[1]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->FillTriangles( thiz, _tris, num ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_SetFont( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBFont *font = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBFont );

     V8_DIRECTFB_CALL( thiz->SetFont( thiz, font ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_GetFont( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBFont *ret_font;

     V8_DIRECTFB_CALL( thiz->GetFont( thiz, &ret_font ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBFont_template();

     return Construct( templ, ret_font );
}

static v8::Handle<v8::Value>
IDirectFBSurface_DrawString( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     const char *text = NULL;
     v8::String::Utf8Value utf8_text(args[0]);
     text = *utf8_text;

     int bytes = (int) args[1]->IntegerValue();

     int x = (int) args[2]->IntegerValue();

     int y = (int) args[3]->IntegerValue();

     DFBSurfaceTextFlags flags = (DFBSurfaceTextFlags) args[4]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->DrawString( thiz, text, bytes, x, y, flags ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_DrawGlyph( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     unsigned int character = (unsigned int) args[0]->IntegerValue();

     int x = (int) args[1]->IntegerValue();

     int y = (int) args[2]->IntegerValue();

     DFBSurfaceTextFlags flags = (DFBSurfaceTextFlags) args[3]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->DrawGlyph( thiz, character, x, y, flags ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_SetEncoding( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBTextEncodingID encoding = (DFBTextEncodingID) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetEncoding( thiz, encoding ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_GetSubSurface( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBRectangle *_rect = NULL;
     DFBRectangle rect;
     if (args[0]->IsObject()) {
          DFBRectangle_read( &rect, args[0] );
          _rect = &rect;
     }

     IDirectFBSurface *ret_interface;

     V8_DIRECTFB_CALL( thiz->GetSubSurface( thiz, _rect, &ret_interface ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBSurface_template();

     return Construct( templ, ret_interface );
}

static v8::Handle<v8::Value>
IDirectFBSurface_GetGL( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBGL *ret_interface;

     V8_DIRECTFB_CALL( thiz->GetGL( thiz, &ret_interface ) );
     v8::Handle<v8::ObjectTemplate> templ = IDirectFBGL_template();

     return Construct( templ, ret_interface );
}

static v8::Handle<v8::Value>
IDirectFBSurface_Dump( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     const char *directory = NULL;
     v8::String::Utf8Value utf8_directory(args[0]);
     directory = *utf8_directory;

     const char *prefix = NULL;
     v8::String::Utf8Value utf8_prefix(args[1]);
     prefix = *utf8_prefix;

     V8_DIRECTFB_CALL( thiz->Dump( thiz, directory, prefix ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_DisableAcceleration( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBAccelerationMask mask = (DFBAccelerationMask) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->DisableAcceleration( thiz, mask ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_ReleaseSource( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     V8_DIRECTFB_CALL( thiz->ReleaseSource( thiz ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_SetIndexTranslation( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     int indices;
     #warning unimplemented (array input?)
     D_UNIMPLEMENTED();

     int num_indices = (int) args[1]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetIndexTranslation( thiz, &indices, num_indices ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_SetRenderOptions( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBSurfaceRenderOptions options = (DFBSurfaceRenderOptions) args[0]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetRenderOptions( thiz, options ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_SetMatrix( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     s32 matrix;
     #warning unimplemented (array input?)
     D_UNIMPLEMENTED();

     V8_DIRECTFB_CALL( thiz->SetMatrix( thiz, &matrix ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_SetSourceMask( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBSurface *mask = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBSurface );

     int x = (int) args[1]->IntegerValue();

     int y = (int) args[2]->IntegerValue();

     DFBSurfaceMaskFlags flags = (DFBSurfaceMaskFlags) args[3]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->SetSourceMask( thiz, mask, x, y, flags ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_MakeSubSurface( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     IDirectFBSurface *from = V8_DIRECTFB_INTERFACE( args[0]->ToObject(), IDirectFBSurface );

     DFBRectangle *_rect = NULL;
     DFBRectangle rect;
     if (args[1]->IsObject()) {
          DFBRectangle_read( &rect, args[1] );
          _rect = &rect;
     }

     V8_DIRECTFB_CALL( thiz->MakeSubSurface( thiz, from, _rect ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_Write( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBRectangle *_rect = NULL;
     DFBRectangle rect;
     if (args[0]->IsObject()) {
          DFBRectangle_read( &rect, args[0] );
          _rect = &rect;
     }

     void *ptr;
     #warning unimplemented (buffer input)
     D_UNIMPLEMENTED();

     int pitch = (int) args[2]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->Write( thiz, _rect, ptr, pitch ) );

     return v8::Undefined();
}

static v8::Handle<v8::Value>
IDirectFBSurface_Read( const v8::Arguments& args )
{
     IDirectFBSurface *thiz = V8_DIRECTFB_INTERFACE( args.This(), IDirectFBSurface );

     if (!thiz)
          return v8::ThrowException( v8::String::New( "Interface already released" ) );


     DFBRectangle *_rect = NULL;
     DFBRectangle rect;
     if (args[0]->IsObject()) {
          DFBRectangle_read( &rect, args[0] );
          _rect = &rect;
     }

     void *ptr;
     #warning unimplemented (buffer input)
     D_UNIMPLEMENTED();

     int pitch = (int) args[2]->IntegerValue();

     V8_DIRECTFB_CALL( thiz->Read( thiz, _rect, ptr, pitch ) );

     return v8::Undefined();
}

/**********************************************************************************************************************/

v8::Handle<v8::ObjectTemplate>
IDirectFBSurface_template()
{
     if (m_IDirectFBSurface.IsEmpty()) {
          v8::HandleScope handle_scope;
          v8::Handle<v8::ObjectTemplate> templ;

          templ = v8::ObjectTemplate::New();

          templ->SetInternalFieldCount( 1 );

          templ->Set( v8::String::NewSymbol("Release"), v8::FunctionTemplate::New(IAny_release) );
          templ->Set( v8::String::NewSymbol("GetCapabilities"), v8::FunctionTemplate::New(IDirectFBSurface_GetCapabilities) );
          templ->Set( v8::String::NewSymbol("GetPosition"), v8::FunctionTemplate::New(IDirectFBSurface_GetPosition) );
          templ->Set( v8::String::NewSymbol("GetSize"), v8::FunctionTemplate::New(IDirectFBSurface_GetSize) );
          templ->Set( v8::String::NewSymbol("GetVisibleRectangle"), v8::FunctionTemplate::New(IDirectFBSurface_GetVisibleRectangle) );
          templ->Set( v8::String::NewSymbol("GetPixelFormat"), v8::FunctionTemplate::New(IDirectFBSurface_GetPixelFormat) );
          templ->Set( v8::String::NewSymbol("GetAccelerationMask"), v8::FunctionTemplate::New(IDirectFBSurface_GetAccelerationMask) );
          templ->Set( v8::String::NewSymbol("GetPalette"), v8::FunctionTemplate::New(IDirectFBSurface_GetPalette) );
          templ->Set( v8::String::NewSymbol("SetPalette"), v8::FunctionTemplate::New(IDirectFBSurface_SetPalette) );
          templ->Set( v8::String::NewSymbol("SetAlphaRamp"), v8::FunctionTemplate::New(IDirectFBSurface_SetAlphaRamp) );
          templ->Set( v8::String::NewSymbol("Lock"), v8::FunctionTemplate::New(IDirectFBSurface_Lock) );
          templ->Set( v8::String::NewSymbol("GetFramebufferOffset"), v8::FunctionTemplate::New(IDirectFBSurface_GetFramebufferOffset) );
          templ->Set( v8::String::NewSymbol("Unlock"), v8::FunctionTemplate::New(IDirectFBSurface_Unlock) );
          templ->Set( v8::String::NewSymbol("Flip"), v8::FunctionTemplate::New(IDirectFBSurface_Flip) );
          templ->Set( v8::String::NewSymbol("SetField"), v8::FunctionTemplate::New(IDirectFBSurface_SetField) );
          templ->Set( v8::String::NewSymbol("Clear"), v8::FunctionTemplate::New(IDirectFBSurface_Clear) );
          templ->Set( v8::String::NewSymbol("SetClip"), v8::FunctionTemplate::New(IDirectFBSurface_SetClip) );
          templ->Set( v8::String::NewSymbol("GetClip"), v8::FunctionTemplate::New(IDirectFBSurface_GetClip) );
          templ->Set( v8::String::NewSymbol("SetColor"), v8::FunctionTemplate::New(IDirectFBSurface_SetColor) );
          templ->Set( v8::String::NewSymbol("SetColorIndex"), v8::FunctionTemplate::New(IDirectFBSurface_SetColorIndex) );
          templ->Set( v8::String::NewSymbol("SetSrcBlendFunction"), v8::FunctionTemplate::New(IDirectFBSurface_SetSrcBlendFunction) );
          templ->Set( v8::String::NewSymbol("SetDstBlendFunction"), v8::FunctionTemplate::New(IDirectFBSurface_SetDstBlendFunction) );
          templ->Set( v8::String::NewSymbol("SetPorterDuff"), v8::FunctionTemplate::New(IDirectFBSurface_SetPorterDuff) );
          templ->Set( v8::String::NewSymbol("SetSrcColorKey"), v8::FunctionTemplate::New(IDirectFBSurface_SetSrcColorKey) );
          templ->Set( v8::String::NewSymbol("SetSrcColorKeyIndex"), v8::FunctionTemplate::New(IDirectFBSurface_SetSrcColorKeyIndex) );
          templ->Set( v8::String::NewSymbol("SetDstColorKey"), v8::FunctionTemplate::New(IDirectFBSurface_SetDstColorKey) );
          templ->Set( v8::String::NewSymbol("SetDstColorKeyIndex"), v8::FunctionTemplate::New(IDirectFBSurface_SetDstColorKeyIndex) );
          templ->Set( v8::String::NewSymbol("SetBlittingFlags"), v8::FunctionTemplate::New(IDirectFBSurface_SetBlittingFlags) );
          templ->Set( v8::String::NewSymbol("Blit"), v8::FunctionTemplate::New(IDirectFBSurface_Blit) );
          templ->Set( v8::String::NewSymbol("TileBlit"), v8::FunctionTemplate::New(IDirectFBSurface_TileBlit) );
          templ->Set( v8::String::NewSymbol("BatchBlit"), v8::FunctionTemplate::New(IDirectFBSurface_BatchBlit) );
          templ->Set( v8::String::NewSymbol("StretchBlit"), v8::FunctionTemplate::New(IDirectFBSurface_StretchBlit) );
          templ->Set( v8::String::NewSymbol("TextureTriangles"), v8::FunctionTemplate::New(IDirectFBSurface_TextureTriangles) );
          templ->Set( v8::String::NewSymbol("SetDrawingFlags"), v8::FunctionTemplate::New(IDirectFBSurface_SetDrawingFlags) );
          templ->Set( v8::String::NewSymbol("FillRectangle"), v8::FunctionTemplate::New(IDirectFBSurface_FillRectangle) );
          templ->Set( v8::String::NewSymbol("DrawRectangle"), v8::FunctionTemplate::New(IDirectFBSurface_DrawRectangle) );
          templ->Set( v8::String::NewSymbol("DrawLine"), v8::FunctionTemplate::New(IDirectFBSurface_DrawLine) );
          templ->Set( v8::String::NewSymbol("DrawLines"), v8::FunctionTemplate::New(IDirectFBSurface_DrawLines) );
          templ->Set( v8::String::NewSymbol("FillTriangle"), v8::FunctionTemplate::New(IDirectFBSurface_FillTriangle) );
          templ->Set( v8::String::NewSymbol("FillRectangles"), v8::FunctionTemplate::New(IDirectFBSurface_FillRectangles) );
          templ->Set( v8::String::NewSymbol("FillSpans"), v8::FunctionTemplate::New(IDirectFBSurface_FillSpans) );
          templ->Set( v8::String::NewSymbol("FillTriangles"), v8::FunctionTemplate::New(IDirectFBSurface_FillTriangles) );
          templ->Set( v8::String::NewSymbol("SetFont"), v8::FunctionTemplate::New(IDirectFBSurface_SetFont) );
          templ->Set( v8::String::NewSymbol("GetFont"), v8::FunctionTemplate::New(IDirectFBSurface_GetFont) );
          templ->Set( v8::String::NewSymbol("DrawString"), v8::FunctionTemplate::New(IDirectFBSurface_DrawString) );
          templ->Set( v8::String::NewSymbol("DrawGlyph"), v8::FunctionTemplate::New(IDirectFBSurface_DrawGlyph) );
          templ->Set( v8::String::NewSymbol("SetEncoding"), v8::FunctionTemplate::New(IDirectFBSurface_SetEncoding) );
          templ->Set( v8::String::NewSymbol("GetSubSurface"), v8::FunctionTemplate::New(IDirectFBSurface_GetSubSurface) );
          templ->Set( v8::String::NewSymbol("GetGL"), v8::FunctionTemplate::New(IDirectFBSurface_GetGL) );
          templ->Set( v8::String::NewSymbol("Dump"), v8::FunctionTemplate::New(IDirectFBSurface_Dump) );
          templ->Set( v8::String::NewSymbol("DisableAcceleration"), v8::FunctionTemplate::New(IDirectFBSurface_DisableAcceleration) );
          templ->Set( v8::String::NewSymbol("ReleaseSource"), v8::FunctionTemplate::New(IDirectFBSurface_ReleaseSource) );
          templ->Set( v8::String::NewSymbol("SetIndexTranslation"), v8::FunctionTemplate::New(IDirectFBSurface_SetIndexTranslation) );
          templ->Set( v8::String::NewSymbol("SetRenderOptions"), v8::FunctionTemplate::New(IDirectFBSurface_SetRenderOptions) );
          templ->Set( v8::String::NewSymbol("SetMatrix"), v8::FunctionTemplate::New(IDirectFBSurface_SetMatrix) );
          templ->Set( v8::String::NewSymbol("SetSourceMask"), v8::FunctionTemplate::New(IDirectFBSurface_SetSourceMask) );
          templ->Set( v8::String::NewSymbol("MakeSubSurface"), v8::FunctionTemplate::New(IDirectFBSurface_MakeSubSurface) );
          templ->Set( v8::String::NewSymbol("Write"), v8::FunctionTemplate::New(IDirectFBSurface_Write) );
          templ->Set( v8::String::NewSymbol("Read"), v8::FunctionTemplate::New(IDirectFBSurface_Read) );

          m_IDirectFBSurface = v8::Persistent<v8::ObjectTemplate>::New( handle_scope.Close( templ ) );
     }

     return m_IDirectFBSurface;
}

}
