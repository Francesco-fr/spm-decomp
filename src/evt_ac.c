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

s32 func_800dfa00(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    AcEntry * ac = acNameToPtr((const char *) name);

    // "Couldn't find AC [%s]"
    SPM_ASSERT(43, ac, "ＡＣがみつかりません[ %s ]", name);

    s32 results = func_8003f5d8(ac);
    if (results < 2)
        return EVT_RET_BLOCK_WEAK;

    evtSetValue(entry, args[1], results);

    return EVT_RET_CONTINUE;
}

s32 func_800dfaac(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    acDelete(acNameToPtr((const char *) evtGetValue(entry, entry->pCurData[0])));

    return EVT_RET_CONTINUE;
}

}
