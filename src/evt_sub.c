#include <common.h>
#include <evt_cmd.h>
#include <spm/evt_sub.h>
#include <spm/evtmgr.h>
#include <spm/animdrv.h>
#include <spm/camdrv.h>
#include <spm/dispdrv.h>
#include <spm/eff_pure_heart.h>
#include <spm/eff_sub.h>
#include <spm/effdrv.h>
#include <spm/evtmgr_cmd.h>
#include <spm/filemgr.h>
#include <spm/fontmgr.h>
#include <spm/gxsub.h>
#include <spm/hitdrv.h>
#include <spm/hud.h>
#include <spm/itemdrv.h>
#include <spm/item_data_ids.h>
#include <spm/lz_embedded.h>
#include <spm/mario.h>
#include <spm/mario_motion.h>
#include <spm/mario_status.h>
#include <spm/mobjdrv.h>
#include <spm/nameent.h>
#include <spm/parse.h>
#include <spm/mapdrv.h>
#include <spm/memory.h>
#include <spm/msgdrv.h>
#include <spm/pausewin.h>
#include <spm/seq_game.h>
#include <spm/spmario.h>
#include <spm/spmario_snd.h>
#include <spm/system.h>
#include <spm/winmgr.h>
#include <spm/wpadmgr.h>
#include <wii/cx.h>
#include <wii/gx.h>
#include <wii/mtx.h>
#include <wii/os.h>
#include <wii/tpl.h>
#include <wii/wpad.h>
#include <msl/math.h>
#include <msl/stdio.h>
#include <msl/string.h>

extern "C" {

typedef struct
{
/* 0x00 */ s32 count;
/* 0x04 */ f32 * table1;
/* 0x08 */ Vec3 * points;
/* 0x0C */ Vec3 * table2;
/* 0x10 */ s32 progress;
/* 0x14 */ s32 max;
/* 0x18 */ s32 mode;
/* 0x1C */ s32 msec;
/* 0x20 */ OSTime startTime;
/* 0x28 */ s32 useTime;
/* 0x2C */ u8 unknown_0x2c[0x30 - 0x2c];
} SplineWork;
SIZE_ASSERT(SplineWork, 0x30)

typedef struct
{
/* 0x00 */ s32 state;
/* 0x04 */ u32 flags;
/* 0x08 */ OSTime time;
/* 0x10 */ s32 alpha;
/* 0x14 */ s32 chapter;
/* 0x18 */ s32 level;
/* 0x1C */ EffEntry * effect;
/* 0x20 */ s32 animPoseId;
/* 0x24 */ u8 unknown_0x24[0x28 - 0x24];
/* 0x28 */ s32 textAlpha;
/* 0x2C */ TPLHeader * tpl;
/* 0x30 */ s32 bgAlpha;
/* 0x34 */ u8 unknown_0x34[0x38 - 0x34];
} RoomNameWork;
SIZE_ASSERT(RoomNameWork, 0x38)

typedef struct
{
/* 0x00 */ s32 name;
/* 0x04 */ s32 type;
/* 0x08 */ s32 state;
/* 0x0C */ s32 alpha;
/* 0x10 */ OSTime time;
/* 0x18 */ u8 unknown_0x18[0x28 - 0x18];
} RoomNameDispWork;
SIZE_ASSERT(RoomNameDispWork, 0x28)

typedef struct
{
/* 0x00 */ u16 flags;
/* 0x04 */ s32 maxLen;
/* 0x08 */ s32 done;
/* 0x0C */ s32 winIds[2];
/* 0x14 */ s32 cursorX;
/* 0x18 */ s32 cursorY;
/* 0x1C */ s32 len;
/* 0x20 */ char buf[32];
/* 0x40 */ s32 cols;
/* 0x44 */ s32 rows;
/* 0x48 */ const char ** table;
/* 0x4C */ s32 count;
} PasswordWork;
SIZE_ASSERT(PasswordWork, 0x50)

typedef struct
{
/* 0x000 */ const char * table[126];
/* 0x1F8 */ const char * tableEn[126];
/* 0x3F0 */ const char * numTable[12];
/* 0x420 */ const char * numTableEn[12];
/* 0x450 */ WindowDesc descs[2];
} PasswordData;
SIZE_ASSERT(PasswordData, 0x4a0)

typedef struct
{
/* 0x0 */ s32 id;
/* 0x4 */ s32 weight;
} RandomCookEntry;

extern RoomNameWork * lbl_805ae010;
extern PasswordData lbl_80410168;
extern char lbl_8050c970[32];
extern RandomCookEntry lbl_8040e44c[];
extern s32 lbl_805ae014;
extern const char * lbl_8040bd08[32];
extern const u8 lbl_8032c1b8[];

s32 func_800b6754();
EffEntry * func_800acc54(s32 param_1);
bool func_800accd4(EffEntry * effect);
EffEntry * func_800ad9a0(s32 type, f32 x, f32 y, f32 z, f32 scale);
EffEntry * func_800af230(s32 param_1);
bool func_800af2b0(EffEntry * effect);
EffEntry * func_800b99f4(s32 chapter, s32 level);
bool func_800b9a90(EffEntry * effect);
void func_800b9ab8(EffEntry * effect, s32 param_2);

extern WPADInfo lbl_8050c8b8[4];
extern u8 lbl_805ae8d0[4];
extern char lbl_8050c918[32];

s32 func_800d378c(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], func_800b6754());

    return EVT_RET_CONTINUE;
}

