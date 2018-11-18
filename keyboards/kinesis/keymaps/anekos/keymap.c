#include QMK_KEYBOARD_H
#include "anekos.h"


#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  C1  |  C2  |  C3  |  C4  |  C5  |  C6  |  C8  |  C9  |  C10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | \      |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | `      |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Ctrl   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | INS  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Vim  | Alt  |         | Gui  | Term |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | S/Spc| A/Esc|------|         |------|A/Esc |S/Spc |
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/
[LR0] = LAYOUT(
   KC_ESC ,CON1   ,CON2   ,CON3   ,CON4   ,CON5   ,CON6   ,CON7   ,CON8 ,
   KC_EQL ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
   L1_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,
   KC_LCTL,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,
   KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,
           MO_1   ,KC_INS ,KC_LEFT,KC_RGHT,
                          AS(KC_G),CHRY,
                                   KC_HOME,
                   S_SPC  ,A_ESC  ,KC_END ,
    CON9  ,CON10  ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_F12,  WINBOOT, TRIPLE,
    KC_6  ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_BSLS,
    KC_Y  ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,L4_GRV ,
    KC_H  ,KC_J   ,KC_K   ,KC_L   ,C_COLN, KC_QUOT,
    KC_N  ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_ENT ,
           KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,
        AS(KC_ENT),AS(KC_ENT),
           KC_PGUP,
           KC_PGDN,  A_ESC,   S_SPC
    ),
/****************************************************************************************************
*
* 1 Parens
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* |        |      |      |      |      |      |                           |      |      |  {   |  }   |      | BkSp   |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* |        |      |      |      |      |      |                           |      |      |  [   |  ]   |      | Del    |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* |        |      |      |      |      |      |                           |  -   |  _   |  (   |  )   |      |        |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* |        |      |      |      |      |      |                           |  +   |  =   |  <   |  >   |      |        |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          |      |      |      |      |                                         |      |      |      |      |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        |      |      |         |      |      |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      |      |         |      |      |      |
*                                 | S/Spc| A/Esc|------|         |------|A/Esc |S/Spc |
*                                 |      |      |      |         |      |      |      |
*                                 `--------------------'         `--------------------'
*/
[LR1] = LAYOUT(
    KC_ESC ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
    _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,
            _______,_______,_______,_______,
                            _______,_______,
                                    _______,
                    _______,_______,_______,

    KC_F9 ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, KC_FN0, KC_1,
    _______,_______,KC_LCBR,KC_RCBR,_______,KC_BSPC,
    _______,_______,KC_LBRC,KC_RBRC,_______,KC_DEL ,
    KC_MINS,KC_UNDS,KC_LPRN,KC_RPRN,_______,_______,
    KC_PLUS,KC_EQL ,KC_LT  ,KC_GT  ,_______,_______,
            KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,
            _______,_______,
            _______,
            _______,_______,_______
    ),
/****************************************************************************************************
*
* 4 Parens
*
* ,-------------------------------------------------------------------------------------------------------------------.
* |        |      |      |      |      |      |      |      |      |      |      |      |      |      |      |        |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* |        |      |      |      |      |      |                           |      |      |  {   |  }   |      | BkSp   |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* |        |      |  ↑  |      |      |      |                           |      |      |  [   |  ]   |      | Del    |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* |        |  ←  |  ↓  | →   |      |      |                           |  -   |  _   |  (   |  )   |      |        |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* |        |      |      |      |      |      |                           |  +   |  =   |  <   |  >   |      |        |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          |      |      |      |      |                                         |      |      |      |      |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        |      |      |         |      |      |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      |      |         |      |      |      |
*                                 | S/Spc| A/Esc|------|         |------|A/Esc |S/Spc |
*                                 |      |      |      |         |      |      |      |
*                                 `--------------------'         `--------------------'
*/
[LR4] = LAYOUT(
    _______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,
    _______,_______,KC_UP  ,_______,_______,_______,
    _______,KC_LEFT,KC_DOWN,KC_RIGHT,_______,_______,
    _______,_______,_______,_______,_______,_______,
            _______,_______,_______,_______,
                            _______,_______,
                                    _______,
                    _______,_______,_______,

    _______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,KC_LCBR,KC_RCBR,_______,KC_BSPC,
    _______,_______,KC_LBRC,KC_RBRC,_______,KC_DEL ,
    KC_MINS,KC_UNDS,KC_LPRN,KC_RPRN,_______,_______,
    KC_PLUS,KC_EQL ,KC_LT  ,KC_GT  ,_______,_______,
            KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,
            _______,_______,
            _______,
            _______,_______,_______
    )
};


const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
      break;
  }
  return MACRO_NONE;
};


void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void led_set_user(uint8_t usb_led) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool my_result = false;

  if (my_process_record_user(keycode, record, &my_result))
    return my_result;

  return true;
}
