
bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case LT(_SYS,KC_TAB):
      return false;
    default:
      return true;
  }
}

/* const uint8_t music_map[MATRIX_ROWS][MATRIX_COLS] = LAYOUT_planck_grid( */
/*     36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, */
/*     24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, */
/*     12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, */
/*      0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11 */
/* ); */


