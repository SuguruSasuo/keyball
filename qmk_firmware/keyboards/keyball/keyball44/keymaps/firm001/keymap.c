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
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_BSPC   ,
    KC_LCTL   , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_ENT  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RSFT  ,
              KC_CAPS,KC_LALT,LT(3,KC_LGUI)     ,LT(1,KC_LNG1),LT(2,KC_SPC),                  LT(2,KC_SPC),LT(1,KC_LNG2), RCTL_T(KC_LNG2),     KC_RALT  , KC_RGUI
  ),

  [1] = LAYOUT_universal(
    KC_TAB ,  _______   , KC_F9    , KC_F10   , KC_F11    , KC_F12    ,                                         KC_7    , KC_8    , KC_9    , KC_MINS    , KC_EQL   , KC_BSPC   ,
    KC_LCTL ,  _______ , KC_F5  , KC_F6   , KC_F7   , KC_F8   ,                                         KC_4  , KC_5  , KC_6    , KC_PSLS  , KC_PAST  , KC_ENT   ,
    KC_LSFT ,  _______ , KC_F1  , KC_F2 , KC_F3  , KC_F4  ,                                         KC_1  , KC_2  , KC_3  , KC_0  , KC_GRV  , KC_RSFT  ,
                  _______  , KC_LALT , KC_LGUI  ,         _______  , _______  ,                   KC_DEL  , _______  , _______       , _______  , KC_RGUI
  ),

  [2] = LAYOUT_universal(
    KC_TAB  ,_______, _______     , _______    , _______     , _______  ,                                         _______  , _______  , _______  , _______  , _______  , KC_BSPC  ,
    KC_LCTL  ,_______, _______     , _______    , _______     , _______  ,                                         _______  , _______  , _______, _______  , _______  , KC_ENT  ,
    KC_LSFT  ,_______, _______     , _______    , _______     ,_______,                                        _______,_______, _______   ,_______,_______,KC_RSFT,
                  _______     , KC_LALT  , KC_LGUI  ,         _______  , _______  ,                   _______   , _______  , _______       , _______  , KC_RGUI
  ),

  [3] = LAYOUT_universal(
    _______  , CPI_D1K   , CPI_I1K  , _______  , _______  , _______  ,                                        KC_HOME  , _______  , _______  , _______ , _______ , _______  ,
    _______  , CPI_D100  , SCRL_DVI  , _______  , _______  , _______ ,                                        KC_PGUP  , _______  , KC_UP  , _______ , _______  , _______  ,
    _______ , CPI_I100  , SCRL_DVD  , _______  , _______  , _______ ,                                        KC_PGDN  , KC_LEFT , KC_DOWN , KC_RIGHT  , _______  , _______ ,
                  _______  , _______  , _______  ,        _______  , KBC_SAVE  ,                   _______  , _______  , _______       , _______  , _______
  ),

  [4] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  , _______  ,                                        RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , SCRL_DVI ,                                        RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , SCRL_DVD ,                                        CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _______  , KBC_SAVE ,
                  QK_BOOT  , KBC_RST  , _______  ,        _______  , _______  ,                   _______  , _______  , _______       , KBC_RST  , QK_BOOT
  ),

  [5] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  , _______  ,                                        RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , SCRL_DVI ,                                        RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , SCRL_DVD ,                                        CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _______  , KBC_SAVE ,
                  QK_BOOT  , KBC_RST  , _______  ,        _______  , _______  ,                   _______  , _______  , _______       , KBC_RST  , QK_BOOT
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state)
{
  // Auto enable scroll mode when the highest layer is 3
  keyball_set_scroll_mode(get_highest_layer(state) == 3);
  return state;
}

// コンボキー定義
#ifdef COMBO_ENABLE
const uint16_t PROGMEM my_esc[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM my_mouse_btn1[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM my_mouse_btn2[] = {KC_K, KC_L, COMBO_END};


combo_t key_combos[] = {
    COMBO(my_esc, KC_ESC),
    COMBO(my_mouse_btn1, KC_BTN1),
    COMBO(my_mouse_btn2, KC_BTN2),
};
#endif

#ifdef OLED_ENABLE

#include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void)
{
  keyball_oled_render_keyinfo();
  keyball_oled_render_ballinfo();
  keyball_oled_render_layerinfo();
}
#endif

// 自動マウスレイヤー変換
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void)
{
  set_auto_mouse_enable(true);
}
#endif


