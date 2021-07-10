#include "Vampiro.h"
#include <iostream>
using std::cout;
using std::endl;
Vampiro::Vampiro():Monstruo(){
    
}
Vampiro::Vampiro(Casilla *casilla,char nombre):Monstruo(casilla,nombre)
{
}
void Vampiro::mostrar(){
    cout<<"Objeto: Vampiro"<<endl;
}
Vampiro::~Vampiro()
{
}

void Vampiro::regenerar_energia() {
    this -> energia += 4;
}

void Vampiro::encuentro_con_elemento() {
    Lista<Objeto*> objetos_casilla;
    Objeto* objeto_para_agregar = nullptr;

    objetos_casilla = this -> casilla -> obtener_objetos();

    objetos_casilla.reiniciar();
    while (objetos_casilla.existe_siguiente()){
        objeto_para_agregar = objetos_casilla.siguiente_dato();

        if (objeto_para_agregar ->obtener_nombre() == NOMBRES_CHAR[ESTACA]){ //los zombies solo pueden agarrar agua bendita
            this -> casilla -> eliminar_objeto(objeto_para_agregar ->obtener_nombre());
            cout << "Un vampiro ha eliminado una estaca del tablero" << endl;
        }
    }
}