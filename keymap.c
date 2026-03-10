#include <stdint.h>
#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif


// GRAPHITE home-row mods
#define LGUI_R LGUI_T(KC_R)
#define LSHT_T LSFT_T(KC_T)
#define LCTL_S LCTL_T(KC_S)
#define LALT_G LALT_T(KC_G)
#define RALT_Y LALT_T(KC_Y)
#define RCTL_H RCTL_T(KC_H)
#define RSHT_A RSFT_T(KC_A)
#define RGUI_E RGUI_T(KC_E)

// QWERTY home-row mods
#define LGUI_S LGUI_T(KC_S)
#define LSHT_D LSFT_T(KC_D)
#define LCTL_F LCTL_T(KC_F)
#define LALT_G LALT_T(KC_G)
#define RALT_H LALT_T(KC_H)
#define RCTL_J RCTL_T(KC_J)
#define RSHT_K RSFT_T(KC_K)
#define RGUI_L RGUI_T(KC_L)

// DHORF home-row mods
#define LGUI_R LGUI_T(KC_R)
#define LSHT_N LSFT_T(KC_N)
#define LCTR_T LCTL_T(KC_T)
#define LALT_W LALT_T(KC_W)
#define RALT_Y LALT_T(KC_Y)
#define RCTR_C RCTL_T(KC_C)
#define RSHT_A RSFT_T(KC_A)
#define RGUI_E RGUI_T(KC_E)

#define L_NAV_K LT(NAV, KC_K)
#define L_NAV_R LT(NAV, KC_R)
#define L_NAV_W LT(NAV, KC_W)

#define L_SYM__ LT(SYM, KC_SPC)

// clang-format off
enum layer_names {
    // BASE,
    DHORF=0, QWERTY, GRAPHITE, // Base keyboard layouts
    HOME_ROW_MODS, SYM, NAV, GAME, GAME_NAV, MOUSE,
    END
};

enum my_keycodes {
    LYR_DHORF = SAFE_RANGE, LYR_QWERTY, LYR_GRAPHITE,
    KG_COMM, KG_MINS, KG_SLSH,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DHORF] = LAYOUT(
                   KC_V,    KC_L,    KC_H, L_NAV_K,    KC_Q,                      KC_J,    KC_F,    KC_O,    KC_U, KC_COMM,
        KC_TAB,    KC_S,  LGUI_R,  LSHT_N,  LCTR_T,  LALT_W,                    RALT_Y,  RCTR_C,  RSHT_A,  RGUI_E,    KC_I, QK_MAKE,
        KC_ESC,    KC_Z,    KC_X,    KC_M,    KC_D,    KC_B, KC_MUTE, KC_MPLY,    KC_P,    KC_G, KC_QUOT, KC_SCLN,  KC_DOT, KC_RSFT,
         _______, OS_LSFT, L_SYM__,   LT(MOUSE, S(KC_MINS)),                   _______,  LT(SYM, KC_BSPC), OS_RSFT, _______
    ),
    [QWERTY] = LAYOUT(
                   KC_Q,    KC_W,    KC_E, L_NAV_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
       _______,    KC_A,  LGUI_S,  LSHT_D,  LCTL_F,  LALT_G,                    RALT_H,  RCTL_J,  RSHT_K,  RGUI_L, KC_SCLN, _______,
       _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, _______, _______,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, _______,
                         _______, _______, _______, _______,                   _______, _______, _______, _______
    ),
    [GRAPHITE] = LAYOUT(
                   KC_B,    KC_L,    KC_D, L_NAV_W,    KC_Z,                   KG_COMM,    KC_F,    KC_O,    KC_U,    KC_J,
       _______,    KC_N,  LGUI_R,  LSHT_T,  LCTL_S,  LALT_G,                    RALT_Y,  RCTL_H,  RSHT_A,  RGUI_E,    KC_I, _______,
       _______,    KC_Q,    KC_X,    KC_M,    KC_C,    KC_V, _______, _______,    KC_K,    KC_P,  KC_DOT, KG_MINS, KG_SLSH, _______,
                         _______, _______, _______, _______,                   _______, _______, _______, _______
    ),
    [SYM] = LAYOUT(
                _______, KC_LBRC, KC_LCBR, S(KC_9), KC_LABK,                   _______,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_TAB, _______, KC_RBRC, KC_RCBR, S(KC_0), KC_RABK,                    KC_EQL,    KC_4,    KC_5,    KC_6,    KC_I, QK_MAKE,
        KC_DEL, _______,  KC_GRV, KC_UNDS, KC_SLSH, KC_BSLS, KC_MUTE, KC_MPLY, KC_MINS,    KC_1,    KC_2,    KC_3,  KC_DOT, KC_RSFT,
                           TG(3), _______, _______, _______,                   _______, _______, _______, _______
    ),
    [NAV] = LAYOUT(
           LYR_GRAPHITE, _______, _______, _______, _______,                   _______, KC_PGUP, _______, KC_PGDN, _______,
     LYR_DHORF, _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, QK_MAKE,
    LYR_QWERTY, _______, _______, _______, _______, _______, _______, _______, KC_MINS, _______, _______, _______, _______, KC_RSFT,
                         _______, _______, _______, _______,                   _______, _______, _______, _______
    ),
    [MOUSE] = LAYOUT(
                _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
       _______, _______, MS_BTN2, MS_BTN3, MS_BTN1, _______,                   _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, _______,                   _______, _______, _______, _______
    ),
    [GAME] = LAYOUT(
                   KC_Q,    KC_F,    KC_L,    KC_E,    KC_R,                     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
        KC_TAB, KC_LCTL,    KC_A,    KC_W,    KC_D,    KC_F,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
        KC_ESC, KC_LSFT,    KC_X,    KC_S,    KC_C,    KC_V, KC_MUTE, KC_MPLY,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, TG(GAME),
              KC_LCTL, MO(GAME_NAV), KC_SPC, LT(MOUSE, S(KC_MINS)),            KC_LGUI,  KC_ENT, _______, KC_BSPC
    ),
    [GAME_NAV] = LAYOUT(
                 KC_1, KC_2, KC_3, KC_4, KC_5,                                  _______, _______, _______, _______, _______,
        _______, KC_6, KC_7, KC_8, KC_9, KC_0,                                  _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______,                            _______, _______, _______, _______
    )

    // [NEW] = LAYOUT(
    //              _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //                       _______, _______, _______, _______,                   _______, _______, _______, _______
    // )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(A(KC_VOLD), A(KC_VOLU))  },
    [1] = { ENCODER_CCW_CW(UG_HUED, UG_HUEU),  ENCODER_CCW_CW(UG_SATD, UG_SATU)  },
    [2] = { ENCODER_CCW_CW(UG_VALD, UG_VALU),  ENCODER_CCW_CW(UG_SPDD, UG_SPDU)  },
    [3] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),  ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [END-1] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),  ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif

