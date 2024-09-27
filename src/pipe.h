#pragma once

#include "entities.h"
#include "textures.h"

void pipe_init(Pipe *pipe, float y);

void pipe_update(Pipe *pipe);

void pipe_draw(Pipe pipe, Texture2D *texture, Orientation orientation);
