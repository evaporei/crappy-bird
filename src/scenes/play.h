#pragma once

#include <primitives.h>

#include "../entities.h"
#include "../constants.h"

typedef struct PlayScene {
    Bird bird;
    PipePair pipe_pairs[MAX_PIPES];
    usize empty_idx;
    f64 spawn_timer;
} PlayScene;

void play_scene_init(PlayScene *scene);

void play_scene_update(PlayScene *scene);

void play_scene_draw(PlayScene *scene);
