// Copyright 2026 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_LOWER] =  { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_RAISE] =  { ENCODER_CCW_CW(KC_DOWN, KC_UP),   ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
    [_ADJUST] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
        KC_ESC,  KC_LGUI, MO(_LOWER), KC_SPC,                          KC_ENT,  MO(_RAISE), KC_BSPC, KC_DEL
    ),

    [_LOWER] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_TAB,  XXXXXXX, KC_UP,   XXXXXXX, KC_PGUP,                   KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
        KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, _______, KC_ESC,                             KC_DEL,  _______, _______, _______
    ),

    [_RAISE] = LAYOUT(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                    KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
        _______, _______, _______, KC_TAB,                             KC_SPC,  _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,                   XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,
        XXXXXXX, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD,                  XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX,
        _______, _______, _______, _______,                            _______, _______, _______, _______
    )
};
