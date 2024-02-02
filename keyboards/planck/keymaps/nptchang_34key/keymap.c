#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layers

#define LAYER_Base 0
#define LAYER_R_NUM_SYMB 1
#define LAYER_L_NUM 2
#define LAYER_L_FUNC 3
#define LAYER_L_SPC 4
#define LAYER_L_NAVI 5
#define LAYER_L_Q 6
#define LAYER_L_Z 7
#define LAYER_L_Z_SPC 8
#define LAYER_Magic 9

// LAYER_Base Hold_Taps

#define LT_Q LT(LAYER_L_Q, KC_Q)
#define MT_A LGUI_T(KC_A)
#define MT_S LALT_T(KC_S)
#define MT_D LCTL_T(KC_D)
#define MT_F LSFT_T(KC_F)
#define MT_J RSFT_T(KC_J)
#define MT_K RCTL_T(KC_K)
#define MT_L RALT_T(KC_L)
#define MT_SCLN RGUI_T(KC_SCLN)
#define LT_Z LT(LAYER_L_Z, KC_Z)
#define LT_TAB LT(LAYER_L_NUM, KC_TAB)
#define LT_SPC LT(LAYER_L_SPC, KC_SPC)
#define LT_ENT LT(LAYER_R_NUM_SYMB, KC_ENT)

// LAYER_Base Hold_Taps

// 其它

#define _delay_ms wait_ms

