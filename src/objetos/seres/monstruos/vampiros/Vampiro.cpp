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

    if(casilla->eliminar_objeto(NOMBRES_CHAR[ESTACA]))
        cout << "Un vampiro ha eliminado una estaca del tablero" << endl;
}