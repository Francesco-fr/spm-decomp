#include <common.h>
#include <evt_cmd.h>
#include <spm/evt_fairy.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>
#include <spm/fairy.h>
#include <spm/framedrv.h>
#include <spm/system.h>

extern "C" {

// Unknown unit
void func_80130c80(s32 param_1);

s32 evt_fairy_get_num(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    evtSetValue(entry, args[0], fairyGetNum() + fairyGetNumExtra());

    return EVT_RET_CONTINUE;
}

s32 func_800e7324(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 id = evtGetValue(entry, args[0]);
    s32 runMode = evtGetValue(entry, args[1]);
    fairyIdEnterRunMode(id, runMode);

    return EVT_RET_CONTINUE;
}

s32 func_800e7380(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    fairyIdEnterRunMode0(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 func_800e73b0(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    fairyIdEnterRunMode1(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 func_800e73e0(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    fairyAllEnterRunMode0();

    return EVT_RET_CONTINUE;
}

s32 func_800e7404(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    fairyAllEnterRunMode1();

    return EVT_RET_CONTINUE;
}

s32 func_800e7428(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    fairyIdEnterRunMode2(evtGetValue(entry, entry->pCurData[0]));

    return EVT_RET_CONTINUE;
}

s32 func_800e7458(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    fairyAllEnterRunMode2();

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_800e747c

s32 evt_fairy_set_pos(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 id = evtGetValue(entry, args[0]);
    f32 x = evtGetFloat(entry, args[1]);
    f32 y = evtGetFloat(entry, args[2]);
    f32 z = evtGetFloat(entry, args[3]);
    FairyEntry * fairy = fairyIdToPtr(id);
    if (fairy != NULL)
    {
        fairy->position.x = x;
        fairy->position.y = y;
        fairy->position.z = z;
    }

    return EVT_RET_CONTINUE;
}

s32 evt_fairy_set_pos_all(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    f32 x = evtGetFloat(entry, args[0]);
    f32 y = evtGetFloat(entry, args[1]);
    f32 z = evtGetFloat(entry, args[2]);
    Vec3 pos = {x, y, z};
    fairySetAllPositions(&pos);

    return EVT_RET_CONTINUE;
}

s32 evt_fairy_get_pos(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    FairyEntry * fairy = fairyIdToPtr(evtGetValue(entry, args[0]));
    f32 x, y, z;
    if (fairy != NULL)
    {
        x = fairy->position.x;
        y = fairy->position.y;
        z = fairy->position.z;
    }
    else
    {
        x = 0.0f;
        y = x;
        z = x;
    }
    evtSetFloat(entry, args[1], x);
    evtSetFloat(entry, args[2], y);
    evtSetFloat(entry, args[3], z);

    return EVT_RET_CONTINUE;
}

s32 func_800e76d4(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 id = evtGetValue(entry, args[0]);
    f32 x = evtGetFloat(entry, args[1]);
    f32 y = evtGetFloat(entry, args[2]);
    f32 z = evtGetFloat(entry, args[3]);
    FairyEntry * fairy = fairyIdToPtr(id);
    if (fairy != NULL)
    {
        fairy->unknown_0x80.x = x;
        fairy->unknown_0x80.y = y;
        fairy->unknown_0x80.z = z;
    }

    return EVT_RET_CONTINUE;
}

s32 func_800e7784(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    FairyEntry * fairy = fairyIdToPtr(evtGetValue(entry, entry->pCurData[0]));
    if (fairy != NULL)
    {
        fairy->rotation.x = 270.0f;
        fairy->rotation.y = 0.0f;
        fairy->rotation.z = 0.0f;
    }

    return EVT_RET_CONTINUE;
}

s32 func_800e77d0(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    s32 i;
    s32 total = fairyGetNum() + fairyGetNumExtra();
    for (i = 0; i < total; i++)
    {
        FairyEntry * fairy = fairyIdToPtr(i);
        if (fairy != NULL)
        {
            fairy->rotation.x = 270.0f;
            fairy->rotation.y = 0.0f;
            fairy->rotation.z = 0.0f;
        }
    }

    return EVT_RET_CONTINUE;
}

s32 func_800e7868(EvtEntry * entry, bool isFirstCall)
{
    (void) entry;
    (void) isFirstCall;

    s32 i;
    s32 total = fairyGetNum() + fairyGetNumExtra();
    for (i = 0; i < total; i++)
    {
        FairyEntry * fairy = fairyIdToPtr(i);
        if (fairy != NULL)
        {
            fairy->rotation.x = 90.0f;
            fairy->rotation.y = 180.0f;
            fairy->rotation.z = 180.0f;
        }
    }

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_800e7900

s32 func_800e7aec(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 id = evtGetValue(entry, args[0]);
    f32 angle = evtGetFloat(entry, args[1]);
    FairyEntry * fairy = fairyIdToPtr(id);
    if (fairy != NULL)
    {
        fairy->rotation.y = reviseAngle(angle);
        fairy->rotation.z = fairy->rotation.y;
    }

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_800e7b78

// NOT_DECOMPILED func_800e7bdc

// NOT_DECOMPILED func_800e7d88

// NOT_DECOMPILED func_800e7f3c

s32 func_800e80ec(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 id = evtGetValue(entry, args[0]);
    s32 value = evtGetValue(entry, args[1]);
    FairyEntry * fairy = fairyIdToPtr(id);
    if (fairy == NULL)
        return EVT_RET_CONTINUE;

    fairy->unknown_0x8 = value;

    return EVT_RET_CONTINUE;
}

s32 evt_fairy_flag_onoff(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 on = evtGetValue(entry, args[0]);
    s32 id = evtGetValue(entry, args[1]);
    s32 flags = evtGetValue(entry, args[2]);
    FairyEntry * fairy = fairyIdToPtr(id);
    if (fairy == NULL)
        return EVT_RET_CONTINUE;

    if (on)
        fairy->flag0 |= flags;
    else
        fairy->flag0 &= ~flags;

    return EVT_RET_CONTINUE;
}

s32 evt_fairy_flag_onoff_all(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 on = evtGetValue(entry, args[0]);
    s32 flags = evtGetValue(entry, args[1]);
    FairyEntry * fairy = fairyGetEntries();
    s32 total = fairyGetNum() + fairyGetNumExtra();
    if (fairy == NULL)
        return EVT_RET_CONTINUE;

    for (s32 i = 0; i < total; i++, fairy++)
    {
        if (on)
            fairy->flag0 |= flags;
        else
            fairy->flag0 &= ~flags;
    }

    return EVT_RET_CONTINUE;
}

s32 func_800e82dc(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    FairyEntry * fairy = fairyIdToPtr(evtGetValue(entry, args[0]));
    if (fairy == NULL)
        evtSetValue(entry, args[1], 0);
    else
        evtSetValue(entry, args[1], fairy->runMode);

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_800e8350

// NOT_DECOMPILED func_800e840c

// NOT_DECOMPILED func_800e8468

// NOT_DECOMPILED evt_fairy_reset

// NOT_DECOMPILED func_800e8518

// NOT_DECOMPILED func_800e86dc

// NOT_DECOMPILED func_800e8748

// NOT_DECOMPILED func_800e87ac

// NOT_DECOMPILED func_800e8824

}
