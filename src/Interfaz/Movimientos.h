//
// Created by agustin on 26/7/21.
//

#ifndef TP3_ALGO2_MOVIMIENTOS_H
#define TP3_ALGO2_MOVIMIENTOS_H

#include "../mapa/Coordenada.h"

const char ARRIBA    = 65;//'W';
const char ABAJO     = 66;//'S';
const char DERECHA   = 67;//'D';
const char IZQUIERDA = 68;//'A';


class Movimientos {
public:
    void mover_arriba_menu(Coordenada &posicion, int primera_opcion, int ultima_opcion);
    void mover_abajo_menu(Coordenada &posicion, int primera_opcion, int ultima_opcion);
    void mover_izquierda(Coordenada &posicion);
    void mover_derecha(Coordenada &posicion);
};


#endif //TP3_ALGO2_MOVIMIENTOS_H
