#pragma once

#include <common.h>
#include <evt_cmd.h>
#include <spm/evtmgr.h>
#include <spm/mario.h>

CPP_WRAPPER(spm::evt_mario)

USING(spm::evtmgr::EvtEntry)
USING(spm::mario::MarioWork)

EVT_UNKNOWN_USER_FUNC(evt_mario_flag0_onoff)
EVT_UNKNOWN_USER_FUNC(evt_mario_flag4_onoff)

// evt_mario_flag8_onoff(bool onOff, u32 mask)
EVT_DECLARE_USER_FUNC(evt_mario_flag8_onoff, 2)

EVT_UNKNOWN_USER_FUNC(func_800ef53c)
EVT_UNKNOWN_USER_FUNC(evt_mario_cont_onoff)



// evt_mario_key_on()
EVT_DECLARE_USER_FUNC(evt_mario_key_on, 0)

// evt_mario_key_off(int)
EVT_DECLARE_USER_FUNC(evt_mario_key_off, 1)

EVT_UNKNOWN_USER_FUNC(evt_mario_key_off2)
EVT_UNKNOWN_USER_FUNC(func_800ef814)
EVT_UNKNOWN_USER_FUNC(func_800ef8c8)

// evt_mario_get_character(s32& ret)
EVT_DECLARE_USER_FUNC(evt_mario_get_character, 1)

EVT_DECLARE_USER_FUNC(evt_mario_set_character, 1)

// evt_mario_set_pos(f32 x, f32 y, f32 z)
EVT_DECLARE_USER_FUNC(evt_mario_set_pos, 3)

// evt_mario_get_pos(f32& x, f32& y, f32& z)
EVT_DECLARE_USER_FUNC(evt_mario_get_pos, 3)

EVT_UNKNOWN_USER_FUNC(func_800efac4)
EVT_UNKNOWN_USER_FUNC(func_800efb50)
EVT_UNKNOWN_USER_FUNC(func_800efbdc)
EVT_UNKNOWN_USER_FUNC(func_800efc54)

// evt_mario_get_height(f32& ret)
EVT_DECLARE_USER_FUNC(evt_mario_get_height, 1)

EVT_DECLARE_USER_FUNC(evt_mario_direction_reset, 0)

EVT_UNKNOWN_USER_FUNC(func_800efd58)

EVT_DECLARE_USER_FUNC(evt_mario_direction_face, 2)

EVT_UNKNOWN_USER_FUNC(func_800eff6c)

// evt_mario_face_npc(const char * name)
EVT_DECLARE_USER_FUNC(evt_mario_face_npc, 1)

// evt_mario_face_coords(float positionX, float PositionZ)
EVT_DECLARE_USER_FUNC(evt_mario_face_coords, 2)

EVT_UNKNOWN_USER_FUNC(func_800f013c)
EVT_UNKNOWN_USER_FUNC(func_800f0160)
EVT_UNKNOWN_USER_FUNC(func_800f01ac)
EVT_UNKNOWN_USER_FUNC(func_800f0210)
EVT_UNKNOWN_USER_FUNC(evt_mario_face)
EVT_UNKNOWN_USER_FUNC(evt_mario_face_free)

// x, z, duration in ms
EVT_DECLARE_USER_FUNC(evt_mario_walk_to, 3)
// Same address as evt_mario_walk_to (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800f0304)

EVT_DECLARE_USER_FUNC(evt_mario_pos_change, 3)
// Same address as evt_mario_pos_change (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800f046c)

EVT_UNKNOWN_USER_FUNC(func_800f05b0)
EVT_UNKNOWN_USER_FUNC(func_800f074c)

EVT_DECLARE_USER_FUNC(evt_mario_walk_back_from_pos, 6)

EVT_UNKNOWN_USER_FUNC(func_800f0c28)

// evt_mario_jump_to(f32 x, f32 y, f32 z, f32 jumpHeight, f32 time_msec)
// Same address as evt_mario_jump_to (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800f0d58)
EVT_DECLARE_USER_FUNC(evt_mario_jump_to, 5)

EVT_UNKNOWN_USER_FUNC(func_800f119c)
EVT_UNKNOWN_USER_FUNC(func_800f1684)
EVT_UNKNOWN_USER_FUNC(func_800f1778)
EVT_UNKNOWN_USER_FUNC(func_800f1810)
EVT_UNKNOWN_USER_FUNC(func_800f1858)

// evt_mario_set_pose(const char * name, s16 time)
EVT_DECLARE_USER_FUNC(evt_mario_set_pose, 2)

