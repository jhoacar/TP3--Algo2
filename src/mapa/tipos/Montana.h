#ifndef MONTANA_H
#define MONTANA_H

#include <string>
using std::string;

class Montana{
        char nombre;
        string cuadrante;
    public:
        /*
        PRE:
        POST: 
        */
        Montana():cuadrante(){
            this->nombre=0;
        }
        /*
        PRE: La posicion y el nombre 
        POST: Crea el MONTANA con la informacion brindad
        */

        /*
        PRE:
        POST: Destruye por defecto cada MONTANA, destruyendo cada atributo
        */
        virtual ~Montana() = default;
        /*
        PRE: 
        POST: Metodo virtual puro para la posterior herencia de esta clase abstracta 
        */
        virtual void mostrar()=0;
        /*
        PRE:
        POST: Devuelve la posicion del MONTANA
        */
        
        /*
        PRE:
        POST: Devuelve el nombre del MONTANA
        */
        char obtener_nombre(){
            return this->nombre;
        }
        /*
        PRE: Un cuadrante a asignar
        POST: Asigna el cuadrante al MONTANA
        */
        void asignar_cuadrante(string cuadrante){
            this->cuadrante=cuadrante;
        }
};

#endif