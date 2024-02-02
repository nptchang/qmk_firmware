#include QMK_KEYBOARD_H

/* extern keymap_config_t keymap_config; */

// Layers

#define _BASEWIN        0
#define _BASEMAC        1
#define _BASE           2
#define _NUM            3
#define _LT_SPC_MAC     4
#define _LT_SPC_WIN     5
#define _FUNC           6
#define _ESC_MAC        7
#define _ESC_WIN        8
#define _MOUSE_MAC      9
#define _MOUSE_WIN      10
#define _NUMPAD         11
#define _TABS_MAC       12
#define _TABS_WIN       13  
#define _SYS            14

/* #include "~/Dropbox/qmk_firmware/keyboards/thevankeyboards/minivan/keymaps/nptchang/_tap_dance.c" */
/* #include "~/Dropbox/qmk_firmware/keyboards/thevankeyboards/minivan/keymaps/nptchang/_leader_key.c" */
/* #include "~/Dropbox/qmk_firmware/keyboards/thevankeyboards/minivan/keymaps/nptchang/_macro.c" */
/* #include "~/Dropbox/qmk_firmware/keyboards/thevankeyboards/minivan/keymaps/nptchang/_combo.c" */

#include "_tap_dance.c"
#include "_leader_key.c"
#include "_macro.c"
#include "_combo.c"

