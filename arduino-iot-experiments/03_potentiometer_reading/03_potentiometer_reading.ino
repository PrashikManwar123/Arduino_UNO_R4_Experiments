void setup() {
  Serial.begin(9600);  // Start the serial monitor at 9600 baud
}

void loop() {
  int sensorValue = analogRead(A0);  // Read analog value from A0
  // ADC has a resolution of 10 bits, so it produces values from 0 to 1023 (0 - 2^10)
  // sensorValue will contain analog value between 0 and 1023
  Serial.println("Voltage across potentiometer is:");
  Serial.println((float(sensorValue)/1023)*5);       // Print the value to Serial Monitor
  // Here, (float(sensorValue)/1023)*5 is the formula to convert digital value into a actual voltage values.
  delay(500);                        // Wait half a second
}
