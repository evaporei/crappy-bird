#pragma once

#include <raylib.h>
#include "textures.h"

typedef struct Bird {
    Vector2 pos;
    double yspeed;
} Bird;

typedef struct Pipe {
    Vector2 pos;
    float xspeed;
    Orientation orientation;
} Pipe;

typedef struct PipePair {
    Pipe top;
    Pipe bottom;
} PipePair;
