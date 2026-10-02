/*
    WARNING: Not fully decompiled
    This file is currently not linked into the final dol
*/

#include <common.h>
#include <evt_cmd.h>
#include <spm/evt_search.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>
#include <spm/search.h>

extern "C" {

s32 func_8024a62c(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    u8 * work = (u8 *) evtGetValue(entry, args[0]);
    s32 count = evtGetValue(entry, args[1]);
    for (s32 i = 0; i < count; i++, work += 0x1c)
        func_802497e8(work);

    return EVT_RET_CONTINUE;
}

s32 func_8024a6a8(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    return func_802498b0() ? EVT_RET_BLOCK_WEAK : EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_8024a6dc

// NOT_DECOMPILED func_8024a7c4

s32 func_8024ace4(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    func_8024a5e8();

    return EVT_RET_CONTINUE;
}

s32 func_8024ad08(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    if (evtGetValue(entry, entry->pCurData[0]))
        func_80243abc();
    else
        func_80243aa8();

    return EVT_RET_CONTINUE;
}

}
