#include "Vampirella.h"
#include "../../../defensa/monstruos/vampiros/Defensa_vampirella.h"
#include "../../../ataque/monstruos/vampiros/Ataque_vampirella.h"

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

void Vampirella::defender(Tablero *tablero){
    if(defensa==nullptr)
        defensa = new Defensa_vampirella(this);
    defensa->defender(tablero);
}
void Vampirella::atacar(Coordenada posicion,Tablero *tablero){
    if(ataque==nullptr)
        ataque = new Ataque_vampirella(this);
    ataque->atacar(posicion,tablero);
}
void Vampirella::regenerar_energia() {
    this -> energia += REGENERAR_ENERGIA[VAMPIRELLA];
}