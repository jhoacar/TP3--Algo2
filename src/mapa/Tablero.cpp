#include "Tablero.h"
#include <iostream>
#include "../funcionalidades/Funciones.h"

using namespace std;


Tablero::Tablero(){

    this->filas=0;

    this->columnas=0;

    casillas=nullptr;

}

Tablero::Tablero(int filas,int columnas)
{

    this->filas=filas;

    this->columnas=columnas;

    casillas = new Casilla**[filas];

    for(int i=0; i < filas; i++)
        casillas[i] = new Casilla*[columnas];


    for(int i=0; i < filas ;i++){

        for(int j=0; j < columnas ;j++)
            casillas[i][j]=nullptr;
    }

}

Tablero::~Tablero()
{
    for(int i=0; i < filas ; i++){

        for(int j=0; j < columnas ; j++){

            if(casillas[i][j] != nullptr){

                delete casillas[i][j];

                casillas[i][j]=nullptr;

            }
        }
    }

    for(int i=0 ; i < filas ;i++){
    
        delete[] casillas[i];
    
        casillas[i]=nullptr;
    
    }

    delete [] casillas;

    casillas=nullptr;
}

string Tablero::obtener_cuadrante(Coordenada posicion){
    
    if(!es_valida(posicion))
    
        return "";

    else if(posicion.obtener_x()<columnas/2 && posicion.obtener_y()<filas/2)
    
        return CARDINALES[NOROESTE];
    
    else if(posicion.obtener_x()>columnas/2 && posicion.obtener_y()>filas/2)
    
        return CARDINALES[SURESTE];
    
    else if(posicion.obtener_x()>=columnas/2 && posicion.obtener_y()<=filas/2)
    
        return CARDINALES[NORESTE];
    
    else
    
        return CARDINALES[SUROESTE];
}

bool Tablero::es_valida(Coordenada posicion){

    Coordenada limite( columnas , filas );

    return posicion<limite;

}
void Tablero::cargar_objeto(Objeto *objeto){
    
    if(objeto!=nullptr){

        Coordenada posicion = objeto->obtener_posicion();

        posicion-=1; //Le resto una posicion para guardarla correctamente en el tablero arrancando en (0,0)

        if(es_valida(posicion)){

            objeto->asignar_cuadrante( obtener_cuadrante ( posicion ) );
    
            casillas[ posicion.obtener_y() ][ posicion.obtener_x() ]->agregar_objeto(objeto);
    
        }

    }    
}

int Tablero::obtener_filas(){
    
    return this->filas;

}
int Tablero::obtener_columnas(){

    return this->columnas;

}
Casilla* Tablero::obtener_casilla(Coordenada posicion){
    
    if(es_valida(posicion))
        return casillas[posicion.obtener_y()][posicion.obtener_x()];        
    else  
        return nullptr;
}

bool Tablero::eliminar_objeto(Objeto *objeto){

    //if(es_valida(objeto->obtener_posicion())){
        
        //if(casillas[posicion.obtener_y()][posicion.obtener_x()]!=nullptr){
            
        //    casillas[posicion.obtener_y()][posicion.obtener_x()]->eliminar_objeto(objeto);
            
        //   return true;
        //}
    //}
    return false;
}

bool Tablero::eliminar_objeto(Coordenada posicion,const char nombre_objeto){
    
    Casilla *casilla = obtener_casilla(posicion);

    if(casilla==nullptr)
        return false;

    return casilla->eliminar_objeto(nombre_objeto);
    
}

void Tablero::mostrar_tablero(){


    mostrar_leyenda();
}


void Tablero::mostrar_leyenda(){

    cout<<"\n\tCONVENCION USADA: "<<endl;
    cout<<"\n-*: vacio";
    cout<<"\n- h: humaNOROESTE simple";
    cout<<"\n- H: humaNOROESTE caza vampiros-zombis";
    cout<<"\n- W: Vanesa";
    cout<<"\n- z: zombi";
    cout<<"\n- v: vampiro";
    cout<<"\n- V: Vampirella"; 
    cout<<"\n- N: NOROESTEsferatu ";
    cout<<"\n- c: cruz ";
    cout<<"\n- a: agua bendita ";
    cout<<"\n- e: estaca ";
    cout<<"\n- E: escopeta ";
    cout<<"\n- b: balas"<<endl;
}
