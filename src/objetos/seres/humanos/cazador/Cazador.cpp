#include "Cazador.h"
#include <iostream>
using std::cout;
using std::endl;
Cazador::Cazador():Humano(){
}
Cazador::Cazador(Casilla *casilla,char nombre,string ID):Humano(casilla,nombre,ID){

}
void Cazador::mostrar(){
    cout<<"Objeto: Cazador"<<endl;
}
Cazador::~Cazador()
{

}

void Cazador::defender(){
    this -> energia -=5;

    int accion = elegir_accion();

    if (accion == CURARME){
        this -> vida +=50;
        cout << "|||| Aumenté +50 de vida ||||" <<endl;
    }
    else{
        cout << "|||| Curé a mis aliados ||||" << endl;
    }
}

int Cazador::elegir_accion() {
    int opcion;
    cout << "¿Qué debo hacer?" << endl;
    cout << "(1) Curarme." << endl;
    cout << "(2) Curar a mis aliados." << endl;
    cin >> opcion;
    while ( opcion != CURARME  && opcion != CURAR_ALIADOS ){
        cout << "No lo entiendo. ¿Qué debo hacer?" << endl;
        cin >> opcion;
    }
    return opcion;
}

void Cazador::atacar(Casilla *casilla){
    
}

void Cazador::regenerar_energia() {
    this -> energia += 8;
}
