#ifndef CASILLA_H
#define CASILLA_H

#include <string>
#include "../objetos/Objeto.h"
#include "../funcionalidades/tda/Lista.h"
using std::string;

class Casilla{
    protected:
        string cuadrante;
        Coordenada posicion;
        Lista<Objeto*> objetos;
    private:    
        Objeto* objeto_referencia; //Objeto manipulable para el uso de comparaciones en la clase lista
    public:
        Casilla();
        Casilla(Coordenada posicion);
        virtual ~Casilla();
        virtual char obtener_tipo()=0;
        virtual int obtener_energia(int tipo_personaje)=0;
        virtual int obtener_color()=0;
        string obtener_cuadrante();
        void asignar_cuadrante(string cuadrante);
        void agregar_objeto(Objeto *objeto);
        Objeto *obtener_objeto(char nombre_objeto);
        int obtener_cantidad_objetos(char nombre_objeto);
        bool eliminar_objeto(char nombre_objeto);
        bool eliminar_toda_ocurrencia(char nombre_objeto);
        Lista<Objeto*> obtener_objetos();
};


#endif