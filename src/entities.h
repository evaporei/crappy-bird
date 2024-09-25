#pragma once

#include <raylib.h>

typedef struct Bird {
    Vector2 pos;
    float yspeed;
    Texture2D *texture;
} Bird;
