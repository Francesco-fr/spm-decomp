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

s32 func_800e0d78(s32 type, bool flag, const char * name, const char * name2,
                  EvtScriptCode * script, s32 * lw)
{
    CaseEntDef def;
    CaseEntDef * pDef = &def;
    if (flag)
        type |= 0x8000;
    pDef->flags = (u16) type;
    pDef->name = name;
    pDef->name2 = name2;
    *(s32 *) pDef->unknown_0xc = 0;
    pDef->script = script;
    pDef->scriptPriority = 0;
    if (lw != NULL)
        memcpy(pDef->lw, lw, sizeof(def.lw));
    else
        memset(pDef->lw, 0, sizeof(def.lw));

    return caseEntry(pDef);
}

s32 func_800e0dfc(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    caseDelete(entry->casedrvId);

    return EVT_RET_CONTINUE;
}

s32 func_800e0e24(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 keepScript = evtGetValue(entry, args[0]);
    s32 id = evtGetValue(entry, args[1]);
    if (keepScript == 0)
    {
        CaseEntry * caseEntry = caseIdToPtr(id);
        if (caseEntry != NULL && evtCheckID(caseEntry->evtId))
            evtDeleteID(caseEntry->evtId);
    }
    caseDelete(id);

    return EVT_RET_CONTINUE;
}

s32 func_800e0eb0(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 id = evtGetValue(entry, args[0]);
    s32 idx = evtGetValue(entry, args[1]);
    s32 value = evtGetValue(entry, args[2]);
    caseIdToPtr(id)->lw[idx] = value;

    return EVT_RET_CONTINUE;
}

s32 func_800e0f30(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    s32 id = evtGetValue(entry, entry->pCurData[0]);
    if (id == -1)
        func_8005ae24();
    else
        func_8005adec(id);

    return EVT_RET_CONTINUE;
}

s32 func_800e0f70(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    s32 id = evtGetValue(entry, entry->pCurData[0]);
    if (id == -1)
        func_8005ae64();
    else
        func_8005ae08(id);

    return EVT_RET_CONTINUE;
}

}
