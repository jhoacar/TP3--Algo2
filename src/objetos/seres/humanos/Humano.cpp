#include "Humano.h"
#include <iostream>
using std::cout;
using std::endl;

Humano::Humano():Ser(){

}
Humano::Humano(Casilla *casilla,char nombre):Ser(casilla,nombre)
{
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

        if (this ->comprobar_es_elemento(objeto_para_agregar)){
            this -> casilla ->eliminar_objeto(objeto_para_agregar ->obtener_nombre());
            this->inventario.agregar(objeto_para_agregar); //Agrega los objetos si es que son elementos

            cout << "Se agrego un " << nombre_del_objeto(objeto_para_agregar -> obtener_nombre()) << " al inventario" << endl;
        }
    }
    cout << "Se ejecuto el metodo encuentro con elemento" << endl;
}