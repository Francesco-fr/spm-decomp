/*
    WARNING: Not fully decompiled
    This file is currently not linked into the final dol
*/

#include <common.h>
#include <msl/string.h>
#include <spm/camdrv.h>
#include <spm/effdrv.h>
#include <spm/gxsub.h>
#include <spm/memory.h>
#include <spm/spmario.h>
#include <spm/sptexture.h>
#include <spm/system.h>
#include <spm/windowdrv.h>
#include <wii/gx.h>
#include <wii/mtx.h>

extern "C" {

// .sbss
static WindowEntry * wp;
static u32 lbl_805ae794;
static u32 lbl_805ae798;
static u32 lbl_805ae79c;

void windowInit()
{
    WindowEntry * entries = (WindowEntry *) __memAlloc(HEAP_MAIN, sizeof(WindowEntry[WINDOW_MAX]));
    wp = entries;
    for (s32 i = 0; i < WINDOW_MAX; i++)
    {
        entries[i].flags = 0;
        entries[i].speakerSp = 0;
    }
}

void windowReInit()
{
    WindowEntry * entries = wp;
    for (s32 i = 0; i < WINDOW_MAX; i++)
    {
        entries[i].flags = 0;
        entries[i].speakerSp = 0;
    }
}

s32 windowEntry(u16 pri)
{
    WindowEntry * entry = wp;
    for (s32 i = 0; i < WINDOW_MAX; i++, entry++)
    {
        if ((entry->flags & 1) == 0)
        {
            memset(entry, 0, sizeof(*entry));
            entry->flags = 1;
            entry->priority = pri;
            return i;
        }
    }
    return -1;
}

bool windowDelete(WindowEntry * entry)
{
    if (entry->deleteFunc != NULL)
        entry->deleteFunc(entry);

    entry->flags = 0;
    entry->speakerSp = 0;

    return true;
}

bool windowDeleteID(s32 id)
{
    WindowEntry * entry = &wp[id];
    if ((entry->flags & 1) == 0)
        return false;
    else
        return windowDelete(entry);
}

void windowMain()
{
    WindowEntry * entry = wp;
    for (s32 i = 0; i < WINDOW_MAX; i++, entry++)
    {
        if ((entry->flags & 1) && (entry->mainFunc != NULL))
            entry->mainFunc(entry);
    }
}

void func_80038b08()
{
    GXSetCullMode(0);
    GXSetZCompLoc(1);
    GXSetAlphaCompare(7, 0, 0, 7, 0);
    GXSetBlendMode(1, 4, 5, 7);
    GXSetZMode(1, 7, 0);

    GXColor fogColour = {0xff, 0xff, 0xff, 0xff};
    GXSetFog(0, 0.0f, 0.0f, 0.0f, 0.0f, &fogColour);

    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(13, 1);
    GXSetVtxAttrFmt(0, 9, 1, 4, 0);
    GXSetVtxAttrFmt(0, 13, 1, 4, 0);
    GXSetTexCoordGen2(0, 1, 4, 60, 0, 125);

    GXSetNumChans(0);
    GXSetNumTexGens(1);
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0, 0, 0xff);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevColorIn(0, 15, 2, 8, 15);
    GXSetTevAlphaIn(0, 7, 1, 4, 7);
    GXSetTevSwapMode(0, 0, 0);
    GXSetCurrentMtx(0);
}

// NOT_DECOMPILED func_80038cc0

// NOT_DECOMPILED func_80038fb8

// NOT_DECOMPILED windowDispGX_Kanban

// NOT_DECOMPILED func_800393c8

// NOT_DECOMPILED windowDispGX_System

// NOT_DECOMPILED func_80039b80

// NOT_DECOMPILED func_80039d40

void windowDispGX_Message(s32 type, Unk param_2, u8 alpha, f32 x, f32 y, f32 width, f32 height,
                          f32 param_9, f32 param_10)
{
    func_80038b08();

    switch (type)
    {
        case 1:
            func_80039d40(type, param_2, alpha, true, x, y, width, height, param_9, param_10);
            func_80039d40(type, param_2, alpha, false, x, y, width, height, param_9, param_10);
            break;

        case 11:
        case 12:
            func_80038cc0();
            func_80039d40(type, param_2, alpha, true, x, y, width, height, param_9, param_10);
            func_80038b08();
            func_80039d40(type, param_2, alpha, false, x, y, width, height, param_9, param_10);
            break;

        default:
            func_80039d40(type, param_2, alpha, true, x, y, width, height, param_9, param_10);
            func_80039d40(type, param_2, alpha, false, x, y, width, height, param_9, param_10);
            break;
    }
}

// NOT_DECOMPILED windowDispGX_ItemBox

// NOT_DECOMPILED windowDispGX2_Waku_col

s32 windowCheckID(s32 id)
{
    return wp[id].flags & 2;
}

WindowEntry * windowGetPointer(s32 id)
{
    return &wp[id];
}

bool windowCheckOpen()
{
    WindowEntry * entry = wp;
    for (s32 i = 0; i < WINDOW_MAX; i++, entry++)
    {
        if ((entry->flags & 1) && (entry->type != 1))
            return true;
    }

    return false;
}
}
