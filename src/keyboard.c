#include "keyboard.h"

const uint8_t MARGIN_TOP_KEYBOARD = 104;

const char *layout[3] = {
    "Q W E R T Y U I O P",
    " A S D F G H J K L ",
    "    Z X C V B N M  "};

void draw_keyboard() {
    for (uint8_t row_idx = 0; row_idx < 3; row_idx++) {
        uint8_t row_length = strlen(layout[row_idx]);
        for (uint8_t char_idx = 0; char_idx < row_length; char_idx++) {
            gotogxy(char_idx, MARGIN_TOP_KEYBOARD / 8 + row_idx);
            char letter = layout[row_idx][char_idx];
            wrtchr(letter);
        }
    }

    // gotogxy(0, MARGIN_TOP_KEYBOARD / 8 + 3);
    // gprint("      A - Afegir");

    // gotogxy(0, MARGIN_TOP_KEYBOARD / 8 + 4);
    // gprint("      B - Esborrar");

    // gotogxy(0, MARGIN_TOP_KEYBOARD / 8 + 5);
    // gprint("  START - Verificar");
}