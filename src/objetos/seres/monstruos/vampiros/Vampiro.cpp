#include "Vampiro.h"
#include <iostream>

using std::cout;
using std::endl;

Vampiro::Vampiro():Monstruo(){
    
}
Vampiro::Vampiro(Casilla *casilla,char nombre,string ID):Monstruo(casilla,nombre,ID)
{
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

    for (int i = 0; i < solo_estaca . obtener_tamano(); i++)
        this -> casilla -> eliminar_objeto(solo_estaca[i]->obtener_ID());
    cout << "Se han destruido las estacas" << endl;
}