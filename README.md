# Arduino IoT Experiments

This repository contains a collection of beginner to intermediate level Arduino IoT experiments using Arduino Uno R4 Wifi Module. Each project demonstrates a specific concept using basic components like LEDs, buttons, potentiometers, sensors, and LCDs. Projects are organized in separate folders with their own `README.md` files and `.ino` source code.

---

## 🔧 List of Experiments

1. **LED Blink Internal** - Blink onboard LED using `LED_BUILTIN`.
2. **LED Blink External** - Blink an external LED connected to a digital pin.
3. **Potentiometer Reading** - Measure voltage across a potentiometer.
4. **Button Toggle LED** - Toggle LED state using a push button.
5. **Potentiometer LED Control** - Control LED brightness using a potentiometer.
6. **Interrupt LED Toggle** - Use hardware interrupts to toggle an LED.
7. **LCD Hello World** - Display a message on a Waveshare LCD1602 RGB screen.
8. **LCD Light Sensor Display** - Show ambient light sensor data on an LCD.

---

## 🧰 Components Used

| Component                          | Description                                               | Documentation Link |
|-----------------------------------|-----------------------------------------------------------|---------------------|
| [Arduino UNO R4 WiFi] | Microcontroller board with Wi-Fi and extended features     | [Arduino Docs](https://docs.arduino.cc/hardware/uno-r4-wifi) |
| [LED]     | Light Emitting Diode, used for visual signals              | [Blink Example](https://docs.arduino.cc/built-in-examples/basics/Blink/) |
| [Resistor]                   | Used to limit current to LEDs                              | |
| [Push Button] | Used to provide digital input                             | [Button Tutorial](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button) |
| [Potentiometer]        | Variable resistor to control analog signals                | [Potentiometer](https://docs.arduino.cc/learn/electronics/potentiometer-basics/) |
| [Waveshare LCD1602 RGB] | 16x2 LCD display module with RGB backlight support        | [Waveshare LCD Docs](https://www.waveshare.com/wiki/LCD1602_RGB_Module) |
| [DFRobot VEML7700] | High precision ambient light sensor                       | [VEML7700 Wiki](https://www.mouser.in/ProductDetail/DFRobot/SEN0228?qs=0lQeLiL1qyZRmybxFLEPOg%3D%3D&srsltid=AfmBOoorS9A9d0Slow7XvMIO676AEAR7UqTdO6TxNq46zONPNthIYIMp) |
| [Jumper Wires & Breadboard] | Used for circuit connections without soldering            | [Breadboard Info]([https://components101.com/misc/breadboard](https://learn.sparkfun.com/tutorials/how-to-use-a-breadboard/all)) |

---

## 📦 Folder Structure

Each experiment is located in its own subfolder.


Each folder contains:
- `README.md` – short description of the experiment
- `.ino` – Arduino code file

---

## ✅ Getting Started

1. Connect your **Arduino UNO R4 WiFi** to your computer.
2. Open the `.ino` file of your chosen experiment using the **Arduino IDE**.
3. Upload the code to your board.
4. Use the `Serial Monitor` or other components as required.

