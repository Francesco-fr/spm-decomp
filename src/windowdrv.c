/*
    WARNING: Not fully decompiled
    This file is currently not linked into the final dol
*/

#include <common.h>
#include <msl/math.h>
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
static f32 lbl_805ae794;
static f32 lbl_805ae798;
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

void func_80038cc0()
{
    GXTexObj texObj;
    Mtx34 mtx;
    Mtx34 lightMtx;

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
    GXSetTexCoordGen2(1, 1, 0, 33, 0, 125);

    GXSetNumChans(0);
    GXSetNumTexGens(2);
    GXSetNumTevStages(2);

    // Scroll texture
    lbl_805ae794 += 0.005f;
    if (lbl_805ae794 > 1.0f)
        lbl_805ae794 -= 1.0f;
    C_MTXLightOrtho(lightMtx, 0.0f, 512.0f, 0.0f, 512.0f, 0.5f, 0.5f, -lbl_805ae794,
                    -lbl_805ae794);
    PSMTXRotRad(mtx, 'z', 0.7853982f);
    PSMTXConcat(lightMtx, mtx, mtx);
    GXLoadTexMtxImm(mtx, 33, 1);
    effGetTexObj(34, &texObj);
    GXLoadTexObj(&texObj, 1);

    GXSetTevOrder(0, 0, 0, 0xff);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevColorIn(0, 15, 2, 8, 15);
    GXSetTevAlphaIn(0, 7, 1, 4, 7);
    GXSetTevSwapMode(0, 0, 0);

    GXSetTevOrder(1, 1, 1, 0xff);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetTevColorIn(1, 15, 15, 15, 8);
    GXSetTevAlphaIn(1, 7, 7, 7, 0);
    GXSetTevSwapMode(1, 0, 0);

    GXSetCurrentMtx(0);
}

void func_80038fb8(s32 texId, f32 x, f32 y, f32 width, f32 height)
{
    GXTexObj texObj;
    Mtx34 mtx;
    f32 scaleX;
    f32 scaleY;

    sptextureGet(texId, &texObj);
    GXSetTexCoordGen2(0, 1, 4, 30, 0, 125);
    scaleY = fabsf(height) / GXGetTexObjHeight(&texObj);
    scaleX = fabsf(width) / GXGetTexObjWidth(&texObj);
    PSMTXScale(mtx, scaleX, scaleY, 1.0f);
    GXLoadTexMtxImm(mtx, 30, 1);
    GXLoadTexObj(&texObj, 0);

    GXBegin(0x80, 0, 4);
    GXPosition3f32(x, y, 0.0f);
    GXTexCoord2f32(0.0f, 0.0f);
    GXPosition3f32(x + width, y, 0.0f);
    GXTexCoord2f32(1.0f, 0.0f);
    GXPosition3f32(x + width, y - height, 0.0f);
    GXTexCoord2f32(1.0f, 1.0f);
    GXPosition3f32(x, y - height, 0.0f);
    GXTexCoord2f32(0.0f, 1.0f);
    GXEnd();
}

void windowDispGX_Kanban(s32 type, GXColor colour, f32 x, f32 y, f32 width, f32 height)
{
    CamEntry * cam;
    Mtx34 mtx;
    Mtx34 scale;

    cam = camGetCurPtr();
    func_80038b08();
    GXSetTevColor(1, colour);

    PSMTXTrans(mtx, x, y, 0.0f);
    PSMTXScale(scale, width / 560.0f, height / 176.0f, 1.0f);
    PSMTXConcat(mtx, scale, mtx);
    PSMTXConcat(cam->viewMtx, mtx, mtx);
    GXLoadPosMtxImm(mtx, 0);
    GXSetCurrentMtx(0);

    switch (type)
    {
        case 2:
        case 4:
            func_80038fb8(30, 0.0f, 0.0f, 72.0f, 176.0f);
            func_80038fb8(32, 72.0f, 0.0f, 416.0f, 136.0f);
            func_80038fb8(31, 488.0f, 0.0f, 72.0f, 176.0f);
            func_80038fb8(33, 72.0f, -136.0f, 416.0f, 40.0f);
            break;

        case 9:
            func_80038fb8(26, 0.0f, 0.0f, 72.0f, 176.0f);
            func_80038fb8(28, 72.0f, 0.0f, 416.0f, 136.0f);
            func_80038fb8(27, 488.0f, 0.0f, 72.0f, 176.0f);
            func_80038fb8(29, 72.0f, -136.0f, 416.0f, 40.0f);
            break;

        case 7:
            func_80038fb8(7, 0.0f, 0.0f, 560.0f, 176.0f);
            break;

        default:
            SPM_ASSERT_NM(464, 0);
    }
}

