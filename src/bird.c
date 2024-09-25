#include "bird.h"

#include "constants.h"

void bird_init(Bird *bird, Texture2D *texture) {
    bird->pos = (Vector2){GAME_WIDTH / 2.f - texture->width / 2.f, GAME_HEIGHT / 2.f - texture->height / 2.f};
    bird->yspeed = 0.f;
    bird->texture = texture;
}

void bird_input(Bird *bird) {
    if (IsKeyPressed(KEY_SPACE)) {
        bird->yspeed = -300;
    }
}

void bird_update(Bird *bird) {
    float dt = GetFrameTime();

    bird->yspeed += GRAVITY * dt;

    bird_input(bird);

    bird->pos.y += bird->yspeed * dt;
}

void bird_draw(Bird bird) {
    DrawTexture(*bird.texture, bird.pos.x, bird.pos.y, WHITE);
}
