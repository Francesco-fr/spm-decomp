#include <common.h>
#include <evt_cmd.h>
#include <spm/evt_mario.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>
#include <spm/fairy.h>
#include <spm/hitdrv.h>
#include <spm/mario.h>
#include <spm/mario_hit.h>
#include <spm/mario_motion.h>
#include <spm/mario_sbr.h>
#include <spm/mario_status.h>
#include <spm/mot_slit.h>
#include <spm/mot_swim.h>
#include <spm/system.h>

extern "C" {

// Unknown unit
void func_80130c80(s32 param_1);

s32 evt_mario_flag0_onoff(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 on = evtGetValue(entry, args[0]);
    u32 flags = (u32) evtGetValue(entry, args[1]);
    MarioWork * mp = marioGetPtr();
    if (on)
        mp->flags |= flags;
    else
        mp->flags &= ~flags;

    return EVT_RET_CONTINUE;
}

s32 evt_mario_flag4_onoff(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 on = evtGetValue(entry, args[0]);
    u32 flags = (u32) evtGetValue(entry, args[1]);
    MarioWork * mp = marioGetPtr();
    if (on)
        mp->miscFlags |= flags;
    else
        mp->miscFlags &= ~flags;

    return EVT_RET_CONTINUE;
}

s32 evt_mario_flag8_onoff(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 on = evtGetValue(entry, args[0]);
    u32 flags = (u32) evtGetValue(entry, args[1]);
    MarioWork * mp = marioGetPtr();
    if (on)
        mp->dispFlags |= flags;
    else
        mp->dispFlags &= ~flags;

    return EVT_RET_CONTINUE;
}

s32 func_800ef53c(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 idx = evtGetValue(entry, args[0]);
    MarioWork * mp = marioGetPtr();
    switch (idx)
    {
        case 0:
            evtSetValue(entry, args[1], (s32) mp->flags);
            break;
        case 1:
            evtSetValue(entry, args[1], (s32) mp->miscFlags);
            break;
        case 2:
            evtSetValue(entry, args[1], (s32) mp->dispFlags);
            break;
    }

    return EVT_RET_CONTINUE;
}

s32 evt_mario_cont_onoff(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    if (evtGetValue(entry, entry->pCurData[0]))
        marioCtrlOn();
    else
        marioCtrlOff();

    return EVT_RET_CONTINUE;
}

s32 evt_mario_key_on(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    marioKeyOn();

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED evt_mario_key_off

s32 evt_mario_key_off2(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    marioKeyOff();

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_800ef814

s32 func_800ef8c8(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    if (evtGetValue(entry, entry->pCurData[0]))
        marioBgModeOn();
    else
        marioBgModeOff();

    return EVT_RET_CONTINUE;
}

s32 evt_mario_get_character(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], marioGetPtr()->character);

    return EVT_RET_CONTINUE;
}

s32 evt_mario_set_character(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    marioChangeCharacter(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 evt_mario_set_pos(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    f32 x = evtGetFloat(entry, args[0]);
    f32 y = evtGetFloat(entry, args[1]);
    f32 z = evtGetFloat(entry, args[2]);
    MarioWork * mp = marioGetPtr();
    if (mp != NULL)
    {
        Vec3 pos = {x, y, z};
        mp->position = pos;
    }

    return EVT_RET_CONTINUE;
}

s32 evt_mario_get_pos(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    MarioWork * mp = marioGetPtr();
    evtSetFloat(entry, args[0], mp->position.x);
    evtSetFloat(entry, args[1], mp->position.y);
    evtSetFloat(entry, args[2], mp->position.z);

    return EVT_RET_CONTINUE;
}

s32 func_800efac4(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    f32 x = evtGetFloat(entry, args[0]);
    f32 y = evtGetFloat(entry, args[1]);
    f32 z = evtGetFloat(entry, args[2]);
    MarioWork * mp = marioGetPtr();
    mp->unknown_0x134.x = x;
    mp->unknown_0x134.y = y;
    mp->unknown_0x134.z = z;

    return EVT_RET_CONTINUE;
}

s32 func_800efb50(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    f32 x = evtGetFloat(entry, args[0]);
    f32 y = evtGetFloat(entry, args[1]);
    f32 z = evtGetFloat(entry, args[2]);
    MarioWork * mp = marioGetPtr();
    mp->scale.x = x;
    mp->scale.y = y;
    mp->scale.z = z;

    return EVT_RET_CONTINUE;
}

s32 func_800efbdc(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    MarioWork * mp = marioGetPtr();
    evtSetFloat(entry, args[0], mp->scale.x);
    evtSetFloat(entry, args[1], mp->scale.y);
    evtSetFloat(entry, args[2], mp->scale.z);

    return EVT_RET_CONTINUE;
}

s32 func_800efc54(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    f32 x = evtGetFloat(entry, args[0]);
    f32 y = evtGetFloat(entry, args[1]);
    f32 z = evtGetFloat(entry, args[2]);
    MarioWork * mp = marioGetPtr();
    mp->ttydRotation.x = x;
    mp->ttydRotation.y = y;
    mp->ttydRotation.z = z;

    return EVT_RET_CONTINUE;
}

s32 evt_mario_get_height(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetFloat(entry, args[0], func_801318f8());

    return EVT_RET_CONTINUE;
}

s32 evt_mario_direction_reset(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    if (marioGetPtr() != NULL)
        func_80150478();

    return EVT_RET_CONTINUE;
}

s32 func_800efd58(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    if (marioGetPtr() != NULL)
        func_801504b0();

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED evt_mario_direction_face

s32 func_800eff6c(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetFloat(entry, args[0], marioGetPtr()->directionView);

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED evt_mario_face_npc

// NOT_DECOMPILED evt_mario_face_coords

s32 func_800f013c(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    func_801502bc();

    return EVT_RET_CONTINUE;
}

s32 func_800f0160(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    MarioWork * mp = marioGetPtr();
    if (marioCheck3d() == 1)
    {
        func_801502bc();
        mp->directionWorld = mp->directionView = 90.0f;
    }

    return EVT_RET_CONTINUE;
}

s32 func_800f01ac(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    f32 angle = evtGetFloat(entry, entry->pCurData[0]);
    MarioWork * mp = marioGetPtr();
    mp->dispDirectionTarget = reviseAngle(angle);
    mp->dispDirectionCurrent = mp->dispDirectionTarget;

    return EVT_RET_CONTINUE;
}

s32 func_800f0210(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetFloat(entry, args[0], marioGetPtr()->dispDirectionCurrent);

    return EVT_RET_CONTINUE;
}

s32 evt_mario_face(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    f32 x = evtGetFloat(entry, args[0]);
    f32 y = evtGetFloat(entry, args[1]);
    f32 z = evtGetFloat(entry, args[2]);
    Vec3 pos = {x, y, z};
    marioLockFacingDir(&pos);

    return EVT_RET_CONTINUE;
}

s32 evt_mario_face_free(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    marioUnlockFacing();

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_800f0304

// NOT_DECOMPILED func_800f046c

// NOT_DECOMPILED func_800f05b0

// NOT_DECOMPILED func_800f074c

// NOT_DECOMPILED evt_mario_walk_back_from_pos

// NOT_DECOMPILED func_800f0c28

// NOT_DECOMPILED func_800f0d58

// NOT_DECOMPILED func_800f119c

// NOT_DECOMPILED func_800f1684

// NOT_DECOMPILED func_800f1778

s32 func_800f1810(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    if (marioKeyOffChk())
        return EVT_RET_BLOCK_WEAK;

    return marioCtrlOffChk() ? EVT_RET_BLOCK_WEAK : EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_800f1858

s32 evt_mario_set_pose(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    s32 time = evtGetValue(entry, args[1]);
    MarioWork * mp = marioGetPtr();
    mp->curPoseName = (const char *) name;
    mp->poseTime = (s16) time;
    mp->trigFlags |= 0x1000;

    return EVT_RET_CONTINUE;
}

s32 evt_mario_wait_anim(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    if (marioGetPtr()->trigFlags & 0x1000)
        return EVT_RET_BLOCK_WEAK;

    return marioIsAnimFinished() ? EVT_RET_CONTINUE : EVT_RET_BLOCK_WEAK;
}

s32 func_800f1a08(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    s32 motionId = evtGetValue(entry, entry->pCurData[0]);
    marioGetPtr();
    marioChgMot(motionId);

    return EVT_RET_CONTINUE;
}

s32 func_800f1a4c(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    MarioWork * mp = marioGetPtr();
    if (mp->trigFlags & 1)
        evtSetValue(entry, args[0], mp->prevMotionId);
    else
        evtSetValue(entry, args[0], mp->motionId);

    return EVT_RET_CONTINUE;
}

s32 func_800f1abc(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], func_80176a10());

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_800f1b08

// NOT_DECOMPILED func_800f1ba8

// NOT_DECOMPILED func_800f1c1c

// NOT_DECOMPILED func_800f1c88

// NOT_DECOMPILED func_800f1d0c

// NOT_DECOMPILED func_800f1d80

// NOT_DECOMPILED func_800f1e30

// NOT_DECOMPILED func_800f1eb0

// NOT_DECOMPILED func_800f1f30

// NOT_DECOMPILED func_800f1f9c

// NOT_DECOMPILED func_800f2008

// NOT_DECOMPILED func_800f2074

s32 func_800f2124(MarioWork * mp, EvtEntry * entry)
{
    (void) mp;
    (void) entry;

    return 0;
}

s32 func_800f212c(MarioWork * mp, EvtEntry * entry)
{
    (void) entry;

    return mp->dispFlags & 0x1000000 ? 0 : 2;
}

// NOT_DECOMPILED func_800f2144

// NOT_DECOMPILED func_800f2310

s32 func_800f23e4(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    func_801528d4(marioGetPtr());

    return EVT_RET_CONTINUE;
}

s32 func_800f240c(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    s32 param_1 = evtGetValue(entry, entry->pCurData[0]);
    marioGetPtr();
    func_80152900(param_1);

    return EVT_RET_CONTINUE;
}

s32 evt_mario_fairy_reset(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    func_80130c80(4);

    return EVT_RET_CONTINUE;
}

s32 evt_mario_swim_onoff(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    s32 on = evtGetValue(entry, entry->pCurData[0]);
    MarioWork * mp = marioGetPtr();
    if (on)
        mp->miscFlags |= 0x100;
    else
        mp->miscFlags &= ~0x100;

    return EVT_RET_CONTINUE;
}

s32 func_800f24d8(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    const char * name = NULL;
    MarioWork * mp = marioGetPtr();
    if (mp->hitObjs1[2] != NULL)
        name = hitGetName(mp->hitObjs1[2]);
    evtSetValue(entry, args[0], (s32) name);

    return EVT_RET_CONTINUE;
}

s32 func_800f2544(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    const char * name = NULL;
    MarioWork * mp = marioGetPtr();
    if (mp->hitObjs1[7] != NULL)
        name = hitGetName(mp->hitObjs1[7]);
    evtSetValue(entry, args[0], (s32) name);

    return EVT_RET_CONTINUE;
}

s32 evt_set_gravity(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    marioSetGravity(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 evt_get_gravity(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], marioGetGravity());

    return EVT_RET_CONTINUE;
}

s32 func_800f262c(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    s32 type = evtGetValue(entry, entry->pCurData[0]);
    if (type == 2)
        func_801173b4();
    else if (type == 1)
        func_8011730c();
    else
        func_801174ec();

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_800f267c

// NOT_DECOMPILED func_800f26c0

// NOT_DECOMPILED func_800f27f4

// NOT_DECOMPILED func_800f2974

// NOT_DECOMPILED func_800f29c8

// NOT_DECOMPILED evt_mario_tamara_onoff

// NOT_DECOMPILED evt_mario_tamara_chg_mode

// NOT_DECOMPILED func_800f2c00

// NOT_DECOMPILED func_800f2c98

// NOT_DECOMPILED func_800f2cbc

// NOT_DECOMPILED func_800f2cfc

// NOT_DECOMPILED func_800f2d74

// NOT_DECOMPILED func_800f2df4

// NOT_DECOMPILED func_800f2e30

// NOT_DECOMPILED func_800f2e54

// NOT_DECOMPILED evt_mario_set_bottomless_cb

// NOT_DECOMPILED evt_mario_get_bottomless_cb

// NOT_DECOMPILED evt_mario_set_anim_change_handler

// NOT_DECOMPILED func_800f2fa8

// NOT_DECOMPILED func_800f2fec

// NOT_DECOMPILED func_800f3074

// NOT_DECOMPILED func_800f30bc

// NOT_DECOMPILED func_800f315c

// NOT_DECOMPILED evt_mario_set_pane_boundaries

// NOT_DECOMPILED evt_mario_get_pane_for_pos

// NOT_DECOMPILED evt_mario_set_pane

// NOT_DECOMPILED evt_mario_pane_change_func

// NOT_DECOMPILED evt_mario_get_pane_change_func

// NOT_DECOMPILED func_800f3310

// NOT_DECOMPILED func_800f3334

// NOT_DECOMPILED evt_mario_check_3d

// NOT_DECOMPILED func_800f33b0

// NOT_DECOMPILED evt_mario_calc_damage_to_enemy

}
