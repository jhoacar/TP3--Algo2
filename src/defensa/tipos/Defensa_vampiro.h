#ifndef VANESSA_H_DEFENSA_VAMPIRO_H
#define VANESSA_H_DEFENSA_VAMPIRO_H

#include "../Defensa.h"
#include "../../objetos/seres/monstruos/vampiros/Vampiro.h"

class Defensa_vampiro:public Defensa{


public:
    Defensa_vampiro(Vampiro *personaje);
    ~Defensa_vampiro();
    void defender();

    void defender(int eleccion){};
    void defender(Tablero* tablero){};
    void defender(int accion, Tablero*){};



};


#endif //VANESSA_H_DEFENSA_VAMPIRO_H
