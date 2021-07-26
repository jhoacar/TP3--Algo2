#ifndef VANESSA_H_DEFENSA_CAZADOR_H
#define VANESSA_H_DEFENSA_CAZADOR_H

#include "Defensa_humano.h"
#include "../../objetos/seres/humanos/cazador/Cazador.h"
class Defensa_cazador:public Defensa_humano {

    public:
    Defensa_cazador(Cazador *personaje);
    ~Defensa_cazador();
    void defender(int accion, Tablero*);
    void defender(){};
    void defender(int eleccion){};
    void defender(Tablero* tablero){};


};


#endif //VANESSA_H_DEFENSA_CAZADOR_H
