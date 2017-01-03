#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "anekos.h"

#define _______ KC_TRNS


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

#define L1_ESC LT(LR1,KC_ESC)
#define L2_ENT LT(LR2,KC_ENT)
#define BT_ESC TD(TD_AESC)

#define TO_0 TO(LR0)
#define TO_1 TO(LR1)
#define TO_2 TO(LR2)
#define TO_3 TO(LR3)

#define MO_4 MO(LR4)

#define AS(x) LALT(LSFT(x))
#define SandS SFT_T(KC_SPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |      |           |OneSht|   6  |   7  |   8  |   9  |   0  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   `    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |  ESC |           | ENT  |   N  |   M  |   ,  |   .  |   /  | Shift  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |L1Esc |      |      |   -  |Esc/A |                                       | Esc/A|   -  |      |      | L2Ent|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |             |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Spc  |      |------|       |------|        | Spc  |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[LR0] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ESC,
        L1_ESC,  _______, MO_4,    KC_MINS, BT_ESC,


                                                     AS(KC_G),_______,
                                                              _______,
                                            SandS,   _______, _______,

        // right hand
             TD_LYR,  KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_BSLS,
             _______, KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_GRV,
                      KC_H,    KC_J,   KC_K,    KC_L,    C_COLN,  TD_QUOT,
             KC_ENT,  KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                               BT_ESC, KC_MINS, _______, _______, L2_ENT,

             _______, AS(KC_ENT),
             _______,
             _______, _______, SandS
    ),

/* Layer 1 - Parens
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
[LR1] = KEYMAP(
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
       TO_0,    _______, _______, KC_LCBR, KC_RCBR, _______, KC_BSPC,
       _______, _______, _______, KC_LBRC, KC_RBRC, _______, KC_DEL,
                KC_MINS, KC_UNDS, KC_LPRN, KC_RPRN, _______, _______,
       _______, KC_PLUS, KC_EQL,  KC_LT,   KC_GT,   _______, _______,
                         _______, _______, _______, _______, _______,

       _______, _______,
       _______,
       _______, _______, _______
),

/* Layer 2 - Mouse and Arrows
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | ↑↑ |  ↑  | ↓↓ |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  ←  |  ↓  |  →  |      |      |------|           |------|  ←  |  ↓  |  ↑  |  →  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | MB_R | MB_C |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      | MB_L |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[LR2] = KEYMAP(
       // left hand
       _______, CON1,    CON2,    CON3,    CON4,    CON5,    _______,
       _______, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______, _______,
       _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,

                                                    _______, _______,
                                                             _______,
                                           _______, _______, _______,

       // right hand
       TO_0,    CON6,    CON7,    CON8,    CON9,    CON10,   _______,
       _______, _______, _______, _______, _______, _______, _______,
                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                         KC_BTN2, KC_BTN3, _______, _______, _______,

       _______, RGB_SLD,
       _______,
       _______, _______, KC_BTN1
),

/* Layer 3
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |Toggle|Animat|Solid |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |HUE+  |SAT+  |VAL+  |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |HUE-  |SAT-  |VAL-  |      |      |------|           |------|      |      |      |      |      |        |
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
[LR3] = KEYMAP(
       // left hand
       _______, RGB_TOG, RGB_MOD, RGB_SLD, _______, _______, _______,
       _______, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______,
       _______, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,

                                                    _______, _______,
                                                             _______,
                                           _______, _______, _______,

       // right hand
       TO_0,    _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, _______, _______,

       _______, _______,
       _______,
       _______, _______, _______
),

/* Layer 4 - Unholy Keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      | BkSp   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|  ←  |  ↓  |  ↑  |  →  |      |        |
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
[LR4] = KEYMAP(
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
       _______, _______, _______, _______, _______, _______, KC_BSPC,
       _______, _______, _______, _______, _______, _______, _______,
                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, _______, _______,

       _______, _______,
       _______,
       _______, _______, _______
),

/* Layer 7 - Oneshot Layer Selector
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           | LR1  |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           | LR2  |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           | LR3  |      |      |      |      |      |        |
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
[LR7] = KEYMAP(
       // left hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, VRSN,    _______, _______,
       _______, _______, _______, _______, _______,

                                                    _______, _______,
                                                             _______,
                                           _______, _______, _______,

       // right hand
       TO_1,    _______, _______, _______, _______, _______, _______,
       TO_2,    _______, _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______, _______,
       TO_3,    _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, _______, _______,

       _______, _______,
       _______,
       _______, _______, _______
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
            ergodox_right_led_3_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            ergodox_right_led_2_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            break;
        case 5:
            ergodox_right_led_3_on();
            ergodox_right_led_1_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_1_on();
            break;
        case 7:
            ergodox_right_led_3_on();
            ergodox_right_led_2_on();
            ergodox_right_led_1_on();
            break;
        default:
            // none
            break;
    }

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;

      break;
  }
  return true;
}
