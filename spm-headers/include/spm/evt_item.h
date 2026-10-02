#pragma once

#include <common.h>
#include <evt_cmd.h>

CPP_WRAPPER(spm::evt_item)

EVT_DECLARE_USER_FUNC(evt_item_event_free_work, 0)

EVT_UNKNOWN_USER_FUNC(evt_item_entry)
EVT_UNKNOWN_USER_FUNC(func_800ecd70)

// evt_item_get_position(const char* name, f32 x, f32 y, f32 z)
EVT_DECLARE_USER_FUNC(evt_item_get_position, 4)

// evt_item_set_position(const char* name, f32 x, f32 y, f32 z)
EVT_DECLARE_USER_FUNC(evt_item_set_position, 4)

EVT_UNKNOWN_USER_FUNC(evt_item_flag_onoff)
EVT_UNKNOWN_USER_FUNC(func_800ecf80)
EVT_UNKNOWN_USER_FUNC(func_800ed020)
EVT_UNKNOWN_USER_FUNC(func_800ed0bc)

// evt_item_wait_collected(const char *name)
EVT_DECLARE_USER_FUNC(evt_item_wait_collected, 1)

EVT_UNKNOWN_USER_FUNC(evt_item_spawn_thunder)
EVT_UNKNOWN_USER_FUNC(func_800ed188)
EVT_UNKNOWN_USER_FUNC(func_800ed1dc)
EVT_UNKNOWN_USER_FUNC(func_800ed468)
EVT_UNKNOWN_USER_FUNC(func_800ed66c)

CPP_WRAPPER_END()