s32 evt_sub_intpl_msec_init(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 mode = evtGetValue(entry, args[0]);
    s32 start = evtGetValue(entry, args[1]);
    s32 end = evtGetValue(entry, args[2]);
    s32 msec = evtGetValue(entry, args[3]);
    entry->lw[11] = mode;
    entry->lw[12] = start;
    entry->lw[13] = end;
    entry->lw[15] = msec;
    entry->unknown_0x190 = entry->lifetime;

    return EVT_RET_CONTINUE;
}

s32 evt_sub_intpl_msec_get_value(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    u64 tickDiff = (s32) entry->lifetime - (s32) entry->unknown_0x190;
    s32 msec = (s32) OSTicksToMilliseconds(tickDiff);
    if (msec < entry->lw[15])
    {
        entry->lw[0] = (s32) intplGetValue(entry->lw[11], (f32) entry->lw[12],
                                           (f32) entry->lw[13], msec, entry->lw[15]);
        entry->lw[1] = 1;
    }
    else
    {
        entry->lw[0] = entry->lw[13];
        entry->lw[1] = 0;
    }

    return EVT_RET_CONTINUE;
}

s32 evt_sub_intpl_msec_get_value_para(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    u64 tickDiff = (s32) entry->lifetime - (s32) entry->unknown_0x190;
    s32 msec = (s32) OSTicksToMilliseconds(tickDiff);
    if (msec < entry->lw[15])
    {
        evtSetFloat(entry, args[0], intplGetValue(entry->lw[11], (f32) entry->lw[12],
                                                  (f32) entry->lw[13], msec, entry->lw[15]));
        evtSetValue(entry, args[1], 1);
    }
    else
    {
        evtSetFloat(entry, args[0], (f32) entry->lw[13]);
        evtSetValue(entry, args[1], 0);
    }

    return EVT_RET_CONTINUE;
}

s32 evt_sub_spline_init(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 useTime = evtGetValue(entry, args[0]);
    s32 mode = evtGetValue(entry, args[1]);
    Vec3 * points = (Vec3 *) evtGetValue(entry, args[2]);
    s32 count = evtGetValue(entry, args[3]);
    s32 max = evtGetValue(entry, args[4]);
    s32 msec = evtGetValue(entry, args[5]);
    SplineWork * work = (SplineWork *) __memAlloc(1, sizeof(SplineWork));
    entry->lw[15] = (s32) work;
    work->count = count;
    work->table1 = (f32 *) __memAlloc(1, count * sizeof(f32));
    work->points = points;
    work->table2 = (Vec3 *) __memAlloc(1, count * sizeof(Vec3));
    spline_maketable(count, work->points, work->table1, work->table2);
    work->useTime = useTime;
    work->mode = mode;
    work->progress = 0;
    work->max = max;
    work->msec = msec;
    work->startTime = entry->lifetime;

    return EVT_RET_CONTINUE;
}

s32 evt_sub_spline_get_value(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args;
    SplineWork * work;
    f32 progress;
    f32 msec;
    Vec3 pos;

    work = (SplineWork *) entry->lw[15];
    args = entry->pCurData;
    if (work->useTime == 0)
    {
        progress = intplGetValue(work->mode, 0.0f, 1.0f, work->progress, work->max);
    }
    else
    {
        msec = OSTicksToMilliseconds((u64) (entry->lifetime - work->startTime));
        progress = intplGetValue(work->mode, 0.0f, 1.0f, (s32) msec, work->msec);
    }
    spline_getvalue(&pos, progress, work->count, work->points, work->table1, work->table2);
    evtSetValue(entry, args[0], FLOAT(pos.x));
    evtSetValue(entry, args[1], FLOAT(pos.y));
    evtSetValue(entry, args[2], FLOAT(pos.z));
    work->progress++;
    if (work->useTime == 0)
    {
        if (work->progress <= work->max)
        {
            evtSetValue(entry, args[3], 1);
            return EVT_RET_CONTINUE;
        }
    }
    else
    {
        if (msec <= work->msec)
        {
            evtSetValue(entry, args[3], 1);
            return EVT_RET_CONTINUE;
        }
    }
    __memFree(1, work->table1);
    __memFree(1, work->table2);
    __memFree(1, work);
    evtSetValue(entry, args[3], 0);

    return EVT_RET_CONTINUE;
}