const uint16_t PROGMEM backspace[] = {KC_L,   KC_H, COMBO_END};
const uint16_t PROGMEM tab[]       = {KC_B, LALT_W, COMBO_END};
const uint16_t PROGMEM escape[]    = {KC_X,   KC_M, COMBO_END};
const uint16_t PROGMEM enter[]     = {KC_G, RCTR_C, COMBO_END};
combo_t key_combos[] = {
    COMBO(backspace, KC_BSPC),
    COMBO(tab, KC_TAB),
    COMBO(escape, KC_ESC),
    COMBO(enter, KC_ENT),
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // // Host Keyboard Layer Status
    //  oled_write_P(PSTR("Layer: "), false);
     switch (get_highest_layer(layer_state)) {
         case 0:
             switch (get_highest_layer(default_layer_state)) {
                 case DHORF:
                     oled_write_P(PSTR("   DHORF\n"), false);
                     break;
                 case QWERTY:
                     oled_write_P(PSTR("   QWERTY\n"), false);
                     break;
                 case GRAPHITE:
                     oled_write_P(PSTR("   GRAPHITE\n"), false);
                     break;
             }
             break;
         case SYM:
             oled_write_P(PSTR("   SYMBOLS\n"), false);
             break;
         case NAV:
             oled_write_P(PSTR("   NAVIGATION\n"), false);
             break;
         default:
             // Or use the write_ln shortcut over adding '\n' to the end of your string
             oled_write_ln_P(PSTR("Undefined"), false);
     }

    //  // Host Keyboard LED Status
    //  led_t led_state = host_keyboard_led_state();
    //  oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    //  oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    //  oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return true;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KG_COMM:
            if (record->event.pressed){
                int mods1 = get_mods();
                if (mods1 == MOD_BIT(KC_LSFT) || mods1 == MOD_BIT(KC_RSFT)) {
                    tap_code(KC_MINUS);
                } else {
                    tap_code(KC_COMMA);
                }
            }
            break;
        case KG_MINS:
            if (record->event.pressed){
                int mods2 = get_mods();
                if (mods2 == MOD_BIT(KC_LSFT) || mods2 == MOD_BIT(KC_RSFT)) {
                    tap_code(KC_QUOTE);
                } else {
                    tap_code(KC_MINUS);
                }
            }
            break;
        case KG_SLSH:
            if (record->event.pressed){
                int mods3 = get_mods();
                if ( mods3 == MOD_BIT(KC_LSFT) || mods3 == MOD_BIT(KC_RSFT)) {
                    tap_code(KC_COMMA);
                } else {
                    tap_code(KC_SLASH);
                }
            }
            break;
        case LYR_DHORF:
            if (record->event.pressed) {
                default_layer_set(1UL << DHORF);
            } else {
            }
            break;
        case LYR_QWERTY:
            if (record->event.pressed) {
                default_layer_set(1UL << QWERTY | 1UL << DHORF);
            } else {
            }
            break;
        case LYR_GRAPHITE:
            if (record->event.pressed) {
                default_layer_set(1UL << GRAPHITE | 1UL << DHORF);
            } else {
            }
            break;
        default:
            return true;
            break;
    }
    return false;
}
