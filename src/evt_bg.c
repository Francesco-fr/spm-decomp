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

s32 func_800dfb80(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 on = evtGetValue(entry, args[0]);
    evtGetValue(entry, args[1]);
    if (on)
        func_8004e77c();
    else
        func_8004e790();

    return EVT_RET_CONTINUE;
}

s32 func_800dfbe4(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 on = evtGetValue(entry, args[0]);
    s32 id = evtGetValue(entry, args[1]);
    if (id != -1)
    {
        if (on)
            func_8004e7c0(id);
        else
            func_8004e7a4(id);
    }
    else
    {
        for (s32 i = 0; i < 18; i++)
        {
            if (on)
                func_8004e7c0(i);
            else
                func_8004e7a4(i);
        }
    }

    return EVT_RET_CONTINUE;
}

}
