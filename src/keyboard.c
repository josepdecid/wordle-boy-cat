#include "keyboard.h"

const uint8_t MARGIN_TOP_KEYBOARD = 104;

const char *layout[3] = {
    " A B C C D E F G H",
    " I J K L M N O P Q",
    " R S T U V W X Y Z"};

void draw_keyboard() {
    color(BLACK, WHITE, M_NOFILL);

    for (uint8_t row_idx = 0; row_idx < 3; row_idx++) {
        uint8_t row_length = strlen(layout[row_idx]);
        for (uint8_t char_idx = 0; char_idx < row_length; char_idx++) {
            gotogxy(char_idx, MARGIN_TOP_KEYBOARD / 8 + 2 * row_idx);
            char letter = layout[row_idx][char_idx];
            wrtchr(letter);
        }
    }

    SPRITES_8x16;

    set_sprite_data(0, 4, selected_letter_sprite);
    move_sprite(0, 12, MARGIN_TOP_KEYBOARD + 12);

    set_sprite_tile(1, 2);
    move_sprite(1, 12 + 8, MARGIN_TOP_KEYBOARD + 12);

    SHOW_SPRITES;
}