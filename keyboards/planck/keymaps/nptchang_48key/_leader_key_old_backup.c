

// ------- //
// Structs //
// ------- //


LEADER_EXTERNS();


void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

  // Make Command

    SEQ_ONE_KEY(KC_M) {
      SEND_STRING(
        "qmk compile -kb planck/rev6 -km nptchang"
      );
    }

  // Markdown Bullets

    SEQ_ONE_KEY(KC_SPACE) {
      SEND_STRING(
        "    "
      );
    }
    SEQ_TWO_KEYS(KC_SPACE,KC_SPACE) {
      SEND_STRING(
        "        "
      );
    }
    SEQ_THREE_KEYS(KC_SPACE,KC_SPACE,KC_SPACE) {
      SEND_STRING(
        "            "
      );
    }

  // SKH Log-Ins

    SEQ_ONE_KEY(KC_T) { /* 開啟Web His分頁 */
      SEND_STRING(
        "http://10.1.205.211/SkmhSSO/Login.jsp" SS_TAP(X_ENTER) 
      );
    }

    SEQ_TWO_KEYS(KC_T,KC_T) { /* 開啟院內網路系統分頁 */
      SEND_STRING(
        "http://web.skh.org.tw/skh/intranet/work/default.aspx" SS_TAP(X_ENTER) 
      );
    }

    SEQ_ONE_KEY(KC_L) { /* 開啟電子資源管理系統分頁 */
      SEND_STRING(
        "http://libskh.skh.org.tw/cgi-bin/smartweaver/browse.cgi?o=der&p=/smartweaver/login.htm" SS_TAP(X_ENTER) 
      );
    }

    SEQ_ONE_KEY(KC_S) { /* Web His 登入*/
      SEND_STRING(
        "M014537"   );_delay_ms(10);SEND_STRING(    SS_TAP(X_TAB)
        "passsssss"                                 SS_TAP(X_ENTER)
      );
    }

    SEQ_TWO_KEYS(KC_S,KC_S) {
      SEND_STRING(
        "M014537"   );_delay_ms(10);SEND_STRING(    SS_TAP(X_TAB)
        "passssss"                                  SS_TAP(X_ENTER)
      );
    }

    SEQ_ONE_KEY(KC_TAB) {
      SEND_STRING(
                    SS_TAP(X_PAUSE)
        "PINP"      SS_TAP(X_KP_ENTER)
        "270537"    SS_TAP(X_TAB)
        "123456"    SS_TAP(X_KP_ENTER)
        "01"        SS_TAP(X_KP_ENTER)
        /* "2133"      SS_TAP(X_KP_ENTER) */
                    SS_TAP(X_TAB)
        "1936"      SS_TAP(X_KP_ENTER)
      );
    }

    SEQ_ONE_KEY(KC_Q) {
      SEND_STRING(
                                /* SS_DOWN(X_LGUI));_delay_ms(100);SEND_STRING(SS_UP(X_LGUI) */
                                SS_TAP(X_LGUI)
                                SS_TAP(X_BSLASH)
                                SS_TAP(X_BSLASH)
        "2700-001008150"        SS_TAP(X_BSLASH)
        "Sung-Ya"               SS_TAP(X_KP_ENTER)
      );
    }

  // Medical Records

    SEQ_ONE_KEY(KC_O) {
      SEND_STRING(
        "Vital Signs: stable"                                                   SS_TAP(X_ENTER)
        "Consciousness: clear"                                                  SS_TAP(X_ENTER)
                                                                                SS_TAP(X_ENTER)
        "---Physical Examinations---"                                           SS_TAP(X_ENTER)
        "HEENT: Pink conjunctiva, no icteric sclera"                            SS_TAP(X_ENTER)
        "Heart: Regular heartbeat, no heart murmur"                             SS_TAP(X_ENTER)
        "Chest: Bilateral clear breathing sound"                                SS_TAP(X_ENTER)
        "Abdomen: Soft, normoactive bowel sound, no distention, no tenderness" SS_TAP(X_ENTER)
        "Extremities: Freely movable, no edema"
        );
    }

    SEQ_THREE_KEYS(KC_T, KC_B, KC_D) {
      SEND_STRING(
        "to be discharged and arrange OPD follow-up"                  SS_TAP(X_ENTER)
        );
    }

    SEQ_THREE_KEYS(KC_M, KC_S, KC_E) {
      SEND_STRING(
        "---MSE---"                    SS_TAP(X_ENTER)
        "Consciousness: "              SS_TAP(X_ENTER)
        "Appearance: "                 SS_TAP(X_ENTER)
        "Attention: "                  SS_TAP(X_ENTER)
            "    - (focus/sustain/shift)"                   SS_TAP(X_ENTER)
        "Attitude: "                   SS_TAP(X_ENTER)
        "Affect: "                     SS_TAP(X_ENTER)
            "    - (stability/appropriateness/range/intensity)"        SS_TAP(X_ENTER)
        "Mood: "                       SS_TAP(X_ENTER)
            "    - (nature/fluctuation/consistency)"        SS_TAP(X_ENTER)
        "Speech: "                     SS_TAP(X_ENTER)
            "    - (tone/rate/volume/latency_of_response)"                      SS_TAP(X_ENTER)
        "Thought: "                    SS_TAP(X_ENTER)
            "    - (stream/form/content/possession)"        SS_TAP(X_ENTER)
        "Perception: "                 SS_TAP(X_ENTER)
        "Behavior: "                   SS_TAP(X_ENTER)
        "Cognition: "                  SS_TAP(X_ENTER)
        "Drive: "                      SS_TAP(X_ENTER)
        "Somatic Complaints: "         SS_TAP(X_ENTER)
        "Insight: "                    SS_TAP(X_ENTER)
        "Suicidal Risk: "              SS_TAP(X_ENTER)
        "Homicidal Risk: "             
        );
    }


  }
}
