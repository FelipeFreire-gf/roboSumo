//
// Classe MotorDC
// arquivo hpp

#ifndef MOTORDC
#define MOTORDC

#include <Arduino.h>

class MotorDC{
  public:
    MotorDC(const uint8_t pin);

    void motorOn();
    void motorOff();
    void motorPWM(uint8_t duty=50);

  private:
    const uint8_t _pin;
    uint8_t _duty;  

}; //end class

#endif