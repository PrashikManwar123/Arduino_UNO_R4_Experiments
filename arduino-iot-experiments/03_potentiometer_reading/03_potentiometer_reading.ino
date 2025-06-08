void setup() {
  Serial.begin(9600);  // Start the serial monitor at 9600 baud
}

void loop() {
  int sensorValue = analogRead(A0);  // Read value from A0
  Serial.println("Voltage across potentiometer is:");
  Serial.println((float(sensorValue)/1023)*5);       // Print the value to Serial Monitor
  delay(500);                        // Wait half a second
}