s32 evt_sub_spline_get_value_manual(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    SplineWork * work = (SplineWork *) entry->lw[15];
    f32 progress = (f32) evtGetValue(entry, args[0]);
    Vec3 pos;

    progress = progress / (work->useTime != 0 ? (f32) work->msec : (f32) work->max);
    spline_getvalue(&pos, progress, work->count, work->points, work->table1, work->table2);
    evtSetValue(entry, args[1], FLOAT(pos.x));
    evtSetValue(entry, args[2], FLOAT(pos.y));
    evtSetValue(entry, args[3], FLOAT(pos.z));

    return EVT_RET_CONTINUE;
}

s32 evt_sub_spline_free(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    SplineWork * work = (SplineWork *) entry->lw[15];
    __memFree(1, work->table1);
    __memFree(1, work->table2);
    __memFree(1, work);

    return EVT_RET_CONTINUE;
}

s32 evt_sub_get_sincos(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    f32 angle = evtGetFloat(entry, args[0]);
    evtSetValue(entry, args[1], FLOAT((f32) sin(3.141592f * angle / 180.0f)));
    evtSetValue(entry, args[2], FLOAT((f32) cos(3.141592f * angle / 180.0f)));

    return EVT_RET_CONTINUE;
}

s32 evt_sub_rumble_onoff(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 mode = evtGetValue(entry, args[0]);
    s32 controller = evtGetValue(entry, args[1]);
    switch (mode)
    {
        case 0:
            wpadRumbleOn(controller);
            break;
        case 1:
            wpadRumbleOff(controller);
            break;
        case 2:
            wpadRumbleOff(controller);
            break;
    }

    return EVT_RET_CONTINUE;
}

s32 evt_sub_random(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 max = evtGetValue(entry, args[0]);
    evtSetValue(entry, args[1], rand() % (max + 1));

    return EVT_RET_CONTINUE;
}

s32 evt_sub_get_stopwatch(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    EvtEntry * other = evtGetPtrID(evtGetValue(entry, args[0]));
    s32 msec = (s32) OSTicksToMilliseconds(other->lifetime);
    if (msec > 600000)
        msec = 600000;
    evtSetValue(entry, args[1], msec);

    return EVT_RET_CONTINUE;
}

s32 func_800d41a8(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[1], sysMsec2Frame(evtGetValue(entry, args[0])));

    return EVT_RET_CONTINUE;
}

s32 evt_sub_get_dist(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    f32 x1 = (f32) evtGetValue(entry, args[0]);
    f32 z1 = (f32) evtGetValue(entry, args[1]);
    f32 x2 = (f32) evtGetValue(entry, args[2]);
    f32 z2 = (f32) evtGetValue(entry, args[3]);
    evtSetFloat(entry, args[4], distABf(x1, z1, x2, z2));

    return EVT_RET_CONTINUE;
}

s32 evt_sub_get_dir(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    f32 x1 = (f32) evtGetValue(entry, args[0]);
    f32 z1 = (f32) evtGetValue(entry, args[1]);
    f32 x2 = (f32) evtGetValue(entry, args[2]);
    f32 z2 = (f32) evtGetValue(entry, args[3]);
    evtSetFloat(entry, args[4], angleABf(x1, z1, x2, z2));

    return EVT_RET_CONTINUE;
}

s32 evt_sub_get_system_flag(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], (s32) gp->flags);

    return EVT_RET_CONTINUE;
}

s32 func_800d4460(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtGetValue(entry, args[0]);
    evtSetValue(entry, args[1], 0);

    return EVT_RET_CONTINUE;
}

s32 evt_key_get_button(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[1], (s32) wpadGetButtonsHeld(evtGetValue(entry, args[0])));

    return EVT_RET_CONTINUE;
}

s32 evt_key_get_buttonrep(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[1], (s32) wpadGetButtonsHeldRepeat(evtGetValue(entry, args[0])));

    return EVT_RET_CONTINUE;
}

s32 evt_key_get_buttontrg(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[1], (s32) wpadGetButtonsPressed(evtGetValue(entry, args[0])));

    return EVT_RET_CONTINUE;
}

void func_800d45ac(s32 chan, s32 result)
{
    if (result != 0)
        lbl_8050c8b8[chan].lowBat = 0;
    lbl_805ae8d0[chan] = 1;
}

