#include <raylib.h>

#include <math.h>
#include <memory.h>

// selva
#include <primitives.h>

#include "constants.h"
#include "bird.h"
#include "textures.h"
#include "pipe.h"

int main(void) {
#ifndef DEBUG
    SetTraceLogLevel(LOG_ERROR);
#endif
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "flappy bird");

    Texture2D textures[TEX_LEN];
    textures_init(textures);

    Camera2D camera = { 0 };
    camera.target = (Vector2){ 0, 0 };
    camera.offset = (Vector2){ 0, 0 };
    camera.rotation = 0.0f;
    camera.zoom = 2.5f;

    Bird bird;
    bird_init(&bird, &textures[TEX_BIRD]);

    Pipe pipes[MAX_PIPES];
    usize empty_idx = 0;
    memset(pipes, 0, sizeof(Pipe) * MAX_PIPES);

    float bg_scroll = 0;
    float g_scroll = 0;

    double spawn_timer = GetTime();

    /* SetTargetFPS(60); */

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        spawn_timer += dt;

        if (spawn_timer > 2.f) {
            spawn_timer = 0;
            pipe_init(&pipes[empty_idx]);
            empty_idx = (empty_idx + 1) % MAX_PIPES;
        }

        bg_scroll += BG_SPEED * dt;
        g_scroll += G_SPEED * dt;

        bg_scroll = fmod(bg_scroll, BG_LOOP_POINT);
        g_scroll = fmod(g_scroll, G_LOOP_POINT);

        bird_update(&bird);

        for (int i = 0; i < MAX_PIPES; i++) {
            if (memcmp(&pipes[i], &(Pipe){0}, sizeof(Pipe)) != 0) {
                pipe_update(&pipes[i]);
            }
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode2D(camera);
                DrawTexture(textures[TEX_BACKGROUND], -bg_scroll, 0, WHITE);
                for (int i = 0; i < MAX_PIPES; i++) {
                    if (memcmp(&pipes[i], &(Pipe){0}, sizeof(Pipe)) != 0) {
                        pipe_draw(pipes[i], &textures[TEX_PIPE]);
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
