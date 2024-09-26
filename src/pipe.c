#include "pipe.h"

#include <raylib.h>
#include "constants.h"

void pipe_init(Pipe *pipe) {
    pipe->pos = (Vector2){GAME_WIDTH, GetRandomValue(GAME_HEIGHT / 2 + 30, GAME_HEIGHT - 10)};
}

void pipe_update(Pipe *pipe) {
    pipe->pos.x -= PIPE_SPEED * GetFrameTime();
}

void pipe_draw(Pipe pipe, Texture2D *texture) {
    DrawTexture(*texture, pipe.pos.x, pipe.pos.y, WHITE);
}
