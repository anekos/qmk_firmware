
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
