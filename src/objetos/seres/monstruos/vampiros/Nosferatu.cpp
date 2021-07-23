#include "Nosferatu.h"
#include "../../../../ataque/Ataque_nosferatu.h"
#include <iostream>
using std::cout;
using std::endl;
Nosferatu::Nosferatu():Vampiro(){
    ataque = nullptr;
}
Nosferatu::Nosferatu(Casilla *casilla,char nombre,string ID):Vampiro(casilla,nombre,ID)
{
    ataque = nullptr;
}
void Nosferatu::mostrar(){
    cout<<"Objeto: Nosferatu"<<endl;
}
Nosferatu::~Nosferatu()
{
    if(ataque != nullptr)
        delete ataque;
}
void Nosferatu::defender(){

}
void Nosferatu::atacar(Casilla *casilla, Tablero* tablero){
    if(ataque == nullptr)
        this -> ataque = new Ataque_nosferatu(this);
    ataque -> atacar(casilla, tablero);

}
void Nosferatu::regnerar_energia() {
    this -> energia += 10;
}