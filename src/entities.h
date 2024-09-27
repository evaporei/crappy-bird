#pragma once

#include <raylib.h>
#include "textures.h"

typedef struct Bird {
    Vector2 pos;
    double yspeed;
    Texture2D *texture;
} Bird;

typedef struct Pipe {
    Vector2 pos;
    float xspeed;
    Orientation orientation;
    Texture2D *texture;
} Pipe;

typedef struct PipePair {
    Pipe top;
    Pipe bottom;
} PipePair;