EVT_DECLARE_USER_FUNC(evt_mario_wait_anim, 0)
EVT_UNKNOWN_USER_FUNC(func_800f1a08)
EVT_UNKNOWN_USER_FUNC(func_800f1a4c)
EVT_UNKNOWN_USER_FUNC(func_800f1abc)
s32 func_800f1b08(MarioWork * mp, EvtEntry * entry);
s32 func_800f1ba8(MarioWork * mp, EvtEntry * entry);
s32 func_800f1c1c(MarioWork * mp, EvtEntry * entry);
s32 func_800f1c88(MarioWork * mp, EvtEntry * entry);
s32 func_800f1d0c(MarioWork * mp, EvtEntry * entry);
s32 func_800f1d80(MarioWork * mp, EvtEntry * entry);
s32 func_800f1e30(MarioWork * mp, EvtEntry * entry);
s32 func_800f1eb0(MarioWork * mp, EvtEntry * entry);
s32 func_800f1f30(MarioWork * mp, EvtEntry * entry);
s32 func_800f1f9c(MarioWork * mp, EvtEntry * entry);
s32 func_800f2008(MarioWork * mp, EvtEntry * entry);
s32 func_800f2074(MarioWork * mp, EvtEntry * entry);
s32 func_800f2124(MarioWork * mp, EvtEntry * entry);
s32 func_800f212c(MarioWork * mp, EvtEntry * entry);
s32 func_800f2144(MarioWork * mp, EvtEntry * entry);
EVT_UNKNOWN_USER_FUNC(func_800f2310)
EVT_UNKNOWN_USER_FUNC(func_800f23e4)
EVT_UNKNOWN_USER_FUNC(func_800f240c)

EVT_DECLARE_USER_FUNC(evt_mario_fairy_reset, 0)

EVT_UNKNOWN_USER_FUNC(evt_mario_swim_onoff)
EVT_UNKNOWN_USER_FUNC(func_800f24d8)
EVT_UNKNOWN_USER_FUNC(func_800f2544)
EVT_UNKNOWN_USER_FUNC(evt_mario_set_gravity)
EVT_UNKNOWN_USER_FUNC(evt_get_gravity)
EVT_UNKNOWN_USER_FUNC(func_800f262c)
EVT_UNKNOWN_USER_FUNC(func_800f267c)
EVT_UNKNOWN_USER_FUNC(func_800f26c0)
EVT_UNKNOWN_USER_FUNC(func_800f27f4)
EVT_UNKNOWN_USER_FUNC(func_800f2974)

// evt_mario_take_damage(s32 type, f32 x, f32 y, f32 z, s32 dmgFlags, s32 damage)
// Same address as evt_mario_take_damage (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800f29c8)
// type 1 = no damage vector, flags = 0, dmg = 1
// type 2 = no damage vector; flags and dmg taken from params
// type 3 = all data taken from params
EVT_DECLARE_USER_FUNC(evt_mario_take_damage, 6)

EVT_UNKNOWN_USER_FUNC(evt_mario_tamara_onoff)
EVT_UNKNOWN_USER_FUNC(evt_mario_tamara_chg_mode)
EVT_UNKNOWN_USER_FUNC(func_800f2c00)
EVT_UNKNOWN_USER_FUNC(func_800f2c98)
EVT_UNKNOWN_USER_FUNC(func_800f2cbc)
EVT_UNKNOWN_USER_FUNC(func_800f2cfc)
EVT_UNKNOWN_USER_FUNC(func_800f2d74)
EVT_UNKNOWN_USER_FUNC(func_800f2df4)
EVT_UNKNOWN_USER_FUNC(func_800f2e30)
EVT_UNKNOWN_USER_FUNC(func_800f2e54)
EVT_UNKNOWN_USER_FUNC(evt_mario_set_bottomless_cb)
EVT_UNKNOWN_USER_FUNC(evt_mario_get_bottomless_cb)

// evt_mario_set_anim_change_handler(MarioAnimChangeHandler * handler)
EVT_DECLARE_USER_FUNC(evt_mario_set_anim_change_handler, 1)

EVT_UNKNOWN_USER_FUNC(func_800f2fa8)
EVT_UNKNOWN_USER_FUNC(func_800f2fec)
EVT_UNKNOWN_USER_FUNC(func_800f3074)
EVT_UNKNOWN_USER_FUNC(func_800f30bc)
EVT_UNKNOWN_USER_FUNC(func_800f315c)
EVT_UNKNOWN_USER_FUNC(evt_mario_set_pane_boundaries)
EVT_UNKNOWN_USER_FUNC(evt_mario_get_pane_for_pos)
EVT_UNKNOWN_USER_FUNC(evt_mario_set_pane)
EVT_UNKNOWN_USER_FUNC(evt_mario_pane_change_func)
EVT_UNKNOWN_USER_FUNC(evt_mario_get_pane_change_func)
EVT_UNKNOWN_USER_FUNC(func_800f3310)
EVT_UNKNOWN_USER_FUNC(func_800f3334)
EVT_DECLARE_USER_FUNC(evt_mario_check_3d, 1)
EVT_UNKNOWN_USER_FUNC(func_800f33b0)
EVT_UNKNOWN_USER_FUNC(evt_mario_calc_damage_to_enemy)

EVT_UNKNOWN_USER_FUNC(evt_set_gravity)

CPP_WRAPPER_END()
