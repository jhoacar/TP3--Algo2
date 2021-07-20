#include "Vampirella.h"
#include <iostream>
using std::cout;
using std::endl;
Vampirella::Vampirella():Vampiro(){

}
Vampirella::Vampirella(Casilla *casilla,char nombre,string ID):Vampiro(casilla,nombre,ID)
{
}
void Vampirella::mostrar(){
    cout<<"Objeto: Vampirella"<<endl;
}
Vampirella::~Vampirella()
{
}

void Vampirella::defender(){
    
}
void Vampirella::atacar(Casilla *casilla){

}
void Vampirella::regenerar_energia() {
    this -> energia += 6;
}

