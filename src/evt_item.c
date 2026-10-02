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

// NOT_DECOMPILED evt_item_set_position

// NOT_DECOMPILED evt_item_get_position

// NOT_DECOMPILED evt_item_flag_onoff

// NOT_DECOMPILED func_800ecf80

// NOT_DECOMPILED func_800ed020

// NOT_DECOMPILED func_800ed0bc

// NOT_DECOMPILED evt_item_wait_collected

// NOT_DECOMPILED func_800ed188

// NOT_DECOMPILED func_800ed1dc

// NOT_DECOMPILED func_800ed468

// NOT_DECOMPILED func_800ed66c

}
