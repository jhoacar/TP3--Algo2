#include "Vampiro.h"
#include <iostream>
using std::cout;
using std::endl;
Vampiro::Vampiro():Monstruo(){
    
}
Vampiro::Vampiro(Coordenada posicion,char nombre):Monstruo(posicion,nombre)
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
    cout << "encuentro de vampiro" << endl;
    /*
     * Por ahora este metodo va a estar vacio ya que va a depender del camino que tome el ser, y en el caso
     * que se cruce con un elemento tomarlo si puede hacerlo, y el camino se va a decidir con la implementacion
     * de caminos minimos. Asi que se va a esperar a eso, para despues implementar esa
     * PD: solo vampiro implementa este metodo ya que vampirella y nosferatu hacen lo mismo
      */
}