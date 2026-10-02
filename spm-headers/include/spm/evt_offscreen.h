#pragma once

#include <common.h>
#include <evt_cmd.h>

CPP_WRAPPER(spm::evt_offscreen)

EVT_UNKNOWN_USER_FUNC(evt_offscreen_entry)
EVT_UNKNOWN_USER_FUNC(evt_offscreen_delete)
EVT_UNKNOWN_USER_FUNC(evt_offscreen_get_boundingbox2)
// Same address as evt_offscreen_get_boundingbox2 (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_8010c504)

CPP_WRAPPER_END()
