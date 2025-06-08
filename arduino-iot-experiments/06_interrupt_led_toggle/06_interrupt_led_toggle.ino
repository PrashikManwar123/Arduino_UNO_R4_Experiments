volatile bool ledState = false;  // must be volatile for use in ISR

void setup() {
  pinMode(8, OUTPUT);            // LED pin
  pinMode(2, INPUT_PULLUP);      // Button pin with internal pull-up

  attachInterrupt(digitalPinToInterrupt(2), turnOnLED, FALLING);
  Serial.begin(9600);
}

void loop() {
  if (ledState) {
    digitalWrite(8, HIGH);       // Turn on LED if flag is true
  } else {
    digitalWrite(8, LOW);
  }
}

// ISR (Interrupt Service Routine)
void turnOnLED() {
  ledState = !ledState;
}
