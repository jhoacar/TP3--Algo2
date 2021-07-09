#include "Monstruo.h"
#include <iostream>
using std::cout;
using std::endl;
Monstruo::Monstruo():Ser(){

}
Monstruo::Monstruo(Casilla *casilla,char nombre):Ser(casilla,nombre)
{
}
void Monstruo::mostrar(){
    cout<<"Objeto: Monstruo "<<endl;
}
Monstruo::~Monstruo()
{
}
