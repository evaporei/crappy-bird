#include <raylib.h>

#include <math.h>
#include <memory.h>

// selva
#include <primitives.h>

#include "constants.h"
#include "textures.h"
#include "scenes/selector.h"
#include "globals.h"

int main(void) {
#ifndef DEBUG
    SetTraceLogLevel(LOG_ERROR);
#endif
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "flappy bird");

    textures_init(textures);
    fonts_init(fonts);

    Camera2D camera = { 0 };
    camera.target = (Vector2){ 0, 0 };
    camera.offset = (Vector2){ 0, 0 };
    camera.rotation = 0.0f;
    camera.zoom = 2.5f;

    SceneSelector scene_selector;
    scene_selector_init(&scene_selector);

    f32 bg_scroll = 0;
    f32 g_scroll = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        scene_selector_update(&scene_selector);

        f32 dt = GetFrameTime();

        bg_scroll += BG_SPEED * dt;
        g_scroll += G_SPEED * dt;

        bg_scroll = fmod(bg_scroll, BG_LOOP_POINT);
        g_scroll = fmod(g_scroll, G_LOOP_POINT);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode2D(camera);
                DrawTexture(textures[TEX_BACKGROUND], -bg_scroll, 0, WHITE);
                scene_selector_draw(&scene_selector);
                DrawTexture(textures[TEX_GROUND], -g_scroll, GAME_HEIGHT - 16, WHITE);
            EndMode2D();
            DrawFPS(0, 0);
        EndDrawing();
    }

    for (usize i = 0; i < TEX_LEN; i++)
        UnloadTexture(textures[i]);

    CloseWindow();

    return 0;
}
