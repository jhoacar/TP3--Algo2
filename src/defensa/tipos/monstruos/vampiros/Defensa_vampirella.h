#ifndef VANESSA_H_DEFENSA_VAMPIRELLA_H
#define VANESSA_H_DEFENSA_VAMPIRELLA_H


#include "Defensa_vampiro.h"
#include "../../../../objetos/seres/monstruos/vampiros/Vampirella.h"
class Defensa_vampirella:public Defensa_vampiro {

public:
    Defensa_vampirella(Vampirella *personaje);
    ~Defensa_vampirella();
    void defender();

     void defender(int eleccion){};
     void defender(Tablero* tablero) {};
     void defender(int accion, Tablero*){};

};


#endif //VANESSA_H_DEFENSA_VAMPIRELLA_H
