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

s32 func_800eadec(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    u32 attr = (u32) evtGetValue(entry, args[0]);
    MarioWork * mp = marioGetPtr();
    if (mp->hitObjs1[2] != NULL)
    {
        for (s32 i = 0; i < mp->numHitObjRideArray; i++)
        {
            if (mp->hitObjRideArray[i] != NULL && (attr & hitGetAttr(mp->hitObjRideArray[i])))
            {
                evtSetValue(entry, args[1], 1);
                return EVT_RET_CONTINUE;
            }
        }
    }
    else
    {
        if (mp->hitObjs1[7] != NULL && (attr & hitGetAttr(mp->hitObjs1[7])))
        {
            evtSetValue(entry, args[1], 1);
            return EVT_RET_CONTINUE;
        }
    }

    evtSetValue(entry, args[1], 0);

    return EVT_RET_CONTINUE;
}

void func_800eaed0(HitObj * hitObj, s32 value)
{
    if (hitObj == NULL)
        return;

    hitObj->unknown_0xe2 = (s16) value;
    if (hitObj->child != NULL)
        func_800eaed0(hitObj->child, value);
    if (hitObj->nextSibling != NULL)
        func_800eaed0(hitObj->nextSibling, value);
}

s32 func_800eb15c(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    s32 recursive = evtGetValue(entry, args[1]);
    s32 value = evtGetValue(entry, args[2]);
    if (!recursive)
    {
        HitObj * hitObj = hitNameToPtr((const char *) name);
        if (hitObj != NULL)
            hitObj->unknown_0xe2 = (s16) value;
    }
    else
    {
        HitObj * hitObj = hitNameToPtr((const char *) name);
        if (hitObj != NULL)
        {
            hitObj->unknown_0xe2 = (s16) value;
            if (hitObj->child != NULL)
                func_800eaed0(hitObj->child, value);
        }
    }

    return EVT_RET_CONTINUE;
}

s32 evt_hit_bind_mapobj(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    const char * hit_name = (const char *) evtGetValue(entry, args[0]);
    const char * map_name = (const char *) evtGetValue(entry, args[1]);

    // "There's no object with that name"
    SPM_ASSERT(228, hit_name, "そんな名前のオブジェはない");
    SPM_ASSERT(229, map_name, "そんな名前のオブジェはない");

    hitBindMapObj(hit_name, map_name);

    return EVT_RET_CONTINUE;
}

s32 evt_hit_bind_update(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    const char * hit_name = (const char *) evtGetValue(entry, entry->pCurData[0]);

    // "There's no object with that name"
    SPM_ASSERT(244, hit_name, "そんな名前のオブジェはない");

    hitBindUpdate(hit_name);

    return EVT_RET_CONTINUE;
}

s32 func_800eb564(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    Vec3 pos;
    hitObjGetPos((const char *) evtGetValue(entry, args[0]), &pos);
    evtSetFloat(entry, args[1], pos.x);
    evtSetFloat(entry, args[2], pos.y);
    evtSetFloat(entry, args[3], pos.z);

    return EVT_RET_CONTINUE;
}

s32 func_800eb5dc(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    Vec3 normal;
    hitObjGetNormal((const char *) evtGetValue(entry, args[0]), &normal);
    evtSetFloat(entry, args[1], normal.x);
    evtSetFloat(entry, args[2], normal.y);
    evtSetFloat(entry, args[3], normal.z);

    return EVT_RET_CONTINUE;
}

s32 func_800eb654(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 group = evtGetValue(entry, args[0]);
    s32 on = evtGetValue(entry, args[1]);
    s32 name = evtGetValue(entry, args[2]);
    EvtVar mask = args[3];
    if (group == 0)
    {
        if (on == 0)
            hitObjFlagOff(false, (const char *) name, (u16) mask);
        else
            hitObjFlagOn(false, (const char *) name, (u16) mask);
    }
    else
    {
        if (on == 0)
            hitGrpFlagOff(false, (const char *) name, (u16) mask);
        else
            hitGrpFlagOn(false, (const char *) name, (u16) mask);
    }

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED evt_hitobj_attr_onoff

// NOT_DECOMPILED func_800eb7f4

// NOT_DECOMPILED func_800eb8bc

// NOT_DECOMPILED func_800ebd74

}
