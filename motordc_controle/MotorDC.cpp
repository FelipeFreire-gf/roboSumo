//
// Classe MotorDC
// arquivo cpp

#include "MotorDC.hpp"

    MotorDC::MotorDC(const uint8_t pin): _pin(pin), _duty(128) {
      pinMode(_pin, OUTPUT);
      digitalWrite(_pin, LOW);
    }


    void MotorDC::motorOn(){
      digitalWrite(_pin, HIGH);

    }

    void MotorDC::motorOff(){
      digitalWrite(_pin, LOW);

    }
    void MotorDC::motorPWM(uint8_t duty){
      _duty = map(duty, 0, 100, 0, 255);
      analogWrite(_pin, _duty);
    }
