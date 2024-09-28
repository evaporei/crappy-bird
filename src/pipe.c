#include "pipe.h"

#include <raylib.h>
#include "constants.h"
#include "globals.h"

void pipe_init(Pipe *pipe, float y, Orientation orientation) {
    switch (orientation) {
        case ORI_BOTTOM:
            pipe->pos = (Vector2){GAME_WIDTH, y};
            break;
        case ORI_TOP:
            pipe->pos = (Vector2){GAME_WIDTH + textures[TEX_PIPE].width, y};
            break;
    }
    pipe->orientation = orientation;
}

void pipe_update(Pipe *pipe) {
    pipe->pos.x -= PIPE_SPEED * GetFrameTime();
}

void pipe_draw(Pipe *pipe) {
    float rotation;
    switch (pipe->orientation) {
        case ORI_BOTTOM:
            rotation = 0.f;
            break;
        case ORI_TOP:
            rotation = 180.f;
            break;
    }
    DrawTextureEx(textures[TEX_PIPE], pipe->pos, rotation, 1, WHITE);
}
