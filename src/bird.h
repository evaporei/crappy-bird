#pragma once

#include "entities.h"

void bird_init(Bird *bird, Texture2D *texture);

void bird_input(Bird *bird);

void bird_update(Bird *bird);

void bird_draw(Bird bird);
