#include "Vanessa.h"
#include <iostream>
using std::cout;
using std::endl;
Vanessa::Vanessa():Cazador(){
    
}
Vanessa::Vanessa(Casilla *casilla,char nombre,string ID):Cazador(casilla,nombre,ID)
{
}
void Vanessa::mostrar(){
    cout<<"Objeto: Vanessa"<<endl;
}
Vanessa::~Vanessa()
{
	
}
void Vanessa::defender(){

}

void Vanessa::atacar(Casilla *casilla){
    
}
void Vanessa::regenerar_energia() {
    this -> energia += 10;
}


