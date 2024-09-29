#include "selector.h"

#include <memory.h>

void scene_selector_init(SceneSelector *selector) {
    selector->curr = TITLE_SCENE;
    selector->next = TITLE_SCENE;
    title_scene_init(&selector->title, selector);
    memset(&selector->play, 0, sizeof(PlayScene));
}

void scene_selector_choose(void *selector, Scene next) {
    ((SceneSelector *)selector)->next = next;
}

void scene_selector_update(SceneSelector *selector) {
    // if we got new scene,
    // only change in new frame
    if (selector->curr != selector->next) {
        // technically we don't need this first switch
        switch (selector->curr) {
            case TITLE_SCENE:
                memset(&selector->title, 0, sizeof(TitleScene));
                break;
            case PLAY_SCENE:
                memset(&selector->play, 0, sizeof(PlayScene));
                break;
        }
        switch (selector->next) {
            case TITLE_SCENE:
                title_scene_init(&selector->title, selector);
                break;
            case PLAY_SCENE:
                play_scene_init(&selector->play, selector);
                break;
        }
        selector->curr = selector->next;
    }
    switch (selector->curr) {
        case TITLE_SCENE:
            title_scene_update(&selector->title);
            break;
        case PLAY_SCENE:
            play_scene_update(&selector->play);
            break;
    }
}

void scene_selector_draw(SceneSelector *selector) {
    switch (selector->curr) {
        case TITLE_SCENE:
            title_scene_draw(&selector->title);
            break;
        case PLAY_SCENE:
            play_scene_draw(&selector->play);
            break;
    }
}
