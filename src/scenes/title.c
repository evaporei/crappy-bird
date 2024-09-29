#include "title.h"

#include <memory.h>
#include <raylib.h>

#include "../constants.h"
#include "../globals.h"
#include "scenes.h"

void title_scene_init(TitleScene *scene, void *parent) {
    scene->parent = parent;
}

void title_scene_update(TitleScene *scene) {
    if (IsKeyPressed(KEY_ENTER)) {
        scene_selector_choose(scene->parent, PLAY_SCENE);
    }
}

void title_scene_draw(TitleScene *scene) {
    char *title = "Crappy Bird";
    Vector2 title_size = MeasureTextEx(fonts[FONT_BIG], title, BIG_FONT_SIZE, 0);
    Vector2 title_pos = (Vector2){GAME_WIDTH / 2.f - title_size.x / 2, 64 - title_size.y / 2};
    DrawTextEx(fonts[FONT_BIG], title, title_pos, BIG_FONT_SIZE, 0, WHITE);

    char *tip = "Press Enter";
    Vector2 tip_size = MeasureTextEx(fonts[FONT_MID], title, MID_FONT_SIZE, 0);
    Vector2 tip_pos = (Vector2){GAME_WIDTH / 2.f - tip_size.x / 2, 100 - tip_size.y / 2};
    DrawTextEx(fonts[FONT_MID], tip, tip_pos, MID_FONT_SIZE, 0, WHITE);
}
