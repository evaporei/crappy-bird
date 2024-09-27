#pragma once

#include "entities.h"

void pipe_init(Pipe *pipe, float y, Orientation orientation, Texture2D *texture);

void pipe_update(Pipe *pipe);

void pipe_draw(Pipe *pipe);
