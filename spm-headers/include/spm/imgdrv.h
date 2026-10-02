#pragma once

#include <common.h>
#include <wii/mtx.h>
#include <wii/os.h>

CPP_WRAPPER(spm::imgdrv)

USING(wii::mtx::Vec2)
USING(wii::os::OSTime)

typedef struct
{
/* 0x000 */ u8 unknown_0x0[0xcc - 0x0]; // 3 capture entries of 0x44 bytes
/* 0x0CC */ u32 flags;
/* 0x0D0 */ u8 unknown_0xd0[0xe8 - 0xd0];
/* 0x0E8 */ Vec2 position;
/* 0x0F0 */ u8 unknown_0xf0[0xfc - 0xf0];
/* 0x0FC */ f32 unknown_0xfc;
/* 0x100 */ u8 unknown_0x100[0x104 - 0x100];
/* 0x104 */ s32 animPoseId;
/* 0x108 */ s32 unknown_0x108;
/* 0x10C */ u8 unknown_0x10c[0x110 - 0x10c];
/* 0x110 */ OSTime animStartTime;
/* 0x118 */ f32 unknown_0x118;
/* 0x11C */ u8 unknown_0x11c[0x150 - 0x11c];
/* 0x150 */ s32 unknown_0x150;
/* 0x154 */ s32 unknown_0x154;
} ImgEntry; // size unknown

UNKNOWN_FUNCTION(func_8007508c)
UNKNOWN_FUNCTION(func_80075290)
UNKNOWN_FUNCTION(func_80075530)
UNKNOWN_FUNCTION(func_80075554)
UNKNOWN_FUNCTION(func_80075b40)
UNKNOWN_FUNCTION(func_8007634c)
UNKNOWN_FUNCTION(func_80076620)
UNKNOWN_FUNCTION(func_80076750)
UNKNOWN_FUNCTION(func_80076abc)
void imgInit();
UNKNOWN_FUNCTION(func_80076bb4)
void func_80076c8c(const char * name, bool param_2);
void imgMain();
ImgEntry * func_8007706c(const char * name, bool param_2);
UNKNOWN_FUNCTION(func_8007711c)
void func_80077178(ImgEntry * img);
void func_80077188(ImgEntry * img, bool param_2);
UNKNOWN_FUNCTION(func_80077240)

CPP_WRAPPER_END()
