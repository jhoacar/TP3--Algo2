#include "Vanessa.h"
#include "../../../../defensa/humanos/cazadores/Defensa_vanesa.h"
#include "../../../../ataque/humanos/cazadores/Ataque_vanesa.h"
#include <iostream>
using std::cout;
using std::endl;
Vanessa::Vanessa():Cazador(){
    
}
Vanessa::Vanessa(Casilla *casilla,char nombre,string ID):Cazador(casilla,nombre,ID)
{
}
void Vanessa::mostrar(){
    cout<<"Objeto: Vanessa"<<endl;
}
Vanessa::~Vanessa()
{
	
}
void Vanessa::defender(Tablero *tablero, int opcion){
    if(defensa == nullptr)
        defensa = new Defensa_vanesa(this);
    defensa->defender(tablero);
}

void Vanessa::atacar(Coordenada posicion, Tablero *tablero, char arma){
    if(se_puede_atacar(posicion,tablero,arma))
        ataque->atacar(posicion,tablero,arma);
}

bool Vanessa::se_puede_atacar(Coordenada posicion, Tablero *tablero,char arma){
    if(ataque==nullptr)
        ataque = new Ataque_vanesa(this);
    return ataque->se_puede_atacar(posicion,tablero,arma);
}
void Vanessa::regenerar_energia() {
    this -> energia += REGENERAR_ENERGIA[VANESA];
}

