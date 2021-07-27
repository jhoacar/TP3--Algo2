//
// Created by agustin on 26/7/21.
//

#include "Movimientos.h"


void Movimientos::mover_arriba_menu(Coordenada &posicion, int primera_opcion, int ultima_opcion){
    if (posicion.obtener_fila() != primera_opcion)
        posicion={(posicion.obtener_fila()-1),posicion.obtener_columna()};
    else
        posicion={ultima_opcion, posicion.obtener_columna()};
}

void Movimientos::mover_abajo_menu(Coordenada &posicion, int primera_opcion, int ultima_opcion){
    if (posicion.obtener_fila() != ultima_opcion)
        posicion={(posicion.obtener_fila()+1),posicion.obtener_columna()};
    else
        posicion={primera_opcion, posicion.obtener_columna()};
}

void Movimientos::mover_izquierda(Coordenada &posicion){
    posicion={posicion.obtener_fila(),posicion.obtener_columna()-1};
}

void Movimientos::mover_derecha(Coordenada &posicion){
    posicion={posicion.obtener_fila(),posicion.obtener_columna()+1};
}