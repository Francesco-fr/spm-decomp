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

s32 func_800e9ce8(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    f32 x = evtGetFloat(entry, args[0]);
    f32 y = evtGetFloat(entry, args[1]);
    f32 z = evtGetFloat(entry, args[2]);
    GuideWork * gw = guideGetWork();
    Vec3 pos = {x, y, z};
    gw->unknown_0x64 = pos;

    return EVT_RET_CONTINUE;
}

s32 func_800e9da4(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    GuideWork * gw = guideGetWork();
    gw->rotation.x = 270.0f;
    gw->rotation.y = 0.0f;
    gw->rotation.z = 0.0f;

    return EVT_RET_CONTINUE;
}

s32 func_800e9ddc(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    GuideWork * gw = guideGetWork();
    gw->rotation.x = 90.0f;
    gw->rotation.y = 180.0f;
    gw->rotation.z = 180.0f;

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_800e9e14

s32 func_800e9ff8(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    f32 angle = evtGetFloat(entry, entry->pCurData[0]);
    GuideWork * gw = guideGetWork();
    gw->rotation.y = reviseAngle(angle);
    gw->rotation.z = gw->rotation.y;

    return EVT_RET_CONTINUE;
}

s32 func_800ea05c(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetFloat(entry, args[0], guideGetWork()->rotation.y);

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_800ea0a8

// NOT_DECOMPILED func_800ea25c

// NOT_DECOMPILED func_800ea3ec

// NOT_DECOMPILED func_800ea584

s32 func_800ea718(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    guideSetAnim((const char *) evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 func_800ea748(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    GuideWork * gw = guideGetWork();
    if (gw->flag3 & 2)
        return EVT_RET_BLOCK_WEAK;

    if (animPoseGetLoopTimes(gw->animPoseId) >= 1.0f)
        return EVT_RET_CONTINUE;
    else
        return EVT_RET_BLOCK_WEAK;
}

s32 evt_guide_enter_run_mode_1(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    guideEnterRunMode1();

    return EVT_RET_CONTINUE;
}

s32 evt_guide_enter_runmode_2(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    guideEnterRunMode2();

    return EVT_RET_CONTINUE;
}

s32 func_800ea7e8(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    Vec3 pos;
    func_80121ba4(&pos);
    evtSetFloat(entry, args[0], pos.x);
    evtSetFloat(entry, args[1], pos.y);
    evtSetFloat(entry, args[2], pos.z);

    return EVT_RET_CONTINUE;
}

s32 func_800ea858(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    func_80121bc8();

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED evt_guide_flag2_onoff

// NOT_DECOMPILED evt_guide_flag0_onoff

// NOT_DECOMPILED evt_guide_check_flag0

// NOT_DECOMPILED func_800ea9f4

// NOT_DECOMPILED evt_guide_get_can_search

// NOT_DECOMPILED func_800eaadc

}
