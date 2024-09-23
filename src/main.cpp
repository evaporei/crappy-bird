#include <raylib.h>

#include <math.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define GAME_WIDTH 512
#define GAME_HEIGHT 288

#define BG_SPEED 30
#define G_SPEED 60

#define BG_LOOP_POINT 413
#define G_LOOP_POINT GAME_WIDTH

int main(void) {
#ifndef DEBUG
    SetTraceLogLevel(LOG_ERROR);
#endif

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "flappy bird");

    Camera2D camera = { 0 };
    camera.target = (Vector2){ 0, 0 };
    camera.offset = (Vector2){ 0, 0 };
    camera.rotation = 0.0f;
    camera.zoom = 2.5f;

    Texture2D background = LoadTexture("background.png");
    Texture2D ground = LoadTexture("ground.png");

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
                DrawTexture(background, -bg_scroll, 0, WHITE);
                DrawTexture(ground, -g_scroll, GAME_HEIGHT - 16, WHITE);
            EndMode2D();
            DrawFPS(0, 0);
        EndDrawing();
    }

    UnloadTexture(ground);
    UnloadTexture(background);

    CloseWindow();

    return 0;
}
