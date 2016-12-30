
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



#endif
