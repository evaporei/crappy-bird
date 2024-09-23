#include <raylib.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define GAME_WIDTH 512
#define GAME_HEIGHT 288

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

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode2D(camera);
                DrawTexture(background, 0, 0, WHITE);
                DrawTexture(ground, 0, GAME_HEIGHT - 16, WHITE);
            EndMode2D();
            DrawFPS(0, 0);
        EndDrawing();
    }

    UnloadTexture(ground);
    UnloadTexture(background);

    CloseWindow();

    return 0;
}
