
// Tap Dance Declarations

typedef struct {
  bool is_press_action;
  int state;
} tap;

bool caps_is_on = false;
#define DEBOUNCE_CAPS_DELAY 100


// ------- //
// Structs //
// ------- //

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  TRIPLE_TAP = 5,
  TRIPLE_HOLD = 6
};

enum {
  LALT = 0,  CMD,
  LGUI,      OPT,
  LCTL_MAC,
  /* LSFT, */
  /* ESC_WIN,  ESC_MAC, */
  /* NUM_LEAD */
};

int cur_dance (tap_dance_state_t *state);




//for the x tap dance. Put it here so it can be used in any keymap
void altwin_finished (tap_dance_state_t *state, void *user_data);
void altwin_reset (tap_dance_state_t *state, void *user_data);
void cmdmac_finished (tap_dance_state_t *state, void *user_data);
void cmdmac_reset (tap_dance_state_t *state, void *user_data);
void guiwin_finished (tap_dance_state_t *state, void *user_data);
void guiwin_reset (tap_dance_state_t *state, void *user_data);
void optmac_finished (tap_dance_state_t *state, void *user_data);
void optmac_reset (tap_dance_state_t *state, void *user_data);
void ctlmac_finished (tap_dance_state_t *state, void *user_data);
void ctlmac_reset (tap_dance_state_t *state, void *user_data);
/* void lsft_finished (tap_dance_state_t *state, void *user_data); */
/* void lsft_reset (tap_dance_state_t *state, void *user_data); */
void escwin_finished (tap_dance_state_t *state, void *user_data);
void escwin_reset (tap_dance_state_t *state, void *user_data);
void escmac_finished (tap_dance_state_t *state, void *user_data);
void escmac_reset (tap_dance_state_t *state, void *user_data);
/* void num_finished (tap_dance_state_t *state, void *user_data); */
/* void num_reset (tap_dance_state_t *state, void *user_data); */



// TAP DANCE: Return an integer that corresponds to what kind of tap dance should be executed.


int cur_dance (tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->pressed) return SINGLE_HOLD;
    else return SINGLE_TAP;
  }
  else if (state->count == 2) {
    if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  else if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8;
}


// TAP DANCE: ALT (WINDOWS) -------------------------------------------------------

static tap altwin_state = {
  .is_press_action = true,
  .state = 0
};

void altwin_finished (tap_dance_state_t *state, void *user_data) {
  altwin_state.state = cur_dance(state);
  switch (altwin_state.state) {

    case SINGLE_TAP: register_code(KC_ENT); break;
    case SINGLE_HOLD: register_code(KC_LALT); break;
    case DOUBLE_TAP: leader_start(); break; 
    case DOUBLE_HOLD: /*layer_on(_TABS_WIN);*/ break;
  }
}

void altwin_reset (tap_dance_state_t *state, void *user_data) {
  switch (altwin_state.state) {
    case SINGLE_TAP: unregister_code(KC_ENT); break;
    case SINGLE_HOLD: unregister_code(KC_LALT); break;
    case DOUBLE_TAP: break;
    case DOUBLE_HOLD: /*layer_off(_TABS_WIN);*/ break;
  }
  altwin_state.state = 0;
}



// TAP DANCE: CMD (MACOS) -------------------------------------------------------

static tap cmdmac_state = {
  .is_press_action = true,
  .state = 0
};

void cmdmac_finished (tap_dance_state_t *state, void *user_data) {
  cmdmac_state.state = cur_dance(state);
  switch (cmdmac_state.state) {

    case SINGLE_TAP: register_code(KC_ENT); break;
    case SINGLE_HOLD: register_code(KC_LGUI); break;
    case DOUBLE_TAP: leader_start(); break; 
    case DOUBLE_HOLD: /*layer_on(_TABS_MAC);*/ break;
  }
}

void cmdmac_reset (tap_dance_state_t *state, void *user_data) {
  switch (cmdmac_state.state) {
    case SINGLE_TAP: unregister_code(KC_ENT); break;
    case SINGLE_HOLD: unregister_code(KC_LGUI); break;
    case DOUBLE_TAP: break;
    case DOUBLE_HOLD: /*layer_off(_TABS_MAC);*/ break;
  }
  cmdmac_state.state = 0;
}




// TAP DANCE: GUI (WINDOWS) -------------------------------------------------------

static tap guiwin_state = {
  .is_press_action = true,
  .state = 0
};

void guiwin_finished (tap_dance_state_t *state, void *user_data) {
  guiwin_state.state = cur_dance(state);
  switch (guiwin_state.state) {

    case SINGLE_TAP: register_code(KC_BSPC); break;
    case SINGLE_HOLD: register_code(KC_LGUI); break;
    case DOUBLE_TAP: break; 
    case DOUBLE_HOLD: break;
  }
}

