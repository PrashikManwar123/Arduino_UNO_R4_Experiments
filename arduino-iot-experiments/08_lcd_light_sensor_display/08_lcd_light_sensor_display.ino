#include <Wire.h>
#include "Waveshare_LCD1602_RGB.h"
#include "DFRobot_VEML7700.h"

// Create LCD object with 16 columns and 2 rows
Waveshare_LCD1602_RGB lcd(16, 2);

// Create VEML7700 sensor object
DFRobot_VEML7700 als;

void setup() {
  Serial.begin(9600);

  // Initialize LCD
  lcd.init();
  lcd.setRGB(0, 255, 0);  // Green backlight
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.send_string("Ambient Light:");

  // Initialize sensor
  als.begin();  // Just call it, no if-condition
}

void loop() {
  float lux;
  als.getALSLux(lux);

  Serial.print("Lux: ");
  Serial.print(lux);
  Serial.println(" lx");

  // Create string for LCD
  char buffer[16]; //buffer is used to store a value temporarily before processing it 
  snprintf(buffer, sizeof(buffer), "Lux: %.1f lx", lux); 

  // Display on LCD second line
  lcd.setCursor(0, 1);
  lcd.send_string("                ");  // Clear old content
  lcd.setCursor(0, 1);
  lcd.send_string(buffer);

  delay(1000);
}

