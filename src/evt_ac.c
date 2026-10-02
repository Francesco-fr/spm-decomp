#include <common.h>
#include <evt_cmd.h>
#include <spm/acdrv.h>
#include <spm/evt_ac.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>
#include <spm/system.h>

extern "C" {

s32 func_800df9a8(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    s32 type = evtGetValue(entry, args[1]);
    acEntry(type)->name = (const char *) name;

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_800dfa00

// NOT_DECOMPILED func_800dfaac

}