s32 func_800d45dc(EvtEntry * entry, bool isFirstCall)
{
    EvtScriptCode * args = entry->pCurData;
    s32 chan = evtGetValue(entry, args[0]);
    if (isFirstCall)
    {
        entry->tempS[0] = 0;
        lbl_805ae8d0[chan] = 0;
        WPADGetInfoAsync(chan, &lbl_8050c8b8[chan], func_800d45ac);
    }
    if (!lbl_805ae8d0[chan])
        return EVT_RET_BLOCK_WEAK;

    evtSetValue(entry, args[1], lbl_8050c8b8[chan].lowBat != 0);

    return EVT_RET_CONTINUE;
}

s32 func_800d46a4(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetFloat(entry, args[0], gp->gameSpeed);

    return EVT_RET_CONTINUE;
}

s32 func_800d46d8(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    gp->gameSpeed = evtGetFloat(entry, args[0]);

    return EVT_RET_CONTINUE;
}

s32 evt_sub_get_mapname(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    char * name;
    if (evtGetValue(entry, args[0]) == 0)
        name = gp->mapName;
    else
        name = gp->prevMapName;
    evtSetValue(entry, args[1], (s32) name);

    return EVT_RET_CONTINUE;
}

s32 evt_sub_get_entername(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], (s32) gp->doorName);

    return EVT_RET_CONTINUE;
}

s32 evt_sub_set_entername(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    strcpy(gp->doorName, (const char *) evtGetValue(entry, args[0]));

    return EVT_RET_CONTINUE;
}

s32 func_800d47e4(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 centre = evtGetValue(entry, args[0]);
    f32 x = evtGetFloat(entry, args[1]);
    f32 y = evtGetFloat(entry, args[2]);
    f32 z = evtGetFloat(entry, args[3]);
    CamEntry * cam = camGetPtr(5);
    f32 screenX;
    f32 screenY;
    f32 screenZ;
    GXProject(x, y, z, cam->viewMtx, cam->projection, cam->viewport, &screenX, &screenY,
              &screenZ);
    if (centre)
    {
        screenX = screenX - 304.0f;
        screenY = 240.0f - screenY;
        screenX = screenX * ((f32) gp->framebufferHeight * cam->aspect /
                             (f32) gp->framebufferWidth);
    }
    evtSetFloat(entry, args[4], screenX);
    evtSetFloat(entry, args[5], screenY);

    return EVT_RET_CONTINUE;
}

s32 evt_sub_get_language(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], gp->language);

    return EVT_RET_CONTINUE;
}

s32 evt_sub_animgroup_async(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    const char * name = (const char *) evtGetValue(entry, args[0]);

    return animGroupBaseAsync(name, 0, 0) != 0;
}

s32 evt_sub_file_async(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 type = evtGetValue(entry, args[0]);
    const char * name = (const char *) evtGetValue(entry, args[1]);

    return fileAsyncf(type, 0, "%s/%s", getSpmarioDVDRoot(), name) != 0;
}

// NOT_DECOMPILED evt_sub_load_mapdata_bin

// NOT_DECOMPILED evt_sub_get_fps

// NOT_DECOMPILED evt_sub_fmt_str_int

// NOT_DECOMPILED func_800d4b4c

// NOT_DECOMPILED func_800d4b60

// NOT_DECOMPILED evt_sub_hud_configure

// NOT_DECOMPILED func_800d4db0

// NOT_DECOMPILED func_800d4de4

// NOT_DECOMPILED func_800d4e48

// NOT_DECOMPILED func_800d5004

// NOT_DECOMPILED func_800d52a8

// NOT_DECOMPILED func_800d5588

// NOT_DECOMPILED func_800d59ac

// NOT_DECOMPILED func_800d59f0

// NOT_DECOMPILED func_800d5a24

// NOT_DECOMPILED func_800d5a60

// NOT_DECOMPILED func_800d5a94

// NOT_DECOMPILED func_800d5acc

// NOT_DECOMPILED func_800d5e80

// NOT_DECOMPILED func_800d6148

// NOT_DECOMPILED func_800d61ac

// NOT_DECOMPILED func_800d6230

// NOT_DECOMPILED func_800d6298

// NOT_DECOMPILED func_800d6308

// NOT_DECOMPILED func_800d6644

// NOT_DECOMPILED func_800d6674

// NOT_DECOMPILED evt_sub_display_room_name

// NOT_DECOMPILED func_800d776c

// NOT_DECOMPILED func_800d7858

// NOT_DECOMPILED evt_sub_get_save_name

// NOT_DECOMPILED evt_sub_zero_vector

// NOT_DECOMPILED evt_sub_item_select_menu

// NOT_DECOMPILED func_800d7b9c

// NOT_DECOMPILED func_800d7e70

// NOT_DECOMPILED func_800d815c

// NOT_DECOMPILED func_800d8498

// NOT_DECOMPILED func_800d8700

}
