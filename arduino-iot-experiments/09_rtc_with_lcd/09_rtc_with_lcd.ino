#include <Wire.h>
#include <Arduino.h>
#include <uRTCLib.h>
#include "Waveshare_LCD1602_RGB.h"

// Initialize RTC at I2C address 0x68 (DS3231)
uRTCLib rtc(0x68);

// Initialize the Waveshare 1602 RGB LCD (16 cols, 2 rows)
Waveshare_LCD1602_RGB lcd(16, 2);

void setup() {
  delay(2000);
  Serial.begin(9600);
  Serial.println("Serial OK");

  URTCLIB_WIRE.begin();  // I2C initialization for RTC

  rtc.set(00, 52, 11, 1, 9, 6, 25);  
  // rtc.set(second, minute, hour, dayOfWeek, day, month, year)

  lcd.init();                // Initialize LCD
  lcd.setRGB(0, 255, 0);     // Set backlight to green
  lcd.clear();               // Clear screen
}

void loop() {
  rtc.refresh();  // Update RTC values

  // --- Serial Monitor Output ---
  Serial.print("RTC DateTime: ");
  Serial.print(rtc.year()); Serial.print('/');
  Serial.print(rtc.month()); Serial.print('/');
  Serial.print(rtc.day()); Serial.print(" ");
  Serial.print(rtc.hour()); Serial.print(':');
  Serial.print(rtc.minute()); Serial.print(':');
  Serial.print(rtc.second());
  Serial.print(" DOW: ");
  Serial.print(rtc.dayOfWeek());
  Serial.print(" - Temp: ");
  Serial.println(rtc.temp() / 100);

  // --- LCD Output ---
  lcd.clear();

  // Line 1: Time (hh:mm:ss)
  lcd.setCursor(0, 0);
  lcd.send_string("Time: ");
  if (rtc.hour() < 10) lcd.send_string("0");
  lcd.send_string(String(rtc.hour()).c_str());
  lcd.send_string(":");
  if (rtc.minute() < 10) lcd.send_string("0");
  lcd.send_string(String(rtc.minute()).c_str());
  lcd.send_string(":");
  if (rtc.second() < 10) lcd.send_string("0");
  lcd.send_string(String(rtc.second()).c_str());

  // Line 2: Date (dd/mm/yy)
  lcd.setCursor(0, 1);
  lcd.send_string("Date: ");
  if (rtc.day() < 10) lcd.send_string("0");
  lcd.send_string(String(rtc.day()).c_str());
  lcd.send_string("/");
  if (rtc.month() < 10) lcd.send_string("0");
  lcd.send_string(String(rtc.month()).c_str());
  lcd.send_string("/");
  lcd.send_string(String(rtc.year()).c_str());

  delay(1000);
}
