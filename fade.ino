int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
int ledPin = 5;    // LED connected to digital pin 5

void setup() {
  // nothing happens in setup
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // write sensor value to the serial interface
  Serial.println(sensorValue); //then open tools > serial monitor

  // LEDs off
  if (sensorValue == 1023) {
//    digitalWrite(5, LOW);
    analogWrite(5, (1023-sensorValue)/4);
    digitalWrite(6, LOW);
    digitalWrite(9, LOW);

    delay(sensorValue);
  
    sensorValue = analogRead(sensorPin);
  } // LED 3 (3/4)
    else if (sensorValue <= 256) {
    digitalWrite(9, HIGH);    
    digitalWrite(6, HIGH);
    analogWrite(5, (1023-sensorValue)/4);
//    digitalWrite(5, HIGH);
    sensorValue = analogRead(sensorPin);
  } // LED 2 (2/4)
    else if (sensorValue <= 512) {
    digitalWrite(9, LOW);  
    digitalWrite(6, HIGH);
    analogWrite(5, (1023-sensorValue)/4);
//    digitalWrite(5, HIGH);
    sensorValue = analogRead(sensorPin);
  } // LED 1 (1/4)
    else if (sensorValue <= 768) {
    digitalWrite(9, LOW);  
    digitalWrite(6, LOW);  
    analogWrite(5, (1023-sensorValue)/4);
//    digitalWrite(5, HIGH);
    sensorValue = analogRead(sensorPin);
    
    }
}
