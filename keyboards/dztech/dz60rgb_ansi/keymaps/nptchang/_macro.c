
// My keycode
enum my_keycodes {
  DYNAMIC_MACRO_RANGE = SAFE_RANGE,
};

#include "dynamic_macro.h"

#define DY_REC1 DYN_REC_START1
#define DY_PLA1 DYN_MACRO_PLAY1
#define DY_REC2 DYN_REC_START2
#define DY_PLA2 DYN_MACRO_PLAY2
#define DY_STOP DYN_REC_STOP

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record))
    return false;
  return true;
}
