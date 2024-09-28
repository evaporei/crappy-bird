#include <raylib.h>

#include <math.h>
#include <memory.h>
#include <stdio.h>

// selva
#include <primitives.h>

#include "constants.h"
#include "bird.h"
#include "textures.h"
#include "pipe.h"
#include "globals.h"

int main(void) {
#ifndef DEBUG
    SetTraceLogLevel(LOG_ERROR);
#endif
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "flappy bird");

    textures_init(textures);

    Camera2D camera = { 0 };
    camera.target = (Vector2){ 0, 0 };
    camera.offset = (Vector2){ 0, 0 };
    camera.rotation = 0.0f;
    camera.zoom = 2.5f;

    Bird bird;
    bird_init(&bird);

    PipePair pipe_pairs[MAX_PIPES];
    usize empty_idx = 0;
    memset(pipe_pairs, 0, sizeof(PipePair) * MAX_PIPES);

    float bg_scroll = 0;
    float g_scroll = 0;

    double spawn_timer = GetTime();

    /* SetTargetFPS(60); */

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        spawn_timer += dt;

        if (spawn_timer > 2.f) {
            spawn_timer = 0;
            pipe_init(
                &pipe_pairs[empty_idx].bottom,
                GetRandomValue(GAME_HEIGHT / 2 + 30, GAME_HEIGHT - 10),
                ORI_BOTTOM
            );
            pipe_init(
                &pipe_pairs[empty_idx].top,
                GetRandomValue(GAME_HEIGHT / 2 + 30, GAME_HEIGHT - 10) - textures[TEX_PIPE].height / 2.f,
                ORI_TOP
            );
            empty_idx = (empty_idx + 1) % MAX_PIPES;
        }

        bg_scroll += BG_SPEED * dt;
        g_scroll += G_SPEED * dt;

        bg_scroll = fmod(bg_scroll, BG_LOOP_POINT);
        g_scroll = fmod(g_scroll, G_LOOP_POINT);

        bird_update(&bird);

        for (int i = 0; i < MAX_PIPES; i++) {
            if (memcmp(&pipe_pairs[i], &(PipePair){0}, sizeof(PipePair)) != 0) {
                pipe_update(&pipe_pairs[i].bottom);
                pipe_update(&pipe_pairs[i].top);

                if (bird_collides(&bird, &pipe_pairs[i].top)) {
                    printf("top\n");
                } else if (bird_collides(&bird, &pipe_pairs[i].bottom)) {
                    printf("bottom\n");
                } else {
                    printf("none\n");
                }
            }
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode2D(camera);
                DrawTexture(textures[TEX_BACKGROUND], -bg_scroll, 0, WHITE);
                for (int i = 0; i < MAX_PIPES; i++) {
                    if (memcmp(&pipe_pairs[i], &(PipePair){0}, sizeof(PipePair)) != 0) {
                        pipe_draw(&pipe_pairs[i].bottom);
                        pipe_draw(&pipe_pairs[i].top);
                    }
                }
                DrawTexture(textures[TEX_GROUND], -g_scroll, GAME_HEIGHT - 16, WHITE);

                bird_draw(bird);
            EndMode2D();
            DrawFPS(0, 0);
        EndDrawing();
    }

    for (int i = 0; i < TEX_LEN; i++)
        UnloadTexture(textures[i]);

    CloseWindow();

    return 0;
}
