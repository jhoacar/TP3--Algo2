#ifndef VANESSA_H_DEFENSA_NOSFERATU_H
#define VANESSA_H_DEFENSA_NOSFERATU_H

#include "Defensa_vampiro.h"
#include "../../../../objetos/seres/monstruos/vampiros/Nosferatu.h"


class Defensa_nosferatu:public Defensa_vampiro {

public:
    Defensa_nosferatu(Nosferatu *personaje);
    ~Defensa_nosferatu();
    void defender(Tablero* tablero);
    void defender(){};
    void defender(int eleccion){};
    void defender(int accion, Tablero*){};

    bool validar_vampiro_cercano(Tablero* tablero);
    bool se_enuentra_nosferatu(Casilla* casilla);

    Lista<Casilla *> obtener_casilla_con_personaje(Lista<Casilla *> lista_casillas);


};


#endif //VANESSA_H_DEFENSA_NOSFERATU_H
