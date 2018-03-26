int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);

  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // write sensor value to the serial interface
  Serial.println(sensorValue); //then open tools > serial monitor
  
  // LEDs off
  if (sensorValue == 1023) {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(9, LOW);

    delay(sensorValue);
  
    sensorValue = analogRead(sensorPin);
  } // LED 3 (3/4)
    else if (sensorValue <= 256) {
    digitalWrite(9, HIGH); 
    digitalWrite(6, HIGH);   
    digitalWrite(5, HIGH);
    delay(1000);             // wait for a second. if set to 1 ms, dim light without actually dimming
    digitalWrite(5, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);             // wait for a second
    sensorValue = analogRead(sensorPin);
  } // LED 2 (2/4)
    else if (sensorValue <= 512) {
    digitalWrite(9, LOW); 
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    delay(1000);             // wait for a second. if set to 1 ms, dim light without actually dimming
    digitalWrite(5, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);             // wait for a second
    sensorValue = analogRead(sensorPin);
  } // LED 1 (1/4)
    else if (sensorValue <= 768) {
    digitalWrite(9, LOW); 
    digitalWrite(6, LOW); 
    digitalWrite(5, HIGH);
    delay(1000);             // wait for a second. if set to 1 ms, dim light without actually dimming
    digitalWrite(5, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);             // wait for a second
    sensorValue = analogRead(sensorPin);
    
  }
  
}
