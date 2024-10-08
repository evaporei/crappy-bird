#pragma once

#include "title.h"
#include "play.h"
#include "scenes.h"

typedef struct SceneSelector {
    Scene curr;
    Scene next;
    TitleScene title;
    PlayScene play;
} SceneSelector;

void scene_selector_init(SceneSelector *selector);

void scene_selector_update(SceneSelector *selector);

void scene_selector_draw(SceneSelector *selector);
