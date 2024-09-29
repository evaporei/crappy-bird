#include "fonts.h"
#include "constants.h"

#include <stddef.h>

void fonts_init(Font *fonts) {
    fonts[FONT_MID] = LoadFontEx("./flappy.ttf", MID_FONT_SIZE, NULL, 0);
    fonts[FONT_BIG] = LoadFontEx("./flappy.ttf", BIG_FONT_SIZE, NULL, 0);
}
