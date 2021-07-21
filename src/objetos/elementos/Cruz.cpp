#include "Cruz.h"
#include <iostream>
using std::cout;
using std::endl;

Cruz::Cruz():Elemento(){

}
Cruz::Cruz(Casilla *casilla,char nombre,int cantidad,string ID):Elemento(casilla,nombre,cantidad,ID)
{
}

Cruz::~Cruz()
{
}
void Cruz::mostrar(){
    cout<<"Objeto: Cruz"<<endl; 
}