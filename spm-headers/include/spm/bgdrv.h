#pragma once

#include <common.h>
#include <wii/gx.h>

CPP_WRAPPER(spm::bgdrv)

USING(wii::gx::GXColor)

void bgInit();
void bgMain();
UNKNOWN_FUNCTION(func_8004e10c)
UNKNOWN_FUNCTION(bgLoadTpl)
UNKNOWN_FUNCTION(func_8004e608)
void func_8004e710(GXColor colour); // bgSetColor?
UNKNOWN_FUNCTION(func_8004e738)
void func_8004e77c(); // bgFlagOn?
void func_8004e790(); // bgFlagOff?
void func_8004e7a4(s32 id); // bgFlag8On?
void func_8004e7c0(s32 id); // bgFlag8Off?
UNKNOWN_FUNCTION(bgMain)
UNKNOWN_FUNCTION(func_8004ec64)
UNKNOWN_FUNCTION(func_8004f53c)
void func_8004f5c8(const char *);
void func_8004f5f0(const char *);

CPP_WRAPPER_END()
