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

s32 evt_frame_set_color(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    s32 r = evtGetValue(entry, args[1]);
    s32 g = evtGetValue(entry, args[2]);
    s32 b = evtGetValue(entry, args[3]);
    s32 a = evtGetValue(entry, args[4]);
    FrameEntry * frame = func_80068254((const char *) name);
    frame->color.r = (u8) r;
    frame->color.g = (u8) g;
    frame->color.b = (u8) b;
    frame->color.a = (u8) a;

    return EVT_RET_CONTINUE;
}

s32 func_800e8b48(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 on = evtGetValue(entry, args[0]);
    s32 name = evtGetValue(entry, args[1]);
    u32 flags = (u32) evtGetValue(entry, args[2]);
    FrameEntry * frame = func_80068254((const char *) name);
    if (on)
        frame->flags |= flags;
    else
        frame->flags &= ~flags;

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_800e8be8

s32 func_800e8cd0(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    return func_8006972c((const char *) evtGetValue(entry, entry->pCurData[0])) ?
        EVT_RET_CONTINUE : EVT_RET_BLOCK_WEAK;
}

s32 func_800e8d0c(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    f32 speed = (f32) evtGetValue(entry, args[1]);
    func_80068254((const char *) name)->drawSpeed = speed;

    return EVT_RET_CONTINUE;
}

s32 func_800e8d98(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    s32 r = evtGetValue(entry, args[1]);
    s32 g = evtGetValue(entry, args[2]);
    s32 b = evtGetValue(entry, args[3]);
    s32 a = evtGetValue(entry, args[4]);
    FrameEntry * frame = func_80068254((const char *) name);
    frame->wireColor.r = (u8) r;
    frame->wireColor.g = (u8) g;
    frame->wireColor.b = (u8) b;
    frame->wireColor.a = (u8) a;

    return EVT_RET_CONTINUE;
}

s32 func_800e8e2c(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    s32 width = evtGetValue(entry, args[1]);
    func_80068254((const char *) name)->wireLineWidth = width;

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_800e8e94

// NOT_DECOMPILED func_800e8f4c

// NOT_DECOMPILED func_800e902c

// NOT_DECOMPILED func_800e90e4

// NOT_DECOMPILED func_800e9178

}
