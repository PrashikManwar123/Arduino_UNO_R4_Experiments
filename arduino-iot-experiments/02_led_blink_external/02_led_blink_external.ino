const int LED=2; //initialised LED at pin 2

void setup(){
  pinMode(LED, OUTPUT); //LED is set as output pin
}
 
 
void loop(){
  digitalWrite(LED, HIGH); //turns on the LED
  delay(500); //500ms
  digitalWrite(LED, LOW); //turns off the LED
  delay(500); //500ms
}
