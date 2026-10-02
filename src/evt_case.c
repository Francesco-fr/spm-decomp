#include <common.h>
#include <evt_cmd.h>
#include <msl/string.h>
#include <spm/casedrv.h>
#include <spm/evt_case.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>

extern "C" {

s32 func_800e0ca4(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    CaseEntDef def;
    s32 type = evtGetValue(entry, args[0]);
    s32 flag = evtGetValue(entry, args[1]);
    s32 name = evtGetValue(entry, args[2]);
    s32 name2 = evtGetValue(entry, args[3]);
    s32 script = evtGetValue(entry, args[4]);
    CaseEntDef * pDef = &def;
    if (flag)
        type |= 0x8000;
    pDef->flags = (u16) type;
    pDef->name = (const char *) name;
    pDef->name2 = (const char *) name2;
    *(s32 *) pDef->unknown_0xc = 0;
    pDef->script = (EvtScriptCode *) script;
    pDef->scriptPriority = 0;
    memcpy(pDef->lw, entry->lw, sizeof(def.lw));
    s32 id = caseEntry(pDef);
    if (args[5] != 0)
        evtSetValue(entry, args[5], id);

    return EVT_RET_CONTINUE;
}

// NOT_DECOMPILED func_800e0d78

// NOT_DECOMPILED func_800e0dfc

// NOT_DECOMPILED func_800e0e24

// NOT_DECOMPILED func_800e0eb0

// NOT_DECOMPILED func_800e0f30

// NOT_DECOMPILED func_800e0f70

}
