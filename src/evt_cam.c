#include <common.h>
#include <evt_cmd.h>
#include <spm/cam_road.h>
#include <spm/cam_shift.h>
#include <spm/camdrv.h>
#include <spm/evt_cam.h>
#include <spm/evt_door.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>
#include <msl/string.h>
#include <spm/mario.h>
#include <spm/mario_sbr.h>
#include <spm/seqdrv.h>
#include <spm/spmario.h>
#include <spm/spmario_snd.h>
#include <spm/system.h>

extern "C" {

// Owned by an unsplit data object
typedef struct
{
/* 0x00 */ u8 unknown_0x0[0x18 - 0x0];
/* 0x18 */ f32 unknown_0x18;
/* 0x1C */ f32 unknown_0x1c;
} UnkCamData;
extern UnkCamData lbl_80407d88[2];

s32 evt_cam_flag_onoff(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 on = evtGetValue(entry, args[0]);
    s32 id = evtGetValue(entry, args[1]);
    u32 flags = (u32) args[2];
    if (on)
        camGetPtr(id)->flag |= flags;
    else
        camGetPtr(id)->flag &= ~flags;

    return EVT_RET_CONTINUE;
}

s32 evt_cam_get_at(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    CamEntry * cam = camGetPtr(evtGetValue(entry, args[0]));
    evtSetFloat(entry, args[1], cam->target.x);
    evtSetFloat(entry, args[2], cam->target.y);
    evtSetFloat(entry, args[3], cam->target.z);

    return EVT_RET_CONTINUE;
}

s32 evt_cam_get_pos(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    CamEntry * cam = camGetPtr(evtGetValue(entry, args[0]));
    evtSetFloat(entry, args[1], cam->pos.x);
    evtSetFloat(entry, args[2], cam->pos.y);
    evtSetFloat(entry, args[3], cam->pos.z);

    return EVT_RET_CONTINUE;
}

s32 evt_cam_shake(EvtEntry * entry, bool isFirstCall)
{
    EvtScriptCode * args = entry->pCurData;
    s32 id = evtGetValue(entry, args[0]);
    f32 x = evtGetFloat(entry, args[1]);
    f32 y = evtGetFloat(entry, args[2]);
    f32 z = evtGetFloat(entry, args[3]);
    s32 time = evtGetValue(entry, args[4]);
    s32 type = evtGetValue(entry, args[5]);
    if (isFirstCall)
    {
        if (type == 0)
            func_80058700(id, x, y, z, time);
        else
            func_800587a0(id, x, y, z, time);
    }

    if (func_80058800(id))
        return EVT_RET_BLOCK_WEAK;

    return EVT_RET_CONTINUE;
}

s32 evt_cam3d_evt_zoom_in(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 projType = args[0];
    s32 posXVar = args[1];
    f32 posX = evtGetFloat(entry, posXVar);
    s32 posYVar = args[2];
    f32 posY = evtGetFloat(entry, posYVar);
    s32 posZVar = args[3];
    f32 posZ = evtGetFloat(entry, posZVar);
    s32 targetXVar = args[4];
    f32 targetX = evtGetFloat(entry, targetXVar);
    s32 targetYVar = args[5];
    f32 targetY = evtGetFloat(entry, targetYVar);
    s32 targetZVar = args[6];
    f32 targetZ = evtGetFloat(entry, targetZVar);
    s32 time = evtGetValue(entry, args[7]);
    s32 type = evtGetValue(entry, args[8]);
    CamEntry * cam = camGetPtr(5);

    cam->zoomStartPos.x = cam->pos.x;
    cam->zoomStartPos.y = cam->pos.y;
    cam->zoomStartPos.z = cam->pos.z;
    cam->zoomStartTarget.x = cam->target.x;
    cam->zoomStartTarget.y = cam->target.y;
    cam->zoomStartTarget.z = cam->target.z;
    cam->zoomDestPos.x = cam->pos.x;
    cam->zoomDestPos.y = cam->pos.y;
    cam->zoomDestPos.z = cam->pos.z;
    cam->zoomDestTarget.x = cam->target.x;
    cam->zoomDestTarget.y = cam->target.y;
    cam->zoomDestTarget.z = cam->target.z;

    // Only override values that were specified
    if (posXVar != EVT_NULLPTR)
        cam->zoomDestPos.x = posX;
    if (posYVar != EVT_NULLPTR)
        cam->zoomDestPos.y = posY;
    if (posZVar != EVT_NULLPTR)
        cam->zoomDestPos.z = posZ;
    if (targetXVar != EVT_NULLPTR)
        cam->zoomDestTarget.x = targetX;
    if (targetYVar != EVT_NULLPTR)
        cam->zoomDestTarget.y = targetY;
    if (targetZVar != EVT_NULLPTR)
        cam->zoomDestTarget.z = targetZ;

    cam->zoomStartTime = gp->time;
    cam->zoomTime = time;
    cam->zoomType = type;
    cam->unknown_0xe4 = 0;
    cam->cameraMode = 2;
    cam->unknown_0x250 = 0;
    if (projType == -1)
        cam->zoomProjectionType = cam->projectionType;
    else
        cam->zoomProjectionType = (GXProjectionType) projType;

    if ((camGetPtr(11)->flag & 0x10000000) && targetZVar != EVT_NULLPTR && posZVar != EVT_NULLPTR &&
        !(cam->flag & 0x20000000) && !(func_800e1040() & 1))
    {
        Vec3 dir;
        f32 dist = PSVECDistance(&cam->zoomDestPos, &cam->zoomDestTarget);
        PSVECSubtract(&cam->zoomDestPos, &cam->zoomDestTarget, &dir);
        PSVECNormalize(&dir, &dir);
        PSVECScale(&dir, &dir, 0.84f * dist);
        PSVECAdd(&cam->zoomDestTarget, &dir, &cam->zoomDestPos);
    }

    return EVT_RET_CONTINUE;
}

s32 func_800e01f8(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    CamEntry * cam = camGetPtr(5);
    cam->zoomStartPos.x = cam->pos.x;
    cam->zoomStartPos.y = cam->pos.y;
    cam->zoomStartPos.z = cam->pos.z;
    cam->zoomStartTarget.x = cam->target.x;
    cam->zoomStartTarget.y = cam->target.y;
    cam->zoomStartTarget.z = cam->target.z;
    cam->zoomDestPos.x = cam->pos.x;
    cam->zoomDestPos.y = cam->pos.y;
    cam->zoomDestPos.z = cam->pos.z;
    cam->zoomDestTarget.x = cam->target.x;
    cam->zoomDestTarget.y = cam->target.y;
    cam->zoomDestTarget.z = cam->target.z;
    cam->zoomStartTime = gp->time;
    cam->zoomTime = 0;
    cam->zoomType = 11;
    cam->unknown_0xe4 = 0;
    cam->cameraMode = 2;
    cam->unknown_0x250 = 0;
    cam->zoomProjectionType = cam->projectionType;

    return EVT_RET_CONTINUE;
}

s32 func_800e02bc(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 id = evtGetValue(entry, args[0]);
    f32 x = evtGetFloat(entry, args[1]);
    f32 y = evtGetFloat(entry, args[2]);
    f32 z = evtGetFloat(entry, args[3]);
    Vec3 target;
    Vec3 pos;
    CamEntry * cam = camGetPtr(5);
    Vec3 at = {x, y, z};
    func_800533cc(id, &at, &pos, &target);
    cam->zoomStartPos.x = pos.x;
    cam->zoomStartPos.y = pos.y;
    cam->zoomStartPos.z = pos.z;
    cam->zoomStartTarget.x = target.x;
    cam->zoomStartTarget.y = target.y;
    cam->zoomStartTarget.z = target.z;
    cam->zoomDestPos.x = pos.x;
    cam->zoomDestPos.y = pos.y;
    cam->zoomDestPos.z = pos.z;
    cam->zoomDestTarget.x = target.x;
    cam->zoomDestTarget.y = target.y;
    cam->zoomDestTarget.z = target.z;
    cam->zoomStartTime = gp->time;
    cam->zoomTime = 0;
    cam->zoomType = 11;
    cam->unknown_0xe4 = 0;
    cam->cameraMode = 2;
    cam->unknown_0x250 = 0;
    cam->zoomProjectionType = cam->projectionType;

    return EVT_RET_CONTINUE;
}

s32 evt_cam_zoom_to_coords(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 time = evtGetValue(entry, args[0]);
    s32 type = evtGetValue(entry, args[1]);
    CamEntry * cam = camGetPtr(5);
    if (cam->cameraMode == 2)
    {
        cam->zoomStartPos.x = cam->pos.x;
        cam->zoomStartPos.y = cam->pos.y;
        cam->zoomStartPos.z = cam->pos.z;
        cam->zoomStartTarget.x = cam->target.x;
        cam->zoomStartTarget.y = cam->target.y;
        cam->zoomStartTarget.z = cam->target.z;
        cam->zoomStartTime = gp->time;
        cam->zoomTime = time;
        cam->zoomType = type;
        cam->unknown_0xe4 = 0;
        cam->cameraMode = 2;
        cam->unknown_0x250 = 1;
    }

    return EVT_RET_CONTINUE;
}

s32 evt_cam_look_at_door(EvtEntry * entry, bool isFirstCall)
{
    EvtScriptCode * args = entry->pCurData;
    MarioWork * mp = marioGetPtr();
    CamEntry * cam = camGetPtr(5);
    s32 wait = evtGetValue(entry, args[0]);
    s32 to3d = evtGetValue(entry, args[1]);

    if (isFirstCall)
    {
        entry->tempS[0] = 0;
        if (!camCheck3d(mp->camId))
        {
            if (to3d)
                func_80058404(mp->camId, 0);
            else
                return EVT_RET_CONTINUE;
        }
        else
        {
            if (!to3d)
            {
                if ((mp->dispFlags & 0x80000000) && strcmp(gp->mapName, "mac_03") != 0)
                {
                    if (evtDoorGetActiveDoorDesc() == NULL)
                    {
                        Vec3 dir = *(Vec3 *) camGetPtr(mp->camId)->viewMtx[2];
                        if (dir.x > 0.0f)
                            entry->tempS[0] = 2;
                        else
                            entry->tempS[0] = 1;
                    }
                    else
                    {
                        Vec3 dir = *(Vec3 *) camGetPtr(mp->camId)->viewMtx[2];
                        if (dir.z > 0.0f)
                            entry->tempS[0] = 2;
                        else
                            entry->tempS[0] = 1;
                    }
                }
                func_80058404(mp->camId, 1);
            }
            else
            {
                return EVT_RET_CONTINUE;
            }
        }

        if (to3d)
            spsndSFXOn("SFX_SYS_3D1");
        else
            spsndSFXOn("SFX_SYS_2D1");
    }

    if (!wait || cam->unknown_0xe4 >= cam->unknown_0xe0)
    {
        if (entry->tempS[0] == 1)
        {
            mp->dispDirectionTarget = 180.0f;
            mp->directionView = func_80150688(mp->dispDirectionTarget);
            mp->directionWorld = mp->directionView;
        }
        else if (entry->tempS[0] == 2)
        {
            mp->dispDirectionTarget = 0.0f;
            mp->directionView = func_80150688(mp->dispDirectionTarget);
            mp->directionWorld = mp->directionView;
        }

        return EVT_RET_CONTINUE;
    }

    return EVT_RET_BLOCK_WEAK;
}

s32 func_800e0720(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 type = evtGetValue(entry, args[0]);
    f32 value = evtGetFloat(entry, args[1]);
    CamEntry * cam = camGetPtr(5);
    if (type == 0)
    {
        if (cam->unknown_0xec > value)
            return EVT_RET_CONTINUE;
    }
    else
    {
        if (cam->unknown_0xe8 > value)
            return EVT_RET_CONTINUE;
    }

    return EVT_RET_BLOCK_WEAK;
}

s32 func_800e07bc(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    f32 x = evtGetFloat(entry, args[0]);
    f32 y = evtGetFloat(entry, args[1]);
    f32 z = evtGetFloat(entry, args[2]);
    CamEntry * cam = camGetPtr(marioGetPtr()->camId);
    cam->flag |= 0x10;
    Vec3 pos = {x, y, z};
    cam->unknown_0x100 = pos;
    cam->unknown_0x10c = y;

    return EVT_RET_CONTINUE;
}

s32 func_800e0890(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 id = evtGetValue(entry, args[0]);
    s32 value = evtGetValue(entry, args[1]);
    camGetPtr(id)->unknown_0x25c = value;

    return EVT_RET_CONTINUE;
}

s32 func_800e08f8(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    if (func_800583b4())
        return EVT_RET_BLOCK_WEAK;

    return EVT_RET_CONTINUE;
}

s32 func_800e092c(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    MarioWork * mp = marioGetPtr();
    CamEntry * cam = camGetPtr(mp->camId);
    func_800531a0();
    func_800547a0();
    cam->unknown_0x100.x = mp->position.x;
    cam->unknown_0x100.y = mp->position.y;
    cam->unknown_0x100.z = mp->position.z;
    cam->unknown_0x10c = cam->unknown_0x100.y;

    return EVT_RET_CONTINUE;
}

s32 evt_cam_check_dimension(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    if (evtGetValue(entry, args[0]))
        evtSetValue(entry, args[1], camCheck3d(5));
    else
        evtSetValue(entry, args[1], !camCheck3d(5));

    return EVT_RET_CONTINUE;
}

s32 func_800e0a14(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    if (camGetPtr(11)->flag & 0x10000000)
        evtSetValue(entry, args[0], 1);
    else
        evtSetValue(entry, args[0], 0);

    return EVT_RET_CONTINUE;
}

s32 func_800e0a84(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 no = evtGetValue(entry, args[0]);
    f32 param_2 = evtGetFloat(entry, args[1]);
    f32 param_3 = evtGetFloat(entry, args[2]);

    // "Strange"
    SPM_ASSERT(451, no == 0 || no == 1, "おかしい");

    lbl_80407d88[no].unknown_0x18 = param_2;
    lbl_80407d88[no].unknown_0x1c = param_3;

    return EVT_RET_CONTINUE;
}

s32 func_800e0b58(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    if (func_8005881c())
        return EVT_RET_BLOCK_WEAK;

    return EVT_RET_CONTINUE;
}

s32 func_800e0b8c(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    func_80058840(evtGetFloat(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 func_800e0bbc(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 param_1 = evtGetValue(entry, args[0]);
    if (evtGetValue(entry, args[1]))
    {
        if (param_1)
            func_80053214();
        else
            func_800532a8();
    }
    else
    {
        if (param_1)
            func_8005333c();
        else
            func_80053384();
    }

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_800e0c40

}
