#include <common.h>
#include <evt_cmd.h>
#include <spm/bgdrv.h>
#include <spm/evt_bg.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>

extern "C" {

s32 func_800dfae0(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 r = evtGetValue(entry, args[0]);
    s32 g = evtGetValue(entry, args[1]);
    s32 b = evtGetValue(entry, args[2]);
    s32 a = evtGetValue(entry, args[3]);
    func_8004e710((GXColor) {(u8) r, (u8) g, (u8) b, (u8) a});

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_800dfb80

// NOT_DECOMPILED func_800dfbe4

}
