const int buttonPin = 2;     // Button connected to pin 2 it is set as constant 
const int ledPin = 13;       // LED connected to pin 13 it is set as constant

bool ledState = false;       // this var keeps the track whether the LED is ON/OFF
bool buttonPressed = false;  // this var keeps the track whethter the button is pressed on not.

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // INPUT_PULLUP activates the internal pullup resistor in the Arduino. This is done to avoid the use of external resistor.
  // when buttonPressed is false -> pin reads high   
  // when buttonPressed is true -> pin reads low
  pinMode(ledPin, OUTPUT); 
  digitalWrite(ledPin, LOW); //turns off the LED at the startup
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {  // Button pressed
    // implementing debouncing logic: 
    if (!buttonPressed) {
      delay(300); //this delay is introduced to prevent debouncing 
      ledState = !ledState;  // Toggles the current LED state
      digitalWrite(ledPin, ledState ? HIGH : LOW); // Shows the output of ledState on LED connected to ledPin 
      Serial.print("LED is now ");
      Serial.println(ledState ? "ON" : "OFF");
      buttonPressed = true; //prevents the led from repeatedly toggling while the buttonPressed in true
    }
  } else {
    buttonPressed = false; // Reset buttonPressed when button is released
  }
}
