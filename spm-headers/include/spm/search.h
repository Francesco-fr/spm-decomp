#pragma once

#include <common.h>
#include <spm/npcdrv.h>

CPP_WRAPPER(spm::search)

USING(spm::npcdrv::NPCEntry)

typedef struct
{
/* 0x000 */ u8 unknown_0x000[0x034 - 0x000];
/* 0x034 */ const char * message;
/* 0x038 */ char msgBuf[32];
/* 0x058 */ u8 unknown_0x058[0x4a8 - 0x058];
} SearchWork;
SIZE_ASSERT(SearchWork, 0x4a8)

DECOMP_STATIC(SearchWork * search_wp)

const char *searchGetNpcMsg(NPCEntry *npc);

void func_80243aa8();
void func_80243abc();
void func_802497e8(void * param_1);
bool func_802498b0();
void func_8024a5e8();

CPP_WRAPPER_END()
