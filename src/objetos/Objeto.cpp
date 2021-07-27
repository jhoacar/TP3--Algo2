#include "Objeto.h"
#include "../mapa/Casilla.h"
#include "seres/humanos/Humano.h"

string convertir_nombre(char nombre){
    int indice = buscar_dato(NOMBRES_CHAR,MAX_NOMBRES,nombre);
    return indice!=NO_ENCONTRADO ? NOMBRES_STRING[indice] : ""; 
}

char obtener_nombre(string ID){
    if(ID == ID_Vanesa)
        return NOMBRES_CHAR[VANESA];
    else if(ID==ID_Nosferatu)
        return NOMBRES_CHAR[NOSFERATU];
    else if(ID==ID_Vampirella)
        return NOMBRES_CHAR[VAMPIRELLA];
    else if(ID>=ID_minimo_humano_simple && ID<=ID_maximo_humano_simple)
        return NOMBRES_CHAR[HUMANO];
    else if(ID>=ID_minimo_cazador && ID<=ID_maximo_cazador)
        return NOMBRES_CHAR[HUMANO_CAZADOR];
    else if(ID>=ID_minimo_vampiro_simple && ID<=ID_maximo_vampiro_simple)
        return NOMBRES_CHAR[VAMPIRO];
    else if(ID>=ID_minimo_zombie && ID<=ID_maximo_zombie)
        return NOMBRES_CHAR[ZOMBIE];
    else if(ID>=ID_minimo_agua && ID<=ID_maximo_agua)
        return NOMBRES_CHAR[AGUA];
    else if(ID>=ID_minimo_balas && ID<=ID_maximo_balas)
        return NOMBRES_CHAR[BALA];
    else if(ID>=ID_minimo_cruces && ID<=ID_maximo_cruces)
        return NOMBRES_CHAR[CRUZ];
    else if(ID>=ID_minimo_escopetas && ID<=ID_maximo_escopetas)
        return NOMBRES_CHAR[ESCOPETA];
    else if(ID>=ID_minimo_estacas && ID<=ID_maximo_estacas)
        return NOMBRES_CHAR[ESTACA];
    else   
        return NO_ARMA;
}

Objeto::Objeto():nombre(),cuadrante(),ID(){
    this->casilla=nullptr;
}
Objeto::Objeto(Casilla *casilla,char nombre,string ID){
    this->casilla = casilla;
    this->nombre = nombre;
    this->ID = ID;
    this->cuadrante="";
}
Objeto::~Objeto(){
}
Casilla* Objeto::obtener_casilla(){
    return this->casilla;
}
Coordenada Objeto::obtener_posicion(){
    if(this->casilla==nullptr)
        return POSICION_INVALIDA;
    else
        return this->casilla->obtener_posicion();
}
string Objeto::obtener_cuadrante(){
    return this->cuadrante;
}
string Objeto::obtener_ID(){
    return this->ID;
}
char Objeto::obtener_nombre(){
    return this->nombre;
}
void Objeto::asignar_cuadrante(string cuadrante){
    this->cuadrante=cuadrante;
}
void Objeto::asignar_ID(string ID){
    this->ID=ID;
}
void Objeto::asignar_nombre(char nombre){
    this->nombre=nombre;
}
void Objeto::asignar_casilla(Casilla *casilla){
    this->casilla=casilla;
}