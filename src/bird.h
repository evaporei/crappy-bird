#pragma once

#include "entities.h"

void bird_init(Bird *bird);

void bird_input(Bird *bird);

bool bird_collides(Bird *bird, Pipe *pipe);

void bird_update(Bird *bird);

void bird_draw(Bird bird);
