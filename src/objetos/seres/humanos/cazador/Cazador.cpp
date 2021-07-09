#include "Cazador.h"
#include <iostream>
using std::cout;
using std::endl;
Cazador::Cazador():Humano(){

}
Cazador::Cazador(Casilla *casilla,char nombre):Humano(casilla,nombre){
}
void Cazador::mostrar(){
    cout<<"Objeto: Cazador"<<endl;
}
Cazador::~Cazador()
{
}