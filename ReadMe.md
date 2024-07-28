# My Hitbox
## Hardware Used
- [18x] 3 x 8 mm round magnets
- [15x] Kailh Choc Low Profile Switches (v1)

## 3D Prints
Printed on a Prusa MK4 which has a print volume of 250 x 210 x 220 mm. Total print time for all pieces was about 12 hours.

- [Stickless Slimbox 2040m](https://www.printables.com/model/449392-slimbox-2040-stickless-all-button-low-profile-figh)
    - Modified in [Blender](https://www.blender.org/) to shrink the round magnet housings from 3x10mm to be 3x8mm. Also removed text to reduce the print time.
- [Kailh Choc Arcade Buttons](https://www.printables.com/model/148297-better-printed-arcade-button-kailh-choc-v1-low-pro)

## Flashing Firmware
The steps below are for flashing firmware to an Arduino Pro Micro (Arduino Micro).

1. Download latest [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases).
1. Run **QMK Toolbox** as administrator.
1. Install necessary drivers by navigating to **Tools** > **Install Drivers...**.
1. Restart **QMK toolbox**; doesn't have to be as administrator.
1. Ensure that the correct **MCU (AVR only)** is selected. **Example:** ATmega32U4
1. Click on the **Open** button and select the `MyHitbox.v1.hex` file.
1. Check the **Auto-Flash** checkbox.
1. Reset the board twice in rapid succession to enter the bootloader. 

## Development
- Firmware was developed and built using [Arduino IDE](https://www.arduino.cc/en/software).
- Build HEX file in **Arduino IDE** by navigating to **Sketch** > **Export Compiled Binary**.
    - Alt + Ctrl + S
    - HEX file needed is located at `build/arduino.avr.micro/MyHitbox.ino.hex`.
