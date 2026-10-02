#pragma once

#include <common.h>
#include <evt_cmd.h>

CPP_WRAPPER(spm::evt_env)

EVT_DECLARE_USER_FUNC(evt_env_blur_on, 2)
// Same address as evt_env_blur_on (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800e658c)
EVT_DECLARE_USER_FUNC(evt_env_static_blur_on, 0)
// Same address as evt_env_static_blur_on (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800e6624)
EVT_UNKNOWN_USER_FUNC(func_800e6650)
EVT_UNKNOWN_USER_FUNC(func_800e6748)
EVT_UNKNOWN_USER_FUNC(func_800e6778)
EVT_UNKNOWN_USER_FUNC(func_800e679c)
EVT_UNKNOWN_USER_FUNC(func_800e6a94)

CPP_WRAPPER_END()
