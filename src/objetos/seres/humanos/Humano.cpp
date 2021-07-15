#include "Humano.h"
#include <iostream>
using std::cout;
using std::endl;

Humano::Humano():Ser(){

}
Humano::Humano(Casilla *casilla,char nombre,string ID):Ser(casilla,nombre,ID)
{
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

    objetos_casilla = this -> casilla ->obtener_objetos();
    solo_elementos = objetos_casilla.filtrar_datos(0, es_elemento);

    this ->inventario += solo_elementos;
    cout << "Se agregaron con exito los elementos al inventario" << endl;

    for (int i = 0; i < solo_elementos . obtener_tamano(); i++)
        this ->casilla -> eliminar_objeto(solo_elementos[i]->obtener_ID());
}