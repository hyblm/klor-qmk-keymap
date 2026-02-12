#include <stdint.h>
#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

// Left-hand home row mods
#define GUI_R LGUI_T(KC_R)
#define SFT_N LSFT_T(KC_N)
#define CTR_T LCTL_T(KC_T)
#define ALT_W LALT_T(KC_W)

// Right-hand home row mods
#define ALT_Y LALT_T(KC_Y)
#define CTR_C RCTL_T(KC_C)
#define SFT_A RSFT_T(KC_A)
#define GUI_E RGUI_T(KC_E)

// clang-format off
typedef enum tagLayer {
    BASE     = 0,
    SYM      = 1,
    NAV      = 2,
    GAME     = 3,
    GAME_NAV = 4,
    MOUSE    = 5,
} Layer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
                KC_V,  KC_L,  KC_H, LT(NAV, KC_K), KC_Q,                   KC_J,   KC_F,    KC_O,    KC_U, KC_COMM,
        KC_TAB, KC_S, GUI_R, SFT_N,        CTR_T, ALT_W,                   ALT_Y, CTR_C,   SFT_A,   GUI_E,    KC_I, QK_MAKE,
        KC_ESC, KC_Z,  KC_X,  KC_M,         KC_D,  KC_B, KC_MUTE, KC_MPLY, KC_P,   KC_G, KC_QUOT, KC_SCLN,  KC_DOT, KC_RSFT,
        KC_TRNS,  OS_LSFT, LT(SYM, KC_SPC),   LT(MOUSE, S(KC_MINS)),       KC_TRNS, LT(SYM, KC_BSPC), OS_RSFT, KC_TRNS
    ),
    [SYM] = LAYOUT(
                KC_TRNS, KC_LBRC, S(KC_LBRC), S(KC_9), S(KC_COMM),                KC_TRNS, KC_7, KC_8, KC_9, KC_0,
        KC_TAB, KC_TRNS, KC_RBRC, S(KC_RBRC), S(KC_0), S(KC_DOT),                  KC_EQL, KC_4, KC_5, KC_6, KC_I, QK_MAKE,
        KC_DEL, KC_TRNS, KC_GRV,  S(KC_MINS), KC_SLSH, KC_BSLS, KC_MUTE, KC_MPLY, KC_MINS, KC_1, KC_2, KC_3,KC_DOT, KC_RSFT,
                  TG(3), KC_TRNS,    KC_TRNS, KC_TRNS,                            KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [NAV] = LAYOUT(
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, QK_MAKE,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_MINS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RSFT,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [MOUSE] = LAYOUT(
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, MS_BTN2, MS_BTN3, MS_BTN1, DF(BASE),                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DF(GAME), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [GAME] = LAYOUT(
                   KC_Q, KC_Q, KC_L, KC_E, KC_R,                   KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
        KC_TAB, KC_LCTL, KC_A, KC_W, KC_D, KC_F,                   KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_ESC, KC_LSFT, KC_X, KC_S, KC_C, KC_V, KC_MUTE, KC_MPLY, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TG(GAME),
              KC_LCTL, MO(GAME_NAV), KC_SPC, LT(MOUSE, S(KC_MINS)),                   KC_LGUI, KC_ENT, KC_TRNS, KC_BSPC
    ),
    [GAME_NAV] = LAYOUT(
                 KC_1, KC_2, KC_3, KC_4, KC_5,                                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_6, KC_7, KC_8, KC_9, KC_0,                                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )

    // [NEW] = LAYOUT(
    //              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    // )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(A(KC_VOLD), A(KC_VOLU))  },
    [1] = { ENCODER_CCW_CW(UG_HUED, UG_HUEU),  ENCODER_CCW_CW(UG_SATD, UG_SATU)  },
    [2] = { ENCODER_CCW_CW(UG_VALD, UG_VALU),  ENCODER_CCW_CW(UG_SPDD, UG_SPDU)  },
    [3] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),  ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [4] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),  ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [5] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),  ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif

const uint16_t PROGMEM backspace[] = {KC_L, KC_H, COMBO_END};
const uint16_t PROGMEM tab[] = {KC_B, ALT_W, COMBO_END};
const uint16_t PROGMEM escape[] = {KC_X, KC_M, COMBO_END};
const uint16_t PROGMEM enter[] = {KC_G, CTR_C, COMBO_END};
combo_t key_combos[] = {
    COMBO(backspace, KC_BSPC),
    COMBO(tab, KC_TAB),
    COMBO(escape, KC_ESC),
    COMBO(enter, KC_ENT),
};

#ifdef OLED_ENABLE
// bool oled_task_user(void) {
    // Host Keyboard Layer Status
    // oled_write_P(PSTR("Layer: "), false);
    //
    // switch (get_highest_layer(layer_state)) {
    //     case 0:
    //         oled_write_P(PSTR("Default\n"), false);
    //         break;
    //     case 1:
    //         oled_write_P(PSTR("symbol\n"), false);
    //         break;
    //     case 2:
    //         oled_write_P(PSTR("nav\n"), false);
    //         break;
    //     default:
    //         // Or use the write_ln shortcut over adding '\n' to the end of your string
    //         oled_write_ln_P(PSTR("Undefined"), false);
    // }
    //
    // // Host Keyboard LED Status
    // led_t led_state = host_keyboard_led_state();
    // oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    // oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    // oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    //
//     return false;
// }
#endif
