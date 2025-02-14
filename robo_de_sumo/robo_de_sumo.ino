#include "motor.h"
#include "robo.h"
#include "controle.h"

#define E_PIN_IN1 2
#define E_PIN_IN2 25
#define E_CANAL1 0 
#define E_CANAL2 1 

#define D_PIN_IN1 2
#define D_PIN_IN2 25
#define D_CANAL1 0 
#define D_CANAL2 1 

#define FREQUENCIA 5000 //5khz
#define RESOLUCAO 8     //8bits

Controle controle(&sumo, 100);

Motor motorDireito(D_PIN_IN1, D_PIN_IN2, D_CANAL1, D_CANAL2, FREQUENCIA, RESOLUCAO);
Motor motorEsquerdo(E_PIN_IN1, E_PIN_IN2, E_CANAL1, E_CANAL2, FREQUENCIA, RESOLUCAO);

Robo sumo(&motorEsquerdo, &motorDireito);

void notify(String comando)
{
    if (comando == "frente"){
        controle.frente();
    }
    else if (comando == "tras"){
        controle.tras();
    }
    else if (comando == "esquerda"){
        controle.esquerda();
    }
    else if (comando == "direita"){
        controle.direita();
    }
    else if (comando == "parar"){
        controle.parar();
    }
}

void setup()
{
    Serial.begin(115200);                                           // Comunicação serial para receber comandos
}

void loop()
{
    if (Serial.available() > 0){
        String comando = Serial.readStringUntil('\n');              // Lê o comando
        comando.trim();
        notify(comando);                                            // Usa o notify para comunicar o robo          
    }
}