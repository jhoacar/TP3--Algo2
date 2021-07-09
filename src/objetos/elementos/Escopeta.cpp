#include "Escopeta.h"
#include <iostream>
using std::cout;
using std::endl;
Escopeta::Escopeta():Elemento(){
    
}
Escopeta::Escopeta(Casilla *casilla,char nombre,int cantidad):Elemento(casilla,nombre,cantidad)
{
}
void Escopeta::mostrar(){
    cout<<"Objeto - Escopeta"<<endl;
}
Escopeta::~Escopeta()
{
}
