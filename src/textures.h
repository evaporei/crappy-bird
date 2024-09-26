#pragma once

#include <raylib.h>

typedef enum TextureKind {
    TEX_BACKGROUND,
    TEX_GROUND,
    TEX_BIRD,
    TEX_PIPE,

    TEX_LEN
} TextureKind;

void textures_init(Texture2D *textures);
