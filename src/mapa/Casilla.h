#ifndef CASILLA_H
#define CASILLA_H

#include <string>
#include "../objetos/Objeto.h"
#include "../objetos/seres/Ser.h"
#include "../funcionalidades/Lista.h"
using std::string;

int comparacion_por_nombre(Objeto *A, Objeto *B){
    if(A->obtener_nombre()==B->obtener_nombre())
        return IGUAL;
    else if(A->obtener_nombre() > B->obtener_nombre())
        return GRANDE;
    else   
        return PEQUENO;
}

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
        virtual int obtener_color()=0;

        string obtener_cuadrante(){
            return cuadrante;
        }
        void asignar_cuadrante(string cuadrante){
            this->cuadrante=cuadrante;
        }
        void agregar_objeto(Objeto *objeto){
            this->objetos.agregar(objeto);
        }
        Objeto *obtener_objeto(char nombre_objeto){
            
            Objeto *objeto_buscar = new Ser(posicion,nombre_objeto);

            int indice = objetos.buscar_dato(0,objeto_buscar,comparacion_por_nombre);
            
            delete objeto_buscar;

            return indice == NO_ENCONTRADO ? nullptr : objetos[indice];
        }
        int obtener_cantidad_objetos(char nombre_objeto){

        }
        int eliminar_objeto(int inicio_busqueda,char nombre_objeto){
            
            Objeto *objeto_eliminar=nullptr;
            
        }
        bool eliminar_toda_ocurrencia(char nombre_objeto){
            

        }
        Lista<Objeto*> obtener_objetos(){
            return objetos;
        }
};


#endif