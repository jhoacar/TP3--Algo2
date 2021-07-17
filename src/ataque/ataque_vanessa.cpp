#include "ataque_vanessa.h"


Ataque_vanessa::Ataque_vanessa(Tablero* tablero, int coordenada_x, int coordenada_y, int energia_actual):Ataque(tablero, coordenada_x, coordenada_y,energia_actual){

    this -> tablero = tablero;
    this -> coordenada_x_actual = coordenada_x;
    this -> coordenada_y_actual = coordenada_y;
    this -> energia_actual = energia_actual;
}


Ataque_vanessa::Ataque_vanessa(){
}



void Ataque_vanessa::bajar_vida(Lista<Objeto*> lista_objetos, Casilla* casilla, string arma_usada) {

    int indice_zombie = indice_personaje(NOMBRES_STRING[ZOMBIE], lista_objetos);
    int indice_vampiro = indice_personaje(NOMBRES_STRING[VAMPIRO], lista_objetos);
    int indice_nosferatu = indice_personaje(NOMBRES_STRING[NOSFERATU], lista_objetos);
    int indice_vampirella = indice_personaje(NOMBRES_STRING[VAMPIRELLA], lista_objetos);

    int valor_ataque;

    if(arma_usada == NOMBRES_STRING[ESCOPETA]) {
        if (indice_zombie != -1) {
            valor_ataque = calcular_porcentaje_fuerza(fuerza, 125);
            valor_final = calcular_vida_con_armadura(valor_ataque);
            lista_objetos[indice] -> quitar_vida(valor_final);
        } else if (indice_vampiro != -1 || indice_nosferatu || indice_vampirella != -1) {
            valor_ataque = calcular_porcentaje_fuerza(fuerza, 40);
            valor_final = calcular_vida_con_armadura(valor_ataque);
            lista_objetos[indice] -> quitar_vida(valor_final);
        }
    }
    if(arma_usada == NOMBRES_STRING[AGUA]) {
        if (indice_vampiro != -1 || indice_nosferatu != -1 || indice_vampirella != -1){
            valor_ataque = 20;
            valor_final = calcular_vida_con_armadura(valor_ataque);
            lista_objetos[indice] -> quitar_vida(valor_final);
        }

    }
    if(arma_usada == NOMBRES_STRING[ESTACA]) {
        if (indice_zombie != -1) {
            valor_ataque = calcular_porcentaje_fuerza(fuerza, 25);
            valor_final = calcular_vida_con_armadura(valor_ataque);
            lista_objetos[indice] -> quitar_vida(valor_final);
        } else if (indice_vampiro != -1 || indice_nosferatu || indice_vampirella != -1) {
            int vida_vampiro = lista_objetos[indice] -> devolver_vida();
            valor_final = calcular_vida_con_armadura(vida_vampiro);
            lista_objetos[indice] -> quitar_vida(valor_final);
        }
    }
}

