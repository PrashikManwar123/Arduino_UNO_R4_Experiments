const int potPin = A0;     // Potentiometer connected to A0
const int ledPin = 9;      // LED connected to PWM pin 9

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin);          // Read value (0–1023)
  int brightness = map(potValue, 0, 1023, 0, 255); // Scale to 0–255 for PWM
  analogWrite(ledPin, brightness);            // Set LED brightness
  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(" -> Brightness: ");
  Serial.println(brightness);
  delay(200);
}
