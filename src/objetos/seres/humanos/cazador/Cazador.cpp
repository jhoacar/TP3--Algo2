#include "Cazador.h"
#include "../../../defensa/humanos/cazadores/Defensa_cazador.h"
#include "../../../ataque/humanos/cazadores/Ataque_cazador.h"
#include <iostream>
using std::cout;
using std::endl;
Cazador::Cazador():Humano(){
}
Cazador::Cazador(Casilla *casilla,char nombre,string ID):Humano(casilla,nombre,ID){
}
void Cazador::mostrar(){
    cout<<"Objeto: Cazador"<<endl;
}
Cazador::~Cazador()
{

}

void Cazador::defender(Tablero *tablero){
    if(defensa == nullptr)
        defensa = new Defensa_cazador(this);
    defensa->defender(tablero);
}

void Cazador::atacar(Coordenada posicion, Tablero *tablero){
    if(ataque == nullptr)
        ataque = new Ataque_cazador(this);
    ataque->atacar(posicion,tablero);
}

void Cazador::regenerar_energia() {
    this -> energia += REGENERAR_ENERGIA[HUMANO_CAZADOR];
}
