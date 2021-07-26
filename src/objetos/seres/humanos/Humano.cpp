#include "Humano.h"
#include "../../../defensa/tipos/Defensa_humano.h"
#include "../../../ataque/Ataque_humano.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

Humano::Humano():Ser(){
	this->armadura_aumentada = false;
    ataque= nullptr;
}

Humano::Humano(Casilla *casilla,char nombre,string ID):Ser(casilla,nombre,ID)
{
	this->armadura_aumentada = false;
    ataque = nullptr;
}

void Humano::mostrar(){
    cout<<"Objeto: Humano "<<endl;
}

Humano::~Humano()
{
if(ataque != nullptr)
    delete ataque;
}

void Humano::regenerar_energia() {
    this -> energia += 5;
}

void Humano::encuentro_con_elemento() {

    Lista<Objeto*> objetos_casilla;
    Lista<Objeto*> solo_elementos;

    objetos_casilla = casilla->obtener_objetos();
    solo_elementos = objetos_casilla.filtrar_datos(0,es_elemento);

    inventario += solo_elementos;

    if(solo_elementos.obtener_tamano()>0)
        cout << "Se agregaron con exito los elementos al inventario" << endl;

    casilla->eliminar_objetos(solo_elementos);
}

bool Humano::validacion_ataque(Casilla *casilla, Tablero* tablero){
    if(ataque == nullptr)
        this -> ataque = new Ataque_humano(this);
    return ataque -> validacion_atacar_personaje(casilla, tablero);
}

void Humano::atacar(Casilla *casilla, Tablero* tablero){
    if(ataque == nullptr)
        this -> ataque = new Ataque_humano(this);
    ataque -> atacar(casilla, tablero);
}


void Humano::defender(int eleccion){
    if(defensa == nullptr)
        this -> defensa = new Defensa_humano(this);
    defensa -> defender(eleccion);
}

bool Humano::validacion_defensa(int valor){
    if(defensa == nullptr)
        this -> defensa = new Defensa_humano(this);
    return defensa -> validar_energia(valor);
}




void Humano::atacar(Casilla *casilla, Tablero* tablero, char arma){
}


int Humano::elegir_accion() {
    int opcion;
    cout << "Tengo agua bendita en mi inventario." << endl;
    cout << "¿Qué debo hacer?" << endl;
    cout << "(1) Regenerar toda mi energía." << endl;
    cout << "(2) Aumentar mi armadura." << endl;
    cin >> opcion;
    while (opcion != REGENERAR_ENERGIA  && opcion != AUMENTAR_ARMADURA ){
        cout << "No lo entiendo. ¿Qué debo hacer?" << endl;
        cin >> opcion;
    }
    return opcion;
}


void Humano::aumentar_energia() {
    energia +=3;
}

void Humano::aumentar_armadura() {
    armadura++;
    armadura_aumentada = true;
}


void Humano::regenerar_energia_defensa() {
    energia += 3;
}


void Humano::regeneracion_maxima_energia(int maximo){
    energia = maximo;
}

void Humano::frenar_transformacion(){
    en_transformacion = false;
}
