#include "Zombie.h"
#include <iostream>
using std::cout;
using std::endl;
Zombie::Zombie():Monstruo(){
    
}
Zombie::Zombie(Casilla *Casilla,char nombre):Monstruo(casilla,nombre)
{
}
void Zombie::mostrar(){
    cout<<"Objeto: Zombie"<<endl;
}
Zombie::~Zombie()
{
}

void Zombie::regenerar_energia() {
    this -> energia += 5;
}

void Zombie::encuentro_con_elemento() {
    Lista<Objeto*> objetos_casilla;
    Objeto* objeto_para_agregar = nullptr;

    objetos_casilla = this -> casilla ->obtener_objetos();

    objetos_casilla.reiniciar();
    while (objetos_casilla.existe_siguiente()){
        objeto_para_agregar = objetos_casilla.siguiente_dato();

        if (objeto_para_agregar ->obtener_nombre() == NOMBRES_CHAR[AGUA]){ //los zombies solo pueden agarrar agua bendita
            this -> casilla ->eliminar_objeto(objeto_para_agregar ->obtener_nombre());
            this -> inventario.agregar(objeto_para_agregar);
            cout << "Se agrego agua bendita al inventario" << endl;
        }
    }
}