void guiwin_reset (tap_dance_state_t *state, void *user_data) {
  switch (guiwin_state.state) {
    case SINGLE_TAP: unregister_code(KC_BSPC); break;
    case SINGLE_HOLD: unregister_code(KC_LGUI); break;
    case DOUBLE_TAP: break;
    case DOUBLE_HOLD: break;
  }
  guiwin_state.state = 0;
}



// TAP DANCE: OPT (MACOS) -------------------------------------------------------

static tap optmac_state = {
  .is_press_action = true,
  .state = 0
};

void optmac_finished (tap_dance_state_t *state, void *user_data) {
  optmac_state.state = cur_dance(state);
  switch (optmac_state.state) {

    case SINGLE_TAP: register_code(KC_BSPC); break;
    case SINGLE_HOLD: register_code(KC_LALT); break;
    case DOUBLE_TAP: break; 
    case DOUBLE_HOLD: register_code(KC_LGUI);
                     register_code(KC_LALT);
                     register_code(KC_LCTL); 
                     register_code(KC_LSFT); break;
  }
}

void optmac_reset (tap_dance_state_t *state, void *user_data) {
  switch (optmac_state.state) {
    case SINGLE_TAP: unregister_code(KC_BSPC); break;
    case SINGLE_HOLD: unregister_code(KC_LALT); break;
    case DOUBLE_TAP: break;
    case DOUBLE_HOLD: unregister_code(KC_LGUI);
                     unregister_code(KC_LALT);
                     unregister_code(KC_LCTL); 
                     unregister_code(KC_LSFT); break;
  }
  optmac_state.state = 0;
}




// TAP DANCE: LCTL (MACOS) -------------------------------------------------------

static tap ctlmac_state = {
  .is_press_action = true,
  .state = 0
};

void ctlmac_finished (tap_dance_state_t *state, void *user_data) {
  ctlmac_state.state = cur_dance(state);
  switch (ctlmac_state.state) {

    case SINGLE_TAP: break;
    case SINGLE_HOLD: register_code(KC_LCTL); break;
    case DOUBLE_TAP: register_code(KC_LGUI);
                     register_code(KC_LALT);
                     register_code(KC_LCTL); 
                     register_code(KC_LSFT);
                     register_code(KC_D); break; 
    case DOUBLE_HOLD: register_code(KC_LGUI);
                     register_code(KC_LALT);
                     register_code(KC_LCTL); 
                     register_code(KC_LSFT); break;
  }
}

void ctlmac_reset (tap_dance_state_t *state, void *user_data) {
  switch (ctlmac_state.state) {
    case SINGLE_TAP: break;
    case SINGLE_HOLD: unregister_code(KC_LCTL); break;
    case DOUBLE_TAP: unregister_code(KC_D);
                     unregister_code(KC_LGUI);
                     unregister_code(KC_LALT);
                     unregister_code(KC_LCTL); 
                     unregister_code(KC_LSFT); break;
    case DOUBLE_HOLD: unregister_code(KC_LGUI);
                     unregister_code(KC_LALT);
                     unregister_code(KC_LCTL); 
                     unregister_code(KC_LSFT); break;
  }
  ctlmac_state.state = 0;
}






// TAP DANCE: LSFT -------------------------------------------------------

/* static tap lsft_state = { */
/*   .is_press_action = true, */
/*   .state = 0 */
/* }; */

/* void lsft_finished (tap_dance_state_t *state, void *user_data) { */
/*   lsft_state.state = cur_dance(state); */
/*   switch (lsft_state.state) { */

/*     case SINGLE_TAP: register_code(KC_LSFT); break; */
/*     case SINGLE_HOLD: register_code(KC_LSFT); break; */
/*     case DOUBLE_TAP: register_code(KC_CAPS); break; */ 
/*     case DOUBLE_HOLD: break; */
/*   } */
/* } */

/* void lsft_reset (tap_dance_state_t *state, void *user_data) { */
/*   switch (lsft_state.state) { */
/*     case SINGLE_TAP: unregister_code(KC_LSFT); break; */
/*     case SINGLE_HOLD: unregister_code(KC_LSFT); break; */
/*     case DOUBLE_TAP: wait_ms(DEBOUNCE_CAPS_DELAY); unregister_code(KC_CAPS); break; */
/*     case DOUBLE_HOLD: break; */
/*   } */
/*   lsft_state.state = 0; */
/* } */






// TAP DANCE: ESC_WIN -------------------------------------------------------

/* static tap escwin_state = { */
/*   .is_press_action = true, */
/*   .state = 0 */
/* }; */

