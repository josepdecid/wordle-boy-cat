#include "grid.h"

const uint8_t SCREEN_SIZE_X = 160;
const uint8_t SCREEN_SIZE_Y = 144;

const uint8_t CELL_SIZE = 14;
const uint8_t CELL_PADDING_X = 2;
const uint8_t CELL_PADDING_Y = 2;

const uint8_t MARGIN_TOP_GRID = 4;

const char *TARGET_WORD = "TRETS";

uint8_t set_box_color_from_match(char value, uint8_t value_idx) {
    if (TARGET_WORD[value_idx] == value) {
        color(LTGREY, LTGREY, M_NOFILL);
        return 1;
    }

    for (uint8_t idx = 0; idx < 5; idx++) {
        if (TARGET_WORD[idx] == value) {
            color(DKGREY, DKGREY, M_NOFILL);
            return 1;
        }
    }

    color(WHITE, DKGREY, M_NOFILL);
    return 0;
}

uint8_t set_letter_color_from_match(char value, uint8_t value_idx) {
    if (TARGET_WORD[value_idx] == value) {
        color(BLACK, LTGREY, M_NOFILL);
        return 1;
    }

    for (uint8_t idx = 0; idx < 5; idx++) {
        if (TARGET_WORD[idx] == value) {
            color(WHITE, DKGREY, M_NOFILL);
            return 1;
        }
    }

    color(BLACK, WHITE, M_NOFILL);
    return 0;
}

void draw_grid_cell(uint8_t row, uint8_t col, char letter) {
    uint8_t starting_x = (SCREEN_SIZE_X - CELL_SIZE * 5 - CELL_PADDING_X * 4) / 2 - 4;
    uint8_t starting_y = MARGIN_TOP_GRID;

    uint8_t x1 = starting_x + col * (CELL_SIZE + CELL_PADDING_X);
    uint8_t x2 = x1 + CELL_SIZE;

    uint8_t y1 = starting_y + row * (CELL_SIZE + CELL_PADDING_Y);
    uint8_t y2 = y1 + CELL_SIZE;

    // Paint cell background according to the match status.
    uint8_t has_match = set_box_color_from_match(letter, col);
    if (has_match) {
        box(x1, y1, x2, y2, M_FILL);
    }

    // Draw cell outline.
    color(BLACK, WHITE, M_NOFILL);
    box(x1, y1, x2, y2, M_NOFILL);

    gotogxy(2 * col + 5, 2 * row + 1);
    set_letter_color_from_match(letter, col);
    wrtchr(letter);
}

void draw_grid_row(uint8_t row, char *word) {
    for (uint8_t col = 0; col < 5; col++) {
        draw_grid_cell(row, col, word[col]);
    }
}

void draw_grid() {
    // TODO: Hardcoded here as a test
    char *guesses[6] = {
        "COSES",
        "SERPS",
        "REPTE",
        "ERINA",
        "DRETS",
        "TRETS",
    };

    for (uint8_t row = 0; row < 6; row++) {
        draw_grid_row(row, guesses[row]);
    }
}