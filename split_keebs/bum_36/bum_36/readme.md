# bum_36

![bum_36](imgur.com image replace me!)

#*A short description of the keyboard/project*

# bum_36 Split Keeb

#### Steps to building this board
I first started with some major hand pain after setting up mealie in a docker container, and then training a gpt to parse my recipes properly. I had some aching from my hands being twisted like a tiny dancer all day.

I ended up deciding to go with a 36 key layout, with the addition of 2 encoders from the suggestion of my wife.

Once I decided on the layout, I designed the board without the encoder first in KLE, then I transfered the json/raw to the Plate & Case Builder - swillkb to generate a *dfx* file. I took the file and uploaded it into Autodesk Fusion and designed a plate and case around the layout. I added the encoder after the fact, and then implemented it into the KLE.

The next step was to 3D print the plates. Once they were printed I determined the matrix I wanted to use, and soldered the columns first. I then wound up the diodes and soldered the rows. Once the switches were all wired up, I could turn my attention to the pro micros. I wired the rows, columns, encoder switches, and usb-c breakouts to each pro micro. I will include a wiring diagram eventually. Once everything is wired up, its time for firmware.

---
#### B.O.M
- (2) Arduino pro micro
- (2) USB-C 4 pin breakout board
- 36 Cherry mx switches
- 2 EC1101 Rotary encoders
- 38 N4148 diodes
- total pull up resistance between 2.2k and 10kOhms (ideal 4.7kOhm)
- 3D Printer
- 16ga Solid Copper wire
- 28ga stranded copper wire
- 70/30 solder
- clear heat shrink tubing cut into ~8mm strips
- (2) USB-C cable
- keycaps and rotary knobs
---

### Firmware
Start by setting up your environment according to your OS and the QMK docs.

Inside the qmk_firmware home folder, run qmk new-keyboard. This will generate default files for a new keyboard. Copy and paste into your project folder if you prefer to organize yourself.



### KLE Board Layout
![5d9c4527e19aa55d121784a453a30570.png](:/f106076ef757447c98fab82040ea83e3)


### [QMK SPLIT KEYBOARD](https://docs.qmk.fm/features/split_keyboard)

---
### Wiring pro micros for I2C
![a33ae3d908881b26e59a945478475315.png](:/31a1afdc7dc142eeb58355cb6608d7b7)

* Keyboard Maintainer: [flbum](https://github.com/flbum)
* Hardware Supported: *The PCBs, controllers supported*
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make bum_36:default

Flashing example for this keyboard:

    make bum_36:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
