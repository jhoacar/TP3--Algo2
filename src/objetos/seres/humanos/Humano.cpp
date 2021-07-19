#include "Humano.h"
#include "../../../defensa/tipos/Defensa_humano.h"
#include <iostream>
using std::cout;
using std::endl;

Humano::Humano():Ser(){
	this->armadura_aumentada = false;
    this->defensa = new Defensa_humano(this);
    this->ataque = new Ataque_humano(this);
}

Humano::Humano(Casilla *casilla,char nombre,string ID):Ser(casilla,nombre,ID)
{
	this->armadura_aumentada = false;
}

void Humano::mostrar(){
    cout<<"Objeto: Humano "<<endl;
}

Humano::~Humano()
{

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
