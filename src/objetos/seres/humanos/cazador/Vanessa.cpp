#include "Vanessa.h"
#include <iostream>
using std::cout;
using std::endl;
Vanessa::Vanessa():Cazador(){
    
}
Vanessa::Vanessa(Casilla *casilla,char nombre):Cazador(casilla,nombre)
{
}
void Vanessa::mostrar(){
    cout<<"Objeto: Vanessa"<<endl;
}
Vanessa::~Vanessa()
{
	
}

void Vanessa::regenerar_energia() {
    this -> energia += 10;
}

