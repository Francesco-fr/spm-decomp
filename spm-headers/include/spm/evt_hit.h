#pragma once

#include <common.h>
#include <evt_cmd.h>
#include <spm/hitdrv.h>

CPP_WRAPPER(spm::evt_hit)

USING(spm::hitdrv::HitObj)

EVT_UNKNOWN_USER_FUNC(func_800eab1c)
EVT_UNKNOWN_USER_FUNC(func_800eabb8)

// evt_hitobj_onoff(const char * name, s32 group, bool on)
EVT_DECLARE_USER_FUNC(evt_hitobj_onoff, 3)

EVT_UNKNOWN_USER_FUNC(func_800ead20)
EVT_UNKNOWN_USER_FUNC(func_800eadec)
// Sets unknown_0xe2 on a HitObj, its children and its siblings
void func_800eaed0(HitObj * hitObj, s32 value);
EVT_UNKNOWN_USER_FUNC(func_800eb15c)

// evt_hit_bind_mapobj(const char * hit_name, const char * map_name)
EVT_DECLARE_USER_FUNC(evt_hit_bind_mapobj, 2)

// evt_hit_bind_update(const char * hit_name)
EVT_DECLARE_USER_FUNC(evt_hit_bind_update, 1)

// evt_hitobj_get_pos(const char * hit_name, f32 x, f32 y, f32 z)
// Same address as evt_hitobj_get_pos (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800eb564)
EVT_DECLARE_USER_FUNC(evt_hitobj_get_pos, 4)

EVT_UNKNOWN_USER_FUNC(func_800eb5dc)
EVT_UNKNOWN_USER_FUNC(func_800eb654)

// evt_hitobj_attr_onoff(s32 group, bool on, const char * name, u32 mask)
EVT_DECLARE_USER_FUNC(evt_hitobj_attr_onoff, 4)

EVT_UNKNOWN_USER_FUNC(func_800eb7f4)
// Checks whether a HitObj or any of its children / siblings has the given name
bool func_800eb8bc(const char * name, HitObj * hitObj);
EVT_UNKNOWN_USER_FUNC(func_800ebd74)

CPP_WRAPPER_END()
