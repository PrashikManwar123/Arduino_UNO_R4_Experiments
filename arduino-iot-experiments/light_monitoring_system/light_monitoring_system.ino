#include <Wire.h>
#include "Waveshare_LCD1602_RGB.h"
#include <uRTCLib.h>
#include "DFRobot_VEML7700.h"
#include "Adafruit_Keypad.h"

// RTC
uRTCLib rtc(0x68);
// LCD
Waveshare_LCD1602_RGB lcd(16, 2);
// Light sensor
DFRobot_VEML7700 als;

// Keypad setup - manual configuration
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {8, 9, 10, 11};

// Initialize keypad instance
Adafruit_Keypad customKeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Interval for readings (default 5 seconds)
unsigned long intervalSeconds = 5;
unsigned long lastReadingTime = 0;

void setup() {
  Serial.begin(9600);
  delay(2000);
  
  // RTC init
  URTCLIB_WIRE.begin();
  rtc.refresh();
  
  // LCD init
  lcd.init();
  lcd.setRGB(0, 255, 0);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.send_string("Lux Monitor");
  
  // Sensor init
  als.begin();
  
  // Keypad init
  customKeypad.begin();
}

void loop() {
  rtc.refresh();
  unsigned long currentMillis = millis();
  unsigned long intervalMillis = intervalSeconds * 1000;
  
  // Check if it's time for next reading
  if ((currentMillis - lastReadingTime) >= intervalMillis) {
    lastReadingTime = currentMillis;
    
    float lux;
    als.getALSLux(lux);
    
    char buffer[17];
    snprintf(buffer, sizeof(buffer), "Lux: %.1f lx", lux);
    
    lcd.setCursor(0, 1);
    lcd.send_string("                ");  // clear line
    lcd.setCursor(0, 1);
    lcd.send_string(buffer);
    
    Serial.print("Reading taken at ");
    Serial.print(rtc.hour());
    Serial.print(":");
    Serial.print(rtc.minute());
    Serial.print(":");
    Serial.print(rtc.second());
    Serial.print(" -> Lux: ");
    Serial.println(lux);
  }
  
  // Keypad input to change interval
  customKeypad.tick();
  
  while (customKeypad.available()) {
    keypadEvent e = customKeypad.read();
    char key = (char)e.bit.KEY;
    
    if (e.bit.EVENT == KEY_JUST_PRESSED) {
      Serial.print("Key pressed: ");
      Serial.println(key);
      
      if (key >= '1' && key <= '9') {
        intervalSeconds = (key - '0') * 5;  // 5 to 45 seconds
        
        lcd.setCursor(0, 0);
        lcd.send_string("Set Int: ");
        char intBuffer[17];
        snprintf(intBuffer, sizeof(intBuffer), "%lu sec", intervalSeconds);
        lcd.send_string(intBuffer);
        delay(1000);  // Brief message display
        lcd.setCursor(0, 0);
        lcd.send_string("Lux Monitor     ");
      }
    }
  }
  
  delay(10); // Small delay for responsive keypad detection
}

