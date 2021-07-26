#ifndef VANESSA_H_DEFENSA_ZOMBIE_H
#define VANESSA_H_DEFENSA_ZOMBIE_H

#include "../../../Defensa.h"
#include "../../../../objetos/seres/monstruos/zombies/Zombie.h"
class Defensa_zombie: public Defensa {

public:
    Defensa_zombie(Zombie *personaje);
    ~Defensa_zombie();
    void defender();

    void defender(int eleccion){};
    void defender(Tablero* tablero){};
    void defender(int accion, Tablero*){};

};


#endif //VANESSA_H_DEFENSA_ZOMBIE_H
