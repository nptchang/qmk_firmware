

void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_M)) {
        // Leader, f => Types the below string
        SEND_STRING("qmk compile -kb planck/rev6 -km nptchang");
    }
}