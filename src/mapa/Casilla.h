#ifndef CASILLA_H
#define CASILLA_H

#include <string>
#include "../objetos/Objeto.h"
#include "../funcionalidades/Lista.h"
using std::string;

class Casilla{
    protected:
        string cuadrante;
        Coordenada posicion;
        Lista<Objeto*> objetos;
    public:
        Casilla():cuadrante(),posicion(),objetos(){

        }
        Casilla(Coordenada pos):cuadrante(),posicion(pos),objetos(){

        }
        virtual ~Casilla()=default;
        
        virtual char obtener_tipo()=0;
        virtual int obtener_energia(int tipo_personaje)=0;

        string obtener_cuadrante(){
            return cuadrante;
        }
        void asignar_cuadrante(string cuadrante){
            this->cuadrante=cuadrante;
        }
        void agregar_objeto(Objeto *objeto){
            this->objetos.agregar(objeto);
        }
        bool eliminar_objeto(Objeto *objeto){
            return this->objetos.borrar_dato(objeto,comparacion);
        }
        Lista<Objeto*> obtener_objetos(){
            return objetos;
        }
};


#endif