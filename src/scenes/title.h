#pragma once

#include <primitives.h>

typedef struct TitleScene {
    void *parent;
} TitleScene;

void title_scene_init(TitleScene *scene, void *parent);

void title_scene_update(TitleScene *scene);

void title_scene_draw(TitleScene *scene);
