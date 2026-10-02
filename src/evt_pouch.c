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

s32 evt_pouch_set_max_hp(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    pouchSetMaxHp(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_get_xp(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], pouchGetXp());

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_add_xp(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    pouchAddXp(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_set_attack(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    pouchSetAttack(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_get_attack(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], pouchGetAttack());

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_add_attack(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    pouchAddAttack(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_set_coins(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    pouchSetCoin(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_get_coins(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], pouchGetCoin());

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_add_coins(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    pouchAddCoin(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_add_item(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    pouchAddItem(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_check_have_item(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[1], pouchCheckHaveItem(evtGetValue(entry, args[0])));

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_remove_item(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    pouchRemoveItem(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_remove_item_idx(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 itemId = evtGetValue(entry, args[0]);
    s32 idx = evtGetValue(entry, args[1]);
    pouchRemoveItemIdx(itemId, idx);

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_add_shop_itme(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    pouchAddShopItem(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_remove_shop_item(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    pouchRemoveShopItem(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_remove_shop_item_idx(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 itemId = evtGetValue(entry, args[0]);
    s32 idx = evtGetValue(entry, args[1]);
    pouchRemoveShopItemIdx(itemId, idx);

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_set_pixl_selected(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    pouchSetPixlSelected(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_count_use_items(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], pouchCountUseItems());

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_count_free_shop_items(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], pouchCountShopItems());

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_count_shop_items(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], POUCH_SHOP_ITEM_MAX - pouchCountShopItems());

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_check_free_use_item(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], pouchCheckFreeUseItem());

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_change_char_selectable(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 selectable = evtGetValue(entry, args[0]);
    s32 id = evtGetValue(entry, args[1]);
    if (selectable)
        pouchMakeCharSelectable(id);
    else
        pouchMakeCharNotSelectable(id);

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_change_pixl_selectable(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 selectable = evtGetValue(entry, args[0]);
    s32 id = evtGetValue(entry, args[1]);
    if (selectable)
        pouchMakePixlSelectable(id);
    else
        pouchMakePixlNotSelectable(id);

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_get_level(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], pouchGetLevel());

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_set_level(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    pouchSetLevel(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_get_next_level_xp(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], pouchGetNextLevelXp());

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_get_arcade_tokens(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], pouchGetArcadeTokens());

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_set_arcade_tokens(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    pouchSetArcadeTokens(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_get_total_coins_collected(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], pouchGetTotalCoinsCollected());

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_get_max_jump_combo(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], pouchGetMaxJumpCombo());

    return EVT_RET_CONTINUE;
}

s32 evt_pouch_get_max_stylish_combo(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], pouchGetMaxStylishCombo());

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED evt_pouch_get_enemies_defeated

// NOT_DECOMPILED evt_pouch_increment_enemies_defeated

}
