/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/



#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
   KC_LGUI  , KC_1      , KC_2      , KC_3         , KC_4        , KC_5       , TO(0)    ,                  KC_6     , KC_7     , KC_8       , KC_9     , KC_0     , KC_MINS  ,KC_DEL   ,
   KC_TAB   , KC_Q      , KC_W      , KC_E         , KC_R        , KC_T       , TO(2)    ,                  KC_Y     , KC_U     , KC_I       , KC_O     , KC_P     , KC_INT3  ,KC_ENTER ,
   KC_LSFT  , KC_A      , KC_S      , KC_D         , KC_F        , KC_G       ,                             KC_H     ,LT(2,KC_J), KC_K       , KC_L     , KC_P     , KC_ENTER ,KC_ENTER ,
   KC_LCTL  , KC_Z      , KC_X      , KC_C         , KC_V        , KC_B       ,                  KC_BTN1  , KC_N     , KC_M     , KC_COMM    , KC_DOT   , KC_SLSH  , KC_RSFT  ,KC_RSFT  ,
   KC_ESC   , KC_SPC    , KC_ENTER  ,LT(1,KC_LNG1),LT(1,KC_LNG2),LT(2,KC_LCTL),TO(0),            KC_BTN2  , KC_BTN3  , _______  ,LT(1,KC_ENT), KC_BSPC  , KC_DEL   , MO(2)    ,MO(3) 
  ),

  [1] = LAYOUT_universal(
    _______ , S(KC_SLSH), S(KC_BSLS), KC_PSCR      , KC_INT3     , S(KC_5)    , _______  ,                  KC_EQL   , S(KC_6)  ,S(KC_QUOT)  , S(KC_8)  , S(KC_9)  ,S(KC_INT1),_______  ,
    _______ , S(KC_1)   , S(KC_2)   , S(KC_3)      , S(KC_4)     , S(KC_5)    , _______  ,                  S(KC_Y)  , S(KC_6)  , S(KC_7)    , S(KC_8)  , S(KC_9)  ,S(KC_INT3),_______  ,
    _______ , KC_LBRC   , KC_RGHT   , KC_UP        , KC_LEFT     , KC_SLSH    ,                             S(KC_H)  , S(KC_J)  , S(KC_K)    , S(KC_L)  , KC_QUOT  , S(KC_2)  ,_______  ,
    _______ , S(KC_Z)   , KC_BTN2   , KC_DOWN      , KC_DEL      , KC_BSPC    ,                  _______  , S(KC_N)  , S(KC_M)  ,S(KC_COMM)  , S(KC_DOT),S(KC_SLSH),S(KC_RSFT),_______  ,
    _______ , _______   , _______   , _______      , _______     , _______    , _______  ,       _______  , _______  , _______  , _______    , _______  , _______  , _______  ,_______  
  ),

  [2] = LAYOUT_universal(
    _______  , S(KC_6)  , KC_F2     , KC_F3        , KC_F4       , KC_PMNS    , _______  ,                  KC_F6    , KC_F7    , KC_F8      , KC_F9    , KC_F10   , KC_F11   ,_______  ,
    _______  , KC_PSLS  , KC_7      , KC_8         , KC_9        , KC_PEQL    , _______  ,                  KC_PPLS  , KC_PMNS  , _______    , KC_INT3  , KC_QUOT  , KC_F12   ,_______  ,
    _______  , KC_PAST  , KC_4      , KC_5         , KC_6        , KC_DOT     ,                             KC_PAST  , KC_PSLS  , KC_UP      , KC_RGHT  , KC_SCLN  , S(KC_2)  ,_______  ,
    _______  , KC_PPLS  , KC_1      , KC_2         , KC_3        , KC_0       ,                  _______  , _______  , KC_RGHT  , S(KC_8)    , S(KC_9)  , _______  , _______  ,_______  ,
    _______  , _______  , _______   , _______      , _______     , _______    , _______  ,       _______  , _______  , _______  , _______    , _______  , _______  , _______  ,_______  
  ),

  [3] = LAYOUT_universal(
    _______  , _______  , _______   , _______      , _______     , _______    , _______  ,                  _______  , _______  , _______    , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______   , C(KC_I)      , C(KC_O)     , C(KC_P)    , _______  ,                  _______  , _______  , _______    , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______   , _______      , C(KC_H)     , C(KC_L)    ,                             _______  , _______  , _______    , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______   , _______      , C(KC_N)     , C(KC_M)    ,                  _______  , _______  , _______  , _______    , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______   , _______      , _______     , _______    , _______  ,       _______  , _______  , _______  , _______    , _______  , _______  , _______  , _______ 
  )
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"
	
void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif


#define ENC ENCODER_CCW_CW(KC_VOLD, KC_VOLU)

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENC, ENCODER_CCW_CW(KC_NO, KC_NO) },
    [1] = { ENC, ENCODER_CCW_CW(KC_NO, KC_NO) },
    [2] = { ENC, ENCODER_CCW_CW(KC_NO, KC_NO) },
    [3] = { ENC, ENCODER_CCW_CW(KC_NO, KC_NO) }
};

void matrix_scan_user(void) {
}