#include <common.h>
#include <evt_cmd.h>
#include <spm/evt_nand.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>
#include <spm/nandmgr.h>
#include <spm/spmario.h>

extern "C" {

s32 func_80241408(EvtEntry * entry, bool isFirstCall)
{
    EvtScriptCode * args = entry->pCurData;
    if (isFirstCall)
        nandWriteBanner();

    if (nandIsExec())
        return EVT_RET_BLOCK_WEAK;

    evtSetValue(entry, args[0], nandGetCode());

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_80241474

// NOT_DECOMPILED func_802414e0

// NOT_DECOMPILED func_8024154c

// NOT_DECOMPILED func_802415e4

// NOT_DECOMPILED func_80241650

// NOT_DECOMPILED func_802416e8

// NOT_DECOMPILED func_80241728

// NOT_DECOMPILED func_8024174c

// NOT_DECOMPILED func_80241778

// NOT_DECOMPILED func_802417a8

// NOT_DECOMPILED func_80241804

}
