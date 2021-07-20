#include "Humano.h"
<<<<<<< HEAD
#include "../../../ataque/Ataque_humano.h"
=======
#include "../../../defensa/tipos/Defensa_humano.h"
>>>>>>> master
#include <iostream>
using std::cout;
using std::endl;

Humano::Humano():Ser(){
	this->armadura_aumentada = false;
	this -> ataque = new Ataque_humano(this);
}

Humano::Humano(Casilla *casilla,char nombre,string ID):Ser(casilla,nombre,ID){
	this->armadura_aumentada = false;
    
}

void Humano::mostrar(){
    cout<<"Objeto: Humano "<<endl;
}

Humano::~Humano()
{

}

void Humano::regenerar_energia() {
    this -> energia += 5;
}




bool Humano::tengo_agua_bendita() {
    objeto_referencia->asignar_nombre(NOMBRES_CHAR[AGUA]); //Le asigno el nombre que quiera buscar en la lista
    return inventario.existe(objeto_referencia,comparacion_por_nombre);
}

void Humano::aumentar_energia() {
    energia +=3;
}

void Humano::aumentar_armadura() {
    armadura++;
    armadura_aumentada = true;
}

void Humano::consumir_agua_bendita() {
    energia = ENERGIA_MAXIMA;
    inventario.borrar(buscar_agua_bendita());
}

bool Humano::tiene_armadura_aumentada() {
    return this->armadura_aumentada;
}

int Humano::buscar_agua_bendita() {

    objeto_referencia->asignar_nombre(NOMBRES_CHAR[AGUA]);
    return inventario.buscar_dato(0,objeto_referencia,comparacion_por_nombre);
}

/*int Humano::elegir_accion() {
    int opcion;
    cout << "Tengo agua bendita en mi inventario." << endl;
    cout << "¿Qué debo hacer?" << endl;
    cout << "(1) Regenerar toda mi energía." << endl;
    cout << "(2) Aumentar mi armadura." << endl;
    cin >> opcion;
    while (opcion != REGENERAR_ENERGIA  && opcion != AUMENTAR_ARMADURA ){
        cout << "No lo entiendo. ¿Qué debo hacer?" << endl;
        cin >> opcion;
    }
    return opcion;
<<<<<<< HEAD

    Lista<Objeto*> objetos_casilla;
    Lista<Objeto*> solo_elementos;

    objetos_casilla = this -> casilla ->obtener_objetos();
    solo_elementos = objetos_casilla.filtrar_datos(0, es_elemento);

    this ->inventario += solo_elementos;
    cout << "Se agregaron con exito los elementos al inventario" << endl;

    for (int i = 0; i < solo_elementos . obtener_tamano(); i++)
        this ->casilla -> eliminar_objeto(solo_elementos[i]->obtener_ID());
}*/


=======
}
>>>>>>> master

