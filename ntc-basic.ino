/**
  Basic NTC Thermistor demo
  https://wokwi.com/arduino/projects/299330254810382858

  Assumes a 10K@25℃ NTC thermistor connected in series with a 10K resistor.

  Copyright (C) 2021, Uri Shaked
*/

const float BETA = 3950; // should match the Beta Coefficient of the thermistor
int LED_GREEN = 8;
int LED_YELLOW = 12;
int LED_RED = 13;

void setup() {
  Serial.begin(9600);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
}

void loop() {
  int analogValue = analogRead(A0);
  float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.println(" ℃");
  
  if (celsius < 30) {
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_RED, LOW);    
    digitalWrite(LED_YELLOW, LOW);   
  } else if (celsius > 80) {
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
  } else {
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_RED, LOW);    
    digitalWrite(LED_GREEN, LOW);   
  }

  delay(1000);
}
