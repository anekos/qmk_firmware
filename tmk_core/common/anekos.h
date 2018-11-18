
#ifndef ANEKOS_H
#define ANEKOS_H


/**
 * Shift-and-Space は、「<Space><Space>おしっぱなし」とすることでキーリピートを発生させることができる。
 */

// Layers
#define LR0 0
#define LR1 1
#define LR2 2
#define LR3 3
#define LR4 4
#define LR5 5
#define LR6 6
#define LR7 7


// XandY
#define A_ESC   ALT_T(KC_ESC)
#define C_COLN  CTL_T(KC_SCLN)
#define S_SPC   SFT_T(KC_SPC)
 
// Layer
#define L1_ESC  LT(LR1, KC_ESC)
#define L1_TAB  LT(LR1, KC_TAB)
#define L2_ENT  LT(LR2, KC_ENT)
#define L4_GRV  LT(LR4, KC_GRV)
#define L5_ESC  LT(LR5, KC_ESC)
#define TO_0 TO(LR0)
#define TO_1 TO(LR1)
#define TO_2 TO(LR2)
#define TO_3 TO(LR3)
#define TO_4 TO(LR4)
#define TO_5 TO(LR5)
#define TO_6 TO(LR6)
#define TO_7 TO(LR7)
#define MO_1 MO(LR1)
#define MO_2 MO(LR2)
#define MO_3 MO(LR3)
#define MO_4 MO(LR4)
#define MO_5 MO(LR5)
#define MO_6 MO(LR6)
#define MO_7 MO(LR7)

// Alias
#define KC_LT   LSFT(KC_COMM)
#define KC_GT   LSFT(KC_DOT)

// Switch consoles
#define CON1    LCTL(LALT(KC_F1))
#define CON2    LCTL(LALT(KC_F2))
#define CON3    LCTL(LALT(KC_F3))
#define CON4    LCTL(LALT(KC_F4))
#define CON5    LCTL(LALT(KC_F5))
#define CON6    LCTL(LALT(KC_F6))
#define CON7    LCTL(LALT(KC_F7))
#define CON8    LCTL(LALT(KC_F8))
#define CON9    LCTL(LALT(KC_F9))
#define CON10   LCTL(LALT(KC_F10))

// Speicial
#define AS(x) LALT(LSFT(x))
#define SandS SFT_T(KC_SPC)

// Combinations
#define TRIPLE LALT(LCTL(KC_DEL))
#define StmSS  LALT(LSFT(KC_G))   // Steam Screen Shot


enum my_custom_keycodes {
  __LR0 = SAFE_RANGE,
  __LR1,
  __LR2,
  __LR3,
  __LR4,
  __LR5,
  __LR7,
  WINBOOT,
  CHRY,
};


bool my_process_record_user(uint16_t keycode, keyrecord_t *record, bool *result) {
  switch (keycode) {
    case CHRY:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("s")"C");
      }
      *result = false;
      return true;
    case WINBOOT:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_DOWN)SS_TAP(X_ENTER));
      }
      *result = false;
      return true;
  }

  return false;
}


enum {
  TD_COLON = 0,
  TD_QUOTE = 1,
  TD_ESC = 2,
  TD_AESC = 3,
  TD_LAYER = 4
};



void dance_quote_finished (qk_tap_dance_state_t *state, void *user_data);
void dance_quote_reset (qk_tap_dance_state_t *state, void *user_data);
void dance_layer_finished (qk_tap_dance_state_t *state, void *user_data);
void dance_layer_reset (qk_tap_dance_state_t *state, void *user_data);

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_COLON]  = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, RSFT(KC_SCLN)),
  [TD_QUOTE]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_quote_finished, dance_quote_reset),
  // [TD_QUOTE]  = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, RSFT(KC_QUOT))
  [TD_AESC]  = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_ESC),
  [TD_LAYER]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_layer_finished, dance_layer_reset),
};


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

void dance_layer_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_BRK);
  } else {
    layer_on(LR7);
    set_oneshot_layer(LR7, ONESHOT_START);
    clear_oneshot_layer_state(ONESHOT_PRESSED);
  }
}

void dance_layer_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_BRK);
  } else {
    // unregister_code (KC_RSFT);
    // unregister_code (KC_QUOT);
  }
}

// Tap Dance
#define TD_QUOT TD(TD_QUOTE)
#define TD_LYR  TD(TD_LAYER)


#endif
