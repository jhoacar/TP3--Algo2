#include "Humano.h"
#include <iostream>
using std::cout;
using std::endl;

Humano::Humano():Ser(){

}
Humano::Humano(Coordenada posicion,char nombre):Ser(posicion,nombre)
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
    cout << "encuentro de humano" << endl;
    /*
     * Por ahora este metodo va a estar vacio ya que va a depender del camino que tome el ser, y en el caso
     * que se cruce con un elemento tomarlo si puede hacerlo, y el camino se va a decidir con la implementacion
     * de caminos minimos. Asi que se va a esperar a eso, para despues implementar esa
     * PD: Este metodo solo esta implementado en Humanos porque Vanessa y cazador hacen lo mismo que humano simple
      */
}