#include "textures.h"

void textures_init(Texture2D *textures) {
    textures[TEX_BACKGROUND] = LoadTexture("background.png");
    textures[TEX_GROUND] = LoadTexture("ground.png");
    textures[TEX_BIRD] = LoadTexture("bird.png");
    textures[TEX_PIPE] = LoadTexture("pipe.png");
}
