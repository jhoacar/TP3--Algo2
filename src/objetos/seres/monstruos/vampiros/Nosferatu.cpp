#include "Nosferatu.h"
#include <iostream>
using std::cout;
using std::endl;
Nosferatu::Nosferatu():Vampiro(){

}
Nosferatu::Nosferatu(Casilla *casilla,char nombre):Vampiro(casilla,nombre)
{
}
void Nosferatu::mostrar(){
    cout<<"Objeto: Nosferatu"<<endl;
}
Nosferatu::~Nosferatu()
{
}
