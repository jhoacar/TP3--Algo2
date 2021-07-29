#include "Cazador.h"
#include "../../../../defensa/humanos/cazadores/Defensa_cazador.h"
#include "../../../../ataque/humanos/cazadores/Ataque_cazador.h"
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

void Cazador::defender(Tablero *tablero, int opcion){
    if(defensa == nullptr)
        defensa = new Defensa_cazador(this);
    defensa->defender(tablero,opcion);
}

void Cazador::atacar(Coordenada posicion, Tablero *tablero,char arma){
    if(se_puede_atacar(posicion,tablero,arma))
        ataque->atacar(posicion,tablero,arma);
}

int Cazador::se_puede_atacar(Coordenada posicion, Tablero *tablero,char arma){
    if(ataque == nullptr)
        ataque = new Ataque_cazador(this);
    return ataque->se_puede_atacar(posicion,tablero,arma);
}


void Cazador::regenerar_energia() {
    this -> energia += REGENERAR_ENERGIA[HUMANO_CAZADOR];
}
