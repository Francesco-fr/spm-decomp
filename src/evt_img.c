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

// NOT_DECOMPILED evt_img_set_paper

// NOT_DECOMPILED evt_img_set_paper_anim

// NOT_DECOMPILED evt_img_alloc_capture

// NOT_DECOMPILED evt_img_free_capture

// NOT_DECOMPILED evt_img_clear_virtual_space

// NOT_DECOMPILED evt_img_release

// NOT_DECOMPILED evt_img_wait_animend

// NOT_DECOMPILED func_800ec998

// NOT_DECOMPILED func_800eca64

// NOT_DECOMPILED func_800ecae0

// NOT_DECOMPILED func_800ecb5c

// NOT_DECOMPILED func_800ecbd8

}
