/* Copyright 2021 m.ki
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN1,
    _FN2
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_7,      KC_8,   KC_9,
        KC_4,      KC_5,   KC_6,
        KC_1,      KC_2,   KC_3,
        LT(_FN1,KC_0), KC_DOT, LT(_FN2,KC_PENT)   ),
    [_FN1] = LAYOUT(
        LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),
        LCTL(KC_A),KC_UP,KC_BSPC,
        KC_LEFT,   KC_DOWN,KC_RIGHT,
        KC_NO,     KC_COMM,KC_SPC    ),
    [_FN2] = LAYOUT(
        KC_PPLS,    KC_PMNS,  KC_NO,
        KC_PAST,   KC_PSLS,   KC_NO,
        KC_PEQL,   KC_PSCR,   KC_NO,
        RESET,     KC_NO,     KC_NO   )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}
