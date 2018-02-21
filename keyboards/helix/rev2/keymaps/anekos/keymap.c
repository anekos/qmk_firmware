#include "helix.h"
#include "bootloader.h"
#include "action_layer.h"
#include "eeconfig.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#include "LUFA/Drivers/Peripheral/TWI.h"
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif
#include "anekos.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

enum custom_keycodes {
  __LR0 = SAFE_RANGE,
  __LR1,
  __LR2,
  __LR3,
  __LR4,
  __LR5,
  __LR6,
  __LR7,
  RCNT,  // Reset counter
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
//Macros
#define M_SAMPLE M(KC_SAMPLEMACRO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.             ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |  \   |
 * |------+------+------+------+------+------+             |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  `   |
 * |------+------+------+------+------+-------             |------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |      |      |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |ESC/Lo|      | LR4  |   -  | Alt  | Spc  |      |      | Spc  |  Alt |   -  |      |      |Ent/Ra|
 * `-------------------------------------------------------------------------------------------------'
 */
[LR0] = KEYMAP( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,  \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                    KC_H,    KC_J,    KC_K,    KC_L,    C_COLN,  KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  TO(LR6), TO(LR7), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  L1_ESC,  MO_4,    A_ESC,   A_ESC,   A_ESC,   S_SPC, _______, _______, S_SPC,   A_ESC,   A_ESC,   A_ESC,   _______, L2_ENT   \
),

/* Layer 1 - Parens
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |      |      |      |      |      |             |      |      |   {  |   }  |      | Bksp |
 * |------+------+------+------+------+------+             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |   [  |   ]  |      | Del  |
 * |------+------+------+------+------+-------             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |   -  |   _  |   (  |   )  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   +  |   =  |   <  |   >  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-------------------------------------------------------------------------------------------------'
 */
[LR1] = KEYMAP( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, KC_LCBR, KC_RCBR, _______, KC_BSPC, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, KC_LBRC, KC_RBRC, _______, KC_DEL , \
  _______, _______, _______, _______, _______, _______,                   KC_MINS, KC_UNDS, KC_LPRN, KC_RPRN, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_PLUS, KC_EQL,  KC_LT,   KC_GT,   _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Layer 2 - Mouse and Arrows
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |      |      |      |      |      |             |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+------+             |------+------+------+------+------+------|
 * |      | ↑↑ |  ↑  | ↓↓ |      |      |             |      |      |      |      |      | Del  |
 * |------+------+------+------+------+-------             |------+------+------+------+------+------|
 * |      |  ←  |  ↓  |  →  |      |      |             |  ←  |  ↓  |  ↑  |  →  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | MUSIC|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | LBtn | CBtn | RBtn |      |      |      |
 * `-------------------------------------------------------------------------------------------------'
 */
[LR2] = KEYMAP( \
  _______, CON1,    CON2,    CON3,    CON4,    CON5,                      CON6,    CON7,    CON8,    CON9,    CON10,   KC_BSPC, \
  _______, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______,                   _______, _______, _______, _______, _______, KC_DEL , \
  _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, MU_TOG,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, KC_BTN3, _______, _______, _______  \
),

/* Layer 4 - Unholy keys
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |      |      |      |      |      |             |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+------+             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |      | Del  |
 * |------+------+------+------+------+-------             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |  ←  |  ↓  |  ↑  |  →  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-------------------------------------------------------------------------------------------------'
 */
[LR4] = KEYMAP( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_BSPC, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_DEL , \
  _______, _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Layer 6 - Lossless cut
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |      |      |      |      |      |             |      | Slow | Fast |      |      |      |
 * |------+------+------+------+------+------+             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |Export|  <   |  >   |      |      |      |
 * |------+------+------+------+------+-------             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             | In   | <<   |  >>  | Out  |      |Export|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |Pause |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-------------------------------------------------------------------------------------------------'
 */
[LR6] = KEYMAP( \
  _______, _______, _______, _______, _______, _______,                   _______, KC_J,    KC_L,    _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   KC_E,    KC_DOT,  KC_COMM, KC_E,    _______, _______, \
  _______, _______, _______, _______, _______, _______,                   KC_I,    KC_LEFT, KC_RGHT, KC_O,    _______, KC_E,    \
  _______, _______, _______, _______, _______, _______, TO(LR0), TO(LR0), _______, KC_SPC,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SPC,  _______, _______, _______, _______  \
),

/* Layer 7 - Helix keys
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |      |      |      |      |RCNT  |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------+             |------+------+------+------+------+------|
 * |      |      |      |      |RESET |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+-------             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |RGB_ON|MODE+ | HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |MODE- | HUE- | SAT- | VAL- |
 * `-------------------------------------------------------------------------------------------------'
 */
[LR7] = KEYMAP( \
  _______, _______, _______, _______, _______, RCNT,                      _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, RESET,   _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, TO(LR0), TO(LR0), _______, RGB_TOG, RGB_SMOD,RGB_HUI, RGB_SAI, RGB_VAI, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD  \
),

};


// define variables for reactive RGB {{{

static uint16_t counter[255] = {0};
static uint16_t score = 0;
static uint8_t highest = 0;
#define COUNT_LO 4
#define COUNT_HI 29

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    score++;
    if (COUNT_LO <= keycode && keycode <= COUNT_HI) {
      uint8_t c = (uint8_t)keycode;
      counter[c]++;
      if (counter[highest] < counter[c])
        highest = c;
    } else if (keycode == RCNT) {
      memset(counter, 0, sizeof counter);
      highest = 0;
    }
  }
  return true;
}