void func_800393c8(s32 texId1, s32 texId2, f32 x, f32 y, f32 width, f32 height, f32 scroll)
{
    GXTexObj texObj0;
    GXTexObj texObj1;
    GXTexObj texObj2;
    Mtx34 scale;
    Mtx34 mtx;
    f32 transX;
    f32 transY;
    f32 scaleX;
    f32 scaleY;

    sptextureGet(6, &texObj0);
    sptextureGet(texId1, &texObj1);
    sptextureGet(texId2, &texObj2);
    GXLoadTexObj(&texObj0, 0);
    GXLoadTexObj(&texObj1, 1);
    GXLoadTexObj(&texObj2, 2);
    GXSetNumTexGens(2);

    GXSetTexCoordGen2(0, 1, 4, 30, 0, 125);
    transY = -y / GXGetTexObjHeight(&texObj0) - scroll;
    transX = scroll + x / GXGetTexObjWidth(&texObj0);
    PSMTXTrans(mtx, transX, transY, 0.0f);
    scaleY = fabsf(height) / GXGetTexObjHeight(&texObj0);
    scaleX = fabsf(width) / GXGetTexObjWidth(&texObj0);
    PSMTXScale(scale, scaleX, scaleY, 1.0f);
    PSMTXConcat(mtx, scale, mtx);
    GXLoadTexMtxImm(mtx, 30, 1);

    GXSetTexCoordGen2(1, 1, 4, 33, 0, 125);
    scaleY = fabsf(height) / GXGetTexObjHeight(&texObj1);
    scaleX = fabsf(width) / GXGetTexObjWidth(&texObj1);
    PSMTXScale(scale, scaleX, scaleY, 1.0f);
    GXLoadTexMtxImm(scale, 33, 1);

    GXBegin(0x80, 0, 4);
    GXPosition3f32(x, y, 0.0f);
    GXTexCoord2f32(0.0f, 0.0f);
    GXPosition3f32(x + width, y, 0.0f);
    GXTexCoord2f32(1.0f, 0.0f);
    GXPosition3f32(x + width, y - height, 0.0f);
    GXTexCoord2f32(1.0f, 1.0f);
    GXPosition3f32(x, y - height, 0.0f);
    GXTexCoord2f32(0.0f, 1.0f);
    GXEnd();
}

void windowDispGX_System(s32 type, u8 alpha, f32 x, f32 y, f32 width, f32 height)
{
    CamEntry * cam;
    Mtx34 mtx;

    cam = camGetCurPtr();

    // Scroll pattern once per frame
    if (lbl_805ae79c != gp->frameCounter)
        lbl_805ae798 += 0.005f;
    lbl_805ae79c = gp->frameCounter;
    if (lbl_805ae798 > 10.0f)
        lbl_805ae798 -= 10.0f;

    func_80038b08();
    GXSetTevColor(1, (GXColor) {0xff, 0xff, 0xff, alpha});
    GXSetNumTevStages(4);

    GXSetTevOrder(0, 0, 0, 0xff);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevColorIn(0, 15, 15, 15, 8);
    GXSetTevAlphaIn(0, 7, 7, 7, 4);
    GXSetTevSwapMode(0, 0, 0);

    GXSetTevOrder(1, 1, 1, 0xff);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetTevColorIn(1, 15, 15, 15, 0);
    GXSetTevAlphaIn(1, 7, 0, 4, 7);
    GXSetTevSwapMode(1, 0, 0);

    GXSetTevOrder(2, 1, 2, 0xff);
    GXSetTevColorOp(2, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(2, 0, 0, 0, 1, 0);
    GXSetTevColorIn(2, 0, 8, 9, 15);
    GXSetTevAlphaIn(2, 7, 7, 7, 0);
    GXSetTevSwapMode(2, 0, 0);

    GXSetTevOrder(3, 0xff, 0xff, 0xff);
    GXSetTevColorOp(3, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(3, 0, 0, 0, 1, 0);
    GXSetTevColorIn(3, 15, 0, 2, 15);
    GXSetTevAlphaIn(3, 7, 0, 1, 7);
    GXSetTevSwapMode(3, 0, 0);

    PSMTXTrans(mtx, x, y, 0.0f);
    PSMTXConcat(cam->viewMtx, mtx, mtx);
    GXLoadPosMtxImm(mtx, 0);
    GXSetCurrentMtx(0);

    if (type != 13)
    {
        func_800393c8(42, 46, 0.0f, 0.0f, width - 32.0f, height - 32.0f, lbl_805ae798);
        func_800393c8(43, 47, 0.0f, -(height - 32.0f), width - 32.0f, 32.0f, lbl_805ae798);
        func_800393c8(44, 48, width - 32.0f, 0.0f, 32.0f, height - 32.0f, lbl_805ae798);
        func_800393c8(45, 49, width - 32.0f, -(height - 32.0f), 32.0f, 32.0f, lbl_805ae798);
    }
    else
    {
        func_800393c8(62, 66, 0.0f, 0.0f, width - 32.0f, height - 32.0f, 0.0f);
        func_800393c8(63, 67, 0.0f, -(height - 32.0f), width - 32.0f, 32.0f, 0.0f);
        func_800393c8(64, 68, width - 32.0f, 0.0f, 32.0f, height - 32.0f, 0.0f);
        func_800393c8(65, 69, width - 32.0f, -(height - 32.0f), 32.0f, 32.0f, 0.0f);
    }
}

void func_80039b80(u8 alpha, f32 x, f32 y, f32 width, f32 height)
{
    CamEntry * cam = camGetCurPtr();
    gxsubInit_Cam(cam);
    gxsubDrawQuad(x, y, width, height, (GXColor) {0x3d, 0x00, 0x89, (u8) (alpha * 60 / 100)});
    func_80038b08();
    GXSetTevColor(1, (GXColor) {0xff, 0xff, 0xff, alpha});
    GXLoadPosMtxImm(cam->viewMtx, 0);
    GXSetCurrentMtx(0);

    f32 scaleX = width / 560.0f;
    f32 scaleY = height / 176.0f;
    func_80038fb8(61, x, y, 560.0f * scaleX - 16.0f, 176.0f * scaleY - 16.0f);
    func_80038fb8(61, x + 560.0f * scaleX, y, -16.0f, 176.0f * scaleY - 16.0f);
    func_80038fb8(61, x, y - 176.0f * scaleY, 560.0f * scaleX - 16.0f, -16.0f);
    func_80038fb8(61, x + 560.0f * scaleX, y - 176.0f * scaleY, -16.0f, -16.0f);
}

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
