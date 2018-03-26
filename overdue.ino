// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(5, OUTPUT); //changes that pin to an output
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for 0.1 second. if set to 1 ms, dim light without actually dimming
  digitalWrite(5, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for 0.1 second
}
