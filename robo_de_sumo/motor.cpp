#include <Arduino.h>
#include "motor.h"

Motor::Motor(int _pinIN1, int _pinIN2, int _canal1, int _canal2, int _frquencia, int _resolucao):
    pinIN1(_pinIN1), pinIN2(_pinIN2), canal1(_canal1), canal2(_canal2), frequencia(_frquencia), resolucao(_resolucao)
{
    config();
};

void Motor::config(){
    // 8 = 255
    // 9 = 510    
    ledcAttachChannel(pinIN1, frequencia, resolucao, canal1);
    ledcAttachChannel(pinIN2, frequencia, resolucao, canal2);
};

void Motor::setPWM(int velocidade){
    if (velocidade > 0){
        ledcWrite(pinIN1, velocidade); // sentido frente
        ledcWrite(pinIN2, 0);          // parar
    }           
    else if (velocidade > 0){
        ledcWrite(pinIN2, (-1)*velocidade); // sentido tras
        ledcWrite(pinIN1, 0);              // parar
    }else{
        ledcWrite(pinIN1, 0);
        ledcWrite(pinIN2, 0);
    }
};
