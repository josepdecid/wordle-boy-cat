#include <gb/drawing.h>
#include <gb/gb.h>

#include <gbdk/console.h>
#include <gbdk/font.h>

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "grid.c"
#include "inputs.c"
#include "keyboard.c"

void init() {
    DISPLAY_ON; // Turn on the display

    NR50_REG = 0x77; // Increase the volume to its max
    NR51_REG = 0x11; // Enable the sound channels
    NR52_REG = 0x8F; // Turn on the sound
}

void main() {
    init();

    draw_grid();
    draw_keyboard();

    while (1) {
        process_input();
        wait_vbl_done();
    }
}
