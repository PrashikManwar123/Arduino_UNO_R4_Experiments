volatile bool ledState = false;  // must be volatile for use in ISR

void setup() {
  pinMode(8, OUTPUT);            // LED pin
  pinMode(2, INPUT_PULLUP);      // Button pin with internal pull-up. The pin reads HIGH normally, and becomes LOW when button is pressed.

  attachInterrupt(digitalPinToInterrupt(2), turnOnLED, FALLING); 
  // digitalPinToInterrupt(2) - initialises pin 2 to interrupt
  // turnOnLED - interrupt function to call 
  // FALLING - indicates that the interrupt will be executed during falling edge of pwm, i.e when pin2 goes from high to low 
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
