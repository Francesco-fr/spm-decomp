#include <common.h>
#include <evt_cmd.h>
#include <spm/evt_pouch.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>
#include <spm/mario_pouch.h>

extern "C" {

s32 evt_pouch_set_hp(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    pouchSetHp(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_get_hp(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], pouchGetHp());

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_add_hp(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    pouchAddHp(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_get_max_hp(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], pouchGetMaxHp());

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED evt_pouch_set_max_hp

// NOT_DECOMPILED evt_pouch_get_xp

// NOT_DECOMPILED evt_pouch_add_xp

// NOT_DECOMPILED evt_pouch_set_attack

// NOT_DECOMPILED evt_pouch_get_attack

// NOT_DECOMPILED evt_pouch_add_attack

// NOT_DECOMPILED evt_pouch_set_coins

// NOT_DECOMPILED evt_pouch_get_coins

// NOT_DECOMPILED evt_pouch_add_coins

// NOT_DECOMPILED evt_pouch_add_item

// NOT_DECOMPILED evt_pouch_check_have_item

// NOT_DECOMPILED evt_pouch_remove_item

// NOT_DECOMPILED evt_pouch_remove_item_idx

// NOT_DECOMPILED evt_pouch_add_shop_itme

// NOT_DECOMPILED evt_pouch_remove_shop_item

// NOT_DECOMPILED evt_pouch_remove_shop_item_idx

// NOT_DECOMPILED evt_pouch_set_pixl_selected

// NOT_DECOMPILED evt_pouch_count_use_items

// NOT_DECOMPILED evt_pouch_count_free_shop_items

// NOT_DECOMPILED evt_pouch_count_shop_items

// NOT_DECOMPILED evt_pouch_check_free_use_item

// NOT_DECOMPILED evt_pouch_change_char_selectable

// NOT_DECOMPILED evt_pouch_change_pixl_selectable

// NOT_DECOMPILED evt_pouch_get_level

// NOT_DECOMPILED evt_pouch_set_level

// NOT_DECOMPILED evt_pouch_get_next_level_xp

// NOT_DECOMPILED evt_pouch_get_arcade_tokens

// NOT_DECOMPILED evt_pouch_set_arcade_tokens

// NOT_DECOMPILED evt_pouch_get_total_coins_collected

// NOT_DECOMPILED evt_pouch_get_max_jump_combo

// NOT_DECOMPILED evt_pouch_get_max_stylish_combo

// NOT_DECOMPILED evt_pouch_get_enemies_defeated

// NOT_DECOMPILED evt_pouch_increment_enemies_defeated

}
