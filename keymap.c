#include QMK_KEYBOARD_H

enum {
    ARROW = 0,
    QUOTE_WORD,
    SQUOTE_WORD,
    SWIFT_STRG,
    CBR_BLOCK,
    CBR_PAIR,
    PRN_PAIR,
   	BRC_PAIR,
   	ANG_PAIR    
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {

    case ARROW: {
        if (record->event.pressed) {
            SEND_STRING("->"); 
            return false;
        }
    }

    case QUOTE_WORD: {
      if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_RALT));
            SEND_STRING(SS_TAP(X_LEFT));
            SEND_STRING(SS_UP(X_RALT));
            SEND_STRING("\""); 
            SEND_STRING(SS_DOWN(X_RALT));
            SEND_STRING(SS_TAP(X_RIGHT));
            SEND_STRING(SS_UP(X_RALT));
            SEND_STRING("\""); 
            return false;
      }
    }

    case SQUOTE_WORD: {
      if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_RALT));
            SEND_STRING(SS_TAP(X_LEFT));
            SEND_STRING(SS_UP(X_RALT));
            SEND_STRING("'"); 
            SEND_STRING(SS_DOWN(X_RALT));
            SEND_STRING(SS_TAP(X_RIGHT));
            SEND_STRING(SS_UP(X_RALT));
            SEND_STRING("'"); 
            return false;
      }
    }

    case SWIFT_STRG: {
      if (record->event.pressed) {
            SEND_STRING("\\()"); 
            SEND_STRING(SS_TAP(X_LEFT));
            return false;
      }
    }

    case CBR_BLOCK: {
      if (record->event.pressed) {
            SEND_STRING("{"); 
            SEND_STRING(SS_TAP(X_ENTER));
            return false;
      }
    }

    case CBR_PAIR: {
      if (record->event.pressed) {
            SEND_STRING("{}"); 
            SEND_STRING(SS_TAP(X_LEFT));
            return false;
      }
    }

    case PRN_PAIR: {
      if (record->event.pressed) {
            SEND_STRING("()"); 
            SEND_STRING(SS_TAP(X_LEFT));
            return false;
      }
    }

    case BRC_PAIR: {
      if (record->event.pressed) {
            SEND_STRING("[]"); 
            SEND_STRING(SS_TAP(X_LEFT));
            return false;
      }
    }

    case ANG_PAIR: {
      if (record->event.pressed) {
            SEND_STRING("<>"); 
            SEND_STRING(SS_TAP(X_LEFT));
            return false;
      }
    }

  }
  return MACRO_NONE;
};



enum {
    TO_3_OR_0 = 0,
    TO_0_OR_0 = 0,
    LT_OR_GT,
    LCBR_OR_RCBR,
    LPRN_OR_RPRN,
    LBRC_OR_RBRC    
};


