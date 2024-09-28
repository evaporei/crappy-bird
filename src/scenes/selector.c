#include "selector.h"

void scene_selector_init(SceneSelector *selector) {
    selector->curr = PLAY_SCENE;
    play_scene_init(&selector->play);
}

void scene_selector_update(SceneSelector *selector) {
    switch (selector->curr) {
        case PLAY_SCENE:
            play_scene_update(&selector->play);
            break;
    }
}

void scene_selector_draw(SceneSelector *selector) {
    switch (selector->curr) {
        case PLAY_SCENE:
            play_scene_draw(&selector->play);
            break;
    }
}
