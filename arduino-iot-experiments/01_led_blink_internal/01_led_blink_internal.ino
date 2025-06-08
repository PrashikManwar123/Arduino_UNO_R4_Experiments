void setup(){
  pinMode(LED_BUILTIN, OUTPUT); //LED_BUILTIN is set as output pin
}
 
void loop(){
  digitalWrite(LED_BUILTIN, HIGH); //turns on the LED_BUILTIN 
  delay(500); //500ms
  digitalWrite(LED_BUILTIN, LOW); //turns off the LED_BUILTIN 
  delay(500); //500ms
}

