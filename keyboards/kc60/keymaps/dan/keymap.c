/*
Copyright 2017 Daniel Khodabakhsh <d.khodabakhsh@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "kc60.h"

#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum layers {
	LAYER_MAIN,
	LAYER_FUNC
};

#define MO_MAIN MO(LAYER_MAIN)
#define MO_FUNC MO(LAYER_FUNC)

enum macros {
	MACRO_LOCK_OS
};

#define M_OSLCK M(0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Main layer
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
│GRAVE│  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │   BKSPC   │
├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
│  TAB   │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │   \    │
├────────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴────────┤
│  CAPSL   │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │   ENTER    │
├──────────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴────────────┤
│   LSHFT    │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │     RSHFT      │
├──────┬─────┴┬────┴─┬───┴─────┴─────┴─────┴─────┴─────┴─────┴┬────┴─┬───┴──┬──────┬──────┤
│LCTRL │L_GUI │L_ALT │               SPC                      │R_ALT │ FN0  │ APP  │RCTRL │
└──────┴──────┴──────┴────────────────────────────────────────┴──────┴──────┴──────┴──────┘*/
	[LAYER_MAIN] = KEYMAP(
KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,\
KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,\
KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, KC_ENT,\
KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, MO_FUNC,\
KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             XXXXXXX, KC_APP,  MO_FUNC, MO_FUNC, MO_FUNC),

/* Function layer
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────────┐
│ ESC │  F1 │  F2 │  F3 │  F4 │  F5 │  F6 │  F7 │  F8 │  F9 │ F10 │ F11 │ F12 │    DEL    │
├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┤
│        │HOME │ UP  │ END │PGUP │     │     │     │ INS │     │PRTSC│SCLCK│PAUSE│        │
├────────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴────────┤
│          │LEFT │DOWN │RIGHT│PGDN │     │     │     │     │LockO│     │     │            │
├──────────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴────────────┤
│            │     │     │     │     │     │     │Mute │VolDn│VolUp│     │                │
├──────┬─────┴┬────┴─┬───┴─────┴─────┴─────┴─────┴─────┴─────┴┬────┴─┬───┴──┬──────┬──────┤
│      │      │      │                                        │      │      │      │      │
└──────┴──────┴──────┴────────────────────────────────────────┴──────┴──────┴──────┴──────┘*/
	[LAYER_FUNC] = KEYMAP(
KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,\
_______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, _______, _______, KC_INS,  _______, KC_PSCR, KC_SLCK, KC_PAUS, _______,\
_______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, _______, _______, _______, M_OSLCK, _______, _______, XXXXXXX, _______,\
_______, XXXXXXX, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, XXXXXXX, _______,\
_______, _______, _______,                   _______,                            XXXXXXX, _______, _______, _______, _______)
};

//const uint16_t PROGMEM fn_actions[] = {};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	if (record->event.pressed) {
		switch(id) {
			case 0:
				return MACRO(D(LSFT), T(H), U(LSFT), T(I), D(LSFT), T(1), U(LSFT), END);
				//return MACRO(D(LGUI), T(L), U(LGUI), END);
		}
	}
	// MACRODOWN only works in this function
	return MACRO_NONE;
};
