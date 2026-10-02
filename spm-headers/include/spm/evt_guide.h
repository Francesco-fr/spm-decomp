#pragma once

#include <common.h>
#include <evt_cmd.h>

CPP_WRAPPER(spm::evt_guide)

EVT_UNKNOWN_USER_FUNC(evt_guide_set_pos)
EVT_UNKNOWN_USER_FUNC(evt_guide_get_pos)
EVT_UNKNOWN_USER_FUNC(func_800e9ce8)
EVT_UNKNOWN_USER_FUNC(func_800e9da4)
EVT_UNKNOWN_USER_FUNC(func_800e9ddc)
EVT_UNKNOWN_USER_FUNC(func_800e9e14)
EVT_UNKNOWN_USER_FUNC(func_800e9ff8)
EVT_UNKNOWN_USER_FUNC(func_800ea05c)
EVT_UNKNOWN_USER_FUNC(func_800ea0a8)
EVT_UNKNOWN_USER_FUNC(func_800ea25c)
EVT_UNKNOWN_USER_FUNC(func_800ea3ec)
EVT_UNKNOWN_USER_FUNC(func_800ea584)
EVT_UNKNOWN_USER_FUNC(func_800ea718)
EVT_UNKNOWN_USER_FUNC(func_800ea748)
EVT_UNKNOWN_USER_FUNC(evt_guide_enter_run_mode_1)
EVT_UNKNOWN_USER_FUNC(evt_guide_enter_runmode_2)
EVT_UNKNOWN_USER_FUNC(func_800ea7e8)
EVT_UNKNOWN_USER_FUNC(func_800ea858)

// evt_guide_flag2_onoff(bool onoff, u32 flags)
EVT_DECLARE_USER_FUNC(evt_guide_flag2_onoff, 2)

EVT_UNKNOWN_USER_FUNC(evt_guide_flag0_onoff)

// evt_guide_check_flag0(u32 flags, bool &ret)
EVT_DECLARE_USER_FUNC(evt_guide_check_flag0, 2)

EVT_UNKNOWN_USER_FUNC(func_800ea9f4)
EVT_DECLARE_USER_FUNC(evt_guide_get_can_search, 1)
EVT_UNKNOWN_USER_FUNC(func_800eaadc)

CPP_WRAPPER_END()
