#pragma once

#include <common.h>
#include <evt_cmd.h>
#include <spm/hitdrv.h>
#include <spm/winmgr.h>

CPP_WRAPPER(spm::evt_sub)

USING(spm::hitdrv::HitObj)
USING(spm::winmgr::WinmgrEntry)

EVT_UNKNOWN_USER_FUNC(func_800d378c)
EVT_DECLARE_USER_FUNC(evt_sub_intpl_msec_init, 4)
EVT_DECLARE_USER_FUNC(evt_sub_intpl_msec_get_value, 0)
EVT_UNKNOWN_USER_FUNC(evt_sub_intpl_msec_get_value_para)
EVT_UNKNOWN_USER_FUNC(evt_sub_spline_init)
EVT_UNKNOWN_USER_FUNC(evt_sub_spline_get_value)
EVT_UNKNOWN_USER_FUNC(evt_sub_spline_get_value_manual)
EVT_UNKNOWN_USER_FUNC(evt_sub_spline_free)
EVT_UNKNOWN_USER_FUNC(evt_sub_get_sincos)
EVT_UNKNOWN_USER_FUNC(evt_sub_rumble_onoff)

// Gives a random number from 0 to max (inclusive)
// evt_sub_random(s32 max, s32& ret)
EVT_DECLARE_USER_FUNC(evt_sub_random, 2)

EVT_UNKNOWN_USER_FUNC(evt_sub_get_stopwatch)
EVT_UNKNOWN_USER_FUNC(func_800d41a8)
EVT_DECLARE_USER_FUNC(evt_sub_get_dist, 5)
EVT_UNKNOWN_USER_FUNC(evt_sub_get_dir)
EVT_UNKNOWN_USER_FUNC(evt_sub_get_system_flag)
EVT_UNKNOWN_USER_FUNC(func_800d4460)
EVT_DECLARE_USER_FUNC(evt_key_get_button, 2)
EVT_UNKNOWN_USER_FUNC(evt_key_get_buttonrep)
EVT_UNKNOWN_USER_FUNC(evt_key_get_buttontrg)
void func_800d45ac(s32 chan, s32 result);
EVT_UNKNOWN_USER_FUNC(func_800d45dc)
EVT_UNKNOWN_USER_FUNC(func_800d46a4)

//evt_sub_set_game_speed(float newSpeed)
// Same address as evt_sub_set_game_speed (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800d46d8)
EVT_DECLARE_USER_FUNC(evt_sub_set_game_speed, 1)

EVT_DECLARE_USER_FUNC(evt_sub_get_mapname, -1)


// Returns the door/bero name
// evt_sub_get_entername(&char* ret)
EVT_DECLARE_USER_FUNC(evt_sub_get_entername, 1)

EVT_UNKNOWN_USER_FUNC(evt_sub_set_entername)
EVT_UNKNOWN_USER_FUNC(func_800d47e4)
EVT_DECLARE_USER_FUNC(evt_sub_get_language, 1)

// evt_sub_animgroup_async(const char * name)
EVT_DECLARE_USER_FUNC(evt_sub_animgroup_async, 1)

EVT_UNKNOWN_USER_FUNC(evt_sub_file_async)
EVT_UNKNOWN_USER_FUNC(evt_sub_load_mapdata_bin)
EVT_UNKNOWN_USER_FUNC(evt_sub_get_fps)
EVT_UNKNOWN_USER_FUNC(evt_sub_fmt_str_int)
s32 func_800d4b4c(void * param, HitObj * hit);
EVT_UNKNOWN_USER_FUNC(func_800d4b60)
EVT_DECLARE_USER_FUNC(evt_sub_hud_configure, 1)
EVT_UNKNOWN_USER_FUNC(func_800d4db0)
EVT_DECLARE_USER_FUNC(func_800d4de4, 2)
EVT_UNKNOWN_USER_FUNC(func_800d4e48)
void func_800d5004(s32 cameraId, void * param);
void func_800d52a8(s32 cameraId, void * param);
EVT_UNKNOWN_USER_FUNC(func_800d5588)
EVT_UNKNOWN_USER_FUNC(func_800d59ac)
EVT_UNKNOWN_USER_FUNC(func_800d59f0)
EVT_UNKNOWN_USER_FUNC(func_800d5a24)
EVT_UNKNOWN_USER_FUNC(func_800d5a60)
EVT_UNKNOWN_USER_FUNC(func_800d5a94)
EVT_UNKNOWN_USER_FUNC(func_800d5acc)
EVT_UNKNOWN_USER_FUNC(func_800d5e80)
EVT_UNKNOWN_USER_FUNC(func_800d6148)
EVT_UNKNOWN_USER_FUNC(func_800d61ac)
EVT_UNKNOWN_USER_FUNC(func_800d6230)
EVT_UNKNOWN_USER_FUNC(func_800d6298)
EVT_UNKNOWN_USER_FUNC(func_800d6308)
EVT_UNKNOWN_USER_FUNC(func_800d6644)
void func_800d6674(s32 cameraId, void * param);
EVT_DECLARE_USER_FUNC(evt_sub_display_room_name, 2)
EVT_UNKNOWN_USER_FUNC(func_800d776c)
EVT_UNKNOWN_USER_FUNC(func_800d7858)
EVT_UNKNOWN_USER_FUNC(evt_sub_get_save_name)
EVT_UNKNOWN_USER_FUNC(evt_zero_vector)

EVT_DECLARE_USER_FUNC(evt_sub_item_select_menu, 4)

void func_800d7b9c(WinmgrEntry * entry);
void func_800d7e70(WinmgrEntry * entry);
void func_800d815c(WinmgrEntry * entry);
EVT_UNKNOWN_USER_FUNC(func_800d8498)

EVT_DECLARE_USER_FUNC(func_800d8700, 1)

EVT_UNKNOWN_USER_FUNC(evt_sub_zero_vector)

CPP_WRAPPER_END()
