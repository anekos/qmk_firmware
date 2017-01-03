
#ifndef ANEKOS_H
#define ANEKOS_H


/**
 * Shift-and-Space は、「<Space><Space>おしっぱなし」とすることでキーリピートを発生させることができる。
 */

// XandY
#define A_ESC   ALT_T(KC_ESC)
#define C_COLN  CTL_T(KC_SCLN)
#define S_SPC   SFT_T(KC_SPC)

// Layer
#define LO_ESC  LT(_LOWER, KC_ESC)
#define RA_ENT  LT(_RAISE, KC_ENT)
#define EX_ESC  LT(_EXT, KC_ESC)


// Alias
#define KC_LT   LSFT(KC_COMM)
#define KC_GT   LSFT(KC_DOT)

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


// Layers
#define LR0 0
#define LR1 1
#define LR2 2
#define LR3 3
#define LR4 4
#define LR7 7





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
