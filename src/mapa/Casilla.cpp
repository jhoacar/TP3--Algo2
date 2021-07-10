#include "Casilla.h"
#include "../objetos/Objeto.h"
#include "../objetos/seres/humanos/Humano.h"

int comparacion_por_nombre(Objeto *A, Objeto *B){
    if(A->obtener_nombre()==B->obtener_nombre())
        return IGUAL;
    else if(A->obtener_nombre() > B->obtener_nombre())
        return GRANDE;
    else   
        return PEQUENO;
}

Casilla::Casilla():cuadrante(),posicion(),objetos(){
    objeto_referencia = new Humano();
}
Casilla::Casilla(Coordenada pos):cuadrante(),posicion(pos),objetos(){
    objeto_referencia = new Humano();
}
Casilla::~Casilla(){
    delete objeto_referencia;
}
int Casilla::obtener_x(){
    return this->posicion.obtener_x();
}
int Casilla::obtener_y(){
    return this->posicion.obtener_y();
}
Coordenada Casilla::obtener_posicion(){
    return this->posicion;
}
string Casilla::obtener_cuadrante(){
    return cuadrante;
}
void Casilla::asignar_cuadrante(string cuadrante){
    this->cuadrante=cuadrante;
}
void Casilla::agregar_objeto(Objeto *objeto){
    this->objetos.agregar(objeto);
}
Objeto *Casilla::obtener_objeto(char nombre_objeto){
    
    objeto_referencia->asignar_nombre(nombre_objeto);

    int indice = objetos.buscar_dato(0,objeto_referencia,comparacion_por_nombre);

    return indice == NO_ENCONTRADO ? nullptr : objetos[indice];
}
int Casilla::obtener_cantidad_objetos(char nombre_objeto){
    
    objeto_referencia->asignar_nombre(nombre_objeto);

    return objetos.obtener_cantidad_dato(objeto_referencia,comparacion_por_nombre);

}
bool Casilla::eliminar_objeto(char nombre_objeto){
    
    objeto_referencia->asignar_nombre(nombre_objeto);
    
    return objetos.borrar_dato(objeto_referencia,comparacion_por_nombre);
}
bool Casilla::eliminar_toda_ocurrencia(char nombre_objeto){
    
    objeto_referencia->asignar_nombre(nombre_objeto);
    
    return objetos.borrar_toda_occurrencia(objeto_referencia,comparacion_por_nombre);

}
Lista<Objeto*> Casilla::obtener_objetos(){
    return objetos;
}