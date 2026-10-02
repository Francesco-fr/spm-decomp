#include <common.h>
#include <evt_cmd.h>
#include <spm/evt_ext.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>
#include <spm/extdrv.h>

extern "C" {

s32 func_800e6f9c(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 param_1 = evtGetValue(entry, args[0]);
    s32 param_2 = evtGetValue(entry, args[1]);
    s32 param_3 = evtGetValue(entry, args[2]);
    s32 param_4 = evtGetValue(entry, args[3]);
    s32 param_5 = evtGetValue(entry, args[4]);
    extEntry(param_1, param_2, param_3, param_4, param_5);

    return EVT_RET_CONTINUE;
}

s32 func_800e702c(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    extReset();

    return EVT_RET_CONTINUE;
}

}
