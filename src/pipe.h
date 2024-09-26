#pragma once

#include "entities.h"

void pipe_init(Pipe *pipe);

void pipe_update(Pipe *pipe);

void pipe_draw(Pipe pipe, Texture2D *texture);
