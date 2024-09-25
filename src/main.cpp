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

typedef enum TextureKind {
    TEX_BACKGROUND,
    TEX_GROUND,
    TEX_BIRD,

    TEX_LEN
} TextureKind;

Texture2D textures[TEX_LEN];

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

    textures[TEX_BACKGROUND] = LoadTexture("background.png");
    textures[TEX_GROUND] = LoadTexture("ground.png");
    textures[TEX_BIRD] = LoadTexture("bird.png");

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
                DrawTexture(textures[TEX_BIRD], GAME_WIDTH / 2 - textures[TEX_BIRD].width / 2, GAME_HEIGHT / 2 - textures[TEX_BIRD].height / 2, WHITE);
            EndMode2D();
            DrawFPS(0, 0);
        EndDrawing();
    }

    for (int i = 0; i < TEX_LEN; i++)
        UnloadTexture(textures[i]);

    CloseWindow();

    return 0;
}
