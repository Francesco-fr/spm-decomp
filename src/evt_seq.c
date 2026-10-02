#include <common.h>
#include <evt_cmd.h>
#include <msl/string.h>
#include <spm/evt_seq.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>
#include <spm/seqdrv.h>

extern "C" {

s32 evt_seq_set_seq(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    EvtScriptCode * args = entry->pCurData;
    s32 seq = evtGetValue(entry, args[0]);
    s32 p0 = evtGetValue(entry, args[1]);
    s32 p1 = evtGetValue(entry, args[2]);
    seqSetSeq(seq, (const char *) p0, (const char *) p1);

    return EVT_RET_BLOCK_WEAK;
}

// NOT_DECOMPILED evt_seq_wait

s32 evt_seq_mapchange(EvtEntry * entry, bool isFirstCall)
{
    EvtScriptCode * args = entry->pCurData;
    s32 map = evtGetValue(entry, args[0]);
    s32 door = evtGetValue(entry, args[1]);
    if (isFirstCall)
    {
        if (strcmp((const char *) map, "GAMEOVER") == 0)
            seqSetSeq(SEQ_GAMEOVER, NULL, NULL);
        else
            seqSetSeq(SEQ_MAPCHANGE, (const char *) map, (const char *) door);
    }

    return EVT_RET_BLOCK_WEAK;
}

}
