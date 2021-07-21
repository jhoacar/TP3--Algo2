#include "Vampiro.h"
#include <iostream>

using std::cout;
using std::endl;

Vampiro::Vampiro():Monstruo(){
    this->oculto = false;
    this->armadura_aumentada = false;
}
Vampiro::Vampiro(Casilla *casilla,char nombre,string ID):Monstruo(casilla,nombre,ID)
{
    this->oculto = false;
    this->armadura_aumentada = false;
}
void Vampiro::mostrar(){
    cout<<"Objeto: Vampiro"<<endl;
}
Vampiro::~Vampiro()
{
}

void Vampiro::regenerar_energia() {
    this -> energia += 4;
}

void Vampiro::encuentro_con_elemento() {

    Lista<Objeto*> objetos_casilla;
    Lista<Objeto*> solo_estaca;

    objetos_casilla = this -> casilla ->obtener_objetos();
    solo_estaca = objetos_casilla.filtrar_datos(0, es_estaca);

    this -> casilla -> eliminar_objetos(solo_estaca);
    cout << "Se han destruido las estacas" << endl;
}

void Vampiro::defender() {
    this->energia -=4;
    this->ocultarse();
}
void Vampiro::atacar(Casilla *casilla){

}

void Vampiro::ocultarse() {
    this->oculto = true;
}

void Vampiro::aparecer() {
    this->oculto = false;
}

bool Vampiro::tiene_armadura_aumentada() {
    return this->armadura_aumentada;
}
