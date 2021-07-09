#ifndef OBJETO_H
#define OBJETO_H

#include <string>
using std::string;

class Casilla;

class Objeto{
    protected:
        char nombre;
        string cuadrante;
        Casilla *casilla;
    public:
        /*
        PRE:
        POST: 
        */
        Objeto();
        /*
        PRE: La posicion y el nombre 
        POST: Crea el objeto con la informacion brindad
        */
        Objeto(Casilla *casilla,char nombre);
        /*
        PRE:
        POST: Destruye por defecto cada objeto, destruyendo cada atributo
        */
        virtual ~Objeto() = default;
        /*
        PRE: 
        POST: Metodo virtual puro para la posterior herencia de esta clase abstracta 
        */
        virtual void mostrar()=0;
        /*
        PRE:
        POST: Devuelve la posicion del objeto
        */
        Casilla* obtener_casilla();
        /*
        PRE:
        POST: Devuelve el cuadrante del objeto
        */
        string obtener_cuadrante();
        /*
        PRE:
        POST: Devuelve el nombre del objeto
        */
        char obtener_nombre();
        /*
        PRE: Un cuadrante a asignar
        POST: Asigna el cuadrante al objeto
        */
        void asignar_cuadrante(string cuadrante);
        /*
        PRE: Un nombre a asignar
        POST: Asigna el nombre al objeto
        */
        void asignar_nombre(char nombre);
        /*
        PRE: Una posicion a asignar
        POST: Asigna la posicion al objeto
        */
        void asignar_casilla(Casilla *casilla);
};


#endif