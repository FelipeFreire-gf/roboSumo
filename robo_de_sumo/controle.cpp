#include "controle.h"

Controle::Controle(Robo* _robo, int _velocidade): 
    robo(_robo), velocidade(_velocidade) 
{}

void Controle::frente(){                                    // Aciona os dois motores na velocidade maxima para frente
    robo->moveFoward(velocidade, velocidade);
}

void Controle::tras(){                                      // Aciona os dois motores na velocidade maxima para tras
    robo->moveFoward(-velocidade, -velocidade);
}

void Controle::esquerda(){                                  // Reduz a velocidade do motor da esquerda
    robo->moveFoward(velocidade/2, velocidade);
}

void Controle::direita(){                                   // Reduz a velocidade do motor da direita
    robo->moveFoward(velocidade, velocidade/2);
}

void Controle::stop(){                                      // Para os dois motores
    robo->Stop();
}