#include <common.h>
#include <evt_cmd.h>
#include <spm/evt_fairy.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>
#include <spm/fairy.h>
#include <spm/framedrv.h>
#include <spm/system.h>

extern "C" {

// Unknown unit
void func_80130c80(s32 param_1);

s32 evt_fairy_get_num(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], fairyGetNum() + fairyGetNumExtra());

    return EVT_RET_CONTINUE;
}

s32 func_800e7324(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 id = evtGetValue(entry, args[0]);
    s32 runMode = evtGetValue(entry, args[1]);
    fairyIdEnterRunMode(id, runMode);

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_800e7380

// NOT_DECOMPILED func_800e73b0

// NOT_DECOMPILED func_800e73e0

// NOT_DECOMPILED func_800e7404

// NOT_DECOMPILED func_800e7428

// NOT_DECOMPILED func_800e7458

// NOT_DECOMPILED func_800e747c

// NOT_DECOMPILED evt_fairy_set_pos

// NOT_DECOMPILED evt_fairy_set_pos_all

// NOT_DECOMPILED evt_fairy_get_pos

// NOT_DECOMPILED func_800e76d4

// NOT_DECOMPILED func_800e7784

// NOT_DECOMPILED func_800e77d0

// NOT_DECOMPILED func_800e7868

// NOT_DECOMPILED func_800e7900

// NOT_DECOMPILED func_800e7aec

// NOT_DECOMPILED func_800e7b78

// NOT_DECOMPILED func_800e7bdc

// NOT_DECOMPILED func_800e7d88

// NOT_DECOMPILED func_800e7f3c

// NOT_DECOMPILED func_800e80ec

// NOT_DECOMPILED evt_fairy_flag_onoff

// NOT_DECOMPILED evt_fairy_flag_onoff_all

// NOT_DECOMPILED func_800e82dc

// NOT_DECOMPILED func_800e8350

// NOT_DECOMPILED func_800e840c

// NOT_DECOMPILED func_800e8468

// NOT_DECOMPILED evt_fairy_reset

// NOT_DECOMPILED func_800e8518

// NOT_DECOMPILED func_800e86dc

// NOT_DECOMPILED func_800e8748

// NOT_DECOMPILED func_800e87ac

// NOT_DECOMPILED func_800e8824

}
