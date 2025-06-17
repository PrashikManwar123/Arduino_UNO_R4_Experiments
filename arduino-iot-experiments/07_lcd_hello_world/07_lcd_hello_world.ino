#include <Wire.h> // Library used for I2C communication
#include "Waveshare_LCD1602_RGB.h" // Library for LCD 

// Create LCD object with 16 columns and 2 rows
Waveshare_LCD1602_RGB lcd(16, 2);

void setup() {
  lcd.init();                    // Initialize the LCD
  lcd.setRGB(0, 255, 0);         // Set backlight color (green)
  lcd.clear();                   // Clear screen
  lcd.setCursor(0, 0);           // Set cursor to first row, first column
  lcd.send_string("Hello World!");  // Print message
}

void loop() {
  // empty
}
