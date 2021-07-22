#include "Vampirella.h"
#include <iostream>
using std::cout;
using std::endl;
Vampirella::Vampirella():Vampiro(){
    this->murcielago= false;
}
Vampirella::Vampirella(Casilla *casilla,char nombre,string ID):Vampiro(casilla,nombre,ID)
{
    this->murcielago=true;
}
void Vampirella::mostrar(){
    cout<<"Objeto: Vampirella"<<endl;
}
Vampirella::~Vampirella()
{
}

void Vampirella::defender(){
    this->energia -=5;
    this->convertir_en_murcielago();
}

void Vampirella::convertir_en_murcielago() {
    this->murcielago = true;
}

void Vampirella::convertir_en_vampiro() {
    this->murcielago = false;
}

bool Vampirella::es_murcielago() {
    return this->murcielago;
}

void Vampirella::atacar(Casilla *casilla){

}
void Vampirella::regenerar_energia() {
    this -> energia += 6;
}