void matrix_init_user(void) {
  rgblight_enable();
  rgblight_mode(5);
  default_layer_set(1UL << LR0);
  layer_move(LR0);
#ifdef SSD1306OLED
  //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
  TWI_Init(TWI_BIT_PRESCALE_1, TWI_BITLENGTH_FROM_FREQ(1, 800000));
  iota_gfx_init(!has_usb());   // turns on the display
#endif
}

// }}}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h {{{
#ifdef SSD1306OLED

void matrix_scan_user(void) {
  iota_gfx_task();  // this is what updates the display continuously
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

//assign the right code to your layers for OLED display
static void render_logo(struct CharacterMatrix *matrix) {
  static char logo[]={
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
    0};
  matrix_write(matrix, logo);
  //matrix_write_P(&matrix, PSTR(" Split keyboard kit"));
}



void render_status(struct CharacterMatrix *matrix) {
  // Render to mode icon
  static char logo[][2][3] = {
    { {0x95, 0x96, 0}, {0xb5, 0xb6, 0} },
    { {0x97, 0x98, 0}, {0xb7, 0xb8, 0} }
  };

  if(keymap_config.swap_lalt_lgui==false){
    matrix_write(matrix, logo[0][0]);
    matrix_write_P(matrix, PSTR("\n"));
    matrix_write(matrix, logo[0][1]);
  }else{
    matrix_write(matrix, logo[1][0]);
    matrix_write_P(matrix, PSTR("\n"));
    matrix_write(matrix, logo[1][1]);
  }

  char highest_char = highest ? 'a' + highest - COUNT_LO : '?';

  char buf[40];
  snprintf(
      buf,
      sizeof(buf),
      "  [%c%c%c%c%c%c%c%c] R%d\nscore: %d  (%c=%d)",
      IS_LAYER_ON(LR0) ? '0' : '-',
      IS_LAYER_ON(LR1) ? '1' : '-',
      IS_LAYER_ON(LR2) ? '2' : '-',
      IS_LAYER_ON(LR3) ? '3' : '-',
      IS_LAYER_ON(LR4) ? '4' : '-',
      IS_LAYER_ON(LR5) ? '5' : '-',
      IS_LAYER_ON(LR6) ? '6' : '-',
      IS_LAYER_ON(LR7) ? '7' : '-',
      rgblight_config.enable ? rgblight_config.mode : 0,
      score,
      highest_char,
      counter[highest]),
  matrix_write(matrix, buf);
}


void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;

#if DEBUG_TO_SCREEN
  if (debug_enable) {
    return;
  }
#endif

  matrix_clear(&matrix);
  if(is_master){
    render_status(&matrix);
  }else{
    render_logo(&matrix);
  }
  matrix_update(&display, &matrix);
}

#endif
// }}}
