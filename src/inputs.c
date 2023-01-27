#include "inputs.h"

void process_input() {
    uint8_t joypad_state = joypad();
    switch (joypad_state) {
    case J_A:
        NR10_REG = 0x38U;
        NR11_REG = 0xAAU;
        NR12_REG = 0xE0U;
        NR13_REG = 0x0AU;
        NR14_REG = 0xC6U;

        NR51_REG |= 0x11;
        break;
    case J_B:
        delay(100);
        break;
    default:
        break;
    }
}