#include "play.h"

#include <memory.h>
#include <raylib.h>
#include <stdio.h>

#include "../bird.h"
#include "../pipe.h"
#include "../globals.h"

void play_scene_init(PlayScene *scene) {
    bird_init(&scene->bird);
    scene->empty_idx = 0;
    memset(scene->pipe_pairs, 0, sizeof(PipePair) * MAX_PIPES);
    scene->spawn_timer = GetTime();
}

void play_scene_update(PlayScene *scene) {
    f32 dt = GetFrameTime();
    scene->spawn_timer += dt;

    if (scene->spawn_timer > 2.f) {
        scene->spawn_timer = 0;
        pipe_init(
            &scene->pipe_pairs[scene->empty_idx].bottom,
            GetRandomValue(GAME_HEIGHT / 2 + 30, GAME_HEIGHT - 10),
            ORI_BOTTOM
        );
        pipe_init(
            &scene->pipe_pairs[scene->empty_idx].top,
            GetRandomValue(GAME_HEIGHT / 2 + 30, GAME_HEIGHT - 10) - textures[TEX_PIPE].height / 2.f,
            ORI_TOP
        );
        scene->empty_idx = (scene->empty_idx + 1) % MAX_PIPES;
    }

    bird_update(&scene->bird);

    for (int i = 0; i < MAX_PIPES; i++) {
        if (memcmp(&scene->pipe_pairs[i], &(PipePair){0}, sizeof(PipePair)) != 0) {
            pipe_update(&scene->pipe_pairs[i].bottom);
            pipe_update(&scene->pipe_pairs[i].top);

            if (bird_collides(&scene->bird, &scene->pipe_pairs[i].top)) {
                printf("top\n");
            } else if (bird_collides(&scene->bird, &scene->pipe_pairs[i].bottom)) {
                printf("bottom\n");
            } else {
                printf("none\n");
            }
        }
    }
}

void play_scene_draw(PlayScene *scene) {
    for (int i = 0; i < MAX_PIPES; i++) {
        if (memcmp(&scene->pipe_pairs[i], &(PipePair){0}, sizeof(PipePair)) != 0) {
            pipe_draw(&scene->pipe_pairs[i].bottom);
            pipe_draw(&scene->pipe_pairs[i].top);
        }
    }
    bird_draw(scene->bird);
}
