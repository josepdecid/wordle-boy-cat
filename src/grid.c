#include "grid.h"

const uint8_t SCREEN_SIZE_X = 160;
const uint8_t SCREEN_SIZE_Y = 144;

const uint8_t CELL_SIZE = 12;
const uint8_t CELL_PADDING = 2;

const uint8_t MARGIN_TOP_GRID = 24;

void draw_grid_cell(uint8_t row, uint8_t col) {
    uint8_t starting_x = (SCREEN_SIZE_X - CELL_SIZE * 5 - CELL_PADDING * 4) / 2;
    uint8_t starting_y = MARGIN_TOP_GRID;

    uint8_t x1 = starting_x + col * (CELL_SIZE + CELL_PADDING);
    uint8_t x2 = x1 + CELL_SIZE;

    uint8_t y1 = starting_y + row * (CELL_SIZE + CELL_PADDING);
    uint8_t y2 = y1 + CELL_SIZE;

    box(x1, y1, x2, y2, M_NOFILL);
}

void draw_grid_row(uint8_t row) {
    for (uint8_t col = 0; col < 5; col++) {
        draw_grid_cell(row, col);
    }
}

void draw_grid() {
    for (uint8_t row = 0; row < 5; row++) {
        draw_grid_row(row);
    }
}