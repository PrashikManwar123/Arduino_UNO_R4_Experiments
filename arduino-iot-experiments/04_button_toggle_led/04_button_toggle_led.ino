const int buttonPin = 2;     // Button connected to pin 2
const int ledPin = 13;       // LED connected to pin 13

bool ledState = false;       // LED ON/OFF
bool buttonPressed = false;  // Button press flag

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // Use internal pull-up resistor
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {  // Button pressed
    if (!buttonPressed) {
      delay(300); //this delay is introduced to prevent debouncing 
      ledState = !ledState;  // Toggle LED
      digitalWrite(ledPin, ledState ? HIGH : LOW);
      Serial.print("LED is now ");
      Serial.println(ledState ? "ON" : "OFF");
      buttonPressed = true;
    }
  } else {
    buttonPressed = false; // Reset flag when button is released
  }
}
