#include "keymap_common.h"
#include "planck.h"
#include "backlight.h"
#include "debug.h"

#define _QW 0
#define _LW 1
#define _RS 2
#define _SP 3
#define _NM 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = { /* Qwerty */
    {KC_TAB  , KC_Q       , KC_W   , KC_E    , KC_R    , KC_T   , KC_Y   , KC_U    , KC_I    , KC_O    , KC_P    , KC_GRV}  ,
    {KC_LCTL , KC_A       , KC_S   , KC_D    , KC_F    , KC_G   , KC_H   , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT} ,
    {KC_LSFT , KC_Z       , KC_X   , KC_C    , KC_V    , KC_B   , KC_N   , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_MINS}  ,
    {FUNC(1) , S(KC_MINS) , KC_EQL , KC_LALT , MO(_LW) , KC_SPC , KC_SPC , MO(_RS) , KC_RALT , KC_LBRC , KC_RBRC , KC_BSLS}
  },
  [_RS] = { /* RAISE */
    {KC_TRNS , KC_1       , KC_2       , KC_3       , KC_4       , KC_5       , KC_6            , KC_7    , KC_8    , KC_9    , KC_0     , KC_DELETE} ,
    {KC_TRNS , LALT(KC_1) , LALT(KC_2) , LALT(KC_3) , LALT(KC_4) , LALT(KC_5) , KC_LEFT         , KC_DOWN , KC_UP   , KC_RGHT , KC_TRNS  , KC_TRNS}   ,
    {KC_TRNS , LALT(KC_6) , LALT(KC_7) , LALT(KC_8) , LALT(KC_9) , LALT(KC_0) , KC_HOME         , KC_PGDN , KC_PGUP , KC_END  , KC_TRNS  , KC_TRNS}   ,
    {KC_TRNS , KC_TRNS    , KC_TRNS    , KC_TRNS    , MO(_SP)    , KC_TRNS    , LALT(S(KC_ENT)) , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS  , KC_TRNS}
  },
  [_LW] = { /* LOWER */
    {KC_TRNS , S(KC_1)    , S(KC_2)    , S(KC_3)    , S(KC_4)    , S(KC_5)       , S(KC_6) , S(KC_7) , S(KC_8) , S(KC_9) , S(KC_0) , KC_BSPC}   ,
    {KC_TRNS , LALT(KC_1) , LALT(KC_2) , LALT(KC_3) , LALT(KC_4) , LALT(KC_5)    , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_MINS , S(KC_EQL)} ,
    {KC_TRNS , LALT(KC_6) , LALT(KC_7) , LALT(KC_8) , LALT(KC_9) , LALT(KC_0)    , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_ENT}   ,
    {KC_TRNS , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , LALT(S(KC_G)) , KC_TRNS , MO(_SP) , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS}
  },
  [_SP] = { /* RAISE + LOWER */
    {KC_TRNS , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_TRNS} ,
    {KC_TRNS , KC_F11  , KC_F12  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , BL_DEC  , BL_INC  , KC_TRNS , KC_TRNS , KC_TRNS} ,
    {KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS} ,
    {BL_TOGG , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , RESET}
  },
  [_NM] = { /* Numpad */
    {KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , S(KC_8)   , KC_7 , KC_8   , KC_9    , KC_BSPC , LCTL(KC_U)} ,
    {KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , S(KC_EQL) , KC_4 , KC_5   , KC_6    , KC_MINS , KC_TRNS} ,
    {KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_MINS   , KC_1 , KC_2   , KC_3    , KC_ENT  , KC_ENT} ,
    {KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_SLSH   , KC_0 , KC_DOT , KC_EQL  , KC_TRNS , KC_TRNS}
  }
};


const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_KEY(_NM, KC_ESC),  // Tap for space, hold for SpaceFN
};
