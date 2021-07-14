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
