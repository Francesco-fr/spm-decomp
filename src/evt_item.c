#include <common.h>
#include <evt_cmd.h>
#include <spm/evt_item.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>
#include <spm/icondrv.h>
#include <spm/itemdrv.h>

extern "C" {

// NOT_DECOMPILED evt_item_entry

s32 func_800ecd70(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    itemDelete((const char *) evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 evt_item_set_position(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    f32 x = evtGetFloat(entry, args[1]);
    f32 y = evtGetFloat(entry, args[2]);
    f32 z = evtGetFloat(entry, args[3]);
    ItemEntry * item = itemNameToPtr((const char *) name);
    if (item != NULL)
    {
        item->position.x = x;
        item->position.y = y;
        item->position.z = z;
    }

    return EVT_RET_CONTINUE;
}

s32 evt_item_get_position(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    ItemEntry * item = itemNameToPtr((const char *) evtGetValue(entry, args[0]));
    if (item != NULL)
    {
        evtSetFloat(entry, args[1], item->position.x);
        evtSetFloat(entry, args[2], item->position.y);
        evtSetFloat(entry, args[3], item->position.z);
    }

    return EVT_RET_CONTINUE;
}

s32 evt_item_flag_onoff(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 on = evtGetValue(entry, args[0]);
    s32 name = evtGetValue(entry, args[1]);
    u32 flags = (u32) evtGetValue(entry, args[2]);
    ItemEntry * item = itemNameToPtr((const char *) name);
    if (item != NULL)
    {
        if (on)
            item->flags |= flags;
        else
            item->flags &= ~flags;
    }

    return EVT_RET_CONTINUE;
}

s32 func_800ecf80(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 on = evtGetValue(entry, args[0]);
    s32 name = evtGetValue(entry, args[1]);
    u32 flags = (u32) evtGetValue(entry, args[2]);
    ItemEntry * item = itemNameToPtr((const char *) name);
    if (item != NULL)
    {
        if (on)
            iconFlagOn(item->name, flags);
        else
            iconFlagOff(item->name, flags);
    }

    return EVT_RET_CONTINUE;
}

s32 func_800ed020(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    evtGetValue(entry, args[1]);
    evtGetValue(entry, args[2]);
    evtGetValue(entry, args[3]);
    s32 alpha = evtGetValue(entry, args[4]);
    ItemEntry * item = itemNameToPtr((const char *) name);
    if (item != NULL)
        iconSetAlpha(item->name, (u8) alpha);

    return EVT_RET_CONTINUE;
}

s32 func_800ed0bc(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 name = evtGetValue(entry, args[0]);
    f32 value = evtGetFloat(entry, args[1]);
    ItemEntry * item = itemNameToPtr((const char *) name);
    if (item != NULL)
        item->unknown_0x20 = value;

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED evt_item_wait_collected

// NOT_DECOMPILED func_800ed188

// NOT_DECOMPILED func_800ed1dc

// NOT_DECOMPILED func_800ed468

// NOT_DECOMPILED func_800ed66c

}
