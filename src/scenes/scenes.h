#pragma once

typedef enum Scene {
    TITLE_SCENE,
    PLAY_SCENE
} Scene;

void scene_selector_choose(void *selector, Scene next);
