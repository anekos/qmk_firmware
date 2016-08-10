#include "preonic.h"
#include "action_layer.h"
#include "eeconfig.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _EXT 3

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  EXT
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum {
  TD_COLON = 0,
  TD_QUOTE = 1,
  TD_ESC = 2
};


void dance_quote_finished (qk_tap_dance_state_t *state, void *user_data);
void dance_quote_reset (qk_tap_dance_state_t *state, void *user_data);

const qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_COLON]  = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, RSFT(KC_SCLN)),
  [TD_QUOTE]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_quote_finished, dance_quote_reset)
  // [TD_QUOTE]  = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, RSFT(KC_QUOT))
};

/**
 * Shift-and-Space は、「<Space><Space>おしっぱなし」とすることでキーリピートを発生させることができる。
 */

// XandY
#define MY_COLN CTL_T(KC_SCLN)
#define CT_SPC  SFT_T(KC_SPC)
#define BT_ESC  LT(_LOWER, KC_ESC)
#define BT_ENT  LT(_RAISE, KC_ENT)
#define TP_ESC  LT(_EXT, KC_ESC)
// Alias
#define KC_LT   LSFT(KC_COMM)
#define KC_GT   LSFT(KC_DOT)
// Tap Dance
#define MY_QUOT TD(TD_QUOTE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  `   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |ESC/Lo|      |      |      | Alt  | Spc  | Spc  |  Alt |      |      |      |Ent/Ra|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {TP_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS},
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV},
  {KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    MY_COLN, MY_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {BT_ESC,  _______, _______, _______, KC_LALT, CT_SPC,  CT_SPC,  KC_RALT, _______, _______, _______, BT_ENT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   [  |   ]  |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |   -  |   _  |   (  |   )  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   +  |   =  |   {  |   }  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   <  |   >  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______, KC_BSPC},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, KC_DEL },
  {_______, _______, _______, _______, _______, _______, KC_MINS, KC_UNDS, KC_LPRN, KC_RPRN, _______, _______},
  {_______, _______, _______, _______, _______, _______, KC_PLUS, KC_EQL,  KC_LT,   KC_GT,   _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | ↑↑ |  ↑  | ↓↓ | RESET|      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  ←  |  ↓  |  →  |      |      |  ←  |  ↓  |  ↑  |  →  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | MUSIC|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | LBtn | CBtn | RBtn |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC},
  {_______, KC_WH_U, KC_MS_U, KC_WH_D, RESET,   _______, _______, _______, _______, _______, _______, KC_DEL },
  {_______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______},
  {_______, _______, _______, _______, _______, _______, _______, MU_TOG,  _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, KC_BTN3, _______, _______, _______}
},

/* EXT
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | ↑↑ |  ↑  | ↓↓ | RESET|      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  ←  |  ↓  |  →  |      |      |  ←  |  ↓  |  ↑  |  →  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | MUSIC|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | LBtn | CBtn | RBtn |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_EXT] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC},
  {_______, KC_WH_U, KC_MS_U, KC_WH_D, RESET,   _______, _______, _______, _______, _______, _______, KC_DEL },
  {_______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______},
  {_______, _______, _______, _______, _______, _______, _______, MU_TOG,  _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, KC_BTN3, _______, _______, _______}
}

};

#ifdef AUDIO_ENABLE
float tone_startup[][2] = {
  {NOTE_B5, 20},
  {NOTE_B6, 8},
  {NOTE_DS6, 20},
  {NOTE_B6, 8}
};

float tone_qwerty[][2]  = SONG(QWERTY_SOUND);
float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
float music_scale[][2]  = SONG(MUSIC_SCALE_SOUND);
#endif

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
            #endif
            persistant_default_layer_set(1UL<<_QWERTY);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
          } else {
            layer_off(_LOWER);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
          } else {
            layer_off(_RAISE);
          }
          return false;
          break;
        case EXT:
          if (record->event.pressed) {
            layer_on(_EXT);
          } else {
            layer_off(_EXT);
          }
          return false;
          break;
      }
    return true;
};

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}


void dance_quote_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_QUOT);
  } else {
    register_code (KC_RSFT);
    register_code (KC_QUOT);
  }
}

void dance_quote_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_QUOT);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_QUOT);
  }
}


#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
