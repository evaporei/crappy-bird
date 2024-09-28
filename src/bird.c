#include "bird.h"

#include "constants.h"
#include "globals.h"

void bird_init(Bird *bird) {
    bird->pos = (Vector2){GAME_WIDTH / 2.f - textures[TEX_BIRD].width / 2.f, GAME_HEIGHT / 2.f - textures[TEX_BIRD].height / 2.f};
    bird->yspeed = 0.f;
}

void bird_input(Bird *bird) {
    if (IsKeyPressed(KEY_SPACE)) {
        bird->yspeed = -300;
    }
}

bool bird_collides(Bird *bird, Pipe *pipe) {
    switch (pipe->orientation) {
        case ORI_BOTTOM:
            if (bird->pos.x > pipe->pos.x + textures[TEX_PIPE].width ||
                    bird->pos.x + textures[TEX_BIRD].width < pipe->pos.x)
                return false;
            if (bird->pos.y > pipe->pos.y + textures[TEX_PIPE].height ||
                    bird->pos.y + textures[TEX_BIRD].height < pipe->pos.y)
                return false;
            break;
        case ORI_TOP:
            if (bird->pos.x > pipe->pos.x ||
                    bird->pos.x + textures[TEX_BIRD].width < pipe->pos.x - textures[TEX_PIPE].width)
                return false;
            if (bird->pos.y > pipe->pos.y + textures[TEX_PIPE].height ||
                    bird->pos.y + textures[TEX_BIRD].height < pipe->pos.y)
                return false;
            break;
    }
    return true;
}

void bird_update(Bird *bird) {
    float dt = GetFrameTime();

    bird->yspeed += GRAVITY * dt;

    bird_input(bird);

    bird->pos.y += bird->yspeed * dt;
}

void bird_draw(Bird bird) {
    DrawTexture(textures[TEX_BIRD], bird.pos.x, bird.pos.y, WHITE);
}
