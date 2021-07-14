#include "Escopeta.h"
#include <iostream>
using std::cout;
using std::endl;
Escopeta::Escopeta():Elemento(){
    
}
Escopeta::Escopeta(Casilla *casilla,char nombre,int cantidad,string ID):Elemento(casilla,nombre,cantidad,ID)
{
}
void Escopeta::mostrar(){
    cout<<"Objeto - Escopeta"<<endl;
}
Escopeta::~Escopeta()
{
}