/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASEWIN] = LAYOUT_truefox(
        KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_GRV, KC_BSLS, KC_HOME,
        LT(_SYS,KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC, KC_PGUP,
        LT(_ESC_WIN,KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGDN,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_END, 
        KC_LCTL, GUI_T(KC_BSPC), TD(LALT), LT(_LT_SPC_WIN,KC_SPC), MO(_MOUSE_WIN), MO(_FUNC),  KC_LEFT, KC_DOWN, KC_RGHT
        ),

    [_BASEMAC] = LAYOUT_truefox(
        KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_GRV, KC_BSLS, KC_HOME,
        LT(_SYS,KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC, KC_PGUP,
        LT(_ESC_MAC,KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGDN,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_END, 
        TD(LCTL_MAC), ALT_T(KC_BSPC), TD(CMD), LT(_LT_SPC_MAC,KC_SPC), MO(_MOUSE_MAC), MO(_FUNC),  KC_LEFT, KC_DOWN, KC_RGHT
        ),

	[_BASE] = LAYOUT_truefox(
        KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_GRV, KC_BSLS, KC_HOME,
        LT(_SYS,KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC, KC_PGUP,
        LT(_ESC_WIN,KC_CAPS), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGDN,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_END,
        KC_LCTL, KC_LGUI, KC_LALT, LT(_LT_SPC_WIN,KC_SPC), MO(_MOUSE_WIN), MO(_FUNC), KC_LEFT, KC_DOWN, KC_RGHT
        ),

	[_NUM] = LAYOUT_truefox( 
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, 
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, _______, _______,  _______, 
        _______, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, _______, _______, _______,  _______, 
        _______, _______, _______, _______, _______, _______, KC_BSLS, KC_QUOT, _______, _______, _______, _______,   _______,  _______, 
        _______, _______, _______, _______, _______, _______, _______, _______,  _______ 
        ),

    [_LT_SPC_MAC] = LAYOUT_truefox(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,  _______, 
        _______, G(KC_LEFT), _______, G(KC_RIGHT), _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, 
        _______, A(KC_LEFT), KC_UP, A(KC_RIGHT), _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, 
        _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, _______, _______, _______, _______,    _______,  _______, 
        _______, _______, _______, _______, _______, _______, _______,  _______,  _______ 
        ), 

    [_LT_SPC_WIN] = LAYOUT_truefox(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, 
        _______, KC_HOME, _______, KC_END, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, 
        _______, C(KC_LEFT), KC_UP, C(KC_RIGHT), _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, 
        _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, _______, _______, _______, _______,   _______,  _______, 
        _______, _______, _______, _______, _______, _______, _______,  _______,  _______
        ), 

	[_FUNC] = LAYOUT_truefox( 
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,  _______,  _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PAUSE,  _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PENT,   _______, 
        DM_PLY1, DM_REC1, DM_RSTP, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,  _______, 
        _______, _______, _______, _______,   _______,         _______,    _______,      _______,  _______
        ),

	[_ESC_MAC] = LAYOUT_truefox( 
        MO(_NUMPAD), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______,   _______,  _______, 
        MO(_MOUSE_MAC), _______, _______, _______, _______, _______, G(KC_LEFT), A(KC_LEFT), A(KC_RIGHT), G(KC_RIGHT), _______, _______, _______,  _______, _______, 
        _______, MEH(KC_F1), MEH(KC_F2), MEH(KC_F3), _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,  _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, KC_WH_U, KC_WH_D, _______, _______, _______,  _______,  _______, 
        _______, _______, MO(_TABS_MAC), HYPR(KC_ENT), _______, _______, _______,  _______,  _______ 
        ), 

	[_ESC_WIN] = LAYOUT_truefox( 
        MO(_NUMPAD), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______,   _______,  _______, 
        MO(_MOUSE_WIN), _______, _______, _______, _______, _______, KC_HOME, C(KC_LEFT), C(KC_RIGHT), KC_END,  _______, _______, _______, KC_DELETE, _______, 
        _______, LCTL(LGUI(KC_LEFT)), LGUI(KC_TAB), LCTL(LGUI(KC_RIGHT)), KC_F11, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______,  _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, KC_WH_D, KC_WH_U, _______, _______,  _______, _______,  _______, 
        _______, KC_LGUI, MO(_TABS_WIN), HYPR(KC_ENT), _______, _______, _______,  _______,  _______ 
        ),

    [_MOUSE_MAC] = LAYOUT_truefox(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,  _______, 
        _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______,  _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,  _______,  _______, 
        _______, _______, _______, _______, _______, _______, _______, KC_WH_U, KC_WH_D, _______, _______,   _______,  _______,  _______, 
        _______, _______, _______, KC_ACL0, _______, _______,  _______, _______,  _______
        ),

    [_MOUSE_WIN] = LAYOUT_truefox(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______,     _______, _______,
        _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,  _______,  _______,
        _______, _______, _______, _______, _______, _______, _______, KC_WH_D, KC_WH_U, _______, _______,   _______,  _______, _______,
        _______, _______, _______, KC_ACL0, _______, _______, _______,  _______ ,  _______
        ),

    [_NUMPAD] = LAYOUT_truefox(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, _______, _______,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, _______, _______,  _______,  _______,
        _______, _______, _______, _______, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, _______,   _______,  _______, _______,
        _______, _______, _______, KC_KP_0, KC_PDOT, _______,  _______, _______ ,  _______
        ),

    [_TABS_MAC] = LAYOUT_truefox(
        _______, G(KC_LBRC), C(S(KC_TAB)), C(KC_TAB), G(KC_RBRC), _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______,
        _______, _______, G(KC_W), _______, _______, G(KC_T), _______, _______, _______, _______, _______, _______, _______,  _______,  _______,
        _______, _______, G(KC_W), MEH(KC_F6), _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,
        _______, MEH(KC_F4), MEH(KC_F5), MEH(KC_F7), _______, _______, _______, _______, _______, _______, _______,   _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______,  _______,  _______
        ), 

    [_TABS_WIN] = LAYOUT_truefox( 
        _______, A(KC_LEFT), C(S(KC_TAB)), C(KC_TAB), A(KC_RIGHT), HYPR(KC_5), HYPR(KC_6), HYPR(KC_7), HYPR(KC_8), HYPR(KC_9), HYPR(KC_0), HYPR(KC_MINS), HYPR(KC_EQL), HYPR(KC_GRV), HYPR(KC_BSLS), _______,
        _______, HYPR(KC_Q), C(KC_W), HYPR(KC_E), HYPR(KC_R), HYPR(KC_T), HYPR(KC_Y), HYPR(KC_U), HYPR(KC_I), HYPR(KC_O), HYPR(KC_P), HYPR(KC_LBRC), HYPR(KC_RBRC), HYPR(KC_BSPC), _______,
        _______, HYPR(KC_A), C(KC_W), HYPR(KC_D), HYPR(KC_F), HYPR(KC_G), HYPR(KC_H), HYPR(KC_J), HYPR(KC_K), HYPR(KC_L), HYPR(KC_SCLN), HYPR(KC_QUOT), HYPR(KC_ENT), _______,
        _______, HYPR(KC_Z), HYPR(KC_X), HYPR(KC_C), HYPR(KC_V), HYPR(KC_B), HYPR(KC_N), HYPR(KC_M), HYPR(KC_COMM), HYPR(KC_DOT), HYPR(KC_SLSH), HYPR(KC_RSFT), _______, _______,
        _______, _______, _______, _______, _______, _______, _______,  _______, _______
        ), 

	[_SYS] = LAYOUT_truefox(
        _______, HYPR(KC_F1), HYPR(KC_F2), HYPR(KC_F3), HYPR(KC_F4), HYPR(KC_F5), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, HYPR(KC_F6), HYPR(KC_F7), HYPR(KC_F8), HYPR(KC_F9), HYPR(KC_F10), _______, _______, _______, _______, _______, _______, _______, QK_BOOT,   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_MAKE,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______,
        DF(_BASE), DF(_BASEWIN), DF(_BASEMAC), _______, _______, _______, _______,  _______,  _______
        )
};


