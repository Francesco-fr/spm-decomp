#include <common.h>
#include <evt_cmd.h>
#include <spm/evt_npc.h>
#include <spm/evt_snd.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>
#include <spm/mario.h>
#include <spm/npcdrv.h>
#include <spm/spmario_snd.h>

extern "C" {

// Id of the last sound effect played by a script (owned by an unsplit sbss object)
extern s32 lbl_805ae8c8;

s32 evt_snd_bgmon(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 param_1 = args[0];
    spsndBGMOn((u32) param_1, (const char *) evtGetValue(entry, args[1]));

    return EVT_RET_CONTINUE;
}

s32 evt_snd_bgmon_f_d(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 param_1 = args[0];
    s32 param_2 = evtGetValue(entry, args[1]);
    s32 param_3 = evtGetValue(entry, args[2]);
    spsndBGMOn_f_d_alt((u32) param_1, (const char *) param_2, param_3);

    return EVT_RET_CONTINUE;
}

s32 evt_snd_bgmoff(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    spsndBGMOff(args[0]);

    return EVT_RET_CONTINUE;
}

s32 evt_snd_bgmoff_f_d(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 param_1 = args[0];
    spsndBGMOff_f_d_alt(param_1, evtGetValue(entry, args[1]));

    return EVT_RET_CONTINUE;
}

s32 func_800d2268(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    func_8023cc90(args[0]);

    return EVT_RET_CONTINUE;
}

s32 evt_snd_channel_fadeout(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 param_1 = args[0];
    func_8023cc98(param_1, evtGetValue(entry, args[1]));

    return EVT_RET_CONTINUE;
}

s32 func_800d22d8(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 param_1 = args[0];
    func_8023ce1c(param_1, evtGetValue(entry, args[1]));

    return EVT_RET_CONTINUE;
}

s32 func_800d231c(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 param_1 = args[0];
    s32 param_2 = evtGetValue(entry, args[1]);
    s32 param_3 = evtGetValue(entry, args[2]);
    func_8023ce20(param_1, param_2, param_3);

    return EVT_RET_CONTINUE;
}

s32 func_800d2388(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 param_1 = args[0];
    func_8023cf14(param_1, evtGetValue(entry, args[1]));

    return EVT_RET_CONTINUE;
}

s32 func_800d23cc(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 param_1 = args[0];
    s32 param_2 = evtGetValue(entry, args[1]);
    s32 param_3 = evtGetValue(entry, args[2]);
    func_8023cfe8(param_1, param_2, param_3);

    return EVT_RET_CONTINUE;
}

s32 func_800d2438(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 param_1 = args[0];
    func_8023d0dc(param_1, evtGetValue(entry, args[1]));

    return EVT_RET_CONTINUE;
}

s32 func_800d247c(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    if (spsndCheckBgmPlaying(entry->pCurData[0]))
        return EVT_RET_BLOCK_WEAK;

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED evt_snd_get_bgm_wait_time

s32 evt_snd_get_bgm_name(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    const char * name = spsndGetBgmName(args[0]);
    if (name == NULL)
        evtSetValue(entry, args[1], 0);
    else
        evtSetValue(entry, args[1], (s32) name);

    return EVT_RET_CONTINUE;
}

s32 evt_snd_sfxon(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    lbl_805ae8c8 = spsndSFXOn((const char *) evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 func_800d2834(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    s32 param_2 = evtGetValue(entry, args[1]);
    lbl_805ae8c8 = spsndSFXOn_UnkEffect((const char *) name, param_2);

    return EVT_RET_CONTINUE;
}

s32 func_800d2894(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    s32 delay = evtGetValue(entry, args[1]);
    lbl_805ae8c8 = spsndSFXOn((const char *) name);
    spsndSFX_delay(lbl_805ae8c8, delay);

    return EVT_RET_CONTINUE;
}

s32 evt_snd_sfxon_character(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    MarioWork * mp = marioGetPtr();
    s32 name;
    switch (mp->character)
    {
        case 0:
            name = evtGetValue(entry, args[0]);
            break;
        case 1:
            name = evtGetValue(entry, args[1]);
            break;
        case 2:
            name = evtGetValue(entry, args[2]);
            break;
        case 3:
            name = evtGetValue(entry, args[3]);
            break;
        default:
            name = evtGetValue(entry, args[0]);
            break;
    }
    if (name == 0)
        return EVT_RET_CONTINUE;

    lbl_805ae8c8 = spsndSFXOn((const char *) name);

    return EVT_RET_CONTINUE;
}

s32 evt_snd_sfxon_3d(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    Vec3 pos;
    s32 name = evtGetValue(entry, args[0]);
    pos.x = evtGetFloat(entry, args[1]);
    pos.y = evtGetFloat(entry, args[2]);
    pos.z = evtGetFloat(entry, args[3]);
    lbl_805ae8c8 = spsndSFXOn_3D((const char *) name, &pos);

    return EVT_RET_CONTINUE;
}

s32 func_800d2a58(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    Vec3 pos;
    s32 name = evtGetValue(entry, args[0]);
    pos.x = evtGetFloat(entry, args[1]);
    pos.y = evtGetFloat(entry, args[2]);
    pos.z = evtGetFloat(entry, args[3]);
    s32 param_3 = evtGetValue(entry, args[4]);
    lbl_805ae8c8 = (s32) _spsndSFXOn((const char *) name, &pos, (u32) param_3);

    return EVT_RET_CONTINUE;
}

s32 evt_snd_sfxon_npc(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    s32 npcName = evtGetValue(entry, args[1]);
    NPCEntry * npc = evtNpcNameToPtr(entry, (const char *) npcName);
    lbl_805ae8c8 = spsndSFXOn_3D((const char *) name, &npc->position);

    return EVT_RET_CONTINUE;
}

s32 evt_snd_sfxon_npc_delay(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    s32 npcName = evtGetValue(entry, args[1]);
    s32 delay = evtGetValue(entry, args[2]);
    NPCEntry * npc = evtNpcNameToPtr(entry, (const char *) npcName);
    lbl_805ae8c8 = spsndSFXOn_3D((const char *) name, &npc->position);
    spsndSFX_delay(lbl_805ae8c8, delay);

    return EVT_RET_CONTINUE;
}

s32 evt_snd_sfxon_3d_player(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    MarioWork * mp = marioGetPtr();
    lbl_805ae8c8 = spsndSFXOn_3D((const char *) evtGetValue(entry, args[0]), &mp->position);

    return EVT_RET_CONTINUE;
}

s32 func_800d2c58(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    MarioWork * mp = marioGetPtr();
    s32 name = evtGetValue(entry, args[0]);
    s32 delay = evtGetValue(entry, args[1]);
    lbl_805ae8c8 = spsndSFXOn_3D((const char *) name, &mp->position);
    spsndSFX_delay(lbl_805ae8c8, delay);

    return EVT_RET_CONTINUE;
}

s32 evt_snd_sfxon_3d_player_character(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    MarioWork * mp = marioGetPtr();
    s32 name;
    switch (mp->character)
    {
        case 0:
            name = evtGetValue(entry, args[0]);
            break;
        case 1:
            name = evtGetValue(entry, args[1]);
            break;
        case 2:
            name = evtGetValue(entry, args[2]);
            break;
        case 3:
            name = evtGetValue(entry, args[3]);
            break;
        default:
            name = evtGetValue(entry, args[0]);
            break;
    }
    if (name == 0)
        return EVT_RET_CONTINUE;

    lbl_805ae8c8 = spsndSFXOn_3D((const char *) name, &mp->position);

    return EVT_RET_CONTINUE;
}

s32 func_800d2db8(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    MarioWork * mp = marioGetPtr();
    s32 name;
    switch (mp->character)
    {
        case 0:
            name = evtGetValue(entry, args[0]);
            break;
        case 1:
            name = evtGetValue(entry, args[1]);
            break;
        case 2:
            name = evtGetValue(entry, args[2]);
            break;
        case 3:
            name = evtGetValue(entry, args[3]);
            break;
        default:
            name = evtGetValue(entry, args[0]);
            break;
    }
    if (name == 0)
        return EVT_RET_CONTINUE;

    s32 delay = evtGetValue(entry, args[4]);
    lbl_805ae8c8 = spsndSFXOn_3D((const char *) name, &mp->position);
    spsndSFX_delay(lbl_805ae8c8, delay);

    return EVT_RET_CONTINUE;
}

s32 func_800d2ed0(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    Vec3 pos;
    s32 name = evtGetValue(entry, args[0]);
    pos.x = evtGetFloat(entry, args[1]);
    pos.y = evtGetFloat(entry, args[2]);
    pos.z = evtGetFloat(entry, args[3]);
    s32 delay = evtGetValue(entry, args[4]);
    lbl_805ae8c8 = spsndSFXOn_3D((const char *) name, &pos);
    spsndSFX_delay(lbl_805ae8c8, delay);

    return EVT_RET_CONTINUE;
}

s32 evt_snd_sfxoff(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    spsndSFXOff(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 func_800d2fa4(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 param_1 = evtGetValue(entry, args[0]);
    s32 param_2 = evtGetValue(entry, args[1]);
    func_8023b38c((u32) param_1, (u32) param_2);

    return EVT_RET_CONTINUE;
}

s32 func_800d3000(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    func_80238868(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 evt_snd_get_last_sfx_id(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    evtSetValue(entry, entry->pCurData[0], lbl_805ae8c8);

    return EVT_RET_CONTINUE;
}

s32 func_800d3060(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    Vec3 pos;
    s32 player = evtGetValue(entry, args[0]);
    pos.x = evtGetFloat(entry, args[1]);
    pos.y = evtGetFloat(entry, args[2]);
    pos.z = evtGetFloat(entry, args[3]);
    spsndSetSfxPlayerPos((u32) player, &pos);

    return EVT_RET_CONTINUE;
}

s32 func_800d30e8(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 player = evtGetValue(entry, args[0]);
    spsndSFX_vol(player, (s8) evtGetValue(entry, args[1]));

    return EVT_RET_CONTINUE;
}

s32 func_800d3144(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 param_1 = evtGetValue(entry, args[0]);
    s32 param_2 = evtGetValue(entry, args[1]);
    func_8023b680(param_1, param_2);

    return EVT_RET_CONTINUE;
}

s32 func_800d31a0(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    func_8023b77c(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 func_800d31d0(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 param_1 = evtGetValue(entry, args[0]);
    s32 param_2 = evtGetValue(entry, args[1]);
    s32 param_3 = evtGetValue(entry, args[2]);
    func_8023b858(param_1, param_2, param_3);

    return EVT_RET_CONTINUE;
}

s32 func_800d3248(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 param_1 = evtGetValue(entry, args[0]);
    s32 param_2 = evtGetValue(entry, args[1]);
    func_8023b974(param_1, param_2);

    return EVT_RET_CONTINUE;
}

s32 evt_snd_sfx_wait(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    if (spsndSFX_chk(evtGetValue(entry, entry->pCurData[0])))
        return EVT_RET_BLOCK_WEAK;

    return EVT_RET_CONTINUE;
}

s32 evt_snd_sfx_wait_name(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    if (spsndSFX_chkName((const char *) evtGetValue(entry, entry->pCurData[0])))
        return EVT_RET_BLOCK_WEAK;

    return EVT_RET_CONTINUE;
}

s32 evt_snd_sfx_flag_on(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 param_1 = evtGetValue(entry, args[0]);
    s32 param_2 = evtGetValue(entry, args[1]);
    spsndSFX_flagOn(param_1, (u32) param_2);

    return EVT_RET_CONTINUE;
}

s32 evt_snd_sfx_flag_off(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 param_1 = evtGetValue(entry, args[0]);
    s32 param_2 = evtGetValue(entry, args[1]);
    spsndSFX_flagOff(param_1, (u32) param_2);

    return EVT_RET_CONTINUE;
}

s32 func_800d33dc(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    evtSetValue(entry, args[1], spsndSFX_getIdPlayingName((const char *) name));

    return EVT_RET_CONTINUE;
}

s32 evt_snd_envon(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    spsndENVOn(args[0], (const char *) args[1], 1000);

    return EVT_RET_CONTINUE;
}

s32 evt_snd_envon_f(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 flags = args[0];
    s32 name = args[1];
    spsndENVOn(flags, (const char *) name, evtGetValue(entry, args[2]));

    return EVT_RET_CONTINUE;
}

s32 func_800d34b8(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    func_8023dc88(args[0]);

    return EVT_RET_CONTINUE;
}

s32 func_800d34e4(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 param_1 = args[0];
    func_8023dc90(param_1, evtGetValue(entry, args[1]));

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_800d3528

// NOT_DECOMPILED func_800d3594

// NOT_DECOMPILED func_800d35d8

// NOT_DECOMPILED func_800d3644

// NOT_DECOMPILED func_800d3688

// NOT_DECOMPILED evt_snd_set_sfx_reverb_mode

// NOT_DECOMPILED evt_snd_flag_on

// NOT_DECOMPILED evt_snd_flag_off

}
