//
// Created by franco on 7/7/2021.
//

#include "Ataque.h"


bool Ataque::energia_suficiente(int minimo, int fuerza) {

    if(energia_actual >= minimo){
        validacion_ataque = true;
    }

}

Ataque::Ataque(){

    tablero = 0;
    coordenada_x_actual = 0;
    coordenada_y_actual = 0;
    fuerza_actual = 0;

}

Ataque::Ataque(Tablero* tablero, int coordenada_x, int coordenada_y, int energia_actual){

    this -> tablero = tablero;
    coordenada_x_actual = coordenada_x;
    coordenada_y_actual = coordenada_y;
    this -> energia_actual = energia_actual;
}



bool Ataque::validacion_rango_ataque(int coord_x, int coord_y, int max_rango){

    bool rango_valido = false;
    int resta_coord_x = abs(coord_x - coordenada_x_actual);
    int resta_coord_y = abs(coord_y - coordenada_y_actual);
    
    if((resta_coord_x <= max_rango && resta_coord_x > 0) || (resta_coord_y <= max_rango && resta_coord_x > 0)){
        rango_valido = true;
    }

    return rango_valido;
}


bool Ataque::validacion_rango_ataque_estaca(int coord_x, int coord_y, int max_rango){

    bool rango_valido = false;
    int resta_coord_x = abs(coord_x - coordenada_x_actual);
    int resta_coord_y = abs(coord_y - coordenada_y_actual);

    if(((resta_coord_x <= max_rango) && (resta_coord_x > 0) && (coordenada_y_actual == coord_y)) || ((resta_coord_y <= max_rango) && (resta_coord_x > 0)&& (coordenada_y_actual == coord_y))){
        rango_valido = true;
    }

    return rango_valido;
}
	
