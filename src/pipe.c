#include "pipe.h"

#include <raylib.h>
#include "constants.h"

void pipe_init(Pipe *pipe, float y) {
    pipe->pos = (Vector2){GAME_WIDTH, y};
}

void pipe_update(Pipe *pipe) {
    pipe->pos.x -= PIPE_SPEED * GetFrameTime();
}

void pipe_draw(Pipe pipe, Texture2D *texture, Orientation orientation) {
    switch (orientation) {
        case ORI_BOTTOM:
            DrawTextureEx(*texture, pipe.pos, 0.f, 1, WHITE);
            break;
        case ORI_TOP:
            DrawTextureEx(*texture, (Vector2){ pipe.pos.x + texture->width, pipe.pos.y }, 180.f, 1, WHITE);
            break;
    }
}
