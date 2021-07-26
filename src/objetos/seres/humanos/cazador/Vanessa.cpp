#include "Vanessa.h"
#include "../../../defensa/humanos/cazadores/Defensa_vanesa.h"
#include "../../../ataque/humanos/cazadores/Ataque_vanesa.h"
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
void Vanessa::defender(Tablero *tablero){
    if(defensa == nullptr)
        defensa = new Defensa_vanesa(this);
    defensa->defender(tablero);
}

void Vanessa::atacar(Coordenada posicion, Tablero *tablero){
    if(ataque == nullptr)
        ataque = new Ataque_vanesa(this);
    ataque->atacar(posicion,tablero);
}

void Vanessa::regenerar_energia() {
    this -> energia += REGENERAR_ENERGIA[VANESA];
}

