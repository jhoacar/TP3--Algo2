#include "Zombie.h"
#include <iostream>
using std::cout;
using std::endl;
Zombie::Zombie():Monstruo(){
    
}
Zombie::Zombie(Casilla *casilla,char nombre):Monstruo(casilla,nombre)
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
    /*
     * Por ahora este metodo va a estar vacio ya que va a depender del camino que tome el ser, y en el caso
     * que se cruce con un elemento tomarlo si puede hacerlo, y el camino se va a decidir con la implementacion
     * de caminos minimos. Asi que se va a esperar a eso, para despues implementar esa
      */
}
