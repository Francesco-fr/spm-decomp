#pragma once

#include <common.h>
#include <evt_cmd.h>
#include <spm/mapdrv.h>

CPP_WRAPPER(spm::evt_map)

USING(spm::mapdrv::MapObj)

// evt_mapobj_trans(const char * name, s32 x, s32 y, s32 z)
EVT_DECLARE_USER_FUNC(evt_mapobj_trans, 4)

EVT_UNKNOWN_USER_FUNC(evt_mapobj_rotate)
EVT_DECLARE_USER_FUNC(evt_mapobj_scale, 4)
// Same address as evt_mapobj_scale (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800ed7f8)
EVT_UNKNOWN_USER_FUNC(evt_map_set_fog)
EVT_UNKNOWN_USER_FUNC(evt_map_fog_onoff)
EVT_DECLARE_USER_FUNC(evt_map_set_blend, 5)
// Same address as evt_map_set_blend (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800ed9b0)
EVT_UNKNOWN_USER_FUNC(func_800eda74)
EVT_UNKNOWN_USER_FUNC(func_800edab4)

// evt_mapobj_color(s32 group, const char * name, u8 r, u8 g, u8 b, u8 a)
EVT_DECLARE_USER_FUNC(evt_mapobj_color, 6)

EVT_DECLARE_USER_FUNC(evt_map_playanim, 3)

EVT_UNKNOWN_USER_FUNC(func_800edca8)

EVT_DECLARE_USER_FUNC(evt_map_checkanim, 3)

EVT_UNKNOWN_USER_FUNC(func_800edd50)
EVT_UNKNOWN_USER_FUNC(func_800eddb4)
EVT_UNKNOWN_USER_FUNC(evt_map_set_playrate)
EVT_UNKNOWN_USER_FUNC(func_800ede70)
EVT_UNKNOWN_USER_FUNC(func_800edec8)

// evt_mapobj_flag_onoff(s32 group, bool on, const char * name, u32 mask)
EVT_DECLARE_USER_FUNC(evt_mapobj_flag_onoff, 4)

// evt_mapobj_flag4_onoff(s32 group, bool on, const char * name, u32 mask)
EVT_DECLARE_USER_FUNC(evt_mapobj_flag4_onoff, 4)

EVT_UNKNOWN_USER_FUNC(func_800ee0b4)
EVT_UNKNOWN_USER_FUNC(func_800ee13c)

// evt_mapobj_get_position(const char * name, f32& x, f32& y, f32& z)
EVT_DECLARE_USER_FUNC(evt_mapobj_get_position, 4)

// Sets unknown_0x140 on a MapObj, its children and siblings
void func_800ee290(MapObj * obj, s32 value);
EVT_UNKNOWN_USER_FUNC(func_800ee51c)

EVT_DECLARE_USER_FUNC(evt_mapdisp_onoff, 1)

// Sets blendMode on a MapObj, its children and optionally its siblings
void func_800ee59c(MapObj * obj, s32 blendMode, bool noSiblings);
EVT_UNKNOWN_USER_FUNC(evt_mapobj_blendmode)
// Sets unknown_0x9 on a MapObj, its children and optionally its siblings
void func_800ee9f4(MapObj * obj, s32 value, bool noSiblings);
EVT_UNKNOWN_USER_FUNC(func_800eec8c)
UNKNOWN_FUNCTION(func_800eee68)
EVT_DECLARE_USER_FUNC(evt_map_spawn_ladder, 8)
// Same address as evt_map_spawn_ladder (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800ef198)

CPP_WRAPPER_END()
