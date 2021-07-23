#include "Vampirella.h"
#include "Ataque_vampirella.h"
#include <iostream>
using std::cout;
using std::endl;
Vampirella::Vampirella():Vampiro(){
    ataque = nullptr;
}
Vampirella::Vampirella(Casilla *casilla,char nombre,string ID):Vampiro(casilla,nombre,ID)
{
    ataque = nullptr;
}
void Vampirella::mostrar(){
    cout<<"Objeto: Vampirella"<<endl;
}
Vampirella::~Vampirella()
{
    if(ataque != nullptr)
        delete ataque;
}

void Vampirella::defender(){
    
}
void Vampirella::atacar(Casilla *casilla, Tablero* tablero){
    if(ataque == nullptr)
        this -> ataque = new Ataque_vampirella(this);
    ataque -> atacar(casilla, tablero);
}
void Vampirella::regenerar_energia() {
    this -> energia += 6;
}

