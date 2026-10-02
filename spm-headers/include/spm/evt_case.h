#pragma once

#include <common.h>
#include <evt_cmd.h>

CPP_WRAPPER(spm::evt_case)

// evt_run_case_evt(int caseType, int unk, const char * a2Name, const char * a3Name, EvtScriptCode * script, unk)
// Same address as evt_run_case_evt (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800e0ca4)
EVT_DECLARE_USER_FUNC(evt_run_case_evt, 6)

UNKNOWN_FUNCTION(evtRunCaseEntry)
// Probably evtRunCaseEntry (name used by the decomp symbol map)
s32 func_800e0d78(s32 type, bool flag, const char * name, const char * name2,
                  EvtScriptCode * script, s32 * lw);

EVT_DECLARE_USER_FUNC(evt_exit_case_evt, 0)
// Same address as evt_exit_case_evt (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800e0dfc)

EVT_DECLARE_USER_FUNC(evt_del_case_evt, 2)
// Same address as evt_del_case_evt (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800e0e24)

EVT_UNKNOWN_USER_FUNC(evt_set_case_wrk)
EVT_UNKNOWN_USER_FUNC(func_800e0f30)
EVT_UNKNOWN_USER_FUNC(func_800e0f70)



EVT_UNKNOWN_USER_FUNC(func_800e0eb0)

CPP_WRAPPER_END()
