#include "Vampirella.h"
#include <iostream>
using std::cout;
using std::endl;
Vampirella::Vampirella():Vampiro(){

}
Vampirella::Vampirella(Casilla *casilla,char nombre):Vampiro(casilla,nombre)
{
}
void Vampirella::mostrar(){
    cout<<"Objeto: Vampirella"<<endl;
}
Vampirella::~Vampirella()
{
}

void Vampirella::regenerar_energia() {
    this -> energia += 6;
}

