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

s32 func_80241474(EvtEntry * entry, bool isFirstCall)
{
    EvtScriptCode * args = entry->pCurData;
    if (isFirstCall)
        nandCheck();

    if (nandIsExec())
        return EVT_RET_BLOCK_WEAK;

    evtSetValue(entry, args[0], nandGetCode());

    return EVT_RET_CONTINUE;
}

s32 func_802414e0(EvtEntry * entry, bool isFirstCall)
{
    EvtScriptCode * args = entry->pCurData;
    if (isFirstCall)
        nandWriteAllSaves();

    if (nandIsExec())
        return EVT_RET_BLOCK_WEAK;

    evtSetValue(entry, args[0], nandGetCode());

    return EVT_RET_CONTINUE;
}

s32 func_8024154c(EvtEntry * entry, bool isFirstCall)
{
    EvtScriptCode * args = entry->pCurData;
    s32 saveId = evtGetValue(entry, args[0]);
    if (isFirstCall)
    {
        if (saveId == -1)
            nandWriteSave(gp->saveFileId);
        else
            nandWriteSave(saveId);
    }

    if (nandIsExec())
        return EVT_RET_BLOCK_WEAK;

    evtSetValue(entry, args[1], nandGetCode());

    return EVT_RET_CONTINUE;
}

s32 func_802415e4(EvtEntry * entry, bool isFirstCall)
{
    EvtScriptCode * args = entry->pCurData;
    if (isFirstCall)
        nandWriteBannerLoadAllSaves();

    if (nandIsExec())
        return EVT_RET_BLOCK_WEAK;

    evtSetValue(entry, args[0], nandGetCode());

    return EVT_RET_CONTINUE;
}

s32 func_80241650(EvtEntry * entry, bool isFirstCall)
{
    EvtScriptCode * args = entry->pCurData;
    s32 saveId = evtGetValue(entry, args[0]);
    if (isFirstCall)
    {
        if (saveId == -1)
            nandDeleteSave(gp->saveFileId);
        else
            nandDeleteSave(saveId);
    }

    if (nandIsExec())
        return EVT_RET_BLOCK_WEAK;

    evtSetValue(entry, args[1], nandGetCode());

    return EVT_RET_CONTINUE;
}

s32 func_802416e8(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    if (evtGetValue(entry, entry->pCurData[0]))
        nandDisableSaving();
    else
        nandEnableSaving();

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_80241728

// NOT_DECOMPILED func_8024174c

// NOT_DECOMPILED func_80241778

// NOT_DECOMPILED func_802417a8

// NOT_DECOMPILED func_80241804

}
