#include "Ser.h"
#include "../elementos/Agua.h"
#include <iostream>

Ser::Ser():Objeto(){
    objeto_referencia = new Agua(); //No me interesa el tipo de objeto, solo sus atributos
}

Ser::Ser(Casilla *casilla,char nombre, string ID):Objeto(casilla,nombre,ID){
    this -> armadura = obtener_numero_aleatorio(ARMADURA_MINIMA, ARMADURA_MAXIMA);
    this -> vida     = obtener_numero_aleatorio(VIDA_MINIMA, VIDA_MAXIMA);
    this -> energia  = obtener_numero_aleatorio(ENERGIA_MINIMA, ENERGIA_MAXIMA);
    this -> fuerza   = obtener_numero_aleatorio(FUERZA_MINIMA, FUERZA_MAXIMA);
}
Ser::~Ser(){
    delete objeto_referencia;
}

int Ser::devolver_armadura() {
    return this -> armadura;
}

int Ser::devolver_energia() {
    return this -> energia;
}

int Ser::devolver_fuerza(){
    return this -> fuerza;
}

int Ser::devolver_vida(){
    return this -> vida;
}

bool es_elemento(Objeto* objeto_a_comprobar) {

    return buscar_dato(NOMBRES_CHAR, MAX_NOMBRES,objeto_a_comprobar->obtener_nombre(),HUMANO) == NO_ENCONTRADO;
}

void Ser::quitar_vida(int puntos){
    this -> vida -= puntos;
}

void Ser::consumir_energia(int cantidad_gastada){
    this -> energia -= cantidad_gastada;
}


int calcular_vida_con_armadura(int vida_a_bajar){

    int vida_final_bajar;

    if(armadura == 0)
        vida_final_bajar = vida_a_bajar;
    else if(armadura == 1){
        vida_final_bajar = vida_a_bajar - ((vida_a_bajar * 10)/100);
    }
    else if(armadura == 2){
        vida_final_bajar = vida_a_bajar - ((vida_a_bajar * 20)/100);
    }
    else if(armadura == 3){
        vida_final_bajar = vida_a_bajar - ((vida_a_bajar * 80)/100);
    }
    return vida_final_bajar
}
