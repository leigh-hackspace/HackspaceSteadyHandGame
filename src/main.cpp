#include <Arduino.h>
const int steadyHandPin = 12;
const int resetPin = 11;
const int alarmPin = 10;
bool latch;
void setup() {
    Serial.begin(9600);
    //Init Pins
    pinMode(alarmPin, OUTPUT);
    pinMode(resetPin, INPUT);
    pinMode(steadyHandPin, INPUT);
    //Set up latch
    latch = false;
}

void loop() {
  if(digitalRead(steadyHandPin)==HIGH){
    Serial.println("You touched the wire! Oh No!");
    latch = true;
  }

  if(digitalRead(resetPin) == HIGH){
    Serial.println("So you're going to try again!");
    latch = false;
  }

  if (latch){
    digitalWrite(alarmPin, HIGH);
  }else{
    digitalWrite(alarmPin, LOW);
  }

}
