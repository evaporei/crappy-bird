#pragma once

#include <raylib.h>

typedef struct Bird {
    Vector2 pos;
    Texture2D *texture;
} Bird;

void bird_init(Bird *bird, Texture2D *texture);

void bird_draw(Bird bird);
