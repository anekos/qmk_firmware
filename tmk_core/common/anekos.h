#ifndef ANEKOS_H
#define ANEKOS_H

#include "process_tap_dance.h"

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


#define ACTION_RENDANCE(kc1, kc2) { \
    .fn = { NULL, rendance_pair_finished, rendance_pair_reset } \
  }

void rendance_pair_finished (qk_tap_dance_state_t *state, void *user_data);
void rendance_pair_reset (qk_tap_dance_state_t *state, void *user_data);

#endif
