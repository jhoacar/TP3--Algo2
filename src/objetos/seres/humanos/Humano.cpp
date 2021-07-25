#include "Humano.h"
#include "../../../defensa/Defensa_humano.h"
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

void Humano::defender() {
    
    if (!tengo_agua_bendita()){
        aumentar_energia();
        cout << "|||| No tengo agua bendita, pero aumenté mi energía ||||" << endl;
    }
    else {
        int accion = elegir_accion();
        if (accion == REGENERAR_ENERGIA){
            consumir_agua_bendita();
            cout << "|||| Regeneré mi energía ||||" << endl;
        }
        else{
            aumentar_armadura();
            cout << "|||| Mejoré mi armadura ||||" << endl;
        }
    }
}

bool Humano::tengo_agua_bendita() {
    objeto_referencia->asignar_nombre(NOMBRES_CHAR[AGUA]); //Le asigno el nombre que quiera buscar en la lista
    return inventario.existe(objeto_referencia,comparacion_por_nombre);
}

void Humano::aumentar_energia() {
    energia +=3;
}

void Humano::aumentar_armadura() {
    armadura++;
    armadura_aumentada = true;
}

void Humano::consumir_agua_bendita() {
    energia = ENERGIA_MAXIMA;
    inventario.borrar(buscar_agua_bendita());
}

bool Humano::tiene_armadura_aumentada() {
    return this->armadura_aumentada;
}

int Humano::buscar_agua_bendita() {

    objeto_referencia->asignar_nombre(NOMBRES_CHAR[AGUA]);
    return inventario.buscar_dato(0,objeto_referencia,comparacion_por_nombre);
}