void dance_home(qk_tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
	case 1: 
		if (IS_LAYER_ON(0)) { 
			layer_clear();
			layer_on(3);
		} else { 
			layer_clear();
			layer_on(0);
		}
    	break;
  	case 2:
		layer_clear();
		layer_on(0);
    	break;
	}
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TO_3_OR_0] = ACTION_TAP_DANCE_FN(dance_home),
    [TO_0_OR_0] = ACTION_TAP_DANCE_FN(dance_home),
    [LT_OR_GT] = ACTION_TAP_DANCE_DOUBLE(KC_LT, KC_GT),
    [LCBR_OR_RCBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [LPRN_OR_RPRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [LBRC_OR_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
	
//                                  ┌───────────────────┐                              
//                                  │  Layer 0 - Base   │                              
//                                  └───────────────────┘                              
//                                                                                     
//                  ┌─────┐                                       ┌─────┐              
//           ┌─────┐│     │┌─────┐                         ┌─────┐│     │┌─────┐       
//           │     ││  L  ││     │┌─────┐           ┌─────┐│     ││  U  ││     │       
//    ┌─────┐│  C  ││     ││  M  ││     │           │     ││  F  ││     ││  ,  │┌─────┐
//    │     ││     │└─────┘│     ││  K  │           │  Z  ││     │└─────┘│     ││     │
//    │  Y  │└─────┘┌─────┐└─────┘│     │           │     │└─────┘┌─────┐└─────┘│  ⌫  │
//    │     │┌─────┐│  R  │┌─────┐└─────┘           └─────┘┌─────┐│  E  │┌─────┐│     │
//    └─────┘│  S  ││     ││  T  │┌─────┐           ┌─────┐│  N  ││     ││  A  │└─────┘
//    ┌─────┐│     ││  ⌥  ││     ││  G  │           │  P  ││     ││  ⌥  ││     │┌─────┐
//    │  I  ││  ^  │└─────┘│  ⌘  ││     │           │     ││  ⌘  │└─────┘│  ^  ││  O  │
//    │     │└─────┘┌─────┐└─────┘│ MEH │           │ MEH │└─────┘┌─────┐└─────┘│     │
//    │  ⇧  │┌─────┐│     │┌─────┐└─────┘           └─────┘┌─────┐│     │┌─────┐│  ⇧  │
//    └─────┘│     ││  W  ││     │┌─────┐           ┌─────┐│     ││  /  ││     │└─────┘
//    ┌─────┐│  V  ││     ││  D  ││     │           │     ││  H  ││     ││  .  │┌─────┐
//    │     ││     │└─────┘│     ││  J  │           │  B  ││     │└─────┘│     ││     │
//    │  Q  │└─────┘       └─────┘│     │           │     │└─────┘       └─────┘│  X  │
//    │     │                     └─────┘           └─────┘                     │     │
//    └─────┘                                                                   └─────┘
//                             ┌─────┐                 ┌─────┐                         
//                             │  ␣  │┌─────┐   ┌─────┐│  ↩  │                         
//                             │     ││ TO3 │   │     ││     │                         
//                             │ LT1 ││     │   │ TO2 ││ LT1 │                         
//                             └─────┘│ DD0 │   │     │└─────┘                         
//                                    └─────┘   └─────┘                                
	[0] = LAYOUT_split_3x5_2(      
	
KC_Y, KC_C, KC_L, KC_M, KC_K,                                               KC_Z, KC_F, KC_U, KC_COMM, KC_BSPC, 
LSFT_T(KC_I), LCTL_T(KC_S), LALT_T(KC_R), LGUI_T(KC_T), MEH_T(KC_G),        MEH_T(KC_P), RGUI_T(KC_N), RALT_T(KC_E), RCTL_T(KC_A), RSFT_T(KC_O), 
KC_Q, KC_V, KC_W, KC_D, KC_J,                                               KC_B, KC_H, KC_SLSH, KC_DOT, KC_X, 

                                                LT(1,KC_SPC), TD(TO_3_OR_0), TO(2), LT(1,KC_ENT)),
	
//                                 ┌──────────────────────┐                            
//                                 │ Layer 1 - Shortcuts  │                            
//                                 └──────────────────────┘                            
//                                                                                     
//                  ┌─────┐                                       ┌─────┐              
//           ┌─────┐│     │┌─────┐                         ┌─────┐│     │┌─────┐       
//           │     ││ ⌘ 4 ││     │┌─────┐           ┌─────┐│     ││ ⌃⌘F ││     │       
//    ┌─────┐│ ⌘ 1 ││     ││ ⌥⌘J ││     │           │     ││ ⇧⌘5 ││     ││⇧⌃⌘/ │┌─────┐
//    │     ││     │└─────┘│     ││ ⇧⌘O │           │ ⌥⌘[ ││     │└─────┘│     ││     │
//    │ ESC │└─────┘┌─────┐└─────┘│     │           │     │└─────┘┌─────┐└─────┘│ ⇧⌘/ │
//    │     │┌─────┐│     │┌─────┐└─────┘           └─────┘┌─────┐│     │┌─────┐│     │
//    └─────┘│     ││ ⌘ A ││     │┌─────┐           ┌─────┐│     ││ ^ ← ││     │└─────┘
//    ┌─────┐│ ⌘ Z ││     ││ ⌘ C ││     │           │     ││ ⌘ V ││     ││ ^ → │┌─────┐
//    │     ││     │└─────┘│     ││ ⇧⌘[ │           │ ⇧⌘] ││     │└─────┘│     ││     │
//    │ TAB │└─────┘┌─────┐└─────┘│     │           │     │└─────┘┌─────┐└─────┘│ ⇧⌘L │
//    │     │┌─────┐│     │┌─────┐└─────┘           └─────┘┌─────┐│     │┌─────┐│     │
//    └─────┘│     ││ ⇧⌘A ││ ⌘ X │┌─────┐           ┌─────┐│     ││⇧⌘TAB││     │└─────┘
//    ┌─────┐│ ⇧⌘Z ││     ││     ││     │           │     ││⌥⇧⌘ V││     ││⌘ TAB│┌─────┐
//    │     ││     │└─────┘│ LT5 ││ ⌘ W │           │ ⌥⌘] ││     │└─────┘│     ││     │
//    │ ^ A │└─────┘       └─────┘│     │           │     │└─────┘       └─────┘│ ^ E │
//    │     │                     └─────┘           └─────┘                     │     │
//    └─────┘                                                                   └─────┘
//                             ┌ ─ ─ ┐                 ┌─────┐                         
//                                    ┌─────┐   ┌─────┐│     │                         
//                             │ N/A ││     │   │     ││ ⌘ ␣ │                         
//                                    │ N/A │   │ ⌃⌘␣ ││     │                         
//                             └ ─ ─ ┘│     │   │     │└─────┘                         
//                                    └─────┘   └─────┘                                	
	
	[1] = LAYOUT_split_3x5_2(
	
KC_ESC, G(KC_1), G(KC_4), LAG(KC_J), SGUI(KC_0),       LAG(KC_LBRC), SGUI(KC_5), KC_F, C(SGUI(KC_SLSH)), SGUI(KC_SLSH), 
KC_TAB, G(KC_Z), G(KC_A), G(KC_C), SGUI(KC_LBRC),      SGUI(KC_RBRC), G(KC_V), C(KC_LEFT), C(KC_RGHT), SGUI(KC_L), 
C(KC_A), SGUI(KC_Z), SGUI(KC_A), LT(5,G(KC_X)), G(KC_W),     LAG(KC_RBRC), A(SGUI(KC_V)), SGUI(KC_TAB), G(KC_TAB), C(KC_E), 

                                KC_NO, LT(5,KC_NO), C(G(KC_SPC)), G(KC_SPC)),
	
//                                  ┌───────────────────┐                              
//                                  │ Layer 2 - Symbols │                              
//                                  └───────────────────┘                              
//                                                                                     
//                  ┌─────┐                                       ┌─────┐              
//           ┌─────┐│     │┌─────┐                         ┌─────┐│     │┌─────┐       
//           │     ││  #  ││     │┌─────┐           ┌─────┐│     ││  *  ││     │       
//    ┌─────┐│  @  ││     ││  $  ││     │           │     ││  &  ││     ││  ,  │┌─────┐
//    │     ││     │└─────┘│     ││  %  │           │  ^  ││     │└─────┘│     ││     │
//    │  !  │└─────┘┌─────┐└─────┘│     │           │     │└─────┘┌─────┐└─────┘│  ⌫  │
//    │     │┌─────┐│     │┌─────┐└─────┘           └─────┘┌─────┐│  (  │┌─────┐│     │
//    └─────┘│     ││  -  ││     │┌─────┐           ┌─────┐│  {  ││     ││  [  │└─────┘
//    ┌─────┐│  "  ││     ││  =  ││     │           │  <  ││     ││ DD) ││     │┌─────┐
//    │     ││     │└─────┘│     ││  +  │           │     ││ DD} │└─────┘│ DD] ││     │
//    │     │└─────┘┌─────┐└─────┘│     │           │ DD> │└─────┘┌─────┐└─────┘│  \  │
//    │     │┌─────┐│     │┌─────┐└─────┘           └─────┘┌─────┐│     │┌─────┐│     │
//    └─────┘│     ││  _  ││     │┌─────┐           ┌─────┐│     ││  /  ││     │└─────┘
//    ┌─────┐│  '  ││     ││ ⇧⌥2 ││     │           │     ││     ││     ││  .  │┌─────┐
//    │     ││     │└─────┘│     ││     │           │  ?  ││     │└─────┘│     ││     │
//    │  `  │└─────┘       └─────┘│     │           │     │└─────┘       └─────┘│  X  │
//    │     │                     └─────┘           └─────┘                     │     │
//    └─────┘                                                                   └─────┘
//                             ┌─────┐                 ┌─────┐                         
//                             │  ␣  │┌─────┐   ┌─────┐│  ↩  │                         
//                             │     ││ TO0 │   │     ││     │                         
//                             │ LT1 ││     │   │ TO4 ││ LT1 │                         
//                             └─────┘│ DD0 │   │     │└─────┘                         
//                                    └─────┘   └─────┘                                

	[2] = LAYOUT_split_3x5_2(

KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_COMM, KC_BSPC, 
KC_NO, KC_DQUO, KC_MINS, KC_EQL, KC_PLUS,      TD(LT_OR_GT), TD(LCBR_OR_RCBR), TD(LPRN_OR_RPRN), TD(LBRC_OR_RBRC), KC_BSLS, 
KC_GRV, KC_QUOT, KC_UNDS, LSA(KC_2), KC_NO,    KC_QUES, KC_NO, KC_SLSH, KC_DOT, KC_NO, 

                         LT(1,KC_SPC), TD(TO_0_OR_0), TO(4), LT(1,KC_ENT)),
	
	
//                                 ┌──────────────────────┐                            
//                                 │  Layer 3 - Numbers   │                            
//                                 └──────────────────────┘                            
//                                                                                     
//                  ┌─────┐                                       ┌─────┐              
//           ┌─────┐│     │┌─────┐                         ┌─────┐│     │┌─────┐       
//           │     ││     ││     │┌─────┐           ┌─────┐│     ││  8  ││     │       
//    ┌─────┐│     ││     ││     ││     │           │     ││  7  ││     ││  9  │┌─────┐
//    │     ││     │└─────┘│     ││     │           │  +  ││     │└─────┘│     ││     │
//    │     │└─────┘┌─────┐└─────┘│     │           │     │└─────┘┌─────┐└─────┘│  ⌫  │
//    │     │┌─────┐│     │┌─────┐└─────┘           └─────┘┌─────┐│     │┌─────┐│     │
//    └─────┘│     ││     ││     │┌─────┐           ┌─────┐│     ││  5  ││     │└─────┘
//    ┌─────┐│     ││  ⌥  ││     ││     │           │     ││  4  ││     ││  6  │┌─────┐
//    │     ││  ^  │└─────┘│  ⌘  ││     │           │  -  ││     │└─────┘│     ││     │
//    │     │└─────┘┌─────┐└─────┘│ MEH │           │     │└─────┘┌─────┐└─────┘│  =  │
//    │  ⇧  │┌─────┐│     │┌─────┐└─────┘           └─────┘┌─────┐│     │┌─────┐│     │
//    └─────┘│     ││     ││     │┌─────┐           ┌─────┐│     ││  2  ││     │└─────┘
//    ┌─────┐│     ││     ││     ││     │           │     ││  1  ││     ││  3  │┌─────┐
//    │     ││     │└─────┘│     ││     │           │  0  ││     │└─────┘│     ││     │
//    │     │└─────┘       └─────┘│     │           │     │└─────┘       └─────┘│     │
//    │     │                     └─────┘           └─────┘                     │     │
//    └─────┘                                                                   └─────┘
//                             ┌─────┐                 ┌─────┐                         
//                             │  ␣  │┌─────┐   ┌─────┐│  ↩  │                         
//                             │     ││ TO0 │   │     ││     │                         
//                             │ LT1 ││     │   │ TO4 ││ LT1 │                         
//                             └─────┘│ DD0 │   │     │└─────┘                         
//                                    └─────┘   └─────┘                                	
	
	
	[3] = LAYOUT_split_3x5_2(

KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                                   KC_PLUS, KC_7, KC_8, KC_9, KC_BSPC, 
LSFT_T(KC_NO), LCTL_T(KC_NO), LALT_T(KC_NO), LGUI_T(KC_NO), MEH_T(KC_NO),            KC_MINS, KC_4, KC_5, KC_6, KC_EQL, 
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                                   KC_0, KC_1, KC_2, KC_3, KC_NO, 

                                                      LT(1,KC_SPC), TD(TO_0_OR_0), TO(4), LT(1,KC_ENT)),
	
	
//                                ┌────────────────────────┐                           
//                                │  Layer 4 - Navigation  │                           
//                                └────────────────────────┘                           
//                                                                                     
//                  ┌─────┐                                       ┌─────┐              
//           ┌─────┐│     │┌─────┐                         ┌─────┐│     │┌─────┐       
//           │     ││ W ↓ ││     │┌─────┐           ┌─────┐│     ││PGDN ││     │       
//    ┌─────┐│ W ↓ ││     ││ W → ││     │           │     ││ RCL ││     ││PGUP │┌─────┐
//    │     ││     │└─────┘│     ││     │           │ LCL ││     │└─────┘│     ││     │
//    │ W ← │└─────┘┌─────┐└─────┘│     │           │     │└─────┘┌─────┐└─────┘│  ⌫  │
//    │     │┌─────┐│     │┌─────┐└─────┘           └─────┘┌─────┐│     │┌─────┐│     │
//    └─────┘│     ││ M ↓ ││     │┌─────┐           ┌─────┐│     ││  ↓  ││     │└─────┘
//    ┌─────┐│ M ↓ ││     ││ M → ││     │           │     ││  ←  ││     ││  ↑  │┌─────┐
//    │     ││     │└─────┘│     ││     │           │     ││     │└─────┘│     ││     │
//    │ M ← │└─────┘┌─────┐└─────┘│     │           │     │└─────┘┌─────┐└─────┘│  →  │
//    │     │┌─────┐│ AC1 │┌─────┐└─────┘           └─────┘┌─────┐│     │┌─────┐│     │
//    └─────┘│ AC0 ││     ││ AC2 │┌─────┐           ┌─────┐│     ││     ││     │└─────┘
//    ┌─────┐│     ││  ⌥  ││     ││     │           │     ││     ││     ││     │┌─────┐
//    │     ││  ^  │└─────┘│  ⌘  ││     │           │RESET││     │└─────┘│     ││     │
//    │     │└─────┘       └─────┘│     │           │     │└─────┘       └─────┘│     │
//    │  ⇧  │                     └─────┘           └─────┘                     │     │
//    └─────┘                                                                   └─────┘
//                             ┌─────┐                 ┌─────┐                         
//                             │  ␣  │┌─────┐   ┌─────┐│  ↩  │                         
//                             │     ││ TO0 │   │     ││     │                         
//                             │ LT1 ││     │   │     ││ LT1 │                         
//                             └─────┘│ DD0 │   │     │└─────┘                         
//                                    └─────┘   └─────┘                                
	
	[4] = LAYOUT_split_3x5_2(
	
KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,                                                KC_BTN1, KC_BTN2, KC_PGDN, KC_PGUP, KC_BSPC, 
KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,                                                KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, 
LSFT_T(KC_NO), LCTL_T(KC_ACL0), LALT_T(KC_ACL1), LGUI_T(KC_ACL2), MEH_T(KC_NO),           RESET, KC_NO, KC_NO, KC_NO, KC_NO, 

LT(1,KC_SPC), TD(TO_0_OR_0), KC_RCTL, LT(1,KC_ENT)),
	
//                                ┌────────────────────────┐                           
//                                │    Layer 5 - Macros    │                           
//                                └────────────────────────┘                           
//                                                                                     
//                  ┌─────┐                                       ┌─────┐              
//           ┌─────┐│     │┌─────┐                         ┌─────┐│     │┌─────┐       
//           │     ││     ││     │┌─────┐           ┌─────┐│     ││\(|) ││     │       
//    ┌─────┐│     ││     ││     ││     │           │     ││ {↩  ││     ││     │┌─────┐
//    │     ││     │└─────┘│     ││     │           │     ││     │└─────┘│     ││     │
//    │     │└─────┘┌─────┐└─────┘│     │           │     │└─────┘┌─────┐└─────┘│     │
//    │     │┌─────┐│     │┌─────┐└─────┘           └─────┘┌─────┐│     │┌─────┐│     │
//    └─────┘│     ││     ││     │┌─────┐           ┌─────┐│     ││ (|) ││     │└─────┘
//    ┌─────┐│"<w>"││     ││     ││     │           │     ││ {|} ││     ││ [|] │┌─────┐
//    │     ││     │└─────┘│     ││     │           │ ->  ││     │└─────┘│     ││     │
//    │     │└─────┘┌─────┐└─────┘│     │           │     │└─────┘┌─────┐└─────┘│     │
//    │     │┌─────┐│     │┌─────┐└─────┘           └─────┘┌─────┐│     │┌─────┐│     │
//    └─────┘│     ││     ││     │┌─────┐           ┌─────┐│     ││     ││     │└─────┘
//    ┌─────┐│'<w>'││     ││     ││     │           │     ││     ││     ││     │┌─────┐
//    │     ││     │└─────┘│     ││     │           │     ││     │└─────┘│     ││     │
//    │     │└─────┘       └─────┘│     │           │     │└─────┘       └─────┘│     │
//    │     │                     └─────┘           └─────┘                     │     │
//    └─────┘                                                                   └─────┘
//                             ┌ ─ ─ ┐                 ┌─────┐                         
//                                    ┌ ─ ─ ┐   ┌─────┐│     │                         
//                             │ N/A │          │     ││     │                         
//                                    │ N/A │   │     ││     │                         
//                             └ ─ ─ ┘          │     │└─────┘                         
//                                    └ ─ ─ ┘   └─────┘                                
	
	[5] = LAYOUT_split_3x5_2(
	
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_NO, M(CBR_BLOCK), M(SWIFT_STRG), KC_NO, KC_NO, 
KC_NO, M(QUOTE_WORD), KC_NO, KC_NO, KC_NO,        M(ARROW), M(CBR_PAIR), M(PRN_PAIR), M(BRC_PAIR), KC_NO, 
KC_NO, M(SQUOTE_WORD), KC_NO, KC_NO, KC_NO,       KC_LT, KC_NO, KC_NO, KC_NO, KC_NO, 

KC_NO, KC_NO, KC_NO, KC_NO)};

