enum combos {
  SHFT_CAPS
};

const uint16_t PROGMEM caps_combo[] = {KC_LSFT, KC_RSFT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [SHFT_CAPS] = COMBO(caps_combo, KC_CAPS)
};
