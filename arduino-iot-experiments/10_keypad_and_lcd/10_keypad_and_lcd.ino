#include <Wire.h>
#include "Waveshare_LCD1602_RGB.h"
#include "Adafruit_Keypad.h"

// LCD setup (16x2 display)
Waveshare_LCD1602_RGB lcd(16, 2);

// Define keys and keypad layout
const byte ROWS = 4; // 4 rows
const byte COLS = 4; // 4 columns

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};    // Connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 9, 10, 11};  // Connect to the column pinouts of the keypad

// Create the Keypad
Adafruit_Keypad customKeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  customKeypad.begin();

  // Initialize LCD
  lcd.init();
  lcd.setRGB(0, 255, 0);  // Green backlight
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.send_string("Press any key:");
}

void loop() {
  customKeypad.tick();

  while (customKeypad.available()) {
    keypadEvent e = customKeypad.read();

    if (e.bit.EVENT == KEY_JUST_PRESSED) {
      char key = (char)e.bit.KEY;
      Serial.print(key); Serial.println(" pressed");

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.send_string("Key Pressed:");
      lcd.setCursor(0, 1);
      lcd.send_string(String(key).c_str());
    }
  }

  delay(10);
}

