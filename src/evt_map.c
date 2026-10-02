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

// NOT_DECOMPILED func_800ed7f8

// NOT_DECOMPILED evt_map_set_fog

// NOT_DECOMPILED evt_map_fog_onoff

// NOT_DECOMPILED func_800ed9b0

// NOT_DECOMPILED func_800eda74

// NOT_DECOMPILED func_800edab4

// NOT_DECOMPILED evt_mapobj_color

// NOT_DECOMPILED evt_map_playanim

// NOT_DECOMPILED func_800edca8

// NOT_DECOMPILED evt_map_checkanim

// NOT_DECOMPILED func_800edd50

// NOT_DECOMPILED func_800eddb4

// NOT_DECOMPILED evt_map_set_playrate

// NOT_DECOMPILED func_800ede70

// NOT_DECOMPILED func_800edec8

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
