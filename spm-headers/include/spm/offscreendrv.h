#pragma once

#include <common.h>

CPP_WRAPPER(spm::offscreendrv)

void offscreenInit();
UNKNOWN_FUNCTION(offscreenReset)
void offscreenEntry(const char * name);
UNKNOWN_FUNCTION(offscreenDisp)
void offscreenMain();
UNKNOWN_FUNCTION(offscreenAddBoundingBox)
UNKNOWN_FUNCTION(func_800350a0)
UNKNOWN_FUNCTION(func_800350fc)
s32 offscreenNameToId(const char * name);
UNKNOWN_FUNCTION(func_8003521c)
UNKNOWN_FUNCTION(func_800352b4)
UNKNOWN_FUNCTION(func_800352cc)
void func_800353c4(const char * name);
bool func_80035478(s32 id, u16 * x0, u16 * y0, u16 * x1, u16 * y1);

void offscreenSetEntryType(const char *name, u32 type);

CPP_WRAPPER_END()
