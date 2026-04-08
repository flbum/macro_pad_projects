# leroy

![leroy](images/leroy_render.png)

*A hand-wired 8-key macro pad with 2 rotary encoders, built for personal use.*

* Keyboard Maintainer: [flbum](https://github.com/flbum)
* Hardware Supported: Arduino Pro Micro (Atmega32u4)
* Hardware Availability: Custom hand-wired build

Make example for this keyboard (after setting up your build environment):

    qmk compile -kb leroy -km vial

Flashing example for this keyboard:

    qmk flash -kb leroy -km vial

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 2 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset**: Briefly short the RST and GND pins