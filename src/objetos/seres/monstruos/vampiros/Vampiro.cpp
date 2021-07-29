#include "Vampiro.h"
#include "../../../../defensa/monstruos/vampiros/Defensa_vampiro.h"
#include "../../../../ataque/monstruos/vampiros/Ataque_vampiro.h"
#include <iostream>

using std::cout;
using std::endl;

Vampiro::Vampiro():Monstruo(){
    this->armadura_aumentada = false;
}
Vampiro::Vampiro(Casilla *casilla,char nombre,string ID):Monstruo(casilla,nombre,ID)
{
    this->armadura_aumentada = false;
}
void Vampiro::mostrar(){
    cout<<"Objeto: Vampiro"<<endl;
}
Vampiro::~Vampiro()
{
}

void Vampiro::regenerar_energia() {
    this -> energia += REGENERAR_ENERGIA[VAMPIRO];
}

void Vampiro::encuentro_con_elemento() {

    Lista<Objeto*> solo_estaca = casilla->obtener_objetos().filtrar_datos(0,es_estaca);
    this -> casilla -> eliminar_objetos(solo_estaca);
}

void Vampiro::defender(Tablero *tablero, int opcion) {
    if(defensa == nullptr)
        defensa = new Defensa_vampiro(this);
    defensa->defender(tablero);
}
void Vampiro::atacar(Coordenada posicion, Tablero *tablero,char arma){   
    if(se_puede_atacar(posicion,tablero)) 
        ataque->atacar(posicion,tablero);
}
int Vampiro::se_puede_atacar(Coordenada posicion, Tablero *tablero,char arma){
    if(ataque == nullptr)
        ataque = new Ataque_vampiro(this);
    return ataque->se_puede_atacar(posicion,tablero);
}



