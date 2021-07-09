#include "Vampiro.h"
#include <iostream>
using std::cout;
using std::endl;
Vampiro::Vampiro():Monstruo(){
    
}
Vampiro::Vampiro(Casilla *casilla,char nombre):Monstruo(casilla,nombre)
{
}
void Vampiro::mostrar(){
    cout<<"Objeto: Vampiro"<<endl;
}
Vampiro::~Vampiro()
{
}
