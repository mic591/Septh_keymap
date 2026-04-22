/*
Copyright 2021 @Yowkees
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

#pragma once

// Key matrix parameters (septh is duplex matrix)
#define MATRIX_ROWS         (5 * 2)  // split keyboard
#define MATRIX_COLS         (4 * 2)  // duplex matrix
#define MATRIX_ROW_PINS       { D4, C6, D7, E6, B4 }
#define MATRIX_COL_PINS       { F4, F5, F6, F7 }

// 右側のピン配置が異なる場合
#ifdef RIGHT_SIDE_PIN_CONFIG
    #undef MATRIX_COL_PINS
    #define MATRIX_COL_PINS { F7, F6, F5, F4} // 右側
#endif

//#ifdef KEYBOARD_RIGHT
//	#define MATRIX_COL_PINS       { F7, F6, F5, F4 }
//#endif

#define MATRIX_MASKED
#define DEBOUNCE            5


// Split parameters
#define SOFT_SERIAL_PIN         D2
#define SPLIT_HAND_MATRIX_GRID  F6, D7

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define SPLIT_USB_DETECT ←一旦オフ

#ifdef OLED_ENABLE
#    define SPLIT_OLED_ENABLE
#endif

#define ENCODER_MAP_ENABLE
#define SPLIT_ENCODERS


// If your PC does not recognize Keyball, try setting this macro. This macro
// increases the firmware size by 200 bytes, so it is disabled by default, but
// it has been reported to work well in such cases.
//#define SPLIT_WATCHDOG_ENABLE

#define SPLIT_TRANSACTION_IDS_KB KEYBALL_GET_INFO, KEYBALL_GET_MOTION, KEYBALL_SET_CPI


#ifndef OLED_FONT_H
#    define OLED_FONT_H "keyboards/00septh/lib/logofont/logofont.c"
#    define OLED_FONT_START 32
#    define OLED_FONT_END 195
#endif

#if !defined(LAYER_STATE_8BIT) && !defined(LAYER_STATE_16BIT) && !defined(LAYER_STATE_32BIT)
#    define LAYER_STATE_8BIT
#endif

// To squeeze firmware size
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
