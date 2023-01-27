#include <gb/drawing.h>
#include <gb/gb.h>

#include <stdio.h>

void draw_grid();
void draw_grid_row(uint8_t row, char *word);
void draw_grid_cell(uint8_t row, uint8_t col, char letter);