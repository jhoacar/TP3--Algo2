#include "Humano.h"
#include <iostream>
using std::cout;
using std::endl;

Humano::Humano():Ser(){
	this->armadura_aumentada = false;
}
Humano::Humano(Casilla *casilla,char nombre,string ID):Ser(casilla,nombre,ID)
{
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

void Humano::encuentro_con_elemento() {
    
    Lista<Objeto*> objetos_casilla;
    Objeto* objeto_para_agregar = nullptr;

    objetos_casilla = this -> casilla ->obtener_objetos();

    objetos_casilla.reiniciar();
    while (objetos_casilla.existe_siguiente()){
        objeto_para_agregar = objetos_casilla.siguiente_dato();

        if (this ->es_elemento(objeto_para_agregar)){
            this -> casilla ->eliminar_objeto(objeto_para_agregar ->obtener_nombre());
            this->inventario.agregar(objeto_para_agregar); //Agrega los objetos si es que son elementos

            cout << "Se agrego un " << obtener_nombre_del_objeto(objeto_para_agregar -> obtener_nombre()) << " al inventario" << endl;
        }
    }
    cout << "Se ejecuto el metodo encuentro con elemento" << endl;
}

bool Humano::tengo_agua_bendita() {
    bool encontrado = false;
    this->inventario.reiniciar();
    while(this->inventario.existe_siguiente() && !encontrado){
        if (obtener_nombre_del_objeto(this->inventario.siguiente_dato()->obtener_nombre()) == NOMBRES_STRING[0]){
               encontrado = true;
        }
    }
    return encontrado;
}

void Humano::aumentar_energia() {
    this->energia +=3;
}

void Humano::aumentar_armadura() {
    this->armadura++;
    this->armadura_mejorada = true;
}

