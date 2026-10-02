#include <common.h>
#include <evt_cmd.h>
#include <spm/evt_fade.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>
#include <spm/fadedrv.h>

extern "C" {

s32 evt_fade_entry(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 type = evtGetValue(entry, args[0]);
    s32 length = evtGetValue(entry, args[1]);
    u8 r = (u8) evtGetValue(entry, args[2]);
    u8 g = (u8) evtGetValue(entry, args[3]);
    u8 b = (u8) evtGetValue(entry, args[4]);
    u8 a = (u8) evtGetValue(entry, args[5]);
    fadeEntry(type, length, (GXColor) {r, g, b, a});

    return EVT_RET_CONTINUE;
}

s32 evt_fade_end_wait(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    s32 id = evtGetValue(entry, entry->pCurData[0]);
    if (id == -1)
    {
        if (fadeIsFinish())
            return EVT_RET_CONTINUE;
    }
    else
    {
        if (func_80067824(id))
            return EVT_RET_CONTINUE;
    }

    return EVT_RET_BLOCK_WEAK;
}

s32 func_800e715c(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    f32 x = evtGetFloat(entry, args[0]);
    f32 y = evtGetFloat(entry, args[1]);
    f32 z = evtGetFloat(entry, args[2]);
    func_80066558(x, y, z);

    return EVT_RET_CONTINUE;
}

s32 func_800e71dc(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    func_8006783c(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 func_800e720c(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 in = evtGetValue(entry, args[0]);
    s32 out = evtGetValue(entry, args[1]);
    fadeSetMapChangeTransition(in, out);

    return EVT_RET_CONTINUE;
}

s32 func_800e7268(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 in = evtGetValue(entry, args[0]);
    s32 out = evtGetValue(entry, args[1]);
    func_80067914(in, out);

    return EVT_RET_CONTINUE;
}

}
