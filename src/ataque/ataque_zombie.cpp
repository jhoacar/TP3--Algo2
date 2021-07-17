#include "ataque_zombie.h"


Ataque_zombie::Ataque_cazador(Tablero* tablero, int coordenada_x, int coordenada_y, int energia_actual):Ataque(tablero, coordenada_x, coordenada_y,energia_actual){

    this -> tablero = tablero;
    this -> coordenada_x_actual = coordenada_x;
    this -> coordenada_y_actual = coordenada_y;
    this -> energia_actual = energia_actual;
}


Ataque_zombie::Ataque_cazador(){
}