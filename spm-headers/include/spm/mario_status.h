#pragma once

#include <common.h>

CPP_WRAPPER(spm::mario_status)


#define STATUS_POISION 0x1
#define STATUS_SLOW 0x2
#define STATUS_NO_SKILLS 0x4
#define STATUS_NO_JUMP 0x8
#define STATUS_FLIPPED_CONTROLS 0x10
#define STATUS_HALF_DAMAGE 0x20
#define STATUS_DOUBLE_ATTACK 0x40
#define STATUS_ELECTRIFIED 0x80
#define STATUS_HP_REGEN 0x100
#define STATUS_BARRIER 0x200
#define STATUS_FAST_FLOWER 0x400
#define STATUS_SLOW_FLOWER 0x800
#define STATUS_COIN_FLOWER 0x1000
#define STATUS_PAL_PILLS 0x4000
#define STATUS_GHOST_SHROOM 0x8000
#define STATUS_DANGEROUS_DELIGHT 0x10000


void marioStatusApplyStatuses(s32 status, s32 lv);

// more

void func_8015affc(f32 x, f32 y, f32 z);
void func_8015b0bc(bool param_1);
void func_8015eff4();

bool func_80166968();
void func_801669ac();
bool func_80166ae0();
void func_8016c608();
void func_8016ccc0();

CPP_WRAPPER_END()
