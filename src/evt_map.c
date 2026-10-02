#include <common.h>
#include <evt_cmd.h>
#include <spm/evt_map.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>
#include <spm/mapdrv.h>

extern "C" {

s32 evt_mapobj_trans(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    f32 x = evtGetFloat(entry, args[1]);
    f32 y = evtGetFloat(entry, args[2]);
    f32 z = evtGetFloat(entry, args[3]);
    mapObjTranslate((const char *) name, x, y, z);

    return EVT_RET_CONTINUE;
}

s32 evt_mapobj_rotate(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    f32 x = evtGetFloat(entry, args[1]);
    f32 y = evtGetFloat(entry, args[2]);
    f32 z = evtGetFloat(entry, args[3]);
    mapObjRotate((const char *) name, x, y, z);

    return EVT_RET_CONTINUE;
}

s32 func_800ed7f8(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    f32 x = evtGetFloat(entry, args[1]);
    f32 y = evtGetFloat(entry, args[2]);
    f32 z = evtGetFloat(entry, args[3]);
    mapObjScale((const char *) name, x, y, z);

    return EVT_RET_CONTINUE;
}

s32 evt_map_set_fog(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 groupId = evtGetValue(entry, args[0]);
    s32 type = evtGetValue(entry, args[1]);
    f32 startZ = evtGetFloat(entry, args[2]);
    f32 endZ = evtGetFloat(entry, args[3]);
    s32 r = evtGetValue(entry, args[4]);
    s32 g = evtGetValue(entry, args[5]);
    s32 b = evtGetValue(entry, args[6]);
    mapSetFog(groupId, type, (GXColor) {(u8) r, (u8) g, (u8) b, 0xff}, startZ, endZ);

    return EVT_RET_CONTINUE;
}

s32 evt_map_fog_onoff(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    if (evtGetValue(entry, entry->pCurData[0]))
        mapFogOn();
    else
        mapFogOff();

    return EVT_RET_CONTINUE;
}

s32 func_800ed9b0(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 which = evtGetValue(entry, args[0]);
    s32 r = evtGetValue(entry, args[1]);
    s32 g = evtGetValue(entry, args[2]);
    s32 b = evtGetValue(entry, args[3]);
    s32 a = evtGetValue(entry, args[4]);
    if (which == 0)
        mapSetBlend((GXColor) {(u8) r, (u8) g, (u8) b, (u8) a});
    else
        mapSetBlend2((GXColor) {(u8) r, (u8) g, (u8) b, (u8) a});

    return EVT_RET_CONTINUE;
}

s32 func_800eda74(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    if (evtGetValue(entry, entry->pCurData[0]) == 0)
        mapBlendOff();
    else
        mapBlendOff2();

    return EVT_RET_CONTINUE;
}

s32 func_800edab4(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 r = evtGetValue(entry, args[0]);
    s32 g = evtGetValue(entry, args[1]);
    s32 b = evtGetValue(entry, args[2]);
    s32 a = evtGetValue(entry, args[3]);
    mapSetColor((GXColor) {(u8) r, (u8) g, (u8) b, (u8) a});

    return EVT_RET_CONTINUE;
}

s32 evt_mapobj_color(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 group = evtGetValue(entry, args[0]);
    s32 name = evtGetValue(entry, args[1]);
    s32 r = evtGetValue(entry, args[2]);
    s32 g = evtGetValue(entry, args[3]);
    s32 b = evtGetValue(entry, args[4]);
    s32 a = evtGetValue(entry, args[5]);
    if (group == 0)
        mapObjSetColor((const char *) name, (GXColor) {(u8) r, (u8) g, (u8) b, (u8) a});
    else
        mapGrpSetColor((const char *) name, (GXColor) {(u8) r, (u8) g, (u8) b, (u8) a});

    return EVT_RET_CONTINUE;
}

s32 evt_map_playanim(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    s32 param_2 = evtGetValue(entry, args[1]);
    s32 level = evtGetValue(entry, args[2]);
    mapPlayAnimationLv((const char *) name, (Unk) param_2, level);

    return EVT_RET_CONTINUE;
}

s32 func_800edca8(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    mapDeleteAnimation((const char *) evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 evt_map_checkanim(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 finished;
    f32 remaining;
    mapCheckAnimation((const char *) evtGetValue(entry, args[0]), &finished, &remaining);
    evtSetValue(entry, args[1], finished);
    evtSetValue(entry, args[2], (s32) remaining);

    return EVT_RET_CONTINUE;
}

s32 func_800edd50(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 all = evtGetValue(entry, args[0]);
    s32 name = evtGetValue(entry, args[1]);
    if (all)
        mapPauseAnimationAll();
    else
        mapPauseAnimation((const char *) name);

    return EVT_RET_CONTINUE;
}

s32 func_800eddb4(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 all = evtGetValue(entry, args[0]);
    s32 name = evtGetValue(entry, args[1]);
    if (all)
        mapReStartAnimationAll();
    else
        mapReStartAnimation((const char *) name);

    return EVT_RET_CONTINUE;
}

s32 evt_map_set_playrate(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    mapSetPlayRate((const char *) name, evtGetFloat(entry, args[1]));

    return EVT_RET_CONTINUE;
}

s32 func_800ede70(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    mapSetPlayProgress((const char *) name, evtGetFloat(entry, args[1]));

    return EVT_RET_CONTINUE;
}

s32 func_800edec8(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    f32 duration = mapGetPlayDuration((const char *) evtGetValue(entry, args[0]));
    evtSetValue(entry, args[1], (s32) duration);

    return EVT_RET_CONTINUE;
}

s32 evt_mapobj_flag_onoff(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 group = evtGetValue(entry, args[0]);
    s32 on = evtGetValue(entry, args[1]);
    s32 name = evtGetValue(entry, args[2]);
    u32 mask = (u32) args[3];
    if (group == 0)
    {
        if (on == 0)
            mapObjFlagOff(false, (const char *) name, mask);
        else
            mapObjFlagOn(false, (const char *) name, mask);
    }
    else
    {
        if (on == 0)
            mapGrpFlagOff(false, (const char *) name, mask);
        else
            mapGrpFlagOn(false, (const char *) name, mask);
    }

    return EVT_RET_CONTINUE;
}

s32 evt_mapobj_flag4_onoff(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 group = evtGetValue(entry, args[0]);
    s32 on = evtGetValue(entry, args[1]);
    s32 name = evtGetValue(entry, args[2]);
    u32 mask = (u32) args[3];
    if (group == 0)
    {
        if (on == 0)
            mapObjFlag4Off(false, (const char *) name, mask);
        else
            mapObjFlag4On(false, (const char *) name, mask);
    }
    else
    {
        if (on == 0)
            mapGrpFlag4Off(false, (const char *) name, mask);
        else
            mapGrpFlag4On(false, (const char *) name, mask);
    }

    return EVT_RET_CONTINUE;
}

s32 func_800ee0b4(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 group = evtGetValue(entry, args[0]);
    s32 name = evtGetValue(entry, args[1]);
    s32 ofsName = evtGetValue(entry, args[2]);
    if (group == 0)
        mapObjSetOffScreen((const char *) name, (const char *) ofsName);
    else
        mapGrpSetOffScreen((const char *) name, (const char *) ofsName);

    return EVT_RET_CONTINUE;
}

s32 func_800ee13c(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 group = evtGetValue(entry, args[0]);
    s32 name = evtGetValue(entry, args[1]);
    s32 ofsName = evtGetValue(entry, args[2]);
    if (group == 0)
        mapObjClearOffScreen((const char *) name, (const char *) ofsName);
    else
        mapGrpClearOffScreen((const char *) name, (const char *) ofsName);

    return EVT_RET_CONTINUE;
}

s32 evt_mapobj_get_position(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    Vec3 pos;
    mapObjGetPos((const char *) evtGetValue(entry, args[0]), &pos);
    evtSetValue(entry, args[1], FLOAT(pos.x));
    evtSetValue(entry, args[2], FLOAT(pos.y));
    evtSetValue(entry, args[3], FLOAT(pos.z));

    return EVT_RET_CONTINUE;
}

void func_800ee290(MapObj * obj, s32 value)
{
    if (obj == NULL)
        return;

    obj->unknown_0x140 = value;
    if (obj->firstChild != NULL)
        func_800ee290(obj->firstChild, value);
    if (obj->nextSibling != NULL)
        func_800ee290(obj->nextSibling, value);
}

s32 func_800ee51c(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    s32 cb = evtGetValue(entry, entry->pCurData[0]);
    mapGetWork()->entries[0].unloadCb = (MapEntryUnloadCb *) cb;

    return EVT_RET_CONTINUE;
}

s32 evt_mapdisp_onoff(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    if (evtGetValue(entry, entry->pCurData[0]))
        mapDispOn();
    else
        mapDispOff();

    return EVT_RET_CONTINUE;
}

void func_800ee59c(MapObj * obj, s32 blendMode, bool noSiblings)
{
    obj->blendMode = (u8) blendMode;
    if (obj->firstChild != NULL)
        func_800ee59c(obj->firstChild, blendMode, false);
    if (!noSiblings && obj->nextSibling != NULL)
        func_800ee59c(obj->nextSibling, blendMode, false);
}

s32 evt_mapobj_blendmode(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 group = evtGetValue(entry, args[0]);
    s32 name = evtGetValue(entry, args[1]);
    s32 blendMode = evtGetValue(entry, args[2]);
    MapObj * obj = mapGetMapObj((const char *) name);
    if (group == 0)
        obj->blendMode = (u8) blendMode;
    else
        func_800ee59c(obj, blendMode, true);

    return EVT_RET_CONTINUE;
}

void func_800ee9f4(MapObj * obj, s32 value, bool noSiblings)
{
    obj->unknown_0x9 = (u8) value;
    if (obj->firstChild != NULL)
        func_800ee9f4(obj->firstChild, value, false);
    if (!noSiblings && obj->nextSibling != NULL)
        func_800ee9f4(obj->nextSibling, value, false);
}

// NOT_DECOMPILED func_800eec8c

// NOT_DECOMPILED func_800eee68

// NOT_DECOMPILED func_800ef198

}
