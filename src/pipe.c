#include "pipe.h"

#include <raylib.h>
#include "constants.h"

void pipe_init(Pipe *pipe, float y, Orientation orientation, Texture2D *texture) {
    switch (orientation) {
        case ORI_BOTTOM:
            pipe->pos = (Vector2){GAME_WIDTH, y};
            break;
        case ORI_TOP:
            pipe->pos = (Vector2){GAME_WIDTH + texture->width, y};
            break;
    }
    pipe->orientation = orientation;
    pipe->texture = texture;
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
    DrawTextureEx(*pipe->texture, pipe->pos, rotation, 1, WHITE);
}
