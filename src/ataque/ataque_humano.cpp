//
// Created by franco on 7/7/2021.
//

#include "ataque_humano.h"
#include <stdlib.h>


Ataque_humano::Ataque_humano(Tablero* tablero, int coordenada_x, int coordenada_y, int energia_actual):Ataque(tablero, coordenada_x, coordenada_y,energia_actual){

    this -> tablero = tablero;
    this -> coordenada_x_actual = coordenada_x;
    this -> coordenada_y_actual = coordenada_y;
    this -> energia_actual = energia_actual;
}


Ataque_humano::Ataque_humano(){
}


void Ataque_humano::bajar_vida(Lista<Objeto*> lista_objetos, Casilla* casilla){
	
	int indice_zombie = indice_personaje(NOMBRES_STRING[ZOMBIE], lista_objetos);
	int indice_vampiro = indice_personaje(NOMBRES_STRING[VAMPIRO], lista_objetos);
	int indice_nosferatu = indice_personaje(NOMBRES_STRING[NOSFERATU], lista_objetos);
	int indice_vampirella = indice_personaje(NOMBRES_STRING[VAMPIRELLA], lista_objetos);
	
	int valor_ataque;

	if(indice_zombie != -1) {
        valor_ataque = calcular_porcentaje_fuerza(fuerza, 100);
        valor_final = calcular_vida_con_armadura(valor_ataque);
        lista_objetos[indice] -> quitar_vida(valor_final);
    }
	else if(indice_vampiro != -1 || indice_nosferatu != -1 || indice_vampirella != -1){
		valor_ataque = calcular_porcentaje_fuerza(fuerza, 20);
        valor_final = calcular_vida_con_armadura(valor_ataque);
		lista_objetos[indice] -> quitar_vida(valor_final);
	}

		
}




