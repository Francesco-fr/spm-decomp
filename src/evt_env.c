#include <common.h>
#include <evt_cmd.h>
#include <spm/envdrv.h>
#include <spm/evt_env.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>

extern "C" {

s32 func_800e658c(EvtEntry * entry, bool isFirstCall)
{
    EvtScriptCode * args = entry->pCurData;
    s32 type = evtGetValue(entry, args[0]);
    s32 time = evtGetValue(entry, args[1]);
    if (isFirstCall)
        func_80063f20(type, time);

    if (time == 0)
        return EVT_RET_CONTINUE;

    return func_80064004() ? EVT_RET_BLOCK_WEAK : EVT_RET_CONTINUE;
}

s32 func_800e6624(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    func_80063f20(0, 500);

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_800e6650

// NOT_DECOMPILED func_800e6748

// NOT_DECOMPILED func_800e6778

// NOT_DECOMPILED func_800e679c

// NOT_DECOMPILED func_800e6a94

}
