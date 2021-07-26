#ifndef VANESSA_H_DEFENSA_VANESA_H
#define VANESSA_H_DEFENSA_VANESA_H


#include "Defensa_humano.h"
#include "../../objetos/seres/humanos/cazador/Vanessa.h"

class Defensa_vanesa: public Defensa_humano {

public:
    Defensa_vanesa(Vanessa *personaje);
    ~Defensa_vanesa();
    void defender(Tablero* tablero);

    void defender(){};
    void defender(int eleccion){};
    void defender(int accion, Tablero*){};



};


#endif //VANESSA_H_DEFENSA_VANESA_H
