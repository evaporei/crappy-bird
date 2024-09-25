#include <raylib.h>

#include <math.h>

#include "constants.h"
#include "bird.h"
#include "textures.h"

Texture2D textures[TEX_LEN];

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
    bird_init(&bird, &textures[TEX_BIRD]);

    float bg_scroll = 0;
    float g_scroll = 0;

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        bg_scroll += BG_SPEED * dt;
        g_scroll += G_SPEED * dt;

        bg_scroll = fmod(bg_scroll, BG_LOOP_POINT);
        g_scroll = fmod(g_scroll, G_LOOP_POINT);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode2D(camera);
                DrawTexture(textures[TEX_BACKGROUND], -bg_scroll, 0, WHITE);
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