#include "_tap_dance.c"
#include "_leader_key.c"
#include "_macro.c"
#include "_combo.c"
#include "_music_mode.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASEWIN] = LAYOUT_planck_grid(
        LT_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        MT_A,    MT_S,    MT_D,    MT_F,    KC_G,    _______, _______, KC_H,    MT_J,    MT_K,    MT_L,    MT_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
        _______, _______, _______, LT_TAB,  LT_SPC,  _______, _______, LT_ENT, KC_BSPC,  _______, _______, _______, 
        ),

    [LAYER_R_NUM_SYMB] = LAYOUT_planck_grid(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_GRV,  KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  _______, _______, KC_BSLS, KC_QUOT, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        ),

    [LAYER_L_NUM] = LAYOUT_planck_grid(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        ),


    [空白] = LAYOUT_planck_grid(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        ),















	[_BASEWIN] = LAYOUT_planck_grid(
        KC_Q, KC_W, KC_E, KC_R, KC_T, _______, _______, KC_Y, KC_U, KC_I, KC_O, KC_P,
        KC_A, KC_S, KC_D, KC_F, KC_G, _______, _______, KC_H, KC_J, KC_K, KC_L, KC_SCLN,
        KC_Z, KC_X, KC_C, KC_V, KC_B, _______, _______, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
        KC_LCTL, MO(_FUNC), /*TD(LGUI)*/GUI_T(KC_BSPC), TD(LALT), LT(_LT_SPC_WIN,KC_SPC), LT(_LT_SPC_WIN,KC_SPC), MO(_NUM), MO(_NUM), MO(_MOUSE_WIN), KC_WH_D, KC_WH_U, TG(_FUNC)
        ),

	[_BASEMAC] = LAYOUT_planck_grid(
        LT(_SYS,KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        LT(_ESC_MAC, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        TD(LCTL_MAC), MO(_FUNC), /*TD(OPT)*/ALT_T(KC_BSPC), TD(CMD), LT(_LT_SPC_MAC,KC_SPC), LT(_LT_SPC_MAC,KC_SPC), MO(_NUM), MO(_NUM), MO(_MOUSE_MAC), KC_WH_U, KC_WH_D, TG(_FUNC)
        ),

	[_NUM] = LAYOUT_planck_grid( 
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______,
        _______, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_BSLS, KC_QUOT, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        ),

    [_LT_SPC_WIN] = LAYOUT_planck_grid(
        _______, KC_HOME, _______, KC_END, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, C(KC_LEFT), KC_UP, C(KC_RIGHT), _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        ), 

    [_LT_SPC_MAC] = LAYOUT_planck_grid(
        _______, G(KC_LEFT), _______, G(KC_RIGHT), _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, A(KC_LEFT), KC_UP, A(KC_RIGHT), _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        ), 

	[_FUNC] = LAYOUT_planck_grid( 
        KC_TAB, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______, _______, KC_P7, KC_P8, KC_P9, _______,
        KC_DOT, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_P4, KC_P5, KC_P6, KC_PENT,
        DM_PLY1, DM_REC1, DM_RSTP, _______, _______, _______, _______, _______, KC_P1, KC_P2, KC_P3, KC_PENT,
        _______, _______, _______, _______,   _______,    _______,    _______,    _______,         KC_P0, _______, KC_PDOT, _______
        ),

	[_ESC_WIN] = LAYOUT_planck_grid( 
        MO(_MOUSE_WIN), HYPR(KC_F1), HYPR(KC_F2), HYPR(KC_F3), HYPR(KC_F4), HYPR(KC_F5), KC_HOME, C(KC_LEFT), C(KC_RIGHT), KC_END, _______, KC_DELETE,
        _______, LCTL(LGUI(KC_LEFT)), LGUI(KC_TAB), LCTL(LGUI(KC_RIGHT)), KC_F11, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, KC_WH_D, KC_WH_U, _______, _______, _______, 
        _______, _______, KC_LGUI, MO(_TABS_WIN), HYPR(KC_ENT), HYPR(KC_ENT), _______, _______, _______, _______, _______, _______
        ), 

	[_ESC_MAC] = LAYOUT_planck_grid( 
        MO(_MOUSE_MAC), MEH(KC_1), MEH(KC_2), KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, _______, G(KC_LEFT), A(KC_LEFT), A(KC_RIGHT), G(KC_RIGHT), _______, _______,
        _______, MEH(KC_F1), MEH(KC_F2), MEH(KC_F3), _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_WH_U, KC_WH_D, _______, _______, _______, 
        _______, _______, _______, MO(_TABS_MAC), HYPR(KC_ENT), HYPR(KC_ENT), _______, _______, _______, _______, _______, _______
        ),

    [_MOUSE_WIN] = LAYOUT_planck_grid(
        _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, KC_WH_D, KC_WH_U, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, KC_ACL0, KC_ACL0, _______, _______, _______, _______ 
        ),

    [_MOUSE_MAC] = LAYOUT_planck_grid(
        _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, KC_WH_U, KC_WH_D, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, KC_ACL0, KC_ACL0, _______, _______, _______, _______ 
        ),

    [_TABS_WIN] = LAYOUT_planck_grid( 
        _______, A(KC_LEFT), C(S(KC_TAB)), C(KC_TAB), A(KC_RIGHT), C(KC_T), HYPR(KC_Y), HYPR(KC_U), HYPR(KC_I), HYPR(KC_O), HYPR(KC_P), HYPR(KC_BSPC), 
        _______, HYPR(KC_A), C(KC_W), HYPR(KC_D), HYPR(KC_F), HYPR(KC_G), HYPR(KC_H), HYPR(KC_J), HYPR(KC_K), HYPR(KC_L), HYPR(KC_SCLN), HYPR(KC_ENT), 
        _______, HYPR(KC_Z), HYPR(KC_X), HYPR(KC_C), HYPR(KC_V), HYPR(KC_B), HYPR(KC_N), HYPR(KC_M), HYPR(KC_COMM), HYPR(KC_DOT), HYPR(KC_SLSH), HYPR(KC_RSFT),
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        ), 

    [_TABS_MAC] = LAYOUT_planck_grid(
        _______, G(KC_LBRC), C(S(KC_TAB)), C(KC_TAB), G(KC_RBRC), G(KC_T), _______, _______, _______, _______, _______, _______, 
        _______, _______, G(KC_W), MEH(KC_F6), _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, MEH(KC_F4), MEH(KC_F5), MEH(KC_F7), _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        ), 

	[_SYS] = LAYOUT_planck_grid(
        _______, HYPR(KC_F6), HYPR(KC_F7), HYPR(KC_F8), HYPR(KC_F9), HYPR(KC_F10), _______, _______, _______, _______, _______, QK_BOOT,
        MU_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_MAKE,
        MU_NEXT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, DF(_BASEWIN), DF(_BASEMAC), _______, _______, _______, _______, _______, _______, _______, _______
        )
};


