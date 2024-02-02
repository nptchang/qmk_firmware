#pragma once

// overrides go here!
#ifndef MY_SETTING
#define MY_SETTING

#define dzrgb60_ansi


/* #if BACKLIGHT_ENABLE */
/*     #include "backlight.h" */
/*     #define BACKLIGHT_PIN B2 */
/*     #define BACKLIGHT_LEVELS 7 */
/*     #define BACKLIGHT_ON_STATE 1 */
/* #endif */

// USE Consuption
#define USB_MAX_POWER_CONSUMPTION 100

// Tap & Hold
/* #define PERMISSIVE_HOLD */
/* #define IGNORE_MOD_TAP_INTERRUPT */
#define TAPPING_TERM 200

// Prevent stuck modifiers
/* #define PREVENT_STUCK_MODIFIERS */

// Leader Key
#define LEADER_TIMEOUT 300
#define LEADER_PER_KEY_TIMING

// Combo
#define COMBO_COUNT 1

// Mouse
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 4
#define MOUSEKEY_TIME_TO_MAX 20
#define MOUSEKEY_WHEEL_MAX_SPEED 1
#define MOUSEKEY_WHEEL_TIME_TO_MAX 250

/* #define MK_3_SPEED */
/* #define MK_MOMENTARY_ACCEL */
/* #define MK_C_OFFSET_0 16 */
/* #define MK_C_INTERVAL_0 16 */
/* #define MK_C_OFFSET_1 32 */
/* #define MK_C_INTERVAL_1 16 */
/* #define MK_C_OFFSET_2 64 */
/* #define MK_C_INTERVAL_2 16 */

#endif
