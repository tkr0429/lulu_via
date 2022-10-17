// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "bootloader.h"
#include "bongo2.h"

enum layers {
    _QWERTY,
    _RAISE,
    _LOWER,
    _ADJUST
};

//#define RAISE MO(_RAISE)
//#define LOWER MO(_LOWER)

enum custom_keycodes {
  QWERTY,
  LOWER,
  RAISE,
  ADJUST,
};

/*
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_LOWER] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [_RAISE] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [_ADJUST] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif
*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 
/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                          KC_LALT,    KC_LGUI, LOWER, KC_SPC,  KC_ENT,   RAISE,   KC_RGUI, KC_RALT,
                                             KC_VOLD, KC_VOLU, KC_PGUP, KC_PGDN
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, 
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_F12,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______,  KC_UNDS, KC_PLUS, KC_LBRC,KC_RBRC, KC_BSLS, KC_TILD,
                             _______, _______, _______, _______, _______,  _______, _______, _______,
                                               RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |MOD   | MODR |  S+  |  S-  |  B+  |  B-  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|RGB_TOG|    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  KC_GRV, _______, _______, _______, _______, _______,                      _______, _______, _______,_______, _______, _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_CIRC, KC_AMPR, KC_ASTR,KC_LPRN, KC_RPRN, _______,
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                       KC_MINS, KC_EQL,  KC_LCBR,KC_RCBR, KC_PIPE, KC_GRV,
  _______, KC_F11,  KC_F12, _______, _______, _______,   RGB_TOG, _______,  KC_UNDS, KC_PLUS, KC_LBRC,KC_RBRC, KC_BSLS, KC_TILD,
                             _______, _______, _______,  _______, _______,  _______, _______, _______,
                                               RGB_MOD, RGB_RMOD, RGB_HUI, RGB_HUD
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______,
                                               KC_VOLD, KC_VOLU, KC_PGUP, KC_PGDN
  )
};

// ========================== User Code ================================
uint8_t mod_state;
static bool lower_pressed = false;
static uint16_t lower_pressed_time = 0;
static bool raise_pressed = false;
static uint16_t raise_pressed_time = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
  }

  mod_state = get_mods();
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        lower_pressed = true;
        lower_pressed_time = record->event.time;
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        if (lower_pressed && (TIMER_DIFF_16(record->event.time, lower_pressed_time) < TAPPING_TERM)) {
          register_code(KC_LANG2);
          register_code(KC_MHEN);
          unregister_code(KC_MHEN);
          unregister_code(KC_LANG2);
        }
        lower_pressed = false;
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        raise_pressed = true;
        raise_pressed_time = record->event.time;
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        if (raise_pressed && (TIMER_DIFF_16(record->event.time, raise_pressed_time) < TAPPING_TERM)) {
          register_code(KC_LANG1);
          register_code(KC_HENK);
          unregister_code(KC_HENK);
          unregister_code(KC_LANG1);
        }
        raise_pressed = false;
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case KC_BSPC:
      {
        static bool delkey_registered;
        if (record->event.pressed) {
          if (mod_state & MOD_MASK_SHIFT) {
            del_mods(MOD_MASK_SHIFT);
            register_code(KC_DEL);
            delkey_registered = true;
            set_mods(mod_state);
            return false;
          }
        } else {
          if (delkey_registered) {
             unregister_code(KC_DEL);
             delkey_registered = false;
             return false;
          }
        }
        return true;
      }
      break;
    default:
      if (record->event.pressed) {
        lower_pressed = false;
        raise_pressed = false;
      }
      break;
  }
  return true;
}

// ========= Encoder ==============

#ifdef ENCODER_ENABLE

/* Rotary encoder settings */

keyevent_t encoder_left_ccw  = {
    .key = (keypos_t){.row = 2, .col = 6},
    .pressed = false
};

keyevent_t encoder_left_cw  = {
    .key = (keypos_t){.row = 1, .col = 6},
    .pressed = false
};

keyevent_t encoder_right_ccw  = {
    .key = (keypos_t){.row = 4, .col = 6},
    .pressed = false
};

keyevent_t encoder_right_cw  = {
    .key = (keypos_t){.row = 3, .col = 6},
    .pressed = false
};

void matrix_scan_user(void) {
    if (IS_PRESSED(encoder_left_ccw)) {
        encoder_left_ccw.pressed = false;
        encoder_left_ccw.time = (timer_read() | 1);
        action_exec(encoder_left_ccw);
    }

    if (IS_PRESSED(encoder_left_cw)) {
        encoder_left_cw.pressed = false;
        encoder_left_cw.time = (timer_read() | 1);
        action_exec(encoder_left_cw);
    }

    if (IS_PRESSED(encoder_right_ccw)) {
        encoder_right_ccw.pressed = false;
        encoder_right_ccw.time = (timer_read() | 1);
        action_exec(encoder_right_ccw);
    }

    if (IS_PRESSED(encoder_right_cw)) {
        encoder_right_cw.pressed = false;
        encoder_right_cw.time = (timer_read() | 1);
        action_exec(encoder_right_cw);
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Left rotary
        if (!clockwise){
            encoder_left_cw.pressed = true;
            encoder_left_cw.time = (timer_read() | 1);
            action_exec(encoder_left_cw);
        } else {
            encoder_left_ccw.pressed = true;
            encoder_left_ccw.time = (timer_read() | 1);
            action_exec(encoder_left_ccw);
        }
    } else if (index == 1) {
        // Right rotary Note:Reverse Rotation
        if (!clockwise){
            encoder_right_cw.pressed = true;
            encoder_right_cw.time = (timer_read() | 1);
            action_exec(encoder_right_cw);
        } else {
            encoder_right_ccw.pressed = true;
            encoder_right_ccw.time = (timer_read() | 1);
            action_exec(encoder_right_ccw);
        }
    }
    return true;
}

#endif
