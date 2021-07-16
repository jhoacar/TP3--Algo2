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

void Humano::defenderse() {
    if (!this->tengo_agua_bendita()){
        this->aumentar_energia();
        std::cout << "|||| No tengo agua bendita, pero aumenté mi energía ||||" << std::endl;
    }
    else {
        int accion = this->elegir_accion();
        if (accion == REGENERAR_ENERGIA){
            this->consumir_agua_bendita();
            std::cout << "|||| Regeneré mi energía ||||" << std::endl;
        }
        else{
            this->aumentar_armadura();
            std::cout << "|||| Mejoré mi armadura ||||" << std::endl;
        }
    }
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

void Humano::consumir_agua_bendita() {
    this->energia = ENERGIA_MAXIMA;
    this->inventario.borrar(this->buscar_agua_bendita_en_mi_inventario());
}

int Humano::buscar_agua_bendita_en_mi_inventario() {
    int posicion=0;
    bool encontrado=false;
    this->inventario.reiniciar();
    while(this->inventario.existe_siguiente() && !encontrado){
        posicion ++;
        if (obtener_nombre_del_objeto(this->inventario.siguiente_dato()->obtener_nombre()) == NOMBRES_STRING[0]){
            encontrado = true;
        }
    }
    return posicion;
}

int Humano::elegir_accion() {
    int opcion;
    std::cout << "Tengo agua bendita en mi inventario." << std::endl;
    std::cout << "¿Qué debo hacer?" << std::endl;
    std::cout << "(1) Regenerar toda mi energía." << std::endl;
    std::cout << "(2) Aumentar mi armadura." << std::endl;
    std::cin >> opcion;
    while (opcion != REGENERAR_ENERGIA  && opcion != AUMENTAR_ARMADURA ){
        std::cout << "No lo entiendo. ¿Qué debo hacer?" << std::endl;
        std::cin >> opcion;
    }
    return opcion;
}

