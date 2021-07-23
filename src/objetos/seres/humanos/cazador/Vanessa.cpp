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
    this->energia -=10;
    if ( !this->tengo_agua_bendita() && !this->tengo_cruz() ){
        this->vida +=10;
    }
    else {
        if ( this->tengo_cruz() ){
            cout << "Lógica de protegerse con una cruz." << endl;
        }
        if ( this->tengo_agua_bendita() ){
            cout << "Lógica de proteger aliados si tiene agua y consumirla." << endl;
        }
    }
}

bool Vanessa::tengo_agua_bendita() {
    objeto_referencia->asignar_nombre(NOMBRES_CHAR[AGUA]);
    return inventario.existe(objeto_referencia,comparacion_por_nombre);
}

bool Vanessa::tengo_cruz() {
    objeto_referencia->asignar_nombre(NOMBRES_CHAR[CRUZ]);
    return inventario.existe(objeto_referencia,comparacion_por_nombre);
}

void Vanessa::atacar(Casilla *casilla){
    
}
void Vanessa::regenerar_energia() {
    this -> energia += 10;
}

