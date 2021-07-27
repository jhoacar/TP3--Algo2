#include "Monstruo.h"
#include <iostream>
using std::cout;
using std::endl;
Monstruo::Monstruo():Ser(){
    this->oculto=false;
}
Monstruo::Monstruo(Casilla *casilla,char nombre,string ID):Ser(casilla,nombre,ID)
{
    this->oculto=false;
}
Monstruo::~Monstruo()
{

}
void Monstruo::mostrar(){
    cout<<"Objeto: Monstruo "<<endl;
}
bool Monstruo::esta_oculto(){
    return oculto;
}
void Monstruo::ocultar(){
    oculto = false;
}
void Monstruo::aparecer(){
    oculto = true;
} 


