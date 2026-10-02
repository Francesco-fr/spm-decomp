#pragma once

#include <common.h>
#include <spm/mario.h>

CPP_WRAPPER(spm::mario_sbr)

void marioAdjustMoveDir();
bool marioCheck1HeldFor3();
f32 revise360(f32);
void toMovedir2(f32, f32);
bool marioCheck2HeldFor2();
f32 func_80150688(f32 angle);

void func_80150250();
void func_80150288(f32 param_1);
void func_801502bc();
void func_80150478();
void func_801504b0();
void func_801528d4(MarioWork * mp);
void func_80152900(s32 param_1);

CPP_WRAPPER_END()
