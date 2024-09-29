#pragma once

#include <raylib.h>

typedef enum FontKind {
    FONT_MID,
    FONT_BIG,

    FONT_LEN
} FontKind;

void fonts_init(Font *fonts);
