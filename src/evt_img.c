#include <common.h>
#include <evt_cmd.h>
#include <spm/animdrv.h>
#include <spm/evt_img.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>
#include <spm/imgdrv.h>
#include <spm/spmario.h>

extern "C" {

s32 evt_img_entry(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    func_80076c8c((const char *) evtGetValue(entry, entry->pCurData[0]), gp->unknown_0xc4 != 0);

    return EVT_RET_CONTINUE;
}

s32 evt_img_set_position(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    f32 x = evtGetFloat(entry, args[1]);
    f32 y = evtGetFloat(entry, args[2]);
    ImgEntry * img = func_8007706c((const char *) name, gp->unknown_0xc4 != 0);
    img->position.x = x;
    img->position.y = y;

    return EVT_RET_CONTINUE;
}

s32 evt_img_set_paper(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    s32 paperName = evtGetValue(entry, args[1]);
    bool flag = gp->unknown_0xc4 != 0;
    ImgEntry * img = func_8007706c((const char *) name, flag);
    img->animPoseId = animPaperPoseGetId((const char *) paperName, flag);
    img->animStartTime = animTimeGetTime(flag);
    animPoseSetFlagF0On(img->animPoseId, 0x60000000);

    return EVT_RET_CONTINUE;
}

s32 evt_img_set_paper_anim(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    s32 anim = evtGetValue(entry, args[1]);
    bool flag = gp->unknown_0xc4 != 0;
    ImgEntry * img = func_8007706c((const char *) name, flag);
    img->unknown_0x108 = anim;
    img->animStartTime = animTimeGetTime(flag);

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED evt_img_alloc_capture

s32 evt_img_free_capture(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    s32 free = evtGetValue(entry, args[1]);
    ImgEntry * img = func_8007706c((const char *) name, gp->unknown_0xc4 != 0);
    if (free)
        img->flags &= ~2;
    else
        img->flags |= 2;

    return EVT_RET_CONTINUE;
}

s32 evt_img_clear_virtual_space(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    func_80077178(func_8007706c((const char *) evtGetValue(entry, entry->pCurData[0]), gp->unknown_0xc4 != 0));

    return EVT_RET_CONTINUE;
}

s32 evt_img_release(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    ImgEntry * img = func_8007706c((const char *) evtGetValue(entry, entry->pCurData[0]), gp->unknown_0xc4 != 0);
    func_80077188(img, gp->unknown_0xc4 != 0);

    return EVT_RET_CONTINUE;
}

s32 evt_img_wait_animend(EvtEntry * entry, bool isFirstCall)
{
    ImgEntry * img = func_8007706c((const char *) evtGetValue(entry, entry->pCurData[0]),
                                   gp->unknown_0xc4 != 0);
    if (isFirstCall)
        return EVT_RET_BLOCK_WEAK;

    if (img->unknown_0x118 < 1.0f)
        return EVT_RET_BLOCK_WEAK;

    return EVT_RET_CONTINUE;
}

s32 func_800ec998(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    u8 r = (u8) evtGetValue(entry, args[1]);
    u8 g = (u8) evtGetValue(entry, args[2]);
    u8 b = (u8) evtGetValue(entry, args[3]);
    u8 a = (u8) evtGetValue(entry, args[4]);
    ImgEntry * img = func_8007706c((const char *) name, gp->unknown_0xc4 != 0);
    animPoseSetFlagF0On(img->animPoseId, 0x2000);
    animPoseSetMaterialEvtColor(img->animPoseId, (GXColor) {r, g, b, a});

    return EVT_RET_CONTINUE;
}

s32 func_800eca64(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    f32 value = evtGetFloat(entry, args[1]);
    func_8007706c((const char *) name, gp->unknown_0xc4 != 0)->unknown_0xfc = value;

    return EVT_RET_CONTINUE;
}

s32 func_800ecae0(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    s32 value = evtGetValue(entry, args[1]);
    func_8007706c((const char *) name, gp->unknown_0xc4 != 0)->unknown_0x150 = value;

    return EVT_RET_CONTINUE;
}

s32 func_800ecb5c(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    s32 value = evtGetValue(entry, args[1]);
    func_8007706c((const char *) name, gp->unknown_0xc4 != 0)->unknown_0x154 = value;

    return EVT_RET_CONTINUE;
}

s32 func_800ecbd8(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    s32 on = evtGetValue(entry, args[1]);
    u32 flags = (u32) evtGetValue(entry, args[2]);
    ImgEntry * img = func_8007706c((const char *) name, gp->unknown_0xc4 != 0);
    if (on)
        img->flags |= flags;
    else
        img->flags &= ~flags;

    return EVT_RET_CONTINUE;
}

}
