#pragma once

#include <common.h>
#include <wii/mtx.h>

CPP_WRAPPER(spm::cam_road)

USING(wii::mtx::Vec3)

void func_800531a0();
void func_80053214();
void func_800532a8();
void func_8005333c();
void func_80053384();
void func_800533cc(s32 param_1, Vec3 * param_2, Vec3 * outPos, Vec3 * outTarget);

CPP_WRAPPER_END()
