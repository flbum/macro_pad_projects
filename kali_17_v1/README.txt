Making my first macro pad

kali_17: a 17 key custom 4x5 numpad with additional buttons above it. I handwired using 4 cols and 5 rows.
Step 1. Created a new keyboard called kali_17
	Build command: qmk compile -kb kali_17 -km default
	Project Location: C:/Users/mjenk/qmk_firmware/keyboards/kali_17

	Now update the config files to match the hardware!

Step 2. Figure out Column and row matrix. 
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

//{
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