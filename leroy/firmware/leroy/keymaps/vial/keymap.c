#include QMK_KEYBOARD_H

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
    [2] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
    [3] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  }
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,                  KC_MEDIA_PLAY_PAUSE,
        KC_A,  KC_B,    KC_C,    KC_D,
        KC_1,  KC_2,    KC_3,    KC_4
    ),
    [1] = LAYOUT(
        _______,                          _______,
        _______,  _______,    _______,    _______,
        _______,  _______,    _______,    _______
    ),
    [2] = LAYOUT(
        _______,                          _______,
        _______,  _______,    _______,    _______,
        _______,  _______,    _______,    _______
    ),
    [3] = LAYOUT(
        _______,                          _______,
        _______,  _______,    _______,    _______,
        _______,  _______,    _______,    _______
    )
};