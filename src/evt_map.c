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

// NOT_DECOMPILED evt_mapobj_flag_onoff

// NOT_DECOMPILED evt_mapobj_flag4_onoff

// NOT_DECOMPILED func_800ee0b4

// NOT_DECOMPILED func_800ee13c

// NOT_DECOMPILED evt_mapobj_get_position

// NOT_DECOMPILED func_800ee290

// NOT_DECOMPILED func_800ee51c

// NOT_DECOMPILED evt_mapdisp_onoff

// NOT_DECOMPILED func_800ee59c

// NOT_DECOMPILED evt_mapobj_blendmode

// NOT_DECOMPILED func_800ee9f4

// NOT_DECOMPILED func_800eec8c

// NOT_DECOMPILED func_800eee68

// NOT_DECOMPILED func_800ef198

}
