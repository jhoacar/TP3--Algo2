#include "Nosferatu.h"
#include <iostream>
using std::cout;
using std::endl;
Nosferatu::Nosferatu():Vampiro(){

}
Nosferatu::Nosferatu(Casilla *casilla,char nombre,string ID):Vampiro(casilla,nombre,ID)
{
}
void Nosferatu::mostrar(){
    cout<<"Objeto: Nosferatu"<<endl;
}
Nosferatu::~Nosferatu()
{
}

void Nosferatu::regnerar_energia() {
    this -> energia += 10;
}