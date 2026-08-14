# Velociraptor36 Dongle Setup

The dongle is the USB central. Both keyboard halves are BLE peripherals.

## Firmware artifacts

The repo intentionally builds only the normal firmware set:

- `velociraptor36_left.uf2`: left keyboard half
- `velociraptor36_right.uf2`: right keyboard half
- `velociraptor36_dongle.uf2`: plain USB dongle
- `settings_reset_keyboard.uf2`: temporary reset image for the keyboard halves
- `settings_reset_dongle.uf2`: temporary reset image for the dongle

The left and right halves are built for `nice_nano_v2`, matching the firmware setup that worked
before the dongle work started. The dongle is built for `nice_nano`, matching the bootloader
reported by the Pro Micro nRF52840 clone:

```text
Model: nice!nano
Board-ID: nRF52840-nicenano
```

## First-time pairing

1. Turn off both keyboard halves.
2. Flash `settings_reset_dongle.uf2` to the dongle.
3. Flash `settings_reset_keyboard.uf2` to the left half and right half.
4. Flash `velociraptor36_dongle.uf2` to the dongle and keep it plugged into the Mac.
5. Flash `velociraptor36_left.uf2` to the left half, then power it on near the dongle.
6. Flash `velociraptor36_right.uf2` to the right half, then power it on near the dongle.
7. Allow several seconds for both halves to bond with the dongle.

The settings-reset image is only required when changing split roles, replacing a controller, or
recovering from broken split bonding. Normal firmware updates do not require it.

## OLED wiring

OLED support is intentionally disabled while the dongle boot issue is being isolated. Once
`velociraptor36_dongle.uf2` reliably appears as a USB keyboard, the OLED can be added back.

Expected OLED wiring for the next step:

- `SCK`/`SCL` -> `P0.20`
- `SDA` -> `P0.17`
- `GND` -> `GND`
- `VCC` -> a real `3.3V` pin

If the OLED has static, first verify that `VCC` is actually 3.3V. Some Pro Micro nRF52840 clones
require a solder bridge on the back of the board before the `3.3V` pin is powered.
