#ifndef CONTROLE_H
#define CONTROLE_H

#include "robo.h"

class Controle{
    private:
        Robo* robo;
        int velocidade;
    public:
        Controle(Robo* _robo, int _velocidade);

        void frente();
        void tras();
        void esquerda();
        void direita();
        void stop();
};

#endif