#pragma once

#include <common.h>
#include <wii/gx.h>

CPP_WRAPPER(spm::sptexture)

USING(wii::gx::GXTexObj)

void sptextureInit();
UNKNOWN_FUNCTION(sptextureSetUnusedBool)
void sptextureMain();

/*
    Initialises a texture object for a texture from the loaded sptexture file
*/
void sptextureGet(s32 id, GXTexObj * texObj);

UNKNOWN_FUNCTION(sptextureIsLoaded)

CPP_WRAPPER_END()
