#include "Nosferatu.h"
#include "../../../defensa/monstruos/vampiros/Defensa_nosferatu.h"
#include "../../../ataque/monstruos/vampiros/Ataque_nosferatu.h"
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
void Nosferatu::defender(Tablero *tablero){
    if(defensa == nullptr)
        defensa = new Defensa_nosferatu(this);
    defensa->defender(tablero);
}
void Nosferatu::atacar(Coordenada posicion, Tablero *tablero){
    if(ataque==nullptr)
        ataque = new Ataque_nosferatu(this);
    ataque->atacar(posicion,tablero);
}
void Nosferatu::regnerar_energia() {
    this -> energia += REGENERAR_ENERGIA[NOSFERATU];
}