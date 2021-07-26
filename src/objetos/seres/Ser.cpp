#include "Ser.h"
//#include "Humano.h"
#include "../elementos/Agua.h"
bool es_elemento(Objeto* objeto_a_comprobar) {
    return buscar_dato(NOMBRES_CHAR, MAX_NOMBRES,objeto_a_comprobar->obtener_nombre(),HUMANO) == NO_ENCONTRADO;
}

Ser::Ser():Objeto(){
    objeto_referencia = new Agua(); //No me interesa el tipo de objeto, solo sus atributos
}

Ser::Ser(Casilla *casilla,char nombre, string ID):Objeto(casilla,nombre,ID){
    this -> armadura = obtener_numero_aleatorio(ARMADURA_MINIMA, ARMADURA_MAXIMA);
    this -> vida     = obtener_numero_aleatorio(VIDA_MINIMA, VIDA_MAXIMA);
    this -> energia  = obtener_numero_aleatorio(ENERGIA_MINIMA, ENERGIA_MAXIMA);
    this -> fuerza   = obtener_numero_aleatorio(FUERZA_MINIMA, FUERZA_MAXIMA);
    objeto_referencia = new Agua(); //No me interesa el tipo de objeto, solo sus atributos
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

void Ser::asignar_armadura(int armadura) {
    this -> armadura = armadura;
}

void Ser::asignar_energia(int energia) {
    this -> energia = energia;
}

void Ser::asignar_fuerza(int fuerza){
    this -> fuerza = fuerza;
}

void Ser::asignar_vida(int vida){
    this -> vida = vida;
}

Lista<Objeto*> Ser::obtener_inventario(){
    return this -> inventario;
}
void Ser::aumentar_armadura(){
    this -> armadura += 1;
}



void Ser::bajar_vida(int cantidad){
    this -> vida -= cantidad;
}




void Ser::consumir_energia(int cantidad_gastada){
    this -> energia -= cantidad_gastada;
}


int Ser::calcular_vida_con_armadura(int vida_a_bajar){

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
    return vida_final_bajar;
}


void Ser::regenerar_vida_defensa(int vida_a_sumar){
    vida += vida_a_sumar;
}