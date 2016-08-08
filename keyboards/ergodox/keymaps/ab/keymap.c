#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define THK  1 // THK layer
#define FN1  2 // media layer

#define CAPS_CTL CTL_T(KC_CAPS)  // Caps on tap, Ctrl on hold.
#define COPY     LCTL(KC_V)      // C-c Copy
#define PASTE    LCTL(KC_V)      // C-v Paste
#define ZM_NRM   LCTL(KC_0)      // C-0 Zoom Normal
#define ZM_OUT   LCTL(KC_MINS)   // C-- Zoom Out
#define ZM_IN    LCTL(KC_PLUS)   // C-+ Zoom In
#define EM_UNDO  LCTL(KC_UNDS)   // C-_ Emacs Undo

#define _MOB  1 // Mobile#
#define _CUS1 2 // Custom macro 1
#define _CUS2 3 // Custom macro 2


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |  6   |           |   7  |   8  |   9  |   0  |   -  |   =  | BSpace |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  Up  |           |Right |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Ctrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------|  Dn  |           | Left |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   '    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Esc  |CpsCtl| LGui | LGui | LAlt |                                       | RGui |  [   |   ]  | RAlt |  FN1 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        | Esc  |      |       | RESET |      |
 *                                 ,------|------+------|       |-------+------+------.
 *                                 |      |      |      |       |       |      |      |
 *                                 |Space | Del  |------|       |-------|BSpace|Space |
 *                                 |      |      | FN1  |       |       |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
    [BASE] = KEYMAP(  // layer 0 : default
	// Left hand
	KC_GRV,   KC_1,    KC_2,    KC_3,     KC_4,     KC_5,    KC_6,
	KC_TAB,   KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,    KC_UP,
	KC_LCTL,  KC_A,    KC_S,    KC_D,     KC_F,     KC_G,
	KC_LSFT,  KC_Z,    KC_X,    KC_C,     KC_V,     KC_B,    KC_DOWN,
	KC_ESC,   CAPS_CTL,KC_LGUI, KC_LGUI,  KC_LALT,
	KC_ESC,   KC_NO,
	KC_NO,
	KC_SPC,   KC_DEL,  TG(FN1),
	// Right hand
	KC_7,     KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,
	KC_RIGHT,  KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,    KC_BSLS,
	KC_H,     KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_ENT,
	KC_LEFT,  KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, KC_QUOT,
	KC_RGUI,  KC_LBRC, KC_RBRC, KC_RALT, TG(FN1),
	RESET,    KC_NO,
	KC_NO,
	KC_NO,  KC_BSPC,  KC_SPC
    ),
/* Keymap 3: THK layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |  6   |           |   7  |   8  |   9  |   0  |   -  |   =  | BSpace |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  Up  |           |Right |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Ctrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------|  Dn  |           | Left |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   '    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Esc  |CpsCtl| LGui | LGui | RAlt |                                       | PrSc |  [   |   ]  | RAlt |  FN1 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        | Esc  |      |       | RESET |      |
 *                                 ,------|------+------|       |-------+------+------.
 *                                 |      |      |      |       |       |      |      |
 *                                 |Space | Del  |------|       |-------|BSpace|Space |
 *                                 |      |      | FN1  |       |       |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
    [THK] = KEYMAP(  // layer 0 : default
	// Left hand
	KC_GRV,   KC_1,    KC_2,    KC_3,     KC_4,     KC_5,    KC_6,
	KC_TAB,   KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,    KC_UP,
	KC_LCTL,  KC_A,    KC_S,    KC_D,     KC_F,     KC_G,
	KC_LSFT,  KC_Z,    KC_X,    KC_C,     KC_V,     KC_B,    KC_DOWN,
	KC_ESC,   CAPS_CTL,KC_LGUI, KC_LGUI,  KC_RALT,
	KC_ESC,   KC_NO,
	KC_NO,
	KC_SPC,   KC_DEL,  TG(FN1),
	// Right hand
	KC_7,     KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,
	KC_RIGHT,  KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,    KC_BSLS,
	KC_H,     KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_ENT,
	KC_LEFT,  KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, KC_QUOT,
	KC_PSCR,  KC_LBRC, KC_RBRC, KC_RALT, TG(FN1),
	RESET,    KC_NO,
	KC_NO,
	KC_NO,  KC_BSPC,  KC_SPC
    ),
/* Keymap 2: Fn Keys, media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | BSpace |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | LClk | MClk | RClk |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Teensy|      |      |      |      |                                       | Undo |VolDn |VolUp | Mute |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------+------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | LClk | RClk |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// FN1 Layer
    [FN1] = KEYMAP(
	// Left hand
	KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN3, KC_BTN2, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS,
	KC_TRNS,
	KC_BTN1, KC_BTN2, KC_TRNS,
	// Right hand
	KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_MPLY,
	KC_TRNS, M(_MOB), KC_TRNS, M(_CUS1),M(_CUS2),KC_TRNS, KC_TRNS,
	EM_UNDO, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS,
	KC_TRNS, KC_TRNS,
	KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS
	),
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch(id) {
    case _MOB: // Your mobile# here.
	return MACRODOWN(T(1), T(2), T(3), T(MINS),
			 T(1), T(2), T(3), T(MINS),
			 T(1), T(2), T(3), T(4),
			 END);
    case _CUS1: // Your custom macro 1
	return MACRODOWN(T(E), T(M), T(A), T(C), T(S), T(SPC), END);
    case _CUS2: // Your custom macro 2
	return MACRODOWN(T(L), T(S), T(SPC), T(MINS), T(L), T(ENT), END);
    };
    return MACRO_NONE;
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
	ergodox_right_led_1_on();
	break;
    case 2:
	ergodox_right_led_2_on();
	break;
    case 3:
	ergodox_right_led_3_on();
	break;
    default:
	// none
	break;
    }

};
