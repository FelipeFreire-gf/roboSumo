#include "motor.h"
#include "robo.h"
#include "controle.h"
#include <DabbleESP32.h>

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

#define E_PIN_IN1 18
#define E_PIN_IN2 19
#define E_CANAL1 0
#define E_CANAL2 1

#define D_PIN_IN1 21
#define D_PIN_IN2 22
#define D_CANAL1 2
#define D_CANAL2 3 

#define FREQUENCIA 5000 //5khz alteracao 5000 - 500 teste
#define RESOLUCAO 8     //8bits

Motor motorDireito(D_PIN_IN1, D_PIN_IN2, D_CANAL1, D_CANAL2, FREQUENCIA, RESOLUCAO);
Motor motorEsquerdo(E_PIN_IN1, E_PIN_IN2, E_CANAL1, E_CANAL2, FREQUENCIA, RESOLUCAO);

Robo sumo(&motorEsquerdo, &motorDireito);

Controle controle(&sumo, 2000);

void setup()
{
    Serial.begin(9600);                                           // Comunicação serial para receber comandos
    Dabble.begin("roboSumo-napoleao2");                                       // Nome do bluetooth
}

void loop()
{
   Dabble.processInput();                                       // Controle processa comando


    if (GamePad.isUpPressed()){                                 // Comando de seta para cima(anda para frente)
        controle.frente();
    }
    else if (GamePad.isDownPressed()){                          // Comando de seta para baixo(anda para tras)
        controle.tras();
    }
    else if (GamePad.isLeftPressed()){                          // Comando de seta para esquerda(vira para a esquerda)
        controle.esquerda();
    }
    else if (GamePad.isRightPressed()){                         // Comando de seta para direita(vira para a diretia)
        controle.direita();
    }
    else{                                                       // Se nenhum comando for dado o robo fica parado
        controle.stop();
    }
}