#include "Cazador.h"
#include <iostream>
using std::cout;
using std::endl;
Cazador::Cazador():Humano(){

}
Cazador::Cazador(Casilla *casilla,char nombre,string ID):Humano(casilla,nombre,ID){
}
void Cazador::mostrar(){
    cout<<"Objeto: Cazador"<<endl;
}
Cazador::~Cazador()
{
}

void Cazador::regenerar_energia() {
    this -> energia += 8;
}
