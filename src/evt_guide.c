#include <common.h>
#include <evt_cmd.h>
#include <spm/animdrv.h>
#include <spm/evt_guide.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>
#include <spm/guide.h>
#include <spm/system.h>

extern "C" {

s32 evt_guide_set_pos(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    f32 x = evtGetFloat(entry, args[0]);
    f32 y = evtGetFloat(entry, args[1]);
    f32 z = evtGetFloat(entry, args[2]);
    GuideWork * gw = guideGetWork();
    Vec3 pos = {x, y, z};
    gw->pos = pos;

    return EVT_RET_CONTINUE;
}

s32 evt_guide_get_pos(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    GuideWork * gw = guideGetWork();
    evtSetFloat(entry, args[0], gw->pos.x);
    evtSetFloat(entry, args[1], gw->pos.y);
    evtSetFloat(entry, args[2], gw->pos.z);

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_800e9ce8

// NOT_DECOMPILED func_800e9da4

// NOT_DECOMPILED func_800e9ddc

// NOT_DECOMPILED func_800e9e14

// NOT_DECOMPILED func_800e9ff8

// NOT_DECOMPILED func_800ea05c

// NOT_DECOMPILED func_800ea0a8

// NOT_DECOMPILED func_800ea25c

// NOT_DECOMPILED func_800ea3ec

// NOT_DECOMPILED func_800ea584

// NOT_DECOMPILED func_800ea718

// NOT_DECOMPILED func_800ea748

// NOT_DECOMPILED evt_guide_enter_run_mode_1

// NOT_DECOMPILED evt_guide_enter_runmode_2

// NOT_DECOMPILED func_800ea7e8

// NOT_DECOMPILED func_800ea858

// NOT_DECOMPILED evt_guide_flag2_onoff

// NOT_DECOMPILED evt_guide_flag0_onoff

// NOT_DECOMPILED evt_guide_check_flag0

// NOT_DECOMPILED func_800ea9f4

// NOT_DECOMPILED evt_guide_get_can_search

// NOT_DECOMPILED func_800eaadc

}
