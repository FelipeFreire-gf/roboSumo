#include "MotorDC.hpp"

#define motorPin 6

MotorDC M1(motorPin);

void setup() {
 

}

void loop() {
 
 M1.motorOn();
 delay(500);

 M1.motorOff();
 delay(500);

}
