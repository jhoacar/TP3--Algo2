#ifndef ARCHIVO_OBJETOS_H
#define ARCHIVO_OBJETOS_H

#include "Archivo.h"
#include "../mapa/Tablero.h"
#include "../funcionalidades/tda/Diccionario.h"

class Archivo_objetos : Archivo {
    private:
    Diccionario<string,Objeto*> objetos;
    //PRE: se lee un archivo correctamente y se graba la informacion
    //POST: asigna el valor de las dimensiones que tendra el tablero.
    void extraer_dimensiones();
    //PRE: Una lista de strings donde cada posicion es el detalle de cada objeto a cargar
	//POST: guarda en la lista de punteros de objeto cada tipo de objeto encontrado en las cadena de string
	void cargar_objetos(Lista<string> &datos, Tablero *tablero);
	//PRE: Una lista de string con la informacion de la linea del fichero
	//POST: Decodifica la informacion y devuelve el nombre que encontro en la linea
	string convertir_nombre  (Lista<string> &datos);
    //PRE: Una lista de string con la informacion de la linea del fichero
	//POST: Decodifica la informacion y devuelve la posicion que encontro en la linea
	Coordenada convertir_posicion(const string &linea);
	//PRE: Una lista de string con la informacion de la linea del fichero
	//POST: Decodifica la informacion y devuelve la cantidad que encontro en la linea
	int convertir_cantidad(Lista<string> &datos);
    //PRE: Una lista de string con la informacion de la linea del fichero
	//POST: Decodifica la informacion y devuelve el id del objeto
    string convertir_id(Lista<string> &datos);
    //PRE:  
	//POST: Carga el tablero en las posiciones que posean cada objeto de la lista de objetos
    void cargar_tablero(Tablero* tablero);
    
    public:

    Archivo_objetos(string nombre_fichero, Tablero *tablero);
    //POST: retorna una lista con los datos de objetos, o una lista vacia si no hay datos cargados.
    Lista<Objeto*> obtener_lista_objetos();
    //PRE: objeto a cargar
    //POST: agrega el objeto al diccionario
    void cargar_objeto(Objeto* objeto);
};

//PRE: Un tipo de objeto (agua, bala,...) el nombre que tendra, la casilla y la cantidad si es que la tiene
//POST: Devuelve el objeto creado con dichas especificaciones
Objeto *crear_objeto(const int tipo_objeto,const char nombre,Casilla *casilla, int cantidad, string ID);

#endif