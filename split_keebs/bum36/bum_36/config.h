#pragma once

// Use EEPROM to identify left/right halves after flashing.
#define EE_HANDS

// Your interconnect is SDA/SCL over the USB-C breakout.
#define USE_I2C
#define SPLIT_USB_DETECT

#define VIAL_KEYBOARD_UID {0xC1, 0x5A, 0x92, 0x33, 0x7E, 0x44, 0x18, 0xB6}

#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}
