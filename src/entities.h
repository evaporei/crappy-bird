#pragma once

#include <raylib.h>

typedef struct Bird {
    Vector2 pos;
    double yspeed;
    Texture2D *texture;
} Bird;
