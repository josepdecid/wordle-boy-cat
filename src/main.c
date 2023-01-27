#include <gb/drawing.h>
#include <gb/gb.h>

#include <gbdk/console.h>
#include <gbdk/font.h>

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "grid.c"
#include "keyboard.c"

void init() {
    DISPLAY_ON;      // Turn on the display
    NR52_REG = 0x8F; // Turn on the sound
    NR51_REG = 0x11; // Enable the sound channels
    NR50_REG = 0x77; // Increase the volume to its max
}

void main() {

    init();

    while (1) {
        gotogxy(3, 1);
        gprint("WordleBoy CAT!");

        draw_grid();
        draw_keyboard();

        wait_vbl_done();
    }
}
