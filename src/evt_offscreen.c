#include <common.h>
#include <evt_cmd.h>
#include <spm/evt_offscreen.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>
#include <spm/offscreendrv.h>

extern "C" {

s32 evt_offscreen_entry(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    offscreenEntry((const char *) evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 evt_offscreen_delete(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    func_800353c4((const char *) evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 func_8010c504(EvtEntry * entry, bool isFirstCall)
{
    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    s32 xVar = args[1];
    s32 yVar = args[2];
    s32 widthVar = args[3];
    s32 heightVar = args[4];
    s32 id = offscreenNameToId((const char *) name);
    u16 x0 = 0;
    u16 y0 = 0;
    u16 x1 = 0;
    u16 y1 = 0;
    if (isFirstCall)
        entry->tempS[0] = 5;

    bool ret = func_80035478(id, &x0, &y0, &x1, &y1);
    entry->tempS[0]--;
    if (!ret && entry->tempS[0] != 0)
        return EVT_RET_BLOCK_WEAK;

    evtSetValue(entry, xVar, x0);
    evtSetValue(entry, yVar, y0);
    evtSetValue(entry, widthVar, x1 - x0);
    evtSetValue(entry, heightVar, y1 - y0);

    return EVT_RET_CONTINUE;
}

}
