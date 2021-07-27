#include "Casilla.h"
#include "../objetos/Objeto.h"
#include "../objetos/elementos/Estaca.h"

int comparacion_por_nombre(Objeto *A, Objeto *B){
    
    if(A->obtener_nombre()==B->obtener_nombre())
        return IGUAL;
    else if(A->obtener_nombre() > B->obtener_nombre())
        return GRANDE;
    else   
        return PEQUENO;
}

int comparacion_por_ID(Objeto *A, Objeto *B){
    
    if(A->obtener_ID()==B->obtener_ID())
        return IGUAL;
    else if(A->obtener_ID() > B->obtener_ID())
        return GRANDE;
    else   
        return PEQUENO;
}


Casilla::Casilla():cuadrante(),posicion(),objetos(){
    objeto_referencia = new Estaca(); 
    //Lo iniciamos con Humano, pero puede ser cualquier objeto, solo me interesa sus atributos
}
Casilla::Casilla(Coordenada pos):cuadrante(),posicion(pos),objetos(){
    objeto_referencia = new Estaca();
    //Lo iniciamos con Humano, pero puede ser cualquier objeto, solo me interesa sus atributos
}
Casilla::~Casilla(){
    delete objeto_referencia;
}
int Casilla::obtener_fila(){
    return this->posicion.obtener_fila();
}
int Casilla::obtener_columna(){
    return this->posicion.obtener_columna();
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
void Casilla::agregar_objetos(Lista<Objeto*> objetos){
    this->objetos+=objetos;
}

Lista<Objeto*> Casilla::obtener_objetos(char nombre_objeto){
    
    Lista<Objeto*> objetos_encontrados;

    objeto_referencia->asignar_nombre(nombre_objeto);

    Lista<int> indices = objetos.buscar_todo_dato(objeto_referencia,comparacion_por_nombre);

    while(indices.existe_siguiente())
        objetos_encontrados.agregar(objetos[indices.siguiente_dato()]);

    return objetos_encontrados;
}
Objeto *Casilla::obtener_objeto(string ID){

    objeto_referencia->asignar_ID(ID);
    
    int indice = objetos.buscar_dato(0,objeto_referencia,comparacion_por_ID);

    return indice == NO_ENCONTRADO ? nullptr : objetos[indice];
}

Objeto *Casilla::obtener_objeto(char nombre_objeto){

    objeto_referencia->asignar_nombre(nombre_objeto);
    
    int indice = objetos.buscar_dato(0,objeto_referencia,comparacion_por_nombre);

    return indice == NO_ENCONTRADO ? nullptr : objetos[indice];
}

Lista<Objeto*> Casilla::obtener_objetos(Lista<char> nombres_objetos){
    
    Lista<Objeto*> objetos_encontrados;

    nombres_objetos.limpiar();//Esto lo hacemos para eliminar las repeticiones de caracteres

    for(int i=0; i< nombres_objetos.obtener_tamano(); i++)
        objetos_encontrados+=obtener_objetos(nombres_objetos[i]);

    return objetos_encontrados;
}

Lista<Objeto*> Casilla::obtener_objetos(Lista<string> IDs_objetos){
    
    Lista<Objeto*> objetos_encontrados;

    IDs_objetos.limpiar();//Esto lo hacemos para eliminar las repeticiones de IDs

    for(int i=0; i< IDs_objetos.obtener_tamano(); i++){
        
        Objeto *objeto_buscado = obtener_objeto(IDs_objetos[i]);
        
        if(objeto_buscado!=nullptr)
            objetos_encontrados.agregar(objeto_buscado);
    }

    return objetos_encontrados;
}

int Casilla::obtener_cantidad_objetos(char nombre_objeto){
    
    objeto_referencia->asignar_nombre(nombre_objeto);

    return objetos.obtener_cantidad_dato(objeto_referencia,comparacion_por_nombre);

}
bool Casilla::eliminar_objeto(char nombre_objeto){
    
    objeto_referencia->asignar_nombre(nombre_objeto);
    
    return objetos.borrar_dato(objeto_referencia,comparacion_por_nombre);
}
bool Casilla::eliminar_objeto(string ID){

    objeto_referencia->asignar_ID(ID);
    
    return objetos.borrar_dato(objeto_referencia,comparacion_por_ID);
}

bool Casilla::eliminar_objeto(Objeto *objeto){

    return objetos.borrar_dato(objeto);
}

int Casilla::eliminar_objetos(Lista<string> IDs){

    int borrados=0;

    for(int i=0; i < IDs.obtener_tamano(); i++)
        borrados+=eliminar_objeto(IDs[i]);

    return borrados;
}

int Casilla::eliminar_objetos(Lista<Objeto*> objetos){

    this->objetos-=objetos;
    return this->objetos.obtener_tamano();
}

int Casilla::eliminar_toda_ocurrencia(char nombre_objeto){
    
    objeto_referencia->asignar_nombre(nombre_objeto);
    
    return objetos.borrar_toda_occurrencia(objeto_referencia,comparacion_por_nombre);

}
Lista<Objeto*>& Casilla::obtener_objetos(){
    return objetos;
}
