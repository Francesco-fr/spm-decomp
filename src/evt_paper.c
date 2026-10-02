#include <common.h>
#include <evt_cmd.h>
#include <spm/animdrv.h>
#include <spm/evt_paper.h>
#include <spm/evtmgr.h>
#include <spm/evtmgr_cmd.h>

extern "C" {

s32 evt_paper_entry(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    s32 name = evtGetValue(entry, entry->pCurData[0]);
    if (!animGroupBaseAsync((const char *) name, 0, NULL))
        return EVT_RET_BLOCK_WEAK;

    animPaperPoseEntry((const char *) name, 0);

    return EVT_RET_CONTINUE;
}

s32 evt_paper_delete(EvtEntry * entry, bool isFirstCall)
{
    (void) isFirstCall;

    s32 name = evtGetValue(entry, entry->pCurData[0]);
    animPaperPoseRelease(animPaperPoseGetId((const char *) name, 0));

    return EVT_RET_CONTINUE;
}

}
