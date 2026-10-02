#include <common.h>
#include <evt_cmd.h>
#include <spm/effdrv.h>
#include <spm/evt_eff.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>

extern "C" {

// NOT_DECOMPILED evt_eff

s32 evt_eff_softdelete(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    effSoftDelete(effNameToPtr((const char *) evtGetValue(entry, entry->pCurData[0])));

    return EVT_RET_CONTINUE;
}

s32 func_800e617c(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    effDelete(effNameToPtr((const char *) evtGetValue(entry, entry->pCurData[0])));

    return EVT_RET_CONTINUE;
}

s32 func_800e61b0(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    effSoftDelete((EffEntry *) evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 func_800e61e0(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    effDelete((EffEntry *) evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_800e6210

// NOT_DECOMPILED func_800e6250

}
