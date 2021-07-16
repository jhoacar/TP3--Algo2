#ifndef CASILLA_H
#define CASILLA_H

#include <string>
#include "../funcionalidades/tda/Lista.h"
#include "Coordenada.h"
using std::string;

class Objeto;


//Pre: Dos objetos a comparar, con el atributo del nombre cargado
//Post: Retorna 0 si son de igual nombre, -1 Si el objeto A es de menor nombre que el objeto B y 1 en caso contrario
int comparacion_por_nombre(Objeto *A, Objeto *B);

//Pre: Dos objetos a comparar, con el atributo del ID cargado
//Post: Retorna 0 si son de igual ID, -1 Si el objeto A es de menor ID que el objeto B y 1 en caso contrario
int comparacion_por_ID(Objeto *A, Objeto *B);

class Casilla{
    protected:
        string cuadrante;
        Coordenada posicion;
        Lista<Objeto*> objetos;

    private:
        
        Objeto *objeto_referencia; //Nombre manipulable para el uso de comparaciones en la clase lista
    public:

        //Post: Crea una casilla vacia con coordenada en (0,0)
        Casilla();
        
        //Post: Crea una casilla con coordenada en la posicion del parametro
        Casilla(Coordenada posicion);
        
        //Post: Destruye la casilla y todo su contenido
        virtual ~Casilla();
        
        //Post: Metodo polimorfico del tipo de casilla
        virtual char obtener_tipo()=0;
        
        //Pre: Un tipo de personaje
        //Dicho tipo de personaje podra ser
		//TIPO_CAZADOR: 0
		//TIPO_HUMANO : 1
		//TIPO_VAMPIRO: 2
		//TIPO_ZOMBIE : 3
        //Post: Metodo polimorfico del tipo de casilla que devuelve la energia que consumiria el personaje
        virtual int obtener_energia(int tipo_personaje)=0;
        
        //Post: Metodo polimorfico que devuelve el color de fondo que se pintara sobre la pantalla
        virtual int obtener_color()=0;
        
        //Post: Devuelve la lista completa de objetos en la casilla
        Lista<Objeto*> obtener_objetos();

        //Post: Devuelve el cuadrante que se le ha asignado
        string obtener_cuadrante();

        //Post: Devuelve la posicion que se le ha asignado
        Coordenada obtener_posicion();
        
        //Post: Devuelve la abscisa que se le ha asignado
        int obtener_fila();
        
        //Post: Devuelve la ordenada que se le ha asignado
        int obtener_columna();
        
        //Pre: Un cuadrante a asignar
        //Post: Asigna el cuadrante al objeto
        void asignar_cuadrante(string cuadrante);
        
        //Pre: Un objeto a agregar
        //Post: Agrega el objeto a la lista de objetos de la casilla
        void agregar_objeto(Objeto *objeto);

        //Pre: Una lista de objetos a agregar
        //Post: Agrega una lista de objetos a la lista de objetos de la casilla 
        void agregar_objetos(Lista<Objeto*> objetos);
        
        //Pre: Un caracter con la representacion del nombre del objeto
        //Post: Devuelve una sublista de objetos con la ocurrencia de dicho nombre
        Lista<Objeto*> obtener_objetos(char nombre_objeto);

        //Pre: Un ID unico para el objeto
        //Post: Devuelve el objeto que encuentra en la lista con dicho ID
        Objeto *obtener_objeto(string ID);

        //Pre: Una lista de caracteres con la representacion de cada nombre de objeto 
        //Post: Devuelve una sublista con todas las ocurrencia de cada nombre de la lista
        Lista<Objeto*> obtener_objetos(Lista<char> nombres_objetos);

        //Pre: Una lista con los IDs de cada objeto
        //Post: Devuelve una lista de los ID asociado a cada objeto encontrado en la lista
        Lista<Objeto*> obtener_objetos(Lista<string> IDs);
        
        //Pre: Un caracter representativo al nombre del objeto
        //Post: Devuelve la cantidad de veces que se encuentra dicho objeto en la lista
        int obtener_cantidad_objetos(char nombre_objeto);

        //Pre: Un puntero del objeto
        //Post: Elimina de la lista el objeto, devolviendo verdadero si lo elimina, falso caso contrario
        bool eliminar_objeto(Objeto *objeto);

        bool eliminar_objeto(char nombre_objeto);

        bool eliminar_objeto(string ID);

        //Pre: Una lista de IDs unicos de cada objeto
        //Post: Elimina de la lista de objetos cada objeto que tenga el mismo ID, devolviendo la cantidad de objetos eliminados
        int eliminar_objetos(Lista<string> IDs);

        //Pre: Una lista de punteros de Objetos
        //Post: Elimina de la lista de objetos cada objeto, devolviendo la cantidad de objetos eliminados
        int eliminar_objetos(Lista<Objeto*> objetos);

        //Pre: Un caracter representativo al nombre del objeto
        //Post: Elimina de la lista todas las ocurrencia de dicho objeto, devolviendo la cantidad de objetos eliminados
        int eliminar_toda_ocurrencia(char nombre_objeto);

};




#endif
