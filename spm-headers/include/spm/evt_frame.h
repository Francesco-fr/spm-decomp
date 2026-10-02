#pragma once

#include <common.h>
#include <evt_cmd.h>

CPP_WRAPPER(spm::evt_frame)

// evt_frame_delete(const char * instanceName)
EVT_DECLARE_USER_FUNC(evt_frame_delete, 1)

// evt_frame_offscreen_draw_flag_onoff(bool onOff, const char * instanceName)
EVT_DECLARE_USER_FUNC(evt_frame_offscreen_draw_flag_onoff, 2)

// evt_frame_offscreen_entry(const char * instanceName, const char * animPoseName, const char * animDef,
//     u32 screenX, u32 screenY, u32 width, u32 height)
EVT_DECLARE_USER_FUNC(evt_frame_offscreen_entry, 7)

// evt_frame_bind_offscreen(const char * instanceName, const char * offsInstanceName, void * callback)
EVT_DECLARE_USER_FUNC(evt_frame_bind_offscreen, 3)

// evt_frame_set_img_anim(const char * instanceName, const char * animDef)
EVT_DECLARE_USER_FUNC(evt_frame_set_img_anim, 2)

// evt_frame_set_color(const char * instanceName, u8 r, u8 g, u8 b, u8 a)
EVT_DECLARE_USER_FUNC(evt_frame_set_color, 5)

// evt_frame_flag_onoff(bool onOff, const char * instanceName, u32 flags)
// Same address as evt_frame_flag_onoff (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800e8b48)
EVT_DECLARE_USER_FUNC(evt_frame_flag_onoff, 3)

// evt_frame_wire_entry(const char * instanceName, const char * animPoseName, const char * animDef,
// Same address as evt_frame_wire_entry (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800e8be8)
//     f32 x, f32 y, f32 z, f32 drawScale)
EVT_DECLARE_USER_FUNC(evt_frame_wire_entry, 7)

// evt_frame_check_draw_finished(const char * instanceName)
EVT_DECLARE_USER_FUNC(evt_frame_check_draw_finished, 1)

// evt_frame_set_draw_speed(const char * instanceName, f32 drawSpeed)
// Same address as evt_frame_set_draw_speed (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800e8d0c)
EVT_DECLARE_USER_FUNC(evt_frame_set_draw_speed, 2)

// evt_frame_set_wire_color(const char * instanceName, u8 r, u8 g, u8 b, u8 a)
// Same address as evt_frame_set_wire_color (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800e8d98)
EVT_DECLARE_USER_FUNC(evt_frame_set_wire_color, 5)

// evt_frame_set_wire_line_width(const char * instanceName, u32 lineWidth)
// Same address as evt_frame_set_wire_line_width (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800e8e2c)
EVT_DECLARE_USER_FUNC(evt_frame_set_wire_line_width, 2)

// evt_frame_set_wire_draw_rotation(const char * instanceName, f32 rotX, f32 rotY, f32 rotZ)
// Same address as evt_frame_set_wire_draw_rotation (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800e8e94)
EVT_DECLARE_USER_FUNC(evt_frame_set_wire_draw_rotation, 4)

// evt_frame_evt_entry(const char * instanceName, f32 x, f32 y, f32 z, f32 width, f32 height)
// Same address as evt_frame_evt_entry (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800e8f4c)
EVT_DECLARE_USER_FUNC(evt_frame_evt_entry, 6)

// evt_frame_set_rotation(const char * instanceName, f32 xRot, f32 yRot, f32 zRot)
// Same address as evt_frame_set_rotation (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800e902c)
EVT_DECLARE_USER_FUNC(evt_frame_set_rotation, 4)

// evt_frame_set_color(const char * instanceName, u8 r, u8 g, u8 b, u8 a)
EVT_DECLARE_USER_FUNC(evt_frame_set_color2, 5)
// Same address as evt_frame_set_color2 (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800e90e4)

// evt_frame_spin_device_entry(s32 arg1, const char * startSegment, const char * segmentArray)
// Same address as evt_frame_spin_device_entry (name used by the decomp symbol map)
EVT_UNKNOWN_USER_FUNC(func_800e9178)
//     segmentArrays are terminated by a nullptr
EVT_DECLARE_USER_FUNC(evt_frame_spin_device_entry, 3)

EVT_UNKNOWN_USER_FUNC(func_800e8cd0)

CPP_WRAPPER_END()
