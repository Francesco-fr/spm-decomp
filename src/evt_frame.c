#include <common.h>
#include <evt_cmd.h>
#include <spm/evt_frame.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>
#include <spm/framedrv.h>

extern "C" {

s32 evt_frame_offscreen_draw_flag_onoff(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 on = evtGetValue(entry, args[0]);
    s32 name = evtGetValue(entry, args[1]);
    if (on)
        func_80068254((const char *) name)->flags |= 0x40;
    else
        func_80068254((const char *) name)->flags &= ~0x40;

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED evt_frame_offscreen_entry

s32 evt_frame_bind_offscreen(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    s32 offsName = evtGetValue(entry, args[1]);
    s32 callback = evtGetValue(entry, args[2]);
    func_800691c0((const char *) name, (const char *) offsName);
    func_80069284((const char *) name, (void *) callback);

    return EVT_RET_CONTINUE;
}

s32 evt_frame_set_img_anim(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    s32 animDef = evtGetValue(entry, args[1]);
    func_80069334((const char *) name, (const char *) animDef);

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED evt_frame_set_color

// NOT_DECOMPILED func_800e8b48

// NOT_DECOMPILED func_800e8be8

// NOT_DECOMPILED func_800e8cd0

// NOT_DECOMPILED func_800e8d0c

// NOT_DECOMPILED func_800e8d98

// NOT_DECOMPILED func_800e8e2c

// NOT_DECOMPILED func_800e8e94

// NOT_DECOMPILED func_800e8f4c

// NOT_DECOMPILED func_800e902c

// NOT_DECOMPILED func_800e90e4

// NOT_DECOMPILED func_800e9178

}
