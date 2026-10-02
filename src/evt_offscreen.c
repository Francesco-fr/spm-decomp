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

// NOT_DECOMPILED evt_offscreen_delete

// NOT_DECOMPILED func_8010c504

}
