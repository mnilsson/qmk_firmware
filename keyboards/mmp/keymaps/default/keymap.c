// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "raw_hid.h"
enum mmp_layers {
    _MMP_L1,
    _MMP_L2,
    _MMP_L3
};

enum mmp_keycodes {
    MMP_B1,
    MMP_B2,
    MMP_B3,
    MMP_B4,
    MMP_B5,
    MMP_B6,
    MMP_B7,
    MMP_B8,
    MMP_B9,
    MMP_B10,
    MMP_B11,
    MMP_B12,
    MMP_B13,
    MMP_B14,
    MMP_B15,
    MMP_B16,
    MMP_B17,
    MMP_B18,
    MMP_B19,
    MMP_B20,
    MMP_B21,
    MMP_B22,
    MMP_B23,
    MMP_B24,
    MMP_B25,
    MMP_B26,
    MMP_B27


};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ 7 │ 8 │ 9 │
     * ├───┼───┼───┤
     * │ 4 │ 5 │ 6 │
     * ├───┼───┼───┤
     * │ 1 │ 2 │ 3 │
     * ├───┼───┼───┘
     * │ < │ > │
     * └───┴───┘
     */
    [_MMP_L1] = LAYOUT(
        MMP_B1,   MMP_B2,   MMP_B3,
        MMP_B4,   MMP_B5,   MMP_B6,
        MMP_B7,   MMP_B8,   MMP_B9,
        MO(_MMP_L2),  MO(_MMP_L3)
    ),
    [_MMP_L2] = LAYOUT(
        MMP_B10,   MMP_B11,   MMP_B12,
        MMP_B13,   MMP_B14,   MMP_B15,
        MMP_B16,   MMP_B17,   MMP_B18,
        _______,  _______
        ),

    [_MMP_L3] = LAYOUT(
        MMP_B19,   MMP_B20,   MMP_B21,
        MMP_B22,   MMP_B23,   MMP_B24,
        MMP_B25,   MMP_B26,   QK_BOOT,
        _______,  _______
        )
};



void raw_hid_receive(uint8_t *data, uint8_t length) { raw_hid_send(data, length);}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    // Only handle our custom keycodes on press
    if (!record->event.pressed || keycode < MMP_B1 || keycode > MMP_B27) {
        return true;
    }

    uint8_t response[32] = {'M', 'M', 'P', 0, 0}; // Initialize with header
    uint8_t button_num = keycode - MMP_B1 + 1;    // Convert keycode to button number (1-27)

    // Convert button number to two-digit string
    response[3] = '0' + (button_num / 10);  // Tens digit
    response[4] = '0' + (button_num % 10);  // Ones digit

    raw_hid_send(response, 32);
    return false;


}