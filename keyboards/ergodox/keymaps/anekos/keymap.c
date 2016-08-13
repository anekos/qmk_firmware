#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define _______ KC_TRNS

#define _BASE 0
#define _LOWER 1
#define _RAISE 2

enum {
  TD_AESC = 0
};

const qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_AESC]  = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_ESC)
};

#define LO_ESC LT(_LOWER,KC_ESC)
#define RA_ENT LT(_RAISE,KC_ENT)
#define BT_ESC TD(TD_AESC)

#define AS(x) LALT(LSFT(x))
#define SandS SFT_T(KC_SPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   `    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |  ESC |           | ENT  |   N  |   M  |   ,  |   .  |   /  | Shift  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LOEsc |      |      |      |Esc/A |                                       | Esc/A|      |      |      | RAEnt|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |             |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Spc  |      |------|       |------|        | Spc  |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ESC,
        LO_ESC,  _______, _______, _______, BT_ESC,


                                                     AS(KC_G), _______,
                                                              _______,
                                            SandS,   _______, _______,

        // right hand
             _______, KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_BSLS,
             _______, KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_GRV,
                      KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
             KC_ENT,  KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                               BT_ESC, _______, _______, _______, RA_ENT,

             _______, AS(KC_ENT),
             _______,
             _______, _______, SandS
    ),

/* Lower
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |  {   |  }   |      |  BkSpc |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |  [   |  ]   |      |  Del   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|   -  |   _  |  (   |  )   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   +  |   =  |  <   |  >   |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_LOWER] = KEYMAP(
       // left hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,

                                                    _______, _______,
                                                             _______,
                                           _______, _______, _______,

       // right hand
       _______, _______, _______, KC_LCBR, KC_RCBR, _______, KC_BSPC,
       _______, _______, _______, KC_LBRC, KC_RBRC, _______, KC_DEL,
                KC_MINS, KC_UNDS, KC_LPRN, KC_RPRN, _______, _______,
       _______, KC_PLUS, KC_EQL,  KC_LT,   KC_GT,   _______, _______,
                         _______, _______, _______, _______, _______,

       _______, _______,
       _______,
       _______, _______, _______
),

/* Raise
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_RAISE] = KEYMAP(
       // left hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, RESET,   _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,

                                                    _______, _______,
                                                             _______,
                                           _______, _______, _______,

       // right hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                         KC_BTN2, KC_BTN3, _______, _______, _______,

       _______, _______,
       _______,
       _______, _______, KC_BTN1
),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
