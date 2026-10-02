#pragma once

#include <common.h>
#include <evt_cmd.h>

CPP_WRAPPER(spm::evt_ac)

// evt_ac_entry(const char * name, s32 type)
// Same address as evt_ac_entry (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800df9a8)
EVT_DECLARE_USER_FUNC(evt_ac_entry, 2)

//evt_ac_return_results(const char * name, s32& ret)
// Same address as evt_ac_return_results (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800dfa00)
EVT_DECLARE_USER_FUNC(evt_ac_return_results, 2)

//evt_ac_delete(const char * name)
// Same address as evt_ac_delete (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800dfaac)
EVT_DECLARE_USER_FUNC(evt_ac_delete, 1)

CPP_WRAPPER_END()
