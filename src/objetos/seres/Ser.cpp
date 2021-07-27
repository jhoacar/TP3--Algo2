#include "Ser.h"
#include "../../ataque/Ataque.h"
#include "../../defensa/Defensa.h"

bool es_agua(Objeto *objeto_a_comprobar){
    
    return objeto_a_comprobar==nullptr? false : es_agua(objeto_a_comprobar->obtener_nombre());
}

bool es_bala(Objeto *objeto_a_comprobar){
    
    return objeto_a_comprobar==nullptr? false : es_bala(objeto_a_comprobar->obtener_nombre());
}

bool es_cruz(Objeto *objeto_a_comprobar){
    
    return objeto_a_comprobar==nullptr? false : es_cruz(objeto_a_comprobar->obtener_nombre());
}

bool es_escopeta(Objeto *objeto_a_comprobar){
    
    return objeto_a_comprobar==nullptr? false : es_escopeta(objeto_a_comprobar->obtener_nombre());
}

bool es_estaca(Objeto *objeto_a_comprobar){
    
    return objeto_a_comprobar==nullptr? false : es_estaca(objeto_a_comprobar->obtener_nombre());
}

bool es_elemento(Objeto* objeto_a_comprobar) {
    
    return objeto_a_comprobar==nullptr? false : es_elemento(objeto_a_comprobar->obtener_nombre());
}
bool es_tipo_humano(Objeto *objeto_a_comprobar){
    
    return objeto_a_comprobar==nullptr? false : es_tipo_humano(objeto_a_comprobar->obtener_nombre());
}
bool es_tipo_vampiro(Objeto *objeto_a_comprobar){
    
    return objeto_a_comprobar==nullptr? false : es_tipo_vampiro(objeto_a_comprobar->obtener_nombre());
}

bool es_tipo_zombie(Objeto *objeto_a_comprobar){
    
    return objeto_a_comprobar==nullptr? false : es_tipo_zombie(objeto_a_comprobar->obtener_nombre());
}

bool es_tipo_monstruo(Objeto *objeto_a_comprobar){
    
    return objeto_a_comprobar==nullptr? false : es_tipo_monstruo(objeto_a_comprobar->obtener_nombre());
}

bool es_agua(char nombre_objeto){
    return nombre_objeto == NOMBRES_CHAR[AGUA];
}
bool es_bala(char nombre_objeto){
    return nombre_objeto == NOMBRES_CHAR[BALA];
}
bool es_cruz(char nombre_objeto){
    return nombre_objeto == NOMBRES_CHAR[CRUZ];
}
bool es_escopeta(char nombre_objeto){
    return nombre_objeto == NOMBRES_CHAR[ESCOPETA];
}
bool es_estaca(char nombre_objeto){
    return nombre_objeto == NOMBRES_CHAR[ESTACA];
}

bool es_elemento(char nombre_objeto){
    return  es_agua(nombre_objeto) ||
            es_bala(nombre_objeto) ||
            es_cruz(nombre_objeto) ||
            es_escopeta(nombre_objeto) ||
            es_estaca(nombre_objeto);
}
bool es_tipo_humano(char nombre_personaje){

    return  nombre_personaje==NOMBRES_CHAR[HUMANO] ||
            nombre_personaje==NOMBRES_CHAR[HUMANO_CAZADOR] ||
            nombre_personaje==NOMBRES_CHAR[VANESA];
}
bool es_tipo_vampiro(char nombre_personaje){

    return  nombre_personaje==NOMBRES_CHAR[VAMPIRO] ||
            nombre_personaje==NOMBRES_CHAR[VAMPIRELLA] ||
            nombre_personaje==NOMBRES_CHAR[NOSFERATU];
}
bool es_tipo_zombie(char nombre_personaje){

    return  nombre_personaje==NOMBRES_CHAR[ZOMBIE]; 
}

bool es_tipo_monstruo(char nombre_personaje){
    
    return es_tipo_zombie(nombre_personaje)|| es_tipo_vampiro(nombre_personaje); 
}

/*
bool es_humano(Objeto* objeto_a_comprobar){
    return buscar_dato(NOMBRES_CHAR, MAX_NOMBRES, objeto_a_comprobar->obtener_nombre(), )
}
*/

Ser::Ser():Objeto(){
    ataque = nullptr;
    defensa = nullptr;
    objeto_referencia = new Agua(); //No me interesa el tipo de objeto, solo sus atributos
}

Ser::Ser(Casilla *casilla,char nombre, string ID):Objeto(casilla,nombre,ID){
    this -> armadura = obtener_numero_aleatorio(ARMADURA_MINIMA, ARMADURA_MAXIMA);
    this -> vida     = obtener_numero_aleatorio(VIDA_MINIMA, VIDA_MAXIMA);
    this -> energia  = obtener_numero_aleatorio(ENERGIA_MINIMA, ENERGIA_MAXIMA);
    this -> fuerza   = obtener_numero_aleatorio(FUERZA_MINIMA, FUERZA_MAXIMA);
    ataque = nullptr;
    defensa = nullptr;
    objeto_referencia = new Agua(); //No me interesa el tipo de objeto, solo sus atributos
}
Ser::~Ser(){
    if(ataque!=nullptr)
        delete ataque;
    if(defensa!=nullptr)
        delete defensa;
    delete objeto_referencia;
}

int Ser::obtener_armadura() {
    return this -> armadura;
}

int Ser::obtener_energia() {
    return this -> energia;
}

int Ser::obtener_fuerza(){
    return this -> fuerza;
}

int Ser::obtener_vida(){
    return this -> vida;
}

Ataque *Ser::obtener_ataque(){
    return this->ataque;
}
Defensa *Ser::obtener_defensa(){
    return this->defensa;
}

void Ser::asignar_armadura(int armadura) {
    this -> armadura = armadura;
}

void Ser::asignar_energia(int energia) {
    this -> energia = energia;
}

void Ser::asignar_fuerza(int fuerza){
    this -> fuerza = fuerza;
}

void Ser::asignar_vida(int vida){
    this -> vida = vida;
}
void Ser::asignar_ataque(Ataque *ataque){
    this->ataque=ataque;
}
void Ser::asignar_defensa(Defensa *defensa){
    this->defensa=defensa;
}

Lista<Objeto*>& Ser::obtener_inventario(){
    return this -> inventario;
}


