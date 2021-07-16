#include "Monstruo.h"
#include <iostream>
using std::cout;
using std::endl;
Monstruo::Monstruo():Ser(){

}
Monstruo::Monstruo(Casilla *casilla,char nombre,string ID):Ser(casilla,nombre,ID)
{
}
void Monstruo::mostrar(){
    cout<<"Objeto: Monstruo "<<endl;
}
Monstruo::~Monstruo()
{
}

bool es_agua(Objeto* objeto_a_comprobar) {

    return objeto_a_comprobar ->obtener_nombre() == NOMBRES_CHAR[AGUA];
}

bool es_estaca(Objeto* objeto_a_comprobar){
    return objeto_a_comprobar->obtener_nombre() == NOMBRES_CHAR[ESTACA];
}
