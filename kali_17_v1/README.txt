Making my first macro pad


//The first thing I did was research the kind of macropad I wanted. I believe I messed up because I wanted a
    numpad with an extra set of keys above the top row [7,8,9] but what I really wanted was the num_lock row with an additional
    row above it. Either way, this just allows me to make another macro pad for my fusion 360 shortcuts.

//I found out how to handwire a macropad, and I learned how to design my own key plate. 

//Designed and printed a case, hand wired in the switches into COLS AND ROWS

//Once everything was wired to the arduino pro micro I started working on the qmk_firmware and this is where we start with the tracking of the readme.


//kali_17: a 17 key custom 4x5 numpad with additional buttons above it. I handwired using 4 cols and 5 rows.
//Step 1. Created a new keyboard called kali_17
	Build command: qmk compile -kb kali_17 -km default
	Project Location: C:/Users/mjenk/qmk_firmware/keyboards/kali_17

	Now update the config files to match the hardware!

//Step 2. Figure out Column and row matrix. 
	col 0. black wire to pin 16   B2
	col 1. blue wire to pin 14    B3 
	col 2. green wire to pin 15   B1
	col 3. red wire to pin 18/A0  F7
	row 0. brown wire to pin 2    D1
	row 1. green wire to pin 3    D0
	row 2. white wire to pin 4    D4
	row 3. blue wire to pin 5     C6
	row 4. yellow wire to pin 6   D7

!!!!! https://docs.qmk.fm/newbs_building_firmware follow this when youre at work !!!!!

	KC_KP_0,   KC_KP_1,   KC_KP_5,   KC_KP_9,
        KC_NUM_LOCK,   KC_SLASH,   KC_KP_ASTERISK,   KC_KP_MINUS,
        KC_KP_7,   KC_KP_8,   KC_KP_9,
        KC_KP_4,   KC_KP_5,   KC_KP_6, KC_KP_PLUS,
        KC_KP_1,   KC_KP_2, KC_KP_3, 
        KC_KP_0,   KC_KP_DOT,   KC_KP_ENTER


.json file below

{
    "manufacturer": "Matt Jenkins",
    "keyboard_name": "kali_17",
    "maintainer": "flbum",
    "bootlaoder": "caterina",
    "development_board": "promicro",
    "diode_direction": "COL2ROW",
    "features": {
        "bootmagic": false,
        "command": false,
        "console": false,
        "extrakey": true,
        "mousekey": true,
        "nkro": true
    },
    "matrix_pins": {
        "cols": ["B2", "B3", "B1", "F7"],
        "rows": ["D1", "D0", "D4", "C6", "D7"]
    },
    "url": "",
    "usb": {
        "device_version": "1.0.0",
        "pid": "0x0000",
        "vid": "0xFEED"
    },
    "layouts": {
        "LAYOUT": {
            "layout": [
                //ROW 1
                {"matrix": [0, 0], "x": 0, "y": 0},
                {"matrix": [0, 1], "x": 1, "y": 0},
                {"matrix": [0, 2], "x": 2, "y": 0},
                {"matrix": [0, 3], "x": 3, "y": 0},

                //ROW 2
                {"matrix": [1, 0], "x": 0, "y": 1},
                {"matrix": [1, 1], "x": 1, "y": 1},
                {"matrix": [1, 2], "x": 2, "y": 1}

                //ROW 3
                {"matrix": [2, 0], "x": 0, "y": 2},
                {"matrix": [2, 1], "x": 1, "y": 2},
                {"matrix": [2, 2], "x": 2, "y": 2},
                {"matrix": [2, 3], "x": 3, "y": 2},

                //ROW 4
                {"matrix": [3, 0], "x": 0, "y": 3},
                {"matrix": [3, 1], "x": 1, "y": 3},
                {"matrix": [3, 2], "x": 2, "y": 3}

                //ROW 5
                {"matrix": [4, 0], "x": 0, "y": 4},
                {"matrix": [4, 1], "x": 1, "y": 4},
                {"matrix": [4, 2], "x": 2, "y": 4}
                
            ]
        }
    }
}




i think the next step will be to create a new keymap.
according to the qmk docs, I need to do that first.

//these are the codes to run

qmk new-keymap -kb kali_17

open keymap.c in vs codes

configure the keymap to match what you want the layout to be. 
Row 0 [S, A, LBRC, ESC]

        KC_S,   KC_A,   KC_LBRC,   KC_ESC,
        KC_KP_7,   KC_KP_8,   KC_KP_9,
        KC_KP_4,   KC_KP_5,   KC_KP_6, KC_KP_PLUS,
        KC_KP_1,   KC_KP_2, KC_KP_3, 
        KC_KP_0,   KC_KP_DOT,   KC_KP_ENTER

//FYI i had the layout all sorts of screwed up, perhaps thats where the error arose. It was a long day.


after this - build qmk_firmware


//this should build a hex file in the qmk folder somewhere. Will need to research more.
qmk compile -kb kali_17 -km default

if the hex file is compiled correctly, the next step is flashing the firmware. 

// follow the instructions via: https://docs.qmk.fm/newbs_flashing


