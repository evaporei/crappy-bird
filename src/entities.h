#pragma once

#include <raylib.h>

typedef struct Bird {
    Vector2 pos;
    double yspeed;
    Texture2D *texture;
} Bird;

typedef struct Pipe {
    Vector2 pos;
    float xspeed;
} Pipe;

typedef struct PipePair {
    Pipe top;
    Pipe bottom;
} PipePair;
