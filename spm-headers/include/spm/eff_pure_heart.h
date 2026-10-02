#pragma once

#include <common.h>
#include <spm/effdrv.h>

CPP_WRAPPER(spm::eff_pure_heart)

USING(spm::effdrv::EffEntry)

UNKNOWN_FUNCTION(func_80094e44)
void func_80095244(EffEntry * effect, f32 x, f32 y, f32 z);
void func_80095258(EffEntry * effect, f32 * x, f32 * y, f32 * z);
void func_80095278(EffEntry * effect, s32 * out);
UNKNOWN_FUNCTION(func_80095288)
void func_800952d8(EffEntry * effect, s32 param_2);
UNKNOWN_FUNCTION(func_800952e4)
UNKNOWN_FUNCTION(func_800952fc)
UNKNOWN_FUNCTION(func_8009530c)
UNKNOWN_FUNCTION(func_80095318)
UNKNOWN_FUNCTION(func_800953a8)
UNKNOWN_FUNCTION(func_800953b4)
UNKNOWN_FUNCTION(func_800953c0)
UNKNOWN_FUNCTION(func_800953e0)
UNKNOWN_FUNCTION(func_80095444)
UNKNOWN_FUNCTION(func_80095568)
UNKNOWN_FUNCTION(func_80095cf0)

CPP_WRAPPER_END()