/* void escwin_finished (tap_dance_state_t *state, void *user_data) { */
/*   escwin_state.state = cur_dance(state); */
/*   switch (escwin_state.state) { */

/*     case SINGLE_TAP: register_code(KC_ESC); break; */
/*     case SINGLE_HOLD: layer_on(_ARROWS_WIN); break; */
/*     /1* case SINGLE_HOLD: unregister_code(KC_LALT); layer_on(_ARROWS_WIN); break; *1/ */
/*                       // 在試圖按ARROW layer位於ALT位置的KC_ENT時，避免Default Layer的ALT卡住 */
/*     case DOUBLE_TAP: register_code(KC_CAPS); break; */
/*     case DOUBLE_HOLD: layer_on(_MACROS_WIN); break; */
/*   } */
/* } */

/* void escwin_reset (tap_dance_state_t *state, void *user_data) { */
/*   switch (escwin_state.state) { */
/*     case SINGLE_TAP: unregister_code(KC_ESC); break; */
/*     case SINGLE_HOLD: layer_off(_ARROWS_WIN); break; */
/*     case DOUBLE_TAP: wait_ms(DEBOUNCE_CAPS_DELAY); unregister_code(KC_CAPS); break; */
/*     case DOUBLE_HOLD: layer_off(_MACROS_WIN); break; */
/*   } */
/*   escwin_state.state = 0; */
/* } */



// TAP DANCE: ESC_MAC -------------------------------------------------------

/* static tap escmac_state = { */
/*   .is_press_action = true, */
/*   .state = 0 */
/* }; */

/* void escmac_finished (tap_dance_state_t *state, void *user_data) { */
/*   escmac_state.state = cur_dance(state); */
/*   switch (escmac_state.state) { */

/*     case SINGLE_TAP: register_code(KC_ESC); break; */
/*     case SINGLE_HOLD: layer_on(_ARROWS_MAC); break; */
/*     /1* case SINGLE_HOLD: unregister_code(KC_LGUI); layer_on(_ARROWS_MAC); break; *1/ */
/*                       // 在試圖按ARROW layer位於CMD位置的KC_ENT時，避免Default Layer的CMD卡住 */
/*     case DOUBLE_TAP: register_code(KC_CAPS); break; */
/*     case DOUBLE_HOLD: layer_on(_MACROS_MAC); break; */
/*   } */
/* } */

/* void escmac_reset (tap_dance_state_t *state, void *user_data) { */
/*   switch (escmac_state.state) { */
/*     case SINGLE_TAP: unregister_code(KC_ESC); break; */
/*     case SINGLE_HOLD: layer_off(_ARROWS_MAC); break; */
/*     case DOUBLE_TAP: wait_ms(DEBOUNCE_CAPS_DELAY); unregister_code(KC_CAPS); break; */
/*     case DOUBLE_HOLD: layer_off(_MACROS_MAC); break; */
/*   } */
/*   escmac_state.state = 0; */
/* } */




// TAP DANCE: NUM_LEAD -------------------------------------------------------

/* static tap numtap_state = { */
/*   .is_press_action = true, */
/*   .state = 0 */
/* }; */

/* void num_finished (tap_dance_state_t *state, void *user_data) { */
/*   numtap_state.state = cur_dance(state); */
/*   switch (numtap_state.state) { */

/*     case SINGLE_TAP: leader_start(); break; */
/*     case SINGLE_HOLD: layer_on(_NUM); break; */
/*     case DOUBLE_TAP: register_code(KC_CAPS); break; */
/*     case DOUBLE_HOLD: layer_on(_MOUSE); break; */
/*   } */
/* } */

/* void num_reset (tap_dance_state_t *state, void *user_data) { */
/*   switch (numtap_state.state) { */
/*     case SINGLE_TAP: break; */
/*     case SINGLE_HOLD: layer_off(_NUM); break; */
/*     case DOUBLE_TAP: wait_ms(DEBOUNCE_CAPS_DELAY); unregister_code(KC_CAPS); break; */
/*     case DOUBLE_HOLD: layer_off(_MOUSE); break; */
/*   } */
/*   numtap_state.state = 0; */
/* } */




// Handler Definitions


tap_dance_action_t tap_dance_actions[] = {
  [LALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, altwin_finished, altwin_reset),
  [CMD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, cmdmac_finished, cmdmac_reset),
  [LGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, guiwin_finished, guiwin_reset),
  [OPT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, optmac_finished, optmac_reset),
  [LCTL_MAC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctlmac_finished, ctlmac_reset),
  /* [LSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lsft_finished, lsft_reset), */
  /* [ESC_WIN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, escwin_finished, escwin_reset), */
  /* [ESC_MAC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, escmac_finished, escmac_reset), */
  /* [NUM_LEAD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, num_finished, num_reset), */
};
