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

// NOT_DECOMPILED evt_fade_end_wait

// NOT_DECOMPILED func_800e715c

// NOT_DECOMPILED func_800e71dc

// NOT_DECOMPILED func_800e720c

// NOT_DECOMPILED func_800e7268

}
