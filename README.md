# Macro Pad Projects

This repository contains a collection of custom macro pads and keyboards built using QMK firmware. These are personal projects ranging from simple macro pads to more complex split keyboards.

## Projects Included

- **bum_deck**: A compact macro pad with custom key mappings.
- **champ_deck**: Another macro pad design with unique features.
- **leroy**: A hand-wired 8-key macro pad with 2 rotary encoders.
- **sh17**: A 17-key numpad-style macro pad, handwired.
- **sh6r2**: A smaller macro pad project.
- **split_keebs**: Split keyboard designs, including the bum_36 split keyboard.

## Getting Started

To build any of these keyboards, you'll need to set up a QMK development environment. Follow the [QMK setup guide](https://docs.qmk.fm/#/getting_started_build_tools).

Each keyboard has its own directory with configuration files. Navigate to the keyboard's folder and use QMK commands like:

```
qmk compile -kb <keyboard_name> -km default
```

For flashing, use:

```
qmk flash -kb <keyboard_name> -km default
```

## Contributing

Feel free to fork and modify these designs. If you have improvements or questions, open an issue or pull request.

## License

This project is licensed under the GNU General Public License v2.0 - see the [LICENSE](LICENSE) file for details.
