// Pot has 3 pins - Vcc, signal and GND

const int potPin = A0;     // Potentiometer connected to A0
const int ledPin = 9;      // LED connected to PWM pin 9

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin);          // The pot reading is stored in variable potValue. It reads value (0–1023)
  int brightness = map(potValue, 0, 1023, 0, 255); // analogWrite accepts the value from 0-255 only. Hence we scaled it as shown and stored the scaled value in var brightness.
  analogWrite(ledPin, brightness);            
  Serial.print("Potentiometer: ");
  Serial.print(potValue); // shows value from 0-1023 (2^10 levels)
  Serial.print(" -> Brightness: ");
  Serial.println(brightness); // shows value from 0-255 (2^8 levels)
  delay(200);
}
