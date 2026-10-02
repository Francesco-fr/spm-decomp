#include <common.h>
#include <evt_cmd.h>
#include <msl/string.h>
#include <spm/evt_hit.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>
#include <spm/hitdrv.h>
#include <spm/mario.h>
#include <spm/system.h>

extern "C" {

s32 func_800eab1c(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    f32 x = evtGetFloat(entry, args[1]);
    f32 y = evtGetFloat(entry, args[2]);
    f32 z = evtGetFloat(entry, args[3]);
    func_8006f7cc((const char *) name, x, y, z);

    return EVT_RET_CONTINUE;
}

s32 func_800eabb8(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    f32 x = evtGetFloat(entry, args[1]);
    f32 y = evtGetFloat(entry, args[2]);
    f32 z = evtGetFloat(entry, args[3]);
    func_8006f884((const char *) name, x, y, z);

    return EVT_RET_CONTINUE;
}

s32 evt_hitobj_onoff(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    s32 group = evtGetValue(entry, args[1]);
    s32 on = evtGetValue(entry, args[2]);
    if (group == 0)
    {
        if (on)
            hitObjFlagOff(false, (const char *) name, 1);
        else
            hitObjFlagOn(false, (const char *) name, 1);
    }
    else
    {
        if (on)
            hitGrpFlagOff(false, (const char *) name, 1);
        else
            hitGrpFlagOn(false, (const char *) name, 1);
    }

    return EVT_RET_CONTINUE;
}

s32 func_800ead20(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    s32 group = evtGetValue(entry, args[1]);
    s32 on = evtGetValue(entry, args[2]);
    if (group == 0)
    {
        if (on)
            hitObjFlagOff(true, (const char *) name, 1);
        else
            hitObjFlagOn(true, (const char *) name, 1);
    }
    else
    {
        if (on)
            hitGrpFlagOff(true, (const char *) name, 1);
        else
            hitGrpFlagOn(true, (const char *) name, 1);
    }

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_800eadec

// NOT_DECOMPILED func_800eaed0

// NOT_DECOMPILED func_800eb15c

// NOT_DECOMPILED evt_hit_bind_mapobj

// NOT_DECOMPILED evt_hit_bind_update

// NOT_DECOMPILED func_800eb564

// NOT_DECOMPILED func_800eb5dc

// NOT_DECOMPILED func_800eb654

// NOT_DECOMPILED evt_hitobj_attr_onoff

// NOT_DECOMPILED func_800eb7f4

// NOT_DECOMPILED func_800eb8bc

// NOT_DECOMPILED func_800ebd74

}
