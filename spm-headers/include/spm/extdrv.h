#pragma once

#include <common.h>

CPP_WRAPPER(spm::extdrv)

void extInit();
UNKNOWN_FUNCTION(extInit)
void extEntry(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5);
UNKNOWN_FUNCTION(extMakeTexture)
void extReset();
void extMain();
UNKNOWN_FUNCTION(compare)
UNKNOWN_FUNCTION(extGetPosePtr)
UNKNOWN_FUNCTION(func_80065848)
UNKNOWN_FUNCTION(extDraw)
UNKNOWN_FUNCTION(extLoadRenderMode)
UNKNOWN_FUNCTION(extLoadVertex)
UNKNOWN_FUNCTION(extLoadTexture)
UNKNOWN_FUNCTION(extLoadTextureExit)
UNKNOWN_FUNCTION(extLoadTev)

CPP_WRAPPER_END()
