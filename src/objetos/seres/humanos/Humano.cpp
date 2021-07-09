#include "Humano.h"
#include <iostream>
using std::cout;
using std::endl;
Humano::Humano():Ser(){

}
Humano::Humano(Casilla *casilla,char nombre):Ser(casilla,nombre)
{
}
void Humano::mostrar(){
    cout<<"Objeto: Humano "<<endl;
}
Humano::~Humano()
{
}
